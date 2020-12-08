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
 * Date:    2005/09/15                       
 *
 * Description:
 * - Sobel operator.
 */

#ifndef VPL_IF_SOBEL_H
#define VPL_IF_SOBEL_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../ImageFilter.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Sobel operator (horizontal version).
 * - Parameter I is a used image type.
 * - Kernel definition: \n
 *   1 [ -1  0  1 ] \n
 *   - [ -2  0  2 ] \n
 *   4 [ -1  0  1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CSobelX : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 4;

public:
    //! Default constructor.
    CSobelX() {}

    //! Destructor.
    ~CSobelX() {}

    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    inline tResult getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }
};


//==============================================================================
/*!
 * Sobel operator (vertical edges).
 * - Parameter I is a used image type.
 * - Kernel definition: \n
 *   1 [ -1 -2 -1 ] \n
 *   - [  0  0  0 ] \n
 *   4 [  1  2  1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CSobelY : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 4;

public:
    //! Default constructor.
    CSobelY() {}

    //! Destructor.
    ~CSobelY() {}

    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    inline tResult getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Sobel.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IF_SOBEL_H

