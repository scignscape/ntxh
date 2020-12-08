//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/24                          \n
 *
 * $Id: mdsThread.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Thread control.
 */

#include <MDSTk/System/mdsThread.h>

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
 * Implementation of the class mds::sys::CThread.
 * - Platform independent.
 */
void CThread::resume()
{
    m_CritSec.enter();

    m_NotSuspendedEvent.set();
    m_bSuspended = false;

    m_CritSec.leave();
}


void CThread::suspend()
{
    m_CritSec.enter();

    if( !m_bSuspended )
    {
        m_NotSuspendedEvent.reset();
        m_bSuspended = true;
    }

    m_CritSec.leave();
}


bool CThread::isExitSignalled()
{
    // Wait while the thread is suspended
    m_NotSuspendedEvent.wait(MDS_WAIT_INFINITE);

    // Check whether the exit event is signalled
    return m_ExitEvent.isSet();
}


int CThread::getExitCode()
{
    m_CritSec.enter();
    int iResult = m_iExitCode;
    m_CritSec.leave();

    return iResult;
}


//==============================================================================
/*
 * Implementation of the class mds::sys::CThread.
 * - Windows version.
 */

#ifdef _WIN32

DWORD WINAPI CThread::threadRoutine(LPVOID pData)
{
    // Pointer to the thread class instance
    CThread *pThread = (CThread *)pData;
    MDS_ASSERT(pThread);

    pThread->m_NotSuspendedEvent.wait(MDS_WAIT_INFINITE);

    // Call the user thread routine
    int iResult = pThread->m_pRoutine(pThread);

    // Set the exit code
    pThread->m_iExitCode = iResult;

    pThread->m_TerminatedEvent.set();

    ExitThread(0);

    return 0;
}


CThread::CThread(CThread::tRoutinePtr pRoutine, void *pData, bool bRun)
    : m_hThread(0)
    , m_dwThreadId(0)
    , m_pRoutine(pRoutine)
    , m_pData(pData)
    , m_bSuspended(!bRun)
    , m_ExitEvent(false, true)
    , m_TerminatedEvent(false, true)
    , m_NotSuspendedEvent(bRun, true)
    , m_iExitCode(-1)
{
    MDS_ASSERT(m_pRoutine);

    // Creation of a new thread
    m_hThread = CreateThread(0, 0, threadRoutine, (void *)this, 0, &m_dwThreadId);
    if( !m_hThread )
    {
        MDS_THROW_ERROR("Constructor CThread::CThread() failed");
    }

    // Let's start the thread
    if( bRun )
    {
        resume();
    }
}


CThread::~CThread()
{
    // Terminates the thread
    terminate();

    m_CritSec.enter();

    if( m_hThread )
    {
        CloseHandle(m_hThread);
    }

    m_CritSec.leave();
}


void CThread::terminate(bool bWait, unsigned uTimeout)
{
    m_CritSec.enter();

    if( m_dwThreadId != 0 )
    {
        m_ExitEvent.set();
        m_NotSuspendedEvent.set();

        if( bWait )
        {
            if( !m_TerminatedEvent.wait(uTimeout) )
            {
                if( TerminateThread(m_hThread, 0) == 0 )
                {
                    MDS_LOG_WARNING("Method CThread::terminate() failed");
                }
            }
        }
    }

    m_dwThreadId = 0;

    m_CritSec.leave();
}


void CThread::setPriority(EThreadPriority ePriority)
{
    if( SetThreadPriority(m_hThread, ePriority) == 0 )
    {
        MDS_LOG_WARNING("Method CThread::setPriority() failed");
    }
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class mds::sys::CThread.
 * - Linux version.
 */

#ifdef _LINUX

void *CThread::threadRoutine(void *pData)
{
    // Pointer to the thread class instance
    CThread *pThread = (CThread *)pData;
    MDS_ASSERT(pThread);

    // Enable POSIX thread cancelation
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, 0);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, 0);

    pThread->m_NotSuspendedEvent.wait(MDS_WAIT_INFINITE);

    // Call the user thread routine
    int iResult = pThread->m_pRoutine(pThread);

    // Set the exit code
    pThread->m_iExitCode = iResult;

    pThread->m_TerminatedEvent.set();

//    pthread_detach(pThread->m_ThreadId);
    pthread_exit(NULL);

    return NULL;
}


CThread::CThread(CThread::tRoutinePtr pRoutine, void *pData, bool bRun)
    : m_ThreadId(0)
    , m_pRoutine(pRoutine)
    , m_pData(pData)
    , m_bSuspended(!bRun)
    , m_ExitEvent(false, true)
    , m_TerminatedEvent(false, true)
    , m_NotSuspendedEvent(bRun, true)
    , m_iExitCode(-1)
{
    MDS_ASSERT(m_pRoutine);

    // Thread attributes
    pthread_attr_t attrDetached;
    pthread_attr_init(&attrDetached);
    pthread_attr_setdetachstate(&attrDetached, PTHREAD_CREATE_DETACHED);

    // Create the thread
//    int iResult = pthread_create(&m_ThreadId, 0, threadRoutine, (void *)this);
    int iResult = pthread_create(&m_ThreadId, &attrDetached, threadRoutine, (void *)this);
    if (iResult != 0)
    {
        MDS_THROW_ERROR("Constructor CThread::CThread() failed");
    }

    // Destroy the threads attributes
    pthread_attr_destroy(&attrDetached);

    // Detach the thread
/*    iResult = pthread_detach(m_ThreadId);
    if (iResult != 0)
    {
        MDS_THROW_ERROR("Constructor CThread::CThread() failed");
    }*/

    // Let's start the thread
    if( bRun )
    {
        resume();
    }
}


CThread::~CThread()
{
    // Terminates the thread
    terminate();
}


void CThread::terminate(bool bWait, unsigned uTimeout)
{
    m_CritSec.enter();

//    pthread_detach(m_ThreadId);
    m_ExitEvent.set();
    m_NotSuspendedEvent.set();

    if( bWait )
    {
        if( !m_TerminatedEvent.wait(uTimeout) )
        {
            if( pthread_cancel(m_ThreadId) != 0 )
            {
                MDS_LOG_WARNING("Method CThread::terminate() failed");
            }
        }
    }

    m_ThreadId = 0;

    m_CritSec.leave();
}


void CThread::setPriority(EThreadPriority ePriority)
{
    sched_param Param;
    int iPolicy;

    if( pthread_getschedparam(m_ThreadId, &iPolicy, &Param) != 0 )
    {
        MDS_LOG_WARNING("Method CThread::setPriority() failed");
    }

    // Minimal and maximal allowed priority
    int iMin = sched_get_priority_min(iPolicy);
    int iMax = sched_get_priority_max(iPolicy);
    if (iMin == -1 || iMax == -1)
    {
        MDS_LOG_WARNING("Method CThread::setPriority() failed");
    }

    // Compute the thread priority
    Param.sched_priority = (iMax - iMin) * (int)ePriority / (int)TP_HIGHEST + iMin;

    if( pthread_setschedparam(m_ThreadId, iPolicy, &Param) != 0 )
    {
        MDS_LOG_WARNING("Method CThread::setPriority() failed");
    }
}

#endif // _LINUX


} // namespace sys
} // namespace mds

