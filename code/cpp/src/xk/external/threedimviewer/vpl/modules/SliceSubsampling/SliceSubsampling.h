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
 * - Image subsampling using Gaussian pyramid.
 */

#ifndef VPL_SLICESUBSAMPLING_H
#define VPL_SLICESUBSAMPLING_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module for an image subsampling.
 */
class CSliceSubsampling : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceSubsampling);

public:
    //! Default constructor
    CSliceSubsampling(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceSubsampling();

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
    //! Module command line arguments values
    unsigned int m_uRate, m_uLevels;
    std::string  m_sAlgorithm;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceSubsampling::tSmartPtr    CSliceSubsamplingPtr;


#endif // VPL_SLICESUBSAMPLING_H

