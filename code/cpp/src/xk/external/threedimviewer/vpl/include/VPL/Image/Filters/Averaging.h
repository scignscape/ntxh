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
 * - Averaging image filters.
 */

#ifndef VPL_IF_AVERAGING_H
#define VPL_IF_AVERAGING_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../ImageFilter.h"
#include "../ImageFunctions.h"
#include "../Kernel.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Averaging image filter (3x3 version).
 * - Parameter I is a used image type.
 * - Policy N is used for filter response normalization.
 * - Kernel definition: \n
 *    1 [ 1  2  1 ] \n
 *   -- [ 2  4  2 ] \n
 *   16 [ 1  2  1 ] \n
 */
template <class I>
class CAvg3Filter : public CImageFilter<I>
{
public:
    //! Image filter base.
    typedef CImageFilter<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    
public:
    //! Number used to divide filter response.
    static const int DENOM = 16;

    //! Filter kernel.
    static const CKernel2D::tData KERNEL[];

public:
    //! Default constructor.
    CAvg3Filter() {}

    //! Destructor.
    ~CAvg3Filter() {}

    //! Filtering of input/source image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tPixel getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }
};


//==============================================================================
/*!
 * Averaging image filter (5x5 version).
 * - Parameter I is a used image type.
 * - Policy N is used for filter response normalization.
 * - Kernel definition: \n
 *      [ 1  2  3  2  1 ] \n
 *    1 [ 2  4  6  4  2 ] \n
 *   -- [ 3  6  9  6  3 ] \n
 *   81 [ 2  4  6  4  2 ] \n
 *      [ 1  2  3  2  1 ] \n
 */
template <class I>
class CAvg5Filter : public CImageFilter<I>
{
public:
    //! Image filter base.
    typedef CImageFilter<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

public:
    //! Number used to divide filter response
    static const int DENOM = 81;

    //! Filter kernel
    static const CKernel2D::tData KERNEL[];

public:
    //! Default constructor.
    CAvg5Filter() {}

    //! Destructor.
    ~CAvg5Filter() {}

    //! Filtering of input/source image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tPixel getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    tSize getSize() const { return 5; }
};


//==============================================================================
/*!
 * Averaging image filter (7x7 version).
 * - Parameter I is a used image type.
 * - Policy N is used for filter response normalization.
 * - Kernel definition: \n
 *      [ 1  2  3  4  3  2  1 ] \n
 *      [ 2  4  6  8  6  4  2 ] \n
 *   1  [ 3  6  9 12  9  6  3 ] \n
 *  --- [ 4  8 12 16 12  8  4 ] \n
 *  256 [ 3  6  9 12  9  6  3 ] \n
 *      [ 2  4  6  8  6  4  2 ] \n
 *      [ 1  2  3  4  3  2  1 ] \n
 */
template <class I>
class CAvg7Filter : public CImageFilter<I>
{
public:
    //! Image filter base.
    typedef CImageFilter<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

public:
    //! Number used to divide filter response
    static const int DENOM = 256;

    //! Filter kernel
    static const CKernel2D::tData KERNEL[];

public:
    //! Default constructor.
    CAvg7Filter() {}

    //! Destructor.
    ~CAvg7Filter() {}

    //! Filtering of input/source image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tPixel getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    tSize getSize() const { return 7; }
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Averaging.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IF_AVERAGING_H

