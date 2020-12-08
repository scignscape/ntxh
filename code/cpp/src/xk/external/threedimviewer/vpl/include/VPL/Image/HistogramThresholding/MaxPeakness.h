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
 * Copyright (c) 2003-2008 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/21                       
 *
 * Description:
 * - Simple mode-based histogram thresholding.
 */

#ifndef VPL_MaxPeaknessThresholding_H
#define VPL_MaxPeaknessThresholding_H

#include <VPL/Math/Vector.h>

#include "../HistogramBase.h"

// STL
#include <vector>


namespace vpl
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
#include "MaxPeakness.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_MaxPeaknessThresholding_H

