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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/03/01                       
 *
 * File description:
 * - Sample implementation of an image segmentation method.
 */

#ifndef VPL_SEGMETHOD_H
#define VPL_SEGMETHOD_H

#include <VPL/Base/Setup.h>
#include <VPL/Image/Image.h>


namespace vpl
{
namespace imseg
{

//==============================================================================
/*!
 * Class template providing image segmentation functions.
 * - Sample code!
 * - Rename the class according to name of your segmentation method.
 */
class CSegMethod
{
public:
    //! Image type.
    typedef vpl::img::CDImage tImage;

    //! Image pixel type.
    typedef vpl::img::CDImage::tPixel tPixel;

public:
    //! Constructor.
    CSegMethod() {}

    //! Virtual destructor.
    virtual ~CSegMethod() {}

    //! Initialization of the segmentation method.
    //! - Returns false on failure.
    bool init();

    //! Segmentation of a given image.
    //! - Pixel values of the output/destination image represent segment indexes.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);
};


} // namespace vpl
} // namespace imseg

#endif // VPL_SEGMETHOD_H

