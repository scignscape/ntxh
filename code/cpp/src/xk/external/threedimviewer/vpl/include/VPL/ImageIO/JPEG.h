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
 * Copyright (c) 2003-2007 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/12                       
 *
 * Description:
 * - Reading and writing of JPEG images.
 */

#ifndef VPL_IMAGEIO_JPEG_H
#define VPL_IMAGEIO_JPEG_H

#include <VPL/Image/ImageBase.h>
#include <VPL/Image/ImageFunctions.h>

#include "JPEGBaseFunctions.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Reads JPEG image from a given input channel.
//! - Returns false on failure.
template <class I>
bool loadJPEG(CImageBase<I>& Image, vpl::mod::CChannel& Channel);

//! Writes JPEG image to a given output channel.
//! - Quality of JPEG image is value in the range <0..255>.
//! - Returns false on failure.
template <class I>
bool saveJPEG(const CImageBase<I>& Image, vpl::mod::CChannel& Channel, int iQuality = 128);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "JPEG.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IMAGEIO_JPEG_H

