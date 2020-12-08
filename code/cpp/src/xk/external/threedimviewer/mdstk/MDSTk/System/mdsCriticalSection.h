//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/22                          \n
 *
 * $Id: mdsCriticalSection.h 1864 2010-09-01 09:07:40Z spanel $
 *
 * Description:
 * - Critical section.
 */

#ifndef MDS_CRITICALSECTION_H
#define MDS_CRITICALSECTION_H

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
/*!
 * Class that encapsulates system critical section.
 * - Its functionality is similar to a recursive mutex.
 */
class MDS_SYSTEM_EXPORT CCriticalSection : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CCriticalSection);

public:
    //! Default constructor.
    CCriticalSection();

    //! Destructor.
    virtual ~CCriticalSection();

    //! Enters critical section.
    //! - If there is a process in the section, execution is suspended.
    void enter();

    //! Tries to enter critical section. If it's already locked, returns immediately.
    //! - Returns true when section obtained. False otherwise.
    bool tryEnter();

    //! Leaves critical section.
    void leave();

private:
#ifdef _WIN32
    //! Windows critical section.
    CRITICAL_SECTION m_CritSec;
#endif // _WIN32

#ifdef _LINUX
    //! Linux critical section implemented via mutexes and conditions.
    pthread_mutex_t m_Mutex;
    pthread_mutexattr_t m_Attr;
#endif // _LINUX

private:
    //! Private copy constructor.
    CCriticalSection(const CCriticalSection&);

    //! Private assignment operator.
    void operator=(const CCriticalSection&);
};


//==============================================================================
/*!
 * Smart pointer to the critical section.
 */
typedef CCriticalSection::tSmartPtr     CCriticalSectionPtr;


} // namespace sys
} // namespace mds

#endif // MDS_CRITICALSECTION_H

