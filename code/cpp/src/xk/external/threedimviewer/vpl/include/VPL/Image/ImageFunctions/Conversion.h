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
 * Date:    2006/08/09                       
 *
 * Description:
 * - Image conversion functions.
 */

#ifndef VPL_IMAGEFUNCTIONS_CONVERSION_H
#define VPL_IMAGEFUNCTIONS_CONVERSION_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../Image.h"

#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Converts source image of one type to destination image of another type.
//! - Changes size of the destination image if required.
//! - Returns false on failure.
template <class I1, class I2>
inline bool convert(const CImageBase<I1>& SrcImage, CImageBase<I2>& DstImage);

//! Logarithmic operator that converts a given image to the logarithmic space.
//! - Conversion is done in-place, the input image is modified.
template <class I>
inline void log(CImageBase<I>& Image);

//! Returns real part of a complex image.
//! - Changes size of the destination image if required.
//! - Returns false on failure.
template <class I>
inline bool real(const CImageBase<CComplexImage>& SrcImage, CImageBase<I>& DstImage);

//! Returns imaginary part of a complex image.
//! - Changes size of the destination image if required.
//! - Returns false on failure.
template <class I>
inline bool imag(const CImageBase<CComplexImage>& SrcImage, CImageBase<I>& DstImage);

//! Returns absolute value (magnitude) of a complex image.
//! - Changes size of the destination image if required.
//! - Returns false on failure.
template <class I>
inline bool abs(const CImageBase<CComplexImage>& SrcImage, CImageBase<I>& DstImage);

//! Returns argument of a complex image.
//! - Changes size of the destination image if required.
//! - Returns false on failure.
template <class I>
inline bool arg(const CImageBase<CComplexImage>& SrcImage, CImageBase<I>& DstImage);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "Conversion.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IMAGEFUNCTIONS_CONVERSION_H

