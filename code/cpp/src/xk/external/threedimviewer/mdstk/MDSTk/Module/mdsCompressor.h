//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/03/03                          \n
 *
 * $Id: mdsCompressor.h 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - Channel compression tools.
 */

#ifndef MDS_COMPRESSOR_H
#define MDS_COMPRESSOR_H

#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsChannel.h"
#include "mdsCompressionMethods.h"

// STL
#include <string>


namespace mds
{
namespace mod
{

//==============================================================================
/*!
 * Abstract class encapsulating a channel compressor.
 */
class MDS_MODULE_EXPORT CChannelCompressor : public CChannel
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CChannelCompressor);

public:
    //! Default constructor.
    //! - Compression type.
    //! - Pointer to an output/input channel.
    CChannelCompressor(int CompressionMethod, CChannel *pChannel = NULL)
        : m_ChannelCompression(CompressionMethod)
        , m_spChannel(pChannel)
    {
        if( pChannel )
        {
            m_Type = CH_COMPRESSOR | pChannel->getType();
            m_Medium = pChannel->getMedium();
        }
    }

    //! Virtual destructor
    virtual ~CChannelCompressor() {}

    //! Returns the compression method.
    int getCompressionMethod() const { return m_ChannelCompression; }

    //! Returns pointer to the input/output channel.
    CChannel *getChannel() { return m_spChannel.get(); }

    //! Sets the input/output channel.
    virtual void setChannel(CChannel *pChannel)
    {
        m_spChannel = pChannel;
        if( pChannel )
        {
            m_Type = CH_COMPRESSOR | pChannel->getType();
            m_Medium = pChannel->getMedium();
        }
    }


    //! Connects to the opposite channel side.
    //! - Returns false on failure and/or timeout elapsed.
    virtual bool connect(unsigned uTimeout = CH_CONNECTION_TIMEOUT)
    {
        return (m_spChannel.get() && m_spChannel->connect(uTimeout));
    }

    //! Listens for the opposite channel side.
    //! - Returns false on failure and/or timeout elapsed.
    virtual bool listen(unsigned uTimeout = CH_CONNECTION_TIMEOUT)
    {
        return (m_spChannel.get() && m_spChannel->listen(uTimeout));
    }

    //! Disconnects from the opossite channel side.
    virtual void disconnect() { m_spChannel->disconnect(); }

    //! Method for testing channel errors such as:
    //! - Disconnected or broken channel.
    //! - Reading after end of input.
    virtual bool isConnected() { return (m_spChannel.get() && m_spChannel->isConnected()); }


    //! Waits for data.
    //! - Returns false if a timeout elapses and/or the channel is not input.
    virtual bool wait(unsigned MDS_UNUSED(uTimeout))
    {
        return m_spChannel->wait();
    }

    //! Reads and decompresses data from the input channel.
    //! - In case of error or reading after end of input
    //!   the number of successfully readed bytes is returned.
    virtual int read(char *pcData, int iLength) = 0;

    //! Writes compressed data to the output channel.
    virtual bool write(const char *pcData, int iLength) = 0;

    //! Finalizes all writing operations (flushes internal buffers, etc.).
    virtual bool flush()
    {
        return (m_spChannel.get() && m_spChannel->flush());
    }


    //! Channel compressor creation function.
    //! - Hides call to the CCompressorFactory.
    //! - Throws exception on failure!
    static CChannelCompressor *create(int CompressionMethod, CChannel *pChannel);

protected:
    //! Compression method.
    int m_ChannelCompression;

    //! Output/input channel.
    CChannelPtr m_spChannel;
};


//==============================================================================
/*!
 * Smart pointer to channel compressor.
 */
typedef CChannelCompressor::tSmartPtr  CChannelCompressorPtr;


//==============================================================================
/*!
 * Writes uncompressed data.
 */
class MDS_MODULE_EXPORT CRawCompressor : public CChannelCompressor
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CRawCompressor);

public:
    //! Constructor.
    CRawCompressor(CChannel *pChannel = NULL) : CChannelCompressor(CC_RAW, pChannel) {}

    //! Destructor.
    virtual ~CRawCompressor() { this->flush(); }

    // Vitual methods.
    virtual int read(char *pcData, int iLength)
    {
        return m_spChannel->read(pcData, iLength);
    }
    virtual bool write(const char *pcData, int iLength)
    {
        return m_spChannel->write(pcData, iLength);
    }
};


//==============================================================================
/*!
 * Smart pointer compressor.
 */
typedef CRawCompressor::tSmartPtr   CRawCompressorPtr;


} // namespace mod
} // namespace mds

#endif // MDS_COMPRESSOR_H

