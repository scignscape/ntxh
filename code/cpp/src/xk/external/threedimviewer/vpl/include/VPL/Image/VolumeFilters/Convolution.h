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
 * Date:    2004/05/04                       
 *
 * Description:
 * - Convolution volume filter.
 */

#ifndef VPL_VF_CONVOLUTION_H
#define VPL_VF_CONVOLUTION_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../VolumeFilter.h"
#include "../VolumeFunctions.h"
#include "../Kernel.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * General convolution volume filter.
 * - Parameter V is a used volume type.
 */
template <class V, template <typename> class N = CDefaultFilterPolicy>
class CVolumeConvolutionFilter
    : public CNormVolumeFilter<V,N>
    , public CKernel3D
{
public:
    //! Volume filter base.
    typedef CNormVolumeFilter<V,N> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tResult tResult;

public:
    //! Constructor that creates a new 2D convolution kernel
    //! - Parameter 'Size' must be an odd number
    CVolumeConvolutionFilter(tSize Size) : CKernel3D(Size) {}

    //! Constructor
    CVolumeConvolutionFilter(const tConstDataPtr pData, tSize Size)
        : CKernel3D(pData, Size)
    {}

    //! Constructor
    //! - Filter is based on a given convolution kernel
    CVolumeConvolutionFilter(const CKernel3D& k) : CKernel3D(k) {}

    //! Destructor
    ~CVolumeConvolutionFilter() {}


    //! Filtering of input/source volume. Point filter responses are written
    //! to the destination volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    tResult getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
    {
        // Compute filter response
        return convolve<tResult>(SrcVolume, x, y, z, *this);
    }
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates.
#include "Convolution.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_VOLUMEFILTER_H

