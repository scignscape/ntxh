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
 * Date:    2005/09/15                       
 * 
 * Description:
 * - Averaging volume filters.
 */


//==============================================================================
/*
 * Methods templates.
 */

//! Volume filter kernel
template <class V>
const CKernel3D::tData CVolumeAvg3Filter<V>::KERNEL[] =
{
    1.0f,  1.0f,  1.0f,
    1.0f,  2.0f,  1.0f,
    1.0f,  1.0f,  1.0f,

    1.0f,  2.0f,  1.0f,
    2.0f,  4.0f,  2.0f,
    1.0f,  2.0f,  1.0f,

    1.0f,  1.0f,  1.0f,
    1.0f,  2.0f,  1.0f,
    1.0f,  1.0f,  1.0f
};


// Volume filtering method
template <class V>
bool CVolumeAvg3Filter<V>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    // Volume size
    tSize XCount = vpl::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YCount = vpl::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZCount = vpl::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize z = 0; z < ZCount; ++z )
    {
        for( tSize y = 0; y < YCount; ++y )
        {
            for( tSize x = 0; x < XCount; ++x )
            {
                DstVolume.set(x, y, z, getResponse(SrcVolume, x, y, z));
            }
        }
    }

    // O.K.
    return true;
}


// Volume filter response
template <class V>
typename CVolumeAvg3Filter<V>::tVoxel CVolumeAvg3Filter<V>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Output normalization
    static const CKernel3D::tData Denom = 1.0f / DENOM;

    // Filter kernel
    static const CKernel3D Kernel(KERNEL, getSize());

    // Compute filter response
    return tVoxel(Denom * convolve<CKernel3D::tData>(SrcVolume, x, y, z, Kernel));
}

