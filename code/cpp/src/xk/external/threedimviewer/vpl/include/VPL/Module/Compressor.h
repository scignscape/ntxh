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
 * Date:    2005/03/03                       
 *
 * Description:
 * - Channel compression tools.
 */

#ifndef VPL_COMPRESSOR_H
#define VPL_COMPRESSOR_H

#include <VPL/Base/Types.h>
#include <VPL/Base/Assert.h>
#include <VPL/Base/SharedPtr.h>

#include "Channel.h"
#include "CompressionMethods.h"

// STL
#include <string>


namespace vpl
{
namespace mod
{

//==============================================================================
/*!
 * Abstract class encapsulating a channel compressor.
 */
class VPL_MODULE_EXPORT CChannelCompressor : public CChannel
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CChannelCompressor);

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
    virtual bool connect(unsigned uTimeout = CH_CONNECTION_TIMEOUT) override
    {
        return (m_spChannel.get() && m_spChannel->connect(uTimeout));
    }

    //! Listens for the opposite channel side.
    //! - Returns false on failure and/or timeout elapsed.
	virtual bool listen(unsigned uTimeout = CH_CONNECTION_TIMEOUT) override
    {
        return (m_spChannel.get() && m_spChannel->listen(uTimeout));
    }

    //! Disconnects from the opossite channel side.
	virtual void disconnect() override { m_spChannel->disconnect(); }

    //! Method for testing channel errors such as:
    //! - Disconnected or broken channel.
    //! - Reading after end of input.
	virtual bool isConnected() override { return (m_spChannel.get() && m_spChannel->isConnected()); }


    //! Waits for data.
    //! - Returns false if a timeout elapses and/or the channel is not input.
	virtual bool wait(unsigned VPL_UNUSED(uTimeout)) override
    {
        return m_spChannel->wait();
    }

    //! Reads and decompresses data from the input channel.
    //! - In case of error or reading after end of input
    //!   the number of successfully readed bytes is returned.
    virtual tSize read(char *pcData, tSize iLength) = 0;

    //! Writes compressed data to the output channel.
    virtual bool write(const char *pcData, tSize iLength) = 0;

    //! Finalizes all writing operations (flushes internal buffers, etc.).
	virtual bool flush() override
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
class VPL_MODULE_EXPORT CRawCompressor : public CChannelCompressor
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CRawCompressor);

public:
    //! Constructor.
    CRawCompressor(CChannel *pChannel = NULL) : CChannelCompressor(CC_RAW, pChannel) {}

    //! Destructor.
    virtual ~CRawCompressor() { this->flush(); }

    // Vitual methods.
	virtual tSize read(char *pcData, tSize iLength) override
    {
        return m_spChannel->read(pcData, iLength);
    }
	virtual bool write(const char *pcData, tSize iLength) override
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
} // namespace vpl

#endif // VPL_COMPRESSOR_H

