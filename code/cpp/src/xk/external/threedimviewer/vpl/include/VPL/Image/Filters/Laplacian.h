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
 * Date:    2005/09/08                       
 *
 * Description:
 * - Laplacian image filters.
 */

#ifndef VPL_IF_LAPLACIAN_H
#define VPL_IF_LAPLACIAN_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../ImageFilter.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Laplacian image filter (first version).
 * - Parameter I is a used image type.
 * - Functor F is used for filter response normalization.
 * - Kernel definition: \n
 *   1 [ 0  1  0 ] \n
 *   - [ 1 -4  1 ] \n
 *   4 [ 0  1  0 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CLaplaceFilter0 : public CNormImageFilter<I,N>
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
    CLaplaceFilter0() {}

    //! Destructor.
    ~CLaplaceFilter0() {}
    
    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tResult getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }
};


//==============================================================================
/*!
 * Laplacian image filter (second version).
 * - Parameter I is a used image type.
 * - Functor F is used for filter response normalization.
 * - Kernel definition: \n
 *   1 [ 1  1  1 ] \n
 *   - [ 1 -8  1 ] \n
 *   8 [ 1  1  1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CLaplaceFilter1 : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 8;

public:
    //! Default constructor.
    CLaplaceFilter1() {}

    //! Destructor.
    ~CLaplaceFilter1() {}

    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tResult getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }
};


//==============================================================================
/*!
 * Laplacian image filter (third version).
 * - Parameter I is a used image type.
 * - Functor F is used for filter response normalization.
 * - Kernel definition: \n
 *   1 [ -1  2 -1 ] \n
 *   - [  2 -4  2 ] \n
 *   8 [ -1  2 -1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CLaplaceFilter2 : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 8;

public:
    //! Default constructor.
    CLaplaceFilter2() {}

    //! Destructor.
    ~CLaplaceFilter2() {}

    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Filter response normalization functor or function can be specified.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tResult getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }
};


//==============================================================================
/*!
 * Laplacian image filter (4-th version).
 * - Parameter I is a used image type.
 * - Policy N is used for filter response normalization.
 * - Kernel definition: \n
 *      [  0  0 -1  0  0 ] \n
 *    1 [  0 -1 -2 -1  0 ] \n
 *   -- [ -1 -2 16 -2 -1 ] \n
 *   16 [  0 -1 -2 -1  0 ] \n
 *      [  0  0 -1  0  0 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CLaplaceFilter5 : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

public:
    //! Number used to divide filter response
    static const int DENOM = 16;

    //! Filter kernel
    static const CKernel2D::tData KERNEL[];

public:
    //! Default constructor.
    CLaplaceFilter5() {}

    //! Destructor.
    ~CLaplaceFilter5() {}

    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tResult getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    tSize getSize() const { return 5; }
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Laplacian.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IF_LAPLACIAN_H
