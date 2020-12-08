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
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.c
 * Date:    2009/04/02                          \n
 */

#include <VPL/System/Condition.h>

#include <VPL/Base/Error.h>
#include <VPL/Base/Warning.h>
#include <VPL/Base/Logging.h>

#if defined(_LINUX) || defined(_MACOSX)
#   include <sys/time.h>
#endif

namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the class vpl::sys::CCondition.
 * - Windows version.
 */

#ifdef _WIN32

CCondition::CCondition() : m_Threads(0), m_Wakeup(0)
{
    InitializeCriticalSection(&m_CritSec);

    m_hEvent = CreateEvent(NULL, false, false, NULL);
    if( !m_hEvent )
    {
        VPL_THROW_ERROR("Constructor CCondition::CCondition() failed");
    }
}


CCondition::~CCondition()
{
    if( !CloseHandle(m_hEvent) )
    {
        VPL_LOG_WARN("Destructor CCondition::~CCondition() failed");
    }

    DeleteCriticalSection(&m_CritSec);
}


bool CCondition::wait(CMutex& Mutex, unsigned uTimeout)
{
    EnterCriticalSection(&m_CritSec);
    ++m_Threads;
    LeaveCriticalSection(&m_CritSec);

    Mutex.unlock();

    DWORD dwResult = WaitForSingleObject(m_hEvent, uTimeout);

    EnterCriticalSection(&m_CritSec);
    --m_Threads;

    if( dwResult != WAIT_OBJECT_0 )
    {
        LeaveCriticalSection(&m_CritSec);
        Mutex.lock();
        return false;
    }

    --m_Wakeup;
    bool bBroadcast = (m_Wakeup > 0);
    LeaveCriticalSection(&m_CritSec);

    if( bBroadcast )
    {
        SetEvent(m_hEvent);
    }

    Mutex.lock();

    return true;
}


void CCondition::notifyOne()
{
    EnterCriticalSection(&m_CritSec);
    m_Wakeup = 1;
    bool bWaiter = (m_Threads > 0);
    LeaveCriticalSection(&m_CritSec);

    if( bWaiter )
    {
        // Wake up all the waiters.
        SetEvent(m_hEvent);
    }
}


void CCondition::notifyAll()
{
    EnterCriticalSection(&m_CritSec);
    m_Wakeup = m_Threads;
    bool bWaiter = (m_Threads > 0);
    LeaveCriticalSection(&m_CritSec);

    if( bWaiter )
    {
        // Wake up all the waiters.
        SetEvent(m_hEvent);
    }
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class vpl::sys::CCondition.
 * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

CCondition::CCondition()
{
    if( pthread_cond_init(&m_Cond, NULL) != 0 )
    {
        VPL_THROW_ERROR("Constructor CCondition::CCondition() failed");
    }
}


CCondition::~CCondition()
{
    if( pthread_cond_destroy(&m_Cond) != 0 )
    {
        VPL_LOG_WARN("Destructor CCondition::~CCondition() failed");
    }
}


void CCondition::cleanupHandler(void *arg)
{
    pthread_mutex_t *Mutex = static_cast<pthread_mutex_t *>(arg);
    if( !Mutex )
    {
        return;
    }

    pthread_mutex_unlock(Mutex);
}


bool CCondition::wait(CMutex& Mutex, unsigned uTimeout)
{
    int iResult = 0;

    pthread_cleanup_push(CCondition::cleanupHandler, &Mutex.m_Mutex);

    if( uTimeout == VPL_WAIT_INFINITE )
    {
        // Infinite waiting for the condition
        iResult = pthread_cond_wait(&m_Cond, &Mutex.m_Mutex);
    }
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

        // Wait for the condition
        iResult = pthread_cond_timedwait(&m_Cond, &Mutex.m_Mutex, &TimeToWait);
    }

    pthread_cleanup_pop(0);

    return (iResult == 0);
}


void CCondition::notifyOne()
{
    if( pthread_cond_signal(&m_Cond) != 0 )
    {
        VPL_LOG_WARN("Method CCondition::signal() failed");
    }
}


void CCondition::notifyAll()
{
    if( pthread_cond_broadcast(&m_Cond) != 0 )
    {
        VPL_LOG_WARN("Method CCondition::broadcast() failed");
    }
}

#endif // _LINUX || _MACOSX


} // namespace sys
} // namespace vpl

