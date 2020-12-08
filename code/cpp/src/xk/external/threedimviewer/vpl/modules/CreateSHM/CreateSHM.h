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
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/07                       
 *
 * File description:
 * - Console utility allocates a new shared memory block.
 * - Only for testing!
 */

#ifndef VPL_CREATESHM_H
#define VPL_CREATESHM_H

#include <VPL/Module/Console.h>
#include <VPL/System/SharedMem.h>
#include <VPL/System/NamedSemaphore.h>


//==============================================================================
/*!
 * This console utility allocates a new named shared memory block
 * of a specified size. The utility must be running in the background
 * in order to use shared memory channel.
 */
class CCreateSHM : public vpl::mod::CConsole
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CCreateSHM);

public:
    //! Default constructor.
    CCreateSHM(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CCreateSHM();

protected:
    //! Virtual method called on startup.
    virtual bool startup();

    //! Virtual method called by the processing thread.
    virtual bool main();

    //! Called on console shutdown.
    virtual void shutdown();

    //! Called on writing a usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream);

protected:
    //! Module parameters.
    std::string m_ssName;
    int m_iSize;

    //! Pointer to the shared memory
    vpl::sys::CNamedSemaphore *m_pSemaphore;

    //! Pointer to the shared memory
    vpl::sys::CSharedMem *m_pSharedMem;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CCreateSHM::tSmartPtr   CCreateSHMPtr;


#endif // VPL_CREATESHM_H

