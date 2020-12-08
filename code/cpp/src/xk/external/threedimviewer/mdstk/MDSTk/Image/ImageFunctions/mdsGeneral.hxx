//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/20                          \n
 *
 * $Id: mdsGeneral.hxx 2105 2012-02-18 06:36:50Z spanel $
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
    tSize XCount = mds::math::getMin(Image1.getXSize(), Image2.getXSize());
    tSize YCount = mds::math::getMin(Image1.getYSize(), Image2.getYSize());

    tSize Count = XCount * YCount;
    MDS_CHECK(Count > 0, return R(0));

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
    tSize XCount = mds::math::getMin(Image1.getXSize(), Image2.getXSize());
    tSize YCount = mds::math::getMin(Image1.getYSize(), Image2.getYSize());

    tSize Count = XCount * YCount;
    MDS_CHECK(Count > 0, return R(0));

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

    return Image.forEach(mds::base::CSum<R,tPixel>()).getValue();
}


template <typename R, class I>
inline R getSumOfSquares(const CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;

    return Image.forEach(mds::base::CSumOfSquares<R,tPixel>()).getValue();
}


template <typename R, class I>
inline R getMean(const CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;

    return Image.forEach(mds::base::CMeanValue<R,tPixel>()).getValue();
}


template <typename R, class I>
inline R getVariance(const CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;

    return Image.forEach(mds::base::CVariance<R,tPixel>()).getValue();
}


template <typename R, class I>
inline R getMin(const CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;

    tSize Count = Image.getXSize() * Image.getYSize();
    MDS_CHECK(Count > 0, return R());

    return R(Image.forEach(mds::base::CMin<tPixel>(Image(0,0))).getValue());
}


template <typename R, class I>
inline R getMax(const CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;

    tSize Count = Image.getXSize() * Image.getYSize();
    MDS_CHECK(Count > 0, return R());

    return R(Image.forEach(mds::base::CMax<tPixel>(Image(0,0))).getValue());
}

