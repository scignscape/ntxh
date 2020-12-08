//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/30                          \n
 *
 * $Id: mdsCondition.h 1864 2010-09-01 09:07:40Z spanel $
 *
 * Description:
 * - Signalling and waiting for conditions.
 */

#ifndef MDS_Condition_H
#define MDS_Condition_H

#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsMutex.h"

// Linux version
#ifdef _LINUX
#    include <unistd.h>
#    include <pthread.h>
#    include <sys/types.h>
#    include <sys/time.h>
#    include <errno.h>
#endif // _LINUX


namespace mds
{
namespace sys
{

//==============================================================================
/*!
 * Class encapsulating system Condition.
 */
class MDS_SYSTEM_EXPORT CCondition : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CCondition);

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
    bool wait(CMutex& Mutex, unsigned uTimeout = MDS_WAIT_INFINITE);

    //! Signals a single waiting thread.
    //! - Returns true on success.
    //! - The mutex shall be locked before calling this method!
    void signal();

    //! Wakes all waiting threads.
    //! - Returns true on success.
    //! - The mutex shall be locked before calling this method!
    void broadcast();

protected:
#ifdef _WIN32
    //! Windows event.
    HANDLE m_hEvent;

    //! Number of waiting threads and number of threads to wake up.
    unsigned m_Threads, m_Wakeup;

    //! Critical section providing mutual access to the number of waiting threads.
    CRITICAL_SECTION m_CritSec;
#endif // _WIN32

#ifdef _LINUX
    //! Linux condition.
    pthread_cond_t m_Cond;

    //! Cancel cleanup handler.
    static void cleanupHandler(void *arg);
#endif // _LINUX

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
} // namespace mds

#endif // MDS_Condition_H

