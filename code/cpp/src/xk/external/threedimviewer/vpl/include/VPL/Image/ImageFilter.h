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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/04                          \n
 *
 * Description:
 * - Image filtering functions.
 */

#ifndef VPL_IMAGEFILTER_H
#define VPL_IMAGEFILTER_H

#include "ImageTypes.h"
#include "Image.h"
#include "FilterPolicy.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Base class for all image filters.
 * - Parameter I is an image type.
 */
template <class I>
class CImageFilter
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
    CImageFilter() : m_dDX(1.0), m_dDY(1.0) {}
    
    //! Virtual destructor.
    virtual ~CImageFilter() {}
    
    //! Filtering of input/source image.
    //! - Returns false on failure.
    virtual bool operator()(const tImage& SrcImage, tImage& DstImage) = 0;

    //! Get pixel sizes
    double getDX() const { return m_dDX; }
    double getDY() const { return m_dDY; }

    //! Set pixel sizes
    void setPixel(double dx, double dy)
    { 
        VPL_ASSERT(dx > 0.0 && dy > 0.0);
        m_dDX = dx;
        m_dDY = dy;
    }

protected:
    //! Pixel sizes
    double m_dDX, m_dDY;
};


//==============================================================================
/*!
 * Base class for all image filters that normalize filter response using
 * a predefined policy.
 * - Parameter I is an image type.
 * - Policy NormPolicy is used for filter response normalization.
 */
template <class I, template <typename> class NormPolicy>
class CNormImageFilter : public CImageFilter<I>, public NormPolicy<typename I::tPixel>
{
public:
    //! Base types.
    typedef CImageFilter<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    
    //! Filter response type.
    typedef typename CPixelTraits<tPixel>::tFilterResponse tResult;
    
    //! Filter response normalization function.
    using NormPolicy<typename I::tPixel>::normalize;
    
public:
    //! Default constructor.
    CNormImageFilter() {}
    
    //! Virtual destructor.
    virtual ~CNormImageFilter() {}

    //! Filtering of input/source image.
    //! - Returns false on failure.
    virtual bool operator()(const tImage& SrcImage, tImage& DstImage) = 0;
};


} // namespace img
} // namespace vpl

#endif // VPL_IMAGEFILTER_H

