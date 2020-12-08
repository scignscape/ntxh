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
 * Copyright (c) 2003-2010 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/15                       
 *
 * Description:
 * - General vector functions.
 */


//==============================================================================
/*
 * Functions templates.
 */

template <typename R, class V1, class V2>
inline R getProd(const CVectorBase<V1>& Vector1, const CVectorBase<V2>& Vector2)
{
    tSize Count = vpl::math::getMin(Vector1.getSize(), Vector2.getSize());

    R Total = R(0);
    for( tSize i = 0; i < Count; ++i )
    {
        Total += R(Vector1(i)) * R(Vector2(i));
    }
    return Total;
}


template <typename R, class V>
inline R getSum(const CVectorBase<V>& Vector)
{
    typedef typename V::tElement tElement;

    return Vector.forEach(vpl::base::CSum<R,tElement>()).getValue();
}


template <typename R, class V>
inline R getMult(const CVectorBase<V>& Vector)
{
    typedef typename V::tElement tElement;

    return Vector.forEach(vpl::base::CCumulativeMult<R,tElement>()).getValue();
}


template <typename R, class V>
inline R getSumOfSquares(const CVectorBase<V>& Vector)
{
    typedef typename V::tElement tElement;

    return Vector.forEach(vpl::base::CSumOfSquares<R,tElement>()).getValue();
}


template <typename R, class V1, class V2>
inline R getSquareError(const CVectorBase<V1>& Vector1, const CVectorBase<V2>& Vector2)
{
    tSize Count = vpl::math::getMin(Vector1.getSize(), Vector2.getSize());
    VPL_CHECK(Count > 0, return R(0));

    R Total = R(0);
    for( tSize i = 0; i < Count; ++i )
    {
        R Temp = R(Vector2(i)) - R(Vector1(i));
        Total += Temp * Temp;
    }
    return Total / R(Count);
}


template <typename R, class V1, class V2>
inline R getError(const CVectorBase<V1>& Vector1, const CVectorBase<V2>& Vector2)
{
    tSize Count = vpl::math::getMin(Vector1.getSize(), Vector2.getSize());
    VPL_CHECK(Count > 0, return R(0));

    R Total = R(0);
    for( tSize i = 0; i < Count; ++i )
    {
        Total += vpl::math::getAbs(R(Vector2(i)) - R(Vector1(i)));
    }
    return Total / R(Count);
}


template <typename R, class V>
inline R getMean(const CVectorBase<V>& Vector)
{
    typedef typename V::tElement tElement;

    return Vector.forEach(vpl::base::CMeanValue<R,tElement>()).getValue();
}


template <typename R, class V>
inline R getVariance(const CVectorBase<V>& Vector)
{
    typedef typename V::tElement tElement;

    return Vector.forEach(vpl::base::CVariance<R,tElement>()).getValue();
}


template <typename R, class V>
inline R getMin(const CVectorBase<V>& Vector)
{
    typedef typename V::tElement tElement;

    tSize Count = Vector.getSize();
    VPL_CHECK(Count > 0, return R());

    return Vector.forEach(vpl::base::CMin<tElement>(Vector(0))).getValue();
}


template <typename R, class V>
inline R getMax(const CVectorBase<V>& Vector)
{
    typedef typename V::tElement tElement;

    tSize Count = Vector.getSize();
    VPL_CHECK(Count > 0, return R());

    return Vector.forEach(vpl::base::CMax<tElement>(Vector(0))).getValue();
}


template <class V>
std::ostream& operator <<(std::ostream& Stream, const CVectorBase<V>& Vector)
{
//  Stream.setf(std::ios_base::fixed);
    for( vpl::tSize i = 0; i < Vector.getSize(); i++ )
    {
        Stream << Vector(i) << "  ";
    }

    return Stream;
}


template <class V1, class V2>
inline void inplaceAdd(CVectorBase<V2>& R, const CVectorBase<V1>& A)
{
    tSize Count = vpl::math::getMin(A.getSize(), R.getSize());
    for( tSize i = 0; i < Count; ++i )
    {
        R(i) += A(i);
    }
}


template <class V1, class V2>
inline void inplaceSub(CVectorBase<V2>& R, const CVectorBase<V1>& A)
{
    tSize Count = vpl::math::getMin(A.getSize(), R.getSize());
    for( tSize i = 0; i < Count; ++i )
    {
        R(i) -= A(i);
    }
}


template <typename T, class V1, class V2>
inline void inplaceMultAdd(CVectorBase<V2>& R, const CVectorBase<V1>& A, const T& b)
{
    tSize Count = vpl::math::getMin(A.getSize(), R.getSize());
    for( tSize i = 0; i < Count; ++i )
    {
        R(i) += A(i) * b;
    }
}

