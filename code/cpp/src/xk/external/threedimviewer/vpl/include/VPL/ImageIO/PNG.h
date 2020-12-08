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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/12                          \n
 *
 * Description:
 * - Reading and writing of PNG images.
 */

#ifndef VPL_IMAGEIO_PNG_H
#define VPL_IMAGEIO_PNG_H

#include <VPL/Image/ImageBase.h>
#include <VPL/Image/ImageFunctions.h>

#include "PNGBaseFunctions.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Reads PNG image from a given input channel.
//! - Returns false on failure.
template <class I>
bool loadPNG(CImageBase<I>& Image, vpl::mod::CChannel& Channel);

//! Writes PNG image to a given output channel.
//! - Returns false on failure.
template <class I>
bool savePNG(const CImageBase<I>& Image, vpl::mod::CChannel& Channel);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "PNG.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IMAGEIO_PNG_H

