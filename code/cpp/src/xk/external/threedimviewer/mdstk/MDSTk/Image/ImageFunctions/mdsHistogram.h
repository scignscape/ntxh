//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/04/17                          \n
 *
 * $Id: mdsHistogram.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Image histogram functions.
 */

#ifndef MDS_IMAGEFUNCTIONS_HISTOGRAM_H
#define MDS_IMAGEFUNCTIONS_HISTOGRAM_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsImageBase.h"
#include "../mdsImageHistogram.h"
#include "../mdsImageFunctional.h"
#include "../HistogramThresholding/mdsMaxPeakness.h"
#include "../HistogramThresholding/mdsIterative.h"
#include "../HistogramThresholding/mdsOtsu.h"

// STL
#include <cmath>


namespace mds
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
#include "mdsHistogram.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IMAGEFUNCTIONS_HISTOGRAM_H

