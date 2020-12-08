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
 * Copyright (c) 2003-2010 by Michal Spanel    \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz \n
 * Date:    2003/12/03                         \n
 *
 * Description:
 * - Class template providing basic matrix operations.
 */

#ifndef VPL_MATRIX_H
#define VPL_MATRIX_H

#include <VPL/Base/SharedPtr.h>

#include "MathExceptions.h"
#include "MatrixBase.h"
#include "StaticMatrix.h"


namespace vpl
{
namespace math
{

// Declare matrix traits first...
VPL_MATRIX_TRAITS(CMatrix)

//==============================================================================
/*!
 * Class template for a two dimensional dense matrix stored in row-major format.
 * - T is a matrix element type. Only int, usnigned int, float, double,
 *   std::complex<> and vpl::math::CComplex<> types are supported.
 * - This class uses Eigen structers for the underlying matrix data
 *   (see the Eigen library).
 */
template <typename T>
class CMatrix : public vpl::base::CObject, public CMatrixBase<CMatrix<T> >
{
public:
    //! Base class.
    typedef CMatrixBase<CMatrix<T> > tBase;

    //! Templates that require members of the CMatrix class can use
    //! this enum to check the existence.
    enum { CLASS_MATRIX };

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CMatrix);

    //! Matrix element type.
    typedef T tElement;

    //! Underlying matrix data (see the Eigen library).
    typedef Eigen::Matrix<tElement, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor | Eigen::AutoAlign> tStorage;

    //! Declare iterators.
    //! - Adds types tIterator and tConstIterator.
    VPL_ITERATOR(CMatrix, tElement, CMatrixIterator)

public:
    //! Default constructor.
    inline CMatrix();

    //! Constructor creates matrix of given dimensions.
    inline CMatrix(tSize NumOfRows, tSize NumOfCols);

    //! Constructor makes a copy of a part of the given source the matrix.
    inline CMatrix(const CMatrix& Matrix,
                   tSize Row,
                   tSize Col,
                   tSize NumOfRows,
                   tSize NumOfCols
                   );

    //! Copy constructor.
    //! - Makes a new copy of the data.
    inline CMatrix(const CMatrix& Matrix);

    //! Constructor.
    //! - Makes a new copy of the data.
    template <typename Derived>
    inline CMatrix(const Eigen::MatrixBase<Derived>& Matrix);

    //! Virtual destructor.
    virtual ~CMatrix();

    //! Resizes the matrix if needed.
    //! - This operation is destructive, the values of the coefficients may change.
    inline CMatrix& resize(tSize NumOfRows, tSize NumOfCols);

    //! Makes a copy of a part of the given source the matrix.
    inline CMatrix& copy(const CMatrix& Matrix,
                         tSize Row,
                         tSize Col,
                         tSize NumOfRows,
                         tSize NumOfCols
                         );

    //! Makes a copy of the source the matrix.
    inline CMatrix& copy(const CMatrix& Matrix);
    
    //! Makes copy of a matrix into another.
    //! - Resizes the matrix on the left-hand side automatically
    //!   so that it matches the size of the matrix on the right-hand size.
    template <typename Derived>
    inline CMatrix& copy(const Eigen::MatrixBase<Derived>& Matrix);

    //! Assignment operator.
    //! - Makes copy of a matrix into another and resizes the matrix
    //!   on the left-hand side automatically so that it matches
    //!   the size of the matrix on the right-hand size.
    inline CMatrix& operator =(const CMatrix& Matrix);
    
    //! Assignment operator.
    //! - Makes copy of a matrix into another and resizes the matrix
    //!   on the left-hand side automatically so that it matches
    //!   the size of the matrix on the right-hand size.
    template <typename Derived>
    inline CMatrix& operator =(const Eigen::MatrixBase<Derived>& Matrix);

    //! Conversion of vectors of different type.
    //! - Makes a new copy of the data.
    template <typename Derived>
    inline CMatrix& convert(const CMatrixBase<Derived>& Matrix);


    //! Returns reference to the underlying matrix data (see the Eigen library).
    tStorage& asEigen() { return m_Matrix; }
    const tStorage& asEigen() const { return m_Matrix; }

    //! Returns the matrix dimensions.
    tSize getNumOfRows() const { return m_Matrix.rows(); }
    tSize getNumOfCols() const { return m_Matrix.cols(); }

    //! Returns the matrix dimensions.
    tSize rows() const { return m_Matrix.rows(); }
    tSize cols() const { return m_Matrix.rows(); }

    //! Returns row offset. In other words, offset between two neighbouring
    //! elements in a matrix column.
    tSize getRowOffset() const { return m_Matrix.stride(); }

    //! Returns column offset. In other words, offset between two neighbouring
    //! elements in a matrix row.
    tSize getColOffset() const { return 1; }

    //! Returns reference to the element [Row][Col].
    T& at(tSize Row, tSize Col)
    {
        return m_Matrix.coeffRef(Row, Col);
    }
    const T& at(tSize Row, tSize Col) const
    {
        return m_Matrix.coeff(Row, Col);
    }

    //! Returns reference to the element [Row][Col].
    T& operator() (tSize Row, tSize Col)
    {
        return m_Matrix.coeffRef(Row, Col);
    }
    const T& operator() (tSize Row, tSize Col) const
    {
        return m_Matrix.coeff(Row, Col);
    }

    //! Sets the element of matrix at the position [row][col].
    CMatrix& set(tSize Row, tSize Col, const T& Value)
    {
        m_Matrix.coeffRef(Row, Col) = Value;
        return *this;
    }


    //! Calculates index of a specified pixel.
    tSize getIdx(tSize Row, tSize Col) const
    {
        return Row * getRowOffset() + Col;
    }

    //! Returns the subscripted pixel.
    T& operator ()(tSize i)
    {
        return *(getPtr() + i);
    }
    const T& operator ()(tSize i) const
    {
        return *(getPtr() + i);
    }

    //! Returns the subscripted pixel.
    T& at(tSize i)
    {
        return *(getPtr() + i);
    }
    const T& at(tSize i) const
    {
        return *(getPtr() + i);
    }

    //! Sets the subscripted voxel.
    CMatrix& set(tSize i, const T& Value)
    {
        *(getPtr() + i) = Value;
        return *this;
    }


    //! Returns pointer to the first matrix element.
    T *getPtr() { return m_Matrix.data(); }
    const T *getPtr() const { return m_Matrix.data(); }

    //! Returns pointer to the given element.
    T *getPtr(tSize Row, tSize Col)
    {
        return (getPtr() + Row * getRowOffset() + Col);
    }
    const T *getPtr(tSize Row, tSize Col) const
    {
        return (getPtr() + Row * getRowOffset() + Col);
    }

    //! Returns pointer to the first element of matrix row.
    T *getRowPtr(tSize Row)
    {
        return (getPtr() + Row * getRowOffset());
    }
    const T *getRowPtr(tSize Row) const
    {
        return (getPtr() + Row * getRowOffset());
    }

    //! Returns pointer to the first element of matrix column.
    T *getColPtr(tSize Col)
    {
        return (getPtr() + Col);
    }
    const T *getColPtr(tSize Col) const
    {
        return (getPtr() + Col);
    }


    //! Calls a function object for every matrix element.
    template <class Function>
    inline Function forEach(Function Func);

    //! Calls a function object for every matrix element.
    template <class Function>
    inline Function forEach(Function Func) const;

    //! Calls a function object for every matrix element.
    //! - Parallel version.
    template <class Function>
    inline void pforEach(Function Func);

    //! Calls a function object for every matrix element.
    //! - Parallel version.
    template <class Function>
    inline void pforEach(Function Func) const;


    //! Element wise addition.
    inline CMatrix& operator +=(const CMatrix& Matrix);

    //! Element wise subtraction.
    inline CMatrix& operator -=(const CMatrix& Matrix);

    //! Element wise product.
    inline CMatrix& operator *=(const CMatrix& Matrix);

    //! Element wise division.
    inline CMatrix& operator /=(const CMatrix& Matrix);


    //! Adds scalar to all elements.
    //! - An operator that allow conversion from U to T must be defined!
    template <typename U>
    inline CMatrix& operator +=(const CScalar<U>& c);

    //! Subtracts scalar to all elements.
    //! - An operator that allow conversion from U to T must be defined!
    template <typename U>
    inline CMatrix& operator -=(const CScalar<U>& c);

    //! Multiplies all elements by scalar.
    //! - An operator that allow conversion from U to T must be defined!
    template <typename U>
    inline CMatrix& operator *=(const CScalar<U>& c);

    //! Divides all elements by scalar.
    //! - An operator that allow conversion from U to T must be defined!
    template <typename U>
    inline CMatrix& operator /=(const CScalar<U>& c);


    //! Zeros the matrix.
    //! - Returns reference to this.
    inline CMatrix& zeros();

    //! Sets all elements to one.
    //! - Returns reference to this.
    inline CMatrix& ones();

    //! Makes the matrix unit.
    //! - Returns reference to this.
    inline CMatrix& unit();

    //! Fills the matrix using a given value.
    //! - Returns reference to this.
    inline CMatrix& fill(const T& Value);

    //! Makes absolute value of all elements.
    //! - Returns reference to this.
    inline CMatrix& abs();

    //! Makes this to be transpose of a given matrix.
    //! - Throws CTransposeFailed() exception on failure.
    //! - Returns reference to this.
    inline CMatrix& transpose(const CMatrix& Matrix);

    //! Makes this to be result of multiplication of two matrices.
    //! - Throws CMultFailed() exception on failure.
    //! - Returns reference to this.
    inline CMatrix& mult(const CMatrix& m1, const CMatrix& m2);

    //! Returns true of the matrix is square.
    bool isSquare() const { return (m_Matrix.rows() == m_Matrix.cols()); }

protected:
    //! Underlying matrix data (see the Eigen math library).
    tStorage m_Matrix;
};


//==============================================================================
/*
 * Method templates.
 */

// Include the file containing method templates.
#include "Matrix.hxx"


//==============================================================================
/*
 * Basic type definitions.
 */

//! Matrix of int numbers.
typedef CMatrix<int>            CIMatrix;

//! Matrix of float numbers.
typedef CMatrix<float>          CFMatrix;

//! Matrix of double numbers.
typedef CMatrix<double>         CDMatrix;

//! Smart pointer to a matrix of int numbers.
typedef CIMatrix::tSmartPtr     CIMatrixPtr;

//! Smart pointer to a matrix of float numbers.
typedef CFMatrix::tSmartPtr     CFMatrixPtr;

//! Smart pointer to a matrix of double numbers.
typedef CDMatrix::tSmartPtr     CDMatrixPtr;


} // namespace math
} // namespace vpl

#endif // VPL_MATRIX_H

