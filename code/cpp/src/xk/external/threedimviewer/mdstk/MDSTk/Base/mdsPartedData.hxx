//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)     \n
 * Copyright (c) 2011 by 3Dim Laboratory s.r.o.  \n
 *
 * Author:  info@3dim-laboratory.cz              \n
 * Date:    2011/11/17                           \n
 *
 * $Id:$
 */

//==============================================================================
/*
 * Methods templates.
 */

template <typename T>
inline CPartedData<T>::SRefInfo::SRefInfo(tSize Size)
    : m_Size(Size)
    , m_iReferences(1)
{
    MDS_ASSERT(Size >= 0);
    
    m_NumOfBlocks = Size >> PartedData::DIV_SHIFT;
    if( Size & PartedData::MOD_MASK || Size == 0 )
    {
        ++m_NumOfBlocks;
    }
    
    m_ppData = memAlloc<tDataPtr>(m_NumOfBlocks);
    for( tSize i = 0; i < (m_NumOfBlocks - 1); ++i )
    {
        m_ppData[i] = memAlloc<tData>(PartedData::BLOCK_SIZE);
        Size -= PartedData::BLOCK_SIZE;
    }
    m_ppData[m_NumOfBlocks - 1] = memAlloc<tData>(Size);
}


template <typename T>
inline CPartedData<T>::SRefInfo::~SRefInfo()
{
    for( ; m_NumOfBlocks > 0; --m_NumOfBlocks )
    {
        memFree(m_ppData[m_NumOfBlocks - 1]);
    }
    memFree(m_ppData);
}


template <typename T>
inline void CPartedData<T>::SRefInfo::resize(tSize Size)
{
    tSize NumOfBlocks = Size >> PartedData::DIV_SHIFT;
    if( Size & PartedData::MOD_MASK || Size == 0 )
    {
        ++NumOfBlocks;
    }

    for( tSize i = NumOfBlocks; i < m_NumOfBlocks; ++i )
    {
        memFree(m_ppData[i]);
    }

    m_ppData = memRealloc<tDataPtr>(m_ppData, NumOfBlocks);

    for( tSize j = m_NumOfBlocks; j < (NumOfBlocks - 1); ++j )
    {
        m_ppData[j] = memAlloc<tData>(PartedData::BLOCK_SIZE);
    }

    tSize LastBlockSize = Size & PartedData::MOD_MASK;
    LastBlockSize = (LastBlockSize == 0 && Size > 0 ) ? PartedData::BLOCK_SIZE : LastBlockSize;

    if( NumOfBlocks <= m_NumOfBlocks )
    {
        m_ppData[NumOfBlocks - 1] = memRealloc<tData>(m_ppData[NumOfBlocks - 1], LastBlockSize);
    }
    else if( NumOfBlocks > m_NumOfBlocks )
    {
        m_ppData[NumOfBlocks - 1] = memAlloc<tData>(LastBlockSize);
        if( m_NumOfBlocks > 0 )
        {
            m_ppData[m_NumOfBlocks - 1] = memRealloc<tData>(m_ppData[m_NumOfBlocks - 1], PartedData::BLOCK_SIZE);
        }
    }

    m_NumOfBlocks = NumOfBlocks;
    m_Size = Size;
}


//==============================================================================

template <typename T>
inline CPartedData<T>::CPartedData() : m_pRef(new SRefInfo(0))
{
    MDS_ASSERT(m_pRef);
}


template <typename T>
inline CPartedData<T>::CPartedData(EEmptyConst) : m_pRef(0)
{
}


template <typename T>
inline CPartedData<T>::CPartedData(tSize Size) : m_pRef(new SRefInfo(Size))
{
    MDS_ASSERT(m_pRef);
}


template <typename T>
inline CPartedData<T>::CPartedData(tConstDataPtr pData, tSize Size)
    : m_pRef(new SRefInfo(Size))
{
    MDS_ASSERT(m_pRef && pData);

    for( int i = 0; i < (m_pRef->m_NumOfBlocks - 1); ++i )
    {
        memCopy(m_pRef->m_ppData[i], 
                pData + i * PartedData::BLOCK_SIZE, 
                PartedData::BLOCK_SIZE
                );
        Size -= PartedData::BLOCK_SIZE;
    }
    memCopy(m_pRef->m_ppData[m_pRef->m_NumOfBlocks - 1], 
            pData + (m_pRef->m_NumOfBlocks - 1) * PartedData::BLOCK_SIZE, 
            Size
            );
}


// Copy constructor
template <typename T>
inline CPartedData<T>::CPartedData(const CPartedData<T>& Data)
    : base()
    , m_pRef(new SRefInfo(Data.m_pRef->m_Size))
{
    MDS_ASSERT(m_pRef);

    tSize Size = Data.m_pRef->m_Size;
    for( int i = 0; i < (m_pRef->m_NumOfBlocks - 1); ++i )
    {
        memCopy(m_pRef->m_ppData[i],
                Data.m_pRef->m_ppData[i],
                PartedData::BLOCK_SIZE
                );
        Size -= PartedData::BLOCK_SIZE;
    }
    memCopy(m_pRef->m_ppData[m_pRef->m_NumOfBlocks - 1], 
            Data.m_pRef->m_ppData[Data.m_pRef->m_NumOfBlocks - 1],
            Size
            );
}


template <typename T>
inline CPartedData<T>::CPartedData(const CPartedData<T>& Data, EMakeRef)
    : m_pRef(Data.m_pRef)
{
    ++m_pRef->m_iReferences;
}


template <typename T>
CPartedData<T>::~CPartedData()
{
    if( m_pRef && (--m_pRef->m_iReferences) == 0 )
    {
        delete m_pRef;
    }
}


template <typename T>
inline CPartedData<T>& CPartedData<T>::operator=(const CPartedData<T>& Data)
{
    if( this != &Data )
    {
        create(Data);
    }
    return *this;
}


template <typename T>
inline CPartedData<T>& CPartedData<T>::create(tSize Size)
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
inline CPartedData<T>& CPartedData<T>::create(tConstDataPtr pData, tSize Size)
{
    MDS_ASSERT(pData);

    create(Size);

    for( int i = 0; i < (m_pRef->m_NumOfBlocks - 1); ++i )
    {
        memCopy(m_pRef->m_ppData[i],
                pData + i * PartedData::BLOCK_SIZE,
                PartedData::BLOCK_SIZE
                );
        Size -= PartedData::BLOCK_SIZE;
    }
    memCopy(m_pRef->m_ppData[m_pRef->m_NumOfBlocks - 1],
            pData + (m_pRef->m_NumOfBlocks - 1) * PartedData::BLOCK_SIZE,
            Size
            );

    return *this;
}


template <typename T>
inline CPartedData<T>& CPartedData<T>::create(const CPartedData<T>& Data)
{
    create(Data.m_pRef->m_Size);

    tSize Size = Data.m_pRef->m_Size;
    for( int i = 0; i < (m_pRef->m_NumOfBlocks - 1); ++i )
    {
        memCopy(m_pRef->m_ppData[i],
                Data.m_pRef->m_ppData[i],
                PartedData::BLOCK_SIZE
                );
        Size -= PartedData::BLOCK_SIZE;
    }
    memCopy(m_pRef->m_ppData[m_pRef->m_NumOfBlocks - 1],
            Data.m_pRef->m_ppData[m_pRef->m_NumOfBlocks - 1],
            Size
            );

    return *this;
}


template <typename T>
inline CPartedData<T>& CPartedData<T>::create(const CPartedData<T>& Data, EMakeRef)
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
inline CPartedData<T>& CPartedData<T>::fill(const tData& Value)
{
    MDS_ASSERT(m_pRef);

    tSize Size = m_pRef->m_Size;
    for( int i = 0; i < (m_pRef->m_NumOfBlocks - 1); ++i )
    {
        memSet(m_pRef->m_ppData[i], Value, PartedData::BLOCK_SIZE);
        Size -= PartedData::BLOCK_SIZE;
    }
    memSet(m_pRef->m_ppData[m_pRef->m_NumOfBlocks - 1], Value, Size);

    return *this;
}


template <typename T>
template <class Function>
inline Function CPartedData<T>::forEach(Function Func)
{
    MDS_ASSERT(m_pRef);

    if( m_pRef->m_NumOfBlocks == 1 )
    {
        tDataPtr p = getPtr();
        for( tSize i = 0; i < m_pRef->m_Size; ++i, ++p )
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
inline Function CPartedData<T>::forEach(Function Func) const
{
    MDS_ASSERT(m_pRef);

    if( m_pRef->m_NumOfBlocks == 1 )
    {
        tConstDataPtr p = getPtr();
        for( tSize i = 0; i < m_pRef->m_Size; ++i, ++p )
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
inline Function CPartedData<T>::forRange(tSize i, tSize j, Function Func)
{
    if( isWithinBlock(i, j) )
    {
        tDataPtr p = getPtr(i);
        for( tSize x = i; x <= j; ++x, ++p )
        {
            Func(*p);
        }
    }
    else
    {
        for( tSize x = i; x <= j; ++x )
        {
            Func(at(x));
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CPartedData<T>::forRange(tSize i, tSize j, Function Func) const
{
    if( isWithinBlock(i, j) )
    {
        tConstDataPtr p = getPtr(i);
        for( tSize x = i; x <= j; ++x, ++p )
        {
            Func(*p);
        }
    }
    else
    {
        for( tSize x = i; x <= j; ++x )
        {
            Func(at(x));
        }
    }
    return Func;
}

