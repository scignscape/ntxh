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
 * Date:    2006/02/20                       
 *
 * Description:
 * - General image functions.
 */


//==============================================================================
/*
 * Functions templates.
 */

template <typename R, class I1, class I2>
inline R getProduct(const CImageBase<I1>& Image1, const CImageBase<I2>& Image2)
{
    tSize XCount = vpl::math::getMin(Image1.getXSize(), Image2.getXSize());
    tSize YCount = vpl::math::getMin(Image1.getYSize(), Image2.getYSize());

    tSize Count = XCount * YCount;
    VPL_CHECK(Count > 0, return R(0));

    R Total = R(0);
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YCount; ++j )
    {
        R SubTotal = R(0);
        tSize idx1 = Image1.getIdx(0, j);
        tSize idx2 = Image2.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += Image1.getXOffset(), idx2 += Image2.getXOffset() )
        {
            SubTotal += R(Image1(idx1)) * R(Image2(idx2));
        }
#pragma omp atomic
        Total += SubTotal;
    }
    return Total;
}


template <typename R, class I1, class I2>
inline R getMeanSquareError(const CImageBase<I1>& Image1, const CImageBase<I2>& Image2)
{
    tSize XCount = vpl::math::getMin(Image1.getXSize(), Image2.getXSize());
    tSize YCount = vpl::math::getMin(Image1.getYSize(), Image2.getYSize());

    tSize Count = XCount * YCount;
    VPL_CHECK(Count > 0, return R(0));

    R Total = R(0);
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YCount; ++j )
    {
        R SubTotal = R(0);
        tSize idx1 = Image1.getIdx(0, j);
        tSize idx2 = Image2.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += Image1.getXOffset(), idx2 += Image2.getXOffset() )
        {
            R Temp = R(Image2(idx2)) - R(Image1(idx1));
            SubTotal += Temp * Temp;
        }
#pragma omp atomic
        Total += SubTotal;
    }
    return (Total / R(Count));
}


template <typename R, class I>
inline R getSum(const CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;

    return Image.forEach(vpl::base::CSum<R,tPixel>()).getValue();
}


template <typename R, class I>
inline R getSumOfSquares(const CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;

    return Image.forEach(vpl::base::CSumOfSquares<R,tPixel>()).getValue();
}


template <typename R, class I>
inline R getMean(const CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;

    return Image.forEach(vpl::base::CMeanValue<R,tPixel>()).getValue();
}


template <typename R, class I>
inline R getVariance(const CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;

    return Image.forEach(vpl::base::CVariance<R,tPixel>()).getValue();
}


template <typename R, class I>
inline R getMin(const CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;

    tSize Count = Image.getXSize() * Image.getYSize();
    VPL_CHECK(Count > 0, return R());

    return R(Image.forEach(vpl::base::CMin<tPixel>(Image(0,0))).getValue());
}


template <typename R, class I>
inline R getMax(const CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;

    tSize Count = Image.getXSize() * Image.getYSize();
    VPL_CHECK(Count > 0, return R());

    return R(Image.forEach(vpl::base::CMax<tPixel>(Image(0,0))).getValue());
}

