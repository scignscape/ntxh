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
 * Date:    2003/12/02                          \n
 *
 * Description:
 * - Handling of the ^C exit sequence.
 */

#include <VPL/System/ExitHandler.h>
#include <VPL/System/ScopedLock.h>

#include <VPL/Base/Assert.h>
#include <VPL/Base/Error.h>
#include <VPL/Base/Warning.h>
#include <VPL/Base/Logging.h>

// STL
#include <iostream>


namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the class vpl::sys::CExitHandler.
 * - Platform independent.
 */

// Objects count
int CExitHandler::m_iCount = 0;

// Mutual exclusion
CMutex CExitHandler::m_Mutex;


//==============================================================================
/*
 * Implementation of the class vpl::sys::CExitHandler.
 * - Windows version.
 */

#ifdef _WIN32

// Signalled condition
CCondition CExitHandler::m_Condition;

// Signalled variable
CAtomic CExitHandler::m_Signalled = 0;


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
            CExitHandler::exit();
            break;
    }
    return true;
}


CExitHandler::CExitHandler()
{
    vpl::sys::tScopedLock Guard(m_Mutex);

    if( m_iCount == 0 )
    {
        BOOL bResult = SetConsoleCtrlHandler(CExitHandler::CtrlHandlerRoutine, TRUE);
        if( !bResult )
        {
            VPL_THROW_ERROR("Constructor CExitHandler::CExitHandler() failed");
        }
    }

    ++m_iCount;
}


CExitHandler::~CExitHandler()
{
    vpl::sys::tScopedLock Guard(m_Mutex);

    if( (--m_iCount) == 0 )
    {
        BOOL bResult = SetConsoleCtrlHandler(CExitHandler::CtrlHandlerRoutine, FALSE);
        if( !bResult )
        {
            VPL_LOG_WARN("Destructor CExitHandler::~CExitHandler() failed");
        }
    }
}


bool CExitHandler::wait(unsigned uTimeout)
{
    if( isCanceled() )
    {
        return true;
    }

    vpl::sys::tScopedLock Guard(m_Mutex);
    return m_Condition.wait(m_Mutex, uTimeout);
}


bool CExitHandler::isCanceled()
{
    return (m_Signalled > 0);
}


void CExitHandler::exit()
{
    vpl::sys::tScopedLock Guard(m_Mutex);

    m_Signalled = 1;
    m_Condition.notifyAll();
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class vpl::sys::CExitHandler.
 * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

// Signal sets
sigset_t CExitHandler::m_ExitSet;

// Signalled variable
sig_atomic_t CExitHandler::m_ExitEvent = 0;


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
    vpl::sys::tScopedLock Guard(m_Mutex);

    if( m_iCount == 0 )
    {
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
            VPL_THROW_ERROR("Constructor CExitHandler::CExitHandler() failed");
        }

        // Unblock signals
        sigprocmask(SIG_UNBLOCK, &m_ExitSet, NULL);
    }

    ++m_iCount;
}


CExitHandler::~CExitHandler()
{
    vpl::sys::tScopedLock Guard(m_Mutex);

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
            VPL_THROW_ERROR("Destructor CExitHandler::~CExitHandler() failed");
        }

        // Unblock signals
        sigprocmask(SIG_UNBLOCK, &m_ExitSet, NULL);
    }
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
    vpl::sys::tScopedLock Guard(m_Mutex);

    sigprocmask(SIG_BLOCK, &m_ExitSet, NULL);
    bool bResult = (m_ExitEvent > 0);
    sigprocmask(SIG_UNBLOCK, &m_ExitSet, NULL);
    return bResult;
}


void CExitHandler::exit()
{
    vpl::sys::tScopedLock Guard(m_Mutex);

    sigprocmask(SIG_BLOCK, &m_ExitSet, NULL);
    m_ExitEvent = 1;
    sigprocmask(SIG_UNBLOCK, &m_ExitSet, NULL);
}

#endif // _LINUX || _MACOSX


} // namespace sys
} // namespace vpl

