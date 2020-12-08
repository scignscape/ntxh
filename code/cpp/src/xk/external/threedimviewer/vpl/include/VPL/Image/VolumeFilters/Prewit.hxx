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
 * Date:    2005/09/20                       
 * 
 * Description:
 * - Prewit gradient edge detectors.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Volume filtering method
template <class V, template <typename> class N>
bool CVolumePrewitX<V,N>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
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
inline typename CVolumePrewitX<V,N>::tResult CVolumePrewitX<V,N>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        tResult(SrcVolume(x + 1, y, z))
                        + tResult(SrcVolume(x + 1, y - 1, z))
                        + tResult(SrcVolume(x + 1, y + 1, z))
                        + tResult(SrcVolume(x + 1, y, z - 1))
                        + tResult(SrcVolume(x + 1, y - 1, z - 1))
                        + tResult(SrcVolume(x + 1, y + 1, z - 1))
                        + tResult(SrcVolume(x + 1, y, z + 1))
                        + tResult(SrcVolume(x + 1, y - 1, z + 1))
                        + tResult(SrcVolume(x + 1, y + 1, z + 1))
                        - tResult(SrcVolume(x - 1, y, z))
                        - tResult(SrcVolume(x - 1, y - 1, z))
                        - tResult(SrcVolume(x - 1, y + 1, z))
                        - tResult(SrcVolume(x - 1, y, z - 1))
                        - tResult(SrcVolume(x - 1, y - 1, z - 1))
                        - tResult(SrcVolume(x - 1, y + 1, z - 1))
                        - tResult(SrcVolume(x - 1, y, z + 1))
                        - tResult(SrcVolume(x - 1, y - 1, z + 1))
                        - tResult(SrcVolume(x - 1, y + 1, z + 1))
                        );
    return Value;
}


// Volume filtering method
template <class V, template <typename> class N>
bool CVolumePrewitY<V,N>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
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
inline typename CVolumePrewitY<V,N>::tResult CVolumePrewitY<V,N>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        tResult(SrcVolume(x, y + 1, z))
                        + tResult(SrcVolume(x + 1, y + 1, z))
                        + tResult(SrcVolume(x - 1, y + 1, z))
                        + tResult(SrcVolume(x, y + 1, z - 1))
                        + tResult(SrcVolume(x + 1, y + 1, z - 1))
                        + tResult(SrcVolume(x - 1, y + 1, z - 1))
                        + tResult(SrcVolume(x, y + 1, z + 1))
                        + tResult(SrcVolume(x + 1, y + 1, z + 1))
                        + tResult(SrcVolume(x - 1, y + 1, z + 1))
                        - tResult(SrcVolume(x, y - 1, z))
                        - tResult(SrcVolume(x + 1, y - 1, z))
                        - tResult(SrcVolume(x - 1, y - 1, z))
                        - tResult(SrcVolume(x, y - 1, z - 1))
                        - tResult(SrcVolume(x + 1, y - 1, z - 1))
                        - tResult(SrcVolume(x - 1, y - 1, z - 1))
                        - tResult(SrcVolume(x, y - 1, z + 1 ))
                        - tResult(SrcVolume(x + 1, y - 1, z + 1))
                        - tResult(SrcVolume(x - 1, y - 1, z + 1))
                        );
    return Value;
}


// Volume filtering method
template <class V, template <typename> class N>
bool CVolumePrewitZ<V,N>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
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
inline typename CVolumePrewitZ<V,N>::tResult CVolumePrewitZ<V,N>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        tResult(SrcVolume(x, y, z + 1))
                        + tResult(SrcVolume(x + 1, y, z + 1))
                        + tResult(SrcVolume(x - 1, y, z + 1))
                        + tResult(SrcVolume(x, y - 1, z + 1))
                        + tResult(SrcVolume(x + 1, y - 1, z + 1))
                        + tResult(SrcVolume(x - 1, y - 1, z + 1))
                        + tResult(SrcVolume(x, y + 1, z + 1))
                        + tResult(SrcVolume(x + 1, y + 1, z + 1))
                        + tResult(SrcVolume(x - 1, y + 1, z + 1))
                        - tResult(SrcVolume(x, y, z - 1))
                        - tResult(SrcVolume(x + 1, y, z - 1))
                        - tResult(SrcVolume(x - 1, y, z - 1))
                        - tResult(SrcVolume(x, y - 1, z - 1))
                        - tResult(SrcVolume(x + 1, y - 1, z - 1))
                        - tResult(SrcVolume(x - 1, y - 1, z - 1))
                        - tResult(SrcVolume(x, y + 1, z - 1))
                        - tResult(SrcVolume(x + 1, y + 1, z - 1))
                        - tResult(SrcVolume(x - 1, y + 1, z - 1))
                        );
    return Value;
}

