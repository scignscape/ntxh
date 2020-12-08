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
 * Date:    2004/04/19                       
 *
 * Description:
 * - Miscellaneous convolution kernels.
 */

#ifndef VPL_KERNELS_H
#define VPL_KERNELS_H

#include "Kernel.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Miscellaneous 1D convolution kernels.
 */

//! Convolution kernel that could be used to compute derivatives.
//! - [-1/9, 8/9, 0, -8/9, 1/9] \n
//extern VPL_IMAGE_EXPORT const CKernel1D K1D_DERIVATIVE;

//! Convolution kernel that could be used to compute derivatives
//! - [-1/12, 8/12, 0, -8/12, 1/12] \n
extern VPL_IMAGE_EXPORT const CKernel1D K1D_DERIVATIVE;


//==============================================================================
/*
 * Miscellaneous 2D convolution kernels.
 */


//==============================================================================
/*
 * Miscellaneous 3D convolution kernels.
 */



} // namespace img
} // namespace vpl

#endif // VPL_KERNEL_H

