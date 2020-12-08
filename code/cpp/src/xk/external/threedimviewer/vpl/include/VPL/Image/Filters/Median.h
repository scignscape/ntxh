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
 * Date:    2005/09/06                       
 * 
 * Description:
 * - Median image filter.
 */

#ifndef VPL_IF_MEDIAN_H
#define VPL_IF_MEDIAN_H

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
 * Template providing median image filtering functions.
 * - Parameter I is a used image type.
 */
template <class I>
class CMedianFilter : public CImageFilter<I>
{
public:
    //! Image filter base.
    typedef CImageFilter<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

public:
    //! Constructor that creates a new median filter.
    //! - Parameter 'Size' is a window size and it must be an odd number.
    CMedianFilter(tSize Size) 
        : m_MedianSize(Size)
        , m_Data(Size * Size * ompGetMaxThreads())
    {
        VPL_ASSERT((Size % 2) == 1);
    }

    //! Destructor
    ~CMedianFilter() {}


    //! Median image filtering
    //! - Returns false on failure
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tPixel getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns current median size
    tSize getSize() const { return m_MedianSize; }

    //! Sets the windows size
    void resize(tSize Size)
    {
        VPL_ASSERT((Size % 2) == 1);

        m_MedianSize = Size;
        m_Data.create(Size * Size * ompGetMaxThreads());
    }

protected:
    //! Median filter size
    tSize m_MedianSize;

    //! Internal data buffer
    vpl::base::CData<tPixel> m_Data;
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Median.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IF_MEDIAN_H

