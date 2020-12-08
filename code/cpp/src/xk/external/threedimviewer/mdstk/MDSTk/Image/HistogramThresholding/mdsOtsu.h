//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/21                          \n
 *
 * $Id: mdsOtsu.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Otsu's histogram thresholding algorithm.
 */

#ifndef MDS_OtsuThresholding_H
#define MDS_OtsuThresholding_H

#include <MDSTk/Math/mdsVector.h>

#include "../mdsHistogramBase.h"


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Finds "optimal" thresholds using the Otsu's algorithm.
template <class H>
inline bool findSingleThresholdOtsu(const CHistogramBase<H>& Histogram,
                                    typename H::tItem& Threshold
                                    );


//==============================================================================
/*
 * Method templates.
 */

// Include file containing function implementation
#include "mdsOtsu.hxx"


} // namespace img
} // namespace mds

#endif // MDS_OtsuThresholding_H

