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
 * Date:    2005/11/02                       
 *
 * Description:
 * - Image segmentation based on EM algorithm.
 */

#ifndef VPL_SLICESEGEM_H
#define VPL_SLICESEGEM_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module provides pixel-based GMM+EM segmentation.
 */
class CSliceSegEM : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceSegEM);

public:
    //! Default constructor
    CSliceSegEM(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceSegEM();

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
    double m_dMinSigma, m_dMinAddChange;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceSegEM::tSmartPtr  CSliceSegEMPtr;


#endif // VPL_SLICESEGEM_H

