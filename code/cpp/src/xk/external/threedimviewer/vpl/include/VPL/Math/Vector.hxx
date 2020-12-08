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
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/05                          \n
 *
 * Description:
 * - Vector template implementation.
 */


//=============================================================================
/*
 * Methods templates.
 */

// Default constructor
template <typename T>
inline CVector<T>::CVector() : m_Vector()
{
}


// Constructor
// - Creates a new vector of a given size
template <typename T>
inline CVector<T>::CVector(tSize Size) : m_Vector(Size)
{
}


// Constructor
// - Creates subvector of a given vector
// - Makes a new copy of the data
template <typename T>
inline CVector<T>::CVector(const CVector<T>& Vector, tSize First, tSize Size)
{
    VPL_ASSERT(First >= 0 && Size >= 0 && First < Vector.getSize());

    m_Vector = Vector.asEigen().segment(First, Size);
}


// Copy constructor
template <typename T>
inline CVector<T>::CVector(const CVector<T>& Vector)
    : vpl::base::CObject()
    , tBase()
    , m_Vector(Vector.asEigen())
{
}


template <typename T>
template <typename Derived>
inline CVector<T>::CVector(const Eigen::MatrixBase<Derived>& Vector)
    : m_Vector(Vector.template cast<T>())
{
}


// Destructor
template <typename T>
CVector<T>::~CVector()
{
}


template <typename T>
inline CVector<T>& CVector<T>::resize(tSize Size)
{
    // Reallocate the data
    m_Vector.resize(Size);

    return *this;
}


template <typename T>
inline CVector<T>& CVector<T>::copy(const CVector<T>& Vector, tSize First, tSize Size)
{
    VPL_ASSERT(First >= 0 && Size >= 0 && First < Vector.getSize());

    m_Vector = Vector.asEigen().segment(First, Size);

    return *this;
}


template <typename T>
inline CVector<T>& CVector<T>::copy(const CVector<T>& Vector)
{
    m_Vector = Vector.asEigen();

    return *this;
}


template <typename T>
template <typename Derived>
inline CVector<T>& CVector<T>::copy(const Eigen::MatrixBase<Derived>& Vector)
{
    m_Vector = Vector.template cast<T>();

    return *this;
}


template <typename T>
template <typename Derived>
inline CVector<T>& CVector<T>::convert(const CVectorBase<Derived>& Vector)
{
    m_Vector.resize(Vector.getSize());

    for( tSize i = 0; i < Vector.getSize(); ++i )
    {
        m_Vector.coeffRef(i) = Vector.at(i);
    }

    return *this;
}


// Assignment operator
template <typename T>
inline CVector<T>& CVector<T>::operator =(const CVector<T>& Vector)
{
    if( &Vector != this )
    {
        m_Vector = Vector.asEigen();
    }

    return *this;
}


template <typename T>
template <typename Derived>
inline CVector<T>& CVector<T>::operator =(const Eigen::MatrixBase<Derived>& Vector)
{
    m_Vector = Vector.template cast<T>();

    return *this;
}


template <typename T>
inline CVector<T>& CVector<T>::operator +=(const CVector<T>& Vector)
{
//    tSize Count = vpl::math::getMin(getSize(), Vector.getSize());

    m_Vector += Vector.asEigen();

    return *this;
}


template <typename T>
inline CVector<T>& CVector<T>::operator -=(const CVector<T>& Vector)
{
//    tSize Count = vpl::math::getMin(getSize(), Vector.getSize());

    m_Vector -= Vector.asEigen();

    return *this;
}


template <typename T>
inline CVector<T>& CVector<T>::operator *=(const CVector<T>& Vector)
{
    tSize Count = vpl::math::getMin(getSize(), Vector.getSize());
    
    vpl::sys::memVectSparseMult(getPtr(), getStride(), Vector.getPtr(), Vector.getStride(), Count);

    return *this;
}


template <typename T>
inline CVector<T>& CVector<T>::operator /=(const CVector<T>& Vector)
{
    tSize Count = vpl::math::getMin(getSize(), Vector.getSize());
    
    vpl::sys::memVectSparseDiv(getPtr(), getStride(), Vector.getPtr(), Vector.getStride(), Count);

    return *this;
}


template <typename T>
template <typename U>
inline CVector<T>& CVector<T>::operator +=(const CScalar<U>& c)
{
    forEach(vpl::base::CAdd<tElement>(tElement(c.value())));

    return *this;
}


template <typename T>
template <typename U>
inline CVector<T>& CVector<T>::operator -=(const CScalar<U>& c)
{
    forEach(vpl::base::CSub<tElement>(tElement(c.value())));

    return *this;
}


template <typename T>
template <typename U>
inline CVector<T>& CVector<T>::operator *=(const CScalar<U>& c)
{
    forEach(vpl::base::CMult<tElement,U>(c.value()));

    return *this;
}


template <typename T>
template <typename U>
inline CVector<T>& CVector<T>::operator /=(const CScalar<U>& c)
{
    forEach(vpl::base::CDiv<tElement,U>(c.value()));

    return *this;
}


template <typename T>
template <class Function>
inline Function CVector<T>::forEach(Function Func)
{
    T *p = getPtr();
    for( tSize i = 0; i < getSize(); ++i, p += getStride() )
    {
        Func(*p);
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CVector<T>::forEach(Function Func) const
{
    const T *p = getPtr();
    for( tSize i = 0; i < getSize(); ++i, p += getStride() )
    {
        Func(*p);
    }
    return Func;
}


template <typename T>
inline CVector<T>& CVector<T>::zeros()
{
    forEach(vpl::base::CFill<tElement>(tElement()));

    return *this;
}


template <typename T>
inline CVector<T>& CVector<T>::ones()
{
    forEach(vpl::base::CFill<tElement>(tElement(1)));

    return *this;
}


template <typename T>
inline CVector<T>& CVector<T>::abs()
{
    forEach(vpl::base::CAbs<tElement>());

    return *this;
}


template <typename T>
inline CVector<T>& CVector<T>::fill(const T& Value)
{
    forEach(vpl::base::CFill<tElement>(Value));

    return *this;
}


template <typename T>
inline CVector<T>& CVector<T>::limit(const T& Lower, const T& Upper)
{
    forEach(vpl::base::CLimit<tElement>(Lower, Upper));

    return *this;
}


// Subsample vector
template <typename T>
inline CVector<T>& CVector<T>::subSample(const CVector<T>& Vector, tSize k)
{
    VPL_CHECK(k > 0, return *this);

    tSize Count = vpl::math::getMin(Vector.getSize() / k, getSize());
    T *p = getPtr();
    const T *pV = Vector.getPtr();
    for( tSize i = 0; i < Count; ++i )
    {
        *p = *pV;
        p += getStride();
        pV += k * Vector.getStride();
    }

    return *this;
}


// Concatenate two vectors
template <typename T>
inline CVector<T>& CVector<T>::concat(const CVector<T>& Vector1,
                                      const CVector<T>& Vector2
                                      )
{
    tSize Count = vpl::math::getMin(Vector1.getSize(), getSize());
    vpl::sys::memSparseCopy(getPtr(), getStride(),
                             Vector1.getPtr(), Vector1.getStride(),
                             Count
                             );

    if( getSize() > Vector1.getSize() )
    {
        Count = vpl::math::getMin(Vector2.getSize(), getSize() - Vector1.getSize());
        vpl::sys::memSparseCopy(getPtr() + Vector1.getSize() * getStride(), getStride(),
                                 Vector2.getPtr(), Vector2.getStride(),
                                 Count
                                 );
    }

    return *this;
}


template <typename T>
inline CVector<T>& CVector<T>::multAdd(const CVector<T>& Vector, const T& Scalar)
{
    if( Vector.getSize() != getSize() )
    {
        throw CMultFailed();
    }

    m_Vector += Scalar * Vector.asEigen();

    return *this;
}


// Matrix vs. vector multiplication
template <typename T>
inline CVector<T>& CVector<T>::mult(const CMatrix<T>& Matrix, const CVector<T>& Vector)
{
    if( Matrix.getNumOfCols() != Vector.getSize() || Matrix.getNumOfRows() != getSize() )
    {
        throw CMultFailed();
    }

    m_Vector = Matrix.asEigen() * Vector.asEigen();

    return *this;
}


// Vector vs. matrix multiplication
template <typename T>
inline CVector<T>& CVector<T>::mult(const CVector<T>& Vector, const CMatrix<T>& Matrix)
{
    if( Matrix.getNumOfRows() != Vector.getSize() || Matrix.getNumOfCols() != getSize() )
    {
        throw CMultFailed();
    }

    m_Vector = (Vector.asEigen().transpose() * Matrix.asEigen()).transpose();

    return *this;
}

