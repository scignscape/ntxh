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
 * - Vector class template implementation.
 */


//=============================================================================
/*
 * Methods templates.
 */

template <typename T>
inline CArray<T>::CArray()
    : m_Size(0)
    , m_Stride(1)
    , m_DataStorage(0)
{
    m_pData = m_DataStorage.getPtr();
}


template <typename T>
inline CArray<T>::CArray(tSize Size)
    : m_DataStorage(EMPTY_CONST)
{
    resize(Size);
}


template <typename T>
inline CArray<T>::CArray(const CArray<T>& Vector, tSize First, tSize Size)
    : m_DataStorage(EMPTY_CONST)
{
    VPL_ASSERT(First >= 0 && Size >= 0 && First < Vector.m_Size);

    copy(Vector, First, Size);
}


template <typename T>
inline CArray<T>::CArray(const CArray<T>& Vector, tSize First, tSize Size, EMakeRef)
    : m_Stride(Vector.m_Stride)
    , m_DataStorage(Vector.m_DataStorage, REFERENCE)
    , m_pData(Vector.m_pData)
{
    VPL_ASSERT(First >= 0 && Size >= 0 && First < Vector.m_Size);

    // Size of the vector
    m_Size = vpl::math::getMin(First + Size, Vector.m_Size) - First;

    // Vector data
    m_pData += First * m_Stride;
}


// Copy constructor
template <typename T>
inline CArray<T>::CArray(const CArray<T>& Vector)
    : m_DataStorage(EMPTY_CONST)
{
    copy(Vector);
}


template <typename T>
inline CArray<T>::CArray(const CArray<T>& Vector, EMakeRef)
    : m_Size(Vector.m_Size)
    , m_Stride(Vector.m_Stride)
    , m_DataStorage(Vector.m_DataStorage, REFERENCE)
    , m_pData(Vector.m_pData)
{
}


template <typename T>
CArray<T>::~CArray()
{
}


template <typename T>
inline CArray<T>& CArray<T>::resize(tSize Size)
{
    // Reallocate the data
    m_Size = Size;
    m_Stride = 1;
    m_DataStorage.resize(Size);
    m_pData = m_DataStorage.getPtr();

    return *this;
}


template <typename T>
inline CArray<T>& CArray<T>::copy(const CArray<T>& Vector, tSize First, tSize Size)
{
    VPL_CHECK(First >= 0 && Size >= 0 && First < Vector.m_Size, return *this);

    // Size of the vector
    m_Size = vpl::math::getMin(First + Size, Vector.m_Size) - First;

    // Allocate the data
    m_Stride = 1;
    m_DataStorage.resize(m_Size);
    m_pData = m_DataStorage.getPtr();

    // Copy the data
    vpl::sys::memSparseCopy(m_pData, m_Stride, Vector.getPtr(First), Vector.m_Stride, m_Size);

    return *this;
}


template <typename T>
inline CArray<T>& CArray<T>::copy(const CArray<T>& Vector)
{
    // Allocate the data
    m_Size = Vector.m_Size;
    m_Stride = 1;
    m_DataStorage.resize(m_Size);
    m_pData = m_DataStorage.getPtr();

    // Copy the data
    vpl::sys::memSparseCopy(m_pData, m_Stride, Vector.m_pData, Vector.m_Stride, m_Size);

    return *this;
}


template <typename T>
inline CArray<T>& CArray<T>::makeRef(const CArray<T>& Vector, tSize First, tSize Size)
{
    VPL_CHECK(First >= 0 && Size >= 0 && First < Vector.m_Size, return *this);

    // Size of the vector
    m_Size = vpl::math::getMin(First + Size, Vector.m_Size) - First;

    // Create a reference to the vector data
    m_Stride = Vector.m_Stride;
    m_DataStorage.makeRef(Vector.m_DataStorage);
    m_pData = Vector.m_pData + First * m_Stride;

    return *this;
}


// Makes only reference to the data
template <typename T>
inline CArray<T>& CArray<T>::makeRef(const CArray<T>& Vector)
{
    // Create a reference to the vector data
    m_Size = Vector.m_Size;
    m_Stride = Vector.m_Stride;
    m_DataStorage.makeRef(Vector.m_DataStorage);
    m_pData = Vector.m_pData;

    return *this;
}


template <typename T>
template <typename Derived>
inline CArray<T>& CArray<T>::convert(const vpl::math::CVectorBase<Derived>& Vector)
{
    // Allocate the data
    m_Size = Vector.getSize();
    m_Stride = 1;
    m_DataStorage.resize(m_Size);
    m_pData = m_DataStorage.getPtr();

    // Copy the data
    for( int i = 0; i < Vector.getSize(); ++i )
    {
        at(i) = tElement(Vector.at(i));
    }

    return *this;
}


// Assignment operator
template <typename T>
inline CArray<T>& CArray<T>::operator =(const CArray<T>& Vector)
{
    if( &Vector == this )
    {
        return *this;
    }
    
    tSize Count = vpl::math::getMin(m_Size, Vector.m_Size);

    vpl::sys::memSparseCopy(m_pData, m_Stride, Vector.m_pData, Vector.m_Stride, Count);

    return *this;
}


template <typename T>
template <class Derived>
inline CArray<T>& CArray<T>::operator +=(const vpl::math::CVectorBase<Derived>& Vector)
{
    tSize Count = vpl::math::getMin(m_Size, Vector.getSize());

    for( tSize i = 0; i < Count; ++i )
    {
        at(i) += Vector.at(i);
    }

    return *this;
}


template <typename T>
template <class Derived>
inline CArray<T>& CArray<T>::operator -=(const vpl::math::CVectorBase<Derived>& Vector)
{
    tSize Count = vpl::math::getMin(m_Size, Vector.getSize());

    for( tSize i = 0; i < Count; ++i )
    {
        at(i) -= Vector.at(i);
    }

    return *this;
}


template <typename T>
template <class Derived>
inline CArray<T>& CArray<T>::operator *=(const vpl::math::CVectorBase<Derived>& Vector)
{
    tSize Count = vpl::math::getMin(m_Size, Vector.getSize());

    for( tSize i = 0; i < Count; ++i )
    {
        at(i) *= Vector.at(i);
    }

    return *this;
}


template <typename T>
template <class Derived>
inline CArray<T>& CArray<T>::operator /=(const vpl::math::CVectorBase<Derived>& Vector)
{
    tSize Count = vpl::math::getMin(m_Size, Vector.getSize());

    for( tSize i = 0; i < Count; ++i )
    {
        at(i) /= Vector.at(i);
    }

    return *this;
}


template <typename T>
template <typename U>
inline CArray<T>& CArray<T>::operator +=(const CScalar<U>& c)
{
    forEach(vpl::base::CAdd<tElement>(tElement(c.value())));

    return *this;
}


template <typename T>
template <typename U>
inline CArray<T>& CArray<T>::operator -=(const CScalar<U>& c)
{
    forEach(vpl::base::CSub<tElement>(tElement(c.value())));

    return *this;
}


template <typename T>
template <typename U>
inline CArray<T>& CArray<T>::operator *=(const CScalar<U>& c)
{
    forEach(vpl::base::CMult<tElement,U>(c.value()));

    return *this;
}


template <typename T>
template <typename U>
inline CArray<T>& CArray<T>::operator /=(const CScalar<U>& c)
{
    forEach(vpl::base::CDiv<tElement,U>(c.value()));

    return *this;
}


template <typename T>
template <class Function>
inline Function CArray<T>::forEach(Function Func)
{
    T *p = m_pData;
    for( tSize i = 0; i < m_Size; ++i, p += m_Stride )
    {
        Func(*p);
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CArray<T>::forEach(Function Func) const
{
    const T *p = m_pData;
    for( tSize i = 0; i < m_Size; ++i, p += m_Stride )
    {
        Func(*p);
    }
    return Func;
}


template <typename T>
template <class Function>
inline void CArray<T>::pforEach(Function Func)
{
	const tSize sz = m_Size;

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(sz > VPL_MIN_OMP_COMPLEXITY)
    for( tSize i = 0; i < sz; ++i )
    {
        Func(at(i));
    }
}


template <typename T>
template <class Function>
inline void CArray<T>::pforEach(Function Func) const
{
	const tSize sz = m_Size;

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(sz > VPL_MIN_OMP_COMPLEXITY)
    for( tSize i = 0; i < sz; ++i )
    {
        Func(at(i));

    }
}


template <typename T>
inline CArray<T>& CArray<T>::zeros()
{
    forEach(vpl::base::CFill<tElement>(tElement()));
    return *this;
}


template <typename T>
inline CArray<T>& CArray<T>::ones()
{
    forEach(vpl::base::CFill<tElement>(tElement(1)));
    return *this;
}


template <typename T>
inline CArray<T>& CArray<T>::abs()
{
    forEach(vpl::base::CAbs<tElement>());
    return *this;
}


template <typename T>
inline CArray<T>& CArray<T>::fill(const T& Value)
{
    forEach(vpl::base::CFill<tElement>(Value));
    return *this;
}


template <typename T>
inline CArray<T>& CArray<T>::limit(const T& Lower, const T& Upper)
{
    forEach(vpl::base::CLimit<tElement>(Lower, Upper));
    return *this;
}


// Subsample vector
template <typename T>
inline CArray<T>& CArray<T>::subSample(const CArray<T>& Vector, tSize k)
{
    VPL_CHECK(k > 0, return *this);

    tSize Count = vpl::math::getMin(Vector.m_Size / k, m_Size);
    
    T *p = m_pData;
    const T *pV = Vector.m_pData;
    for( tSize i = 0; i < Count; ++i )
    {
        *p = *pV;
        p += m_Stride;
        pV += k * Vector.m_Stride;
    }

    return *this;
}


// Concatenate two vectors
template <typename T>
inline CArray<T>& CArray<T>::concat(const CArray<T>& Vector1,
                                    const CArray<T>& Vector2
                                    )
{
    tSize Count = vpl::math::getMin(Vector1.m_Size, m_Size);
    vpl::sys::memSparseCopy(m_pData, m_Stride,
                             Vector1.m_pData, Vector1.m_Stride,
                             Count
                             );

    if( m_Size > Vector1.m_Size )
    {
        Count = vpl::math::getMin(Vector2.m_Size, m_Size - Vector1.m_Size);
        vpl::sys::memSparseCopy(m_pData + Vector1.m_Size * m_Stride, m_Stride,
                                 Vector2.m_pData, Vector2.m_Stride,
                                 Count
                                 );
    }

    return *this;
}


// Matrix vs. vector multiplication
template <typename T>
inline CArray<T>& CArray<T>::mult(const vpl::math::CMatrix<T>& Matrix, 
                                  const CArray<T>& Vector
                                  )
{
    if( Matrix.getNumOfCols() != Vector.m_Size || Matrix.getNumOfRows()!= m_Size )
    {
        throw vpl::math::CMultFailed();
    }

    for( tSize i = 0; i < m_Size; ++i )
    {
        T *p = m_pData + i * m_Stride;

        const T *pV = Vector.m_pData;
        const T *pM = Matrix.getRowPtr(i);

        *p = T(0);
        for( tSize k = 0; k < Matrix.getNumOfCols(); ++k )
        {
            *p += *pM * *pV;
            pM += Matrix.getColOffset();
            pV += Vector.m_Stride;
        }
    }

    return *this;
}


// Vector vs. matrix multiplication
template <typename T>
inline CArray<T>& CArray<T>::mult(const CArray<T>& Vector, 
                                  const vpl::math::CMatrix<T>& Matrix
                                  )
{
    if( Matrix.getNumOfRows() != Vector.m_Size || Matrix.getNumOfCols() != m_Size )
    {
        throw vpl::math::CMultFailed();
    }

    for( tSize i = 0; i < m_Size; ++i )
    {
        T *p = m_pData + i * m_Stride;

        const T *pV = Vector.m_pData;
        const T *pM = Matrix.getColPtr(i);

        *p = T(0);
        for( tSize k = 0; k < Matrix.getNumOfRows(); ++k )
        {
            *p += *pM * *pV;
            pM += Matrix.getRowOffset();
            pV += Vector.m_Stride;
        }
    }

    return *this;
}

