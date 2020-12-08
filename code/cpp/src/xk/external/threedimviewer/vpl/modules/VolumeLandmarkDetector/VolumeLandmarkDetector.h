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
 * Copyright (c) 2003-2007 by Michal Spanel     
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  
 * Date:    2007/07/03                          
 *
 * Description:
 * - Volume landmark ("3D corner") detection algorithms.
 */

#ifndef VPL_DENSITYVOLUMELANDMARKDETECTOR_H
#define VPL_DENSITYVOLUMELANDMARKDETECTOR_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module provides volume landmark ("3D corner") detection.
 */
class CVolumeLandmarkDetector : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CVolumeLandmarkDetector);

public:
    //! Default constructor
    CVolumeLandmarkDetector(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CVolumeLandmarkDetector();

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
    //! Value of the corner detector type argument.
    std::string m_ssDetectorName;

    //! Type specific arguments.
    int m_iSize;
    double m_dW, m_dEdge, m_dT;
    bool m_bDraw, m_bCornerness;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeLandmarkDetector::tSmartPtr   CVolumeLandmarkDetectorPtr;


#endif // VPL_DENSITYVOLUMELANDMARKDETECTOR_H

