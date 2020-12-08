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
 * Date:    2007/06/18                       
 *
 * Description:
 * - Serialization of objects (data entities).
 * - Hides representation details from serializable objects.
 */

#ifndef VPL_Serializer_H
#define VPL_Serializer_H

#include <VPL/Base/Exception.h>
#include <VPL/Base/HasOptions.h>

#include "SerializationTraits.h"
#include "Progress.h"
#include "Channel.h"

// STL
#include <string>


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

    //! Basic serializer flags.
    enum EOptions
    {
        //! Additional flag which suppresses compression and all data headers.
        RAW_DATA    = 1 << 0,
        //! Additional flag that disables read/write access locking
        NO_LOCKING  = 1 << 1
    };

    //! Exception thrown in case of some read error during deserialization of an object.
    VPL_DECLARE_EXCEPTION(CWriteFailed, "Failed to serialize an object")

    //! Exception thrown in case of some error during deserialization of an object.
    VPL_DECLARE_EXCEPTION(CReadFailed, "Failed to deserialize an object")

} // namespace Serializer


//==============================================================================
/*!
 * Base class for all serializers.
 * - Hides detailes of internal representation from serializable objects.
 * - Base class takes a template parameter S. This parameter is the type
 *   of the class which derives from it (so called curiously recurring template
 *   pattern).
 */
template <class S>
class CChannelSerializer : public vpl::base::CHasOptions, public CProgress
{
public:
    //! Serializer type.
    typedef S tSerializer;

public:
    //! Destructor.
    ~CChannelSerializer() {}

    //! Returns reference to the serializer implementation.
    tSerializer& getImpl()
    {
        return *static_cast<tSerializer *>(this);
    }
    const tSerializer& getImpl() const
    {
        return *static_cast<const tSerializer *>(this);
    }


    //! Returns pointer to the I/O channel.
    CChannel *getChannelPtr() { return m_spChannel.get(); }

    //! Sets the I/O channel.
    void setChannel(CChannel *pChannel) { m_spChannel = pChannel; }


    //! Serializes a given data entity.
    //! - Throws exception on failure.
    //! - Derived classes have to implement this method!
    template <typename T>
    void writeRoot(T& Object)
    {
        getImpl().writeRoot(Object);
    }

    //! Creates a new logical group of class members in the serialized data.
    //! - Properties of the group, such as compression method, are chosen according
    //!   to the serialization traits.
    //! - Must be called before any write() method.
    //! - Throws exception on failure.
    template <typename T>
    void beginWrite(T& Object)
    {
#ifdef _WIN32
        if (m_bBlockEntered)
            __debugbreak();
#else
        VPL_ASSERT(!m_bBlockEntered);
#endif
        m_bBlockEntered = true;
        getImpl().beginWrite(Object);
    }

    //! End of the logical group.
    //! - Throws exception on failure.
    template <typename T>
    void endWrite(T& Object)
    {
        getImpl().endWrite(Object);
        m_bBlockEntered = false;
    }

    //! Serializes a given fundamental value.
    //! - Throws exception on failure.
    //! - Derived classes have to implement this method!
    template <typename T>
    void write(const T& Value)
    {
        getImpl().write(Value);
    }

    //! Serializes a given block of data.
    //! - Throws exception on failure.
    //! - Derived classes have to implement this method!
    template <typename T>
    void write(const T *pData, tSize Length)
    {
        getImpl().write(pData, Length);
    }

    //! Deserializes a given data entity.
    //! - Throws exception on failure.
    //! - Derived classes have to implement this method!
    template <typename T>
    void readRoot(T& Object)
    {
        getImpl().readRoot(Object);
    }

    //! Reads information on logical group of class members from the serialized data.
    //! - Must be called before any read() method.
    //! - Throws exception on failure.
    template <typename T>
    void beginRead(T& Object)
    {
        getImpl().beginRead(Object);
    }

    //! Reads end of the logical group.
    //! - Throws exception on failure.
    template <typename T>
    void endRead(T& Object)
    {
        getImpl().endRead(Object);
    }

    //! Deserializes a given fundamental value.
    //! - Throws exception on failure.
    //! - Derived classes have to implement this method!
    template <typename T>
    void read(T& Value)
    {
        getImpl().read(Value);
    }

    //! Deserializes a given block of data.
    //! - Throws exception on failure.
    //! - Derived classes have to implement this method!
    template <typename T>
    void read(T *pData, tSize Length)
    {
        getImpl().read(pData, Length);
    }

protected:
    //! Pointer to the I/O channel.
    CChannelPtr m_spChannel;
    //! Nesting protection
    bool m_bBlockEntered;

protected:
    //! Hidden constructor.
    CChannelSerializer(CChannel *pChannel, int iFlags = 0)
        : vpl::base::CHasOptions(iFlags)
        , m_spChannel(pChannel)
        , m_bBlockEntered(false)
    {
        VPL_ASSERT(pChannel);
    }

    //! Hidden copy constructor.
    CChannelSerializer(const CChannelSerializer& Serializer)
        : vpl::base::CHasOptions(Serializer.getOptions())
        , m_spChannel(Serializer.m_spChannel)
        , m_bBlockEntered(false)
    {
    }

    //! Hidden assignment operator.
    CChannelSerializer& operator =(const CChannelSerializer& Serializer)
    {
        this->setOptions(Serializer.getOptions());
        m_spChannel = Serializer.m_spChannel;
        return *this;
    }
};


//==============================================================================
/*
 * Helper macro definitions.
 */

#define CONTAINER_WRITE( tpContainer ) \
    template < typename tpElement > \
    void write( const tpContainer< tpElement > & Container ) \
    { \
        getImpl().write( vpl::sys::tUInt64(Container.size()) ); \
        typename tpContainer< tpElement >::const_iterator it, itEnd( Container.end() ); \
        for( it = Container.begin(); it != itEnd; ++it ) \
        { \
            getImpl().write( *it ); \
        } \
    }

#define CONTAINER_READ( tpContainer ) \
    template < typename tpElement > \
    void read( tpContainer< tpElement > & Container ) \
    { \
        vpl::sys::tUInt64 size; \
        getImpl().read( size ); \
        Container.resize( std::size_t(size) ); \
        typename tpContainer< tpElement >::iterator it, itEnd( Container.end() ); \
        for( it = Container.begin(); it != itEnd; ++it ) \
        { \
            getImpl().read(*it); \
        } \
    }


} // namespace mod
} // namespace vpl

#endif // VPL_Serializer_H

