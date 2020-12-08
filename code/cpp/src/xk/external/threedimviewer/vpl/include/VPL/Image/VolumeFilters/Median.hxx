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
 * Date:    2005/01/29                       
 * 
 * Description:
 * - Volume median filter definition.
 */

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
    tSize XCount = vpl::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YCount = vpl::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZCount = vpl::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());

    // Initialize the progress observer
    CProgress::setProgressMax(ZCount);

    tSize KernelSize = m_MedianSize * m_MedianSize * m_MedianSize;
    tSize HalfSize = m_MedianSize >> 1;
    const int maxThreads = ompGetMaxThreads();

    for( tSize z = 0; z < ZCount; ++z )
    {
#pragma omp parallel for schedule(static) default(shared) num_threads(maxThreads)
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

