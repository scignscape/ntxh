//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/20                          \n
 *
 * $Id: mdsBinarySerializer.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Binary serialization of objects (data entities) over channels.
 */

#ifndef MDS_BinarySerializer_H
#define MDS_BinarySerializer_H

#include <MDSTk/Base/mdsTypes.h>

#include "mdsModuleExport.h"
#include "mdsSerializer.h"
#include "mdsBlockChannel.h"
#include "mdsCompressor.h"


namespace mds
{
namespace mod
{

//==============================================================================
/*!
 * Serializer which encapsulates serialization of data entities
 * and their members via channels.
 */
class MDS_MODULE_EXPORT CBinarySerializer
    : public mds::base::CObject
    , public CChannelSerializer<CBinarySerializer>
{
public:
    //! Base class.
    typedef CChannelSerializer<CBinarySerializer> tBase;

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CBinarySerializer);

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
MDS_MODULE_EXPORT bool writeEntityHeader(CChannel& Channel);

//! Reads and checks the data entity header.
//! - Returns false on failure.
MDS_MODULE_EXPORT bool readEntityHeader(CChannel& Channel);

//! Writes header of data entity logical group.
//! - Returns false on failure.
MDS_MODULE_EXPORT bool writeGroupHeader(CChannel& Channel,
                                        const char *pcName,
                                        int Compression,
                                        tSize BlockSize
                                        );

//! Reads and decodes header of data entity group.
//! - Returns false on failure.
MDS_MODULE_EXPORT bool readGroupHeader(CChannel& Channel,
                                       const char *pcName,
                                       int& Compression,
                                       tSize& BlockSize
                                       );

//! Writes terminal to a binary channel.
//! - Returns false on failure.
MDS_MODULE_EXPORT bool writeTerminal(CChannel& Channel);

//! Finds and reads terminal.
//! - Returns false on failure.
MDS_MODULE_EXPORT bool readTerminal(CChannel& Channel);

} // namespace BinarySerializer


//==============================================================================
/*
 * Implementation...
 */
#include "mdsBinarySerializer.hxx"


} // namespace mod
} // namespace mds

#endif // MDS_BinarySerializer_H

