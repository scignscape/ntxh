//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/06                          \n
 *
 * $Id: mdsStaticVector.h 2094 2012-02-16 01:54:45Z spanel $
 *
 * Description:
 * - Static dense vector.
 */

#ifndef MDS_StaticVector_H
#define MDS_StaticVector_H

#include "mdsStaticMatrix.h"
#include "mdsVectorBase.h"
#include "mdsVectorIterator.h"


namespace mds
{
namespace math
{

// Declare vector traits first...
MDS_STATIC_VECTOR_TRAITS(CStaticVector)

//==============================================================================
/*!
 * Class template for a static vector.
 * - T is a vector element type. Only int, usnigned int, float, double,
 *   std::complex<> and mds::math::CComplex<> types are supported.
 * - M is vector size.
 */
template <typename T, tSize M>
class CStaticVector : public CVectorBase<CStaticVector<T,M> >
{
public:
    //! Base class.
    typedef CVectorBase<CStaticVector<T,M> > tBase;

    //! Templates that require members of the CStaticVector class can use this
    //! enum to check the existence.
    enum { CLASS_VECTOR };

    //! The vector size.
    enum { SIZE = M };

    //! Vector element type.
    typedef T tElement;

    //! Underlying data (see the Eigen math library).
    typedef Eigen::Matrix<tElement, SIZE, 1, Eigen::ColMajor> tStorage;

    //! Declare iterator types tIterator and tConstIterator.
    MDS_ITERATOR(CStaticVector, tElement, CVectorIterator)

public:
    //! Constructor.
    inline CStaticVector();

    //! Copy constructor.
    template <typename U>
    inline CStaticVector(const CStaticVector<U,M>& Vector);

    //! Conversion constructor.
    template <typename Derived>
    inline CStaticVector(const Eigen::MatrixBase<Derived>& Vector);

    //! Specialization of the copy constructor.
    inline CStaticVector(const CStaticVector& Vector);

    //! Destructor.
    ~CStaticVector() {}

    //! Assignment operator.
    template <typename U>
    inline CStaticVector& operator =(const CStaticVector<U,M>& Vector);

    //! Assignment operator.
    template <typename Derived>
    inline CStaticVector& operator =(const Eigen::MatrixBase<Derived>& Vector);

    //! Specialization of the assignment operator.
    inline CStaticVector& operator =(const CStaticVector& Vector);


    //! Returns reference to the underlying data (see the Eigen math library).
    tStorage& asEigen() { return m_Vector; }
    const tStorage& asEigen() const { return m_Vector; }

    //! Returns the vector size.
    tSize getSize() const { return SIZE; }

    //! Returns the vector size.
    tSize size() const { return SIZE; }

    //! Returns stride between two neigbouring vector elements.
    tSize getStride() const { return 1; }

    //! Returns reference to the element [i].
    T& at(tSize i)
    {
        return m_Vector.coeffRef(i);
    }
    const T& at(tSize i) const
    {
        return m_Vector.coeff(i);
    }

    //! Returns reference to the subscripted element [i].
    T& operator ()(tSize i)
    {
        return m_Vector.coeffRef(i);
    }
    const T& operator ()(tSize i) const
    {
        return m_Vector.coeff(i);
    }

    //! Sets the vector element at the position [i].
    CStaticVector& set(tSize i, const T& Value)
    {
        m_Vector.coeffRef(i) = Value;
        return *this;
    }

    //! Returns pointer to the vector data.
    T *getPtr() { return m_Vector.data(); }
    const T *getPtr() const { return m_Vector.data(); }

    //! Returns pointer to a given element.
    T *getPtr(tSize i) { return (getPtr() + i); }
    const T *getPtr(tSize i) const { return (getPtr() + i); }


    //! Calls a function object for every vector element.
    template <class Function>
    inline Function forEach(Function Func);

    //! Calls a function object for every vector element.
    template <class Function>
    inline Function forEach(Function Func) const;


    //! Element wise addition.
    inline CStaticVector& operator +=(const CStaticVector& v);

    //! Element wise subtraction.
    inline CStaticVector& operator -=(const CStaticVector& v);

    //! Element wise product.
    inline CStaticVector& operator *=(const CStaticVector& v);

    //! Element wise addition.
    inline CStaticVector& operator /=(const CStaticVector& v);


    //! Adds scalar to all elements.
    template <typename U>
    inline CStaticVector& operator +=(const CScalar<U>& c);

    //! Subtracts scalar from all elements.
    template <typename U>
    inline CStaticVector& operator -=(const CScalar<U>& c);

    //! Multiplies all elements by scalar.
    template <typename U>
    inline CStaticVector& operator *=(const CScalar<U>& c);

    //! Divides all elements by scalar.
    template <typename U>
    inline CStaticVector& operator /=(const CScalar<U>& c);


    //! The vector initialization method.
    //! - Returns reference to this.
    inline CStaticVector& zeros();

    //! The vector initialization method.
    //! - Returns reference to this.
    inline CStaticVector& ones();

    //! Sets all elements of the vector to a given value.
    //! - Returns reference to this.
    inline CStaticVector& fill(const T& Value);

    //! Absolute value of all elements.
    //! - Returns reference to this.
    inline CStaticVector& abs();

    //! Provides operation this += Vector * Scalar.
    //! - Returns reference to this.
    inline CStaticVector& multAdd(const CStaticVector& Vector,
                                  const T& Scalar
                                  );

    //! Matrix vs. column vector multiplication.
    //! - Returns reference to this.
    template <tSize K>
    inline CStaticVector& mult(const CStaticMatrix<T,M,K>& Matrix,
                               const CStaticVector<T,K>& Vector
                               );

    //! Row vector vs. matrix multiplication.
    //! - Returns reference to this.
    template <tSize K>
    inline CStaticVector& mult(const CStaticVector<T,K>& Vector,
                               const CStaticMatrix<T,K,M>& Matrix
                               );

protected:
    //! Underlying vector data (see the Eigen library).
    tStorage m_Vector;
};


//==============================================================================
/*
 * Method templates.
 */

// Include the file containing method templates.
#include "mdsStaticVector.hxx"


//==============================================================================
/*
 * Basic type definitions.
 */

//! Vector of int numbers.
typedef CStaticVector<int, 2>       CIVector2;
typedef CStaticVector<int, 3>       CIVector3;
typedef CStaticVector<int, 4>       CIVector4;

//! Vector of float numbers.
typedef CStaticVector<float, 2>     CFVector2;
typedef CStaticVector<float, 3>     CFVector3;
typedef CStaticVector<float, 4>     CFVector4;

//! Vector of double numbers.
typedef CStaticVector<double, 2>    CDVector2;
typedef CStaticVector<double, 3>    CDVector3;
typedef CStaticVector<double, 4>    CDVector4;


} // namespace math
} // namespace mds

#endif // MDS_StaticVector_H

