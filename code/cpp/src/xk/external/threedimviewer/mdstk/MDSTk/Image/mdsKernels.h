//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/04/19                          \n
 *
 * $Id: mdsKernels.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Miscellaneous convolution kernels.
 */

#ifndef MDS_KERNELS_H
#define MDS_KERNELS_H

#include "mdsKernel.h"


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Miscellaneous 1D convolution kernels.
 */

//! Convolution kernel that could be used to compute derivatives.
//! - [-1/9, 8/9, 0, -8/9, 1/9] \n
//extern MDS_IMAGE_EXPORT const CKernel1D K1D_DERIVATIVE;

//! Convolution kernel that could be used to compute derivatives
//! - [-1/12, 8/12, 0, -8/12, 1/12] \n
extern MDS_IMAGE_EXPORT const CKernel1D K1D_DERIVATIVE;


//==============================================================================
/*
 * Miscellaneous 2D convolution kernels.
 */


//==============================================================================
/*
 * Miscellaneous 3D convolution kernels.
 */



} // namespace img
} // namespace mds

#endif // MDS_KERNEL_H

