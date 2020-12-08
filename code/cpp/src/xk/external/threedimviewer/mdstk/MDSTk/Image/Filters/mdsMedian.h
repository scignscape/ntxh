//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/06                          \n
 *
 * $Id: mdsMedian.h 2110 2012-02-19 15:39:45Z spanel $
 * 
 * Description:
 * - Median image filter.
 */

#ifndef MDS_IF_MEDIAN_H
#define MDS_IF_MEDIAN_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Base/mdsData.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsImageFilter.h"


namespace mds
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
        MDS_ASSERT((Size % 2) == 1);
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
        MDS_ASSERT((Size % 2) == 1);

        m_MedianSize = Size;
        m_Data.create(Size * Size * ompGetMaxThreads());
    }

protected:
    //! Median filter size
    tSize m_MedianSize;

    //! Internal data buffer
    mds::base::CData<tPixel> m_Data;
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsMedian.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IF_MEDIAN_H

