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
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/12/08                       
 *
 * Description:
 * - Buffered channel organizing data into blocks.
 */

#ifndef VPL_BLOCKCHANNEL_H
#define VPL_BLOCKCHANNEL_H

#include <VPL/Base/Data.h>

#include "ModuleExport.h"
#include "Channel.h"


namespace vpl
{
namespace mod
{

//==============================================================================
/*!
 * Buffered channel organizing data into blocks of predefined size.
 */
class VPL_MODULE_EXPORT CBlockChannel : public CChannel
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CBlockChannel);

    //! Default block size.
    enum { DEFAULT_BLOCK_SIZE = 4096 };

public:
    //! Default constructor.
    //! - Predefined block size.
    //! - Pointer to an output/input channel.
    CBlockChannel(tSize iBlockSize = DEFAULT_BLOCK_SIZE, CChannel *pChannel = NULL, bool bNoLocking = false);

    //! Virtual destructor
    virtual ~CBlockChannel();

    //! Returns data block size.
    tSize getBlockSize() const { return m_iBlockSize; }

    //! Returns pointer to the input/output channel.
    CChannel *getChannel() { return m_spChannel.get(); }

    //! Sets the input/output channel.
    void setChannel(CChannel *pChannel);


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
    //! - Returns false on failure.
	virtual void disconnect() override { m_spChannel->disconnect(); }

    //! Method for testing channel errors such as:
    //! - Disconnected or broken channel.
    //! - Reading after end of input.
	virtual bool isConnected() override;


    //! Waits for data.
    //! - Returns false if a timeout elapses and/or the channel is not input.
	virtual bool wait(unsigned VPL_UNUSED(uTimeout)) override
    {
        return m_spChannel->wait();
    }

    //! Reads data from the input channel.
    //! - In case of error or reading after end of input
    //!   the number of successfully readed bytes is returned.
	virtual tSize read(char *pcData, tSize iLength) override;

    //! Writes compressed data to the output channel.
    //! - Returns false on failure.
	virtual bool write(const char *pcData, tSize iLength) override;

    //! In case of the output channel, the function writes all remaining
    //! data (partially filled or empty block) to the channel.
    //! Otherwise, it skips the remaining data in the channel until en empty
    //! data block or partially filled block is found.
	virtual bool flush() override;

protected:
    //! Size of the block.
    tSize m_iBlockSize;

    //! Pointer to the data.
    char *m_pcData;

    //! The number of free (or unread) bytes in the block.
    tSize m_iNumOfBytes;

    //! Flag set to true if an empty or partially filled block was found.
    bool m_bFinished;

    //! Output/input channel.
    CChannelPtr m_spChannel;

    //! Internal buffer (data block).
    vpl::base::CData<char> m_Buffer;

    //! Use lock for read/write access
    bool m_bUseLock;

protected:
    //! Writes data block header to the channel.
    //! - Returns false on failure.
    bool writeBlockHeader(tSize iSize);

    //! Reads and checks the data block header.
    //! - Returns false on failure.
    bool readBlockHeader(tSize& iSize);

    //! Reads data from the input channel.
        //! - In case of error or reading after end of input
        //!   the number of successfully readed bytes is returned.
    inline tSize read_nolock(char *pcData, tSize iLength);

    //! Writes compressed data to the output channel.
    //! - Returns false on failure.
    inline bool write_nolock(const char *pcData, tSize iLength);

    //! In case of the output channel, the function writes all remaining
    //! data (partially filled or empty block) to the channel.
    //! Otherwise, it skips the remaining data in the channel until en empty
    //! data block or partially filled block is found.
    inline bool flush_nolock();
};


//==============================================================================
/*!
 * Smart pointer to channel BlockChannel.
 */
typedef CBlockChannel::tSmartPtr  CBlockChannelPtr;


} // namespace mod
} // namespace vpl

#endif // VPL_BLOCKCHANNEL_H

