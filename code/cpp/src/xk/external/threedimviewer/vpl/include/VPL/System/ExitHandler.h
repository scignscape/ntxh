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
 * Copyright (c) 2003-2005 by Michal Spanel    
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz 
 * Date:    2003/12/02                         
 *
 * Description:
 * - Handling of the ^C exit sequence.
 */

#ifndef VPL_EXITHANDLER_H
#define VPL_EXITHANDLER_H

#include <VPL/Base/Setup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <unistd.h>
#    include <signal.h>
#endif

#include <VPL/Base/SharedPtr.h>

#include "Atomic.h"
#include "Condition.h"
#include "Sleep.h"


namespace vpl
{
namespace sys
{

//==============================================================================
/*!
 * Class implementing an exit handler functions.
 */
class VPL_SYSTEM_EXPORT CExitHandler : public vpl::base::CObject
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CExitHandler);

public:
    //! Default constructor.
    CExitHandler();

    //! Destructor.
    virtual ~CExitHandler();


    //! Waits for the exit event.
    //! - If timeout elapses it return false.
    bool wait(unsigned uTimeout = VPL_WAIT_INFINITE);

    //! True if the exit event is already signaled.
    bool isCanceled();

    //! Sets the exit event to the signalled state.
    static void exit();

private:
    //! Objects count.
    static int m_iCount;

    //! Mutual exclusion.
    static CMutex m_Mutex;

#ifdef _WIN32
    //! Signalled condition.
    static CCondition m_Condition;

    //! Signalled variable (non-zero when exit was already signalled).
    static CAtomic m_Signalled;

    //! Windows version.
    static BOOL WINAPI CtrlHandlerRoutine(DWORD dwCtrlType);
#endif

#if defined(_LINUX) || defined(_MACOSX)
    //! Linux version.
    static void signalHandler(int iSignal);

    //! Signal sets.
    static sigset_t m_ExitSet;

    //! Signalled variable.
    static sig_atomic_t m_ExitEvent;
#endif

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
} // namespace vpl

#endif // VPL_EXITHANDLER_H

