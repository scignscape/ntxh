//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/11/22                          \n
 *
 * $Id: mdsRefData.hxx 2092 2012-02-15 12:50:59Z spanel $
 *
 * Description:
 * - Class template managing references to 1D data array.
 * - Functions malloc() and free() are used internally.
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
    MDS_ASSERT(Size >= 0);

    m_pData = memAlloc<tData>(m_Size);
}


template <typename T>
inline CRefData<T>::SRefInfo::~SRefInfo()
{
    memFree(m_pData);
}


template <typename T>
inline void CRefData<T>::SRefInfo::resize(tSize Size)
{
    m_Size = Size;
    m_pData = memRealloc<tData>(m_pData, m_Size);
}


//==============================================================================

template <typename T>
inline CRefData<T>::CRefData() : m_pRef(new SRefInfo(0))
{
    MDS_ASSERT(m_pRef);
}


template <typename T>
inline CRefData<T>::CRefData(EEmptyConst) : m_pRef(0)
{
}


template <typename T>
inline CRefData<T>::CRefData(tSize Size) : m_pRef(new SRefInfo(Size))
{
    MDS_ASSERT(m_pRef);
}


template <typename T>
inline CRefData<T>::CRefData(tConstDataPtr pData, tSize Size)
    : m_pRef(new SRefInfo(Size))
{
    MDS_ASSERT(m_pRef && pData);

    memCopy(m_pRef->m_pData, pData, m_pRef->m_Size);
}


template <typename T>
inline CRefData<T>::CRefData(const CRefData<T>& Data)
    : m_pRef(new SRefInfo(Data.m_pRef->m_Size))
{
    MDS_ASSERT(m_pRef);

    memCopy(m_pRef->m_pData, Data.m_pRef->m_pData, m_pRef->m_Size);
}


template <typename T>
inline CRefData<T>::CRefData(const CRefData<T>& Data, EMakeRef)
    : base()
    , m_pRef(Data.m_pRef)
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
        create(Data);
    }
    return *this;
}


template <typename T>
inline CRefData<T>& CRefData<T>::create(tSize Size)
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
        if( Size > m_pRef->m_Size || Size < (m_pRef->m_Size >> 1) )
        {
            m_pRef->resize(Size);
        }
        else
        {
            m_pRef->m_Size = Size;
        }
    }

    MDS_ASSERT(m_pRef);

    return *this;
}


template <typename T>
inline CRefData<T>& CRefData<T>::create(tConstDataPtr pData, tSize Size)
{
    MDS_ASSERT(pData);

    create(Size);

    memCopy(m_pRef->m_pData, pData, m_pRef->m_Size);

    return *this;
}


template <typename T>
inline CRefData<T>& CRefData<T>::create(const CRefData<T>& Data)
{
    create(Data.m_pRef->m_Size);

    memCopy(m_pRef->m_pData, Data.m_pRef->m_pData, m_pRef->m_Size);

    return *this;
}


template <typename T>
inline CRefData<T>& CRefData<T>::create(const CRefData<T>& Data, EMakeRef)
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
    MDS_ASSERT(m_pRef);

    memSet(m_pRef->m_pData, Value, m_pRef->m_Size);

    return *this;
}


template <typename T>
template <class Function>
inline Function CRefData<T>::forEach(Function Func)
{
    MDS_ASSERT(m_pRef);

    tDataPtr p = getPtr();
    for( tSize i = 0; i < m_pRef->m_Size; ++i, ++p )
    {
        Func(*p);
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CRefData<T>::forEach(Function Func) const
{
    MDS_ASSERT(m_pRef);

    tConstDataPtr p = getPtr();
    for( tSize i = 0; i < m_pRef->m_Size; ++i, ++p )
    {
        Func(*p);
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CRefData<T>::forRange(tSize i, tSize j, Function Func)
{
    MDS_ASSERT(m_pRef);

    tDataPtr p = getPtr(i);
    for( tSize x = i; x <= j; ++x, ++p )
    {
        Func(*p);
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CRefData<T>::forRange(tSize i, tSize j, Function Func) const
{
    MDS_ASSERT(m_pRef);

    tConstDataPtr p = getPtr(i);
    for( tSize x = i; x <= j; ++x, ++p )
    {
        Func(*p);
    }
    return Func;
}

