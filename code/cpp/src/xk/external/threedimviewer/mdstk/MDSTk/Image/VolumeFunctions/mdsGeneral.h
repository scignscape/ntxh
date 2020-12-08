//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/21                          \n
 *
 * $Id: mdsGeneral.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - General volume functions.
 */

#ifndef MDS_VOLUMEFUNCTIONS_GENERAL_H
#define MDS_VOLUMEFUNCTIONS_GENERAL_H

#include <MDSTk/Base/mdsSetup.h>
#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsVolumeBase.h"

#include <cmath>


namespace mds
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
#include "mdsGeneral.hxx"


} // namespace img
} // namespace mds

#endif // MDS_VOLUMEFUNCTIONS_GENERAL_H

