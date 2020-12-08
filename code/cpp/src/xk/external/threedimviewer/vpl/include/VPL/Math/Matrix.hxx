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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/03                          \n
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
    VPL_ASSERT(Row >= 0 && NumOfRows >= 0 && Row < Matrix.getNumOfRows()
               && Col >= 0 && NumOfCols >= 0 && Col < Matrix.getNumOfCols()
               );

    // Copy the data
    m_Matrix = Matrix.asEigen().block(Row, Col, NumOfRows, NumOfCols);
}


// Copy constructor
template <typename T>
inline CMatrix<T>::CMatrix(const CMatrix<T>& Matrix)
    : vpl::base::CObject()
    , tBase()
    , m_Matrix(Matrix.asEigen())
{
}


template <typename T>
template <typename Derived>
inline CMatrix<T>::CMatrix(const Eigen::MatrixBase<Derived>& Matrix)
    : m_Matrix(Matrix.template cast<T>())
{
}


template <typename T>
CMatrix<T>::~CMatrix()
{
}


template <typename T>
inline CMatrix<T>& CMatrix<T>::resize(tSize NumOfRows, tSize NumOfCols)
{
    m_Matrix.resize(NumOfRows, NumOfCols);

    return *this;
}


template <typename T>
inline CMatrix<T>& CMatrix<T>::copy(const CMatrix<T>& Matrix,
                                    tSize Row,
                                    tSize Col,
                                    tSize NumOfRows,
                                    tSize NumOfCols
                                    )
{
    // Check the position
    VPL_CHECK(Row >= 0 && NumOfRows >= 0 && Row < Matrix.getNumOfRows()
              && Col >= 0 && NumOfCols >= 0 && Col < Matrix.getNumOfCols(), return *this);

    // Copy the data
    m_Matrix = Matrix.asEigen().block(Row, Col, NumOfRows, NumOfCols);

    return *this;
}


template <typename T>
inline CMatrix<T>& CMatrix<T>::copy(const CMatrix& Matrix)
{
    m_Matrix = Matrix.asEigen();

    return *this;
}


template <typename T>
template <typename Derived>
inline CMatrix<T>& CMatrix<T>::copy(const Eigen::MatrixBase<Derived>& Matrix)
{
    m_Matrix = Matrix.template cast<T>();

    return *this;
}


template <typename T>
template <typename Derived>
inline CMatrix<T>& CMatrix<T>::convert(const CMatrixBase<Derived>& Matrix)
{
    m_Matrix.resize(Matrix.getNumOfRows(), Matrix.getNumOfCols());

    for( tSize j = 0; j < Matrix.getNumOfRows(); ++j )
    {
        for( tSize i = 0; i < Matrix.getNumOfCols(); ++i )
        {
            m_Matrix.coeffRef(j, i) = Matrix.at(j, i);
        }
    }

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
    m_Matrix = Matrix.template cast<T>();

    return *this;
}


// Combined addition and assignment operator
template <typename T>
inline CMatrix<T>& CMatrix<T>::operator +=(const CMatrix<T>& Matrix)
{
    m_Matrix += Matrix.asEigen();

    return *this;
}


// Combined subtraction and assignment operator
template <typename T>
inline CMatrix<T>& CMatrix<T>::operator -=(const CMatrix<T>& Matrix)
{
    m_Matrix -= Matrix.asEigen();

    return *this;
}


// Combined scalar multiplication and assignment operator
template <typename T>
inline CMatrix<T>& CMatrix<T>::operator *=(const CMatrix<T>& Matrix)
{
    tSize NumOfRows = vpl::math::getMin(getNumOfRows(), Matrix.getNumOfRows());
    tSize NumOfCols = vpl::math::getMin(getNumOfCols(), Matrix.getNumOfCols());

    for( tSize j = 0; j < NumOfRows; ++j )
    {
        vpl::sys::memVectMult(getPtr() + j * getRowOffset(),
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
    tSize NumOfRows = vpl::math::getMin(getNumOfRows(), Matrix.getNumOfRows());
    tSize NumOfCols = vpl::math::getMin(getNumOfCols(), Matrix.getNumOfCols());

    for( tSize j = 0; j < NumOfRows; ++j )
    {
        vpl::sys::memVectDiv(getPtr() + j * getRowOffset(),
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
    pforEach(vpl::base::CMult<tElement,U>(c.value()));

    return *this;
}


// Combined scalar division and assignment operator
template <typename T>
template <typename U>
inline CMatrix<T>& CMatrix<T>::operator /=(const CScalar<U>& c)
{
    pforEach(vpl::base::CDiv<tElement,U>(c.value()));

    return *this;
}


// Combined scalar addition and assignment operator
template <typename T>
template <typename U>
inline CMatrix<T>& CMatrix<T>::operator +=(const CScalar<U>& c)
{
    pforEach(vpl::base::CAdd<tElement>(tElement(c.value())));

    return *this;
}


// Combined scalar subtraction and assignment operator
template <typename T>
template <typename U>
inline CMatrix<T>& CMatrix<T>::operator -=(const CScalar<U>& c)
{
    pforEach(vpl::base::CSub<tElement>(tElement(c.value())));

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
inline void CMatrix<T>::pforEach(Function Func)
{
	const tSize rows = getNumOfRows();
	const tSize cols = getNumOfCols();
	const tSize offset = getRowOffset();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(rows * cols > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < rows; ++j )
    {
        tElement *p = getPtr() + j * offset;
        for( tSize i = 0; i < cols; ++i, ++p )
        {
            Func(*p);
        }
    }
}


template <typename T>
template <class Function>
inline void CMatrix<T>::pforEach(Function Func) const
{
	const tSize rows = getNumOfRows();
	const tSize cols = getNumOfCols();
	const tSize offset = getRowOffset();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(rows * cols > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < rows; ++j )
    {
        const tElement *p = getPtr() + j * offset;
        for( tSize i = 0; i < cols; ++i, ++p )
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
    pforEach(vpl::base::CFill<tElement>(tElement()));
    return *this;
}


// Set all elements of a matrix to one
template <typename T>
inline CMatrix<T>& CMatrix<T>::ones()
{
    pforEach(vpl::base::CFill<tElement>(tElement(1)));
    return *this;
}


// Set a matrix to unit
template <typename T>
inline CMatrix<T>& CMatrix<T>::unit()
{
	const tSize rows = getNumOfRows();
	const tSize cols = getNumOfCols();
	const T zero(0);
	const T one(1);

#pragma omp parallel for schedule(static) default(none) if(rows * cols > VPL_MIN_OMP_COMPLEXITY)
    for( tSize i = 0; i < rows; ++i )
    {
        for( tSize j = 0; j < cols; ++j )
        {
            m_Matrix(i, j) = (i == j) ? one : zero;
        }
    }
    return *this;
}


template <typename T>
inline CMatrix<T>& CMatrix<T>::fill(const T& Value)
{
    pforEach(vpl::base::CFill<tElement>(Value));
    return *this;
}


template <typename T>
inline CMatrix<T>& CMatrix<T>::abs()
{
    pforEach(vpl::base::CAbs<tElement>());
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

