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
 * Date:    2009/03/28                       
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
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

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
#ifdef VPL_USE_XML_SERIALIZER
    else if( iFlags & Serializer::XML )
    {
        // XML serializer
        CXMLSerializer Writer(&Channel, iFlags);
        return write(Object, Writer);
    }
#endif // VPL_USE_XML_SERIALIZER
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
#ifdef VPL_USE_XML_SERIALIZER
    else if( iFlags & Serializer::XML )
    {
        // XML serializer
        CXMLSerializer Writer(&Channel, iFlags);
        Writer.registerProgressFunc(Progress);
        return write(Object, Writer);
    }
#endif // VPL_USE_XML_SERIALIZER
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
    vpl::mod::CFileChannel Channel(vpl::mod::CH_OUT, ssFilename);
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
#ifdef VPL_USE_XML_SERIALIZER
    else if( iFlags & Serializer::XML )
    {
        // Common channel serializer
        CXMLSerializer Reader(&Channel, iFlags);
        return read(Object, Reader);
    }
#endif // VPL_USE_XML_SERIALIZER
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
#ifdef VPL_USE_XML_SERIALIZER
    else if( iFlags & Serializer::XML )
    {
        // Common channel serializer
        CXMLSerializer Reader(&Channel, iFlags);
        Reader.registerProgressFunc(Progress);
        return read(Object, Reader);
    }
#endif // VPL_USE_XML_SERIALIZER
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
    vpl::mod::CFileChannel Channel(vpl::mod::CH_IN, ssFilename);
    if( !Channel.connect() )
    {
        return false;
    }

    return read(Object, Channel, iFlags);
}

