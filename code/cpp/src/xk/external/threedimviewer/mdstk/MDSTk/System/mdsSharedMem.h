//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/24                          \n
 *
 * $Id: mdsSharedMem.h 1864 2010-09-01 09:07:40Z spanel $
 *
 * Description:
 * - Shared memory allocation.
 */

#ifndef MDS_SHAREDMEM_H
#define MDS_SHAREDMEM_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#  include <windows.h>
#endif // _WIN32

// Linux version
#ifdef _LINUX
#    include <unistd.h>
#    include <sys/types.h>
#    include <sys/time.h>
#    include <sys/ipc.h>
#    include <sys/shm.h>
#    include <sys/stat.h>
#    include <errno.h>
#endif // _LINUX

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
 * Class encapsulating access to the shared memory.
 */
class MDS_SYSTEM_EXPORT CSharedMem : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CSharedMem);

public:
    //! Constructor.
    //! - If the shared memory already exists, its size can be determined
    //!   automatically and zero can be given in place of the size parameter.
    CSharedMem(const std::string& sName,
               int iSize,
               bool bWriteAccess = true,
               bool *pbAlreadyExists = NULL
               );

    //! Destructor.
    virtual ~CSharedMem();

    //! Returns pointer to the shared memory area.
    void *getData() { return m_pData; }

    //! Returns size of the shared memory area.
    int getSize() { return m_iSize; }

    //! Returns name of the shared memory.
    std::string& getName() { return m_sName; }

protected:
#ifdef _WIN32
    //! Handle of the shared area.
    HANDLE m_hFileMap;
#endif // _WIN32

#ifdef _LINUX
    //! Unix identifier of the shared area.
    int m_iSharedMemId;

    //! Key of the shared memory.
    key_t m_SharedMemKey;

    //! If set to true, the shared memory won't be deleted by destructor.
    bool m_bDestroy;
#endif // _LINUX

    //! Pointer to the shared area.
    void *m_pData;

    //! Size of the shared area.
    int m_iSize;

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
} // namespace mds

#endif // MDS_SHAREDMEM_H

