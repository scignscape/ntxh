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
 * Copyright (c) 2003-2008 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/09/28                       
 *
 * Description:
 * - Buffered channel providing STL-like stream functionality.
 */

#include <VPL/Module/StreamChannel.h>

#include <VPL/System/Memory.h>
#include <VPL/System/SystemTypes.h>
#include <VPL/Math/Base.h>

// STL
#include <istream>
#include <ostream>
#include <iostream>


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Implementation of the class COStreamChannel.
 */
COStreamChannel::COStreamChannel(CChannel *pChannel)
    : m_spChannel(pChannel)
{
    VPL_ASSERT(pChannel);
    
    // Create the output stream
    m_pStream = new std::ostream(this);

    // Buffer initialization
    m_pcBufferEnd = m_pcBuffer + SIZE;

    // Sets the put area
    setp(m_pcBuffer, m_pcBufferEnd);
}


COStreamChannel::~COStreamChannel()
{
    // Flush the buffer
    overflow();

    // Flush the channel
    m_spChannel->flush();
}


int COStreamChannel::overflow(int c)
{
    // Get the data size
    int iSize = int(pptr() - pbase());

    // Write it to the output channels
    if( !m_spChannel->write(pbase(), iSize) )
    {
        m_pStream->setstate(std::ios_base::badbit);
    }

    // Reinitiate the internal buffer
    setp(m_pcBuffer, m_pcBufferEnd);
    if( c != EOF )
    {
        sputc(char(c));
    }

    return 0;
}


int COStreamChannel::underflow()
{
    return 0;
}


int COStreamChannel::sync()
{
    overflow();

    return 0;
}


//==============================================================================
/*
 * Implementation of the class CIStreamChannel.
 */
CIStreamChannel::CIStreamChannel(CChannel *pChannel)
    : m_spChannel(pChannel)
    , m_numberOfBlocks(0)
{
    VPL_ASSERT(pChannel);

    // Create the input stream
    m_pStream = new std::istream(this);

    // Buffer initialization
    m_pcBufferEnd = m_pcBuffer + SIZE;
    
    // Sets the put area
    setg(m_pcBuffer, m_pcBufferEnd , m_pcBufferEnd);

    // Initialize the internal buffer
    //underflow();
}


CIStreamChannel::~CIStreamChannel()
{
    // Flush the buffer
    underflow();

    // Flush the channel
    m_spChannel->flush();
}


int CIStreamChannel::overflow(int VPL_UNUSED(c))
{
    return 0;
}


int CIStreamChannel::underflow()
{
    // Get the data size
    int iSize = int(egptr() - gptr());
    if( iSize > 0 )
    {
        return 0;
    }
    int bytesLoaded = m_spChannel->read(m_pcBuffer, SIZE);
    // Read data from the intput channels
    if (bytesLoaded == 0)
    {
        //it's neccessary to distinguish why no bytes were loaded
        if (feof(stdin))
            m_pStream->setstate(std::ios_base::eofbit);
        else if (ferror(stdin))
            m_pStream->setstate(std::ios_base::badbit);
        else
            m_pStream->setstate(std::ios_base::badbit);        
    }

    // Reinitiate the internal buffer
    setg(m_pcBuffer, m_pcBuffer, m_pcBufferEnd);

    ++m_numberOfBlocks;

    return 0;
}


int CIStreamChannel::sync()
{
    underflow();

    return 0;
}

std::streampos CIStreamChannel::seekoff(std::streamoff off, std::ios_base::seekdir way, std::ios_base::openmode which)
{
   
    if (way == std::ios_base::cur)
    {
        int currentPos = gptr() - eback();
        if ( (currentPos + off) > SIZE || (currentPos + off) < 0)
        {
            throw CSeekBeyond();
        }
        gbump(off);

    }
    if (way == std::ios_base::beg)
    {
        if (m_numberOfBlocks > 1)
        {
            throw CSeekBeyond();
        }
        setg(m_pcBuffer, m_pcBuffer + off, m_pcBufferEnd);
    }
        
    if (way == std::ios_base::end)
    {
        throw CSeekBeginning();
    }
        
    return gptr() - eback();
}

std::streampos CIStreamChannel::seekpos(std::streampos sp, std::ios_base::openmode which)
{
    if (sp > SIZE)
    {
        throw CSeekEnd();
        return std::streampos(EOF);
    }
   
    if (which == std::ios_base::in)
    {
        setg(m_pcBuffer, m_pcBuffer+sp, m_pcBufferEnd);;
        int val = gptr() - eback();
        return gptr() - eback();
    }
    return std::streampos(EOF);
}

} // namespace mod
} // namespace vpl

