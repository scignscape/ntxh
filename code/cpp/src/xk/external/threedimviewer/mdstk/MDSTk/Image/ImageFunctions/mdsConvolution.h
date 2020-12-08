//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/20                          \n
 *
 * $Id: mdsConvolution.h 2084 2012-02-13 10:23:58Z spanel $
 *
 * Description:
 * - Convolution functions.
 */

#ifndef MDS_IMAGEFUNCTIONS_CONVOLUTION_H
#define MDS_IMAGEFUNCTIONS_CONVOLUTION_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsImageBase.h"
#include "../mdsKernel.h"

#include <cmath>


namespace mds
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
#include "mdsConvolution.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IMAGEFUNCTIONS_CONVOLUTION_H

