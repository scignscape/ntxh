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
 * Date:    2007/06/20                       
 *
 * Description:
 * - Serialization of objects (data entities) via channels.
 */


//==============================================================================
/*
 * Implementation of the CBinarySerializer class.
 */

template <typename T>
void CBinarySerializer::writeRoot(T& Object)
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    tProgressInitializer StartProgress(*this);

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
void CBinarySerializer::beginWrite(T& VPL_UNUSED(Object))
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    if( this->checkOption(Serializer::RAW_DATA) )
    {
        m_spActiveChannel = m_spChannel;
        return;
    }

    static const char *pcName = CSerializationTraits<T>::getName();
    static const int Compression = CSerializationTraits<T>::getCompression();
    static const int BlockSize = CSerializationTraits<T>::getBlockSize();

    m_spActiveChannel = CChannelCompressor::create(Compression, new CBlockChannel(BlockSize, m_spChannel.get(), this->checkOption(Serializer::NO_LOCKING)));

    if( !BinarySerializer::writeGroupHeader(*m_spChannel,
                                            pcName,
                                            Compression,
                                            BlockSize
                                            ) )
    {
        throw Serializer::CWriteFailed();
    }
}


template <typename T>
void CBinarySerializer::endWrite(T& VPL_UNUSED(Object))
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    m_spActiveChannel->flush();
}


template <typename T>
void CBinarySerializer::write(const T& Value)
{
    VPL_STATIC_ASSERT(vpl::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_VALUE);

    if( !m_spActiveChannel->write((char *)&Value, tSize(sizeof(T))) )
    {
        throw Serializer::CWriteFailed();
    }
}


template <typename T>
void CBinarySerializer::write(const T *pData, tSize Length)
{
//    VPL_STATIC_ASSERT(vpl::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_BLOCK_OF_DATA);

    if( !m_spActiveChannel->write((char *)pData, Length * tSize(sizeof(T))) )
    {
        throw Serializer::CWriteFailed();
    }
}

template<>
inline void CBinarySerializer::write(const bool & bValue )
{
    vpl::sys::tInt32 v( bValue ? 1 : 0 );
    write( v );
}

template <typename T>
void CBinarySerializer::readRoot(T& Object)
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    tProgressInitializer StartProgress(*this);

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
void CBinarySerializer::beginRead(T& VPL_UNUSED(Object))
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    if( this->checkOption(Serializer::RAW_DATA) )
    {
        m_spActiveChannel = m_spChannel;
        return;
    }

    static const char *pcName = CSerializationTraits<T>::getName();

    int Compression;
    int BlockSize;
    if( !BinarySerializer::readGroupHeader(*m_spChannel, pcName, Compression, BlockSize)
        || BlockSize < 0 )
    {
        throw Serializer::CReadFailed();
    }

    m_spActiveChannel = CChannelCompressor::create(Compression, new CBlockChannel(BlockSize, m_spChannel.get(), this->checkOption(Serializer::NO_LOCKING)));
}


template <typename T>
void CBinarySerializer::endRead(T& VPL_UNUSED(Object))
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    m_spActiveChannel->flush();
}


template <typename T>
void CBinarySerializer::read(T& Value)
{
    VPL_STATIC_ASSERT(vpl::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_VALUE);

    if( m_spActiveChannel->read((char *)&Value, tSize(sizeof(T))) != tSize(sizeof(T)) )
    {
        throw Serializer::CReadFailed();
    }
}


template <typename T>
void CBinarySerializer::read(T *pData, tSize Length)
{
//    VPL_STATIC_ASSERT(vpl::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_DATA);

    tSize Size = Length * tSize(sizeof(T));

    if( m_spActiveChannel->read((char *)pData, Size) != Size )
    {
        throw Serializer::CReadFailed();
    }
}

template <>
inline void CBinarySerializer::read( bool & bValue )
{
    vpl::sys::tInt32 v;
    read( v );
    bValue = (v != 0);
}
