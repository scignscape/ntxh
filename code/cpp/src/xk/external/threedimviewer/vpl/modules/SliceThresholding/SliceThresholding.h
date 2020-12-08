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
 * Copyright (c) 2003-2004 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/19                       
 *
 * File description:
 * - Simple pixel value thresholding.
 */

#ifndef VPL_SLICETHRESHOLDING_H
#define VPL_SLICETHRESHOLDING_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module for a simple pixel values thresholding.
 */
class CSliceThresholding : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceThresholding);

public:
    //! Default constructor
    CSliceThresholding(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceThresholding();

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
    //! Value of the method type argument.
    std::string m_ssMethodName;

    //! Module command line arguments values
    int m_iMin, m_iMax, m_iN;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceThresholding::tSmartPtr   CSliceThresholdingPtr;


#endif // VPL_SLICETHRESHOLDING_H

