//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2008 by PGMed@FIT              \n
 *
 * Author:  Radek Barton, ibarton@fit.vutbr.cz  \n
 * Date:    2008/11/17                          \n
 *
 * $Id: mdsMemoryChannel.h 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - Channel that reads or writes from allocated memory buffer.
 */

#ifndef MDS_MEMORYCHANNEL_H
#define MDS_MEMORYCHANNEL_H

#include "mdsChannel.h"


namespace mds
{
namespace mod
{

//==============================================================================
/*!
 * Simple memory channel that keeps all data in a memory buffer.
 */
class MDS_MODULE_EXPORT CMemoryChannel : public CChannel
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CMemoryChannel);

public:
    //! Constructor.
    //! - Creates channel over memory buffer \p data of size \p size.
    //! - If \p data is \p NULL allocates memory internally and manages it
    //!   itself.
    //! - It keeps buffer deallocation to user otherwise.
    CMemoryChannel(const EChannelType type, const int length, char * data = NULL);

    //! Virtual destructor.
    virtual ~CMemoryChannel();

    //! Returns pointer to the memory.
    char *getDataPtr();

    //! Returns length of memory buffer.
    int getLength();

    //! Returns number of bytes currently read from memory buffer.
    int getNumOfReadBytes();

    //! Returns number of bytes currently written to memory buffer.
    int getNumOfWrittenBytes();

    //! Sets target data of memory channel and resets read and write index.
    void setDataPtr(const int length, char * data = NULL);


    //! Connects to the opposite channel side.
    //! - Returns false on failure and/or timeout elapsed.
    virtual bool connect(unsigned timeout = CH_CONNECTION_TIMEOUT);

    //! Listens for and accepts an incoming connection.
    //! - If the channel is connection oriented, this function must be called
    //!   on the server side before any communication!
    //! - Returns false on failure or timeout elapsed.
    virtual bool listen(unsigned uTimeout = CH_CONNECTION_TIMEOUT);

    //! Disconnects from the opossite channel side.
    //! - Returns false on failure.
    //! - This method does nothing.
    virtual void disconnect();

    //! Method for testing channel errors such as:
    //! - Disconnected or broken channel.
    //! - Reading after end of input.
    virtual bool isConnected();


    //! Waits for data.
    //! - Returns false if a timeout elapses and/or the channel is not input.
    virtual bool wait(unsigned timeout = CH_WAIT_TIMEOUT);

    //! Reads data from the input channel.
    //! - In case of error or reading after end of input
    //!   the number of successfully readed bytes is returned.
    virtual int read(char * data, int length);

    //! Writes compressed data to the output channel.
    //! - Returns false on failure.
    virtual bool write(const char * data, int length);

    //! In case of the output channel, the function writes all remaining
    //! data (partially filled or empty block) to the channel.
    //! Otherwise, it skips the remaining data in the channel until en empty
    //! data block or partially filled block is found.
    //! - This method does nothing.
    virtual bool flush();

    //! Skips a given number of bytes.
    virtual bool skip(int length);

protected:
    //! Index of reading from buffer.
    int m_iNumOfReadBytes;

    //! Index of write to buffer.
    int m_iNumOfWrittenBytes;

    //! Length of memory buffer.
    int m_iLength;

    //! Pointer to memory buffer.
    char * m_pcData;

    //! Memory buffer owner flag.
    bool m_bBufferOwner;
};


//==============================================================================
/*!
 * Smart pointer to memory channel.
 */
typedef CMemoryChannel::tSmartPtr CMemoryChannelPtr;


} // namespace mod
} // namespace mds

#endif // MDS_MEMORYCHANNEL_H

