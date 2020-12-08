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
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/06                          \n
 *
 * Description:
 * - Static dense vector.
 */

#ifndef VPL_StaticVector_H
#define VPL_StaticVector_H

#include "StaticMatrix.h"
#include "VectorBase.h"
#include "VectorIterator.h"

#include <VPL/Base/Scalar.h>
#include <VPL/Base/Logging.h>
#include <VPL/Base/Templates.h>
#include <VPL/Base/StaticAssert.h>


#include <Eigen/Geometry>


namespace vpl
{
namespace math
{

// Declare vector traits first...
VPL_STATIC_VECTOR_TRAITS(CStaticVector)

//==============================================================================
/*!
 * Class template for a static vector.
 * - T is a vector element type. Only int, usnigned int, float, double,
 *   std::complex<> and vpl::math::CComplex<> types are supported.
 * - M is vector size.
 * - This class uses Eigen structers for the underlying matrix data
 *   (see the Eigen library).
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
    VPL_ITERATOR(CStaticVector, tElement, CVectorIterator)

public:
    //! Constructor.
    inline CStaticVector();

    //! Copy constructor.
    template <typename U>
    explicit inline CStaticVector(const CStaticVector<U,M>& Vector);

    //! Conversion constructor.
    template <typename Derived>
    inline CStaticVector(const Eigen::MatrixBase<Derived>& Vector);

    //! Specialization of the copy constructor.
    inline CStaticVector(const CStaticVector& Vector);

    //! Initializing constructor by one value
    explicit CStaticVector(tElement e);

    //! Initializing constructor of the two components vector
    CStaticVector(tElement x, tElement y);

    //! Initializing constructor of the 3 component vector
    CStaticVector(tElement x, tElement y, tElement z);

    //! Initialize four component vector
    CStaticVector(tElement x, tElement y, tElement z, tElement w);

    //! Initializing constructor by vector and one element
    CStaticVector(const CStaticVector<T, SIZE - 1> &v, tElement e);

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

    //! Initialize by elements
    inline void set(tElement x, tElement y);
    inline void set(tElement x, tElement y, tElement z);
    inline void set(tElement x, tElement y, tElement z, tElement w);

    //! Initialize by another vector
    inline void set(const CStaticVector &v) { m_Vector = v.m_Vector; }
    
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
    
    //! Element wise addition.
    inline CStaticVector& operator +=(const CStaticVector& v);

    //! Element wise subtraction.
    inline CStaticVector& operator -=(const CStaticVector& v);

    //! Element wise product.
    inline CStaticVector& operator *=(const CStaticVector& v);

    //! Element wise addition.
    inline CStaticVector& operator /=(const CStaticVector& v);

    //! Equality operator
    inline bool operator == (const CStaticVector& v) const { return m_Vector == v.m_Vector; }

    //! Inequality operator
    inline bool operator != (const CStaticVector& v) const { return m_Vector != v.m_Vector; }

    //! Compartment operator
    inline bool operator <  (const CStaticVector& v) const;

    //! Element wise addition operator
    template <typename U>
    inline CStaticVector operator + (const CScalar<U>& v) const
    {
        CStaticVector nv = *this;
        for (int i = 0; i < SIZE; ++i) { nv.m_Vector(i) = m_Vector(i) + v.value(); }
        return nv;
    }

    //! Element wise subtraction operator
    template <typename U>
    inline CStaticVector operator - (const CScalar<U>& v) const
    {
        CStaticVector nv = *this;
        for (int i = 0; i < SIZE; ++i) { nv.m_Vector(i) = m_Vector(i) - v.value(); }
        return nv;
    }

    //! Element wise product operator
    template <typename U>
    inline CStaticVector operator * (const CScalar<U>& v) const
    {
        CStaticVector nv = *this;
        for (int i = 0; i < SIZE; ++i) { nv.m_Vector(i) = m_Vector(i) * v.value(); }
        return nv;
    }

    //! Element wise division operator
    template <typename U>
    inline CStaticVector operator / (const CScalar<U>& v) const
    {
        CStaticVector nv = *this;
        for (int i = 0; i < SIZE; ++i) { nv.m_Vector(i) = m_Vector(i) / v.value(); }
        return nv;
    }
    
    //! Addition operator
    inline CStaticVector operator + (const CStaticVector &v) const { CStaticVector nv = *this; for (int i = 0; i < SIZE; ++i) { nv.m_Vector(i) = m_Vector(i) + v.m_Vector(i); } return nv; }

    //! Subtraction operator
    inline CStaticVector operator - (const CStaticVector &v) const { CStaticVector nv = *this; for (int i = 0; i < SIZE; ++i) { nv.m_Vector(i) = m_Vector(i) - v.m_Vector(i); } return nv; }

    //! Unary - - calculate opposite vector
    inline CStaticVector operator -() const { CStaticVector nv = *this; for (int i = 0; i < SIZE; ++i) { nv.m_Vector(i) = -m_Vector(i); } return nv; }

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

    // Access to elements
    //! Get element reference
    inline tElement & operator [] (int i) { return m_Vector(i); }
    
    //! Get element copy
    inline tElement operator [] (int i) const { return m_Vector(i); }
    
    //! Get x value reference
    inline tElement & x();
    inline tElement & y();
    inline tElement & z();
    inline tElement & w();

    //! Get x value copy
    inline tElement x() const;
    inline tElement y() const;
    inline tElement z() const;
    inline tElement w() const;

    // Others

    //! Dot product 
    inline tElement operator *(const CStaticVector &rhs) const { return asEigen().dot(rhs.asEigen()); }

    //! Cross product
    inline const CStaticVector operator ^ (const CStaticVector &rhs) const { return CStaticVector(asEigen().cross(rhs.asEigen())); }

    //! Length of the vector.
    inline tElement length() const
    {
        typedef typename CTypeTraits<tElement>::tFloat tFloat;

        return tElement(std::sqrt(tFloat(this->length2())));
    }

    //! Squared length of the vector.
    inline tElement length2() const { return asEigen().cwiseAbs2().sum(); }

    //! Normalize vector. Returns previous vector length.
    inline tElement normalize() 
    {
        tElement norm(this->length());
        
        if( CTypeTraits<tElement>::isIntegral )
        {
            VPL_LOG_WARN("Normalizing integral vector.");
            return norm;
        }

        if( norm > 0 )
        {
            tElement divider(1 / norm);
            m_Vector *= divider;
        }
        return norm;
    }

protected:
    //! Underlying vector data (see the Eigen library).
    tStorage m_Vector;
};


//! Multiply vector by scalar from left
template <typename Element, tSize M>
inline CStaticVector<Element, M> operator *(const CScalar<Element>& scalar, const CStaticVector<Element, M>& vec)
{
    return vec * scalar;
}
    
    
//==============================================================================
/*
 * Method templates.
 */

// Include the file containing method templates.
#include "StaticVector.hxx"


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
} // namespace vpl

#endif // VPL_StaticVector_H

