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
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.c
 * Date:    2003/10/27                          \n
 *
 * Description:
 * - Class encapsulating timer functions.
 */

#include <VPL/System/Timer.h>
#include <VPL/System/Thread.h>
#include <VPL/System/Sleep.h>
#include <VPL/System/ScopedLock.h>

#include <VPL/Base/Assert.h>
#include <VPL/Base/Error.h>
#include <VPL/Base/Warning.h>
#include <VPL/Base/Logging.h>
#include <VPL/Base/Singleton.h>


namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the class vpl::sys::CTimer.
 * - Windows version.
 */

#ifdef _WIN32

CTimer::CTimer(unsigned uDelay, bool bRun)
    : m_hTimer(0)
    , m_uDelay(uDelay)
{
    m_hEvent = CreateEvent(NULL, false, false, NULL);
    if( !m_hEvent )
    {
        VPL_THROW_ERROR("Constructor CTimer::CTimer() failed");
    }

    if( timeBeginPeriod(TIMER_RESOLUTION) != TIMERR_NOERROR )
    {
        VPL_THROW_ERROR("Constructor CTimer::CTimer() failed");
    }

    if( bRun )
    {
        start();
    }
}


CTimer::~CTimer()
{
    if( m_hTimer != 0 )
    {
        stop();
    }

    timeEndPeriod(TIMER_RESOLUTION);

    if( !CloseHandle(m_hEvent) )
    {
        VPL_LOG_WARN("Destructor CTimer::~CTimer() failed");
    }
}


bool CTimer::wait(unsigned uTimeout)
{
    return (WaitForSingleObject(m_hEvent, uTimeout) == WAIT_OBJECT_0);
}


void CTimer::signal()
{
    SetEvent(m_hEvent);
}


void CTimer::start()
{
    if( m_hTimer != 0 )
    {
        stop();
    }

    if( m_uDelay == 0 )
    {
        SetEvent(m_hEvent);
    }
    else
    {
        ResetEvent(m_hEvent);

        // "Although the timeSetEvent() API call has been officially deprecated
        // for some time, it still seems to be the only reliable, high-resolution timer
        // available in Windows..."
        m_hTimer = timeSetEvent(m_uDelay,
                                TIMER_RESOLUTION,
                                (LPTIMECALLBACK)m_hEvent,
                                0,
                                TIME_PERIODIC | TIME_CALLBACK_EVENT_SET
                                );
        if( m_hTimer == 0 )
        {
            VPL_THROW_ERROR("Method CTimer::start() failed");
        }
    }
}


void CTimer::stop()
{
    if( m_hTimer != 0 )
    {
        if( timeKillEvent(m_hTimer) != TIMERR_NOERROR )
        {
            VPL_LOG_WARN("Method CTimer::stop() failed");
        }
        m_hTimer = 0;
    }
}


void CTimer::setDelay(unsigned uDelay)
{
    // Sets the new timer delay value
    m_uDelay = uDelay;

    if( m_hTimer != 0 )
    {
        start();
    }
}


bool CTimer::isRunning()
{
    return (m_hTimer != 0);
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class vpl::sys::CTimer.
 * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

//==============================================================================
/*!
 * Scheduled timer event description.
 */
class CTimerDesc
{
public:
    //! Pointer to a scheduled timer.
    CTimer *m_pTimer;

    //! Flag set to true if the timer is running.
    bool m_bRunning;

    //! Pointer to the next and previous scheduled timer.
    CTimerDesc *m_pNext, *m_pPrev;

    //! Planed time when the timer have to be signalled.
    unsigned long m_ulShotTime;

public:
    //! Constructor.
    CTimerDesc(CTimer *pTimer)
        : m_pTimer(pTimer)
        , m_bRunning(false)
        , m_pNext(NULL)
        , m_pPrev(NULL)
        , m_ulShotTime(0)
    {
        VPL_ASSERT(m_pTimer);
    }
};


//==============================================================================
/*!
 * Timer scheduler.
 */
class CTimerScheduler : public vpl::base::CLibrarySingleton
{
public:
    //! Destructor.
    ~CTimerScheduler();

    //! Insert a given timer event to the list.
    void queueTimer(CTimerDesc *pDesc, unsigned long ulWhen = 0);

    //! Removes a given timer event from the list.
    void removeTimer(CTimerDesc *pDesc);

    //! Signals all relevant timer events.
    void sendEvents();

private:
    //! Thread used to send timer events.
    CThread m_Thread;

    //! Mutex providing mutual access to scheduler.
    CMutex m_Mutex;

    //! Pointer to a list of scheduled timer events.
    CTimerDesc *m_pTimers;

private:
    //! Thread routine.
    static int threadRoutine(CThread *pThread);

    //! Returns current system time in milliseconds.
    unsigned long getTime();

private:
    //! Private default constructor.
    CTimerScheduler();

    //! Allow main log instantiation using the singleton holder.
    VPL_PRIVATE_SINGLETON(CTimerScheduler);
};


//==============================================================================
/*
 * Implementation of the class vpl::sys::CTimerScheduler.
 */
VPL_THREAD_ROUTINE(CTimerScheduler::threadRoutine)
{
    // Get the shcheduler
    CTimerScheduler *pScheduler = (CTimerScheduler *)pThread->getData();

    // Main thread loop
    VPL_THREAD_MAIN_LOOP
    {
        // Send the timer events
        pScheduler->sendEvents();

        // Sleep (minimal timer resolution)
        sleep(TIMER_RESOLUTION);
    }

    return 0;
}


CTimerScheduler::CTimerScheduler()
    : m_Thread(CTimerScheduler::threadRoutine, (void *)this, false)
    , m_pTimers(NULL)
{
    m_Thread.setPriority(TP_HIGH);
}


CTimerScheduler::~CTimerScheduler()
{
    m_Thread.terminate();
}


void CTimerScheduler::queueTimer(CTimerDesc *pDesc, unsigned long ulWhen)
{
    vpl::sys::tScopedLock Guard(m_Mutex);

    if( pDesc->m_bRunning )
    {
        return;
    }

    if( ulWhen == 0 )
    {
        ulWhen = getTime() + pDesc->m_pTimer->getDelay();
    }

    pDesc->m_ulShotTime = ulWhen;
    pDesc->m_bRunning = true;

    if( m_pTimers )
    {
        pDesc->m_pNext = m_pTimers;
        m_pTimers->m_pPrev = pDesc;
        pDesc->m_pPrev = NULL;
        m_pTimers = pDesc;
    }
    else
    {
        pDesc->m_pPrev = pDesc->m_pNext = NULL;
        m_pTimers = pDesc;

        m_Thread.resume();
    }
}


void CTimerScheduler::removeTimer(CTimerDesc *pDesc)
{
    vpl::sys::tScopedLock Guard(m_Mutex);

    pDesc->m_bRunning = false;

    if( pDesc == m_pTimers )
    {
        m_pTimers = pDesc->m_pNext;
    }
    if( pDesc->m_pPrev )
    {
        pDesc->m_pPrev->m_pNext = pDesc->m_pNext;
    }
    if( pDesc->m_pNext )
    {
        pDesc->m_pNext->m_pPrev = pDesc->m_pPrev;
    }

    pDesc->m_pNext = pDesc->m_pPrev = NULL;

    if( m_pTimers == NULL )
    {
        m_Thread.suspend();
    }
}


void CTimerScheduler::sendEvents()
{
    vpl::sys::tScopedLock Guard(m_Mutex);

    if( m_pTimers )
    {
        unsigned long ulNow = getTime();

        CTimerDesc *pTemp, *pDesc = m_pTimers;
        while( pDesc )
        {
            if( pDesc->m_ulShotTime <= ulNow )
            {
                pTemp = pDesc;
                pDesc = pDesc->m_pNext;

                pTemp->m_pTimer->signal();
                pTemp->m_ulShotTime += pTemp->m_pTimer->getDelay();
            }
            else
            {
                pDesc = pDesc->m_pNext;
            }
        }
    }
}


unsigned long CTimerScheduler::getTime()
{
#ifdef _LINUX
    struct timespec Time;
    if( clock_gettime(CLOCK_REALTIME, &Time) != 0 )
    {
        VPL_LOG_WARN("Method CTimerScheduler::getTime() failed");
    }

    return (unsigned long)((Time.tv_sec * 1000) + (Time.tv_nsec / 1000000));
#endif // _LINUX

#ifdef _MACOSX
    struct timeval Time;
    if( gettimeofday(&Time, NULL) != 0 )
    {
        VPL_LOG_WARN("Method CTimerScheduler::getTime() failed");
    }

    return (unsigned long)((Time.tv_sec * 1000) + (Time.tv_usec / 1000));
#endif // _MACOSX
}


//==============================================================================
/*
 * Implementation of the class vpl::sys::CTimer.
 * - Linux and Mac version.
 */
CTimer::CTimer(unsigned uDelay, bool bRun)
    : m_pDesc(new CTimerDesc(this))
    , m_uDelay(uDelay)
{
    VPL_ASSERT(m_pDesc);

    if( bRun )
    {
        start();
    }
}


CTimer::~CTimer()
{
    if( m_pDesc->m_bRunning )
    {
        stop();
    }

    delete m_pDesc;
}


bool CTimer::wait(unsigned uTimeout)
{
    vpl::sys::tScopedLock Guard(m_Mutex);
    return m_Cond.wait(m_Mutex, uTimeout);
}


void CTimer::signal()
{
    vpl::sys::tScopedLock Guard(m_Mutex);
    m_Cond.notifyAll();
}


void CTimer::start()
{
    if( m_pDesc->m_bRunning )
    {
        stop();
    }

    if( m_uDelay == 0 )
    {
        signal();
    }
    else
    {
        VPL_SINGLETON(CTimerScheduler).queueTimer(m_pDesc);
    }
}


void CTimer::stop()
{
    if( m_pDesc->m_bRunning )
    {
        VPL_SINGLETON(CTimerScheduler).removeTimer(m_pDesc);
    }
}


bool CTimer::isRunning()
{
    return m_pDesc->m_bRunning;
}


void CTimer::setDelay(unsigned uDelay)
{
    m_uDelay = uDelay;

    if( m_pDesc->m_bRunning )
    {
        stop();
        start();
    }
}


#endif // _LINUX || _MACOSX


} // namespace sys
} // namespace vpl

