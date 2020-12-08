//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/21                          \n
 *
 * $Id: mdsSHMData.hxx 2040 2011-12-29 17:52:28Z spanel $
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
    MDS_ASSERT(Size >= 0);

    m_pData = memAlloc<tData>(m_Size);
}


template <typename T>
inline CSHMData<T>::SRefInfo::SRefInfo(mds::sys::CSharedMem *pSharedMem, 
                                       tDataPtr pBegin,
                                       tSize Size
                                       )
    : m_Size(Size)
    , m_pData(pBegin)
    , m_iReferences(1)
    , m_spSharedMem(pSharedMem)
{
    MDS_ASSERT(pSharedMem && pBegin && Size >= 0);
}


template <typename T>
inline CSHMData<T>::SRefInfo::~SRefInfo()
{
    if( !m_spSharedMem )
    {
        memFree(m_pData);
    }
}


template <typename T>
inline void CSHMData<T>::SRefInfo::resize(tSize Size)
{
    if( !m_spSharedMem )
    {
        m_pData = memRealloc<tData>(m_pData, Size);
    }
    else
    {
        m_spSharedMem = NULL;
        m_pData = memAlloc<tData>(Size);
    }
    m_Size = Size;
}


//==============================================================================

template <typename T>
inline CSHMData<T>::CSHMData() : m_pRef(new SRefInfo(0))
{
    MDS_ASSERT(m_pRef);
}


template <typename T>
inline CSHMData<T>::CSHMData(EEmptyConst) : m_pRef(0)
{
}


template <typename T>
inline CSHMData<T>::CSHMData(tSize Size) : m_pRef(new SRefInfo(Size))
{
    MDS_ASSERT(m_pRef);
}


template <typename T>
inline CSHMData<T>::CSHMData(tConstDataPtr pData, tSize Size)
    : m_pRef(new SRefInfo(Size))
{
    MDS_ASSERT(m_pRef && pData);

    memCopy(m_pRef->m_pData, pData, m_pRef->m_Size);
}


template <typename T>
inline CSHMData<T>::CSHMData(const CSHMData<T>& Data)
    : m_pRef(new SRefInfo(Data.m_pRef->m_Size))
{
    MDS_ASSERT(m_pRef);

    memCopy(m_pRef->m_pData, Data.m_pRef->m_pData, m_pRef->m_Size);
}


template <typename T>
inline CSHMData<T>::CSHMData(const CSHMData<T>& Data, EMakeRef MakeRef)
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
        create(Data);
    }
    return *this;
}


template <typename T>
inline CSHMData<T>& CSHMData<T>::create(tSize Size)
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
inline CSHMData<T>& CSHMData<T>::create(tConstDataPtr pData, tSize Size)
{
    MDS_ASSERT(pData);

    create(Size);

    memCopy(m_pRef->m_pData, pData, m_pRef->m_Size);

    return *this;
}


template <typename T>
inline CSHMData<T>& CSHMData<T>::create(const CSHMData<T>& Data)
{
    create(Data.m_pRef->m_Size);

    memCopy(m_pRef->m_pData, Data.m_pRef->m_pData, m_pRef->m_Size);

    return *this;
}


template <typename T>
inline CSHMData<T>& CSHMData<T>::create(const CSHMData<T>& Data, EMakeRef)
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
inline CSHMData<T>& CSHMData<T>::create(mds::sys::CSharedMem *pSharedMem, tDataPtr pBegin, tSize Size)
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
    MDS_ASSERT(m_pRef);

    memSet(m_pRef->m_pData, Value, m_pRef->m_Size);

    return *this;
}


template <typename T>
template <class Function>
inline Function CSHMData<T>::forEach(Function Func)
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
inline Function CSHMData<T>::forEach(Function Func) const
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
inline Function CSHMData<T>::forRange(tSize i, tSize j, Function Func)
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
inline Function CSHMData<T>::forRange(tSize i, tSize j, Function Func) const
{
    MDS_ASSERT(m_pRef);

    tConstDataPtr p = getPtr(i);
    for( tSize x = i; x <= j; ++x, ++p )
    {
        Func(*p);
    }
    return Func;
}

