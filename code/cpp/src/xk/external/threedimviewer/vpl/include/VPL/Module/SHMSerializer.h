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
 * Date:    2007/06/21                       
 *
 * Description:
 * - Binary serialization of objects (data entities) over shared memory.
 */

#ifndef VPL_SHMSERIALIZER_H
#define VPL_SHMSERIALIZER_H

#include <VPL/Base/SHMData.h>
#include <VPL/Base/Logging.h>

#include "BinarySerializer.h"


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Various definitions.
 */

namespace Serializer
{

    //! Additional serializer flags.
    enum ESHMOptions
    {
        //! Serialization over shared memory.
        SHM_FLAG = 1 << 2
    };

} // namespace Serializer


//==============================================================================
/*!
 * Fast serialization of data entities and their members over shared memory.
 */
class VPL_MODULE_EXPORT CSHMSerializer
    : public vpl::base::CObject
    , public CChannelSerializer<CSHMSerializer>
{
public:
    //! Base class.
    typedef CChannelSerializer<CSHMSerializer> tBase;

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CSHMSerializer);

public:
    //! Default constructor.
    CSHMSerializer(CSharedMemChannel *pChannel, int iFlags = 0)
        : tBase(pChannel, iFlags | Serializer::SHM_FLAG)
        , m_spActiveChannel(pChannel)
    {}

    //! Destructor.
    ~CSHMSerializer() {}


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

    //! Serializes a block of data stored in a CSHMData<> structure.
    //! - Throws exception on failure.
    template <typename T>
    void write(vpl::base::CSHMData<T>& Value);

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
        getImpl().write( Set.size() );
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

    //! Deserializes a block of data stored in a CSHMData<> structure.
    //! - Throws exception on failure.
    template <typename T>
    void read(vpl::base::CSHMData<T>& Value);

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
        typename std::set<T>::size_type size, i;
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
    CSharedMemChannelPtr m_spActiveChannel;
};


//==============================================================================
/*!
 * Smart pointer to SHM serializer.
 */
typedef CSHMSerializer::tSmartPtr   CCSHMSerializerPtr;


//==============================================================================
/*
 * Methods implementation.
 */
#include "SHMSerializer.hxx"


} // namespace mod
} // namespace vpl

#endif // VPL_SHMSERIALIZER_H

