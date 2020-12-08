//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/06                          \n
 *
 * $Id: mdsStaticMatrix.h 2102 2012-02-17 09:12:21Z spanel $
 *
 * Description:
 * - Static dense matrix.
 */

#ifndef MDS_StaticMatrix_H
#define MDS_StaticMatrix_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Base/mdsMeta.h>
#include <MDSTk/Base/mdsMemory.h>
#include <MDSTk/Base/mdsFunctional.h>

#include "mdsBase.h"
#include "mdsMatrixBase.h"
#include "mdsMatrixIterator.h"
#include "mdsEigenCore.h"


namespace mds
{
namespace math
{

// Declare matrix traits first
MDS_STATIC_MATRIX_TRAITS(CStaticMatrix)

//=============================================================================
/*!
 * Class template for a two dimensional static row-major dense matrix.
 * - T is a matrix element type. Only int, usnigned int, float, double,
 *   std::complex<> and mds::math::CComplex<> types are supported.
 * - M and N are matrix dimensions (the number of rows and columns).
 */
template <typename T, tSize M, tSize N>
class CStaticMatrix : public CMatrixBase<CStaticMatrix<T, M, N> >
{
public:
    //! Base class.
    typedef CMatrixBase<CStaticMatrix<T, M, N> > tBase;

    //! Templates that require members of the CStaticMatrix class can use this
    //! enum to check the existence.
    enum { CLASS_MATRIX };

    //! Size of the matrix data.
    enum { SIZE = M * N };

    //! Matrix element type.
    typedef T tElement;

    //! Underlying matrix data (see the Eigen math library).
    typedef Eigen::Matrix<tElement, M, N, Eigen::RowMajor> tStorage;

    //! Declare iterator types tIterator and tConstIterator.
    MDS_ITERATOR(CStaticMatrix, tElement, CMatrixIterator)

public:
    //! Constructor.
    inline CStaticMatrix();

    //! Copy constructor.
    template <typename U>
    inline CStaticMatrix(const CStaticMatrix<U,M,N>& Matrix);

    //! Conversion constructor.
    template <typename Derived>
    inline CStaticMatrix(const Eigen::MatrixBase<Derived>& Matrix);

    //! Copy constructor specialization.
    inline CStaticMatrix(const CStaticMatrix& Matrix);

    //! Destructor.
    ~CStaticMatrix() {}

    //! Assignment operator.
    template <typename U>
    inline CStaticMatrix& operator =(const CStaticMatrix<U,M,N>& Matrix);

    //! Assignment operator.
    template <typename Derived>
    inline CStaticMatrix& operator =(const Eigen::MatrixBase<Derived>& Matrix);

    //! Assignment operator specialization.
    inline CStaticMatrix& operator =(const CStaticMatrix& Matrix);


    //! Returns reference to the underlying matrix data (see the Eigen math library).
    tStorage& asEigen() { return m_Matrix; }
    const tStorage& asEigen() const { return m_Matrix; }

    //! Returns the matrix dimensions.
    tSize getNumOfRows() const { return M; }
    tSize getNumOfCols() const { return N; }

    //! Returns the matrix dimensions.
    tSize rows() const { return M; }
    tSize cols() const { return N; }

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

    //! Sets the element of matrix at the position [Row][Col].
    CStaticMatrix& set(tSize Row, tSize Col, const T& Value)
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
    CStaticMatrix& set(tSize i, const T& Value)
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
    inline Function pforEach(Function Func);

    //! Calls a function object for every matrix element.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func) const;


    //! Element wise addition.
    inline CStaticMatrix& operator +=(const CStaticMatrix& Matrix);

    //! Element wise subtraction.
    inline CStaticMatrix& operator -=(const CStaticMatrix& Matrix);

    //! Element wise product.
    inline CStaticMatrix& operator *=(const CStaticMatrix& Matrix);

    //! Element wise addition.
    inline CStaticMatrix& operator /=(const CStaticMatrix& Matrix);


    //! Adds scalar to all elements.
    template <typename U>
    inline CStaticMatrix& operator +=(const CScalar<U>& c);

    //! Subtracts scalar to all elements.
    template <typename U>
    inline CStaticMatrix& operator -=(const CScalar<U>& c);

    //! Multiplies all elements by scalar.
    template <typename U>
    inline CStaticMatrix& operator *=(const CScalar<U>& c);

    //! Divides all elements by scalar.
    template <typename U>
    inline CStaticMatrix& operator /=(const CScalar<U>& c);


    //! Zeros the matrix.
    //! - Returns reference to this.
    inline CStaticMatrix& zeros();

    //! Sets all elements to one.
    //! - Returns reference to this.
    inline CStaticMatrix& ones();

    //! Makes the matrix unit.
    //! - Returns reference to this.
    inline CStaticMatrix& unit();

    //! Fills the matrix using a given value.
    //! - Returns reference to this.
    inline CStaticMatrix& fill(const T& Value);

    //! Makes absolute value of all elements.
    //! - Returns reference to this.
    inline CStaticMatrix& abs();

    //! Makes this to be transpose of a given matrix.
    //! - Returns reference to this.
    inline CStaticMatrix& transpose(const CStaticMatrix<T,N,M>& Matrix);

    //! Provides operation this += Matrix * Scalar.
    //! - Returns reference to this.
    inline CStaticMatrix& multAdd(const CStaticMatrix& Matrix,
                                  const T& Scalar
                                  );

    //! Matrix multiplication.
    //! - Returns reference to this.
    template <tSize K>
    inline CStaticMatrix& mult(const CStaticMatrix<T,M,K>& Matrix1,
                               const CStaticMatrix<T,K,N>& Matrix2
                               );

    //! Returns true of the matrix is square.
    bool isSquare() const { return (M == N); }

protected:
    //! Underlying matrix data (see the Eigen math library).
    tStorage m_Matrix;
};


//==============================================================================
/*
 * Method templates.
 */

// Include the file containing method templates.
#include "mdsStaticMatrix.hxx"


//==============================================================================
/*
 * Basic type definitions.
 */

//! Matrix of int numbers.
typedef CStaticMatrix<int, 2, 2>        CIMatrix2x2;
typedef CStaticMatrix<int, 3, 3>        CIMatrix3x3;
typedef CStaticMatrix<int, 4, 4>        CIMatrix4x4;

//! Matrix of float numbers.
typedef CStaticMatrix<float, 2, 2>      CFMatrix2x2;
typedef CStaticMatrix<float, 3, 3>      CFMatrix3x3;
typedef CStaticMatrix<float, 4, 4>      CFMatrix4x4;

//! Matrix of double numbers.
typedef CStaticMatrix<double, 2, 2>     CDMatrix2x2;
typedef CStaticMatrix<double, 3, 3>     CDMatrix3x3;
typedef CStaticMatrix<double, 4, 4>     CDMatrix4x4;


} // namespace math
} // namespace mds

#endif // MDS_StaticMatrix_H

