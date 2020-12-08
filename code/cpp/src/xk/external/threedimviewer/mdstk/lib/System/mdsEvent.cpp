//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-20010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/26                          \n
 *
 * $Id: mdsEvent.cpp 1707 2010-05-05 11:00:46Z spanel $
 *
 * Description:
 * - Signalling and waiting for events/conditions
 */

#include <MDSTk/System/mdsEvent.h>

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsError.h>
#include <MDSTk/Base/mdsWarning.h>
#include <MDSTk/Base/mdsGlobalLog.h>


namespace mds
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the class mds::sys::CEvent
 * - Windows version
 */

#ifdef _WIN32

CEvent::CEvent(bool bState, bool bManual) : m_bManual(bManual)
{
    m_hEvent = CreateEvent(NULL, m_bManual, bState, NULL);
    if( !m_hEvent )
    {
        MDS_THROW_ERROR("Constructor CEvent::CEvent() failed");
    }
}


CEvent::~CEvent()
{
    if( !CloseHandle(m_hEvent) )
    {
        MDS_LOG_WARNING("Destructor CEvent::~CEvent() failed");
    }
}


bool CEvent::set()
{
    return (SetEvent(m_hEvent) != FALSE);
}


bool CEvent::reset()
{
    return (ResetEvent(m_hEvent) != FALSE);
}


bool CEvent::wait(unsigned uTimeout)
{
    return (WaitForSingleObject(m_hEvent, uTimeout) == WAIT_OBJECT_0);
}


bool CEvent::isSet()
{
    return (WaitForSingleObject(m_hEvent, 0) == WAIT_OBJECT_0);
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class mds::sys::CEvent
 * - Linux version
 */

#ifdef _LINUX

CEvent::CEvent(bool bState, bool bManual)
    : m_bManual(bManual)
    , m_bSignalled(bState)
{
    if( pthread_mutex_init(&m_Mutex, NULL) != 0 )
    {
        MDS_THROW_ERROR("Constructor CEvent::CEvent() failed");
    }

    if( pthread_cond_init(&m_Cond, NULL) != 0 )
    {
        MDS_THROW_ERROR("Constructor CEvent::CEvent() failed");
    }
}


CEvent::~CEvent()
{
    if( pthread_mutex_destroy(&m_Mutex) != 0 )
    {
        MDS_LOG_WARNING("Destructor CEvent::~CEvent() failed");
    }

    if( pthread_cond_destroy(&m_Cond) != 0 )
    {
        MDS_LOG_WARNING("Destructor CEvent::~CEvent() failed");
    }
}


bool CEvent::set()
{
    pthread_mutex_lock(&m_Mutex);
    m_bSignalled = true;
    if( m_bManual )
    {
        pthread_cond_broadcast(&m_Cond);
    }
    else
    {
        pthread_cond_signal(&m_Cond);
    }
    pthread_mutex_unlock(&m_Mutex);

    return true;
}


bool CEvent::reset()
{
    pthread_mutex_lock(&m_Mutex);
    m_bSignalled = false;
    pthread_mutex_unlock(&m_Mutex);

    return true;
}


void CEvent::cleanupHandler(void *arg)
{
    pthread_mutex_t *Mutex = static_cast<pthread_mutex_t *>(arg);
    if( !Mutex )
    {
        return;
    }

    pthread_mutex_unlock(Mutex);
}


bool CEvent::wait(unsigned uTimeout)
{
    int iResult = 0;

    pthread_cleanup_push(CEvent::cleanupHandler, &m_Mutex);

    // Infinite waiting for the condition
    if( uTimeout == MDS_WAIT_INFINITE )
    {
        pthread_mutex_lock(&m_Mutex);
        while( !m_bSignalled )
        {
            pthread_cond_wait(&m_Cond, &m_Mutex);
        }
    }

    // Timed waiting for the condition
    else
    {
        // Get the current time
        timeval Now;
        gettimeofday(&Now, NULL);
        Now.tv_sec += uTimeout / 1000;
        Now.tv_usec += (uTimeout % 1000) * 1000;

        // Specify the time to wait
        timespec TimeToWait;
        TimeToWait.tv_sec = Now.tv_sec + (Now.tv_usec / 1000000);
        TimeToWait.tv_nsec = (Now.tv_usec % 1000000) * 1000;

        iResult = EINTR;
        pthread_mutex_lock(&m_Mutex);
        while( !m_bSignalled && iResult == EINTR )
        {
            iResult = pthread_cond_timedwait(&m_Cond, &m_Mutex, &TimeToWait);
        }
    }

    pthread_cleanup_pop(0);

    if( iResult == ETIMEDOUT )
    {
        pthread_mutex_unlock(&m_Mutex);
        return false;
    }

    m_bSignalled = (m_bSignalled && m_bManual);
    pthread_mutex_unlock(&m_Mutex);
    return true;
}


bool CEvent::isSet()
{
    pthread_mutex_lock(&m_Mutex);
    bool bState = m_bSignalled;
    pthread_mutex_unlock(&m_Mutex);

    return bState;
}

#endif // _LINUX


} // namespace sys
} // namespace mds

