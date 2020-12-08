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
 * Date:    2003/10/24                          \n
 *
 * Description:
 * - Mutual exclusion.
 */

#include <VPL/System/Mutex.h>

#include <VPL/Base/Assert.h>
#include <VPL/Base/Error.h>
#include <VPL/Base/Warning.h>
#include <VPL/Base/Logging.h>


namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the class vpl::sys::CMutex.
 * - Windows version.
 */

#ifdef _WIN32

CMutex::CMutex(bool bLocked)
{
    m_hMutex = CreateMutex(NULL, bLocked, NULL);
    if( !m_hMutex )
    {
        VPL_THROW_ERROR("Constructor CMutex::CMutex() failed");
    }
}


CMutex::~CMutex()
{
    BOOL bResult = CloseHandle(m_hMutex);
    if( !bResult )
    {
        VPL_LOG_WARN("Destructor CMutex::~CMutex() failed");
    }
}


void CMutex::lock()
{
    DWORD dwResult = WaitForSingleObject(m_hMutex, INFINITE);
    if( dwResult != WAIT_OBJECT_0 )
    {
        VPL_LOG_WARN("Method CMutex::lock() failed");
    }
}


void CMutex::unlock()
{
    BOOL bResult = ReleaseMutex(m_hMutex);
    if( !bResult )
    {
        VPL_LOG_WARN("Method CMutex::unlock() failed");
    }
}


bool CMutex::tryLock()
{
    return (WaitForSingleObject(m_hMutex, 0) == WAIT_OBJECT_0);
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class vpl::sys::CMutex.
 * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

CMutex::CMutex(bool bLocked)
{
    pthread_mutexattr_init(&m_Attr);
    pthread_mutexattr_settype(&m_Attr, PTHREAD_MUTEX_RECURSIVE);

    if( pthread_mutex_init(&m_Mutex, &m_Attr) != 0 )
//    if( pthread_mutex_init(&m_Mutex, NULL) != 0 )
    {
        VPL_THROW_ERROR("Constructor CMutex::CMutex() failed");
    }

    if( bLocked )
    {
        pthread_mutex_lock(&m_Mutex);
    }
}


CMutex::~CMutex()
{
    if( pthread_mutex_destroy(&m_Mutex) != 0 )
    {
        VPL_LOG_WARN("Destructor CMutex::~CMutex() failed");
    }
}


void CMutex::lock()
{
    if( pthread_mutex_lock(&m_Mutex) != 0 )
    {
        VPL_LOG_WARN("Method CMutex::lock() failed");
    }
}


void CMutex::unlock()
{
    if( pthread_mutex_unlock(&m_Mutex) != 0 )
    {
        VPL_LOG_WARN("Method CMutex::unlock() failed");
    }
}


bool CMutex::tryLock()
{
    return (pthread_mutex_trylock(&m_Mutex) == 0);
}

#endif // _LINUX || _MACOSX


} // namespace sys
} // namespace vpl

