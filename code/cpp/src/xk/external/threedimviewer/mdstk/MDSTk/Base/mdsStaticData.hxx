//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)	\n
 * Copyright (c) 2003-2010 by Michal Spanel		\n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz	\n
 * Date:    2006/02/15							\n
 *
 * $Id: mdsStaticData.hxx 2092 2012-02-15 12:50:59Z spanel $
 *
 * Description:
 * - Template providing data allocation functions.
 * - Implemented via static array.
 */

//==============================================================================
/*
 * Methods templates.
 */

template <typename T, tSize M>
inline CStaticData<T,M>::CStaticData() : m_Size(M)
{
}


template <typename T, tSize M>
inline CStaticData<T,M>::CStaticData(EEmptyConst) : m_Size(M)
{
}


template <typename T, tSize M>
inline CStaticData<T,M>::CStaticData(tSize Size)
{
    MDS_ASSERT(Size >= 0);

    if( Size > M )
    {
        throw CBadStaticAlloc();
    }
    m_Size = Size;
}


template <typename T, tSize M>
inline CStaticData<T,M>::CStaticData(tConstDataPtr pData, tSize Size)
{
    create(pData, Size);
}


// Copy constructor
template <typename T, tSize M>
inline CStaticData<T,M>::CStaticData(const CStaticData<T,M>& Data) : base()
{
    create(Data);
}


template <typename T, tSize M>
inline CStaticData<T,M>::~CStaticData()
{
}


template <typename T, tSize M>
inline CStaticData<T,M>& CStaticData<T,M>::operator =(const CStaticData<T,M>& Data)
{
    if( this != &Data )
    {
        create(Data);
    }
    return *this;
}


template <typename T, tSize M>
inline CStaticData<T,M>& CStaticData<T,M>::create(tSize Size)
{
    MDS_ASSERT(Size >= 0);

    if( Size > M )
    {
        throw CBadStaticAlloc();
    }
    m_Size = Size;

    return *this;
}


template <typename T, tSize M>
inline CStaticData<T,M>& CStaticData<T,M>::create(tConstDataPtr pData, tSize Size)
{
    MDS_ASSERT(Size >= 0 && pData);

    m_Size = (Size < M) ? Size : M;
    memCopy(m_pData, pData, m_Size);

    return *this;
}


template <typename T, tSize M>
inline CStaticData<T,M>& CStaticData<T,M>::create(const CStaticData<T,M>& Data)
{
    m_Size = Data.m_Size;
    memCopy(m_pData, Data.m_pData, m_Size);

    return *this;
}


template <typename T, tSize M>
inline CStaticData<T,M>& CStaticData<T,M>::fill(const tData& Value)
{
    memSet(m_pData, Value, m_Size);

    return *this;
}


#define MDS_META_FOR_EACH_IMPL(n) \
        case n: \
            return metaForEach<n,tData,Function>(m_pData, Func); \
            break


template <typename T, tSize M>
template <class Function>
inline Function CStaticData<T,M>::forEach(Function Func)
{
    switch( m_Size )
    {
        case 0:
            return Func;
            break;
            
        case 1:
            return Func(*m_pData);
            break;
            
        MDS_META_FOR_EACH_IMPL(2);
        MDS_META_FOR_EACH_IMPL(3);
        MDS_META_FOR_EACH_IMPL(4);
        MDS_META_FOR_EACH_IMPL(5);
        MDS_META_FOR_EACH_IMPL(6);
        MDS_META_FOR_EACH_IMPL(7);
        MDS_META_FOR_EACH_IMPL(8);
        MDS_META_FOR_EACH_IMPL(9);
        MDS_META_FOR_EACH_IMPL(10);
        MDS_META_FOR_EACH_IMPL(11);
        MDS_META_FOR_EACH_IMPL(12);
        MDS_META_FOR_EACH_IMPL(13);
        MDS_META_FOR_EACH_IMPL(14);
        MDS_META_FOR_EACH_IMPL(15);
        MDS_META_FOR_EACH_IMPL(16);
            
        default: {
            tDataPtr p = getPtr();
            for( tSize i = 0; i < m_Size; ++i, ++p )
            {
                Func(*p);
            }
            return Func;
        }
    }
}


template <typename T, tSize M>
template <class Function>
inline Function CStaticData<T,M>::forEach(Function Func) const
{
    switch( m_Size )
    {
        case 0:
            return Func;
            break;
            
        case 1:
            return Func(*m_pData);
            break;
            
        MDS_META_FOR_EACH_IMPL(2);
        MDS_META_FOR_EACH_IMPL(3);
        MDS_META_FOR_EACH_IMPL(4);
        MDS_META_FOR_EACH_IMPL(5);
        MDS_META_FOR_EACH_IMPL(6);
        MDS_META_FOR_EACH_IMPL(7);
        MDS_META_FOR_EACH_IMPL(8);
        MDS_META_FOR_EACH_IMPL(9);
        MDS_META_FOR_EACH_IMPL(10);
        MDS_META_FOR_EACH_IMPL(11);
        MDS_META_FOR_EACH_IMPL(12);
        MDS_META_FOR_EACH_IMPL(13);
        MDS_META_FOR_EACH_IMPL(14);
        MDS_META_FOR_EACH_IMPL(15);
        MDS_META_FOR_EACH_IMPL(16);
            
        default: {
            tConstDataPtr p = getPtr();
            for( tSize i = 0; i < m_Size; ++i, ++p )
            {
                Func(*p);
            }
            return Func;
        }
    }
}


#define MDS_META_FOR_RANGE_IMPL(n) \
        case n: \
            return metaForEach<n,tData,Function>(m_pData + i, Func); \
            break


template <typename T, tSize M>
template <class Function>
inline Function CStaticData<T,M>::forRange(tSize i, tSize j, Function Func)
{
    tSize n = j - i + 1;
    
    switch( n )
    {
        case 0:
            return Func;
            break;
            
        case 1:
            return Func(*m_pData);
            break;
            
        MDS_META_FOR_RANGE_IMPL(2);
        MDS_META_FOR_RANGE_IMPL(3);
        MDS_META_FOR_RANGE_IMPL(4);
        MDS_META_FOR_RANGE_IMPL(5);
        MDS_META_FOR_RANGE_IMPL(6);
        MDS_META_FOR_RANGE_IMPL(7);
        MDS_META_FOR_RANGE_IMPL(8);
        MDS_META_FOR_RANGE_IMPL(9);
        MDS_META_FOR_RANGE_IMPL(10);
        MDS_META_FOR_RANGE_IMPL(11);
        MDS_META_FOR_RANGE_IMPL(12);
        MDS_META_FOR_RANGE_IMPL(13);
        MDS_META_FOR_RANGE_IMPL(14);
        MDS_META_FOR_RANGE_IMPL(15);
        MDS_META_FOR_RANGE_IMPL(16);

        default: {
            tDataPtr p = getPtr(i);
            for( tSize x = i; x <= j; ++x, ++p )
            {
                Func(*p);
            }
            return Func;
        }
    }
}


template <typename T, tSize M>
template <class Function>
inline Function CStaticData<T,M>::forRange(tSize i, tSize j, Function Func) const
{
    tSize n = j - i + 1;
    
    switch( n )
    {
        case 0:
            return Func;
            break;
            
        case 1:
            return Func(*m_pData);
            break;
            
        MDS_META_FOR_RANGE_IMPL(2);
        MDS_META_FOR_RANGE_IMPL(3);
        MDS_META_FOR_RANGE_IMPL(4);
        MDS_META_FOR_RANGE_IMPL(5);
        MDS_META_FOR_RANGE_IMPL(6);
        MDS_META_FOR_RANGE_IMPL(7);
        MDS_META_FOR_RANGE_IMPL(8);
        MDS_META_FOR_RANGE_IMPL(9);
        MDS_META_FOR_RANGE_IMPL(10);
        MDS_META_FOR_RANGE_IMPL(11);
        MDS_META_FOR_RANGE_IMPL(12);
        MDS_META_FOR_RANGE_IMPL(13);
        MDS_META_FOR_RANGE_IMPL(14);
        MDS_META_FOR_RANGE_IMPL(15);
        MDS_META_FOR_RANGE_IMPL(16);

        default: {
            tConstDataPtr p = getPtr(i);
            for( tSize x = i; x <= j; ++x, ++p )
            {
                Func(*p);
            }
            return Func;
        }
    }
}

