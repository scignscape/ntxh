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
 * Date:    2004/05/03                       
 *
 * Description:
 * - Several image filtering functions.
 */

#ifndef VPL_SLICEFILTER_H
#define VPL_SLICEFILTER_H

#include <VPL/Module/Module.h>
#include <VPL/Image/Slice.h>
#include <VPL/Image/ImageFiltering.h>


//==============================================================================
/*!
 * Module provides several image filtering functions.
 */
class CSliceFilter : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceFilter);

public:
    //! Default constructor
    CSliceFilter(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceFilter();

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
    //! Value of the filter type argument.
    std::string m_ssFilterName;

    //! Filter response normalization function.
    vpl::img::CUserFunc<vpl::img::tDensityPixel>::tNormFunc m_NormFunc;

    //! Type specific arguments.
    double m_dSigma, m_dSigma2, m_dSigmaDensity;
    int m_iSize;
    double m_dKappa;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceFilter::tSmartPtr     CSliceFilterPtr;


#endif // VPL_SLICEFILTER_H

