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
 * Copyright (c) 2008 by PGMed@FIT           
 *
 * Author:  Radek Barton, ibarton@fit.vutbr.cz  \n
 * Date:    2008/11/17                       
 *
 * Description:
 * - Channel that reads or writes from allocated memory buffer.
 */

#ifndef VPL_MEMORYCHANNEL_H
#define VPL_MEMORYCHANNEL_H

#include "Channel.h"


namespace vpl
{
namespace mod
{

//==============================================================================
/*!
 * Simple memory channel that keeps all data in a memory buffer.
 */
class VPL_MODULE_EXPORT CMemoryChannel : public CChannel
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CMemoryChannel);

public:
    //! Constructor.
    //! - Creates channel over memory buffer \p data of size \p size.
    //! - If \p data is \p NULL allocates memory internally and manages it
    //!   itself.
    //! - It keeps buffer deallocation to user otherwise.
    CMemoryChannel(const EChannelType type, const tSize length, char * data = NULL);

    //! Virtual destructor.
    virtual ~CMemoryChannel();

    //! Returns pointer to the memory.
    char *getDataPtr();

    //! Returns length of memory buffer.
    tSize getLength();

    //! Returns number of bytes currently read from memory buffer.
    tSize getNumOfReadBytes();

    //! Returns number of bytes currently written to memory buffer.
    tSize getNumOfWrittenBytes();

    //! Sets target data of memory channel and resets read and write index.
    void setDataPtr(const tSize length, char * data = NULL);


    //! Connects to the opposite channel side.
    //! - Returns false on failure and/or timeout elapsed.
	virtual bool connect(unsigned timeout = CH_CONNECTION_TIMEOUT) override;

    //! Listens for and accepts an incoming connection.
    //! - If the channel is connection oriented, this function must be called
    //!   on the server side before any communication!
    //! - Returns false on failure or timeout elapsed.
	virtual bool listen(unsigned uTimeout = CH_CONNECTION_TIMEOUT) override;

    //! Disconnects from the opossite channel side.
    //! - Returns false on failure.
    //! - This method does nothing.
	virtual void disconnect() override;

    //! Method for testing channel errors such as:
    //! - Disconnected or broken channel.
    //! - Reading after end of input.
	virtual bool isConnected() override;


    //! Waits for data.
    //! - Returns false if a timeout elapses and/or the channel is not input.
	virtual bool wait(unsigned timeout = CH_WAIT_TIMEOUT) override;

    //! Reads data from the input channel.
    //! - In case of error or reading after end of input
    //!   the number of successfully readed bytes is returned.
	virtual tSize read(char * data, tSize length) override;

    //! Writes compressed data to the output channel.
    //! - Returns false on failure.
	virtual bool write(const char * data, tSize length) override;

    //! In case of the output channel, the function writes all remaining
    //! data (partially filled or empty block) to the channel.
    //! Otherwise, it skips the remaining data in the channel until en empty
    //! data block or partially filled block is found.
    //! - This method does nothing.
	virtual bool flush() override;

    //! Skips a given number of bytes.
	virtual bool skip(tSize length) override;

protected:
    //! Index of reading from buffer.
    tSize m_iNumOfReadBytes;

    //! Index of write to buffer.
    tSize m_iNumOfWrittenBytes;

    //! Length of memory buffer.
    tSize m_iLength;

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
} // namespace vpl

#endif // VPL_MEMORYCHANNEL_H

