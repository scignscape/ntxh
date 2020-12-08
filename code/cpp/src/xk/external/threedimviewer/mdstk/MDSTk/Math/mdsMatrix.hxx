//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/03                          \n
 *
 * $Id: mdsMatrix.hxx 2093 2012-02-16 00:32:09Z spanel $
 *
 * Description:
 * - Class template providing basic matrix operations.
 */


//==============================================================================
/*
 * Methods templates.
 */

template <typename T>
inline CMatrix<T>::CMatrix() : m_Matrix()
{
}


template <typename T>
inline CMatrix<T>::CMatrix(tSize NumOfRows, tSize NumOfCols)
    : m_Matrix(NumOfRows, NumOfCols)
{
}


template <typename T>
inline CMatrix<T>::CMatrix(const CMatrix<T>& Matrix,
                           tSize Row,
                           tSize Col,
                           tSize NumOfRows,
                           tSize NumOfCols
                           )
{
/*    MDS_ASSERT(Row >= 0 && NumOfRows >= 0 && Row < Matrix.getNumOfRows()
               && Col >= 0 && NumOfCols >= 0 && Col < Matrix.getNumOfCols()
               );

    // Modify size of the matrix
    NumOfRows = mds::math::getMin(Row + NumOfRows, Matrix.getNumOfRows()) - Row;
    NumOfCols = mds::math::getMin(Col + NumOfCols, Matrix.getNumOfCols()) - Col;*/

    // Copy the data
    m_Matrix = Matrix.asEigen().block(Row, Col, NumOfRows, NumOfCols);
}


// Copy constructor
template <typename T>
inline CMatrix<T>::CMatrix(const CMatrix<T>& Matrix)
    : mds::base::CObject()
    , tBase()
    , m_Matrix(Matrix.asEigen())
{
}


template <typename T>
template <typename Derived>
inline CMatrix<T>::CMatrix(const Eigen::MatrixBase<Derived>& Matrix)
    : m_Matrix(Matrix)
{
}


template <typename T>
CMatrix<T>::~CMatrix()
{
}


template <typename T>
inline CMatrix<T>& CMatrix<T>::create(tSize NumOfRows, tSize NumOfCols)
{
    m_Matrix.resize(NumOfRows, NumOfCols);

    return *this;
}


template <typename T>
inline CMatrix<T>& CMatrix<T>::create(const CMatrix<T>& Matrix,
                                      tSize Row,
                                      tSize Col,
                                      tSize NumOfRows,
                                      tSize NumOfCols
                                      )
{
    // Check the position
/*    MDS_CHECK(Row >= 0 && NumOfRows >= 0 && Row < Matrix.getNumOfRows()
              && Col >= 0 && NumOfCols >= 0 && Col < Matrix.getNumOfCols(), return *this);

    // Matrix size
    NumOfRows = mds::math::getMin(Row + NumOfRows, Matrix.getNumOfRows()) - Row;
    NumOfCols = mds::math::getMin(Col + NumOfCols, Matrix.getNumOfCols()) - Col;*/

    // Copy the data
    m_Matrix = Matrix.asEigen().block(Row, Col, NumOfRows, NumOfCols);

    return *this;
}


template <typename T>
template <typename Derived>
inline CMatrix<T>& CMatrix<T>::create(const CMatrixBase<Derived>& Matrix)
{
    m_Matrix = Matrix.getImpl().asEigen();

    return *this;
}


template <typename T>
template <typename Derived>
inline CMatrix<T>& CMatrix<T>::create(const Eigen::MatrixBase<Derived>& Matrix)
{
    m_Matrix = Matrix;

    return *this;
}


template <typename T>
inline CMatrix<T>& CMatrix<T>::operator =(const CMatrix<T>& Matrix)
{
    if( &Matrix != this )
    {
        m_Matrix = Matrix.asEigen();
    }

    return *this;
}


template <typename T>
template <typename Derived>
inline CMatrix<T>& CMatrix<T>::operator =(const Eigen::MatrixBase<Derived>& Matrix)
{
    m_Matrix = Matrix;

    return *this;
}


// Combined addition and assignment operator
template <typename T>
inline CMatrix<T>& CMatrix<T>::operator +=(const CMatrix<T>& Matrix)
{
//    tSize NumOfRows = mds::math::getMin(m_NumOfRows, Matrix.m_NumOfRows);
//    tSize NumOfCols = mds::math::getMin(m_NumOfCols, Matrix.m_NumOfCols);

    m_Matrix += Matrix.asEigen();

    return *this;
}


// Combined subtraction and assignment operator
template <typename T>
inline CMatrix<T>& CMatrix<T>::operator -=(const CMatrix<T>& Matrix)
{
//    tSize NumOfRows = mds::math::getMin(m_NumOfRows, Matrix.m_NumOfRows);
//    tSize NumOfCols = mds::math::getMin(m_NumOfCols, Matrix.m_NumOfCols);

    m_Matrix -= Matrix.asEigen();

    return *this;
}


// Combined scalar multiplication and assignment operator
template <typename T>
inline CMatrix<T>& CMatrix<T>::operator *=(const CMatrix<T>& Matrix)
{
    tSize NumOfRows = mds::math::getMin(getNumOfRows(), Matrix.getNumOfRows());
    tSize NumOfCols = mds::math::getMin(getNumOfCols(), Matrix.getNumOfCols());

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
template <typename T>
inline CMatrix<T>& CMatrix<T>::operator /=(const CMatrix<T>& Matrix)
{
    tSize NumOfRows = mds::math::getMin(getNumOfRows(), Matrix.getNumOfRows());
    tSize NumOfCols = mds::math::getMin(getNumOfCols(), Matrix.getNumOfCols());

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
template <typename T>
template <typename U>
inline CMatrix<T>& CMatrix<T>::operator *=(const CScalar<U>& c)
{
    pforEach(mds::base::CMult<tElement,U>(c.value()));

    return *this;
}


// Combined scalar division and assignment operator
template <typename T>
template <typename U>
inline CMatrix<T>& CMatrix<T>::operator /=(const CScalar<U>& c)
{
    pforEach(mds::base::CDiv<tElement,U>(c.value()));

    return *this;
}


// Combined scalar addition and assignment operator
template <typename T>
template <typename U>
inline CMatrix<T>& CMatrix<T>::operator +=(const CScalar<U>& c)
{
    pforEach(mds::base::CAdd<tElement>(tElement(c.value())));

    return *this;
}


// Combined scalar subtraction and assignment operator
template <typename T>
template <typename U>
inline CMatrix<T>& CMatrix<T>::operator -=(const CScalar<U>& c)
{
    pforEach(mds::base::CSub<tElement>(tElement(c.value())));

    return *this;
}


template <typename T>
template <class Function>
inline Function CMatrix<T>::forEach(Function Func)
{
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


template <typename T>
template <class Function>
inline Function CMatrix<T>::forEach(Function Func) const
{
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


template <typename T>
template <class Function>
inline Function CMatrix<T>::pforEach(Function Func)
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


template <typename T>
template <class Function>
inline Function CMatrix<T>::pforEach(Function Func) const
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


// Set all elements of the matrix to zero
template <typename T>
inline CMatrix<T>& CMatrix<T>::zeros()
{
    pforEach(mds::base::CFill<tElement>(tElement()));
    return *this;
}


// Set all elements of a matrix to one
template <typename T>
inline CMatrix<T>& CMatrix<T>::ones()
{
    pforEach(mds::base::CFill<tElement>(tElement(1)));
    return *this;
}


// Set a matrix to unit
template <typename T>
inline CMatrix<T>& CMatrix<T>::unit()
{
#pragma omp parallel for schedule(static) default(shared)
    for( tSize i = 0; i < getNumOfRows(); ++i )
    {
        for( tSize j = 0; j < getNumOfCols(); ++j )
        {
            m_Matrix(i, j) = (i == j) ? T(1) : T(0);
        }
    }
    return *this;
}


template <typename T>
inline CMatrix<T>& CMatrix<T>::fill(const T& Value)
{
    pforEach(mds::base::CFill<tElement>(Value));
    return *this;
}


template <typename T>
inline CMatrix<T>& CMatrix<T>::abs()
{
    pforEach(mds::base::CAbs<tElement>());
    return *this;
}


// Matrix multiplication
template <typename T>
inline CMatrix<T>& CMatrix<T>::mult(const CMatrix<T>& m1, const CMatrix<T>& m2)
{
    if( m1.getNumOfCols() != m2.getNumOfRows() || getNumOfRows() != m1.getNumOfRows() || getNumOfCols() != m2.getNumOfCols() )
    {
        throw CMultFailed();
    }

    m_Matrix = m1.asEigen() * m2.asEigen();
    
    return *this;
}


// Compute a matrix transpose
template <typename T>
inline CMatrix<T>& CMatrix<T>::transpose(const CMatrix<T>& Matrix)
{
    if( getNumOfCols() != Matrix.getNumOfRows() || getNumOfRows() != Matrix.getNumOfCols() )
    {
        throw CTransposeFailed();
    }

    m_Matrix = Matrix.asEigen().transpose();

    return *this;
}

