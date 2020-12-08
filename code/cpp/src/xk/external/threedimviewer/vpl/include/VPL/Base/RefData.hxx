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
 * Date:    2004/11/22                          \n
 *
 * Description:
 * - Class template managing references to 1D data array.
 * - Provides own data reference counting mechanism.
 */

//==============================================================================
/*
 * Methods templates.
 */

template <typename T>
inline CRefData<T>::SRefInfo::SRefInfo(tSize Size)
    : m_Size(Size)
    , m_iReferences(1)
{
    VPL_ASSERT(Size >= 0);

    m_pData = vpl::sys::memAlloc<tData>(m_Sampling.adjustSize(m_Size));
}


template <typename T>
inline CRefData<T>::SRefInfo::~SRefInfo()
{
    vpl::sys::memFree(m_pData);
}


template <typename T>
inline void CRefData<T>::SRefInfo::resize(tSize Size)
{
    m_Size = Size;
    m_pData = vpl::sys::memRealloc<tData>(m_pData, m_Sampling.adjustSize(m_Size));
}


//==============================================================================

template <typename T>
inline CRefData<T>::CRefData() : m_pRef(new SRefInfo(0))
{
    VPL_ASSERT(m_pRef);
}


template <typename T>
inline CRefData<T>::CRefData(EEmptyConst) : m_pRef(0)
{
}


template <typename T>
inline CRefData<T>::CRefData(tSize Size) : m_pRef(new SRefInfo(Size))
{
    VPL_ASSERT(m_pRef);
}


template <typename T>
inline CRefData<T>::CRefData(tConstDataPtr pData, tSize Size)
    : m_pRef(new SRefInfo(Size))
{
    VPL_ASSERT(m_pRef && pData);

    vpl::sys::memCopy(m_pRef->m_pData, pData, m_pRef->m_Sampling.adjustSize(m_pRef->m_Size));
}


template <typename T>
inline CRefData<T>::CRefData(const CRefData<T>& Data)
    : m_pRef(new SRefInfo(Data.m_pRef->m_Size))
{
    VPL_ASSERT(m_pRef);

    vpl::sys::memCopy(m_pRef->m_pData, Data.m_pRef->m_pData, m_pRef->m_Sampling.adjustSize(m_pRef->m_Size));
}


template <typename T>
inline CRefData<T>::CRefData(const CRefData<T>& Data, EMakeRef)
    : m_pRef(Data.m_pRef)
{
    ++m_pRef->m_iReferences;
}


template <typename T>
CRefData<T>::~CRefData()
{
    if( m_pRef && (--m_pRef->m_iReferences) == 0 )
    {
        delete m_pRef;
    }
}


template <typename T>
inline CRefData<T>& CRefData<T>::operator=(const CRefData<T>& Data)
{
    if( this != &Data )
    {
        copy(Data);
    }
    return *this;
}


template <typename T>
inline CRefData<T>& CRefData<T>::resize(tSize Size)
{
    if( !m_pRef )
    {
        m_pRef = new SRefInfo(Size);
    }
    else if( m_pRef->m_iReferences > 1 )
    {
        --m_pRef->m_iReferences;
        m_pRef = new SRefInfo(Size);
    }
    else
    {
        // Memory block is shrinked only when the new number of elements
        // is less than half of the currrent size, or when zero size
        // is given
        if( Size > m_pRef->m_Size || Size <= (m_pRef->m_Size >> 1) )
        {
            m_pRef->resize(Size);
        }
        else
        {
            m_pRef->m_Size = Size;
        }
    }

    VPL_ASSERT(m_pRef);

    return *this;
}


template <typename T>
inline CRefData<T>& CRefData<T>::copy(tConstDataPtr pData, tSize Size)
{
    VPL_ASSERT(pData);

    resize(Size);

    vpl::sys::memCopy(m_pRef->m_pData, pData, m_pRef->m_Sampling.adjustSize(m_pRef->m_Size));

    return *this;
}


template <typename T>
inline CRefData<T>& CRefData<T>::copy(const CRefData<T>& Data)
{
    resize(Data.m_pRef->m_Size);

    vpl::sys::memCopy(m_pRef->m_pData, Data.m_pRef->m_pData, m_pRef->m_Sampling.adjustSize(m_pRef->m_Size));

    return *this;
}


template <typename T>
inline CRefData<T>& CRefData<T>::makeRef(const CRefData<T>& Data)
{
    if( m_pRef && (--m_pRef->m_iReferences) <= 0 )
    {
        delete m_pRef;
    }

    m_pRef = Data.m_pRef;
    ++m_pRef->m_iReferences;

    return *this;
}


template <typename T>
inline CRefData<T>& CRefData<T>::fill(const tData& Value)
{
    VPL_ASSERT(m_pRef);

    vpl::sys::memSet(m_pRef->m_pData, Value, m_pRef->m_Sampling.adjustSize(m_pRef->m_Size));

    return *this;
}


template <typename T>
template <class Function>
inline Function CRefData<T>::forEach(Function Func)
{
    VPL_ASSERT(m_pRef);

    if( m_pRef->m_Sampling.isDefault() )
    {
        tDataPtr p = getPtr();
        for (tSize i = 0; i < m_pRef->m_Size; ++i, ++p)
        {
            Func(*p);
        }
    }
    else
    {
        for( tSize i = 0; i < m_pRef->m_Size; ++i )
        {
            Func(at(i));
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CRefData<T>::forEach(Function Func) const
{
    VPL_ASSERT(m_pRef);

    if (m_pRef->m_Sampling.isDefault())
    {
        tConstDataPtr p = getPtr();
        for (tSize i = 0; i < m_pRef->m_Size; ++i, ++p)
        {
            Func(*p);
        }
    }
    else
    {
        for (tSize i = 0; i < m_pRef->m_Size; ++i)
        {
            Func(at(i));
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CRefData<T>::forRange(tSize i, tSize j, Function Func)
{
    VPL_ASSERT(m_pRef);

    if (m_pRef->m_Sampling.isDefault())
    {
        tDataPtr p = getPtr(i);
        for (tSize x = i; x <= j; ++x, ++p)
        {
            Func(*p);
        }
    }
    else
    {
        for (tSize x = i; x <= j; ++x)
        {
            Func(at(x));
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CRefData<T>::forRange(tSize i, tSize j, Function Func) const
{
    VPL_ASSERT(m_pRef);

    if (m_pRef->m_Sampling.isDefault())
    {
        tDataPtr p = getPtr(i);
        for (tSize x = i; x <= j; ++x, ++p)
        {
            Func(*p);
        }
    }
    else
    {
        for (tSize x = i; x <= j; ++x)
        {
            Func(at(x));
        }
    }
    return Func;
}

