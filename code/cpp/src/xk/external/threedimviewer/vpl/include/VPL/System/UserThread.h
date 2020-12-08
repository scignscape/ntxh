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
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.c
 * Date:    2009/03/30                          \n
 *
 * Description:
 * - Thread control.
 */

#ifndef VPL_UserThread_H
#define VPL_UserThread_H

#include "Thread.h"


namespace vpl
{
namespace sys
{

//==============================================================================
/*!
 * Thread encapsulation. Internal thread routine calls a virtual method
 * that may be overloaded.
 */
class VPL_SYSTEM_EXPORT CUserThread : public CThread
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CUserThread);

public:
    //! Default constructor.
    CUserThread(void *pData = NULL, bool bRun = true);

    //! Virtual destructor.
    virtual ~CUserThread();

    //! Entry point of the thread. This function is pure virtual and must
    //! be implemented by any derived class. The thread execution
    //! is going to start here.
    //! - Please, call the method isExitSignalled() periodically to check
    //!   if the function should be terminated, or use the VPL_THREAD_MAIN_LOOP macro
    //!   to implement this behaviour.
    //! - Returned value can be checked further.
    virtual int entry() = 0;

protected:
    //! Real thread routine.
    static VPL_THREAD_ROUTINE(threadRoutine);

private:
    //! Private copy constructor.
    CUserThread(const CUserThread&);

    //! Private assignment operator.
    void operator=(const CUserThread&);
};


//==============================================================================
/*!
 * Smart pointer to the user thread.
 */
typedef CUserThread::tSmartPtr  CUserThreadPtr;


} // namespace sys
} // namespace vpl

#endif // VPL_UserThread_H

