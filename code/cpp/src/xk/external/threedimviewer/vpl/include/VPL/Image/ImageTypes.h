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
 * Date:    2006/02/24                       
 * 
 * Description:
 * - Basic types used by the image library.
 */

#ifndef VPL_IMAGETYPES_H
#define VPL_IMAGETYPES_H

#include <VPL/Base/Setup.h>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Additional types definitions.
 */

//! Coordinate of a point in 2D (image) and 3D (volume) space.
typedef double  tCoordinate;

//! Type of convolution kernel data element.
typedef float   tConvKernelData;


} // namespace img
} // namespace vpl

#endif // VPL_IMAGETYPES_H

