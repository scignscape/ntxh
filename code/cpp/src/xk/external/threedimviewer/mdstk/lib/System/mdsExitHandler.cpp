//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/02                          \n
 *
 * $Id: mdsExitHandler.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Handling of the ^C exit sequence.
 */

#include <MDSTk/System/mdsExitHandler.h>

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsError.h>
#include <MDSTk/Base/mdsWarning.h>
#include <MDSTk/Base/mdsGlobalLog.h>

// STL
#include <iostream>


namespace mds
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the class mds::sys::CExitHandler.
 * - Platform independent.
 */

//! Objects count
int CExitHandler::m_iCount = 0;

//! Mutual exclusion
CMutex CExitHandler::m_Mutex;


//==============================================================================
/*
 * Implementation of the class mds::sys::CExitHandler.
 * - Windows version.
 */

#ifdef _WIN32

//! Exit event handle
HANDLE CExitHandler::m_hExitEvent;


//! Windows exit handler
BOOL WINAPI CExitHandler::CtrlHandlerRoutine(DWORD dwCtrlType)
{
    switch( dwCtrlType )
    {
        case CTRL_C_EVENT:
        case CTRL_BREAK_EVENT:
        case CTRL_CLOSE_EVENT:
        case CTRL_LOGOFF_EVENT:
        case CTRL_SHUTDOWN_EVENT:
            SetEvent(m_hExitEvent);
            break;
    }
    return true;
}


CExitHandler::CExitHandler()
{
    m_Mutex.lock();

    if( m_iCount == 0 )
    {
        m_hExitEvent = CreateEvent(NULL, true, false, NULL);
        if( !m_hExitEvent )
        {
            MDS_THROW_ERROR("Constructor CExitHandler::CExitHandler() failed");
        }

        BOOL bResult = SetConsoleCtrlHandler(CExitHandler::CtrlHandlerRoutine, TRUE);
        if( !bResult )
        {
            MDS_THROW_ERROR("Constructor CExitHandler::CExitHandler() failed");
        }
    }

    ++m_iCount;

    m_Mutex.unlock();
}


CExitHandler::~CExitHandler()
{
    m_Mutex.lock();

    if( (--m_iCount) == 0 )
    {
        BOOL bResult = CloseHandle(m_hExitEvent);
        if( !bResult )
        {
            MDS_LOG_WARNING("Destructor CExitHandler::~CExitHandler() failed");
        }

        bResult = SetConsoleCtrlHandler(CExitHandler::CtrlHandlerRoutine, FALSE);
        if( !bResult )
        {
            MDS_LOG_WARNING("Destructor CExitHandler::~CExitHandler() failed");
        }
    }

    m_Mutex.unlock();
}


bool CExitHandler::wait(unsigned uTimeout)
{
    return (WaitForSingleObject(m_hExitEvent, uTimeout) == WAIT_OBJECT_0);
}


bool CExitHandler::isCanceled()
{
    return (WaitForSingleObject(m_hExitEvent, 0) == WAIT_OBJECT_0);
}


void CExitHandler::exit()
{
    SetEvent(m_hExitEvent);
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class mds::sys::CExitHandler.
 * - Linux version.
 */

#ifdef _LINUX

//! Signals set
sigset_t CExitHandler::m_ExitSet, CExitHandler::m_EmptySet;

//! Signalled variable
sig_atomic_t CExitHandler::m_ExitEvent;


//! Linux signal handler
void CExitHandler::signalHandler(int iSignal)
{
    switch( iSignal )
    {
        case SIGINT:
        case SIGHUP:
        case SIGTERM:
            m_ExitEvent = 1;
            break;
    }
}


CExitHandler::CExitHandler()
{
    m_Mutex.lock();

    if( m_iCount == 0 )
    {
        // Create empty signal set
        sigemptyset(&m_EmptySet);

        // Block signals during the initialization
        sigemptyset(&m_ExitSet);
        sigaddset(&m_ExitSet, SIGINT);
        sigaddset(&m_ExitSet, SIGHUP);
        sigaddset(&m_ExitSet, SIGTERM);
        sigprocmask(SIG_BLOCK, &m_ExitSet, NULL);

        // Signal action
        struct sigaction SigAct;
        SigAct.sa_handler = CExitHandler::signalHandler;
        sigemptyset(&SigAct.sa_mask);
        SigAct.sa_flags = 0;
        sigaction(SIGHUP,  &SigAct, NULL);
        sigaction(SIGTERM, &SigAct, NULL);
        if( sigaction(SIGINT,  &SigAct, NULL) != 0 )
        {
            MDS_THROW_ERROR("Constructor CExitHandler::CExitHandler() failed");
        }

        // Unblock signals
        sigprocmask(SIG_UNBLOCK, &m_ExitSet, NULL);
    }

    ++m_iCount;

    m_Mutex.unlock();
}


CExitHandler::~CExitHandler()
{
    m_Mutex.lock();

    if( (--m_iCount) == 0 )
    {
        // Block signals
        sigprocmask(SIG_BLOCK, &m_ExitSet, NULL);

        // Set default signal action
        struct sigaction SigAct;
        SigAct.sa_handler = SIG_DFL;
        sigemptyset(&SigAct.sa_mask);
        SigAct.sa_flags = 0;
        sigaction(SIGINT, &SigAct, NULL);
        sigaction(SIGHUP, &SigAct, NULL);
        if( sigaction(SIGTERM, &SigAct, NULL) != 0 )
        {
            MDS_THROW_ERROR("Destructor CExitHandler::~CExitHandler() failed");
        }

        // Unblock signals
        sigprocmask(SIG_UNBLOCK, &m_ExitSet, NULL);
    }

    m_Mutex.unlock();
}


bool CExitHandler::wait(unsigned uTimeout)
{
    if( isCanceled() )
    {
        return true;
    }

    // Sleep for the specified time
    // - returns immediately if a signal has been delivered
    timespec Req, Rem;
    Req.tv_sec = uTimeout / 1000;
    Req.tv_nsec = (uTimeout % 1000) * 1000000;
    nanosleep(&Req, &Rem);

    // Second test
    return isCanceled();
}


bool CExitHandler::isCanceled()
{
    m_Mutex.lock();

    sigprocmask(SIG_BLOCK, &m_ExitSet, NULL);
    bool bResult = (m_ExitEvent != 0) ? true : false;
    sigprocmask(SIG_UNBLOCK, &m_ExitSet, NULL);

    m_Mutex.unlock();

    return bResult;
}


void CExitHandler::exit()
{
    m_Mutex.lock();

    sigprocmask(SIG_BLOCK, &m_ExitSet, NULL);
    m_ExitEvent = 1;
    sigprocmask(SIG_UNBLOCK, &m_ExitSet, NULL);

    m_Mutex.unlock();
}

#endif // _LINUX


} // namespace sys
} // namespace mds

