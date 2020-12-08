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
 * Date:    2005/01/26                       
 *
 * Description:
 * - Several volume filtering functions.
 */

#ifndef VPL_VLMFILTER_H
#define VPL_VLMFILTER_H

#include <VPL/Module/Module.h>
#include <VPL/Image/DensityVolume.h>
#include <VPL/Image/VolumeFiltering.h>


//==============================================================================
/*!
 * Module providing several volume filtering functions.
 */
class CVolumeFilter : public vpl::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CVolumeFilter);

public:
    //! Default constructor.
    CVolumeFilter(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CVolumeFilter();

protected:
    //! Virtual method called on startup.
    virtual bool startup();

    //! Virtual method called by the processing thread.
    virtual bool main();

    //! Called on console shutdown.
    virtual void shutdown();

    //! Called on writing a usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream);

protected:
    //! Value of the filter type argument.
    std::string m_ssFilterName;

    //! Filter response normalization function.
    vpl::img::CUserFunc<vpl::img::tDensityPixel>::tNormFunc m_NormFunc;

    //! Type specific arguments.
    int m_iSize;
    double m_dSigma;
    double m_dSigmaS;
    double m_dKappa;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeFilter::tSmartPtr    CVolumeFilterPtr;


#endif // VPL_VLMFILTER_H

