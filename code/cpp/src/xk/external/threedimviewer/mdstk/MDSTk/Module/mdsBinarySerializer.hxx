//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/20                          \n
 *
 * $Id: mdsBinarySerializer.hxx 2098 2012-02-16 23:50:36Z spanel $
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
    MDS_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

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
void CBinarySerializer::beginWrite(T& MDS_UNUSED(Object))
{
    MDS_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    if( this->checkOption(Serializer::RAW_DATA) )
    {
        m_spActiveChannel = m_spChannel;
        return;
    }

    static const char *pcName = CSerializationTraits<T>::getName();
    static const int Compression = CSerializationTraits<T>::getCompression();
    static const int BlockSize = CSerializationTraits<T>::getBlockSize();

    m_spActiveChannel = CChannelCompressor::create(Compression, new CBlockChannel(BlockSize, m_spChannel.get()));

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
void CBinarySerializer::endWrite(T& MDS_UNUSED(Object))
{
    MDS_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    m_spActiveChannel->flush();
}


template <typename T>
void CBinarySerializer::write(const T& Value)
{
    MDS_STATIC_ASSERT(mds::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_VALUE);

    if( !m_spActiveChannel->write((char *)&Value, (int)sizeof(T)) )
    {
        throw Serializer::CWriteFailed();
    }
}


template <typename T>
void CBinarySerializer::write(const T *pData, tSize Length)
{
//    MDS_STATIC_ASSERT(mds::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_BLOCK_OF_DATA);

    if( !m_spActiveChannel->write((char *)pData, Length * (int)sizeof(T)) )
    {
        throw Serializer::CWriteFailed();
    }
}


template <typename T>
void CBinarySerializer::readRoot(T& Object)
{
    MDS_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

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
void CBinarySerializer::beginRead(T& MDS_UNUSED(Object))
{
    MDS_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    if( this->checkOption(Serializer::RAW_DATA) )
    {
        m_spActiveChannel = m_spChannel;
        return;
    }

    static const char *pcName = CSerializationTraits<T>::getName();

    int Compression;
    tSize BlockSize;
    if( !BinarySerializer::readGroupHeader(*m_spChannel, pcName, Compression, BlockSize)
        || BlockSize < 0 )
    {
        throw Serializer::CReadFailed();
    }

    m_spActiveChannel = CChannelCompressor::create(Compression, new CBlockChannel(BlockSize, m_spChannel.get()));
}


template <typename T>
void CBinarySerializer::endRead(T& MDS_UNUSED(Object))
{
    MDS_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    m_spActiveChannel->flush();
}


template <typename T>
void CBinarySerializer::read(T& Value)
{
    MDS_STATIC_ASSERT(mds::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_VALUE);

    if( m_spActiveChannel->read((char *)&Value, (int)sizeof(T)) != (int)sizeof(T) )
    {
        throw Serializer::CReadFailed();
    }
}


template <typename T>
void CBinarySerializer::read(T *pData, tSize Length)
{
//    MDS_STATIC_ASSERT(mds::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_DATA);

    int Size = (int)Length * (int)sizeof(T);

    if( m_spActiveChannel->read((char *)pData, Size) != Size )
    {
        throw Serializer::CReadFailed();
    }
}

