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
 * Author:   Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:     2010/06/25                       
 *
 * File description:
 * - Sample volume segmentation module.
 */

#ifndef VPL_VolumeSegEM_H
#define VPL_VolumeSegEM_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module provides voxel-based segmentation based on GMM+EM algorithm.
 */
class CVolumeSegEM : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CVolumeSegEM);

public:
    //! Default constructor
    CVolumeSegEM(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CVolumeSegEM();

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
    //! Sample command line argument
    int m_iClusters;
    double m_dMinAddChange;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeSegEM::tSmartPtr   CVolumeSegEMPtr;


#endif // VPL_VolumeSegEM_H

