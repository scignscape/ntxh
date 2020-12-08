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
 * Date:    2004/07/26                          \n
 *
 * File description:
 * - Module makes volume from several input slices.
 */

#ifndef VPL_MAKEVOLUME_H
#define VPL_MAKEVOLUME_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module creates volume (3D image) from several input slices.
 */
class CMakeVolume : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CMakeVolume);

public:
    //! Default constructor
    CMakeVolume(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CMakeVolume();

protected:
    //! Virtual method called on startup
    virtual bool startup();

    //! Virtual method called by the processing thread
    virtual bool main();

    //! Called on console shutdown
    virtual void shutdown();

    //! Called on writing a usage statement
    virtual void writeExtendedUsage(std::ostream& Stream);

private:
    //! Command line arguments.
    int m_iBorder, m_iBorderValue;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CMakeVolume::tSmartPtr  CMakeVolumePtr;


#endif // VPL_MAKEVOLUME_H

