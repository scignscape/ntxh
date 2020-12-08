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
 * Date:    2003/10/24                       
 *
 * Description:
 * - Shared memory allocation.
 */

#ifndef VPL_SHAREDMEM_H
#define VPL_SHAREDMEM_H

#include <VPL/Base/Setup.h>

// Windows version
#ifdef _WIN32
#  include <windows.h>
#endif

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <unistd.h>
#    include <sys/types.h>
#    include <sys/time.h>
#    include <sys/ipc.h>
#    include <sys/shm.h>
#    include <sys/stat.h>
#    include <errno.h>
#endif

#include <VPL/Base/SharedPtr.h>
#include <VPL/Base/Types.h>

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
 * Class encapsulating access to the shared memory.
 */
class VPL_SYSTEM_EXPORT CSharedMem : public vpl::base::CObject
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CSharedMem);

public:
    //! Constructor.
    //! - If the shared memory already exists, its size can be determined
    //!   automatically and zero can be given in place of the size parameter.
    CSharedMem(const std::string& sName,
               tSize iSize,
               bool bWriteAccess = true,
               bool *pbAlreadyExists = NULL
               );

    //! Destructor.
    virtual ~CSharedMem();

    //! Returns pointer to the shared memory area.
    void *getData() { return m_pData; }

    //! Returns size of the shared memory area.
    tSize getSize() { return m_iSize; }

    //! Returns name of the shared memory.
    std::string& getName() { return m_sName; }

protected:
#ifdef _WIN32
    //! Handle of the shared area.
    HANDLE m_hFileMap;
#endif

#if defined(_LINUX) || defined(_MACOSX)
    //! Unix identifier of the shared area.
    int m_iSharedMemId;

    //! Key of the shared memory.
    key_t m_SharedMemKey;

    //! If set to true, the shared memory won't be deleted by destructor.
    bool m_bDestroy;
#endif

    //! Pointer to the shared area.
    void *m_pData;

    //! Size of the shared area.
    tSize m_iSize;

    //! Name of the shared area.
    std::string m_sName;

private:
    //! Private copy constructor.
    CSharedMem(const CSharedMem&);

    //! Private assignment operator.
    void operator=(const CSharedMem&);
};


//==============================================================================
/*!
 * Smart pointer to the shared memory.
 */
typedef CSharedMem::tSmartPtr   CSharedMemPtr;


} // namespace sys
} // namespace vpl

#endif // VPL_SHAREDMEM_H

