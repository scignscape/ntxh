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
 * Date:    2004/11/23                          \n
 *
 * Description:
 * - Template providing data allocation functions.
 * - Functions malloc() and free() are used internally.
 */

//==============================================================================
/*
 * Methods templates.
 */

template <typename T>
inline CData<T>::CData() : m_Size(0)
{
    m_pData = vpl::sys::memAlloc<tData>(m_Sampling.adjustSize(0));
}


template <typename T>
inline CData<T>::CData(EEmptyConst) : m_Size(0), m_pData(0)
{
}


template <typename T>
inline CData<T>::CData(tSize Size) : m_Size(Size)
{
    VPL_ASSERT(m_Size >= 0);

	m_pData = vpl::sys::memAlloc<tData>(m_Sampling.adjustSize(m_Size));
}


template <typename T>
inline CData<T>::CData(tConstDataPtr pData, tSize Size) : m_Size(Size)
{
    VPL_ASSERT(m_Size >= 0 && pData);

	m_pData = vpl::sys::memAlloc<tData>(m_Sampling.adjustSize(m_Size));

	vpl::sys::memCopy(m_pData, pData, m_Sampling.adjustSize(m_Size));
}


template <typename T>
inline CData<T>::CData(const CData<T>& Data) : m_Size(Data.m_Size)
{
	m_pData = vpl::sys::memAlloc<tData>(m_Sampling.adjustSize(m_Size));

	vpl::sys::memCopy(m_pData, Data.m_pData, m_Sampling.adjustSize(m_Size));
}


template <typename T>
inline CData<T>::~CData()
{
    vpl::sys::memFree(m_pData);
}


template <typename T>
inline CData<T>& CData<T>::operator=(const CData<T>& Data)
{
    if( this != &Data )
    {
        copy(Data);
    }
    return *this;
}


template <typename T>
inline CData<T>& CData<T>::resize(tSize Size)
{
    VPL_ASSERT(Size >= 0);

    // Memory block is shrinked only when the new number of elements
    // is less than half of the currrent size, or when zero size
    // is given
    if( Size > m_Size || Size <= (m_Size >> 1) )
    {
		m_pData = vpl::sys::memRealloc<tData>(m_pData, m_Sampling.adjustSize(Size));
    }
    m_Size = Size;

    return *this;
}


template <typename T>
inline CData<T>& CData<T>::copy(tConstDataPtr pData, tSize Size)
{
    VPL_ASSERT(pData);

    resize(Size);

	vpl::sys::memCopy(m_pData, pData, m_Sampling.adjustSize(m_Size));
    
    return *this;
}


template <typename T>
inline CData<T>& CData<T>::copy(const CData<T>& Data)
{
    resize(Data.m_Size);

	vpl::sys::memCopy(m_pData, Data.m_pData, m_Sampling.adjustSize(m_Size));

    return *this;
}


template <typename T>
inline CData<T>& CData<T>::fill(const tData& Value)
{
	vpl::sys::memSet(m_pData, Value, m_Sampling.adjustSize(m_Size));

    return *this;
}


template <typename T>
template <class Function>
inline Function CData<T>::forEach(Function Func)
{
    if (m_Sampling.isDefault())
    {
        tDataPtr p = getPtr();
        for (tSize i = 0; i < m_Size; ++i, ++p)
        {
            Func(*p);
        }
    }
    else
    {
        for (tSize i = 0; i < m_Size; ++i)
        {
            Func(at(i));
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CData<T>::forEach(Function Func) const
{
    if (m_Sampling.isDefault())
    {
        tConstDataPtr p = getPtr();
        for (tSize i = 0; i < m_Size; ++i, ++p)
        {
            Func(*p);
        }
    }
    else
    {
        for (tSize i = 0; i < m_Size; ++i)
        {
            Func(at(i));
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CData<T>::forRange(tSize i, tSize j, Function Func)
{
    if (m_Sampling.isDefault())
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
inline Function CData<T>::forRange(tSize i, tSize j, Function Func) const
{
    if (m_Sampling.isDefault())
    {
        tConstDataPtr p = getPtr(i);
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

