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
 * Date:    2003/12/05                          \n
 *
 * Description:
 * - Array class template.
 */

#ifndef VPL_Array_H
#define VPL_Array_H

#include <VPL/Base/SharedPtr.h>
#include <VPL/Base/RefData.h>

#include <VPL/Math/Vector.h>
#include <VPL/Math/Matrix.h>


namespace vpl
{

// Declare vector traits first...
namespace math { VPL_VECTOR_TRAITS(CArray) }

namespace base
{

//==============================================================================
/*!
 * Class template providing a basic vector like container.
 * It allows you to create new vectors as references to existing ones
 * (or their parts) without making copies of data.
 * - T is the vector element type.
 * - T might be a simple data structure without virtual methods
 *   that do not need any special construtor to initialize its members.
 */
template <typename T>
class CArray : public vpl::base::CObject, public vpl::math::CVectorBase<CArray<T> >
{
public:
    //! Base class.
    typedef vpl::math::CVectorBase<CArray<T> > tBase;

    //! Templates that require members of the CArray class can use
    //! this enum to check the existence.
    enum { CLASS_VECTOR };

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CArray);

    //! Array element type.
    typedef T tElement;

    //! Array data.
    typedef vpl::base::CRefData<T> tDataStorage;

    //! Declare iterator types tIterator and tConstIterator.
    VPL_ITERATOR(CArray, tElement, vpl::math::CVectorIterator)

public:
    //! Default constructor.
    inline CArray();

    //! Constructor creates vector of a given size.
    inline explicit CArray(tSize Size);

    //! Constructor makes a copy of a part of the given vector.
    //! - Makes a new copy of the data.
    inline CArray(const CArray& Vector, tSize First, tSize Size);
    
    //! Constructor creates reference to a given vector.
    //! - No data are copied.
    inline CArray(const CArray& Vector, tSize First, tSize Size, EMakeRef);

    //! Copy constructor.
    //! - Makes a new copy of the data.
    inline CArray(const CArray& Vector);

    //! Constructor makes only reference to a given vector.
    inline CArray(const CArray& Vector, EMakeRef);

    //! Destructor.
    ~CArray();

    //! Resizes the vector.
    //! - If Size is smaller than the current size,
    //!   the content is reduced by removing those beyond (no destructor called).
    //! - If Size is greater than the current size, the content is expanded
    //!   by allocating more memory (no initialiazation of the new elements
    //!   is performed).
    inline CArray& resize(tSize Size);

    //! Makes a copy of a specified part of the source vector.
    inline CArray& copy(const CArray& Vector, tSize First, tSize Size);

    //! Makes a new copy of the given vector.
    inline CArray& copy(const CArray& Vector);

    //! Initializes the vector as a reference to specified data.
    inline CArray& makeRef(const CArray& Vector, tSize First, tSize Size);

    //! Initializes the vector as a reference to the given one.
    //! - No elements are copied!
    inline CArray& makeRef(const CArray& Vector);
    
    //! Assignment operator.
    //! - Copies element values from one vector to another.
    inline CArray& operator =(const CArray& Vector);

    //! Conversion between vectors of different type.
    //! - Resizes the current vector according to the source one.
    //! - Makes a new copy of the data.
    template <typename Derived>
    inline CArray& convert(const vpl::math::CVectorBase<Derived>& Vector);


    //! Returns the vector size.
    tSize getSize() const { return m_Size; }

    //! Returns the vector size.
    tSize size() const { return m_Size; }

    //! Returns stride between two neigbouring vector elements.
    tSize getStride() const { return m_Stride; }

    //! Returns reference to the element [i].
    T& at(tSize i)
    {
        return *(m_pData + i * m_Stride);
    }
    const T& at(tSize i) const
    {
        return *(m_pData + i * m_Stride);
    }

    //! Returns reference to the subscripted element [i].
    T& operator ()(tSize i)
    {
        return *(m_pData + i * m_Stride);
    }
    const T& operator ()(tSize i) const
    {
        return *(m_pData + i * m_Stride);
    }

    //! Sets the vector element at the position [i].
    CArray& set(tSize i, const T& Value)
    {
        *(m_pData + i * m_Stride) = Value;
        return *this;
    }

    //! Returns pointer to the vector data.
    T *getPtr() { return m_pData; }
    const T *getPtr() const { return m_pData; }

    //! Returns pointer to the subscripted element.
    T *getPtr(tSize i)
    {
        return (m_pData + i * m_Stride);
    }
    const T *getPtr(tSize i) const
    {
        return (m_pData + i * m_Stride);
    }


    //! Calls a function object for every vector element.
    template <class Function>
    inline Function forEach(Function Func);

    //! Calls a function object for every vector element.
    template <class Function>
    inline Function forEach(Function Func) const;

    //! Calls a function object for every vector element.
    //! - Parallel version.
    template <class Function>
    inline void pforEach(Function Func);

    //! Calls a function object for every vector element.
    //! - Parallel version.
    template <class Function>
    inline void pforEach(Function Func) const;


    //! Element wise addition.
    template <class Derived>
    inline CArray& operator +=(const vpl::math::CVectorBase<Derived>& Vector);

    //! Element wise subtraction.
    template <class Derived>
    inline CArray& operator -=(const vpl::math::CVectorBase<Derived>& Vector);

    //! Element wise product.
    template <class Derived>
    inline CArray& operator *=(const vpl::math::CVectorBase<Derived>& Vector);

    //! Element wise addition.
    template <class Derived>
    inline CArray& operator /=(const vpl::math::CVectorBase<Derived>& Vector);


    //! Adds scalar to all elements.
    template <typename U>
    inline CArray& operator +=(const CScalar<U>& c);

    //! Subtracts scalar from all elements.
    template <typename U>
    inline CArray& operator -=(const CScalar<U>& c);

    //! Multiplies all elements by scalar.
    template <typename U>
    inline CArray& operator *=(const CScalar<U>& c);

    //! Divides all elements by scalar.
    template <typename U>
    inline CArray& operator /=(const CScalar<U>& c);


    //! The vector initialization method.
    //! - Returns reference to this.
    inline CArray& zeros();

    //! The vector initialization method.
    //! - Returns reference to this.
    inline CArray& ones();

    //! Absolute value of all elements.
    //! - Returns reference to this.
    inline CArray& abs();

    //! Sets vector elements to a given value.
    //! - Returns reference to this.
    inline CArray& fill(const T& Value);

    //! Limit range of elements.
    //! - Returns reference to this.
    inline CArray& limit(const T& Lower, const T& Upper);

    //! Initializes this subsampling a given vector.
    //! - Returns reference to this.
    inline CArray& subSample(const CArray& Vector, tSize k = 2);

    //! Concatenates two vectors.
    //! - Returns reference to this.
    inline CArray& concat(const CArray& Vector1, const CArray& Vector2);

    //! Provides operation this += Vector * Scalar.
    //! - Throws CMultFailed() exception on failure.
    //! - Returns reference to this.
    inline CArray& multAdd(const CArray& Vector, const T& Scalar);

    //! Matrix vs. column vector multiplication.
    //! - Throws CMultFailed() exception on failure.
    //! - Returns reference to this.
    inline CArray& mult(const vpl::math::CMatrix<T>& Matrix,
                        const CArray& Vector
                        );

    //! Row vector vs. matrix multiplication.
    //! - Throws CMultFailed() exception on failure.
    //! - Returns reference to this.
    inline CArray& mult(const CArray& Vector,
                        const vpl::math::CMatrix<T>& Matrix
                        );

protected:
    //! Vector dimension.
    tSize m_Size;

    //! Stride between two neighbouring vector values.
    tSize m_Stride;

    //! Vector data.
    tDataStorage m_DataStorage;

    //! Direct pointer to the data.
    T *m_pData;
};


//=============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Array.hxx"


//=============================================================================
/*
 * Basic type definitions.
 */

//! Array of int numbers.
typedef CArray<int>            CIArray;

//! Array of float numbers.
typedef CArray<float>          CFArray;

//! Array of doubles.
typedef CArray<double>         CDArray;


//! Pointer to a vector of int numbers.
typedef CIArray::tSmartPtr     CIArrayPtr;

//! Pointer to a vector of float numbers.
typedef CFArray::tSmartPtr     CFArrayPtr;

//! Pointer to a vector of doubles.
typedef CDArray::tSmartPtr     CDArrayPtr;


} // namespace base
} // namespace vpl

#endif // VPL_Array_H

