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
 *          Michal Spanel, spanel@fit.vutbr.cz \n
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
inline CSparseMatrixAlt<T>::CSparseMatrixAlt()
    : m_Matrix()
    , m_Dominant(T(0))
    , m_NumOfRows(0)
    , m_NumOfCols(0)
    , m_NumOfNonDominant(0)
{
}


template <typename T>
inline CSparseMatrixAlt<T>::CSparseMatrixAlt(tSize rows, tSize cols)
    : m_Matrix(cols)
    , m_Dominant()
    , m_NumOfRows(rows)
    , m_NumOfCols(cols)
    , m_NumOfNonDominant(0)
{
}


template <typename T>
inline CSparseMatrixAlt<T>::CSparseMatrixAlt(tSize rows, tSize cols, const tElement& dom)
    : m_Matrix(cols)
    , m_Dominant(dom)
    , m_NumOfRows(rows)
    , m_NumOfCols(cols)
    , m_NumOfNonDominant(0)
{
}


// Copy constructor
template <typename T>
inline CSparseMatrixAlt<T>::CSparseMatrixAlt(const CSparseMatrixAlt& Matrix)
    : vpl::base::CObject()
    , tBase()
    , m_Matrix(Matrix.m_Matrix)
    , m_Dominant(Matrix.m_Dominant)
    , m_NumOfRows(Matrix.m_NumOfRows)
    , m_NumOfCols(Matrix.m_NumOfCols)
    , m_NumOfNonDominant(Matrix.m_NumOfNonDominant)
{
}


template <typename T>
CSparseMatrixAlt<T>::~CSparseMatrixAlt()
{
}


template <typename T>
inline void CSparseMatrixAlt<T>::resize(tSize rows, tSize cols)
{
    clear();

    m_NumOfCols = cols;
    m_NumOfRows = rows;

    m_Matrix.resize(cols);
}


template <typename T>
inline void CSparseMatrixAlt<T>::resize(tSize rows, tSize cols, const tElement& dominant)
{
    clear();

    m_NumOfCols = cols;
    m_NumOfRows = rows;
    m_Dominant = dominant;

    m_Matrix.resize(cols);
}


template <typename T>
inline CSparseMatrixAlt<T>& CSparseMatrixAlt<T>::copy(const CSparseMatrixAlt<T>& Matrix)
{
    m_Matrix = Matrix.m_Matrix;
    m_Dominant = Matrix.m_Dominant;
    m_NumOfRows = Matrix.m_NumOfRows;
    m_NumOfCols = Matrix.m_NumOfCols;
    m_NumOfNonDominant = Matrix.m_NumOfNonDominant;

    return *this;
}


template <typename T>
template <typename Derived>
inline CSparseMatrixAlt<T>& CSparseMatrixAlt<T>::convert(const CSparseMatrixBase<Derived>& Matrix)
{
    const Derived& MatrixImpl = Matrix.getImpl();

    clear();

    m_NumOfCols = MatrixImpl.getNumOfCols();
    m_NumOfRows = MatrixImpl.getNumOfRows();
    m_Dominant = MatrixImpl.getDominant();

    for( typename Derived::tConstIterator It(MatrixImpl); It; ++It )
    {
        atRef(It.row(), It.col()) = It.value();
    }
}


template <typename T>
inline CSparseMatrixAlt<T>& CSparseMatrixAlt<T>::operator =(const CSparseMatrixAlt<T>& Matrix)
{
    if( &Matrix != this )
    {
        copy(Matrix);
    }

    return *this;
}


template <typename T>
inline void CSparseMatrixAlt<T>::clear()
{
    for( tSize i = 0; i < m_NumOfCols; i++ )
    {
        m_Matrix[i].erase(m_Matrix[i].begin(), m_Matrix[i].end());
    }
    m_NumOfNonDominant = 0;
}


template <typename T>
inline typename CSparseMatrixAlt<T>::tElement CSparseMatrixAlt<T>::at(tSize row, tSize col) const
{
    tColConstIterator position;
    if( search(row, col, position) )
    {
        return position->second;
    }
    else
    {
        return m_Dominant;
    }
}


template <typename T>
inline typename CSparseMatrixAlt<T>::tElement& CSparseMatrixAlt<T>::atRef(tSize row, tSize col)
{
    tColIterator position;
    if( !search(row, col, position) )
    {
        insert(row, col, position, m_Dominant);
        ++m_NumOfNonDominant;
    }
    return position->second;
}


template <typename T>
inline typename CSparseMatrixAlt<T>::tElement CSparseMatrixAlt<T>::operator() (tSize row, tSize col) const
{
    return at(row, col);
}


template <typename T>
inline CSparseMatrixAlt<T>& CSparseMatrixAlt<T>::set(tSize row, tSize col, const tElement& el)
{
    tColIterator position;
    if( search(row, col, position) )
    {
        position->second = el;
    }
    else
    {
        insert(row, col, position, el);
        ++m_NumOfNonDominant;
    }
    return *this;
}


template <typename T>
template <class Function>
inline Function CSparseMatrixAlt<T>::forEachRef(Function Func)
{
    for( tSize i = 0; i < m_NumOfCols; ++i )
    {
        tColIterator itEnd = getColEnd(i);
        for( tColIterator it = getColBegin(i); it != itEnd; ++it )
        {
            Func(it->second);
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CSparseMatrixAlt<T>::forEach(Function Func) const
{
    for( tSize i = 0; i < m_NumOfCols; ++i )
    {
        tColConstIterator itEnd = getColEnd(i);
        for( tColConstIterator it = getColBegin(i); it != itEnd; ++it )
        {
            Func(it->second);
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline void CSparseMatrixAlt<T>::pforEachRef(Function Func)
{
    const tSize rows = getNumOfRows();
    const tSize cols = getNumOfCols();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(rows * cols > VPL_MIN_OMP_COMPLEXITY)
    for( tSize i = 0; i < cols; ++i )
    {
        tColIterator itEnd = getColEnd(i);
        for( tColIterator it = getColBegin(i); it != itEnd; ++it )
        {
            Func(it->second);
        }
    }
}


template <typename T>
template <class Function>
inline void CSparseMatrixAlt<T>::pforEach(Function Func) const
{
    const tSize rows = getNumOfRows();
    const tSize cols = getNumOfCols();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(rows * cols > VPL_MIN_OMP_COMPLEXITY)
    for( tSize i = 0; i < cols; ++i )
    {
        tColConstIterator itEnd = getColEnd(i);
        for( tColConstIterator it = getColBegin(i); it != itEnd; ++it )
        {
            Func(it->second);
        }
    }
}


template <typename T>
inline void CSparseMatrixAlt<T>::lmult(const CVector<T>& vec, CVector<T>& result)
{
    if( vec.getSize() != m_NumOfRows )
    {
        throw CMultFailed();
    }
    
    result.resize(m_NumOfCols);
    result.fill(tElement(0));
    
    if( m_Dominant == tElement(0) )
    {
#pragma omp parallel for schedule(static) default(shared)
        for( tSize i = 0; i < m_NumOfCols; ++i )
        {
            tColIterator itEnd = getColEnd(i);
            for( tColIterator it = getColBegin(i); it != itEnd; ++it )
            {
                result(i) = result(i) + it->second * vec(it->first);
            }
        }
    }
}


template <typename T>
inline void CSparseMatrixAlt<T>::rmult(const CVector<T>& vec, CVector<T>& result)
{
    if( vec.getSize() != m_NumOfCols )
    {
        throw CMultFailed();
    }
    
    result.resize(m_NumOfCols);
    result.fill(tElement(0));
    
    if( m_Dominant == tElement(0) )
    {
#pragma omp parallel for schedule(static) default(shared)
        for( tSize i = 0; i < m_NumOfCols; ++i )
        {
            tColIterator itEnd = getColEnd(i);
            for( tColIterator it = getColBegin(i); it != itEnd; ++it )
            {
                result(it->first) = result(it->first) + vec(i) * it->second;
            }
        }
    }
}


template <typename T>
inline CSparseMatrixAlt<T>& CSparseMatrixAlt<T>::zeros()
{
    clear();
    m_Dominant = tElement(0);
    return *this;
}


template <typename T>
inline CSparseMatrixAlt<T>& CSparseMatrixAlt<T>::ones()
{
    clear();
    m_Dominant = tElement(1);
    return *this;
}


template <typename T>
inline CSparseMatrixAlt<T>& CSparseMatrixAlt<T>::unit()
{
    clear();
    for( tSize i = 0; i < m_NumOfCols; ++i )
    {
        m_Matrix[i].push_back(tEntry(i, tElement(1)));
    }
    m_NumOfNonDominant = m_NumOfCols;
    return *this;
}


template <typename T>
inline CSparseMatrixAlt<T>& CSparseMatrixAlt<T>::fill(const T& Value)
{
    clear();
    m_Dominant = Value;
    return *this;
}


template <typename T>
inline CSparseMatrixAlt<T>& CSparseMatrixAlt<T>::abs()
{
    pforEachRef(vpl::base::CAbs<tElement>());
    return *this;
}


template <typename T>
inline bool CSparseMatrixAlt<T>::search(tSize row, tSize col, tColIterator& it)
{
    typedef std::pair<tColIterator, tColIterator> tBounds;
    
    if( col >= m_NumOfCols )
    {
        return false;
    }

    // perform binary search and return iterator pair marking result
    tBounds bounds = std::equal_range(m_Matrix[col].begin(),
                                      m_Matrix[col].end(),
                                      tEntry(row, tElement(0)),
                                      CEntryCompare()
                                      );
    
    if( bounds.first == bounds.second ) // not found
    {
        it = bounds.second; // it points to first element with row index greater than desired
        return false;
    }
    else
    {
        it = bounds.first; // it points to found element
        return true;
    }
}


template <typename T>
inline bool CSparseMatrixAlt<T>::search(tSize row, tSize col, tColConstIterator& it) const
{
    typedef std::pair<tColConstIterator, tColConstIterator> tBounds;

    if( col >= m_NumOfCols )
    {
        return false;
    }
   
    // perform binary search and return iterator pair marking result
    tBounds bounds = std::equal_range(m_Matrix[col].begin(),
                                      m_Matrix[col].end(),
                                      tEntry(row, tElement(0)),
                                      CEntryCompare()
                                      );
    
    if( bounds.first == bounds.second ) // not found
    {
        it = bounds.second; // it points to first element with row index greater than desired
        return false;
    }
    else
    {
        it = bounds.first; // it points to found element
        return true;
    }
}


template <typename T>
inline void CSparseMatrixAlt<T>::insert(tSize row,
                                     tSize col,
                                     tColIterator& col_pos,
                                     tElement element
                                     )
{
    if( col >= m_NumOfCols )
    {
        return;
    }

    m_Matrix[col].insert(col_pos, tEntry(row, element));
}


template <typename T>
inline typename CSparseMatrixAlt<T>::tEntry & CSparseMatrixAlt<T>::getEntry(tSize row, tSize col)
{
    tColIterator it;
    if( this->search(row, col, it) ) return *it;
    else return m_NullEntry;
}


template <typename T>
inline const typename CSparseMatrixAlt<T>::tEntry & CSparseMatrixAlt<T>::getEntry(tSize row, tSize col) const
{
    tColConstIterator it;
    if( this->search(row, col, it) ) return *it;
    else return m_NullEntry;
}
