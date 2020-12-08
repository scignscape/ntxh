//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/26                          \n
 *
 * $Id: mdsEvent.h 1864 2010-09-01 09:07:40Z spanel $
 *
 * Description:
 * - Signalling and waiting for events/conditions.
 */

#ifndef MDS_EVENT_H
#define MDS_EVENT_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif // _WIN32

// Linux version
#ifdef _LINUX
#    include <unistd.h>
#    include <pthread.h>
#    include <sys/types.h>
#    include <sys/time.h>
#    include <errno.h>
#endif // _LINUX

#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsSystem.h"
#include "mdsSystemExport.h"


namespace mds
{
namespace sys
{

//==============================================================================
/*
 * Global definitions.
 */

#ifdef _WIN32

//! Timer class declaration.
class CTimer;

#endif // _WIN32


//==============================================================================
/*!
 * Class encapsulating system event.
 */
class MDS_SYSTEM_EXPORT CEvent : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CEvent);

public:
    //! Constructor.
    //! - Creates a new event.
    CEvent(bool bState = false, bool bManual = false);

    //! Standard destructor.
    virtual ~CEvent();


    //! Sets the event to signaled state.
    //! - Returns true on success.
    bool set();

    //! Resets the event to non-signaled state.
    bool reset();

    //! Wait for the event's signaled state.
    bool wait(unsigned uTimeout = MDS_WAIT_INFINITE);

    //! True if event is in signaled state.
    bool isSet();

protected:
    //! Type of the event.
    //! - If the type is manual reseted then all waiting threads are released.
    //! - Otherwise just one waiting thread wakes up.
    bool m_bManual;

#ifdef _WIN32
    //! Windows event.
    HANDLE m_hEvent;

    //! Allow timer to access event handle.
    friend class CTimer;
#endif // _WIN32

#ifdef _LINUX
    //! Linux/POSIX conditions.
    pthread_mutex_t m_Mutex;
    pthread_cond_t m_Cond;
    bool m_bSignalled;

    //! Cancel cleanup handler.
    static void cleanupHandler(void *arg);
#endif // _LINUX

private:
    //! Private copy constructor.
    CEvent(const CEvent&);

    //! Private assignment operator.
    void operator=(const CEvent&);
};


//==============================================================================
/*!
 * Smart pointer to the event.
 */
typedef CEvent::tSmartPtr   CEventPtr;


} // namespace sys
} // namespace mds

#endif // MDS_EVENT_H

