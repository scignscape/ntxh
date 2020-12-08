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
 * Date:    2004/12/18                          \n
 */

#include <VPL/System/NamedSemaphore.h>

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
 * Global definitions.
 * - Windows version.
 */

#ifdef _WIN32

//! Default semaphore name prefix.
const std::string SEMAPHORE_NAME_PREFIX = "::CNamedSemaphore::";

#endif


//==============================================================================
/*
 * Global definitions.
 * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

//! Default semaphore name prefix.
const std::string SEMAPHORE_NAME_PREFIX = "/::CNamedSemaphore::";

#endif


//==============================================================================
/*
 * Implementation of the class vpl::sys::CNamedSemaphore.
 * - Windows version.
 */

#ifdef _WIN32

CNamedSemaphore::CNamedSemaphore(int iValue,
                                 const std::string *psName,
                                 bool *pbAlreadyExists
                                 )
    : m_hSemaphore(0)
{
    if( psName )
    {
        // Create a semaphore name
        std::string sName = SEMAPHORE_NAME_PREFIX + *psName;

        // Create the semaphore
        SetLastError(0);
        m_hSemaphore = CreateSemaphore(NULL,
                                       (LONG)iValue,
                                       LONG_MAX,
                                       sName.c_str()
                                       );
        if( !m_hSemaphore )
        {
            VPL_THROW_ERROR("Constructor CNamedSemaphore::CNamedSemaphore() failed");
        }

        if( pbAlreadyExists )
        {
            *pbAlreadyExists = (ERROR_ALREADY_EXISTS == GetLastError());
        }
    }
    else
    {
        m_hSemaphore = CreateSemaphore(NULL, (LONG)iValue, LONG_MAX, NULL);
        if( !m_hSemaphore )
        {
            VPL_THROW_ERROR("Constructor CNamedSemaphore::CNamedSemaphore() failed");
        }

        if( pbAlreadyExists )
        {
            *pbAlreadyExists = false;
        }
    }
}


CNamedSemaphore::~CNamedSemaphore()
{
    if( m_hSemaphore )
    {
        if( CloseHandle(m_hSemaphore) == 0 )
        {
            VPL_LOG_WARN("Destructor CNamedSemaphore::~CNamedSemaphore() failed");
        }
    }
}


void CNamedSemaphore::lock()
{
    if( WaitForSingleObject(m_hSemaphore, INFINITE) != WAIT_OBJECT_0 )
    {
        VPL_LOG_WARN("Method CNamedSemaphore::lock() failed");
    }
}


void CNamedSemaphore::unlock(int iValue)
{
    if( ReleaseSemaphore(m_hSemaphore, (LONG)iValue, NULL) == 0 )
    {
        VPL_LOG_WARN("Method CNamedSemaphore::unlock() failed");
    }
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class vpl::sys::CNamedSemaphore.
 * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
// Union semun defined in <sys/sem.h>
#else
union semun
{
    //! Value for SETVAL
    int val;

    //! Buffer for IPC_STAT and IPC_SET
    struct semid_ds *buf;

    //! Array for GETALL and SETALL
    unsigned short int *array;

    //! Buffer for IPC_INFO
    struct seminfo *__buf;
};
#endif


namespace
{

//! Creates a unique system identifier from a given string
unsigned CreateKey(const std::string& sId)
{
    // String conversion/hash function parameters
    static const unsigned uShift = 6;
    static const unsigned uMask = ~0U << (16U - uShift);

    // String to UInt conversion
    unsigned uHash = 0;
    for (int i = 0; i < (int)sId.length(); i++)
    {
        uHash = (uHash & uMask) ^ (uHash << uShift) ^ sId[i];
    }

    // Return the hash
    return (uHash & 0xffff);
}

}


CNamedSemaphore::CNamedSemaphore(int iValue,
                       const std::string *psName,
                       bool *pbAlreadyExists
                       )
    : m_iSemaphore(-1)
    , m_SemaphoreKey(IPC_PRIVATE)
    , m_bDestroy(false)
{
    if( psName )
    {
        // Create a semaphore name
        std::string sName = SEMAPHORE_NAME_PREFIX + *psName;

        // Create the semaphore key
        m_SemaphoreKey = (key_t)CreateKey(sName);
    }

    if( pbAlreadyExists )
    {
        // Create a new unique semaphore
        m_iSemaphore = semget(m_SemaphoreKey, 1, IPC_CREAT | IPC_EXCL | S_IRWXU | S_IRWXG);
        if( m_iSemaphore == -1 )
        {
            if( errno != EEXIST )
            {
                VPL_THROW_ERROR("Constructor CNamedSemaphore::CNamedSemaphore() failed");
            }
        }
        else
        {
            m_bDestroy = true;
            goto lInit;
        }
    }

    // Create/Open the named unix semaphore
    m_iSemaphore = semget(m_SemaphoreKey, 1, IPC_CREAT | S_IRWXU | S_IRWXG);
    if( m_iSemaphore == -1 )
    {
        VPL_THROW_ERROR("Constructor CNamedSemaphore::CNamedSemaphore() failed");
    }

lInit:
    if( pbAlreadyExists )
    {
        *pbAlreadyExists = !m_bDestroy;
    }

    // Initialize the semaphore value
    unlock(iValue);
}


CNamedSemaphore::~CNamedSemaphore()
{
    // Close the semaphore
    if( m_iSemaphore != -1 && m_bDestroy )
    {
        if( semctl(m_iSemaphore, 0, IPC_RMID) == -1 && errno != EINVAL )
        {
            VPL_LOG_WARN("Destructor CNamedSemaphore::~CNamedSemaphore() failed");
        }
    }
}


void CNamedSemaphore::lock()
{
    // Prepare semaphore operation
    struct sembuf LockSem;
    LockSem.sem_num = 0;
    LockSem.sem_op = -1;
    LockSem.sem_flg = SEM_UNDO;

    // Wait for the semaphore
    int iResult = 0;
    do {
        iResult = semop(m_iSemaphore, &LockSem, 1);
    } while( iResult == -1 && errno == EINTR );

    if( iResult == -1 )
    {
        VPL_LOG_WARN("Method CNamedSemaphore::lock() failed");
    }
}


void CNamedSemaphore::unlock(int iValue)
{
    // Prepare semaphore operation
    struct sembuf UnlockSem;
    UnlockSem.sem_num = 0;
    UnlockSem.sem_op = iValue;
    UnlockSem.sem_flg = SEM_UNDO;

    if( semop(m_iSemaphore, &UnlockSem, 1) == -1 )
    {
        VPL_LOG_WARN("Method CNamedSemaphore::lock() failed");
    }
}

#endif // _LINUX || _MACOSX


} // namespace sys
} // namespace base

