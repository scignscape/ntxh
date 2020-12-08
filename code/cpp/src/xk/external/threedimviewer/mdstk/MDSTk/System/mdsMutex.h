//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/24                          \n
 *
 * $Id: mdsMutex.h 1864 2010-09-01 09:07:40Z spanel $
 *
 * Description:
 * - Mutual exclusion.
 */

#ifndef MDS_MUTEX_H
#define MDS_MUTEX_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif // _WIN32

// Linux version
#ifdef _LINUX
#    include <unistd.h>
#    include <pthread.h>
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
 * Forward declarations.
 */
class CCondition;


//==============================================================================
/*!
 * Class providing simple mutual exclusion (recursive version).
 * - A thread that owns the mutex can lock the same mutex repeatedly
 *   without blocking its execution.
 */
class MDS_SYSTEM_EXPORT CMutex : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CMutex);

public:
    //! Constructor that creates a new mutex.
    CMutex(bool bLocked = false);

    //! Destructor.
    virtual ~CMutex();

    //! Locks the mutex.
    void lock();

    //! Tries to lock the mutex. If it's already locked, returns immediately.
    //! - Returns true when obtained, false otherwise.
    bool tryLock();

    //! Releases ownership of the mutex.
    void unlock();

protected:
#ifdef _WIN32
    //! Windows mutex.
    HANDLE m_hMutex;
#endif // _WIN32

#ifdef _LINUX
    //! Linux mutex.
    pthread_mutex_t m_Mutex;
    pthread_mutexattr_t m_Attr;
#endif // _LINUX

private:
    //! Private copy constructor.
    CMutex(const CMutex&);

    //! Private assignment operator.
    void operator=(const CMutex&);

    // Friend classes...
    friend class CCondition;
};


//==============================================================================
/*!
 * Smart pointer to the mutex.
 */
typedef CMutex::tSmartPtr   CMutexPtr;


} // namespace sys
} // namespace mds

#endif // MDS_MUTEX_H

