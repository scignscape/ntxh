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
 * Copyright (c) 2003-2007 by PGMed@FIT         
 *
 * Authors: Petr Hyna, xhynap00@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz  
 * Date:    2007/04/12                          
 * 
 * Description:
 * - More sophisticated functions for image corner detection.
 */

#ifndef VPL_IMAGECORNERDETECTOR_H
#define VPL_IMAGECORNERDETECTOR_H

#include "ImageTypes.h"
#include "Image.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Base class for all image corner detectors.
 * - Parameter I is an image type.
 */
template <class I>
class CImageCornerDetector
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
    CImageCornerDetector() {}
    
    //! Virtual destructor.
    virtual ~CImageCornerDetector() {}

    //! Corner detection in a given image.
    //! - Returns false on failure.
    virtual bool operator()(const tImage& SrcImage, tImage& DstImage) = 0;
};


} // namespace img
} // namespace vpl

#endif // VPL_IMAGECORNERDETECTOR_H 

