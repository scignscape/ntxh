//==============================================================================
/* This file comes from MDSTk software and was modified for
 * 
 * VPL - Voxel Processing Library
 * Changes are Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * The original MDSTk legal notice can be found below.
 * 
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2009 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * File:    mdsSHMSerializer.hxx             
 * Section: libModule                        
 * Date:    2007/06/21                       
 *
 * Description:
 * - Binary serialization of objects (data entities) over shared memory.
 */


//==============================================================================
/*
 * Implementation of the CSHMSerializer class.
 */

template <typename T>
inline void CSHMSerializer::writeRoot(T& Object)
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    // Write the entity header
    if( !this->checkOption(Serializer::RAW_DATA) )
    {
        if( !BinarySerializer::writeEntityHeader(*m_spChannel) )
        {
            throw Serializer::CWriteFailed();
        }
    }

    // Write the entity data
    Object.serialize(*this);

    // Write the terminal block
    if( !this->checkOption(Serializer::RAW_DATA) )
    {
        if( !BinarySerializer::writeTerminal(*m_spChannel) )
        {
            throw Serializer::CWriteFailed();
        }
    }
}


template <typename T>
inline void CSHMSerializer::beginWrite(T& VPL_UNUSED(Object))
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    if( this->checkOption(Serializer::RAW_DATA) )
    {
        return;
    }

    static const char *pcName = CSerializationTraits<T>::getName();

    if( !BinarySerializer::writeGroupHeader(*m_spChannel, pcName, CC_RAW, 0) )
    {
        throw Serializer::CWriteFailed();
    }
}


template <typename T>
inline void CSHMSerializer::endWrite(T& VPL_UNUSED(Object))
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    m_spActiveChannel->flush();
}


template <typename T>
inline void CSHMSerializer::write(const T& Value)
{
    VPL_STATIC_ASSERT(vpl::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_VALUE);

    if( !m_spActiveChannel->write((char *)&Value, tSize(sizeof(T))) )
    {
        throw Serializer::CWriteFailed();
    }
}


template <typename T>
inline void CSHMSerializer::write(vpl::base::CSHMData<T>& Data)
{
    // Write size of the data block
    tSize Size = Data.getSize();
    if( !m_spActiveChannel->write((char *)&Size, tSize(sizeof(tSize))) )
    {
        throw Serializer::CWriteFailed();
    }

    // Check if the pointer already addresses the shared memory
    if( Data.getSharedMemPtr() && Data.getSharedMemPtr()->getName() == m_spActiveChannel->getSharedMemPtr()->getName() )
    {
        // Compare distance from the beginning
        size_t Dist1 = (char *)Data.getPtr() - (char *)Data.getSharedMemPtr()->getData();
        size_t Dist2 = (char *)m_spActiveChannel->getDataPtr() - (char *)m_spActiveChannel->getSharedMemPtr()->getData();
        if( Dist1 == Dist2 )
        {
            // Skip the data
            if( !m_spActiveChannel->skip(Data.getSize() * tSize(sizeof(T))) )
            {
                throw Serializer::CWriteFailed();
            }

            // Logging
            VPL_LOG_INFO("CSHMSerializer::writeData(): Data already stored in the SHM");
            return;
        }
    }

    // Write the data
    if( !m_spActiveChannel->write((char *)Data.getPtr(), Data.getSize() * tSize(sizeof(T))) )
    {
        throw Serializer::CWriteFailed();
    }

    // Logging
    VPL_LOG_INFO("CSHMSerializer::writeData(): Copying data to the shared memory");
}


template <typename T>
inline void CSHMSerializer::write(const T *pData, tSize Length)
{
//    VPL_STATIC_ASSERT(vpl::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_BLOCK_OF_DATA);

    if( !m_spActiveChannel->write((char *)pData, Length * tSize(sizeof(T))) )
    {
        throw Serializer::CWriteFailed();
    }
}


template <typename T>
inline void CSHMSerializer::readRoot(T& Object)
{
    // Read and check the entity header
    if( !this->checkOption(Serializer::RAW_DATA) )
    {
        if( !BinarySerializer::readEntityHeader(*m_spChannel) )
        {
            throw Serializer::CReadFailed();
        }
    }

    // Read the entity data
    Object.deserialize(*this);

    // Read the terminal block
    if( !this->checkOption(Serializer::RAW_DATA) )
    {
        if( !BinarySerializer::readTerminal(*m_spChannel) )
        {
            throw Serializer::CReadFailed();
        }
    }
}


template <typename T>
inline void CSHMSerializer::beginRead(T& VPL_UNUSED(Object))
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    if( this->checkOption(Serializer::RAW_DATA) )
    {
        return;
    }

    static const char *pcName = CSerializationTraits<T>::getName();

    int Compression;
    int BlockSize;
    if( !BinarySerializer::readGroupHeader(*m_spChannel, pcName, Compression, BlockSize)
        || BlockSize != 0
        || Compression != CC_RAW )
    {
        throw Serializer::CReadFailed();
    }
}


template <typename T>
inline void CSHMSerializer::endRead(T& VPL_UNUSED(Object))
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    m_spActiveChannel->flush();
}


template <typename T>
inline void CSHMSerializer::read(T& Value)
{
    VPL_STATIC_ASSERT(vpl::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_VALUE);

	if (m_spActiveChannel->read((char *)&Value, tSize(sizeof(T))) != tSize(sizeof(T)))
    {
        throw Serializer::CReadFailed();
    }
}


template <typename T>
inline void CSHMSerializer::read(vpl::base::CSHMData<T>& Data)
{
    // Read size of the data block in elements T
    tSize Size;
	if (m_spActiveChannel->read((char *)&Size, tSize(sizeof(tSize))) != tSize(sizeof(tSize)))
    {
        throw Serializer::CReadFailed();
    }

    // Initialize the data so that it will point to the shared memory
    Data.create(m_spActiveChannel->getSharedMemPtr(),
                (T *)m_spActiveChannel->getDataPtr(),
                Size
                );

    // Skip the data
    if( !m_spActiveChannel->skip(Size * tSize(sizeof(T))) )
    {
        throw Serializer::CReadFailed();
    }

    // Logging
    VPL_LOG_INFO("CSHMSerializer::readData(): Getting data from the shared memory");
}


template <typename T>
inline void CSHMSerializer::read(T *pData, tSize Length)
{
//    VPL_STATIC_ASSERT(vpl::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_DATA);

    tSize Size = Length * tSize(sizeof(T));

    if( m_spActiveChannel->read((char *)pData, Size) != Size )
    {
        throw Serializer::CReadFailed();
    }
}

