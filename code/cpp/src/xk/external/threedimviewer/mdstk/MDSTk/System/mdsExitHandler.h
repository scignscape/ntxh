//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)      \n
 * Copyright (c) 2003-2005 by Michal Spanel       \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz    \n
 * Date:    2003/12/02                            \n
 *
 * $Id: mdsExitHandler.h 1864 2010-09-01 09:07:40Z spanel $
 *
 * Description:
 * - Handling of the ^C exit sequence.
 */

#ifndef MDS_EXITHANDLER_H
#define MDS_EXITHANDLER_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif // _WIN32

// Linux version
#ifdef _LINUX
#    include <unistd.h>
#    include <signal.h>
#endif // _LINUX

#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsEvent.h"
#include "mdsMutex.h"
#include "mdsSleep.h"


namespace mds
{
namespace sys
{

//==============================================================================
/*!
 * Class implementing an exit handler functions.
 */
class MDS_SYSTEM_EXPORT CExitHandler : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CExitHandler);

public:
    //! Default constructor.
    CExitHandler();

    //! Destructor.
    virtual ~CExitHandler();


    //! Waits for the exit event.
    //! - If timeout elapses it return false.
    bool wait(unsigned uTimeout = MDS_WAIT_INFINITE);

    //! True if the exit event is already signaled.
    bool isCanceled();

    //! Sets the exit event to the signalled state.
    void exit();

private:
    //! Objects count.
    static int m_iCount;

    //! Mutual exclusion.
    static CMutex m_Mutex;

#ifdef _WIN32
    //! Windows version.
    static BOOL WINAPI CtrlHandlerRoutine(DWORD dwCtrlType);

    //! The exit event handle.
    static HANDLE m_hExitEvent;
#endif // _WIN32

#ifdef _LINUX
    //! Linux version.
    static void signalHandler(int iSignal);

    //! Signals set.
    static sigset_t m_ExitSet, m_EmptySet;

    //! Signalled variable.
    static sig_atomic_t m_ExitEvent;
#endif // _LINUX

private:
    //! Private copy constructor.
    CExitHandler(const CExitHandler&);

    //! Private assignment operator.
    void operator=(const CExitHandler&);
};


//==============================================================================
/*!
 * Smart pointer to the exit handler.
 */
typedef CExitHandler::tSmartPtr     CExitHandlerPtr;


} // namespace sys
} // namespace mds

#endif // MDS_EXITHANDLER_H

