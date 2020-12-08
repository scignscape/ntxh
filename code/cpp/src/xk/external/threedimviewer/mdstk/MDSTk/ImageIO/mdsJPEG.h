//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/12                          \n
 *
 * $Id: mdsJPEG.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Reading and writing of JPEG images.
 */

#ifndef MDS_IMAGEIO_JPEG_H
#define MDS_IMAGEIO_JPEG_H

#include <MDSTk/Image/mdsImageBase.h>
#include <MDSTk/Image/mdsImageFunctions.h>

#include "mdsJPEGBaseFunctions.h"


namespace mds
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
bool loadJPEG(CImageBase<I>& Image, mds::mod::CChannel& Channel);

//! Writes JPEG image to a given output channel.
//! - Quality of JPEG image is value in the range <0..255>.
//! - Returns false on failure.
template <class I>
bool saveJPEG(const CImageBase<I>& Image, mds::mod::CChannel& Channel, int iQuality = 128);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "mdsJPEG.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IMAGEIO_JPEG_H

