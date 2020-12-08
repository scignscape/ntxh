//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/11/14                          \n
 *
 * $Id: mdsLog.cpp 2049 2012-01-09 13:04:08Z spanel $
 * 
 * Description:
 * - Logging functions.
 */

#include <MDSTk/Base/mdsLog.h>


namespace mds
{
namespace base
{

//==============================================================================
/*
 * Implementation of the class mds::base::CLog.
 */
CLog::CLog(bool bEnable) : m_bEnabled(bEnable)
{
    // Create the output stream
    m_pStream = new std::ostream(this);

    // Buffer initialization
    m_pcBufferEnd = m_pcBuffer + SIZE - 1;

    // Sets the put area
    setp(m_pcBuffer, m_pcBufferEnd);
}


CLog::~CLog()
{
    // Flush the buffer
    overflow();

    // Remove all channels
    removeAllChannels();
}


void CLog::registerChannel(CLogChannel *pLogChannel)
{
    if( !pLogChannel )
    {
        return;
    }

    tLock Lock(*this);

    m_Channels.insert(pLogChannel);
}


void CLog::unregisterChannel(CLogChannel *pLogChannel)
{
    if( !pLogChannel )
    {
        return;
    }

    tLock Lock(*this);

    m_Channels.erase(pLogChannel);
}


void CLog::removeAllChannels()
{
    tLock Lock(*this);

    m_Channels.clear();
}


void CLog::enable(bool bEnable)
{
    tLock Lock(*this);

    m_bEnabled = bEnable;
}


void CLog::disable()
{
    tLock Lock(*this);

    m_bEnabled = false;
}


int CLog::overflow(int c)
{
    static char pcTemp[SIZE + 1];

    tLock Lock(*this);

    if( !m_bEnabled )
    {
        return 0;
    }

    // Get the data from buffer
    int iSize = int(pptr() - pbase());
    memcpy(pcTemp, pbase(), iSize);

    // Termination
    pcTemp[iSize] = '\0';

    // Write it to all output channels
    tChannels::iterator it = m_Channels.begin();
    tChannels::iterator itEnd = m_Channels.end();
    while( it != itEnd )
    {
        (*it)->entry(pcTemp);
        ++it;
    }

    // Reinitiate the internal buffer
    setp(m_pcBuffer, m_pcBufferEnd);
    if( c != EOF )
    {
        sputc((char)c);
    }

    return 0;
}


int CLog::underflow()
{
    return 0;
}


int CLog::sync()
{
    overflow();

    return 0;
}


} // namespace base
} // namespace mds

