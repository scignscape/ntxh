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
 * Copyright (c) 2003-2007 by PGMed@FIT         
 *
 * Author:  Petr Hyna, xhynap00@stud.fit.vutbr.cz  \n
 *          (modified by Michal Spanel)         
 * Date:    2007/04/12                          
 *
 * Description:
 * - Image corner detection algorithms.
 */

#ifndef VPL_SLICECORNERDETECTOR_H
#define VPL_SLICECORNERDETECTOR_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module provides image corner detection.
 */
class CSliceCornerDetector : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceCornerDetector);

public:
    //! Default constructor
    CSliceCornerDetector(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceCornerDetector();

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
    //! Value of the Corner detector type argument.
    std::string m_ssDetectorName;

    //! Type specific arguments.
    double m_dSigma;
    double m_dK, m_dT, m_dW;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceCornerDetector::tSmartPtr   CSliceCornerDetectorPtr;


#endif // VPL_SLICECORNERDETECTOR_H

