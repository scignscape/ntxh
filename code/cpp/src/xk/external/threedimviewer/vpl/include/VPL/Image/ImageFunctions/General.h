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
 * - General image functions.
 */

#ifndef VPL_IMAGEFUNCTIONS_GENERAL_H
#define VPL_IMAGEFUNCTIONS_GENERAL_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../ImageBase.h"

#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Inner product of two images.
template <typename R, class I1, class I2>
inline R getProduct(const CImageBase<I1>& Image1, const CImageBase<I2>& Image2);

//! Mean square error between pixels of two images.
template <typename R, class I1, class I2>
inline R getMeanSquareError(const CImageBase<I1>& Image1, const CImageBase<I2>& Image2);

//! Sum of pixels in the image.
template <typename R, class I>
inline R getSum(const CImageBase<I>& Image);

//! Sum of squares of pixels in the image.
template <typename R, class I>
inline R getSumOfSquares(const CImageBase<I>& Image);

//! Mean of pixel value.
template <typename R, class I>
inline R getMean(const CImageBase<I>& Image);

//! Variance of image pixels.
//! - Standard deviation is square root of the returned variance!
template <typename R, class I>
inline R getVariance(const CImageBase<I>& Image);

//! Minimum pixel value in the image.
template <typename R, class I>
inline R getMin(const CImageBase<I>& Image);

//! Maximum pixel in the image.
template <typename R, class I>
inline R getMax(const CImageBase<I>& Image);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "General.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IMAGEFUNCTIONS_GENERAL_H

