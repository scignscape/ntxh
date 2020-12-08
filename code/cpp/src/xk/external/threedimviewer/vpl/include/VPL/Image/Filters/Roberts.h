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
 * - Roberts cross operator.
 */

#ifndef VPL_IF_ROBERTS_H
#define VPL_IF_ROBERTS_H

#include <VPL/Base/Setup.h>
#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../ImageFilter.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Roberts cross operator (first version).
 * - Parameter I is a used image type.
 * - Policy N is used for filter response normalization.
 * - Kernel definition: \n
 *   [ 1  0 ] \n
 *   [ 0 -1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CRobertsX : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 1;

public:
    //! Default constructor.
    CRobertsX() {}

    //! Destructor.
    ~CRobertsX() {}

    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tResult getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    tSize getSize() const { return 2; }
};


//==============================================================================
/*!
 * Roberts operator (second version).
 * - Parameter I is a used image type.
 * - Policy N is used for filter response normalization.
 * - Kernel definition: \n
 *   [  0  1 ] \n
 *   [ -1  0 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CRobertsY : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 1;

public:
    //! Default constructor.
    CRobertsY() {}

    //! Destructor.
    ~CRobertsY() {}

    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tResult getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    tSize getSize() const { return 2; }
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Roberts.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IF_ROBERTS_H

