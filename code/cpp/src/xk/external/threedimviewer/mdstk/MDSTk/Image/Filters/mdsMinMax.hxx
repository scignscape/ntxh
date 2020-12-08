//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/06/14                          \n
 *
 * $Id: mdsMinMax.hxx 2098 2012-02-16 23:50:36Z spanel $
 * 
 * Description:
 * - Square min and max image filters.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Image filtering method
template <class I>
bool CMinFilter<I>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = mds::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = mds::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
    tSize HalfSize = m_MinSize >> 1;
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            // Min finding
            tPixel Min = SrcImage
                .rect(CPoint2i(x - HalfSize, y - HalfSize), CSize2i(m_MinSize))
                .forEach(mds::base::CMin<tPixel>(SrcImage(x,y)))
                .getValue();
            
            // Set pixel value
            DstImage.set(x, y, Min);
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <class I>
typename CMinFilter<I>::tPixel CMinFilter<I>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Min finding
    tSize HalfSize = m_MinSize >> 1;
    tPixel Min = SrcImage
        .rect(CPoint2i(x - HalfSize, y - HalfSize), CSize2i(m_MinSize))
        .forEach(mds::base::CMin<tPixel>(SrcImage(x,y)))
        .getValue();

    return Min;
}


// Image filtering method
template <class I>
bool CMaxFilter<I>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = mds::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = mds::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
    tSize HalfSize = m_MaxSize >> 1;
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            // Max finding
            tPixel Max = SrcImage
                .rect(CPoint2i(x - HalfSize, y - HalfSize), CSize2i(m_MaxSize))
                .forEach(mds::base::CMax<tPixel>(SrcImage(x,y)))
                .getValue();

            // Set pixel value
            DstImage.set(x, y, Max);
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <class I>
typename CMaxFilter<I>::tPixel CMaxFilter<I>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Max finding
    tSize HalfSize = m_MaxSize >> 1;
    tPixel Max = SrcImage
        .rect(CPoint2i(x - HalfSize, y - HalfSize), CSize2i(m_MaxSize))
        .forEach(mds::base::CMax<tPixel>(SrcImage(x,y)))
        .getValue();

    return Max;
}

