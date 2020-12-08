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
 * Date:    2006/04/27                       
 *
 * Description:
 * - Advanced volume edge detection algorithms.
 */

#ifndef VPL_DENSITYVOLUMEEDGEDETECTOR_H
#define VPL_DENSITYVOLUMEEDGEDETECTOR_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module provides 3D edge detection routines.
 */
class CVolumeEdgeDetector : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CVolumeEdgeDetector);

public:
    //! Default constructor
    CVolumeEdgeDetector(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CVolumeEdgeDetector();

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
    //! Value of the edge detector type argument.
    std::string m_ssDetectorName;

    //! Type specific arguments.
    double m_dSigma, m_dT1, m_dT2, m_dT;

    //! Should borders be detected?
    bool m_bDetectBorder;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeEdgeDetector::tSmartPtr  CVolumeEdgeDetectorPtr;


#endif // VPL_DENSITYVOLUMEEDGEDETECTOR_H

