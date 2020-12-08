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

#ifndef VPL_TIMER_H
#define VPL_TIMER_H

#include <VPL/Base/Setup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#    include <mmsystem.h>
#endif

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <unistd.h>
#    include <signal.h>
#    include <pthread.h>
#    include <time.h>
#    include <sys/types.h>
#    include <sys/time.h>
#    include <errno.h>
#endif

#include <VPL/Base/SharedPtr.h>

#include "Condition.h"


namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Global definitions.
 */

//! Minimal timer resolution.
const unsigned TIMER_RESOLUTION     = 10; // Mac has a limit of 150 wakeups per second


//==============================================================================
/*
 * Global definitions.
 * - Linux and Mac version.
 */
#if defined(_LINUX) || defined(_MACOSX)

//! Timer description class declaration.
class CTimerDesc;

#endif


//==============================================================================
/*!
 * Class encapsulating timer functions.
 */
class VPL_SYSTEM_EXPORT CTimer : public vpl::base::CObject
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CTimer);

public:
    //! Constructor.
    CTimer(unsigned uDelay, bool bRun = true);

    //! Default destructor.
    virtual ~CTimer();

    //! Waits for the timer event.
    bool wait(unsigned uTimeout);

    //! Starts the timer.
    void start();

    //! Stops the timer.
    void stop();

    //! Sets the timer delay.
    void setDelay(unsigned uDelay);

    //! Returns the timer delay.
    unsigned getDelay() { return m_uDelay; }

    //! Returns true if the timer is already running.
    bool isRunning();

    //! Signals the timer event.
    void signal();

protected:
#ifdef _WIN32
    //! Handle of the timer.
    unsigned int m_hTimer;

    //! Windows event handle.
    HANDLE m_hEvent;
#endif

#if defined(_LINUX) || defined(_MACOSX)
    //! Condition signalled every time the timer delay elapses.
    CCondition m_Cond;
    CMutex m_Mutex;

    //! Pointer to an object which stores additional timer information.
    CTimerDesc *m_pDesc;
#endif

    //! The timer delay.
    unsigned m_uDelay;

private:
    //! Private copy constructor.
    CTimer(const CTimer&);

    //! Private assignment operator.
    void operator=(const CTimer&);
};


//==============================================================================
/*!
 * Smart pointer to the timer.
 */
typedef CTimer::tSmartPtr   CTimerPtr;


} // namespace sys
} // namespace vpl

#endif // VPL_TIMER_H

