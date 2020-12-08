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
 * Medical Data Segmentation Toolkit (MDSTk)     \n
 * Copyright (c) 2011 by 3Dim Laboratory s.r.o.  \n
 *
 * Author:  info@3dim-laboratory.cz              \n
 * Date:    2011/11/17                           \n
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
    VPL_ASSERT(Size >= 0);
    
    tSize AuxSize = m_Sampling.adjustSize(Size);

    m_NumOfBlocks = AuxSize >> PartedData::DIV_SHIFT;
    if (AuxSize & PartedData::MOD_MASK || AuxSize == 0)
    {
        ++m_NumOfBlocks;
    }
    
    m_ppData = vpl::sys::memAlloc<tDataPtr>(m_NumOfBlocks);
    for( tSize i = 0; i < (m_NumOfBlocks - 1); ++i )
    {
        m_ppData[i] = vpl::sys::memAlloc<tData>(PartedData::BLOCK_SIZE);
        AuxSize -= PartedData::BLOCK_SIZE;
    }
    m_ppData[m_NumOfBlocks - 1] = vpl::sys::memAlloc<tData>(AuxSize);
}


template <typename T>
inline CPartedData<T>::SRefInfo::~SRefInfo()
{
    for( ; m_NumOfBlocks > 0; --m_NumOfBlocks )
    {
        vpl::sys::memFree(m_ppData[m_NumOfBlocks - 1]);
    }
    vpl::sys::memFree(m_ppData);
}


template <typename T>
inline void CPartedData<T>::SRefInfo::resize(tSize Size)
{
    tSize AuxSize = m_Sampling.adjustSize(Size);

    tSize NumOfBlocks = AuxSize >> PartedData::DIV_SHIFT;
    tSize LastBlockSize = AuxSize & PartedData::MOD_MASK;
    if( LastBlockSize != 0 || AuxSize == 0 )
    {
        ++NumOfBlocks;
    }
    if (LastBlockSize == 0 && AuxSize > 0)
    {
        LastBlockSize = PartedData::BLOCK_SIZE;
    }

    if( NumOfBlocks < m_NumOfBlocks )
    {
        for( tSize i = NumOfBlocks; i < m_NumOfBlocks; ++i )
        {
            vpl::sys::memFree(m_ppData[i]);
            m_ppData[i] = NULL;
        }
        try {
            m_ppData = vpl::sys::memRealloc<tDataPtr>(m_ppData, NumOfBlocks);
        }
        catch( const std::bad_alloc& )
        {
            m_NumOfBlocks = NumOfBlocks;
            m_Size = Size;
            return;
        }
    }

    if( NumOfBlocks <= m_NumOfBlocks )
    {
        try {
            m_ppData[NumOfBlocks - 1] = vpl::sys::memRealloc<tData>(m_ppData[NumOfBlocks - 1], LastBlockSize);
        }
        catch( const std::bad_alloc& )
        {
            m_NumOfBlocks = NumOfBlocks;
            m_Size = (Size < m_Size) ? Size : m_Size;
            throw;
        }
    }
    else
    {
        try {
            m_ppData = vpl::sys::memRealloc<tDataPtr>(m_ppData, NumOfBlocks);
            
            for( tSize j = m_NumOfBlocks; j < NumOfBlocks; ++j )
            {
                m_ppData[j] = NULL;
            }

            if( m_NumOfBlocks > 0 )
            {
                m_ppData[m_NumOfBlocks - 1] = vpl::sys::memRealloc<tData>(m_ppData[m_NumOfBlocks - 1], PartedData::BLOCK_SIZE);
            }
        }
        catch( const std::bad_alloc& )
        {
            throw;
        }

        tSize n = m_NumOfBlocks; 
        try {       
            for( ; n < (NumOfBlocks - 1); ++n )
            {
                m_ppData[n] = vpl::sys::memAlloc<tData>(PartedData::BLOCK_SIZE);
            }
            m_ppData[NumOfBlocks - 1] = vpl::sys::memAlloc<tData>(LastBlockSize);      
        }
        catch( const std::bad_alloc& )
        {
            m_NumOfBlocks = n - 1;
            m_Size = (Size < m_Size) ? Size : m_Size;
            throw;
        }
    }
    
    m_NumOfBlocks = NumOfBlocks;
    m_Size = Size;
}


//==============================================================================

template <typename T>
inline CPartedData<T>::CPartedData() : m_pRef(new SRefInfo(0))
{
    VPL_ASSERT(m_pRef);
}


template <typename T>
inline CPartedData<T>::CPartedData(EEmptyConst) : m_pRef(0)
{
}


template <typename T>
inline CPartedData<T>::CPartedData(tSize Size) : m_pRef(new SRefInfo(Size))
{
    VPL_ASSERT(m_pRef);
}


template <typename T>
inline CPartedData<T>::CPartedData(tConstDataPtr pData, tSize Size)
    : m_pRef(new SRefInfo(Size))
{
    VPL_ASSERT(m_pRef && pData);

    tSize AuxSize = m_pRef->m_Sampling.adjustSize(Size);

    for (int i = 0; i < (m_pRef->m_NumOfBlocks - 1); ++i)
    {
        vpl::sys::memCopy(m_pRef->m_ppData[i], 
                pData + i * PartedData::BLOCK_SIZE, 
                PartedData::BLOCK_SIZE
                );
        AuxSize -= PartedData::BLOCK_SIZE;
    }
    vpl::sys::memCopy(m_pRef->m_ppData[m_pRef->m_NumOfBlocks - 1], 
            pData + (m_pRef->m_NumOfBlocks - 1) * PartedData::BLOCK_SIZE, 
            AuxSize
            );
}


// Copy constructor
template <typename T>
inline CPartedData<T>::CPartedData(const CPartedData<T>& Data)
    : m_pRef(new SRefInfo(Data.m_pRef->m_Size))
{
    VPL_ASSERT(m_pRef);

    tSize AuxSize = Data.m_pRef->m_Sampling.adjustSize(Data.m_pRef->m_Size);

    for( int i = 0; i < (m_pRef->m_NumOfBlocks - 1); ++i )
    {
        vpl::sys::memCopy(m_pRef->m_ppData[i],
                Data.m_pRef->m_ppData[i],
                PartedData::BLOCK_SIZE
                );
        AuxSize -= PartedData::BLOCK_SIZE;
    }
    vpl::sys::memCopy(m_pRef->m_ppData[m_pRef->m_NumOfBlocks - 1], 
            Data.m_pRef->m_ppData[Data.m_pRef->m_NumOfBlocks - 1],
            AuxSize
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
        copy(Data);
    }
    return *this;
}


template <typename T>
inline CPartedData<T>& CPartedData<T>::resize(tSize Size)
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
inline CPartedData<T>& CPartedData<T>::copy(tConstDataPtr pData, tSize Size)
{
    VPL_ASSERT(pData);

    resize(Size);

    tSize AuxSize = m_pRef->m_Sampling.adjustSize(Size);

    for( int i = 0; i < (m_pRef->m_NumOfBlocks - 1); ++i )
    {
        vpl::sys::memCopy(m_pRef->m_ppData[i],
                pData + i * PartedData::BLOCK_SIZE,
                PartedData::BLOCK_SIZE
                );
        AuxSize -= PartedData::BLOCK_SIZE;
    }
    vpl::sys::memCopy(m_pRef->m_ppData[m_pRef->m_NumOfBlocks - 1],
            pData + (m_pRef->m_NumOfBlocks - 1) * PartedData::BLOCK_SIZE,
            AuxSize
            );

    return *this;
}


template <typename T>
inline CPartedData<T>& CPartedData<T>::copy(const CPartedData<T>& Data)
{
    resize(Data.m_pRef->m_Size);

    tSize AuxSize = Data.m_pRef->m_Sampling.adjustSize(Data.m_pRef->m_Size);

    for( int i = 0; i < (m_pRef->m_NumOfBlocks - 1); ++i )
    {
        vpl::sys::memCopy(m_pRef->m_ppData[i],
                Data.m_pRef->m_ppData[i],
                PartedData::BLOCK_SIZE
                );
        AuxSize -= PartedData::BLOCK_SIZE;
    }
    vpl::sys::memCopy(m_pRef->m_ppData[m_pRef->m_NumOfBlocks - 1],
            Data.m_pRef->m_ppData[m_pRef->m_NumOfBlocks - 1],
            AuxSize
            );

    return *this;
}


template <typename T>
inline CPartedData<T>& CPartedData<T>::makeRef(const CPartedData<T>& Data)
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
    VPL_ASSERT(m_pRef);

    tSize AuxSize = m_pRef->adjustSize(m_pRef->m_Size);

    for( int i = 0; i < (m_pRef->m_NumOfBlocks - 1); ++i )
    {
        vpl::sys::memSet(m_pRef->m_ppData[i], Value, PartedData::BLOCK_SIZE);
        AuxSize -= PartedData::BLOCK_SIZE;
    }
    vpl::sys::memSet(m_pRef->m_ppData[m_pRef->m_NumOfBlocks - 1], Value, AuxSize);

    return *this;
}


template <typename T>
template <class Function>
inline Function CPartedData<T>::forEach(Function Func)
{
    VPL_ASSERT(m_pRef);

    if( m_pRef->m_NumOfBlocks == 1 && m_pRef->m_Sampling.isDefault() )
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
    VPL_ASSERT(m_pRef);

    if( m_pRef->m_NumOfBlocks == 1 && m_pRef->m_Sampling.isDefault() )
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
    if( m_pRef->m_Sampling.isDefault() && isWithinBlock(i, j) )
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
    if (m_pRef->m_Sampling.isDefault() && isWithinBlock(i, j))
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

