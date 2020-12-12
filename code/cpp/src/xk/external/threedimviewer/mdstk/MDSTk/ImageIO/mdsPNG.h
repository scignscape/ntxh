//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/12                          \n
 *
 * $Id: mdsPNG.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Reading and writing of PNG images.
 */

#ifndef MDS_IMAGEIO_PNG_H
#define MDS_IMAGEIO_PNG_H

#include <MDSTk/Image/mdsImageBase.h>
#include <MDSTk/Image/mdsImageFunctions.h>

#include "mdsPNGBaseFunctions.h"


namespace mds
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
bool loadPNG(CImageBase<I>& Image, mds::mod::CChannel& Channel);

//! Writes PNG image to a given output channel.
//! - Returns false on failure.
template <class I>
bool savePNG(const CImageBase<I>& Image, mds::mod::CChannel& Channel);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "mdsPNG.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IMAGEIO_PNG_H
