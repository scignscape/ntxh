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
 * Copyright (c) 2003-2010 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/11/01                       
 *
 * File description:
 * - Loads all DICOM images from a given directory.
 */

#ifndef VPL_LoadDicomDir_H
#define VPL_LoadDicomDir_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module loads DICOM images from a specified directory and converts them
 * to MDSTk slices.
 */
class CLoadDicomDir : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CLoadDicomDir);

public:
    //! Default constructor
    CLoadDicomDir(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CLoadDicomDir();

protected:
    //! Virtual method called on startup
    virtual bool startup();

    //! Virtual method called by the processing thread
    virtual bool main();

    //! Called on console shutdown
    virtual void shutdown();

    //! Called on writing a usage statement
    virtual void writeExtendedUsage(std::ostream& Stream);

protected:
    //! Arguments...
    std::string m_ssDir, m_ssFileMask;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CLoadDicomDir::tSmartPtr   CLoadDicomDirPtr;


#endif // VPL_LoadDicomDir_H

