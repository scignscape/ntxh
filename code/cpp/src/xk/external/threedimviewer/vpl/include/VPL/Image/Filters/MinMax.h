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
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/06/14                       
 *
 * Description:
 * - Square min and max image filters.
 */

#ifndef VPL_IF_MINMAX_H
#define VPL_IF_MINMAX_H

#include <VPL/Base/Assert.h>
#include <VPL/Base/Types.h>
#include <VPL/Base/Data.h>
#include <VPL/Math/Base.h>

#include "../ImageFilter.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Template providing square min-value image filtering functions.
 * - Parameter I is a used image type.
 */
template <class I>
class CMinFilter : public CImageFilter<I>
{
public:
    //! Image filter base.
    typedef CImageFilter<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

public:
    //! Constructor that creates a new filter.
    //! - Parameter 'Size' is a window size and it must be an odd number.
    CMinFilter(tSize Size) : m_MinSize(Size)
    {
        VPL_ASSERT((Size % 2) == 1);
    }

    //! Destructor
    ~CMinFilter() {}


    //! Min image filtering.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tPixel getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns current filter size.
    tSize getSize() const { return m_MinSize; }

    //! Sets the windows size
    void resize(tSize Size)
    {
        VPL_ASSERT((Size % 2) == 1);

        m_MinSize = Size;
    }

protected:
    //! Min filter size.
    tSize m_MinSize;
};


//==============================================================================
/*!
 * Template providing square max-value image filtering functions.
 * - Parameter I is a used image type.
 */
template <class I>
class CMaxFilter : public CImageFilter<I>
{
public:
    //! Image filter base.
    typedef CImageFilter<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

public:
    //! Constructor that creates a new filter.
    //! - Parameter 'Size' is a window size and it must be an odd number.
    CMaxFilter(tSize Size) : m_MaxSize(Size)
    {
        VPL_ASSERT((Size % 2) == 1);
    }

    //! Destructor
    ~CMaxFilter() {}


    //! Max image filtering.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tPixel getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns current filter size.
    tSize getSize() const { return m_MaxSize; }

    //! Sets the windows size.
    void resize(tSize Size)
    {
        VPL_ASSERT((Size % 2) == 1);

        m_MaxSize = Size;
    }

protected:
    //! Max filter size.
    tSize m_MaxSize;
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "MinMax.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IF_MINMAX_H

