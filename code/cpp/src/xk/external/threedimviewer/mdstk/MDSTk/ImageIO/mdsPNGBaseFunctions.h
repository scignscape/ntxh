//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * File:    mdsPNGBaseFunctions.h               \n
 * Section: libImageIO                          \n
 * Date:    2007/06/12                          \n
 *
 * $Id: mdsPNGBaseFunctions.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Reading and writing of PNG images using libpng.
 */

#ifndef MDS_PNGBASEFUNCTIONS_H
#define MDS_PNGBASEFUNCTIONS_H

#include <MDSTk/Base/mdsSetup.h>
#include <MDSTk/Image/mdsImage.h>
#include <MDSTk/Module/mdsChannel.h>

#include "mdsImageIOExport.h"


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Reads grayscale PNG image from a given input channel.
//! - Returns false on failure.
MDS_IMAGEIO_EXPORT bool loadGrayPNG(CImage16& Image, mds::mod::CChannel& Channel);

//! Reads full color PNG image from a given input channel.
//! - Returns false on failure.
MDS_IMAGEIO_EXPORT bool loadColorPNG(CRGBImage& Image, mds::mod::CChannel& Channel);

//! Writes grayscale PNG image to a given output channel.
//! - Returns false on failure.
MDS_IMAGEIO_EXPORT bool saveGrayPNG(const CImage16& Image, mds::mod::CChannel& Channel);

//! Writes full color PNG image to a given output channel.
//! - Returns false on failure.
MDS_IMAGEIO_EXPORT bool saveColorPNG(const CRGBImage& Image, mds::mod::CChannel& Channel);


} // namespace img
} // namespace mds

#endif // MDS_PNGBASEFUNCTIONS_H

