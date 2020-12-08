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
 * - Sobel operator.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Volume filtering method
template <class V, template <typename> class N>
bool CVolumeSobelX<V,N>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
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

    return true;
}


// Volume filter response
template <class V, template <typename> class N>
inline typename CVolumeSobelX<V,N>::tResult CVolumeSobelX<V,N>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Volume properties
    tSize XOffset = SrcVolume.getXOffset();
    tSize YOffset = SrcVolume.getYOffset();
    tSize ZOffset = SrcVolume.getZOffset();

    // Index of the center
    tSize idx = SrcVolume.getIdx(x, y, z);

    // Compute filter response
    tResult Value = Denom * (
                        4 * tResult(SrcVolume.at(idx + XOffset))
                        + 2 * tResult(SrcVolume.at(idx + XOffset - YOffset))
                        + 2 * tResult(SrcVolume.at(idx + XOffset + YOffset))
                        + 2 * tResult(SrcVolume.at(idx + XOffset - ZOffset))
                        + 2 * tResult(SrcVolume.at(idx + XOffset + ZOffset))
                        + tResult(SrcVolume.at(idx + XOffset - YOffset - ZOffset))
                        + tResult(SrcVolume.at(idx + XOffset + YOffset - ZOffset))
                        + tResult(SrcVolume.at(idx + XOffset - YOffset + ZOffset))
                        + tResult(SrcVolume.at(idx + XOffset + YOffset + ZOffset))
                        - 4 * tResult(SrcVolume.at(idx - XOffset))
                        - 2 * tResult(SrcVolume.at(idx - XOffset - YOffset))
                        - 2 * tResult(SrcVolume.at(idx - XOffset + YOffset))
                        - 2 * tResult(SrcVolume.at(idx - XOffset - ZOffset))
                        - 2 * tResult(SrcVolume.at(idx - XOffset + ZOffset))
                        - tResult(SrcVolume.at(idx - XOffset - YOffset - ZOffset))
                        - tResult(SrcVolume.at(idx - XOffset + YOffset - ZOffset))
                        - tResult(SrcVolume.at(idx - XOffset - YOffset + ZOffset))
                        - tResult(SrcVolume.at(idx - XOffset + YOffset + ZOffset))
                        );

    return Value;
}


// Volume filtering method
template <class V, template <typename> class N>
bool CVolumeSobelY<V,N>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
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

    return true;
}


// Volume filter response
template <class V, template <typename> class N>
inline typename CVolumeSobelY<V,N>::tResult CVolumeSobelY<V,N>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Volume properties
    tSize XOffset = SrcVolume.getXOffset();
    tSize YOffset = SrcVolume.getYOffset();
    tSize ZOffset = SrcVolume.getZOffset();

    // Index of the center
    tSize idx = SrcVolume.getIdx(x, y, z);

    // Compute filter response
    tResult Value = Denom * (
                        4 * tResult(SrcVolume.at(idx + YOffset))
                        + 2 * tResult(SrcVolume.at(idx + XOffset + YOffset))
                        + 2 * tResult(SrcVolume.at(idx - XOffset + YOffset))
                        + 2 * tResult(SrcVolume.at(idx + YOffset - ZOffset))
                        + 2 * tResult(SrcVolume.at(idx + YOffset + ZOffset))
                        + tResult(SrcVolume.at(idx + XOffset + YOffset - ZOffset))
                        + tResult(SrcVolume.at(idx - XOffset + YOffset - ZOffset))
                        + tResult(SrcVolume.at(idx + XOffset + YOffset + ZOffset))
                        + tResult(SrcVolume.at(idx - XOffset + YOffset + ZOffset))
                        - 4 * tResult(SrcVolume.at(idx - YOffset))
                        - 2 * tResult(SrcVolume.at(idx + XOffset - YOffset))
                        - 2 * tResult(SrcVolume.at(idx - XOffset - YOffset))
                        - 2 * tResult(SrcVolume.at(idx - YOffset - ZOffset))
                        - 2 * tResult(SrcVolume.at(idx - YOffset + ZOffset ))
                        - tResult(SrcVolume.at(idx + XOffset - YOffset - ZOffset))
                        - tResult(SrcVolume.at(idx - XOffset - YOffset - ZOffset))
                        - tResult(SrcVolume.at(idx + XOffset - YOffset + ZOffset))
                        - tResult(SrcVolume.at(idx - XOffset - YOffset + ZOffset))
                        );

    return Value;
}


// Volume filtering method
template <class V, template <typename> class N>
bool CVolumeSobelZ<V,N>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
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

    return true;
}


// Volume filter response
template <class V, template <typename> class N>
inline typename CVolumeSobelZ<V,N>::tResult CVolumeSobelZ<V,N>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Volume properties
    tSize XOffset = SrcVolume.getXOffset();
    tSize YOffset = SrcVolume.getYOffset();
    tSize ZOffset = SrcVolume.getZOffset();

    // Pointer to the voxel
    tSize idx = SrcVolume.getIdx(x, y, z);

    // Compute filter response
    tResult Value = Denom * (
                        4 * tResult(SrcVolume.at(idx + ZOffset))
                        + 2 * tResult(SrcVolume.at(idx + XOffset + ZOffset))
                        + 2 * tResult(SrcVolume.at(idx - XOffset + ZOffset))
                        + 2 * tResult(SrcVolume.at(idx - YOffset + ZOffset))
                        + 2 * tResult(SrcVolume.at(idx + YOffset + ZOffset))
                        + tResult(SrcVolume.at(idx + XOffset - YOffset + ZOffset))
                        + tResult(SrcVolume.at(idx - XOffset - YOffset + ZOffset))
                        + tResult(SrcVolume.at(idx + XOffset + YOffset + ZOffset))
                        + tResult(SrcVolume.at(idx - XOffset + YOffset + ZOffset))
                        - 4 * tResult(SrcVolume.at(idx - ZOffset))
                        - 2 * tResult(SrcVolume.at(idx + XOffset - ZOffset))
                        - 2 * tResult(SrcVolume.at(idx - XOffset - ZOffset))
                        - 2 * tResult(SrcVolume.at(idx - YOffset - ZOffset))
                        - 2 * tResult(SrcVolume.at(idx + YOffset - ZOffset))
                        - tResult(SrcVolume.at(idx + XOffset - YOffset - ZOffset))
                        - tResult(SrcVolume.at(idx - XOffset - YOffset - ZOffset))
                        - tResult(SrcVolume.at(idx + XOffset + YOffset - ZOffset))
                        - tResult(SrcVolume.at(idx - XOffset + YOffset - ZOffset))
                        );

    return Value;
}

