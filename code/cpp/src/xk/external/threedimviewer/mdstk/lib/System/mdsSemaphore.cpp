//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/12/18                          \n
 *
 * $Id: mdsSemaphore.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Named semaphore.
 */

#include <MDSTk/System/mdsSemaphore.h>

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
 * Global definitions.
 * - Windows version.
 */

#ifdef _WIN32

//! Default semaphore name prefix.
const std::string SEMAPHORE_NAME_PREFIX = "mds::CSemaphore::";

#endif // _WIN32


//==============================================================================
/*
 * Global definitions.
 * - Linux version.
 */

#ifdef _LINUX

//! Default semaphore name prefix.
const std::string SEMAPHORE_NAME_PREFIX = "/mds::CSemaphore::";

#endif // _LINUX


//==============================================================================
/*
 * Implementation of the class mds::sys::CSemaphore.
 * - Windows version.
 */

#ifdef _WIN32

CSemaphore::CSemaphore(int iValue,
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
            MDS_THROW_ERROR("Constructor CSemaphore::CSemaphore() failed");
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
            MDS_THROW_ERROR("Constructor CSemaphore::CSemaphore() failed");
        }

        if( pbAlreadyExists )
        {
            *pbAlreadyExists = false;
        }
    }
}


CSemaphore::~CSemaphore()
{
    if( m_hSemaphore )
    {
        if( CloseHandle(m_hSemaphore) == 0 )
        {
            MDS_LOG_WARNING("Destructor CSemaphore::~CSemaphore() failed");
        }
    }
}


void CSemaphore::lock()
{
    if( WaitForSingleObject(m_hSemaphore, INFINITE) != WAIT_OBJECT_0 )
    {
        MDS_LOG_WARNING("Method CSemaphore::lock() failed");
    }
}


void CSemaphore::unlock(int iValue)
{
    if( ReleaseSemaphore(m_hSemaphore, (LONG)iValue, NULL) == 0 )
    {
        MDS_LOG_WARNING("Method CSemaphore::unlock() failed");
    }
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class mds::sys::CSemaphore.
 * - Linux version.
 */

#ifdef _LINUX

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


CSemaphore::CSemaphore(int iValue,
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
                MDS_THROW_ERROR("Constructor CSemaphore::CSemaphore() failed");
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
        MDS_THROW_ERROR("Constructor CSemaphore::CSemaphore() failed");
    }

lInit:
    if( pbAlreadyExists )
    {
        *pbAlreadyExists = !m_bDestroy;
    }

    // Initialize the semaphore value
    unlock(iValue);
}


CSemaphore::~CSemaphore()
{
    // Close the semaphore
    if( m_iSemaphore != -1 && m_bDestroy )
    {
        if( semctl(m_iSemaphore, 0, IPC_RMID) == -1 && errno != EINVAL )
        {
            MDS_LOG_WARNING("Destructor CSemaphore::~CSemaphore() failed");
        }
    }
}


void CSemaphore::lock()
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
        MDS_LOG_WARNING("Method CSemaphore::lock() failed");
    }
}


void CSemaphore::unlock(int iValue)
{
    // Prepare semaphore operation
    struct sembuf UnlockSem;
    UnlockSem.sem_num = 0;
    UnlockSem.sem_op = iValue;
    UnlockSem.sem_flg = SEM_UNDO;

    if( semop(m_iSemaphore, &UnlockSem, 1) == -1 )
    {
        MDS_LOG_WARNING("Method CSemaphore::lock() failed");
    }
}

#endif // _LINUX


} // namespace sys
} // namespace base

