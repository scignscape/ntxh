//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/28                          \n
 *
 * $Id: mdsSerialization.hxx 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Serialization of objects (data entities) over channels.
 */


//==============================================================================
/*
 * Implementation...
 */

template <typename T, class S>
bool write(T& Object, CChannelSerializer<S>& Writer)
{
    MDS_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    try {
        Writer.writeRoot(Object);
    }
    catch( const Serializer::CWriteFailed& )
    {
        return false;
    }

    return true;
}


template <typename T>
bool write(T& Object, CChannel& Channel, int iFlags)
{
    // Check the channel type
    if( Channel.getMedium() == CH_SHM )
    {
        // SHM serializer
        CSHMSerializer Writer(static_cast<CSharedMemChannel *>(&Channel), iFlags);
        return write(Object, Writer);
    }
#ifdef MDS_USE_XML_SERIALIZER
    else if( iFlags & Serializer::XML )
    {
        // XML serializer
        CXMLSerializer Writer(&Channel, iFlags);
        return write(Object, Writer);
    }
#endif // MDS_USE_XML_SERIALIZER
    else
    {
        // Common binary serializer
        CBinarySerializer Writer(&Channel, iFlags);
        return write(Object, Writer);
    }
}


template <typename T>
bool write(T& Object,
           CChannel& Channel,
           CProgress::tProgressFunc& Progress,
           int iFlags
           )
{
    // Check the channel type
    if( Channel.getMedium() == CH_SHM )
    {
        // SHM serializer
        CSHMSerializer Writer(static_cast<CSharedMemChannel *>(&Channel), iFlags);
        return write(Object, Writer);
    }
#ifdef MDS_USE_XML_SERIALIZER
    else if( iFlags & Serializer::XML )
    {
        // XML serializer
        CXMLSerializer Writer(&Channel, iFlags);
        Writer.registerProgressFunc(Progress);
        return write(Object, Writer);
    }
#endif // MDS_USE_XML_SERIALIZER
    else
    {
        // Common binary serializer
        CBinarySerializer Writer(&Channel, iFlags);
        Writer.registerProgressFunc(Progress);
        return write(Object, Writer);
    }
}


template <typename T>
bool save(T& Object, const std::string& ssFilename, int iFlags)
{
    // Open output file channel
    mds::mod::CFileChannel Channel(mds::mod::CH_OUT, ssFilename);
    if( !Channel.connect() )
    {
        return false;
    }

    return write(Object, Channel, iFlags);
}


template <typename T, class S>
bool read(T& Object, CChannelSerializer<S>& Reader)
{
    try {
        Reader.readRoot(Object);
    }
    catch( const Serializer::CReadFailed& )
    {
        return false;
    }

    return true;
}


template <typename T>
bool read(T& Object, CChannel& Channel, int iFlags)
{
    // Check the channel type
    if( Channel.getMedium() == CH_SHM )
    {
        // SHM serializer
        CSHMSerializer Reader(static_cast<CSharedMemChannel *>(&Channel), iFlags);
        return read(Object, Reader);
    }
#ifdef MDS_USE_XML_SERIALIZER
    else if( iFlags & Serializer::XML )
    {
        // Common channel serializer
        CXMLSerializer Reader(&Channel, iFlags);
        return read(Object, Reader);
    }
#endif // MDS_USE_XML_SERIALIZER
    else
    {
        // Common channel serializer
        CBinarySerializer Reader(&Channel, iFlags);
        return read(Object, Reader);
    }
}


template <typename T>
bool read(T& Object,
          CChannel& Channel,
          CProgress::tProgressFunc& Progress,
          int iFlags
          )
{
    // Check the channel type
    if( Channel.getMedium() == CH_SHM )
    {
        // SHM serializer
        CSHMSerializer Reader(static_cast<CSharedMemChannel *>(&Channel), iFlags);
        return read(Object, Reader);
    }
#ifdef MDS_USE_XML_SERIALIZER
    else if( iFlags & Serializer::XML )
    {
        // Common channel serializer
        CXMLSerializer Reader(&Channel, iFlags);
        Reader.registerProgressFunc(Progress);
        return read(Object, Reader);
    }
#endif // MDS_USE_XML_SERIALIZER
    else
    {
        // Common channel serializer
        CBinarySerializer Reader(&Channel, iFlags);
        Reader.registerProgressFunc(Progress);
        return read(Object, Reader);
    }
}


template <typename T>
bool load(T& Object, const std::string& ssFilename, int iFlags)
{
    // Open input file channel
    mds::mod::CFileChannel Channel(mds::mod::CH_IN, ssFilename);
    if( !Channel.connect() )
    {
        return false;
    }

    return read(Object, Channel, iFlags);
}

