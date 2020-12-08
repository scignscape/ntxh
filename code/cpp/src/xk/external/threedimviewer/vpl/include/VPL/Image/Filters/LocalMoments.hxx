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
 * Date:    2006/03/30                       
 *
 * Description:
 * - Local moments (local texture features).
 */


//==============================================================================
/*
 * Methods templates.
 */

// Image filtering method
template <typename I, template <typename> class N>
bool CLocalMoment00<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            tResult Value = getResponse(SrcImage, x, y);
            DstImage.set(x, y, base::normalize(Value));
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <typename I, template <typename> class N>
inline typename CLocalMoment00<I,N>::tResult CLocalMoment00<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        tResult(SrcImage(x - 1, y -1))
                        + tResult(SrcImage(x, y - 1))
                        + tResult(SrcImage(x + 1, y - 1))
                        + tResult(SrcImage(x - 1, y))
                        + tResult(SrcImage(x, y))
                        + tResult(SrcImage(x + 1, y))
                        + tResult(SrcImage(x - 1, y + 1))
                        + tResult(SrcImage(x, y + 1))
                        + tResult(SrcImage(x + 1, y + 1))
                        );

    return Value;
}


// Image filtering method
template <typename I, template <typename> class N>
bool CLocalMoment10<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            tResult Value = getResponse(SrcImage, x, y);
            DstImage.set(x, y, base::normalize(Value));
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <typename I, template <typename> class N>
inline typename CLocalMoment10<I,N>::tResult CLocalMoment10<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        - tResult(SrcImage(x - 1, y -1))
                        - tResult(SrcImage(x, y - 1))
                        - tResult(SrcImage(x + 1, y - 1))
                        + tResult(SrcImage(x - 1, y + 1))
                        + tResult(SrcImage(x, y + 1))
                        + tResult(SrcImage(x + 1, y + 1))
                        );

    return Value;
}


// Image filtering method
template <typename I, template <typename> class N>
bool CLocalMoment01<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            tResult Value = getResponse(SrcImage, x, y);
            DstImage.set(x, y, base::normalize(Value));
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <typename I, template <typename> class N>
inline typename CLocalMoment01<I,N>::tResult CLocalMoment01<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        - tResult(SrcImage(x - 1, y - 1))
                        + tResult(SrcImage(x + 1, y - 1))
                        - tResult(SrcImage(x - 1, y))
                        + tResult(SrcImage(x + 1, y))
                        - tResult(SrcImage(x - 1, y + 1))
                        + tResult(SrcImage(x + 1, y + 1))
                        );

    return Value;
}


// Image filtering method
template <typename I, template <typename> class N>
bool CLocalMoment11<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            tResult Value = getResponse(SrcImage, x, y);
            DstImage.set(x, y, base::normalize(Value));
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <typename I, template <typename> class N>
inline typename CLocalMoment11<I,N>::tResult CLocalMoment11<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        tResult(SrcImage(x - 1, y -1))
                        - tResult(SrcImage(x + 1, y - 1))
                        - tResult(SrcImage(x - 1, y + 1))
                        + tResult(SrcImage(x + 1, y + 1))
                        );

    return Value;
}


// Image filtering method
template <typename I, template <typename> class N>
bool CLocalMoment20<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            tResult Value = getResponse(SrcImage, x, y);
            DstImage.set(x, y, base::normalize(Value));
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <typename I, template <typename> class N>
inline typename CLocalMoment20<I,N>::tResult CLocalMoment20<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        tResult(SrcImage(x - 1, y - 1))
                        + tResult(SrcImage(x, y - 1))
                        + tResult(SrcImage(x + 1, y - 1))
                        + tResult(SrcImage(x - 1, y + 1))
                        + tResult(SrcImage(x, y + 1))
                        + tResult(SrcImage(x + 1, y + 1))
                        );

    return Value;
}


// Image filtering method
template <typename I, template <typename> class N>
bool CLocalMoment02<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            tResult Value = getResponse(SrcImage, x, y);
            DstImage.set(x, y, base::normalize(Value));
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <typename I, template <typename> class N>
inline typename CLocalMoment02<I,N>::tResult CLocalMoment02<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        tResult(SrcImage(x - 1, y - 1))
                        + tResult(SrcImage(x + 1, y - 1))
                        + tResult(SrcImage(x - 1, y))
                        + tResult(SrcImage(x + 1, y))
                        + tResult(SrcImage(x - 1, y + 1))
                        + tResult(SrcImage(x + 1, y + 1))
                        );

    return Value;
}


// Image filtering method
template <typename I, template <typename> class N>
bool CLocalMoment22<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            tResult Value = getResponse(SrcImage, x, y);
            DstImage.set(x, y, base::normalize(Value));
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <typename I, template <typename> class N>
inline typename CLocalMoment22<I,N>::tResult CLocalMoment22<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (tResult(SrcImage(x - 1, y - 1))
                        + tResult(SrcImage(x + 1, y - 1))
                        + tResult(SrcImage(x - 1, y + 1))
                        + tResult(SrcImage(x + 1, y + 1))
                        );

    return Value;
}

