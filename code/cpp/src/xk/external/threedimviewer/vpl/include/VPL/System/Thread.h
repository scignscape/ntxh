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

#ifndef VPL_THREAD_H
#define VPL_THREAD_H

#include <VPL/Base/Setup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <unistd.h>
#    include <pthread.h>
#    include <sys/types.h>
#    include <sys/time.h>
#    include <errno.h>
#endif

#include <VPL/Base/SharedPtr.h>

#include "Atomic.h"
#include "Condition.h"


namespace vpl
{
namespace sys
{

//=============================================================================
/*
 * Global definitions.
 */

//! Waiting for a thread termination
const unsigned THREAD_EXIT_TIME     = 2000;


//=============================================================================
/*
 * Global definitions.
 * - Windows version.
 */

#ifdef _WIN32

//! Thread priority.
enum EThreadPriority
{
    TP_LOWEST       = THREAD_PRIORITY_LOWEST,
    TP_LOW          = THREAD_PRIORITY_BELOW_NORMAL,
    TP_NORMAL       = THREAD_PRIORITY_NORMAL,
    TP_HIGH         = THREAD_PRIORITY_ABOVE_NORMAL,
    TP_HIGHEST      = THREAD_PRIORITY_HIGHEST
};

#endif // _WIN32


//=============================================================================
/*
 * Global definitions.
 * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

//! Thread priority.
enum EThreadPriority
{
    TP_LOWEST       = 0,
    TP_LOW          = 25,
    TP_NORMAL       = 50,
    TP_HIGH         = 75,
    TP_HIGHEST      = 100
};

#endif // _LINUX || _MACOSX


//==============================================================================
/*!
 * Encapsulation of several thread functions into a class vpl::CThread.
 */
class VPL_SYSTEM_EXPORT CThread : public vpl::base::CObject
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CThread);

    //! User thread routine.
    //! - Please, call the method isExitSignalled() periodically to check
    //!   if the routine should be terminated, or use the VPL_THREAD_MAIN_LOOP macro
    //!   to implement this behaviour.
    typedef int (tRoutine)(CThread *pThread);

    //! Pointer to a user thread routine.
    typedef tRoutine *tRoutinePtr;

	//! Thread ID type.
	typedef unsigned tId;

public:
    //! Constructor.
    CThread(tRoutinePtr pRoutine, void *pData = NULL, bool bRun = true);

    //! Destructor.
    virtual ~CThread();


    //! Returns pointer to the user data.
    void *getData() { return m_pData; }

    //! Sets pointer to the user data.
    void setData(void *pData) { m_pData = pData; }

    //! Suspends the thread.
    void suspend();

    //! Resumes the suspended thread.
    void resume();

    //! Enforces the thread to terminate.
    void terminate(bool bWait = true, unsigned uTime = THREAD_EXIT_TIME);

    //! Waits for the thread termination.
    bool join(unsigned uTimeout);

    //! Detaches the thread.
    //! - You should call detach() when you do not want to wait
    //!   for the thread using join() so the system can immediately
    //!   reuse the resources once the thread terminates.
    void detach();

    //! Returns true if the thread is still active,
    //! i.e. either running or suspended.
    bool isActive();

    //! Sets the thread priority.
    void setPriority(EThreadPriority ePriority);

    //! Returns exit code returned by an user thread routine.
    //! - -1 if the thread is still running.
    int getExitCode();

    //! Just signals the exit to the thread routine.
    void exit();

    //! Returns true if the exit was already signalled.
    //! - The method starts waiting if the thread is suspended.
    bool isExitSignalled();

	//! Returns integer thread ID of the caller thread.
	static tId currentId();

protected:
#ifdef _WIN32
    //! Windows thread handle.
    HANDLE m_hThread;

    //! Windows thread identifier.
    DWORD m_dwThreadId;

    //! Windows thread routine.
    static DWORD WINAPI threadRoutine(LPVOID pData);
#endif // _WIN32

#if defined(_LINUX) || defined(_MACOSX)
    //! POSIX thread.
    pthread_t m_ThreadId;

    //! POSIX thread routine.
    static void *threadRoutine(void *pData);
#endif // _LINUX || _MACOSX

    //! Pointer to a user thread routine.
    tRoutinePtr m_pRoutine;

    //! Pointer to user data.
    void *m_pData;

    //! Thread state.
    CAtomic m_State;

    //! Signalled conditions.
    CCondition m_Cond, m_TermCond;

    //! Mutual access.
    CMutex m_Mutex;

    //! Thread exit code.
    int m_iExitCode;

private:
    //! Private copy constructor.
    CThread(const CThread&);

    //! Private assignment operator.
    void operator=(const CThread&);
};


//==============================================================================
/*!
 * Smart pointer to the mutex.
 */
typedef CThread::tSmartPtr          CThreadPtr;


//==============================================================================
/*
 * Thread routine definition macros.
 */

//! Thread routine declaration.
#define VPL_THREAD_ROUTINE(Name)    int Name(vpl::sys::CThread *pThread)

//! Thread main loop.
#define VPL_THREAD_MAIN_LOOP        while( !pThread->isExitSignalled() )


} // namespace sys
} // namespace vpl

#endif // VPL_THREAD_H

