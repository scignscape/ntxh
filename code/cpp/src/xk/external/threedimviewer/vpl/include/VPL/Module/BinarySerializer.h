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
 * Copyright (c) 2003-2007 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/20                       
 *
 * Description:
 * - Binary serialization of objects (data entities) over channels.
 */

#ifndef VPL_BinarySerializer_H
#define VPL_BinarySerializer_H

#include <VPL/Base/Types.h>

#include "ModuleExport.h"
#include "Serializer.h"
#include "BlockChannel.h"
#include "Compressor.h"

#include <set>

namespace vpl
{
namespace mod
{

//==============================================================================
/*!
 * Serializer which encapsulates serialization of data entities
 * and their members via channels.
 */
class VPL_MODULE_EXPORT CBinarySerializer
    : public vpl::base::CObject
    , public CChannelSerializer<CBinarySerializer>
{
public:
    //! Base class.
    typedef CChannelSerializer<CBinarySerializer> tBase;

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CBinarySerializer);

public:
    //! Default constructor.
    CBinarySerializer(CChannel *pChannel, int iFlags = 0)
        : tBase(pChannel, iFlags)
        , m_spActiveChannel(pChannel)
    {}

    //! Destructor.
    ~CBinarySerializer() {}


    //! Serializes a given data entity.
    //! - Throws exception on failure.
    template <typename T>
    void writeRoot(T& Object);

    //! Creates a new logical group of class members in the serialized data.
    //! - Properties of the group, such as compression method, are chosen according
    //!   to the serialization traits.
    //! - Must be called before any write() method.
    //! - Throws exception on failure.
    template <typename T>
    void beginWrite(T& Object);

    //! End of the logical group.
    //! - Throws exception on failure.
    template <typename T>
    void endWrite(T& Object);

    //! Serializes a given fundamental value.
    //! - Throws exception on failure.
    template <typename T>
    void write(const T& Value);

    //! Serializes a given block of data.
    //! - Throws exception on failure.
    template <typename T>
    void write(const T *pData, tSize Length);

    //! Serializes vector of values
    //! - Throws exception on failure.
    CONTAINER_WRITE( std::vector )
    
    //! Serializes basic string
    //! - Throws exception on failure.
    CONTAINER_WRITE( std::basic_string )

    //! Serializes set of values
    //! - Throws exception on failure.
    template < typename T >
    void write( const std::set<T> & Set )
    {
        getImpl().write( vpl::sys::tUInt64(Set.size()) );
        typename std::set<T>::const_iterator it, itEnd( Set.end() );
        for( it = Set.begin(); it != itEnd; ++it )
        {
            getImpl().write( *it );
        }
    }
    

    //! Deserializes a given data entity.
    //! - Throws exception on failure.
    template <typename T>
    void readRoot(T& Object);

    //! Reads information on logical group of class members from the serialized data.
    //! - Must be called before any read() method.
    //! - Throws exception on failure.
    template <typename T>
    void beginRead(T& Object);

    //! Reads end of the logical group.
    //! - Throws exception on failure.
    template <typename T>
    void endRead(T& Object);

    //! Deserializes a given fundamental value.
    //! - Throws exception on failure.
    template <typename T>
    void read(T& Value);

    //! Deserializes a given block of data.
    //! - Throws exception on failure.
    template <typename T>
    void read(T *pData, tSize Length);

    //! Deserializes vector of values
    //! - Throws exception on failure.
    CONTAINER_READ( std::vector )
    
    //! Deserializes basic string
    //! - Throws exception on failure.
    CONTAINER_READ( std::basic_string )

    //! Deserializes set of values
    //! - Throws exception on failure.
    template <typename T>
    void read( std::set<T> & Set )
    {
        vpl::sys::tUInt64 size, i;
        getImpl().read(size);
        for( i = 0; i < size; ++i )
        {
            T aux;
            getImpl().read(aux);
            Set.insert(aux);
        }
    }

protected:
    //! Smart pointer to actively used channel.
    CChannelPtr m_spActiveChannel;
};


//==============================================================================
/*!
 * Smart pointer to binary serializer.
 */
typedef CBinarySerializer::tSmartPtr   CBinarySerializerPtr;


//==============================================================================
/*
 * Global functions.
 */

namespace BinarySerializer
{

//! Writes data entity header to a binary channel.
//! - Returns false on failure.
VPL_MODULE_EXPORT bool writeEntityHeader(CChannel& Channel);

//! Reads and checks the data entity header.
//! - Returns false on failure.
VPL_MODULE_EXPORT bool readEntityHeader(CChannel& Channel);

//! Writes header of data entity logical group.
//! - Returns false on failure.
VPL_MODULE_EXPORT bool writeGroupHeader(CChannel& Channel,
                                        const char *pcName,
                                        int Compression,
                                        int BlockSize
                                        );

//! Reads and decodes header of data entity group.
//! - Returns false on failure.
VPL_MODULE_EXPORT bool readGroupHeader(CChannel& Channel,
                                       const char *pcName,
                                       int& Compression,
                                       int& BlockSize
                                       );

//! Writes terminal to a binary channel.
//! - Returns false on failure.
VPL_MODULE_EXPORT bool writeTerminal(CChannel& Channel);

//! Finds and reads terminal.
//! - Returns false on failure.
VPL_MODULE_EXPORT bool readTerminal(CChannel& Channel);

} // namespace BinarySerializer


//==============================================================================
/*
 * Implementation...
 */
#include "BinarySerializer.hxx"


} // namespace mod
} // namespace vpl

#endif // VPL_BinarySerializer_H

