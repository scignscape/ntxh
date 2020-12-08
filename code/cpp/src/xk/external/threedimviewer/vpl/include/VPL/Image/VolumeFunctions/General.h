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
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/21                       
 *
 * Description:
 * - General volume functions.
 */

#ifndef VPL_VOLUMEFUNCTIONS_GENERAL_H
#define VPL_VOLUMEFUNCTIONS_GENERAL_H

#include <VPL/Base/Setup.h>
#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../VolumeBase.h"

#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Inner product of two volumes.
template <typename R, class V1, class V2>
inline R getProduct(const CVolumeBase<V1>& Volume1, const CVolumeBase<V2>& Volume2);

//! Mean square error between voxels of two volumes.
template <typename R, class V1, class V2>
inline R getMeanSquareError(const CVolumeBase<V1>& Volume1, const CVolumeBase<V2>& Volume2);

//! Sum of voxels in the volume.
template <typename R, class V>
inline R getSum(const CVolumeBase<V>& Volume);

//! Sum of squares of voxels in the volume.
template <typename R, class V>
inline R getSumOfSquares(const CVolumeBase<V>& Volume);

//! Mean of voxel value.
template <typename R, class V>
inline R getMean(const CVolumeBase<V>& Volume);

//! Variance of volume voxels.
//! - Standard deviation is square root of the returned variance!
template <typename R, class V>
inline R getVariance(const CVolumeBase<V>& Volume);

//! Minimum voxel value in the volume.
template <typename R, class V>
inline R getMin(const CVolumeBase<V>& Volume);

//! Maximum voxel in the volume.
template <typename R, class V>
inline R getMax(const CVolumeBase<V>& Volume);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "General.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_VOLUMEFUNCTIONS_GENERAL_H

