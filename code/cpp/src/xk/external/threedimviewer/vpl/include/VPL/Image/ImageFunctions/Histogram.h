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
 * Copyright (c) 2003-2007 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/04/17                       
 *
 * Description:
 * - Image histogram functions.
 */

#ifndef VPL_IMAGEFUNCTIONS_HISTOGRAM_H
#define VPL_IMAGEFUNCTIONS_HISTOGRAM_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../ImageBase.h"
#include "../ImageHistogram.h"
#include "../ImageFunctional.h"
#include "../HistogramThresholding/MaxPeakness.h"
#include "../HistogramThresholding/Iterative.h"
#include "../HistogramThresholding/Otsu.h"

// STL
#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Histogram equalization.
template <class I>
inline bool histogramEqualization(CImageBase<I>& Image);

//! Simple mode-based histogram thresholding choosing an optimal threshold
//! with respect to histogram peaks and valleys.
//! - Results in a binary image containing zeros and ones.
template <class I>
inline bool singleThresholding(CImageBase<I>& Image);

//! Iterative histogram thresholding.
//! - Produces a labeled image.
template <class I>
inline bool multiIterativeThresholding(CImageBase<I>& Image, int NumOfThresholds);

//! Otsu's histogram thresholding algorithm.
//! - Produces a binary image.
template <class I>
inline bool singleOtsuThresholding(CImageBase<I>& Image);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "Histogram.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IMAGEFUNCTIONS_HISTOGRAM_H

