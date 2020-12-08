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
 * Copyright (c) 2003-2007 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/08/10                       
 * 
 * Description:
 * - Miscellaneous filters and operators.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Volume filtering method
template <class V, template <typename> class N>
bool CVolumeDiffXFilter<V,N>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
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
                tResult Value = getResponse(SrcVolume, x, y, z);
                DstVolume.set(x, y, z, base::normalize(Value));
            }
        }
    }

    // O.K.
    return true;
}


// Volume filter response
template <class V, template <typename> class N>
inline typename CVolumeDiffXFilter<V,N>::tResult CVolumeDiffXFilter<V,N>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        4 * tResult(SrcVolume(x + 1, y, z))
                        + 2 * tResult(SrcVolume(x + 2, y, z))
                        + tResult(SrcVolume(x + 3, y, z))
                        - 4 * tResult(SrcVolume(x - 1, y, z))
                        - 2 * tResult(SrcVolume(x - 2, y, z))
                        - tResult(SrcVolume(x - 3, y, z))
                        );
    return Value;
}


// Volume filtering method
template <class V, template <typename> class N>
bool CVolumeDiffYFilter<V,N>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    // Volume size
    tSize XCount = vpl::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YCount = vpl::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZCount = vpl::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());

    // Filter the volume
#pragma omp parallel for schedule(static) default(shared)
    for( tSize z = 0; z < ZCount; ++z )
    {
        for( tSize y = 0; y < YCount; ++y )
        {
            for( tSize x = 0; x < XCount; ++x )
            {
                tResult Value = getResponse(SrcVolume, x, y, z);
                DstVolume.set(x, y, z, base::normalize(Value));
            }
        }
    }

    // O.K.
    return true;
}


// Volume filter response
template <class V, template <typename> class N>
inline typename CVolumeDiffYFilter<V,N>::tResult CVolumeDiffYFilter<V,N>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        4 * tResult(SrcVolume(x, y + 1, z))
                        + 2 * tResult(SrcVolume(x, y + 2, z))
                        + tResult(SrcVolume(x, y + 3, z))
                        - 4 * tResult(SrcVolume(x, y - 1, z))
                        - 2 * tResult(SrcVolume(x, y - 2, z))
                        - tResult(SrcVolume(x, y - 3, z))
                        );
    return Value;
}


// Volume filtering method
template <class V, template <typename> class N>
bool CVolumeDiffZFilter<V,N>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    // Volume size
    tSize XCount = vpl::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YCount = vpl::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZCount = vpl::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());

    // Filter the volume
#pragma omp parallel for schedule(static) default(shared)
    for( tSize z = 0; z < ZCount; ++z )
    {
        for( tSize y = 0; y < YCount; ++y )
        {
            for( tSize x = 0; x < XCount; ++x )
            {
                tResult Value = getResponse(SrcVolume, x, y, z);
                DstVolume.set(x, y, z, base::normalize(Value));
            }
        }
    }

    // O.K.
    return true;
}


// Volume filter response
template <class V, template <typename> class N>
inline typename CVolumeDiffZFilter<V,N>::tResult CVolumeDiffZFilter<V,N>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        4 * tResult(SrcVolume(x, y, z + 1))
                        + 2 * tResult(SrcVolume(x, y, z + 2))
                        + tResult(SrcVolume(x, y, z + 3))
                        - 4 * tResult(SrcVolume(x, y, z - 1))
                        - 2 * tResult(SrcVolume(x, y, z - 2))
                        - tResult(SrcVolume(x, y, z - 3))
                        );
    return Value;
}

