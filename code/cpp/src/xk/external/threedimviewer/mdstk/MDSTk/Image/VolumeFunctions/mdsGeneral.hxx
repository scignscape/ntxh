//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/21                          \n
 *
 * $Id: mdsGeneral.hxx 2105 2012-02-18 06:36:50Z spanel $
 *
 * Description:
 * - General volume functions.
 */


//==============================================================================
/*
 * Functions templates.
 */

template <typename R, class V1, class V2>
inline R getProduct(const CVolumeBase<V1>& Volume1, const CVolumeBase<V2>& Volume2)
{
    tSize XCount = mds::math::getMin(Volume1.getXSize(), Volume2.getXSize());
    tSize YCount = mds::math::getMin(Volume1.getYSize(), Volume2.getYSize());
    tSize ZCount = mds::math::getMin(Volume1.getZSize(), Volume2.getZSize());

    tSize Count = XCount * YCount * ZCount;
    MDS_CHECK(Count > 0, return R(0));

    R Total = R(0);
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < ZCount; ++k )
    {
        R SubTotal = R(0);
        for( tSize j = 0; j < YCount; ++j )
        {
            tSize idx1 = Volume1.getIdx(0, j, k);
            tSize idx2 = Volume2.getIdx(0, j, k);
            for( tSize i = 0; i < XCount; ++i, idx1 += Volume1.getXOffset(), idx2 += Volume2.getXOffset() )
            {
                SubTotal += R(Volume1(idx1)) * R(Volume2(idx2));
            }
        }
#pragma omp atomic
        Total += SubTotal;
    }
    return Total;
}


template <typename R, class V1, class V2>
inline R getMeanSquareError(const CVolumeBase<V1>& Volume1, const CVolumeBase<V2>& Volume2)
{
    tSize XCount = mds::math::getMin(Volume1.getXSize(), Volume2.getXSize());
    tSize YCount = mds::math::getMin(Volume1.getYSize(), Volume2.getYSize());
    tSize ZCount = mds::math::getMin(Volume1.getZSize(), Volume2.getZSize());

    tSize Count = XCount * YCount * ZCount;
    MDS_CHECK(Count > 0, return R(0));

    R Total = R(0);
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < ZCount; ++k )
    {
        R SubTotal = R(0);
        for( tSize j = 0; j < YCount; ++j )
        {
            tSize idx1 = Volume1.getIdx(0, j, k);
            tSize idx2 = Volume2.getIdx(0, j, k);
            for( tSize i = 0; i < XCount; ++i, idx1 += Volume1.getXOffset(), idx2 += Volume2.getXOffset() )
            {
                R Temp = R(Volume2(idx2)) - R(Volume1(idx1));
                SubTotal += Temp * Temp;
            }
        }
#pragma omp atomic
        Total += SubTotal;
    }
    return Total / R(Count);
}


template <typename R, class V>
inline R getSum(const CVolumeBase<V>& Volume)
{
    R Total = R(0);
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < Volume.getZSize(); ++k )
    {
        R SubTotal = R(0);
        for( tSize j = 0; j < Volume.getYSize(); ++j )
        {
            tSize idx = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Volume.getXSize(); ++i, idx += Volume.getXOffset() )
            {
                SubTotal += R(Volume(idx));
            }
        }
#pragma omp atomic
        Total += SubTotal;
    }
    return Total;

//    typedef typename V::tVoxel tVoxel;
//    return Volume.forEach(mds::base::CSum<R,tVoxel>()).getValue();
}


template <typename R, class V>
inline R getSumOfSquares(const CVolumeBase<V>& Volume)
{
    R Total = R(0);
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < Volume.getZSize(); ++k )
    {
        R SubTotal = R(0);
        for( tSize j = 0; j < Volume.getYSize(); ++j )
        {
            tSize idx = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Volume.getXSize(); ++i, idx += Volume.getXOffset() )
            {
                R Temp = R(Volume(idx));
                SubTotal += Temp * Temp;
            }
        }
#pragma omp atomic
        Total += SubTotal;
    }
    return Total;

//    typedef typename V::tVoxel tVoxel;
//    return Volume.forEach(mds::base::CSumOfSquares<R,tVoxel>()).getValue();
}


template <typename R, class V>
inline R getMean(const CVolumeBase<V>& Volume)
{
    tSize Count = Volume.getXSize() * Volume.getYSize() * Volume.getZSize();
    MDS_CHECK(Count > 0, return R(0));

    R Total = R(0);
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < Volume.getZSize(); ++k )
    {
        R SubTotal = R(0);
        for( tSize j = 0; j < Volume.getYSize(); ++j )
        {
            tSize idx = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Volume.getXSize(); ++i, idx += Volume.getXOffset() )
            {
                SubTotal += R(Volume(idx));
            }
        }
#pragma omp atomic
        Total += SubTotal;
    }
    return Total / R(Count);
    
//    typedef typename V::tVoxel tVoxel;
//    return Volume.forEach(mds::base::CMeanValue<R,tVoxel>()).getValue();
}


template <typename R, class V>
inline R getVariance(const CVolumeBase<V>& Volume)
{
    tSize Count = Volume.getXSize() * Volume.getYSize() * Volume.getZSize();
    MDS_CHECK(Count > 0, return R(0));

    R Sum = R(0), SumSqr = R(0);
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < Volume.getZSize(); ++k )
    {
        R SubSum = R(0);
        R SubSumSqr = R(0);
        for( tSize j = 0; j < Volume.getYSize(); ++j )
        {
            tSize idx = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Volume.getXSize(); ++i, idx += Volume.getXOffset() )
            {
                R Temp = R(Volume(idx));
                SubSum += Temp;
                SubSumSqr += Temp * Temp;
            }
        }
#pragma omp critical
        {
            Sum += SubSum;
            SumSqr += SubSumSqr;
        }
    }
    R Temp = R(1) / R(Count);
    return SumSqr * Temp - (Sum * Temp * Sum * Temp);
    
//    typedef typename V::tVoxel tVoxel;
//    return Volume.forEach(mds::base::CVariance<R,tVoxel>()).getValue();
}


template <typename R, class V>
inline R getMin(const CVolumeBase<V>& Volume)
{
    typedef typename V::tVoxel tVoxel;

    tSize Count = Volume.getXSize() * Volume.getYSize() * Volume.getZSize();
    MDS_CHECK(Count > 0, return R());
    
    tVoxel Min = Volume(0, 0, 0);
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < Volume.getZSize(); ++k )
    {
        tVoxel SubMin = Volume(0, 0, k);
        for( tSize j = 0; j < Volume.getYSize(); ++j )
        {
            tSize idx = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Volume.getXSize(); ++i, idx += Volume.getXOffset() )
            {
                SubMin = mds::math::getMin(SubMin, Volume(idx));
            }
        }
#pragma omp critical
        {
            Min = mds::math::getMin(SubMin, Min);
        }
    }
    return R(Min);

//    return R(Volume.forEach(mds::base::CMin<tVoxel>(Volume(0,0,0))).getValue());
}


template <typename R, class V>
inline R getMax(const CVolumeBase<V>& Volume)
{
    typedef typename V::tVoxel tVoxel;

    tSize Count = Volume.getXSize() * Volume.getYSize() * Volume.getZSize();
    MDS_CHECK(Count > 0, return R());

    tVoxel Max = Volume(0, 0, 0);
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < Volume.getZSize(); ++k )
    {
        tVoxel SubMax = Volume(0, 0, k);
        for( tSize j = 0; j < Volume.getYSize(); ++j )
        {
            tSize idx = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Volume.getXSize(); ++i, idx += Volume.getXOffset() )
            {
                SubMax = mds::math::getMax(SubMax, Volume(idx));
            }
        }
#pragma omp critical
        {
            Max = mds::math::getMax(SubMax, Max);
        }
    }
    return R(Max);

//    return R(Volume.forEach(mds::base::CMax<tVoxel>(Volume(0,0,0))).getValue());
}

