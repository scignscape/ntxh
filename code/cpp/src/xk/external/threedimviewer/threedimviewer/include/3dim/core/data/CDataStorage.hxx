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


///////////////////////////////////////////////////////////////////////////////
//

inline CStorableFactory& CDataStorage::getFactory()
{
    // Some specific factory?
    if( m_pFactory )
    {
        return *m_pFactory;
    }

    // No specific factory, so use the default one...
    return STORABLE_FACTORY;
}

///////////////////////////////////////////////////////////////////////////////
//

template <class T>
inline CPtrWrapper<CStorageEntry> CDataStorage::findObject(const CChangedEntries& Changes, int Flags)
{
    typedef CObjectHolder<T> tObjectHolder;

    return findEntry<tObjectHolder>(Changes, Flags);
}

///////////////////////////////////////////////////////////////////////////////
//

inline CDataStorage::tSigEntryChanged& CDataStorage::getEntrySignal(int Id)
{
    if( !checkId(Id) )
    {
        throw Storage::CUnknowEntry();
    }

    return m_Storage[Id]->getSignal();
}

///////////////////////////////////////////////////////////////////////////////
//

template <class T>
inline CPtrWrapper<CStorageEntry> CDataStorage::findEntry(const CChangedEntries& Changes, int Flags)
{
    typename CChangedEntries::tChanges::const_iterator itEnd = Changes.getImpl().end();
    typename CChangedEntries::tChanges::const_iterator it = Changes.getImpl().begin();
    for( ; it != itEnd; ++it )
    {
        CStorageEntry *pEntry = m_Storage[it->first].get();
        if( pEntry->getId() != Storage::UNKNOWN && pEntry->checkType<T>() )
        {
            return CPtrWrapper<CStorageEntry>(pEntry, Flags);
        }
    }
    throw Storage::CUnknowEntry();
}


///////////////////////////////////////////////////////////////////////////////
//

template <class T>
inline int CDataStorage::findEntryId(const CChangedEntries& Changes)
{
    typename CChangedEntries::tChanges::const_iterator itEnd = Changes.getImpl().end();
    typename CChangedEntries::tChanges::const_iterator it = Changes.getImpl().begin();
    for( ; it != itEnd; ++it )
    {
        CStorageEntry *pEntry = m_Storage[it->first].get();
        if( pEntry->getId() != Storage::UNKNOWN && pEntry->checkType<T>() )
        {
			return pEntry->getId();
        }
    }
    return Storage::UNKNOWN;
}

///////////////////////////////////////////////////////////////////////////////
//! Serialize the data storage

template <class S>
void CDataStorage::serialize(vpl::mod::CChannelSerializer<S>& Writer)
{
	// lock storage
	tLock Lock(*this);

	tStorage::iterator i;

	for( i = m_Storage.begin(); i != m_Storage.end(); ++i )
    {
		(*i)->serialize( Writer );
    }
}


///////////////////////////////////////////////////////////////////////////////
//! Deserialize the data storage

template <class S>
void CDataStorage::deserialize(vpl::mod::CChannelSerializer<S>& Reader)
{
    #pragma unused(Reader)
	// lock storage
	tLock Lock(*this);

    // Not yet implemented!
}
