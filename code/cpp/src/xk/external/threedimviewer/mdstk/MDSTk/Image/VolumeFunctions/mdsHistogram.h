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
 * - Volume histogram functions.
 */

#ifndef MDS_VOLUMEFUNCTIONS_HISTOGRAM_H
#define MDS_VOLUMEFUNCTIONS_HISTOGRAM_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsVolumeBase.h"
#include "../mdsVolumeHistogram.h"
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
template <class V>
inline bool histogramEqualization(CVolumeBase<V>& Volume);

//! Simple mode-based histogram thresholding choosing an optimal threshold
//! with respect to histogram peaks and valleys.
//! - Results in binary volume data containing zeros and ones.
template <class V>
inline bool singleThresholding(CVolumeBase<V>& Volume);

//! Iterative histogram thresholding.
//! - Produces labeled volume data.
template <class V>
inline bool multiIterativeThresholding(CVolumeBase<V>& Volume, int NumOfThresholds);

//! Otsu's histogram thresholding algorithm.
//! - Produces binary volume data.
template <class V>
inline bool singleOtsuThresholding(CVolumeBase<V>& Volume);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "mdsHistogram.hxx"


} // namespace img
} // namespace mds

#endif // MDS_VOLUMEFUNCTIONS_HISTOGRAM_H

