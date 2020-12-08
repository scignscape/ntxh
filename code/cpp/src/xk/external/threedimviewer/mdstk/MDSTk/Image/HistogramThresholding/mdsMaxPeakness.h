//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/21                          \n
 *
 * $Id: mdsMaxPeakness.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Simple mode-based histogram thresholding.
 */

#ifndef MDS_MaxPeaknessThresholding_H
#define MDS_MaxPeaknessThresholding_H

#include <MDSTk/Math/mdsVector.h>

#include "../mdsHistogramBase.h"

// STL
#include <vector>


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Calculates an "optimal" threshold using the mode-based method
//! which analyzes histogram peaks and valleys.
//! - This method evaluates "peakness" for every possible pair of local
//!   histogram maxima and for all minimum values lying between them.
template <class H>
inline bool findSingleThreshold(const CHistogramBase<H>& Histogram,
                                typename H::tItem& Threshold
                                );


//==============================================================================
/*
 * Method templates.
 */

// Include file containing function implementation
#include "mdsMaxPeakness.hxx"


} // namespace img
} // namespace mds

#endif // MDS_MaxPeaknessThresholding_H

