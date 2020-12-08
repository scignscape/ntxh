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
 * - Reading and writing of JPEG images using libjpeg.
 */

#ifndef VPL_JPEGBASEFUNCTIONS_H
#define VPL_JPEGBASEFUNCTIONS_H

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

//! Reads grayscale JPEG image from a given input channel.
//! - Returns false on failure.
VPL_IMAGEIO_EXPORT bool loadGrayJPEG(CImage8& Image, vpl::mod::CChannel& Channel);

//! Reads full color JPEG image from a given input channel.
//! - Returns false on failure.
VPL_IMAGEIO_EXPORT bool loadColorJPEG(CRGBImage& Image, vpl::mod::CChannel& Channel);

//! Writes grayscale JPEG image to a given output channel.
//! - Quality of JPEG image is value in the range <0..255>.
//! - Returns false on failure.
VPL_IMAGEIO_EXPORT bool saveGrayJPEG(const CImage8& Image, vpl::mod::CChannel& Channel, int iQuality = 128);

//! Writes full color JPEG image to a given output channel.
//! - Quality of JPEG image is value in the range <0..255>.
//! - Returns false on failure.
VPL_IMAGEIO_EXPORT bool saveColorJPEG(const CRGBImage& Image, vpl::mod::CChannel& Channel, int iQuality = 128);


} // namespace img
} // namespace vpl

#endif // VPL_JPEGBASEFUNCTIONS_H

