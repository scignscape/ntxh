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
 * Date:    2005/09/27                       
 *
 * Description:
 * - Advanced image edge detection algorithms.
 */

#ifndef VPL_SLICEEDGEDETECTOR_H
#define VPL_SLICEEDGEDETECTOR_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module provides image edge detection routines.
 */
class CSliceEdgeDetector : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceEdgeDetector);

public:
    //! Default constructor
    CSliceEdgeDetector(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceEdgeDetector();

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
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceEdgeDetector::tSmartPtr   CSliceEdgeDetectorPtr;


#endif // VPL_SLICEEDGEDETECTOR_H

