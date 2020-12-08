//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)   \n
 * Copyright (c) 2003-2010 by PGMed@FIT        \n
 *
 * Authors: Miroslav Svub, svub@fit.vutbr.cz   \n
 *          Michal Spanel, spanel@fit.vutbr.cz \n
 * Date:    2007/06/12                         \n
 *
 * $Id:$
 *
 * Description:
 * - Template providing basic sparse matrix operations.
 */

#ifndef MDS_SparseMatrixAlt_H
#define MDS_SparseMatrixAlt_H

#include "mdsMathExceptions.h"
#include "mdsSparseMatrixBase.h"
#include "mdsSparseMatrixAltIterator.h"
#include "mdsVector.h"

// STL
#include <vector>
#include <algorithm>
#include <iostream>


namespace mds
{
namespace math
{

// Declare sparse matrix traits first...
MDS_SPARSE_MATRIX_TRAITS(CSparseMatrixAlt)

//==============================================================================
/*!
 * Template for a two dimensional sparse matrix.
 * - T is a matrix element type.
 *
 * Operations worst case complexity:
 * - get()      O(log(column fill factor))
 * - set()      O(column fill factor)
 * - rmult()    O(number of columns * column fill factor)
 * - lmult()    O(number of columns * column fill factor)
 */
template <typename T>
class CSparseMatrixAlt 
    : public mds::base::CObject
    , public CSparseMatrixBase<CSparseMatrixAlt<T> >
{
public:
    //! Base class.
    typedef CSparseMatrixBase<CSparseMatrixAlt<T> > tBase;

    //! Templates that require members of the CMatrix class can use
    //! this enum to check the existence.
    enum { CLASS_SPARSEMATRIX };

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CSparseMatrixAlt);

    //! Matrix element type
    typedef T tElement;

    //! One entry stored in column constists of row index and value.
    typedef std::pair<tSize, tElement> tEntry;

    //! Sparse matrix column is represented by vector of entries.
    typedef std::vector<tEntry> tColumn;

    //! Whole matrix structure is represented by vector of sparse columns.
    typedef std::vector<tColumn> tSparseMatrix;

    //! Declare iterator types tIterator and tConstIterator.
    MDS_ITERATOR(CSparseMatrixAlt, tElement, CSparseMatrixAltIterator)

public:
    //! Constructor
    inline CSparseMatrixAlt();

    //! Constructor
    inline CSparseMatrixAlt(tSize NumOfRows, tSize NumOfCols);

    //! Constructor, in addition parametrized by dominant value.
    inline CSparseMatrixAlt(tSize NumOfRows,
                            tSize NumOfCols,
                            const tElement& Dominant
                            );

    //! Copy constructor.
    //! - Makes a new copy of the data.
    inline CSparseMatrixAlt(const CSparseMatrixAlt& Matrix);

    //! Destructor
    virtual ~CSparseMatrixAlt();

    //! Creates new matrix of specified dimensions
    inline void create(tSize NumOfRows, tSize NumOfCols);

    //! Creates new matrix of specified dimensions and dominant entry
    inline void create(tSize NumOfRows, 
                       tSize NumOfCols,
                       const tElement& Dominant
                       );

    //! Re-creates the matrix.
    //! - Makes a new copy of the data.
    template <typename Derived>
    inline CSparseMatrixAlt& create(const CSparseMatrixBase<Derived>& Matrix);

    //! Assignment operator.
    inline CSparseMatrixAlt& operator =(const CSparseMatrixAlt& Matrix);
    

    //! Returns the matrix dominant value.
    tElement getDominant() const { return m_Dominant; }

    //! Clears whole matrix
    inline void clear();

    //! Returns the matrix dimensions.
    tSize getNumOfRows() const { return m_NumOfRows; }
    tSize getNumOfCols() const  { return m_NumOfCols; }

    //! Returns the matrix dimensions.
    tSize rows() const { return m_NumOfRows; }
    tSize cols() const  { return m_NumOfCols; }

    //! Returns number of non-dominant elements
    tSize getNumOfNonDominant() const { return m_NumOfNonDominant; }

    //! Method returns reference to the element at (row, col).
    //! If specified element doesn't exist, it is inserted automatically.
    inline tElement& atRef(tSize row, tSize col);

    //! Method returns element (by value) at (row, col). If specified element
    //! doesn't exist, returns dominant value.
    inline tElement at(tSize row, tSize col) const;

    //! Method returns element (by value) at (row, col). If specified element
    //! doesn't exist, it returns dominant value.
    inline tElement operator() (tSize row, tSize col) const;

    //! Method sets value of element at (row, col). if element doesn't exist,
    //! new one is created.
    inline CSparseMatrixAlt& set(tSize row, tSize col, const tElement& el);


    //! Calls a function object for every non-dominant matrix element.
    template <class Function>
    inline Function forEachRef(Function Func);

    //! Calls a function object for every non-dominant matrix element.
    template <class Function>
    inline Function forEach(Function Func) const;

    //! Calls a function object for every non-dominant matrix element.
    //! - Parallel version.
    template <class Function>
    inline Function pforEachRef(Function Func);

    //! Calls a function object for every non-dominant matrix element.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func) const;


    //! Sets all entries in matrix to zero.
    inline CSparseMatrixAlt& zeros();

    //! Sets all elements to one (including non-dominant values).
    inline CSparseMatrixAlt& ones();

    //! Makes the matrix unit.
    inline CSparseMatrixAlt& unit();

    //! Fills the whole matrix using a given value.
    inline CSparseMatrixAlt& fill(const T& Value);

    //! Makes absolute value of all non-dominant elements.
    inline CSparseMatrixAlt& abs();

    //! Matrix vector left multiplication
    inline void lmult(const CVector<T>& vec, CVector<T>& result);

    //! Matrix vector right multiplication
    inline void rmult(const CVector<T>& vec, CVector<T>& result);

    //! Transpose of the matrix.
    inline CSparseMatrixAlt& transpose(const CSparseMatrixAlt&)
    {
        throw mds::base::CNotImplemented();
        return *this;
    }

    //! Stores the sparse matrix as dense.
    inline CSparseMatrixAlt& asDense(CMatrix<T>&)
    {
        throw mds::base::CNotImplemented();
        return *this;
    }

    //! Type of the matrix.
    //! - Returns true if the matrix is square.
    inline bool isSquare() const { return (m_NumOfRows == m_NumOfCols); }

public:
    //! Iterator over non-dominant values of column.
    typedef typename tColumn::iterator tColIterator;

    //! Const iterator over non-dominant values of column.
    typedef typename tColumn::const_iterator tColConstIterator;

    //! Nested function class for comparing two std::pairs according to the first
    //! element instead of lexicographical.
    struct CEntryCompare
    {
        bool operator() (const tEntry& e1, const tEntry& e2)
        {
            return (e1.first < e2.first);
        }
    };

public:
    //! Searches col-th column for index row, returns iterator to that element when
    //! found or iterator to first greater value in case i was not found via it parameter
    inline bool search(tSize row, tSize col, tColIterator& it);
    inline bool search(tSize row, tSize col, tColConstIterator& it) const;

    //! Inserts new element into matrix
    inline void insert(tSize row, tSize col, tColIterator& col_pos, tElement element);

    //! Returns iterator (stl vector iterator) to end of desired column.
    tColIterator getColEnd(tSize col)
    {
        return m_Matrix[col].end();
    }
    tColConstIterator getColEnd(tSize col) const
    {
        return m_Matrix[col].end();
    }

    //! Returns iterator (stl vector iterator) to begining of desired column.
    tColIterator getColBegin(tSize col)
    {
        return m_Matrix[col].begin();
    }
    tColConstIterator getColBegin(tSize col) const
    {
        return m_Matrix[col].begin();
    }

    //! Returns reference to matrix internal entry.
    inline tEntry& getEntry(tSize row, tSize col);
    inline const tEntry& getEntry(tSize row, tSize col) const;

    //! Returns null element of matrix
    tElement* getNull() { return &m_NullEntry.second; }
    const tElement* getNull() const { return &m_NullEntry.second; }

	//! Returns size of col-th column
	tSize getColSize( tSize col ) const { return m_Matrix[col].size(); }

protected:
    //! Internal data storage.
    tSparseMatrix m_Matrix;

    //! Dominant matrix value.
    tElement m_Dominant;

    //! Null matrix entry.
    tEntry m_NullEntry;

    //! Number of rows.
    tSize m_NumOfRows;

    //! Number of columns.
    tSize m_NumOfCols;

    //! Number of nondominant elements.
    tSize m_NumOfNonDominant;
};


//==============================================================================
/*
 * Method templates.
 */

// Include the file containing method templates.
#include "mdsSparseMatrixAlt.hxx"


//==============================================================================
/*
 * Basic type definitions.
 */

//! Matrix of int numbers.
typedef CSparseMatrixAlt<int>                  CISparseMatrixAlt;

//! Matrix of float numbers.
typedef CSparseMatrixAlt<float>                CFSparseMatrixAlt;

//! Matrix of double numbers.
typedef CSparseMatrixAlt<double>               CDSparseMatrixAlt;

//! Matrix of int numbers.
typedef CSparseMatrixAlt<int>::tSmartPtr       CISparseMatrixAltPtr;

//! Matrix of float numbers.
typedef CSparseMatrixAlt<float>::tSmartPtr     CFSparseMatrixAltPtr;

//! Matrix of double numbers.
typedef CSparseMatrixAlt<double>::tSmartPtr    CDSparseMatrixAltPtr;


} // namespace math
} // namespace mds

#endif // MDS_SparseMatrixAlt_H

