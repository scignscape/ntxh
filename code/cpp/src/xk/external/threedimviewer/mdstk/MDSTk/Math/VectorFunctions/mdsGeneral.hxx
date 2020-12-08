//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/15                          \n
 *
 * $Id: mdsGeneral.hxx 2084 2012-02-13 10:23:58Z spanel $
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
    tSize Count = mds::math::getMin(Vector1.getSize(), Vector2.getSize());

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

    return Vector.forEach(mds::base::CSum<R,tElement>()).getValue();
}


template <typename R, class V>
inline R getMult(const CVectorBase<V>& Vector)
{
    typedef typename V::tElement tElement;

    return Vector.forEach(mds::base::CCumulativeMult<R,tElement>()).getValue();
}


template <typename R, class V>
inline R getSumOfSquares(const CVectorBase<V>& Vector)
{
    typedef typename V::tElement tElement;

    return Vector.forEach(mds::base::CSumOfSquares<R,tElement>()).getValue();
}


template <typename R, class V1, class V2>
inline R getSquareError(const CVectorBase<V1>& Vector1, const CVectorBase<V2>& Vector2)
{
    tSize Count = mds::math::getMin(Vector1.getSize(), Vector2.getSize());
    MDS_CHECK(Count > 0, return R(0));

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
    tSize Count = mds::math::getMin(Vector1.getSize(), Vector2.getSize());
    MDS_CHECK(Count > 0, return R(0));

    R Total = R(0);
    for( tSize i = 0; i < Count; ++i )
    {
        Total += mds::math::getAbs(R(Vector2(i)) - R(Vector1(i)));
    }
    return Total / R(Count);
}


template <typename R, class V>
inline R getMean(const CVectorBase<V>& Vector)
{
    typedef typename V::tElement tElement;

    return Vector.forEach(mds::base::CMeanValue<R,tElement>()).getValue();
}


template <typename R, class V>
inline R getVariance(const CVectorBase<V>& Vector)
{
    typedef typename V::tElement tElement;

    return Vector.forEach(mds::base::CVariance<R,tElement>()).getValue();
}


template <typename R, class V>
inline R getMin(const CVectorBase<V>& Vector)
{
    typedef typename V::tElement tElement;

    tSize Count = Vector.getSize();
    MDS_CHECK(Count > 0, return R());

    return Vector.forEach(mds::base::CMin<tElement>(Vector(0))).getValue();
}


template <typename R, class V>
inline R getMax(const CVectorBase<V>& Vector)
{
    typedef typename V::tElement tElement;

    tSize Count = Vector.getSize();
    MDS_CHECK(Count > 0, return R());

    return Vector.forEach(mds::base::CMax<tElement>(Vector(0))).getValue();
}


template <class V>
std::ostream& operator <<(std::ostream& Stream, const CVectorBase<V>& Vector)
{
//  Stream.setf(std::ios_base::fixed);
    for( mds::tSize i = 0; i < Vector.getSize(); i++ )
    {
        Stream << Vector(i) << "  ";
    }

    return Stream;
}


template <class V1, class V2>
inline void inplaceAdd(CVectorBase<V2>& R, const CVectorBase<V1>& A)
{
    tSize Count = mds::math::getMin(A.getSize(), R.getSize());
    for( tSize i = 0; i < Count; ++i )
    {
        R(i) += A(i);
    }
}


template <class V1, class V2>
inline void inplaceSub(CVectorBase<V2>& R, const CVectorBase<V1>& A)
{
    tSize Count = mds::math::getMin(A.getSize(), R.getSize());
    for( tSize i = 0; i < Count; ++i )
    {
        R(i) -= A(i);
    }
}


template <typename T, class V1, class V2>
inline void inplaceMultAdd(CVectorBase<V2>& R, const CVectorBase<V1>& A, const T& b)
{
    tSize Count = mds::math::getMin(A.getSize(), R.getSize());
    for( tSize i = 0; i < Count; ++i )
    {
        R(i) += A(i) * b;
    }
}

