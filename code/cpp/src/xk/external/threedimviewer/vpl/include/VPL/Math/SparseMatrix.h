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
 * Copyright (c) 2003-2011 by PGMed@FIT        \n
 *
 * Authors: Miroslav Svub, svub@fit.vutbr.cz   \n
 *          Michal Spanel, spanel@fit.vutbr.cz \n
 * Date:    2011/05/28                         \n
 *
 * Description:
 * - Template providing sparse matrix operations.
 */

#ifndef VPL_SPARSEMATRIX_H
#define VPL_SPARSEMATRIX_H

#include <VPL/Base/SharedPtr.h>

#include "MathExceptions.h"
#include "SparseMatrixBase.h"
#include "SparseMatrixIterator.h"
#include "Vector.h"
#include "Matrix.h"

#ifndef EIGEN_YES_I_KNOW_SPARSE_MODULE_IS_NOT_STABLE_YET
#    define EIGEN_YES_I_KNOW_SPARSE_MODULE_IS_NOT_STABLE_YET
#endif
#include <Eigen/Sparse>


namespace vpl
{
namespace math
{

// Declare sparse matrix traits first...
VPL_SPARSE_MATRIX_TRAITS(CSparseMatrix)

//==============================================================================
/*!
 * Template for a two dimensional sparse matrix.
 * - T is a matrix element type. Only int, usnigned int, float, double,
 *   std::complex<> and vpl::math::CComplex<> types are supported.
 * - Never use at() for traversal, use tIterator or forEach() instead!
 * - Dominant value of the sparse matrix is T(0).
 * - This class uses Eigen structers for the underlying matrix data
 *   (see the Eigen library).
 */
template <typename T>
class CSparseMatrix : public vpl::base::CObject, public CSparseMatrixBase<CSparseMatrix<T> >
{
public:
    //! Base class.
    typedef CSparseMatrixBase<CSparseMatrix<T> > tBase;

    //! Templates that require members of the CMatrix class can use
    //! this enum to check the existence.
    enum { CLASS_SPARSEMATRIX };

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CSparseMatrix);

    //! Matrix element type
    typedef T tElement;

    //! Underlying matrix data (see the Eigen library).
    typedef Eigen::SparseMatrix<tElement, Eigen::ColMajor> tStorage;

    //! Declare iterator types tIterator and tConstIterator.
    VPL_ITERATOR(CSparseMatrix, tElement, CSparseMatrixIterator)

public:
    //! Default constructor.
    inline CSparseMatrix();

    //! Constructor initializes sparse matrix of specified dimensions.
    inline CSparseMatrix(tSize NumOfRows, tSize NumOfCols);

    //! Copy constructor.
    //! - Makes a new copy of the data.
    inline CSparseMatrix(const CSparseMatrix& Matrix);

    //! Constructor makes a copy of the given matrix.
    template <typename Derived>
    inline CSparseMatrix(const Eigen::SparseMatrixBase<Derived>& Matrix);

    //! Destructor
    virtual ~CSparseMatrix();

    //! Resizes the matrix to specified dimensions.
    inline CSparseMatrix& resize(tSize NumOfRows, tSize NumOfCols);
    
    //! Makes a new copy of the given matrix.
    inline CSparseMatrix& copy(const CSparseMatrix& Matrix);

    //! Makes a new copy of the given matrix.
    template <typename Derived>
    inline CSparseMatrix& copy(const Eigen::SparseMatrixBase<Derived>& Matrix);

    //! Assignment operator.
    //! - Makes copy of a matrix into another and resizes the matrix
    //!   on the left-hand side automatically so that it matches
    //!   the size of the matrix on the right-hand size.
    inline CSparseMatrix& operator =(const CSparseMatrix& Matrix);
    
    //! Assignment operator.
    //! - Makes copy of a matrix into another and resizes the matrix
    //!   on the left-hand side automatically so that it matches
    //!   the size of the matrix on the right-hand size.
    template <typename Derived>
    inline CSparseMatrix& operator =(const Eigen::SparseMatrixBase<Derived>& Matrix);

    //! Converts sparse matrix of one type to another one.
    template <typename Derived>
    inline CSparseMatrix& convert(const CSparseMatrixBase<Derived>& Matrix);

    
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
    inline void pforEachRef(Function Func);

    //! Calls a function object for every non-zero matrix element.
    //! - Parallel version.
    template <class Function>
    inline void pforEach(Function Func) const;


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
#include "SparseMatrix.hxx"


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
} // namespace vpl

#endif // VPL_SPARSEMATRIX_H

