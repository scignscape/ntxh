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
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/24                       
 *
 * Description:
 * - Mutual exclusion.
 */

#ifndef VPL_MUTEX_H
#define VPL_MUTEX_H

#include <VPL/Base/Setup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <unistd.h>
#    include <pthread.h>
#endif

#include <VPL/Base/SharedPtr.h>

#include "System.h"
#include "SystemExport.h"


namespace vpl
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
class VPL_SYSTEM_EXPORT CMutex : public vpl::base::CObject
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CMutex);

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
#endif

#if defined(_LINUX) || defined(_MACOSX)
    //! POSIX mutex.
    pthread_mutex_t m_Mutex;
    pthread_mutexattr_t m_Attr;
#endif

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
} // namespace vpl

#endif // VPL_MUTEX_H

