//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)   \n
 * Copyright (c) 2003-2010 by PGMed@FIT        \n
 *
 * Authors: Miroslav Svub, svub@fit.vutbr.cz   \n
 * Date:    2007/06/12                         \n
 *
 * $Id: mdsSparseMatrix.hxx 2093 2012-02-16 00:32:09Z spanel $
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
    : mds::base::CObject()
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
inline CSparseMatrix<T>& CSparseMatrix<T>::create(tSize rows, tSize cols)
{
    m_Matrix.resize(rows, cols);

    return *this;
}


template <typename T>
template <typename Derived>
inline CSparseMatrix<T>& CSparseMatrix<T>::create(const CSparseMatrixBase<Derived>& Matrix)
{
    m_Matrix.resize(Matrix.getNumOfRows(), Matrix.getNumOfCols());

    for( tSize j = 0; j < Matrix.getNumOfRows(); ++j )
    {
        for( tSize i = 0; i < Matrix.getNumOfCols(); ++i )
        {
            m_Matrix.insert(j, i) = Matrix.at(j, i);
        }
    }

    return *this;
}


template <typename T>
template <typename Derived>
inline CSparseMatrix<T>& CSparseMatrix<T>::create(const Eigen::SparseMatrixBase<Derived>& Matrix)
{
    m_Matrix = Matrix.template cast<T>();

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
inline Function CSparseMatrix<T>::pforEachRef(Function Func)
{
#pragma omp parallel for schedule(static) default(shared)
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
inline Function CSparseMatrix<T>::pforEach(Function Func) const
{
#pragma omp parallel for schedule(static) default(shared)
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
inline void CSparseMatrix<T>::lmult(const CVector<T>& vec, CVector<T>& result)
{
    if( vec.getSize() != getNumOfRows() )
    {
        throw CMultFailed();
    }
    
    result.create(getNumOfCols());
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
    
    result.create(getNumOfRows());
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
    pforEachRef(mds::base::CFill<tElement>(Value));

    return *this;
}


template <typename T>
inline CSparseMatrix<T>& CSparseMatrix<T>::abs()
{
    pforEachRef(mds::base::CAbs<tElement>());

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
