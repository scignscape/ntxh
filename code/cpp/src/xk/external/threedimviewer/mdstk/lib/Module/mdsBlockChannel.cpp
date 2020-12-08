//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/12/08                          \n
 *
 * $Id: mdsBlockChannel.cpp 1707 2010-05-05 11:00:46Z spanel $
 *
 * Description:
 * - Buffered channel organizing data into blocks.
 */

#include <MDSTk/Module/mdsBlockChannel.h>

#include <MDSTk/Base/mdsMemory.h>
#include <MDSTk/System/mdsSystemTypes.h>
#include <MDSTk/Math/mdsBase.h>


namespace mds
{
namespace mod
{

//==============================================================================
/*
 * Various global definitions and constants.
 */

//! Data entity magic number.
const mds::sys::tUInt32 CH_MAGIC    = 0x5a53;


//==============================================================================
/*
 * Definition of data block header.
 */

//! Data block header.
struct SBlockHeader
{
    //! Magic number.
    mds::sys::tUInt32 m_Magic;

    //! Block size.
    mds::sys::tInt32 m_Size;
};


//==============================================================================
/*
 * Implementation of the class CBlockChannel.
 */
CBlockChannel::CBlockChannel(int iBlockSize, CChannel *pChannel)
    : m_iBlockSize(iBlockSize)
    , m_iNumOfBytes(0)
    , m_bFinished(false)
    , m_spChannel(pChannel)
    , m_Buffer(EMPTY_CONST)
{
    // Check the minimal allowed block size
    if( m_iBlockSize < 64 )
    {
        m_iBlockSize = 64;
    }

    // Allocate the buffer
    m_Buffer.create(m_iBlockSize);

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


int CBlockChannel::read(char *pcData, int iLength)
{
    MDS_CHECK(pcData && iLength > 0, return 0);

    tLock Lock(*this);

    if( (m_Type & CH_IN) == 0 )
    {
        return 0;
    }

    int iLeft = iLength;
    while( iLeft > 0 )
    {
        if( m_iNumOfBytes > 0 )
        {
            int iCount = (iLeft > m_iNumOfBytes) ? m_iNumOfBytes : iLeft;
            mds::base::memCopy(pcData, m_pcData, iCount);
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
            int iSize;
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


bool CBlockChannel::write(const char *pcData, int iLength)
{
    MDS_CHECK(pcData && iLength >= 0, return false);

    tLock Lock(*this);

    if( (m_Type & CH_OUT) == 0 )
    {
        return 0;
    }

    int iLeft = iLength;
    while( iLeft > 0 )
    {
        if( m_iNumOfBytes > 0 )
        {
            int iCount = (iLeft > m_iNumOfBytes) ? m_iNumOfBytes : iLeft;
            mds::base::memCopy(m_pcData, pcData, iCount);
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
    if( m_bFinished )
    {
        return true;
    }

	tLock Lock(*this);

    if( m_Type & CH_IN )
    {
        if( !m_spChannel->isConnected() )
        {
            return false;
        }

        while( !m_bFinished )
        {
            // Read all blocks until an empty one or partially filled one is found
            int iSize;
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

        // Write block
        m_pcData = m_Buffer.getPtr();
        if( !m_spChannel->write(m_pcData, m_iBlockSize - m_iNumOfBytes) )
        {
            return false;
        }
        m_bFinished = true;

        // Flush the output channel.
        return m_spChannel->flush();
    }
    else
    {
        return false;
    }
}


bool CBlockChannel::writeBlockHeader(int iSize)
{
    // Initialize data block header
    SBlockHeader Header;
    Header.m_Magic = CH_MAGIC;
    Header.m_Size = mds::sys::tInt32(iSize);

    // Write the header
    if( !m_spChannel->write((char *)&Header, (int)sizeof(Header)) )
    {
        return false;
    }

    // O.K.
    return true;
}


bool CBlockChannel::readBlockHeader(int& iSize)
{
    // Read the data block header
    SBlockHeader Header;
    int HeaderSize = (int)sizeof(Header);
    if( m_spChannel->read((char *)&Header, HeaderSize) != HeaderSize )
    {
        return false;
    }

    // Check the magic number
    if( Header.m_Magic != CH_MAGIC )
    {
        return false;
    }
    iSize = int(Header.m_Size);

    // O.K.
    return true;
}


} // namespace mod
} // namespace mds

