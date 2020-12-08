//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/20                          \n
 *
 * $Id: mdsGeneral.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - General image functions.
 */

#ifndef MDS_IMAGEFUNCTIONS_GENERAL_H
#define MDS_IMAGEFUNCTIONS_GENERAL_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsImageBase.h"

#include <cmath>


namespace mds
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
#include "mdsGeneral.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IMAGEFUNCTIONS_GENERAL_H

