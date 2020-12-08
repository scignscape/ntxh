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
 * - Iterative histogram thresholding.
 */

#ifndef VPL_IterativeThresholding_H
#define VPL_IterativeThresholding_H

#include <VPL/Math/Vector.h>

#include "../HistogramBase.h"
#include "../ImageFunctional.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Finds "optimal" thresholds using the iterative method.
template <class H>
inline bool findThresholdsIterative(const CHistogramBase<H>& Histogram,
                                    int NumOfThresholds,
                                    CMultiThresholding<typename H::tItem>& Thresholds
                                    );


//==============================================================================
/*
 * Method templates.
 */

// Include file containing function implementation
#include "Iterative.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IterativeThresholding_H

