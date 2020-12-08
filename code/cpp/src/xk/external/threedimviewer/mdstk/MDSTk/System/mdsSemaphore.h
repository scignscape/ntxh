//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/12/18                          \n
 *
 * $Id: mdsSemaphore.h 1864 2010-09-01 09:07:40Z spanel $
 *
 * Description:
 * - Named semaphore.
 */

#ifndef MDS_SEMAPHORE_H
#define MDS_SEMAPHORE_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#    include <limits.h>
#endif // _WIN32

// Linux version
#ifdef _LINUX
#    include <unistd.h>
#    include <sys/types.h>
#    include <sys/time.h>
#    include <sys/ipc.h>
#    include <sys/sem.h>
#    include <sys/stat.h>
#    include <errno.h>
#endif //_LINUX

#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsSystem.h"
#include "mdsSystemExport.h"

// STL
#include <string>


namespace mds
{
namespace sys
{

//==============================================================================
/*!
 * Named semaphore.
 */
class MDS_SYSTEM_EXPORT CSemaphore : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CSemaphore);

public:
    //! Semaphore constructor.
    CSemaphore(int iValue = 1,
               const std::string *psName = NULL,
               bool *pbAlreadyExists = NULL
               );

    //! Destructor.
    virtual ~CSemaphore();

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
#endif // _WIN32

#ifdef _LINUX
    //! Semaphore used for mutual exclusion among processes.
    int m_iSemaphore;

    //! Key of the mutex.
    key_t m_SemaphoreKey;

    //! If set to true, the semaphore will be deleted by destructor.
    bool m_bDestroy;
#endif // _LINUX

private:
    //! Private copy constructor.
    CSemaphore(const CSemaphore&);

    //! Private assignment operator.
    void operator=(const CSemaphore&);
};


//==============================================================================
/*!
 * Smart pointer to a semaphore.
 */
typedef CSemaphore::tSmartPtr   CSemaphorePtr;


} // namespace sys
} // namespace mds

#endif // MDS_SEMAPHORE_H

