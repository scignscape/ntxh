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

#include <VPL/Module/BlockChannel.h>

#include <VPL/System/Memory.h>
#include <VPL/System/SystemTypes.h>
#include <VPL/Math/Base.h>


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Various global definitions and constants.
 */

//! Data entity magic number.
const vpl::sys::tUInt32 CH_MAGIC    = 0x5a53;


//==============================================================================
/*
 * Definition of data block header.
 */

//! Data block header.
struct SBlockHeader
{
    //! Magic number.
    vpl::sys::tUInt32 m_Magic;

    //! Block size.
    vpl::sys::tInt32 m_Size;
};


//==============================================================================
/*
 * Implementation of the class CBlockChannel.
 */
CBlockChannel::CBlockChannel(tSize iBlockSize, CChannel *pChannel, bool bNoLocking)
    : m_iBlockSize(iBlockSize)
    , m_iNumOfBytes(0)
    , m_bFinished(false)
    , m_spChannel(pChannel)
    , m_Buffer(EMPTY_CONST)
    , m_bUseLock(!bNoLocking)
{
    // Check the minimal allowed block size
    if( m_iBlockSize < 64 )
    {
        m_iBlockSize = 64;
    }

    // Allocate the buffer
    m_Buffer.resize(m_iBlockSize);

    // Initialize pointer to the data
    m_pcData = m_Buffer.getPtr();

    if( pChannel )
    {
        m_Type = pChannel->getType();
        m_Medium = pChannel->getMedium();

        // Initialize the number of bytes
        if( m_Type & CH_OUT )
        {
            m_iNumOfBytes = m_iBlockSize;
        }
    }
}


CBlockChannel::~CBlockChannel()
{
    CBlockChannel::flush();
}


void CBlockChannel::setChannel(CChannel *pChannel)
{
    m_spChannel = pChannel;

    if( pChannel )
    {
        m_Type = pChannel->getType();
        m_Medium = pChannel->getMedium();

        if( m_Type & CH_OUT )
        {
            m_iNumOfBytes = m_iBlockSize;
        }
    }
}


bool CBlockChannel::isConnected()
{
    return (m_spChannel.get() && m_spChannel->isConnected());
}

tSize CBlockChannel::read(char *pcData, tSize iLength)
{
    if (m_bUseLock)
    {
        tLock Lock(*this);
        return read_nolock(pcData, iLength);
    }
    else
    {
        return read_nolock(pcData, iLength);
    }
}


tSize CBlockChannel::read_nolock(char *pcData, tSize iLength)
{
    VPL_CHECK(pcData && iLength > 0, return 0);

    if( (m_Type & CH_IN) == 0 )
    {
        return 0;
    }

    tSize iLeft = iLength;
    while( iLeft > 0 )
    {
        if( m_iNumOfBytes > 0 )
        {
            tSize iCount = (iLeft > m_iNumOfBytes) ? m_iNumOfBytes : iLeft;
            vpl::sys::memCopy(pcData, m_pcData, iCount);
            m_iNumOfBytes -= iCount;
			iLeft -= iCount;
            m_pcData += iCount;
			pcData += iCount;
        }
        else
        {
			// Check the finished flag
            if( m_bFinished )
            {
                break;
            }

            // Read size of the block
            tSize iSize;
            if( !readBlockHeader(iSize) )
            {
                break;
            }

            // Check size of the block
            if( iSize > m_iBlockSize || iSize < 0 )
            {
                break;
            }

            // Read the data
            m_pcData = m_Buffer.getPtr();
            if( m_spChannel->read(m_pcData, iSize) != iSize )
            {
                break;
            }
            m_iNumOfBytes = iSize;

			// Check if the last block was found
			if( iSize < m_iBlockSize )
            {
                m_bFinished = true;
            }
        }
    }

    return (iLength - iLeft);
}

bool CBlockChannel::write(const char *pcData, tSize iLength)
{
    if (m_bUseLock)
    {
        tLock Lock(*this);
        return write_nolock(pcData, iLength);
    }
    else
    {
        return write_nolock(pcData, iLength);
    }
}


bool CBlockChannel::write_nolock(const char *pcData, tSize iLength)
{
    VPL_CHECK(pcData && iLength >= 0, return false);

    if( (m_Type & CH_OUT) == 0 )
    {
        return 0;
    }

    tSize iLeft = iLength;
    while( iLeft > 0 )
    {
        if( m_iNumOfBytes > 0 )
        {
            tSize iCount = (iLeft > m_iNumOfBytes) ? m_iNumOfBytes : iLeft;
            vpl::sys::memCopy(m_pcData, pcData, iCount);
            m_iNumOfBytes -= iCount;
			iLeft -= iCount;
            m_pcData += iCount;
            pcData += iCount;
        }
        else
        {
			// Clear the flag
			m_bFinished = false;

			// Write size of the block
            if( !writeBlockHeader(m_iBlockSize) )
            {
                break;
            }

            // Write block
            m_pcData = m_Buffer.getPtr();
            if( !m_spChannel->write(m_pcData, m_iBlockSize) )
            {
                break;
            }
            m_iNumOfBytes = m_iBlockSize;
        }
    }

    return (iLeft == 0);
}

bool CBlockChannel::flush()
{
    if (m_bUseLock)
    {
        tLock Lock(*this);
        return flush_nolock();
    }
    else
    {
        return flush_nolock();
    }
}

bool CBlockChannel::flush_nolock()
{
    if( m_bFinished )
    {
        return true;
    }

    if( m_Type & CH_IN )
    {
        if( !m_spChannel->isConnected() )
        {
            return false;
        }

        while( !m_bFinished )
        {
            // Read all blocks until an empty one or partially filled one is found
            tSize iSize;
            if( !readBlockHeader(iSize) )
            {
                return false;
            }

            // Check size of the block
            if( iSize > m_iBlockSize || iSize < 0 )
            {
                return false;
            }
            else if( iSize < m_iBlockSize )
            {
                m_bFinished = true;
            }

            // Skip the data
            if( !m_spChannel->skip(iSize) )
            {
                return false;
            }
        }

        // O.K.
        return true;
    }
    else if( m_Type & CH_OUT )
    {
        if( !m_spChannel->isConnected() )
        {
            return false;
        }

        // Write size of the block
        if( !writeBlockHeader(m_iBlockSize - m_iNumOfBytes) )
        {
            return false;
        }

        // Write block data
        m_pcData = m_Buffer.getPtr();
        if( !m_spChannel->write(m_pcData, m_iBlockSize - m_iNumOfBytes) )
        {
            return false;
        }

        // Write one more empty block if the last one was fully occupied
        if( m_iNumOfBytes == 0 )
        {
            if( !writeBlockHeader(0) )
            {
                return false;
            }
        }

        m_bFinished = true;

        // Flush the output channel
        return m_spChannel->flush();
    }
    else
    {
        return false;
    }
}


bool CBlockChannel::writeBlockHeader(tSize iSize)
{
    // Initialize data block header
    SBlockHeader Header;
    Header.m_Magic = CH_MAGIC;
    Header.m_Size = vpl::sys::tInt32(iSize);

    // Write the header
    if( !m_spChannel->write((char *)&Header, (tSize)sizeof(Header)) )
    {
        return false;
    }

    // O.K.
    return true;
}


bool CBlockChannel::readBlockHeader(tSize& iSize)
{
    // Read the data block header
    SBlockHeader Header;
    tSize HeaderSize = (tSize)sizeof(Header);
    if( m_spChannel->read((char *)&Header, HeaderSize) != HeaderSize )
    {
        return false;
    }

    // Check the magic number
    if( Header.m_Magic != CH_MAGIC )
    {
        return false;
    }
    iSize = tSize(Header.m_Size);

    // O.K.
    return true;
}


} // namespace mod
} // namespace vpl

