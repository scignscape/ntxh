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
 * Date:    2004/05/08                       
 *
 * Description:
 * - Optical flow estimation and visualization module.
 */

#ifndef VPL_SLICEOPTICALFLOW_H
#define VPL_SLICEOPTICALFLOW_H

// MDSTk
#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Optical flow estimation and visualization module.
 */
class CSliceOpticalFlow : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceOpticalFlow);

public:
    //! Default constructor
    CSliceOpticalFlow(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceOpticalFlow();

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
    //! Command line argument
    int m_iGrid;

    //! Command line argument
    int m_iLevels;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceOpticalFlow::tSmartPtr    CSliceOpticalFlowPtr;


#endif // VPL_SLICEOPTICALFLOW_H

