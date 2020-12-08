//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/11/23                          \n
 *
 * $Id: mdsData.hxx 2091 2012-02-14 11:26:36Z spanel $
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
    m_pData = memAlloc<tData>(0);
}


template <typename T>
inline CData<T>::CData(EEmptyConst) : m_Size(0), m_pData(0)
{
}


template <typename T>
inline CData<T>::CData(tSize Size) : m_Size(Size)
{
    MDS_ASSERT(m_Size >= 0);

    m_pData = memAlloc<tData>(m_Size);
}


template <typename T>
inline CData<T>::CData(tConstDataPtr pData, tSize Size) : m_Size(Size)
{
    MDS_ASSERT(m_Size >= 0 && pData);

    m_pData = memAlloc<tData>(m_Size);

    memCopy(m_pData, pData, m_Size);
}


template <typename T>
inline CData<T>::CData(const CData<T>& Data) : m_Size(Data.m_Size)
{
    m_pData = memAlloc<tData>(m_Size);

    memCopy(m_pData, Data.m_pData, m_Size);
}


template <typename T>
inline CData<T>::~CData()
{
    memFree(m_pData);
}


template <typename T>
inline CData<T>& CData<T>::operator=(const CData<T>& Data)
{
    if( this != &Data )
    {
        create(Data);
    }
    return *this;
}


template <typename T>
inline CData<T>& CData<T>::create(tSize Size)
{
    MDS_ASSERT(Size >= 0);

    if( Size > m_Size || Size < (m_Size >> 1) )
    {
        m_pData = memRealloc<tData>(m_pData, Size);
    }
    m_Size = Size;

    return *this;
}


template <typename T>
inline CData<T>& CData<T>::create(tConstDataPtr pData, tSize Size)
{
    MDS_ASSERT(pData);

    create(Size);

    memCopy(m_pData, pData, m_Size);
    
    return *this;
}


template <typename T>
inline CData<T>& CData<T>::create(const CData<T>& Data)
{
    create(Data.m_Size);

    memCopy(m_pData, Data.m_pData, m_Size);

    return *this;
}


template <typename T>
inline CData<T>& CData<T>::fill(const tData& Value)
{
    memSet(m_pData, Value, m_Size);

    return *this;
}


template <typename T>
template <class Function>
inline Function CData<T>::forEach(Function Func)
{
    tDataPtr p = getPtr();
    for( tSize i = 0; i < m_Size; ++i, ++p )
    {
        Func(*p);
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CData<T>::forEach(Function Func) const
{
    tConstDataPtr p = getPtr();
    for( tSize i = 0; i < m_Size; ++i, ++p )
    {
        Func(*p);
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CData<T>::forRange(tSize i, tSize j, Function Func)
{
    tDataPtr p = getPtr(i);
    for( tSize x = i; i <= j; ++x, ++p )
    {
        Func(*p);
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CData<T>::forRange(tSize i, tSize j, Function Func) const
{
    tConstDataPtr p = getPtr(i);
    for( tSize x = i; i <= j; ++x, ++p )
    {
        Func(*p);
    }
    return Func;
}

