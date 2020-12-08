//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/24                          \n
 *
 * $Id: mdsMutex.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Mutual exclusion.
 */

#include <MDSTk/System/mdsMutex.h>

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsError.h>
#include <MDSTk/Base/mdsWarning.h>
#include <MDSTk/Base/mdsGlobalLog.h>


namespace mds
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the class mds::sys::CMutex.
 * - Windows version.
 */

#ifdef _WIN32

CMutex::CMutex(bool bLocked)
{
    m_hMutex = CreateMutex(NULL, bLocked, NULL);
    if( !m_hMutex )
    {
        MDS_THROW_ERROR("Constructor CMutex::CMutex() failed");
    }
}


CMutex::~CMutex()
{
    BOOL bResult = CloseHandle(m_hMutex);
    if( !bResult )
    {
        MDS_LOG_WARNING("Destructor CMutex::~CMutex() failed");
    }
}


void CMutex::lock()
{
    DWORD dwResult = WaitForSingleObject(m_hMutex, INFINITE);
    if( dwResult != WAIT_OBJECT_0 )
    {
        MDS_LOG_WARNING("Method CMutex::lock() failed");
    }
}


void CMutex::unlock()
{
    BOOL bResult = ReleaseMutex(m_hMutex);
    if( !bResult )
    {
        MDS_LOG_WARNING("Method CMutex::unlock() failed");
    }
}


bool CMutex::tryLock()
{
    return (WaitForSingleObject(m_hMutex, 0) == WAIT_OBJECT_0);
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class mds::sys::CMutex.
 * - Linux version.
 */

#ifdef _LINUX

CMutex::CMutex(bool bLocked)
{
    pthread_mutexattr_init(&m_Attr);
    pthread_mutexattr_settype(&m_Attr, PTHREAD_MUTEX_RECURSIVE);

    if( pthread_mutex_init(&m_Mutex, &m_Attr) != 0 )
//    if( pthread_mutex_init(&m_Mutex, NULL) != 0 )
    {
        MDS_THROW_ERROR("Constructor CMutex::CMutex() failed");
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
        MDS_LOG_WARNING("Destructor CMutex::~CMutex() failed");
    }
}


void CMutex::lock()
{
    if( pthread_mutex_lock(&m_Mutex) != 0 )
    {
        MDS_LOG_WARNING("Method CMutex::lock() failed");
    }
}


void CMutex::unlock()
{
    if( pthread_mutex_unlock(&m_Mutex) != 0 )
    {
        MDS_LOG_WARNING("Method CMutex::unlock() failed");
    }
}


bool CMutex::tryLock()
{
    return (pthread_mutex_trylock(&m_Mutex) == 0);
}

#endif // _LINUX


} // namespace sys
} // namespace mds

