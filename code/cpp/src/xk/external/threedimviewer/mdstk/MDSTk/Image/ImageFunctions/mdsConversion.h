//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/08/09                          \n
 *
 * $Id: mdsConversion.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Image conversion functions.
 */

#ifndef MDS_IMAGEFUNCTIONS_CONVERSION_H
#define MDS_IMAGEFUNCTIONS_CONVERSION_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsImage.h"

#include <cmath>


namespace mds
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
#include "mdsConversion.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IMAGEFUNCTIONS_CONVERSION_H

