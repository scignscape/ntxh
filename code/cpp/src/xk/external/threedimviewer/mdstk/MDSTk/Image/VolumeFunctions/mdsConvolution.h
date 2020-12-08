//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/21                          \n
 *
 * $Id: mdsConvolution.h 2065 2012-02-02 23:29:38Z spanel $
 *
 * Description:
 * - Convolution functions.
 */

#ifndef MDS_VOLUMEFUNCTIONS_CONVOLUTION_H
#define MDS_VOLUMEFUNCTIONS_CONVOLUTION_H

#include <MDSTk/Base/mdsSetup.h>
#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsVolumeBase.h"
#include "../mdsKernel.h"

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

//! Convolves the volume with a given 3D convolution kernel.
template <typename R, class V>
inline R convolve(const CVolumeBase<V>& Volume,
                  tSize x,
                  tSize y,
                  tSize z,
                  const CKernel3D& Kernel
                  );

//! Convolves the volume with a given 2D convolution kernel.
template <typename R, class V>
inline R convolveXY(const CVolumeBase<V>& Volume,
                    tSize x,
                    tSize y,
                    tSize z,
                    const CKernel2D& Kernel
                    );

//! Convolves the volume with a given 2D convolution kernel.
template <typename R, class V>
inline R convolveXZ(const CVolumeBase<V>& Volume,
                    tSize x,
                    tSize y,
                    tSize z,
                    const CKernel2D& Kernel
                    );

//! Convolves the volume with a given 2D convolution kernel.
template <typename R, class V>
inline R convolveYZ(const CVolumeBase<V>& Volume,
                    tSize x,
                    tSize y,
                    tSize z,
                    const CKernel2D& Kernel
                    );

//! Convolves the volume in the x-dimension with a given 1D kernel.
template <typename R, class V>
inline R convolveX(const CVolumeBase<V>& Volume,
                   tSize x,
                   tSize y,
                   tSize z,
                   const CKernel1D& Kernel
                   );

//! Convolves the volume in the y-dimension with a given 1D kernel.
template <typename R, class V>
inline R convolveY(const CVolumeBase<V>& Volume,
                   tSize x,
                   tSize y,
                   tSize z,
                   const CKernel1D& Kernel
                   );

//! Convolves the volume in the z-dimension with a given 1D kernel.
template <typename R, class V>
inline R convolveZ(const CVolumeBase<V>& Volume,
                   tSize x,
                   tSize y,
                   tSize z,
                   const CKernel1D& Kernel
                   );


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "mdsConvolution.hxx"


} // namespace img
} // namespace mds

#endif // MDS_VOLUMEFUNCTIONS_CONVOLUTION_H

