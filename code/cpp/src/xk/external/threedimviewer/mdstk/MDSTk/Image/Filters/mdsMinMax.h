//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/06/14                          \n
 *
 * $Id: mdsMinMax.h 2084 2012-02-13 10:23:58Z spanel $
 *
 * Description:
 * - Square min and max image filters.
 */

#ifndef MDS_IF_MINMAX_H
#define MDS_IF_MINMAX_H

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
        MDS_ASSERT((Size % 2) == 1);
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
        MDS_ASSERT((Size % 2) == 1);

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
        MDS_ASSERT((Size % 2) == 1);
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
        MDS_ASSERT((Size % 2) == 1);

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
#include "mdsMinMax.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IF_MINMAX_H

