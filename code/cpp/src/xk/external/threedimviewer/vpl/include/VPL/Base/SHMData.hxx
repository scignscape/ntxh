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
 * Date:    2007/06/21                          \n
 *
 * Description:
 * - Class template managing references to 1D data array.
 * - Functions malloc() and free() are used internally.
 * - Provides own data reference counting mechanism.
 * - Allows to share data over shared memory.
 */

//==============================================================================
/*
 * Methods templates.
 */

template <typename T>
inline CSHMData<T>::SRefInfo::SRefInfo(tSize Size)
    : m_Size(Size)
    , m_iReferences(1)
    , m_spSharedMem(NULL)
{
    VPL_ASSERT(Size >= 0);

    m_pData = vpl::sys::memAlloc<tData>(m_Size);
}


template <typename T>
inline CSHMData<T>::SRefInfo::SRefInfo(vpl::sys::CSharedMem *pSharedMem, 
                                       tDataPtr pBegin,
                                       tSize Size
                                       )
    : m_Size(Size)
    , m_pData(pBegin)
    , m_iReferences(1)
    , m_spSharedMem(pSharedMem)
{
    VPL_ASSERT(pSharedMem && pBegin && Size >= 0);
}


template <typename T>
inline CSHMData<T>::SRefInfo::~SRefInfo()
{
    if( !m_spSharedMem )
    {
        vpl::sys::memFree(m_pData);
    }
}


template <typename T>
inline void CSHMData<T>::SRefInfo::resize(tSize Size)
{
    if( !m_spSharedMem )
    {
        m_pData = vpl::sys::memRealloc<tData>(m_pData, Size);
    }
    else
    {
        m_spSharedMem = NULL;
        m_pData = vpl::sys::memAlloc<tData>(Size);
    }
    m_Size = Size;
}


//==============================================================================

template <typename T>
inline CSHMData<T>::CSHMData() : m_pRef(new SRefInfo(0))
{
    VPL_ASSERT(m_pRef);
}


template <typename T>
inline CSHMData<T>::CSHMData(EEmptyConst) : m_pRef(0)
{
}


template <typename T>
inline CSHMData<T>::CSHMData(tSize Size) : m_pRef(new SRefInfo(Size))
{
    VPL_ASSERT(m_pRef);
}


template <typename T>
inline CSHMData<T>::CSHMData(tConstDataPtr pData, tSize Size)
    : m_pRef(new SRefInfo(Size))
{
    VPL_ASSERT(m_pRef && pData);

    vpl::sys::memCopy(m_pRef->m_pData, pData, m_pRef->m_Size);
}


template <typename T>
inline CSHMData<T>::CSHMData(const CSHMData<T>& Data)
    : m_pRef(new SRefInfo(Data.m_pRef->m_Size))
{
    VPL_ASSERT(m_pRef);

    vpl::sys::memCopy(m_pRef->m_pData, Data.m_pRef->m_pData, m_pRef->m_Size);
}


template <typename T>
inline CSHMData<T>::CSHMData(const CSHMData<T>& Data, EMakeRef)
    : m_pRef(Data.m_pRef)
{
    ++m_pRef->m_iReferences;
}


template <typename T>
CSHMData<T>::~CSHMData()
{
    if( m_pRef && (--m_pRef->m_iReferences) == 0 )
    {
        delete m_pRef;
    }
}


template <typename T>
inline CSHMData<T>& CSHMData<T>::operator=(const CSHMData<T>& Data)
{
    if( this != &Data )
    {
        copy(Data);
    }
    return *this;
}


template <typename T>
inline CSHMData<T>& CSHMData<T>::resize(tSize Size)
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
inline CSHMData<T>& CSHMData<T>::copy(tConstDataPtr pData, tSize Size)
{
    VPL_ASSERT(pData);

    resize(Size);

    vpl::sys::memCopy(m_pRef->m_pData, pData, m_pRef->m_Size);

    return *this;
}


template <typename T>
inline CSHMData<T>& CSHMData<T>::copy(const CSHMData<T>& Data)
{
    resize(Data.m_pRef->m_Size);

    vpl::sys::memCopy(m_pRef->m_pData, Data.m_pRef->m_pData, m_pRef->m_Size);

    return *this;
}


template <typename T>
inline CSHMData<T>& CSHMData<T>::makeRef(const CSHMData<T>& Data)
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
inline CSHMData<T>& CSHMData<T>::create(vpl::sys::CSharedMem *pSharedMem, tDataPtr pBegin, tSize Size)
{
    if( m_pRef && m_pRef->m_iReferences > 1 )
    {
        --m_pRef->m_iReferences;
    }
    else
    {
        delete m_pRef;
    }

    m_pRef = new SRefInfo(pSharedMem, pBegin, Size);
    return *this;
}


template <typename T>
inline CSHMData<T>& CSHMData<T>::fill(const tData& Value)
{
    VPL_ASSERT(m_pRef);

    vpl::sys::memSet(m_pRef->m_pData, Value, m_pRef->m_Size);

    return *this;
}


template <typename T>
template <class Function>
inline Function CSHMData<T>::forEach(Function Func)
{
    VPL_ASSERT(m_pRef);

    tDataPtr p = getPtr();
    for( tSize i = 0; i < m_pRef->m_Size; ++i, ++p )
    {
        Func(*p);
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CSHMData<T>::forEach(Function Func) const
{
    VPL_ASSERT(m_pRef);

    tConstDataPtr p = getPtr();
    for( tSize i = 0; i < m_pRef->m_Size; ++i, ++p )
    {
        Func(*p);
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CSHMData<T>::forRange(tSize i, tSize j, Function Func)
{
    VPL_ASSERT(m_pRef);

    tDataPtr p = getPtr(i);
    for( tSize x = i; x <= j; ++x, ++p )
    {
        Func(*p);
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CSHMData<T>::forRange(tSize i, tSize j, Function Func) const
{
    VPL_ASSERT(m_pRef);

    tConstDataPtr p = getPtr(i);
    for( tSize x = i; x <= j; ++x, ++p )
    {
        Func(*p);
    }
    return Func;
}

