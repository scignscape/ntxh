//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/27                          \n
 *
 * $Id: mdsTimer.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Class encapsulating timer functions.
 */

#ifndef MDS_TIMER_H
#define MDS_TIMER_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#    include <mmsystem.h>
#endif // _WIN32

// Linux version
#ifdef _LINUX
#    include <unistd.h>
#    include <signal.h>
#    include <pthread.h>
#    include <time.h>
#    include <sys/types.h>
#    include <sys/time.h>
#    include <errno.h>
#endif // _LINUX

#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsEvent.h"


namespace mds
{
namespace sys
{

//==============================================================================
/*
 * Global definitions.
 */

//! Minimal timer resolution.
const unsigned TIMER_RESOLUTION     = 1;


//==============================================================================
/*
 * Global definitions.
 * - Linux version.
 */
#ifdef _LINUX

//! Timer description class declaration.
class CTimerDesc;

#endif // _LINUX


//==============================================================================
/*!
 * Class encapsulating timer functions.
 */
class MDS_SYSTEM_EXPORT CTimer : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CTimer);

public:
    //! Constructor.
    CTimer(unsigned uDelay, bool bRun = true);

    //! Default destructor.
    virtual ~CTimer();

    //! Waits for the timer event.
    bool wait(unsigned uTimeout) { return m_Event.wait(uTimeout); }

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
    void signal() { m_Event.set(); }

protected:
#ifdef _WIN32
    //! Handle of the timer.
    unsigned int m_hTimer;
#endif // _WIN32

#ifdef _LINUX
    //! Pointer to an object which stores additional timer information.
    CTimerDesc *m_pDesc;
#endif // _LINUX

    //! Event signalled every time the timer delay elapses.
    CEvent m_Event;

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
} // namespace mds

#endif // MDS_TIMER_H

