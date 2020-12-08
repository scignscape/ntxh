//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/22                          \n
 *
 * $Id: mdsCriticalSection.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Critical section
 */

#include <MDSTk/System/mdsCriticalSection.h>

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
 * Implementation of the class mds::sys::CCriticalSection
 * - Windows version
 */

#ifdef _WIN32

CCriticalSection::CCriticalSection()
{
    InitializeCriticalSection(&m_CritSec);
}


CCriticalSection::~CCriticalSection()
{
    DeleteCriticalSection(&m_CritSec);
}


void CCriticalSection::enter()
{
    EnterCriticalSection(&m_CritSec);
}


bool CCriticalSection::tryEnter()
{
    return (TryEnterCriticalSection(&m_CritSec) != 0);
}


void CCriticalSection::leave()
{
    LeaveCriticalSection(&m_CritSec);
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class mds::sys::CCriticalSection
 * - Linux version
 */

#ifdef _LINUX

CCriticalSection::CCriticalSection()
{
    pthread_mutexattr_init(&m_Attr);
    pthread_mutexattr_settype(&m_Attr, PTHREAD_MUTEX_RECURSIVE);

    if( pthread_mutex_init(&m_Mutex, &m_Attr) != 0 )
    {
        MDS_THROW_ERROR("Constructor CCriticalSection::CCriticalSection() failed");
    }
}


CCriticalSection::~CCriticalSection()
{
    if( pthread_mutex_destroy(&m_Mutex) != 0 )
    {
        MDS_LOG_WARNING("Destructor CCriticalSection::~CCriticalSection() failed");
    }

    pthread_mutexattr_destroy(&m_Attr);
}


void CCriticalSection::enter()
{
    if( pthread_mutex_lock(&m_Mutex) != 0 )
    {
        MDS_LOG_WARNING("Method CCriticalSection::enter() failed");
    }
}


bool CCriticalSection::tryEnter()
{
    return (pthread_mutex_trylock(&m_Mutex) == 0);
}


void CCriticalSection::leave()
{
    if( pthread_mutex_unlock(&m_Mutex) != 0 )
    {
        MDS_LOG_WARNING("Method CCriticalSection::leave() failed");
    }
}

#endif // _LINUX


} // namespace sys
} // namespace mds

