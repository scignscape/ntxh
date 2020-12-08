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
 * Date:    2003/10/24                          \n
 *
 * Description:
 * - Thread control.
 */

#include <VPL/System/Thread.h>
#include <VPL/System/ScopedLock.h>
#include <VPL/System/Sleep.h>

#include <VPL/Base/Assert.h>
#include <VPL/Base/Error.h>
#include <VPL/Base/Warning.h>
#include <VPL/Base/Logging.h>


namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the class vpl::sys::CThread.
 * - Platform independent.
 */

//! Internal thread states
const unsigned T_INITIALIZED    = 0;
const unsigned T_SUSPENDED      = 1;
const unsigned T_RUNNING        = 2;
const unsigned T_EXIT_SIGNALLED = 3;
const unsigned T_TERMINATED     = 4;


void CThread::resume()
{
    vpl::sys::tScopedLock Guard(m_Mutex);

    m_State = T_RUNNING;
    m_Cond.notifyAll();
}


void CThread::suspend()
{
    m_State = T_SUSPENDED;
}


bool CThread::join(unsigned uTimeout)
{
    bool bResult = true;
    if( m_State < T_TERMINATED )
    {
        vpl::sys::tScopedLock Guard(m_Mutex);
        if( m_State < T_TERMINATED )
        {
            bResult = m_TermCond.wait(m_Mutex, uTimeout);
        }
    }
    return bResult;
}


bool CThread::isActive()
{
    return (m_State < T_TERMINATED);
}


bool CThread::isExitSignalled()
{
    if( m_State >= T_EXIT_SIGNALLED )
    {
        return true;
    }

    vpl::sys::tScopedLock Guard(m_Mutex);

    // Wait while the thread is suspended
    while( m_State <= T_SUSPENDED )
    {
        m_Cond.wait(m_Mutex, THREAD_EXIT_TIME);
    }

    // Check whether the exit event is signalled
    return (m_State >= T_EXIT_SIGNALLED);
}


CThread::tId CThread::currentId()
{
#ifdef _WIN32
	const DWORD id = GetCurrentThreadId();
#elif defined(_MACOSX)
    uint64_t id;
    pthread_threadid_np(NULL, &id);
#elif defined(_LINUX)
    uint64_t id;
    id =  pthread_self();
#endif

	return static_cast<tId>(id);
}


int CThread::getExitCode()
{
    vpl::sys::tScopedLock Guard(m_Mutex);

    return m_iExitCode;
}


void CThread::exit()
{
    if( m_State < T_EXIT_SIGNALLED )
    {
        vpl::sys::tScopedLock Guard(m_Mutex);
        m_State = T_EXIT_SIGNALLED;
        m_Cond.notifyAll();
    }
}


//==============================================================================
/*
 * Implementation of the class vpl::sys::CThread.
 * - Windows version.
 */

#ifdef _WIN32

DWORD WINAPI CThread::threadRoutine(LPVOID pData)
{
    // Pointer to the thread class instance
    CThread *pThread = (CThread *)pData;
    VPL_ASSERT(pThread);

    // Wait if the thread is suspended...
    if( !pThread->isExitSignalled() )
    {
        // Call the user thread routine and set the exit code
        pThread->m_iExitCode = pThread->m_pRoutine(pThread);
    }

    // Notify all threads waiting until this one finishes
    {
        vpl::sys::tScopedLock Guard(pThread->m_Mutex);
        pThread->m_State = T_TERMINATED;
        pThread->m_TermCond.notifyAll();
    }

    ExitThread(0);

    return 0;
}


CThread::CThread(CThread::tRoutinePtr pRoutine, void *pData, bool bRun)
    : m_hThread(0)
    , m_dwThreadId(0)
    , m_pRoutine(pRoutine)
    , m_pData(pData)
    , m_State(T_INITIALIZED)
    , m_iExitCode(-1)
{
    VPL_ASSERT(m_pRoutine);

    // Creation of a new thread
    m_hThread = CreateThread(0, 0, threadRoutine, (void *)this, 0, &m_dwThreadId);
    if( !m_hThread )
    {
        VPL_THROW_ERROR("Constructor CThread::CThread() failed");
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

    vpl::sys::tScopedLock Guard(m_Mutex);

    if( m_hThread )
    {
        CloseHandle(m_hThread);
    }
}


void CThread::terminate(bool bWait, unsigned uTimeout)
{
    if( m_dwThreadId != 0 )
    {
        exit();

        if( bWait )
        {
            vpl::sys::tScopedLock Guard(m_Mutex);
            if( m_State < T_TERMINATED )
            {
                m_TermCond.wait(m_Mutex, uTimeout);
                if( m_State < T_TERMINATED )
                {
                    if( TerminateThread(m_hThread, 0) == 0 )
                    {
                        VPL_LOG_WARN("Method CThread::terminate() failed");
                    }
                }
            }
        }
    }

    m_dwThreadId = 0;
}


void CThread::detach()
{
}


void CThread::setPriority(EThreadPriority ePriority)
{
    if( SetThreadPriority(m_hThread, ePriority) == 0 )
    {
        VPL_LOG_WARN("Method CThread::setPriority() failed");
    }
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class vpl::sys::CThread.
 * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

void *CThread::threadRoutine(void *pData)
{
    // Pointer to the thread class instance
    CThread *pThread = static_cast<CThread *>(pData);
    VPL_ASSERT(pThread);

    // Enable POSIX thread cancelation
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, 0);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, 0);

    // Wait if the thread is suspended...
    if( !pThread->isExitSignalled() )
    {
        // Call the user thread routine and set the exit code
        pThread->m_iExitCode = pThread->m_pRoutine(pThread);
    }

    // Notify all threads waiting until this one finishes
    {
        vpl::sys::tScopedLock Guard(pThread->m_Mutex);
        pThread->m_State = T_TERMINATED;
        pThread->m_TermCond.notifyAll();
    }

//    pthread_detach(pThread->m_ThreadId);
    pthread_exit(NULL);

    return NULL;
}


CThread::CThread(CThread::tRoutinePtr pRoutine, void *pData, bool bRun)
    : m_ThreadId(0)
    , m_pRoutine(pRoutine)
    , m_pData(pData)
    , m_State(T_INITIALIZED)
    , m_iExitCode(-1)
{
    VPL_ASSERT(m_pRoutine);

    // Thread attributes
    pthread_attr_t attrDetached;
    pthread_attr_init(&attrDetached);
    //pthread_attr_setdetachstate(&attrDetached, PTHREAD_CREATE_DETACHED);
    pthread_attr_setdetachstate(&attrDetached, PTHREAD_CREATE_JOINABLE);

    // Create the thread
    int iResult = pthread_create(&m_ThreadId, &attrDetached, threadRoutine, (void *)this);
    if (iResult != 0)
    {
        VPL_THROW_ERROR("Constructor CThread::CThread() failed");
    }

    // Destroy the threads attributes
    pthread_attr_destroy(&attrDetached);

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
    exit();

    if( bWait )
    {
        vpl::sys::tScopedLock Guard(m_Mutex);
        if( m_State < T_TERMINATED )
        {
            m_TermCond.wait(m_Mutex, uTimeout);
            if( m_State < T_TERMINATED )
            {
                if( pthread_cancel(m_ThreadId) != 0 )
                {
                    VPL_LOG_WARN("Method CThread::terminate() failed");
                }
            }
        }
    }

    m_ThreadId = 0;
}


void CThread::detach()
{
    if( pthread_detach(m_ThreadId) != 0 )
    {
        VPL_LOG_WARN("Method CThread::detach() failed");
    }
}


void CThread::setPriority(EThreadPriority ePriority)
{
    sched_param Param;
    int iPolicy;

    if( pthread_getschedparam(m_ThreadId, &iPolicy, &Param) != 0 )
    {
        VPL_LOG_WARN("Method CThread::setPriority() failed");
    }

    // Minimal and maximal allowed priority
    int iMin = sched_get_priority_min(iPolicy);
    int iMax = sched_get_priority_max(iPolicy);
    if (iMin == -1 || iMax == -1)
    {
        VPL_LOG_WARN("Method CThread::setPriority() failed");
    }

    // Compute the thread priority
    Param.sched_priority = (iMax - iMin) * (int)ePriority / (int)TP_HIGHEST + iMin;

    if( pthread_setschedparam(m_ThreadId, iPolicy, &Param) != 0 )
    {
        VPL_LOG_WARN("Method CThread::setPriority() failed");
    }
}

#endif // _LINUX || _MACOSX


} // namespace sys
} // namespace vpl

