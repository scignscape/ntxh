//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/18                          \n
 *
 * $Id: mdsSerializer.h 2092 2012-02-15 12:50:59Z spanel $
 *
 * Description:
 * - Serialization of objects (data entities).
 * - Hides representation details from serializable objects.
 */

#ifndef MDS_Serializer_H
#define MDS_Serializer_H

#include <MDSTk/Base/mdsException.h>
#include <MDSTk/Base/mdsHasOptions.h>

#include "mdsSerializationTraits.h"
#include "mdsProgress.h"
#include "mdsChannel.h"

// STL
#include <string>


namespace mds
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
        RAW_DATA    = 1 << 0
    };

    //! Exception thrown in case of some read error during deserialization of an object.
    MDS_DECLARE_EXCEPTION(CWriteFailed, "Failed to serialize an object")

    //! Exception thrown in case of some error during deserialization of an object.
    MDS_DECLARE_EXCEPTION(CReadFailed, "Failed to deserialize an object")

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
class CChannelSerializer : public mds::base::CHasOptions, public CProgress
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
        getImpl().beginWrite(Object);
    }

    //! End of the logical group.
    //! - Throws exception on failure.
    template <typename T>
    void endWrite(T& Object)
    {
        getImpl().endWrite(Object);
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

protected:
    //! Hidden constructor.
    CChannelSerializer(CChannel *pChannel, int iFlags = 0)
        : mds::base::CHasOptions(iFlags)
        , m_spChannel(pChannel)
    {
        MDS_ASSERT(pChannel);
    }

    //! Hidden copy constructor.
    CChannelSerializer(const CChannelSerializer& Serializer)
        : mds::base::CHasOptions(Serializer.getOptions())
        , m_spChannel(Serializer.m_spChannel)
    {}

    //! Hidden assignment operator.
    CChannelSerializer& operator =(const CChannelSerializer& Serializer)
    {
        this->setOptions(Serializer.getOptions());
        m_spChannel = Serializer.m_spChannel;
        return *this;
    }
};


} // namespace mod
} // namespace mds

#endif // MDS_Serializer_H

