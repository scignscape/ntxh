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
 * Copyright (c) 2003-2010 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/30                       
 */

#ifndef VPL_Condition_H
#define VPL_Condition_H

#include <VPL/Base/SharedPtr.h>

#include "Mutex.h"

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <unistd.h>
#    include <pthread.h>
#    include <sys/types.h>
#    include <sys/time.h>
#    include <errno.h>
#endif


namespace vpl
{
namespace sys
{

//==============================================================================
/*!
 * Class encapsulating system condition.
 */
class VPL_SYSTEM_EXPORT CCondition : public vpl::base::CObject
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CCondition);

public:
    //! Constructor creates a new condition.
    CCondition();

    //! Standard destructor.
    virtual ~CCondition();


    //! Waits on a mutex for a given period of time.
    //! - The calling thread should obtain a mutex before it tests the predicate
    //!   or calls wait(). The implementation guarantees that wait() causes
    //!   the thread to atomically release the mutex and block! Then,
    //!   the mutex is reacquired and must be released!
    bool wait(CMutex& Mutex, unsigned uTimeout = VPL_WAIT_INFINITE);

    //! Signals a single waiting thread.
    //! - The mutex shall be locked before calling this method!
    void notifyOne();

    //! Wakes all waiting threads.
    //! - The mutex shall be locked before calling this method!
    void notifyAll();

protected:
#ifdef _WIN32
    //! Windows event.
    HANDLE m_hEvent;

    //! Number of waiting threads and number of threads to wake up.
    unsigned m_Threads, m_Wakeup;

    //! Critical section providing mutual access to the number of waiting threads.
    CRITICAL_SECTION m_CritSec;
#endif

#if defined(_LINUX) || defined(_MACOSX)
    //! Linux condition.
    pthread_cond_t m_Cond;

    //! Cancel cleanup handler.
    static void cleanupHandler(void *arg);
#endif

private:
    //! Private copy constructor.
    CCondition(const CCondition&);

    //! Private assignment operator.
    void operator=(const CCondition&);
};


//==============================================================================
/*!
 * Smart pointer to the Condition.
 */
typedef CCondition::tSmartPtr   CConditionPtr;


} // namespace sys
} // namespace vpl

#endif // VPL_Condition_H

