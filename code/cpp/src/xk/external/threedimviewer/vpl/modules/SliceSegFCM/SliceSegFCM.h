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
 * Date:    2005/10/14                       
 *
 * Description:
 * - Fuzzy C-means image segmentation.
 */

#ifndef VPL_SLICESEGFCM_H
#define VPL_SLICESEGFCM_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module provides pixel-based fuzzy C-means image segmentation.
 */
class CSliceSegFCM : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceSegFCM);

public:
    //! Default constructor
    CSliceSegFCM(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceSegFCM();

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
    //! Command line arguments
    int m_iClusters;
    double m_dWeight;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceSegFCM::tSmartPtr     CSliceSegFCMPtr;


#endif // VPL_SLICESEGFCM_H

