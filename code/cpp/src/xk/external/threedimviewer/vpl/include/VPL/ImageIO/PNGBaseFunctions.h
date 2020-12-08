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
 * File:    mdsPNGBaseFunctions.h               \n
 * Section: libImageIO                          \n
 * Date:    2007/06/12                          \n
 *
 * Description:
 * - Reading and writing of PNG images using libpng.
 */

#ifndef VPL_PNGBASEFUNCTIONS_H
#define VPL_PNGBASEFUNCTIONS_H

#include <VPL/Base/Setup.h>
#include <VPL/Image/Image.h>
#include <VPL/Module/Channel.h>

#include "ImageIOExport.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Reads grayscale PNG image from a given input channel.
//! - Returns false on failure.
VPL_IMAGEIO_EXPORT bool loadGrayPNG(CImage16& Image, vpl::mod::CChannel& Channel);

//! Reads full color PNG image from a given input channel.
//! - Returns false on failure.
VPL_IMAGEIO_EXPORT bool loadColorPNG(CRGBImage& Image, vpl::mod::CChannel& Channel);

//! Writes grayscale PNG image to a given output channel.
//! - Returns false on failure.
VPL_IMAGEIO_EXPORT bool saveGrayPNG(const CImage16& Image, vpl::mod::CChannel& Channel);

//! Writes full color PNG image to a given output channel.
//! - Returns false on failure.
VPL_IMAGEIO_EXPORT bool saveColorPNG(const CRGBImage& Image, vpl::mod::CChannel& Channel);


} // namespace img
} // namespace vpl

#endif // VPL_PNGBASEFUNCTIONS_H

