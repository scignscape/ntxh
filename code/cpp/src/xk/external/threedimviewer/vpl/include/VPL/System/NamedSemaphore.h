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
 * Date:    2004/12/18                       
 */

#ifndef VPL_NamedSemaphore_H
#define VPL_NamedSemaphore_H

#include <VPL/Base/Setup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#    include <limits.h>
#endif

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <unistd.h>
#    include <sys/types.h>
#    include <sys/time.h>
#    include <sys/ipc.h>
#    include <sys/sem.h>
#    include <sys/stat.h>
#    include <errno.h>
#endif

#include <VPL/Base/SharedPtr.h>

#include "System.h"
#include "SystemExport.h"

// STL
#include <string>


namespace vpl
{
namespace sys
{

//==============================================================================
/*!
 * Named semaphore.
 */
class VPL_SYSTEM_EXPORT CNamedSemaphore : public vpl::base::CObject
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CNamedSemaphore);

public:
    //! Semaphore constructor.
    CNamedSemaphore(int iValue = 1,
                    const std::string *psName = NULL,
                    bool *pbAlreadyExists = NULL
                    );

    //! Destructor.
    virtual ~CNamedSemaphore();

    //! Locks the semaphore.
    //! - Decreases the semaphore value by one.
    void lock();

    //! Releases the semaphore.
    //! - Increases the value.
    void unlock(int iValue = 1);

protected:
#ifdef _WIN32
    //! Semaphore handle.
    HANDLE m_hSemaphore;
#endif

#if defined(_LINUX) || defined(_MACOSX)
    //! Semaphore used for mutual exclusion among processes.
    int m_iSemaphore;

    //! Key of the mutex.
    key_t m_SemaphoreKey;

    //! If set to true, the semaphore will be deleted by destructor.
    bool m_bDestroy;
#endif

private:
    //! Private copy constructor.
    CNamedSemaphore(const CNamedSemaphore&);

    //! Private assignment operator.
    void operator=(const CNamedSemaphore&);
};


//==============================================================================
/*!
 * Smart pointer to a semaphore.
 */
typedef CNamedSemaphore::tSmartPtr   CNamedSemaphorePtr;


} // namespace sys
} // namespace vpl

#endif // VPL_NamedSemaphore_H

