//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/12/08                          \n
 *
 * $Id: mdsBlockChannel.h 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - Buffered channel organizing data into blocks.
 */

#ifndef MDS_BLOCKCHANNEL_H
#define MDS_BLOCKCHANNEL_H

#include <MDSTk/Base/mdsData.h>

#include "mdsModuleExport.h"
#include "mdsChannel.h"


namespace mds
{
namespace mod
{

//==============================================================================
/*!
 * Buffered channel organizing data into blocks of predefined size.
 */
class MDS_MODULE_EXPORT CBlockChannel : public CChannel
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CBlockChannel);

    //! Default block size.
    enum { DEFAULT_BLOCK_SIZE = 4096 };

public:
    //! Default constructor.
    //! - Predefined block size.
    //! - Pointer to an output/input channel.
    CBlockChannel(int iBlockSize = DEFAULT_BLOCK_SIZE, CChannel *pChannel = NULL);

    //! Virtual destructor
    virtual ~CBlockChannel();

    //! Returns data block size.
    int getBlockSize() const { return m_iBlockSize; }

    //! Returns pointer to the input/output channel.
    CChannel *getChannel() { return m_spChannel.get(); }

    //! Sets the input/output channel.
    void setChannel(CChannel *pChannel);


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
    //! - Returns false on failure.
    virtual void disconnect() { m_spChannel->disconnect(); }

    //! Method for testing channel errors such as:
    //! - Disconnected or broken channel.
    //! - Reading after end of input.
    virtual bool isConnected();


    //! Waits for data.
    //! - Returns false if a timeout elapses and/or the channel is not input.
    virtual bool wait(unsigned MDS_UNUSED(uTimeout))
    {
        return m_spChannel->wait();
    }

    //! Reads data from the input channel.
    //! - In case of error or reading after end of input
    //!   the number of successfully readed bytes is returned.
    virtual int read(char *pcData, int iLength);

    //! Writes compressed data to the output channel.
    //! - Returns false on failure.
    virtual bool write(const char *pcData, int iLength);

    //! In case of the output channel, the function writes all remaining
    //! data (partially filled or empty block) to the channel.
    //! Otherwise, it skips the remaining data in the channel until en empty
    //! data block or partially filled block is found.
    virtual bool flush();

protected:
    //! Size of the block.
    int m_iBlockSize;

    //! Pointer to the data.
    char *m_pcData;

    //! The number of free (or unread) bytes in the block.
    int m_iNumOfBytes;

    //! Flag set to true if an empty or partially filled block was found.
    bool m_bFinished;

    //! Output/input channel.
    CChannelPtr m_spChannel;

    //! Internal buffer (data block).
    mds::base::CData<char> m_Buffer;

protected:
    //! Writes data block header to the channel.
    //! - Returns false on failure.
    bool writeBlockHeader(int iSize);

    //! Reads and checks the data block header.
    //! - Returns false on failure.
    bool readBlockHeader(int& iSize);
};


//==============================================================================
/*!
 * Smart pointer to channel BlockChannel.
 */
typedef CBlockChannel::tSmartPtr  CBlockChannelPtr;


} // namespace mod
} // namespace mds

#endif // MDS_BLOCKCHANNEL_H

