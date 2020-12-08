//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/24                          \n
 *
 * $Id: mdsSharedMem.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Shared memory allocation.
 */

#include <MDSTk/System/mdsSharedMem.h>

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

//! Default shared memory name prefix.
const std::string SHAREDMEM_NAME_PREFIX = "mds::CSharedMem::";

#endif // _WIN32


//==============================================================================
/*
 * Global definitions.
 * - Linux version.
 */

#ifdef _LINUX

//! Default shared memory name prefix.
const std::string SHAREDMEM_NAME_PREFIX = "/mds::CSharedMem::";

#endif // _LINUX


//==============================================================================
/*
 * Implementation of the class mds::sys::CSharedMem.
 * - Windows version.
 */

#ifdef _WIN32

CSharedMem::CSharedMem(const std::string& sName,
                       int iSize,
                       bool bWriteAccess,
                       bool* pbAlreadyExists
                       )
    : m_hFileMap(NULL)
    , m_pData(NULL)
    , m_iSize(iSize)
    , m_sName(SHAREDMEM_NAME_PREFIX)
{
    MDS_ASSERT(m_iSize >= 0);

    m_sName += sName;

    // Real size of the shared memory
    // - First 32-bits of the shared memory are used to store its size.
    DWORD dwSize = DWORD(m_iSize) + sizeof(int);

    // Create/open the shared memory
    SetLastError(0);
    m_hFileMap = CreateFileMapping(INVALID_HANDLE_VALUE,
                                   NULL,
                                   bWriteAccess ? PAGE_READWRITE : PAGE_READONLY,
                                   0,
                                   dwSize,
                                   m_sName.c_str()
                                   );

    // Check if the shared memory already exists
    bool bAlreadyExists = (GetLastError() == ERROR_ALREADY_EXISTS);
    if( pbAlreadyExists )
    {
        *pbAlreadyExists = bAlreadyExists;
    }
    if( !m_hFileMap )
    {
        MDS_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
    }

    // Map the shared memory
    m_pData = (void *)MapViewOfFile(m_hFileMap,
                                    bWriteAccess ? FILE_MAP_WRITE : FILE_MAP_READ,
                                    0, 0, 0
                                   );
    if( !m_pData )
    {
        MDS_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
    }

    // Change type of the pointer to the shared memory
    int *piData = (int *)m_pData;

    // Read/write size of the shared memory
    if( bAlreadyExists )
    {
        if( m_iSize == 0 && *piData >= 0 )
        {
            m_iSize = *piData;
        }
    }
    else if ( bWriteAccess )
    {
        *piData = m_iSize;
    }
    else
    {
        MDS_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
    }

    // Increment pointer to the data
    m_pData = (void *)(piData + 1);
}


CSharedMem::~CSharedMem()
{
    if( m_pData )
    {
        if( !UnmapViewOfFile((LPVOID)(((int *)m_pData) - 1)) )
        {
            MDS_LOG_WARNING("Destructor CSharedMem::CSharedMem() failed");
        }
    }

    if( m_hFileMap )
    {
        if( !CloseHandle(m_hFileMap) )
        {
            MDS_LOG_WARNING("Destructor CSharedMem::CSharedMem() failed");
        }
    }
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class mds::sys::CSharedMem.
 * - Linux version.
 */

#ifdef _LINUX

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


CSharedMem::CSharedMem(const std::string& sName,
                       int iSize,
                       bool bWriteAccess,
                       bool* pbAlreadyExists
                       )
    : m_iSharedMemId(-1)
    , m_bDestroy(false)
    , m_pData(NULL)
    , m_iSize(iSize)
    , m_sName(SHAREDMEM_NAME_PREFIX)
{
    MDS_ASSERT(m_iSize >= 0);

    m_sName += sName;

    // Create the shared memory key
    m_SharedMemKey = (key_t)CreateKey(m_sName);

    // Read/Write access?
    int iMemMap = (bWriteAccess) ? 0 : SHM_RDONLY;

    // Create a new shared memory
    m_iSharedMemId = shmget(m_SharedMemKey,
                            size_t(m_iSize),
                            IPC_CREAT | IPC_EXCL | S_IRWXU | S_IRWXG
                            );
    if( m_iSharedMemId == -1 )
    {
        if( errno != EEXIST )
        {
            MDS_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
        }
    }
    else
    {
        m_bDestroy = true;
        goto lMap;
    }

    // Create/Open an existing shared memory
    m_iSharedMemId = shmget(m_SharedMemKey,
                            size_t(m_iSize),
                            IPC_CREAT | S_IRWXU | S_IRWXG
                            );
    if( m_iSharedMemId == -1 )
    {
        MDS_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
    }

lMap:
    if( pbAlreadyExists )
    {
        *pbAlreadyExists = !m_bDestroy;
    }

    // Map the shared memory
    m_pData = shmat(m_iSharedMemId, 0, iMemMap);
    if( m_pData == (void *)-1 )
    {
        MDS_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
    }

    // Get size of the shared memory
    if( m_iSize == 0 )
    {
        struct shmid_ds Stats;
        if( shmctl(m_iSharedMemId, IPC_STAT, &Stats) != 0 )
        {
            MDS_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
        }
        m_iSize = int(Stats.shm_segsz);
    }
}


CSharedMem::~CSharedMem()
{
    // Close the shared memory
    if( m_iSharedMemId != -1 )
    {
        if( shmdt(m_pData) == -1 )
        {
            MDS_LOG_WARNING("Destructor CSharedMem::CSharedMem() failed");
        }
        if( m_bDestroy )
        {
            if( shmctl(m_iSharedMemId, IPC_RMID, 0) == -1 && errno != EINVAL )
            {
                MDS_LOG_WARNING("Destructor CSharedMem::CSharedMem() failed");
            }
        }
    }
}

#endif // _LINUX


} // namespace sys
} // namespace mds

