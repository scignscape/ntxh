//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/01/29                          \n
 *
 * $Id: mdsMedian.hxx 2106 2012-02-18 21:55:47Z spanel $
 * 
 * Description:
 * - Volume median filter definition.
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

// Volume filtering method
template <class V>
bool CVolumeMedianFilter<V>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    CProgress::tProgressInitializer StartProgress(*this);

    // Volume size
    tSize XCount = mds::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YCount = mds::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZCount = mds::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());

    // Initialize the progress observer
    CProgress::setProgressMax(ZCount);

    tSize KernelSize = m_MedianSize * m_MedianSize * m_MedianSize;
    tSize HalfSize = m_MedianSize >> 1;
    for( tSize z = 0; z < ZCount; ++z )
    {
#pragma omp parallel for schedule(static) default(shared)
        for( tSize y = 0; y < YCount; ++y )
        {
            tSize Start = ompGetThreadNum() * KernelSize;
            for( tSize x = 0; x < XCount; ++x )
            {
                // Copy voxels from the window
                SrcVolume.rect(CPoint3i(x - HalfSize, y - HalfSize, z - HalfSize), CSize3i(m_MedianSize)).copyTo(m_Data.getPtr(Start));

                // Median finding
                tVoxel Median = median::findMedian<tVoxel>(m_Data.getPtr(Start), KernelSize);

                // Set pixel value
                DstVolume.set(x, y, z, Median);
            }
        }

        // Notify progress observers...
        if( !CProgress::progress() )
        {
            return false;
        }
    }

    // O.K.
    return true;
}


// Volume filter response
template <class V>
typename CVolumeMedianFilter<V>::tVoxel CVolumeMedianFilter<V>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Copy voxels from the window
    tSize HalfSize = m_MedianSize >> 1;
    SrcVolume.rect(CPoint3i(x - HalfSize, y - HalfSize, z - HalfSize), CSize3i(m_MedianSize)).copyTo(m_Data.getPtr());

    // Median finding
    return median::findMedian<tVoxel>(m_Data.getPtr(), m_MedianSize * m_MedianSize * m_MedianSize);
}

