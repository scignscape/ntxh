//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)   \n
 * Copyright (c) 2003-2011 by PGMed@FIT        \n
 *
 * Authors: Miroslav Svub, svub@fit.vutbr.cz   \n
 *          Michal Spanel, spanel@fit.vutbr.cz \n
 * Date:    2011/05/28                         \n
 *
 * $Id: mdsSparseMatrix.h 2094 2012-02-16 01:54:45Z spanel $
 *
 * Description:
 * - Template providing sparse matrix operations.
 */

#ifndef MDS_SPARSEMATRIX_H
#define MDS_SPARSEMATRIX_H

#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsMathExceptions.h"
#include "mdsSparseMatrixBase.h"
#include "mdsSparseMatrixIterator.h"
#include "mdsVector.h"
#include "mdsMatrix.h"

#include <Eigen/SparseCore>


namespace mds
{
namespace math
{

// Declare sparse matrix traits first...
MDS_SPARSE_MATRIX_TRAITS(CSparseMatrix)

//==============================================================================
/*!
 * Template for a two dimensional sparse matrix.
 * - T is a matrix element type. Only int, usnigned int, float, double,
 *   std::complex<> and mds::math::CComplex<> types are supported.
 * - Do not use get() for traversal, use tIterator or forEach() instead!
 * - Dominant value of the sparse matrix is T(0).
 */
template <typename T>
class CSparseMatrix : public mds::base::CObject, public CSparseMatrixBase<CSparseMatrix<T> >
{
public:
    //! Base class.
    typedef CSparseMatrixBase<CSparseMatrix<T> > tBase;

    //! Templates that require members of the CMatrix class can use
    //! this enum to check the existence.
    enum { CLASS_SPARSEMATRIX };

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CSparseMatrix);

    //! Matrix element type
    typedef T tElement;

    //! Underlying matrix data (see the Eigen library).
    typedef Eigen::SparseMatrix<tElement, Eigen::ColMajor> tStorage;

    //! Declare iterator types tIterator and tConstIterator.
    MDS_ITERATOR(CSparseMatrix, tElement, CSparseMatrixIterator)

public:
    //! Default constructor.
    inline CSparseMatrix();

    //! Constructor.
    inline CSparseMatrix(tSize NumOfRows, tSize NumOfCols);

    //! Copy constructor.
    //! - Makes a new copy of the data.
    inline CSparseMatrix(const CSparseMatrix& Matrix);

    //! Constructor.
    template <typename Derived>
    inline CSparseMatrix(const Eigen::SparseMatrixBase<Derived>& Matrix);

    //! Destructor
    virtual ~CSparseMatrix();

    //! Creates new matrix of specified dimensions
    inline CSparseMatrix& create(tSize NumOfRows, tSize NumOfCols);
    
    //! Re-creates the matrix.
    //! - Makes a new copy of the data.
    template <typename Derived>
    inline CSparseMatrix& create(const CSparseMatrixBase<Derived>& Matrix);

    //! Re-creates the matrix.
    //! - Makes a new copy of the data.
    template <typename Derived>
    inline CSparseMatrix& create(const Eigen::SparseMatrixBase<Derived>& Matrix);

    //! Assignment operator.
    inline CSparseMatrix& operator =(const CSparseMatrix& Matrix);
    
    //! Assignment operator.
    template <typename Derived>
    inline CSparseMatrix& operator =(const Eigen::SparseMatrixBase<Derived>& Matrix);
    
    
    //! Returns reference to the underlying matrix data (see the Eigen library).
    tStorage& asEigen() { return m_Matrix; }
    const tStorage& asEigen() const { return m_Matrix; }

    //! Returns matrix dominant value (i.e. zero).
    tElement getDominant() { return T(0); }

    //! Clears the whole matrix (i.e. removes all non zeros).
    inline void clear();

    //! Returns the matrix dimensions.
    tSize getNumOfRows() const { return m_Matrix.rows(); }
    tSize getNumOfCols() const { return m_Matrix.cols(); }

    //! Returns the matrix dimensions.
    tSize rows() const { return m_Matrix.rows(); }
    tSize cols() const { return m_Matrix.rows(); }

    //! Returns number of non-dominant (i.e. non-zero) elements.
    tSize getNumOfNonDominant() const { return m_Matrix.nonZeros(); }

    //! Method returns reference to the element at (row, col).
    //! If specified element doesn't exist, it is inserted automatically.
    inline tElement& atRef(tSize row, tSize col)
    {
        return m_Matrix.coeffRef(row, col);
    }

    //! Method returns element (by value) at (row, col). If specified element
    //! doesn't exist, returns the dominant value.
    inline tElement at(tSize row, tSize col) const
    {
        return m_Matrix.coeff(row, col);
    }

    //! Method returns element (by value) at (row, col). If specified element
    //! doesn't exist, it returns dominant value.
    inline tElement operator() (tSize row, tSize col) const
    {
        return m_Matrix.coeff(row, col);
    }

    //! Method sets value of element at (row, col). if element doesn't exist,
    //! new one is created.
    inline CSparseMatrix& set(tSize row, tSize col, const tElement& el)
    {
        m_Matrix.coeffRef(row, col) = el;
        return *this;
    }


    //! Calls a function object for every non-zero matrix element.
    template <class Function>
    inline Function forEachRef(Function Func);

    //! Calls a function object for every non-zero matrix element.
    template <class Function>
    inline Function forEach(Function Func) const;

    //! Calls a function object for every non-zero matrix element.
    //! - Parallel version.
    template <class Function>
    inline Function pforEachRef(Function Func);

    //! Calls a function object for every non-zero matrix element.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func) const;


    //! Sets all entries in matrix to zero.
    inline CSparseMatrix& zeros();

    //! Makes the matrix unit.
    inline CSparseMatrix& unit();

    //! Changes value of all non-dominant (i.e. non-zero) coefficients.
    inline CSparseMatrix& fill(const T& Value);

    //! Makes absolute value of all non-dominant (i.e. non-zero) elements.
    inline CSparseMatrix& abs();

    //! Matrix vector left multiplication
    inline void lmult(const CVector<T>& vec, CVector<T>& result);

    //! Matrix vector right multiplication
    inline void rmult(const CVector<T>& vec, CVector<T>& result);

    //! Transpose of the matrix.
    inline CSparseMatrix& transpose(const CSparseMatrix & Matrix);

    //! Stores the sparse matrix as dense.
    inline CSparseMatrix& asDense(CMatrix<T>& result);

    //! Type of the matrix.
    //! - Returns true if the matrix is square.
    inline bool isSquare() const { return (m_Matrix.rows() == m_Matrix.cols()); }

protected:
    //! Internal data storage.
    tStorage m_Matrix;
};


//==============================================================================
/*
 * Method templates.
 */

// Include the file containing method templates.
#include "mdsSparseMatrix.hxx"


//==============================================================================
/*
 * Basic type definitions.
 */

//! Matrix of int numbers.
typedef CSparseMatrix<int>                  CISparseMatrix;

//! Matrix of float numbers.
typedef CSparseMatrix<float>                CFSparseMatrix;

//! Matrix of double numbers.
typedef CSparseMatrix<double>               CDSparseMatrix;

//! Matrix of int numbers.
typedef CSparseMatrix<int>::tSmartPtr       CISparseMatrixPtr;

//! Matrix of float numbers.
typedef CSparseMatrix<float>::tSmartPtr     CFSparseMatrixPtr;

//! Matrix of double numbers.
typedef CSparseMatrix<double>::tSmartPtr    CDSparseMatrixPtr;


} // namespace math
} // namespace mds

#endif // MDS_SPARSEMATRIX_H

