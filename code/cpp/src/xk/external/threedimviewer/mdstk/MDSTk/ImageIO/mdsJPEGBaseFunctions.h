//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/12                          \n
 *
 * $Id: mdsJPEGBaseFunctions.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Reading and writing of JPEG images using libjpeg.
 */

#ifndef MDS_JPEGBASEFUNCTIONS_H
#define MDS_JPEGBASEFUNCTIONS_H

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

//! Reads grayscale JPEG image from a given input channel.
//! - Returns false on failure.
MDS_IMAGEIO_EXPORT bool loadGrayJPEG(CImage8& Image, mds::mod::CChannel& Channel);

//! Reads full color JPEG image from a given input channel.
//! - Returns false on failure.
MDS_IMAGEIO_EXPORT bool loadColorJPEG(CRGBImage& Image, mds::mod::CChannel& Channel);

//! Writes grayscale JPEG image to a given output channel.
//! - Quality of JPEG image is value in the range <0..255>.
//! - Returns false on failure.
MDS_IMAGEIO_EXPORT bool saveGrayJPEG(const CImage8& Image, mds::mod::CChannel& Channel, int iQuality = 128);

//! Writes full color JPEG image to a given output channel.
//! - Quality of JPEG image is value in the range <0..255>.
//! - Returns false on failure.
MDS_IMAGEIO_EXPORT bool saveColorJPEG(const CRGBImage& Image, mds::mod::CChannel& Channel, int iQuality = 128);


} // namespace img
} // namespace mds

#endif // MDS_JPEGBASEFUNCTIONS_H

