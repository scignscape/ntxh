//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/21                          \n
 *
 * $Id: mdsSHMSerializer.h 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - Binary serialization of objects (data entities) over shared memory.
 */

#ifndef MDS_SHMSERIALIZER_H
#define MDS_SHMSERIALIZER_H

#include <MDSTk/Base/mdsSHMData.h>
#include <MDSTk/Base/mdsGlobalLog.h>

#include "mdsBinarySerializer.h"


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
class MDS_MODULE_EXPORT CSHMSerializer
    : public mds::base::CObject
    , public CChannelSerializer<CSHMSerializer>
{
public:
    //! Base class.
    typedef CChannelSerializer<CSHMSerializer> tBase;

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CSHMSerializer);

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
    void write(mds::base::CSHMData<T>& Value);


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
    void read(mds::base::CSHMData<T>& Value);

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
#include "mdsSHMSerializer.hxx"


} // namespace mod
} // namespace mds

#endif // MDS_SHMSERIALIZER_H

