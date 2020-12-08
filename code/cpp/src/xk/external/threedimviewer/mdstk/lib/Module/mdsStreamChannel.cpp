//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/09/28                          \n
 *
 * $Id: mdsStreamChannel.cpp 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - Buffered channel providing STL-like stream functionality.
 */

#include <MDSTk/Module/mdsStreamChannel.h>

#include <MDSTk/Base/mdsMemory.h>
#include <MDSTk/System/mdsSystemTypes.h>
#include <MDSTk/Math/mdsBase.h>

// STL
#include <istream>
#include <ostream>


namespace mds
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
    MDS_ASSERT(pChannel);
    
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
{
    MDS_ASSERT(pChannel);

    // Create the input stream
    m_pStream = new std::istream(this);

    // Buffer initialization
    m_pcBufferEnd = m_pcBuffer + SIZE;

    // Sets the put area
    setg(m_pcBuffer, m_pcBufferEnd, m_pcBufferEnd);
}


CIStreamChannel::~CIStreamChannel()
{
    // Flush the buffer
    underflow();

    // Flush the channel
    m_spChannel->flush();
}


int CIStreamChannel::overflow(int MDS_UNUSED(c))
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

    // Read data from the intput channels
    if( m_spChannel->read(m_pcBuffer, SIZE) <= 0 )
    {
        m_pStream->setstate(std::ios_base::badbit);
    }

    // Reinitiate the internal buffer
    setg(m_pcBuffer, m_pcBuffer, m_pcBufferEnd);

    return 0;
}


int CIStreamChannel::sync()
{
    underflow();

    return 0;
}


} // namespace mod
} // namespace mds

