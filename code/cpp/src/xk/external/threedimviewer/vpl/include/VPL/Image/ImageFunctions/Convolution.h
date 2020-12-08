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
 * Date:    2006/02/20                       
 *
 * Description:
 * - Convolution functions.
 */

#ifndef VPL_IMAGEFUNCTIONS_CONVOLUTION_H
#define VPL_IMAGEFUNCTIONS_CONVOLUTION_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../ImageBase.h"
#include "../Kernel.h"

#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Convolves image with a given 2D convolution kernel.
template <typename R, class I>
inline R convolve(const CImageBase<I>& Image,
                  tSize x,
                  tSize y,
                  const CKernel2D& Kernel
                  );

//! Convolves the image in the x-dimension with a given 1D kernel.
template <typename R, class I>
inline R convolveX(const CImageBase<I>& Image,
                   tSize x,
                   tSize y,
                   const CKernel1D& Kernel
                   );

//! Convolves the image in the y-dimension with a given 1D kernel.
template <typename R, class I>
inline R convolveY(const CImageBase<I>& Image,
                   tSize x,
                   tSize y,
                   const CKernel1D& Kernel
                   );


//! Convolves the image with a given 2D convolution kernel.
//! - Using subpixel representation.
template <typename R, class I>
inline R convolve(const CImageBase<I>& Image,
                  const CPoint3D& Point,
                  const CKernel2D& Kernel
                  );

//! Convolves the image in the x-dimension with a given 1D kernel.
//! - Using subpixel representation.
template <typename R, class I>
inline R convolveX(const CImageBase<I>& Image,
                   const CPoint3D& Point,
                   const CKernel1D& Kernel
                   );

//! Convolves the image in the y-dimension with a given 1D kernel.
//! - Using subpixel representation.
template <typename R, class I>
inline R convolveY(const CImageBase<I>& Image,
                   const CPoint3D& Point,
                   const CKernel1D& Kernel
                   );


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "Convolution.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IMAGEFUNCTIONS_CONVOLUTION_H

