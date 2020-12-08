//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/15                          \n
 *
 * $Id: mdsGeneral.hxx 2105 2012-02-18 06:36:50Z spanel $
 *
 * Description:
 * - General matrix functions.
 */


//==============================================================================
/*
 * Functions templates.
 */

template <typename R, class M1, class M2>
inline R getProduct(const CMatrixBase<M1>& Matrix1, const CMatrixBase<M2>& Matrix2)
{
    tSize NumOfCols = mds::math::getMin(Matrix1.getColSize(), Matrix2.getColSize());
    tSize NumOfRows = mds::math::getMin(Matrix1.getRowSize(), Matrix2.getRowSize());

    tSize Count = NumOfCols * NumOfRows;
    MDS_CHECK(Count > 0, return R(0));

    R Total = R(0);
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < NumOfRows; ++j )
    {
        R SubTotal = R(0);
        tSize idx1 = Matrix1.getIdx(j, 0);
        tSize idx2 = Matrix2.getIdx(j, 0);
        for( tSize i = 0; i < NumOfCols; ++i, idx1 += Matrix1.getColOffset(), idx2 += Matrix2.getColOffset() )
        {
            SubTotal += R(Matrix1(idx1)) * R(Matrix2(idx2));
        }
#pragma omp atomic
        Total += SubTotal;
    }
    return Total;
}


template <typename R, class M1, class M2>
inline R getSquareError(const CMatrixBase<M1>& Matrix1, const CMatrixBase<M2>& Matrix2)
{
    tSize NumOfCols = mds::math::getMin(Matrix1.getColSize(), Matrix2.getColSize());
    tSize NumOfRows = mds::math::getMin(Matrix1.getRowSize(), Matrix2.getRowSize());

    tSize Count = NumOfCols * NumOfRows;
    MDS_CHECK(Count > 0, return R(0));

    R Total = R(0);
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < NumOfRows; ++j )
    {
        R SubTotal = R(0);
        tSize idx1 = Matrix1.getIdx(j, 0);
        tSize idx2 = Matrix2.getIdx(j, 0);
        for( tSize i = 0; i < NumOfCols; ++i, idx1 += Matrix1.getColOffset(), idx2 += Matrix2.getColOffset() )
        {
            R Temp = R(Matrix2(idx2)) - R(Matrix1(idx1));
            SubTotal += Temp * Temp;
        }
#pragma omp atomic
        Total += SubTotal;
    }
    return Total / R(Count);
}


template <typename R, class M>
inline R getSum(const CMatrixBase<M>& Matrix)
{
    typedef typename M::tElement tElement;

    return Matrix.forEach(mds::base::CSum<R,tElement>()).getValue();
}


template <typename R, class M>
inline R getMult(const CMatrixBase<M>& Matrix)
{
    typedef typename M::tElement tElement;

    return Matrix.forEach(mds::base::CCumulativeMult<R,tElement>()).getValue();
}


template <typename R, class M>
inline R getSumOfSquares(const CMatrixBase<M>& Matrix)
{
    typedef typename M::tElement tElement;

    return Matrix.forEach(mds::base::CSumOfSquares<R,tElement>()).getValue();
}


template <typename R, class M>
inline R getTrace(const CMatrixBase<M>& Matrix)
{
    typedef typename M::tElement tElement;

    tSize Size = mds::math::getMin(Matrix.getNumOfRows(), Matrix.getNumOfCols());

    tSize idx = Matrix.getIdx(0, 0);

    R Total = R(0);
    for( tSize i = 0; i < Size; ++i )
    {
        Total += R(Matrix(idx));
        idx += Matrix.getRowOffset() + Matrix.getColOffset();
    }
    return Total;
}


template <typename R, class M>
inline R getMean(const CMatrixBase<M>& Matrix)
{
    typedef typename M::tElement tElement;

    return Matrix.forEach(mds::base::CMeanValue<R,tElement>()).getValue();
}


template <typename R, class M>
inline R getVariance(const CMatrixBase<M>& Matrix)
{
    typedef typename M::tElement tElement;

    return Matrix.forEach(mds::base::CVariance<R,tElement>()).getValue();
}


template <typename R, class M>
inline R getMin(const CMatrixBase<M>& Matrix)
{
    typedef typename M::tElement tElement;

    tSize Count = Matrix.getNumOfRows() * Matrix.getNumOfCols();
    MDS_CHECK(Count > 0, return R());

    return R(Matrix.forEach(mds::base::CMin<tElement>(Matrix(0,0))).getValue());
}


template <typename R, class M>
inline R getMax(const CMatrixBase<M>& Matrix)
{
    typedef typename M::tElement tElement;

    tSize Count = Matrix.getNumOfRows() * Matrix.getNumOfCols();
    MDS_CHECK(Count > 0, return R());

    return R(Matrix.forEach(mds::base::CMax<tElement>(Matrix(0,0))).getValue());
}


template <class M>
std::ostream& operator <<(std::ostream& Stream, const CMatrixBase<M>& Matrix)
{
//  Stream.setf(std::ios_base::fixed);
    for( tSize i = 0; i < Matrix.getNumOfRows(); ++i )
    {
        for( tSize j = 0; j < Matrix.getNumOfCols(); ++j )
        {
            Stream << Matrix(i,j) << "  ";
        }
        if( i < Matrix.getNumOfRows() - 1 )
        {
            Stream << std::endl;
        }
    }
    
    return Stream;
}

