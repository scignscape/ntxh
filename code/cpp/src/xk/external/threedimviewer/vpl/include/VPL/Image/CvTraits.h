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
 * Copyright (c) 2010 by Michal Spanel       
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/18                       
 *
 * Description:
 * - OpenCV specific image pixel traits.
 */

#ifndef VPL_CvTraits_H
#define VPL_CvTraits_H

#include <VPL/Base/Setup.h>

#ifdef VPL_OPENCV_ENABLED

// MDSTk pixel types
#include "PixelTypes.h"

// OpenCV
#include <opencv2/core/types_c.h>
//#include <cxcore.h>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * OpenCV specific image pixel traits.
 */
template <typename T>
class CvTraits
{
public:
    //! Returns depth for a corresponding OpenCV image.
    inline static int getDepth();

    //! Returns number of channels for a corresponding OpenCV image.
    inline static int getChannels();

    //! Returns pixel size in bytes.
    static int getPixelSize()
    {
        return ((getDepth() & 255) >> 3) * getChannels();
    }

    //! Returns offset (in pixels) betwen two neighbouring
    //! pixels in image column.
    inline static int convWidthStep(int Bytes);
};


//==============================================================================
/*
 * Include type traits for the predefined pixel types.
 */
#include "CvTraits.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_OPENCV_ENABLED
#endif // VPL_CvTraits_H
