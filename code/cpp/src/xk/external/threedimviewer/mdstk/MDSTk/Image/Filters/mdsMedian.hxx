//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/06                          \n
 *
 * $Id: mdsMedian.hxx 2106 2012-02-18 21:55:47Z spanel $
 *
 * Description:
 * - Median image filter.
 */


//==============================================================================
/*
 * Global functions.
 */

namespace median
{

//! Median value finding (Z Algorithm)
template <typename T>
T findMedian(T *pData, tSize Size)
{
    // Index of the median value
    const tSize Median = Size >> 1; // Size / 2

    // Z algorithm initialization
    tSize Left = 0;
    tSize Right = Size - 1;

    // Median finding
    while( Left < Right )
    {
        T Value = pData[Median];
        tSize LeftValue = Left;
        tSize RightValue = Right;

        while( RightValue >= Median && Median >= LeftValue )
        {
            while( pData[LeftValue] < Value )
            {
                ++LeftValue;
            }
            while( Value < pData[RightValue] )
            {
                --RightValue;
            }

            T Temp = pData[LeftValue];
            pData[LeftValue] = pData[RightValue];
            pData[RightValue] = Temp;

            ++LeftValue;
            --RightValue;
        }

        if( RightValue < Median )
        {
            Left = LeftValue;
        }
        if( Median < LeftValue )
        {
            Right = RightValue;
        }
    }

    return pData[Median];
}

} // namespace


//==============================================================================
/*
 * Methods templates.
 */

// Image filtering method
template <class I>
bool CMedianFilter<I>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = mds::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = mds::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter kernel size
    tSize KernelSize = m_MedianSize * m_MedianSize;
    tSize HalfSize = m_MedianSize >> 1;

#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        tSize Start = ompGetThreadNum() * KernelSize;
        for( tSize x = 0; x < XCount; ++x )
        {
            // Copy pixels from the window
            SrcImage.rect(CPoint2i(x - HalfSize, y - HalfSize), CSize2i(m_MedianSize)).copyTo(m_Data.getPtr(Start));

            // Median finding
            tPixel Median = median::findMedian<tPixel>(m_Data.getPtr(Start), KernelSize);

            // Set pixel value
            DstImage.set(x, y, Median);
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <class I>
typename CMedianFilter<I>::tPixel CMedianFilter<I>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Copy pixels from the window
    tSize HalfSize = m_MedianSize >> 1;
    SrcImage.rect(CPoint2i(x - HalfSize, y - HalfSize), CSize2i(m_MedianSize)).copyTo(m_Data.getPtr());

    // Compute filter response
    return median::findMedian<tPixel>(m_Data.getPtr(), m_MedianSize * m_MedianSize);
}

