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
 * - Convolution functions.
 */

#ifndef VPL_VOLUMEFUNCTIONS_CONVOLUTION_H
#define VPL_VOLUMEFUNCTIONS_CONVOLUTION_H

#include <VPL/Base/Setup.h>
#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../VolumeBase.h"
#include "../Kernel.h"

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
#include "Convolution.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_VOLUMEFUNCTIONS_CONVOLUTION_H

