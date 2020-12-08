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
 * Date:    2005/09/08                       
 *
 * Description:
 * - Laplacian image filters.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Image filtering method
template <class I, template <typename> class N>
bool CLaplaceFilter0<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
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
template <class I, template <typename> class N>
typename CLaplaceFilter0<I,N>::tResult CLaplaceFilter0<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        tResult(SrcImage(x, y - 1))
                        + tResult(SrcImage(x, y + 1))
                        + tResult(SrcImage(x - 1, y))
                        + tResult(SrcImage(x + 1, y))
                        - 4 * tResult(SrcImage(x, y))
                        );
    return Value;
}


// Image filtering method
template <class I, template <typename> class N>
bool CLaplaceFilter1<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
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
template <class I, template <typename> class N>
typename CLaplaceFilter1<I,N>::tResult CLaplaceFilter1<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        tResult(SrcImage(x, y - 1))
                        + tResult(SrcImage(x, y + 1))
                        + tResult(SrcImage(x - 1, y))
                        + tResult(SrcImage(x - 1, y - 1))
                        + tResult(SrcImage(x - 1, y + 1))
                        + tResult(SrcImage(x + 1, y))
                        + tResult(SrcImage(x + 1, y - 1))
                        + tResult(SrcImage(x + 1, y + 1))
                        - 8 * tResult(SrcImage(x, y))
                        );
    return Value;
}


// Image filtering method
template <class I, template <typename> class N>
bool CLaplaceFilter2<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
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
template <class I, template <typename> class N>
typename CLaplaceFilter2<I,N>::tResult CLaplaceFilter2<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        2 * tResult(SrcImage(x, y - 1))
                        + 2 * tResult(SrcImage(x, y + 1))
                        + 2 * tResult(SrcImage(x - 1, y))
                        + 2 * tResult(SrcImage(x + 1, y))
                        - tResult(SrcImage(x - 1, y - 1))
                        - tResult(SrcImage(x - 1, y + 1))
                        - tResult(SrcImage(x + 1, y - 1))
                        - tResult(SrcImage(x + 1, y + 1))
                        - 4 * tResult(SrcImage(x, y))
                        );
    return Value;
}


// Filter kernel
template <class I, template <typename> class N>
const CKernel2D::tData CLaplaceFilter5<I,N>::KERNEL[] =
{
    0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
    0.0f, -1.0f, -2.0f, -1.0f,  0.0f,
    -1.0f, -2.0f, 16.0f, -2.0f, -1.0f,
    0.0f, -1.0f, -2.0f, -1.0f,  0.0f,
    0.0f,  0.0f, -1.0f,  0.0f,  0.0f
};


// Image filtering method
template <class I, template <typename> class N>
bool CLaplaceFilter5<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
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
template <class I, template <typename> class N>
typename CLaplaceFilter5<I,N>::tResult CLaplaceFilter5<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const tResult Denom = 1.0 / DENOM;

    // Filter kernel
    static const CKernel2D Kernel(KERNEL, getSize());

    // Compute filter response
    return Denom * convolve<tResult>(SrcImage, x, y, Kernel);
}

