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
 * Copyright (C) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/19                       
 *
 * File description:
 * - Simple voxel value thresholding.
 */

#ifndef VPL_VOLUMETHRESHOLDING_H
#define VPL_VOLUMETHRESHOLDING_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module providing a simple voxel value thresholding.
 */
class CVolumeThresholding : public vpl::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CVolumeThresholding);

public:
    //! Default constructor.
    CVolumeThresholding(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CVolumeThresholding();

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
    //! Value of the method type argument.
    std::string m_ssMethodName;

    //! Module command line arguments values
    int m_iMin, m_iMax, m_iN;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeThresholding::tSmartPtr  CVolumeThresholdingPtr;


#endif // VPL_VOLUMETHRESHOLDING_H

