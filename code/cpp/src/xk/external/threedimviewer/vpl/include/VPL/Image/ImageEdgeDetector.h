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
 * Date:    2005/09/20                       
 *
 * Description:
 * - More sophisticated functions for image edge detection.
 */

#ifndef VPL_IMAGEEDGEDETECTOR_H
#define VPL_IMAGEEDGEDETECTOR_H

#include "ImageTypes.h"
#include "Image.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Base class for all image edge detectors.
 * - Parameter I is an image type.
 */
template <class I>
class CImageEdgeDetector
{
public:
    //! Check that I is an image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Image type.
    typedef typename I::tImage tImage;

    //! Image pixel type.
    typedef typename I::tPixel tPixel;

public:
    //! Default constructor.
    CImageEdgeDetector() {}
    
    //! Virtual destructor.
    virtual ~CImageEdgeDetector() {}

    //! Edge detection in a given image.
    //! - Returns false on failure.
    virtual bool operator()(const tImage& SrcImage, tImage& DstImage) = 0;
};


} // namespace img
} // namespace vpl

#endif // VPL_IMAGEEDGEDETECTOR_H

