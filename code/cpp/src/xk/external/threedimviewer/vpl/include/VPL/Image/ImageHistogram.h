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
 * Date:    2005/02/10                       
 *
 * Description:
 * - Image histogram computation and equalization
 */

#ifndef VPL_IMAGEHISTOGRAM_H
#define VPL_IMAGEHISTOGRAM_H

#include "Histogram.h"
#include "Image.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Basic template instances and type definitions.
 */

//! Histogram of the grayscale image, 8-bits per pixel
typedef CFullHistogram<CImage8>         CImage8Histogram;

//! Histogram of the grayscale image, 16-bits per pixel
typedef CFullHistogram<CImage16>        CImage16Histogram;

//! Histogram of the grayscale image, 32-bits per pixel
typedef CFullHistogram<CImage32>        CImage32Histogram;

//! Histogram of the density image
typedef CFullHistogram<CDImage>         CDImageHistogram;

//! Histogram of the float image
typedef CHistogram<CFImage>             CFImageHistogram;


} // namespace img
} // namespace vpl

#endif // VPL_IMAGEHISTOGRAM_H

