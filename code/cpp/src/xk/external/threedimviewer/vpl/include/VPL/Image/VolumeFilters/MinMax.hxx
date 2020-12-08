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
 * - Volume min and max filters.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Volume filtering method
template <class V>
bool CVolumeMinFilter<V>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    // Volume size
    tSize XCount = vpl::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YCount = vpl::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZCount = vpl::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());

    // Filter the image
    tSize HalfSize = m_MinSize >> 1;
#pragma omp parallel for schedule(static) default(shared)
    for( tSize z = 0; z < ZCount; ++z )
    {
        for( tSize y = 0; y < YCount; ++y )
        {
            for( tSize x = 0; x < XCount; ++x )
            {
                // Minimum finding
                tVoxel Min = SrcVolume
                    .rect(CPoint3i(x - HalfSize, y - HalfSize, z - HalfSize), CSize3i(m_MinSize))
                    .forEach(vpl::base::CMin<tVoxel>(SrcVolume(x, y, z)))
                    .getValue();

                // Set pixel value
                DstVolume.set(x, y, z, Min);
            }
        }
    }

    // O.K.
    return true;
}


// Volume filter response
template <class V>
typename CVolumeMinFilter<V>::tVoxel CVolumeMinFilter<V>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Minimum finding
    tSize HalfSize = m_MinSize >> 1;
    tVoxel Min = SrcVolume
        .rect(CPoint3i(x - HalfSize, y - HalfSize, z - HalfSize), CSize3i(m_MinSize))
        .forEach(vpl::base::CMin<tVoxel>(SrcVolume(x, y, z)))
        .getValue();

    return Min;
}


// Volume filtering method
template <class V>
bool CVolumeMaxFilter<V>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    // Volume size
    tSize XCount = vpl::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YCount = vpl::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZCount = vpl::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());

    // Filter the image
    tSize HalfSize = m_MaxSize >> 1;
#pragma omp parallel for schedule(static) default(shared)
    for( tSize z = 0; z < ZCount; ++z )
    {
        for( tSize y = 0; y < YCount; ++y )
        {
            for( tSize x = 0; x < XCount; ++x )
            {
                // Maximum finding
                tVoxel Max = SrcVolume
                    .rect(CPoint3i(x - HalfSize, y - HalfSize, z - HalfSize), CSize3i(m_MaxSize))
                    .forEach(vpl::base::CMax<tVoxel>(SrcVolume(x, y, z)))
                    .getValue();

                // Set pixel value
                DstVolume.set(x, y, z, Max);
            }
        }
    }

    // O.K.
    return true;
}


// Volume filter response
template <class V>
typename CVolumeMaxFilter<V>::tVoxel CVolumeMaxFilter<V>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Maximum finding
    tSize HalfSize = m_MaxSize >> 1;
    tVoxel Max = SrcVolume
        .rect(CPoint3i(x - HalfSize, y - HalfSize, z - HalfSize), CSize3i(m_MaxSize))
        .forEach(vpl::base::CMax<tVoxel>(SrcVolume(x, y, z)))
        .getValue();

    return Max;
}

