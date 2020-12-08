//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2008 by PGMed@FIT              \n
 *
 * Author:  Radek Barton, ibarton@fit.vutbr.cz  \n
 * Date:    2008/11/18                          \n
 *
 * $Id: mdsMemoryChannel.cpp 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - Channel that reads or writes from allocated memory buffer.
 */

#include <MDSTk/Module/mdsMemoryChannel.h>
#include <MDSTk/Base/mdsMemory.h>
#include <MDSTk/Math/mdsBase.h>


namespace mds
{
namespace mod
{

//=============================================================================
/*
 * Implementation of the class CMemoryChannel.
 */
CMemoryChannel::CMemoryChannel(const EChannelType type, const int length, char * data)
    : CChannel(CH_MEM, type)
    , m_iNumOfReadBytes(0)
    , m_iNumOfWrittenBytes(0)
    , m_iLength(length)
    , m_pcData(data)
    , m_bBufferOwner(false)
{
    MDS_CHECK(m_iLength > 0, m_iLength = 0; return);

    // Allocate buffer if no data specified.
    if( !m_pcData )
    {
        m_pcData = mds::base::memAlloc<char>(m_iLength);
        m_bBufferOwner = true;
    }
}


CMemoryChannel::~CMemoryChannel()
{
    tLock Lock(*this);

    // Free memory buffer if owner.
    if( m_bBufferOwner )
    {
        mds::base::memFree<char>(m_pcData);
    }
    m_pcData = NULL;
}


char * CMemoryChannel::getDataPtr()
{
    tLock Lock(*this);

    return m_pcData;
}


int CMemoryChannel::getLength()
{
    tLock Lock(*this);

    return m_iLength;
}


int CMemoryChannel::getNumOfReadBytes()
{
    tLock Lock(*this);

    return m_iNumOfReadBytes;
}


int CMemoryChannel::getNumOfWrittenBytes()
{
    tLock Lock(*this);

    return m_iNumOfWrittenBytes;
}


void CMemoryChannel::setDataPtr(const int length, char * data)
{
    MDS_CHECK(length > 0, return);

    tLock Lock(*this);

    // Free current buffer if owner.
    if( m_bBufferOwner && m_pcData )
    {
        mds::base::memFree<char>(m_pcData);
    }

    // Allocate buffer if no data specified.
    m_iLength = length;
    if( !data )
    {
        m_pcData = mds::base::memAlloc<char>(m_iLength);
        m_bBufferOwner = true;
    }
    else
    {
        m_pcData = data;
        m_bBufferOwner = false;
    }

    // Clear buffer indices.
    m_iNumOfReadBytes = 0;
    m_iNumOfWrittenBytes = 0;
}


void CMemoryChannel::disconnect()
{
    // Nothing.
}


bool CMemoryChannel::connect(unsigned MDS_UNUSED(timeout))
{
    tLock Lock(*this);

    // No waiting, just check buffer state.
    return (m_pcData && m_iLength > 0);
}

bool CMemoryChannel::listen(unsigned MDS_UNUSED(timeout))
{
    return true;
}

bool CMemoryChannel::wait(unsigned MDS_UNUSED(timeout))
{
    tLock Lock(*this);

    // No waiting, just check buffer state.
    return (m_pcData && m_iLength > 0);
}


int CMemoryChannel::read(char * data, int length)
{
    MDS_CHECK(data && (length > 0) && (m_Type & CH_IN) && m_pcData, return 0);

    tLock Lock(*this);

    // Read only as far as buffer length permits.
    int read_length = mds::math::getMin(length, m_iLength - m_iNumOfReadBytes);
    mds::base::memCopy<char>(data, m_pcData + m_iNumOfReadBytes, read_length);
    m_iNumOfReadBytes += read_length;
    return read_length;
}


bool CMemoryChannel::write(const char * data, int length)
{
    MDS_CHECK(data && (length >= 0) && (m_Type & CH_OUT) && m_pcData, return false);

    tLock Lock(*this);

    // Write only what buffer length permits.
    int write_length = mds::math::getMin(length, m_iLength - m_iNumOfWrittenBytes);
    if( write_length != length )
    {
        return false;
    }

    mds::base::memCopy<char>(m_pcData + m_iNumOfWrittenBytes, data, write_length);
    m_iNumOfWrittenBytes += write_length;
    return true;
}


bool CMemoryChannel::isConnected()
{
    return (m_pcData && m_iLength > 0);
}


bool CMemoryChannel::flush()
{
    return true;
}


bool CMemoryChannel::skip(int length)
{
    // Skip in read index.
    if( m_Type & CH_IN )
    {
        int skip_length = mds::math::getMin(length, m_iNumOfReadBytes);
        if( skip_length != length )
        {
            return false;
        }

        m_iNumOfReadBytes += skip_length;
    }

    // Skip in write index.
    else if( m_Type & CH_OUT )
    {
        int skip_length = mds::math::getMin(length, m_iNumOfWrittenBytes);
        if( skip_length != length )
        {
            return false;
        }

        m_iNumOfWrittenBytes += skip_length;
    }

    return true;
}


} // namespace mod
} // namespace mds

