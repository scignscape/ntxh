//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/27                          \n
 *
 * $Id: mdsTimer.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Class encapsulating timer functions.
 */

#include <MDSTk/System/mdsTimer.h>
#include <MDSTk/System/mdsThread.h>
#include <MDSTk/System/mdsSleep.h>

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
 * Implementation of the class mds::sys::CTimer.
 * - Windows version.
 */

#ifdef _WIN32

CTimer::CTimer(unsigned uDelay, bool bRun)
    : m_hTimer(0)
    , m_Event(false, false)
    , m_uDelay(uDelay)
{
    if( timeBeginPeriod(TIMER_RESOLUTION) != TIMERR_NOERROR )
    {
        MDS_THROW_ERROR("Constructor CTimer::CTimer() failed");
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
}


void CTimer::start()
{
    if( m_hTimer != 0 )
    {
        stop();
    }

    if( m_uDelay == 0 )
    {
        m_Event.set();
    }
    else
    {
        m_Event.reset();
        m_hTimer = timeSetEvent(m_uDelay,
                                TIMER_RESOLUTION,
                                (LPTIMECALLBACK)m_Event.m_hEvent,
                                0,
                                TIME_PERIODIC | TIME_CALLBACK_EVENT_SET
                                );
        if( m_hTimer == 0 )
        {
            MDS_THROW_ERROR("Method CTimer::start() failed");
        }
    }
}


void CTimer::stop()
{
    if( m_hTimer != 0 )
    {
        if( timeKillEvent(m_hTimer) != TIMERR_NOERROR )
        {
            MDS_LOG_WARNING("Method CTimer::stop() failed");
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
//        stop();
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
 * Implementation of the class mds::sys::CTimer.
 * - Linux version.
 */

#ifdef _LINUX

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
        MDS_ASSERT(m_pTimer);
    }
};


//==============================================================================
/*!
 * Timer scheduler.
 */
class CTimerScheduler
{
public:
    //! Default constructor.
    CTimerScheduler();

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

    //! Critical section providing mutual access to scheduler.
    CCriticalSection m_CritSec;

    //! Pointer to a list of scheduled timer events.
    CTimerDesc *m_pTimers;

private:
    //! Thread routine.
    static int threadRoutine(CThread *pThread);

    //! Returns current system time in milliseconds.
    unsigned long getTime();
};


//! Global timer events scheduler.
CTimerScheduler TimerScheduler;


//==============================================================================
/*
 * Implementation of the class mds::sys::CTimerScheduler.
 */
MDS_THREAD_ROUTINE(CTimerScheduler::threadRoutine)
{
    // Get the shcheduler
    CTimerScheduler *pScheduler = (CTimerScheduler *)pThread->getData();

    // Main thread loop
    MDS_THREAD_MAIN_LOOP
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
    m_CritSec.enter();

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

    m_CritSec.leave();
}


void CTimerScheduler::removeTimer(CTimerDesc *pDesc)
{
    m_CritSec.enter();

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

    m_CritSec.leave();
}


void CTimerScheduler::sendEvents()
{
    m_CritSec.enter();

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

    m_CritSec.leave();
}


unsigned long CTimerScheduler::getTime()
{
    struct timespec Time;
    if( clock_gettime(CLOCK_REALTIME, &Time) != 0 )
    {
        MDS_LOG_WARNING("Method CTimerScheduler::getTime() failed");
    }

    return (unsigned long)((Time.tv_sec * 1000) + (Time.tv_nsec / 1000000));
}


//==============================================================================
/*
 * Implementation of the class mds::sys::CTimer.
 * - Linux version.
 */
CTimer::CTimer(unsigned uDelay, bool bRun)
    : m_pDesc(new CTimerDesc(this))
    , m_Event(false, false)
    , m_uDelay(uDelay)
{
    MDS_ASSERT(m_pDesc);

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


void CTimer::start()
{
    if( m_pDesc->m_bRunning )
    {
        stop();
    }

    if( m_uDelay == 0 )
    {
        m_Event.set();
    }
    else
    {
        TimerScheduler.queueTimer(m_pDesc);
    }
}


void CTimer::stop()
{
    if( m_pDesc->m_bRunning )
    {
        TimerScheduler.removeTimer(m_pDesc);
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


#endif // _LINUX


} // namespace sys
} // namespace mds

