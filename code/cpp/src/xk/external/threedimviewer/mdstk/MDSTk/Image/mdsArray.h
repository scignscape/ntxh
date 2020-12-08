//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/05                          \n
 *
 * $Id:$
 *
 * Description:
 * - Array class template.
 */

#ifndef MDS_Array_H
#define MDS_Array_H

#include <MDSTk/Base/mdsSharedPtr.h>
#include <MDSTk/Base/mdsRefData.h>

#include <MDSTk/Math/mdsVector.h>
#include <MDSTk/Math/mdsMatrix.h>


namespace mds
{

// Declare vector traits first...
namespace math { MDS_VECTOR_TRAITS(CArray) }

namespace img
{
   
//==============================================================================
/*!
 * Class template providing basic vector operations.
 * - This is the mds::math::CArray<> from the previous MDSTk release.
 * - T is vector element type.
 */
template <typename T>
class CArray : public mds::base::CObject, public mds::math::CVectorBase<CArray<T> >
{
public:
    //! Base class.
    typedef mds::math::CVectorBase<CArray<T> > tBase;

    //! Templates that require members of the CArray class can use
    //! this enum to check the existence.
    enum { CLASS_VECTOR };

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CArray);

    //! Array element type.
    typedef T tElement;

    //! Array data.
    typedef mds::base::CRefData<T> tDataStorage;

    //! Declare iterator types tIterator and tConstIterator.
    MDS_ITERATOR(CArray, tElement, mds::math::CVectorIterator)

public:
    //! Default constructor.
    inline CArray();

    //! Constructor.
    //! - Creates a new vector of a given size.
    inline explicit CArray(tSize Size);

    //! Constructor.
    //! - Creates subvector of a given vector.
    //! - Makes a new copy of the data.
    inline CArray(const CArray& Vector, tSize First, tSize Size);

    //! Constructor.
    //! - Creates subvector of a given vector.
    //! - Makes only reference to the data.
    inline CArray(const CArray& Vector, tSize First, tSize Size, EMakeRef);

    //! Copy constructor.
    //! - Makes a new copy of the data.
    inline CArray(const CArray& Vector);

    //! Copy constructor.
    //! - Makes only reference to the data.
    inline CArray(const CArray& Vector, EMakeRef);

    //! Destructor.
    ~CArray();

    //! Resizes the vector.
    inline CArray& create(tSize Size);

    //! Re-creates the vector.
    inline CArray& create(const CArray& Vector, tSize First, tSize Size);

    //! Re-creates the vector as a reference to specified data.
    inline CArray& create(const CArray& Vector, tSize First, tSize Size, EMakeRef);

    //! Re-creates the vector.
    //! - Makes a new copy of the data.
    inline CArray& create(const CArray& Vector);

    //! Re-creates the vector.
    //! - Makes only reference to the data.
    inline CArray& create(const CArray& Vector, EMakeRef);
    
    //! Assignment operator.
    inline CArray& operator =(const CArray& Vector);

    //! Conversion between vectors of different type.
    //! - Makes a new copy of the data.
    template <typename Derived>
    inline CArray& convert(const mds::math::CVectorBase<Derived>& Vector);


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
    inline Function pforEach(Function Func);

    //! Calls a function object for every vector element.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func) const;


    //! Element wise addition.
    template <class Derived>
    inline CArray& operator +=(const mds::math::CVectorBase<Derived>& Vector);

    //! Element wise subtraction.
    template <class Derived>
    inline CArray& operator -=(const mds::math::CVectorBase<Derived>& Vector);

    //! Element wise product.
    template <class Derived>
    inline CArray& operator *=(const mds::math::CVectorBase<Derived>& Vector);

    //! Element wise addition.
    template <class Derived>
    inline CArray& operator /=(const mds::math::CVectorBase<Derived>& Vector);


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
    inline CArray& mult(const mds::math::CMatrix<T>& Matrix,
                        const CArray& Vector
                        );

    //! Row vector vs. matrix multiplication.
    //! - Throws CMultFailed() exception on failure.
    //! - Returns reference to this.
    inline CArray& mult(const CArray& Vector,
                        const mds::math::CMatrix<T>& Matrix
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
#include "mdsArray.hxx"


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


} // namespace img
} // namespace mds

#endif // MDS_Array_H

