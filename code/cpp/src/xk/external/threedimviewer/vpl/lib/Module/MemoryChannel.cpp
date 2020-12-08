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
 * Date:    2008/11/18                       
 *
 * Description:
 * - Channel that reads or writes from allocated memory buffer.
 */

#include <VPL/Module/MemoryChannel.h>
#include <VPL/System/Memory.h>
#include <VPL/Math/Base.h>


namespace vpl
{
namespace mod
{

//=============================================================================
/*
 * Implementation of the class CMemoryChannel.
 */
CMemoryChannel::CMemoryChannel(const EChannelType type, const tSize length, char * data)
    : CChannel(CH_MEM, type)
    , m_iNumOfReadBytes(0)
    , m_iNumOfWrittenBytes(0)
    , m_iLength(length)
    , m_pcData(data)
    , m_bBufferOwner(false)
{
    VPL_CHECK(m_iLength > 0, m_iLength = 0; return);

    // Allocate buffer if no data specified.
    if( !m_pcData )
    {
        m_pcData = vpl::sys::memAlloc<char>(m_iLength);
        m_bBufferOwner = true;
    }
}


CMemoryChannel::~CMemoryChannel()
{
    tLock Lock(*this);

    // Free memory buffer if owner.
    if( m_bBufferOwner )
    {
        vpl::sys::memFree<char>(m_pcData);
    }
    m_pcData = NULL;
}


char * CMemoryChannel::getDataPtr()
{
    tLock Lock(*this);

    return m_pcData;
}


tSize CMemoryChannel::getLength()
{
    tLock Lock(*this);

    return m_iLength;
}


tSize CMemoryChannel::getNumOfReadBytes()
{
    tLock Lock(*this);

    return m_iNumOfReadBytes;
}


tSize CMemoryChannel::getNumOfWrittenBytes()
{
    tLock Lock(*this);

    return m_iNumOfWrittenBytes;
}


void CMemoryChannel::setDataPtr(const tSize length, char * data)
{
    VPL_CHECK(length > 0, return);

    tLock Lock(*this);

    // Free current buffer if owner.
    if( m_bBufferOwner && m_pcData )
    {
        vpl::sys::memFree<char>(m_pcData);
    }

    // Allocate buffer if no data specified.
    m_iLength = length;
    if( !data )
    {
        m_pcData = vpl::sys::memAlloc<char>(m_iLength);
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


bool CMemoryChannel::connect(unsigned VPL_UNUSED(timeout))
{
    tLock Lock(*this);

    // No waiting, just check buffer state.
    return (m_pcData && m_iLength > 0);
}

bool CMemoryChannel::listen(unsigned VPL_UNUSED(timeout))
{
    return true;
}

bool CMemoryChannel::wait(unsigned VPL_UNUSED(timeout))
{
    tLock Lock(*this);

    // No waiting, just check buffer state.
    return (m_pcData && m_iLength > 0);
}


tSize CMemoryChannel::read(char * data, tSize length)
{
    VPL_CHECK(data && (length > 0) && (m_Type & CH_IN) && m_pcData, return 0);

    tLock Lock(*this);

    // Read only as far as buffer length permits.
    tSize read_length = vpl::math::getMin(length, m_iLength - m_iNumOfReadBytes);
    vpl::sys::memCopy<char>(data, m_pcData + m_iNumOfReadBytes, read_length);
    m_iNumOfReadBytes += read_length;
    return read_length;
}


bool CMemoryChannel::write(const char * data, tSize length)
{
    VPL_CHECK(data && (length >= 0) && (m_Type & CH_OUT) && m_pcData, return false);

    tLock Lock(*this);

    // Write only what buffer length permits.
    tSize write_length = vpl::math::getMin(length, m_iLength - m_iNumOfWrittenBytes);
    if( write_length != length )
    {
        return false;
    }

    vpl::sys::memCopy<char>(m_pcData + m_iNumOfWrittenBytes, data, write_length);
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


bool CMemoryChannel::skip(tSize length)
{
    // Skip in read index.
    if( m_Type & CH_IN )
    {
        tSize skip_length = vpl::math::getMin(length, m_iNumOfReadBytes);
        if( skip_length != length )
        {
            return false;
        }

        m_iNumOfReadBytes += skip_length;
    }

    // Skip in write index.
    else if( m_Type & CH_OUT )
    {
        tSize skip_length = vpl::math::getMin(length, m_iNumOfWrittenBytes);
        if( skip_length != length )
        {
            return false;
        }

        m_iNumOfWrittenBytes += skip_length;
    }

    return true;
}


} // namespace mod
} // namespace vpl

