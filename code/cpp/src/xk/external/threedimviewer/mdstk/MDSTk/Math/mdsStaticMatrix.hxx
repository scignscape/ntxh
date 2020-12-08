//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/06/05                          \n
 *
 * $Id: mdsStaticMatrix.hxx 2093 2012-02-16 00:32:09Z spanel $
 * 
 * Description:
 * - Static matrix template implementation.
 */


//==============================================================================
/*
 * Method templates
 */
template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>::CStaticMatrix() : m_Matrix()
{
}


// Copy constructor
template <typename T, tSize M, tSize N>
template <typename U>
inline CStaticMatrix<T,M,N>::CStaticMatrix(const CStaticMatrix<U,M,N>& Matrix)
    : m_Matrix()
{
    m_Matrix = Matrix.asEigen().template cast<T>();
}


template <typename T, tSize M, tSize N>
template <typename Derived>
inline CStaticMatrix<T,M,N>::CStaticMatrix(const Eigen::MatrixBase<Derived>& Matrix)
    : m_Matrix()
{
    m_Matrix = Matrix.template cast<T>();
}


// Copy constructor
template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>::CStaticMatrix(const CStaticMatrix<T,M,N>& Matrix)
    : tBase()
    , m_Matrix(Matrix.asEigen())
{
}


// Assignment operator
template <typename T, tSize M, tSize N>
template <typename U>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::operator =(const CStaticMatrix<U,M,N>& Matrix)
{
    m_Matrix = Matrix.asEigen().template cast<T>();

    return *this;
}


template <typename T, tSize M, tSize N>
template <typename Derived>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::operator =(const Eigen::MatrixBase<Derived>& Matrix)
{
    m_Matrix = Matrix.template cast<T>();

    return *this;
}


// Assignment operator
template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::operator =(const CStaticMatrix<T,M,N>& Matrix)
{
    if( &Matrix != this )
    {
        m_Matrix = Matrix.asEigen();
    }

    return *this;
}


// Combined addition and assignment operator
template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::operator +=(const CStaticMatrix<T,M,N>& Matrix)
{
    m_Matrix += Matrix.asEigen();

    return *this;
}


// Combined subtraction and assignment operator
template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::operator -=(const CStaticMatrix<T,M,N>& Matrix)
{
    m_Matrix -= Matrix.asEigen();

    return *this;
}


// Combined multiplication and assignment operator
template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::operator *=(const CStaticMatrix<T,M,N>& Matrix)
{
    tSize NumOfRows = mds::math::getMin(getNumOfRows(), Matrix.getNumOfRows());
    tSize NumOfCols = mds::math::getMin(getNumOfCols(), Matrix.getNumOfCols());

#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < NumOfRows; ++j )
    {
        mds::base::memVectMult(getPtr() + j * getRowOffset(),
                               Matrix.getPtr() + j * Matrix.getRowOffset(),
                               NumOfCols
                               );
    }

    return *this;
}


// Combined division and assignment operator
template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::operator /=(const CStaticMatrix<T,M,N>& Matrix)
{
    tSize NumOfRows = mds::math::getMin(getNumOfRows(), Matrix.getNumOfRows());
    tSize NumOfCols = mds::math::getMin(getNumOfCols(), Matrix.getNumOfCols());

#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < NumOfRows; ++j )
    {
        mds::base::memVectDiv(getPtr() + j * getRowOffset(),
                              Matrix.getPtr() + j * Matrix.getRowOffset(),
                              NumOfCols
                              );
    }

    return *this;
}


// Combined scalar multiplication and assignment operator
template <typename T, tSize M, tSize N>
template <typename U>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::operator *=(const CScalar<U>& c)
{
    forEach(mds::base::CMult<tElement,U>(c.value()));

    return *this;
}


// Combined scalar division and assignment operator
template <typename T, tSize M, tSize N>
template <typename U>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::operator /=(const CScalar<U>& c)
{
    forEach(mds::base::CDiv<tElement,U>(c.value()));

    return *this;
}


// Combined scalar addition and assignment operator
template <typename T, tSize M, tSize N>
template <typename U>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::operator +=(const CScalar<U>& c)
{
    forEach(mds::base::CAdd<tElement>(tElement(c.value())));

    return *this;
}


// Combined scalar subtraction and assignment operator
template <typename T, tSize M, tSize N>
template <typename U>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::operator -=(const CScalar<U>& c)
{
    forEach(mds::base::CSub<tElement>(tElement(c.value())));

    return *this;
}


template <typename T, tSize M, tSize N>
template <class Function>
inline Function CStaticMatrix<T,M,N>::forEach(Function Func)
{
    return mds::base::metaForEach<SIZE,T,Function>(getPtr(), Func);
}


template <typename T, tSize M, tSize N>
template <class Function>
inline Function CStaticMatrix<T,M,N>::forEach(Function Func) const
{
    return mds::base::metaForEach<SIZE,const T,Function>(getPtr(), Func);
}


template <typename T, tSize M, tSize N>
template <class Function>
inline Function CStaticMatrix<T,M,N>::pforEach(Function Func)
{
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < getNumOfRows(); ++j )
    {
        tElement *p = getPtr() + j * getRowOffset();
        for( tSize i = 0; i < getNumOfCols(); ++i, ++p )
        {
            Func(*p);
        }
    }
    return Func;
}


template <typename T, tSize M, tSize N>
template <class Function>
inline Function CStaticMatrix<T,M,N>::pforEach(Function Func) const
{
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < getNumOfRows(); ++j )
    {
        const tElement *p = getPtr() + j * getRowOffset();
        for( tSize i = 0; i < getNumOfCols(); ++i, ++p )
        {
            Func(*p);
        }
    }
    return Func;
}


// Set all elements of a matrix to zero
template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::zeros()
{
    forEach(mds::base::CFill<tElement>(tElement()));

    return *this;
}


// Set all elements of a matrix to one
template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::ones()
{
    forEach(mds::base::CFill<tElement>(tElement(1)));

    return *this;
}


// Set a matrix to unit
template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::unit()
{
    for( tSize i = 0; i < M; ++i )
    {
        for( tSize j = 0; j < N; ++j )
        {
            m_Matrix(i, j) = (i == j) ? T(1) : T(0);
        }
    }

    return *this;
}


template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::fill(const T& Value)
{
    forEach(mds::base::CFill<tElement>(Value));

    return *this;
}


template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::abs()
{
    forEach(mds::base::CAbs<tElement>());
    
    return *this;
}


template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::multAdd(const CStaticMatrix<T,M,N>& Matrix,
                                                           const T& Scalar
                                                           )
{
    m_Matrix += Scalar * Matrix.asEigen();
    
    return *this;
}


// Matrix multiplication
template <typename T, tSize M, tSize N>
template <tSize K>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::mult(const CStaticMatrix<T,M,K>& m1,
                                                        const CStaticMatrix<T,K,N>& m2
                                                        )
{
    m_Matrix = m1.asEigen() * m2.asEigen();

    return *this;
}


// Compute a matrix transpose
template <typename T, tSize M, tSize N>
inline CStaticMatrix<T,M,N>& CStaticMatrix<T,M,N>::transpose(const CStaticMatrix<T,N,M>& Matrix)
{
    m_Matrix = Matrix.asEigen().transpose();

    return *this;
}

