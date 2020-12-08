//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/24                          \n
 *
 * $Id: mdsThread.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Thread control.
 */

#ifndef MDS_THREAD_H
#define MDS_THREAD_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif

// Linux version
#ifdef _LINUX
#    include <unistd.h>
#    include <pthread.h>
#    include <sys/types.h>
#    include <sys/time.h>
#    include <errno.h>
#endif

#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsCriticalSection.h"
#include "mdsEvent.h"


namespace mds
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
 * - Linux version.
 */

#ifdef _LINUX

//! Thread priority.
enum EThreadPriority
{
    TP_LOWEST       = 0,
    TP_LOW          = 25,
    TP_NORMAL       = 50,
    TP_HIGH         = 75,
    TP_HIGHEST      = 100
};

#endif // _LINUX


//==============================================================================
/*!
 * Encapsulation of several thread functions into a class mds::CThread.
 */
class MDS_SYSTEM_EXPORT CThread : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CThread);

    //! User thread routine.
    //! - Please, call the method isExitSignalled() periodically to check
    //!   if the routine should be terminated, or use the MDS_THREAD_MAIN_LOOP macro
    //!   to implement this behaviour.
    typedef int (tRoutine)(CThread *pThread);

    //! Pointer to a user thread routine.
    typedef tRoutine *tRoutinePtr;

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

    //! Terminates the thread.
    void terminate(bool bWait = true, unsigned uTime = THREAD_EXIT_TIME);

    //! Waits for the thread termination.
    bool join(unsigned uTimeout) { return m_TerminatedEvent.wait(uTimeout); }

    //! Returns true if the thread is running.
    bool isActive() { return (!m_TerminatedEvent.isSet()); }

    //! Sets the thread priority.
    void setPriority(EThreadPriority ePriority);

    //! Returns exit code returned by an user thread routine.
    //! - -1 if the thread is still running.
    int getExitCode();

    //! Signals the exit event that controls the thread termination.
    void setExitEvent() { m_ExitEvent.set(); }

    //! Returns true if the exit event is already signalled.
    bool isExitSignalled();

protected:
#ifdef _WIN32
    //! Windows thread handle.
    HANDLE m_hThread;

    //! Windows thread identifier.
    DWORD m_dwThreadId;

    //! Windows thread routine.
    static DWORD WINAPI threadRoutine(LPVOID pData);
#endif // _WIN32

#ifdef _LINUX
    //! POSIX thread.
    pthread_t m_ThreadId;

    //! POSIX thread routine.
    static void *threadRoutine(void *pData);
#endif // _LINUX

    //! Pointer to a user thread routine.
    tRoutinePtr m_pRoutine;

    //! Pointer to user data.
    void *m_pData;

    //! Thread suspended flag.
    bool m_bSuspended;

    //! Event the thread should check periodically and exit when it's set.
    CEvent m_ExitEvent;

    //! Event signalled when the thread has terminated.
    CEvent m_TerminatedEvent;

    //! Event signalled if the thread is not paused.
    CEvent m_NotSuspendedEvent;

    //! Critical section for mutual access.
    CCriticalSection m_CritSec;

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
#define MDS_THREAD_ROUTINE(Name)    int Name(mds::sys::CThread *pThread)

//! Thread main loop.
#define MDS_THREAD_MAIN_LOOP        while( !pThread->isExitSignalled() )


} // namespace sys
} // namespace mds

#endif // MDS_THREAD_H

