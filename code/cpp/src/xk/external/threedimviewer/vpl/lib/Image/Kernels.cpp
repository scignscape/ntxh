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

#include <VPL/Image/Kernels.h>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Several 1D convolution kernels.
 */

// Convolution kernel definition
/*float K1D_DERIVATIVE_DATA[] =
{
    -1.0f/12, 8.0f/12, 0.0f, -8.0f/12, 1.0f/12
};*/

// Convolution kernel definition
float K1D_DERIVATIVE_DATA[] =
{
    -1.0f/9, 8.0f/9, 0.0f, -8.0f/9, 1.0f/9
};

const CKernel1D K1D_DERIVATIVE(K1D_DERIVATIVE_DATA, 5);


//==============================================================================
/*
 * Several 2D convolution kernels.
 */


//==============================================================================
/*
 * Several 3D convolution kernels.
 */


} // namespace img
} // namespace vpl

