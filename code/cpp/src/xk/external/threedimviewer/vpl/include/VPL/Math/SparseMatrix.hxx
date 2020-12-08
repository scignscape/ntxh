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
 * Medical Data Segmentation Toolkit (MDSTk)   \n
 * Copyright (c) 2003-2010 by PGMed@FIT        \n
 *
 * Authors: Miroslav Svub, svub@fit.vutbr.cz   \n
 * Date:    2007/06/12                         \n
 *
 * Description:
 * - Template providing basic sparse matrix operations.
 */


//==============================================================================
/*
 * Methods templates.
 */

template <typename T>
inline CSparseMatrix<T>::CSparseMatrix() : m_Matrix()
{
}


template <typename T>
inline CSparseMatrix<T>::CSparseMatrix(tSize rows, tSize cols)
    : m_Matrix(rows, cols)
{
}


// Copy constructor
template <typename T>
inline CSparseMatrix<T>::CSparseMatrix(const CSparseMatrix<T>& Matrix)
    : vpl::base::CObject()
    , tBase()
    , m_Matrix(Matrix.asEigen())
{
}


template <typename T>
template <typename Derived>
inline CSparseMatrix<T>::CSparseMatrix(const Eigen::SparseMatrixBase<Derived>& Matrix)
{
    m_Matrix = Matrix.template cast<T>();
}


template <typename T>
CSparseMatrix<T>::~CSparseMatrix()
{
}


template <typename T>
inline CSparseMatrix<T>& CSparseMatrix<T>::resize(tSize rows, tSize cols)
{
    m_Matrix.resize(rows, cols);

    return *this;
}


template <typename T>
inline CSparseMatrix<T>& CSparseMatrix<T>::copy(const CSparseMatrix<T>& Matrix)
{
    m_Matrix = Matrix.asEigen();

    return *this;
}


template <typename T>
template <typename Derived>
inline CSparseMatrix<T>& CSparseMatrix<T>::copy(const Eigen::SparseMatrixBase<Derived>& Matrix)
{
    m_Matrix = Matrix.template cast<T>();

    return *this;
}


template <typename T>
template <typename Derived>
inline CSparseMatrix<T>& CSparseMatrix<T>::convert(const CSparseMatrixBase<Derived>& Matrix)
{
    const Derived& MatrixImpl = Matrix.getImpl();

    m_Matrix.resize(MatrixImpl.getNumOfRows(), MatrixImpl.getNumOfCols());

    for( typename Derived::tConstIterator It(MatrixImpl); It; ++It )
    {
        atRef(It.row(), It.col()) = It.value();
    }

    return *this;
}


template <typename T>
inline CSparseMatrix<T>& CSparseMatrix<T>::operator =(const CSparseMatrix<T>& Matrix)
{
    if( &Matrix != this )
    {
        m_Matrix = Matrix.asEigen();
    }

    return *this;
}


template <typename T>
template <typename Derived>
inline CSparseMatrix<T>& CSparseMatrix<T>::operator =(const Eigen::SparseMatrixBase<Derived>& Matrix)
{
    m_Matrix = Matrix.template cast<T>();

    return *this;
}


template <typename T>
inline void CSparseMatrix<T>::clear()
{
    m_Matrix.setZero();
}


template <typename T>
template <class Function>
inline Function CSparseMatrix<T>::forEachRef(Function Func)
{
    for( int k = 0; k < m_Matrix.outerSize(); ++k )
    {
        for( typename tStorage::InnerIterator it(m_Matrix, k); it; ++it )
        {
            Func(it.valueRef());
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CSparseMatrix<T>::forEach(Function Func) const
{
    for( tSize i = 0; i < getNumOfRows(); ++i )
    {
        for( tSize j = 0; j < getNumOfCols(); ++j )
        {
            Func(m_Matrix.coeff(i, j));
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline void CSparseMatrix<T>::pforEachRef(Function Func)
{
#pragma omp parallel for schedule(static) default(shared)
    for( int k = 0; k < m_Matrix.outerSize(); ++k )
    {
        for( typename tStorage::InnerIterator it(m_Matrix, k); it; ++it )
        {
            Func(it.valueRef());
        }
    }
}


template <typename T>
template <class Function>
inline void CSparseMatrix<T>::pforEach(Function Func) const
{
    const tSize rows = getNumOfRows();
    const tSize cols = getNumOfCols();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(rows * cols > VPL_MIN_OMP_COMPLEXITY)
    for( tSize i = 0; i < rows; ++i )
    {
        for( tSize j = 0; j < cols; ++j )
        {
            Func(m_Matrix.coeff(i, j));
        }
    }
}


template <typename T>
inline void CSparseMatrix<T>::lmult(const CVector<T>& vec, CVector<T>& result)
{
    if( vec.getSize() != getNumOfRows() )
    {
        throw CMultFailed();
    }
    
    result.resize(getNumOfCols());
//    result.fill(tElement(0));
    
    result.asEigen() = vec.asEigen() * m_Matrix;
}


template <typename T>
inline void CSparseMatrix<T>::rmult(const CVector<T>& vec, CVector<T>& result)
{
    if( vec.getSize() != getNumOfCols() )
    {
        throw CMultFailed();
    }
    
    result.resize(getNumOfRows());
//    result.fill(tElement(0));
    
    result.asEigen() = m_Matrix * vec.asEigen();
}


template <typename T>
inline CSparseMatrix<T>& CSparseMatrix<T>::zeros()
{
    clear();
    return *this;
}


template <typename T>
inline CSparseMatrix<T>& CSparseMatrix<T>::unit()
{
    clear();
    for( tSize i = 0; i < getNumOfRows(); ++i )
    {
        m_Matrix.insert(i, i) = tElement(1);
    }
    return *this;
}


template <typename T>
inline CSparseMatrix<T>& CSparseMatrix<T>::fill(const T& Value)
{
    pforEachRef(vpl::base::CFill<tElement>(Value));

    return *this;
}


template <typename T>
inline CSparseMatrix<T>& CSparseMatrix<T>::abs()
{
    pforEachRef(vpl::base::CAbs<tElement>());

    return *this;
}


// Compute a matrix transpose
template <typename T>
inline CSparseMatrix<T>& CSparseMatrix<T>::transpose(const CSparseMatrix<T>& Matrix)
{
    if( getNumOfCols() != Matrix.getNumOfRows() || getNumOfRows() != Matrix.getNumOfCols() )
    {
        throw CTransposeFailed();
    }

    m_Matrix = tStorage(Matrix.asEigen().transpose());

    return *this;
}


// Stores the sparse matrix as dense.
template <typename T>
inline CSparseMatrix<T>& CSparseMatrix<T>::asDense(CMatrix<T>& result)
{
    result.asEigen() = m_Matrix;

    return *this;
}
