///////////////////////////////////////////////////////////////////////////////
// $Id$
//
// 3DimViewer
// Lightweight 3D DICOM viewer.
//
// Copyright 2008-2016 3Dim Laboratory s.r.o.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////////

#include <data/CSerializationManager.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   ! Constructor. 
////////////////////////////////////////////////////////////////////////////////////////////////////
CSerializationManager::CSerializationManager( data::CDataStorage * dataStorage, data::CStorageIdRemapperBase* mapper)
    : m_dataStorage( dataStorage )
    , m_version( SERIALIZER_CURRENT_VERSION )
    , m_idMapper(mapper)
{
}


CSerializationManager::~CSerializationManager()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   ! Serialize. 
//!
//!\param [in,out]  Writer  the writer. 
////////////////////////////////////////////////////////////////////////////////////////////////////
void CSerializationManager::serialize(vpl::mod::CBinarySerializer & Writer, const tIdVector & ids )
{
    // Initialize progress notification
    CProgress::tProgressInitializer StartProgress(*this);

    // Serialize only entries with data
    tIdVector serialized;
    tIdVector::const_iterator i;


    for( i = ids.begin(); i != ids.end(); ++i )
    {
        data::CStorageEntry * entry = m_dataStorage->getEntry(*i).get();

        if( entry != NULL )
        {
            if( entry->hasData() )
                serialized.insert( *i );
        }
    }

    CProgress::setProgressMax( serialized.size() );

    // Initialize the progress
//    tProgressInitializer StartProgress(*this);
    
    // Write the entity header
    if( !vpl::mod::BinarySerializer::writeEntityHeader(*Writer.getChannelPtr()) )
    {
        throw vpl::mod::Serializer::CWriteFailed();
    }

    // serialize header structure
    serializeHeader( Writer, serialized );

    // serialize all items 
    for( i = serialized.begin(); i != serialized.end(); ++i )
    {
        data::CStorageEntry * entry = m_dataStorage->getEntry(*i).get();

//        int k = *i;
        if( entry != NULL )
        {
            entry->lockData();
            entry->serialize( Writer );
            entry->unlockData();
        }
        else
        {
            throw vpl::mod::Serializer::CWriteFailed();
        }

        if( !CProgress::progress() )
        {
            return;
        }
    }

    // Write the terminal block
    if( !vpl::mod::BinarySerializer::writeTerminal(*Writer.getChannelPtr()) )
    {
        throw vpl::mod::Serializer::CWriteFailed();
    }

    CProgress::endProgress();
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   ! Deserialize. 
//!
//!\param [in,out]  Reader  the reader. 
////////////////////////////////////////////////////////////////////////////////////////////////////
void CSerializationManager::deserialize(vpl::mod::CBinarySerializer & Reader, tIdVector & ids )
{
    // Initialize progress notification
    CProgress::tProgressInitializer StartProgress(*this);
    
    // Read the entity header
    if( !vpl::mod::BinarySerializer::readEntityHeader(*Reader.getChannelPtr()) )
    {
        throw vpl::mod::Serializer::CReadFailed();
    }

    // clear output vector
    ids.clear();

    // serialize header structure
    deserializeHeader( Reader, ids );
    if( m_version != SERIALIZER_CURRENT_VERSION )
    {
        throw vpl::mod::Serializer::CReadFailed();
    }

#ifdef _WIN32
    // output storage entry id
    {
        std::stringstream ss;
        ss << "Loading " << ids.size() << " storage entries\n";
        std::string str = ss.str();
        OutputDebugStringA(str.c_str());
    }
#endif

    CProgress::setProgressMax( ids.size() );

    // deserialize all items
    for (tIdVector::iterator iter = ids.begin(); iter != ids.end(); ++iter)
    {
        int i = m_idMapper->getId(*iter);
        // Is id valid storage id?
        if(!m_dataStorage->isEntryValid(i))
		{
			if (i > data::Storage::UNKNOWN && i < data::Storage::MAX_ID)
			{
				VPL_LOG_INFO("Deserialize skipping entry " << i);
#ifdef _WIN32
                // output storage entry id
                {
                    std::stringstream ss;
                    ss << "Deserialize skipping entry " << i << "\n";
                    std::string str = ss.str();
                    OutputDebugStringA(str.c_str());
                }
#endif
			}
            continue;
		}

        data::CStorageEntry * entry = m_dataStorage->getEntry(i).get();
        bool readError = true;

        if (entry != NULL)
        {
            readError = false;

#ifdef _WIN32
             // output storage entry id
             {
                 std::stringstream ss;
                 ss << "Loading storage entry " << i << " ";
                 if (NULL!=entry->getStorableDataPtr())
                     ss << " " << typeid(*entry->getStorableDataPtr()).name();
                 ss << "\n";
                 std::string str = ss.str();
                 OutputDebugStringA(str.c_str());
             }
#endif

            // Initialize default state
            entry->init();

            entry->lockData();

            try
            {
                // Load data
                entry->deserialize( Reader );
            }
            catch (const vpl::base::CException Exception)
            {
                readError = true;
            }

            entry->unlockData();

            // Invalidate entry
            m_dataStorage->invalidate(entry, data::Storage::FORCE_UPDATE | data::StorageEntry::DESERIALIZED);
        }

        // check progress before readError because progress functions in entry deserializers throw exceptions (ie cause readError)
        if (!CProgress::progress())
        {
            return;
        }

        if (readError)
        {
            throw vpl::mod::Serializer::CReadFailed();
        }
    }

    // Read the terminal block
    if (!vpl::mod::BinarySerializer::readTerminal(*Reader.getChannelPtr()))
    {
        throw vpl::mod::Serializer::CReadFailed();
    }

    // notify all items that deserialization has finished
    for (tIdVector::iterator iter = ids.begin(); iter != ids.end(); ++iter)
    {
        int i = m_idMapper->getId(*iter);

        // Is id valid storage id?
        if (!m_dataStorage->isEntryValid(i))
        {
            continue;
        }

        data::CStorageEntry *entry = m_dataStorage->getEntry(i).get();
        if (entry != NULL)
        {
            entry->lockData();
            bool invalidate = entry->deserializationFinished();
            entry->unlockData();

            if (invalidate)
            {
                m_dataStorage->invalidate(entry, data::Storage::FORCE_UPDATE | data::StorageEntry::DESERIALIZED);
            }
        }

        if (!CProgress::progress())
        {
            return;
        }
    }

    CProgress::endProgress();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   ! Serialize header. 
//!
//!\param [in,out]  Writer  the writer. 
////////////////////////////////////////////////////////////////////////////////////////////////////
void CSerializationManager::serializeHeader(vpl::mod::CBinarySerializer &Writer, const tIdVector & ids )
{
    Writer.beginWrite( *this );

    Writer.write( m_version );
    Writer.write( ids );

    Writer.endWrite( *this );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   ! Deserialize header. 
//!
//!\param [in,out]  Reader  the reader. 
////////////////////////////////////////////////////////////////////////////////////////////////////
void CSerializationManager::deserializeHeader(vpl::mod::CBinarySerializer &Reader, tIdVector & ids )
{
    Reader.beginRead( *this );

    Reader.read( m_version );
    Reader.read( ids );

    Reader.endRead( *this );
}
