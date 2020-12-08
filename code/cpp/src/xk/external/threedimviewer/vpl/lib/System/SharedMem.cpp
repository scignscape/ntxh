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
 * - Shared memory allocation.
 */

#include <VPL/System/SharedMem.h>

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

//! Default shared memory name prefix.
const std::string SHAREDMEM_NAME_PREFIX = "::CSharedMem::";

#endif


//==============================================================================
/*
 * Global definitions.
 * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

//! Default shared memory name prefix.
const std::string SHAREDMEM_NAME_PREFIX = "/::CSharedMem::";

#endif


//==============================================================================
/*
 * Implementation of the class vpl::sys::CSharedMem.
 * - Windows version.
 */

#ifdef _WIN32

CSharedMem::CSharedMem(const std::string& sName,
                       tSize iSize,
                       bool bWriteAccess,
                       bool* pbAlreadyExists
                       )
    : m_hFileMap(NULL)
    , m_pData(NULL)
    , m_iSize(iSize)
    , m_sName(SHAREDMEM_NAME_PREFIX)
{
    VPL_ASSERT(m_iSize >= 0);

    m_sName += sName;

    // Real size of the shared memory
    // - First 32-bits of the shared memory are used to store its size.
	DWORD dwSize = DWORD(m_iSize) + sizeof(DWORD);

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
        VPL_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
    }

    // Map the shared memory
    m_pData = (void *)MapViewOfFile(m_hFileMap,
                                    bWriteAccess ? FILE_MAP_WRITE : FILE_MAP_READ,
                                    0, 0, 0
                                    );
    if( !m_pData )
    {
        VPL_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
    }

    // Change type of the pointer to the shared memory
    DWORD *pdwData = (DWORD *)m_pData;

    // Read/write size of the shared memory
    if( bAlreadyExists )
    {
        if( m_iSize == 0 && *pdwData >= 0 )
        {
            m_iSize = tSize(*pdwData);
        }
    }
    else if ( bWriteAccess )
    {
        *pdwData = DWORD(m_iSize);
    }
    else
    {
        VPL_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
    }

    // Increment pointer to the data
    m_pData = (void *)(pdwData + 1);
}


CSharedMem::~CSharedMem()
{
    if( m_pData )
    {
        if( !UnmapViewOfFile((LPVOID)(((int *)m_pData) - 1)) )
        {
            VPL_LOG_WARN("Destructor CSharedMem::CSharedMem() failed");
        }
    }

    if( m_hFileMap )
    {
        if( !CloseHandle(m_hFileMap) )
        {
            VPL_LOG_WARN("Destructor CSharedMem::CSharedMem() failed");
        }
    }
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class vpl::sys::CSharedMem.
 * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

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
                       tSize iSize,
                       bool bWriteAccess,
                       bool* pbAlreadyExists
                       )
    : m_iSharedMemId(-1)
    , m_bDestroy(false)
    , m_pData(NULL)
    , m_iSize(iSize)
    , m_sName(SHAREDMEM_NAME_PREFIX)
{
    VPL_ASSERT(m_iSize >= 0);

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
            VPL_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
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
        VPL_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
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
        VPL_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
    }

    // Get size of the shared memory
    if( m_iSize == 0 )
    {
        struct shmid_ds Stats;
        if( shmctl(m_iSharedMemId, IPC_STAT, &Stats) != 0 )
        {
            VPL_THROW_ERROR("Constructor CSharedMem::CSharedMem() failed");
        }
        m_iSize = tSize(Stats.shm_segsz);
    }
}


CSharedMem::~CSharedMem()
{
    // Close the shared memory
    if( m_iSharedMemId != -1 )
    {
        if( shmdt(m_pData) == -1 )
        {
            VPL_LOG_WARN("Destructor CSharedMem::CSharedMem() failed");
        }
        if( m_bDestroy )
        {
            if( shmctl(m_iSharedMemId, IPC_RMID, 0) == -1 && errno != EINVAL )
            {
                VPL_LOG_WARN("Destructor CSharedMem::CSharedMem() failed");
            }
        }
    }
}

#endif // _LINUX || _MACOSX


} // namespace sys
} // namespace vpl

