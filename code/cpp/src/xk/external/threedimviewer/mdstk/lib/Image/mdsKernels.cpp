//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/04/19                          \n
 *
 * $Id: mdsKernels.cpp 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Miscellaneous convolution kernels.
 */

#include <MDSTk/Image/mdsKernels.h>


namespace mds
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
} // namespace mds

