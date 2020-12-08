//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)        \n
 * Copyright (c) 2003-2008 by Michal Spanel         \n
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz      \n
 * Date:    2006/12/29                              \n
 *
 * $Id: mdsAdjacencyGraph.hxx 1764 2010-06-17 07:31:23Z spanel $
 *
 * Description:
 * - Region Adjacency Graph (RAG).
 */


//==============================================================================
/*
 * Implementation of the CAdjacencyGraph::SRegionInfo class.
 */

template <typename T>
inline CAdjacencyGraph<T>::SRegionInfo::SRegionInfo()
    : m_MaxIndex(-1)
    , m_MinIndex(-1)
    , m_Flags(0)
{
}


template <typename T>
inline int CAdjacencyGraph<T>::SRegionInfo::set(tSize i, const T& Value)
{
    m_Row[i] = Value;

    if( (m_Flags & DIRTY) || m_MaxIndex == i || m_MinIndex == i )
    {
        return (m_Flags = DIRTY);
    }

    int Result = VALID;
    if( Value > m_Max || m_MaxIndex == -1 )
    {
        m_Max = Value;
        m_MaxIndex = i;
        Result |= CHANGED;
    }
    if( Value < m_Min || m_MinIndex == -1 )
    {
        m_Min = Value;
        m_MinIndex = i;
        Result |= CHANGED;
    }
    return Result;
}


template <typename T>
inline T CAdjacencyGraph<T>::SRegionInfo::get(tSize i, const T& DefaultValue) const
{
    typename tRow::const_iterator it = m_Row.find(i);
    return (it != m_Row.end()) ? it->second : DefaultValue;
}


template <typename T>
inline int CAdjacencyGraph<T>::SRegionInfo::remove(tSize i)
{
    m_Row.erase(i);

    if( (m_Flags & DIRTY) || m_MinIndex == i || m_MaxIndex == i )
    {
        return (m_Flags = DIRTY);
    }

    return VALID;
}


template <typename T>
inline void CAdjacencyGraph<T>::SRegionInfo::clear()
{
    m_Row.clear();

    m_Flags = 0;
    m_MinIndex = m_MaxIndex = -1;
}


template <typename T>
inline int CAdjacencyGraph<T>::SRegionInfo::insert(const SRegionInfo& Info)
{
    int Result = VALID;

    typename tRow::const_iterator itEnd = Info.m_Row.end();
    typename tRow::const_iterator it = Info.m_Row.begin();
    for( ; it != itEnd; ++it )
    {
        Result |= set(it->first, it->second);
    }
    return Result;
}


template <typename T>
inline void CAdjacencyGraph<T>::SRegionInfo::findMinMax()
{
    if( (m_Flags & DIRTY) == 0 )
    {
        return;
    }

    m_Flags = 0;
    m_MinIndex = m_MaxIndex = -1;

    typename tRow::iterator itEnd = m_Row.end();
    typename tRow::iterator it = m_Row.begin();
    if( it == itEnd )
    {
        return;
    }

    m_Min = m_Max = it->second;
    m_MinIndex = m_MaxIndex = it->first;
    ++it;

    for( ; it != itEnd; ++it )
    {
        if( it->second < m_Min )
        {
            m_Min = it->second;
            m_MinIndex = it->first;
        }
        if( it->second > m_Max )
        {
            m_Max = it->second;
            m_MaxIndex = it->first;
        }
    }
}


template <typename T>
inline T CAdjacencyGraph<T>::SRegionInfo::getMin(tSize& i, const T& DefaultValue)
{
    findMinMax();
    i = m_MinIndex;
    return (m_MinIndex != -1) ? m_Min : DefaultValue;
}


template <typename T>
inline T CAdjacencyGraph<T>::SRegionInfo::getMax(tSize& i, const T& DefaultValue)
{
    findMinMax();
    i = m_MaxIndex;
    return (m_MaxIndex != -1) ? m_Max : DefaultValue;
}


//==============================================================================
/*
 * Implementation of the CAdjacencyGraph class.
 */

template <typename T>
inline void CAdjacencyGraph<T>::set(tSize i, tSize j, const T& Value)
{
    if( i == j )
    {
        return;
    }

    int Flag1 = m_RAG[i].set(j, Value);
    int Flag2 = m_RAG[j].set(i, Value);

    if( (Flag1 | Flag2) & SRegionInfo::DIRTY )
    {
        m_Flags = SRegionInfo::DIRTY;
        return;
    }

    if( Flag1 & SRegionInfo::CHANGED )
    {
        if( Value > m_Max || m_MaxIndex == -1 )
        {
            m_Max = Value;
            m_MaxIndex = i;
        }
        if( Value < m_Min || m_MinIndex == -1 )
        {
            m_Min = Value;
            m_MinIndex = i;
        }
    }

    if( Flag2 & SRegionInfo::CHANGED )
    {
        if( Value > m_Max || m_MaxIndex == -1 )
        {
            m_Max = Value;
            m_MaxIndex = j;
        }
        if( Value < m_Min || m_MinIndex == -1 )
        {
            m_Min = Value;
            m_MinIndex = j;
        }
    }
}


template <typename T>
inline T CAdjacencyGraph<T>::get(tSize i, tSize j, const T& DefaultValue) const
{
    return m_RAG[i].get(j, DefaultValue);
}


template <typename T>
inline void CAdjacencyGraph<T>::clear(tSize i)
{
    typename SRegionInfo::tRow::iterator itEnd = m_RAG[i].m_Row.end();
    typename SRegionInfo::tRow::iterator it = m_RAG[i].m_Row.begin();
    for( ; it != itEnd; ++it )
    {
        m_RAG[it->first].remove(i);
    }

    m_RAG[i].clear();

    m_Flags = SRegionInfo::DIRTY;
}


template <typename T>
inline void CAdjacencyGraph<T>::clear()
{
    for( std::size_t k = 0; k < m_RAG.size(); ++k )
    {
        m_RAG[k].clear();
    }

    m_Flags = 0;
    m_MaxIndex = m_MinIndex = -1;
}


template <typename T>
void CAdjacencyGraph<T>::merge(tSize i, tSize j)
{
    m_RAG[i].m_Row.erase(j);
    m_RAG[j].insert(m_RAG[i]);

    typename SRegionInfo::tRow::iterator itEnd = m_RAG[j].m_Row.end();
    typename SRegionInfo::tRow::iterator it = m_RAG[j].m_Row.begin();
    for( ; it != itEnd; ++it )
    {
        m_RAG[it->first].set(j, it->second);
    }

    // Clear sets the dirty flag automatically...
    clear(i);
}


template <typename T>
inline T CAdjacencyGraph<T>::getMax(tSize& i, tSize& j, const T& DefaultValue)
{
    findMinMax();
    i = m_MaxIndex;
    return (m_MaxIndex != -1) ? m_RAG[m_MaxIndex].getMax(j, DefaultValue) : DefaultValue;
}


template <typename T>
inline T CAdjacencyGraph<T>::getMin(tSize& i, tSize& j, const T& DefaultValue)
{
    findMinMax();
    i = m_MinIndex;
    return (m_MinIndex != -1) ? m_RAG[m_MinIndex].getMin(j, DefaultValue) : DefaultValue;
}


template <typename T>
inline void CAdjacencyGraph<T>::findMinMax()
{
    if( (m_Flags & SRegionInfo::DIRTY) == 0 )
    {
        return;
    }

    m_Flags = 0;
    m_MaxIndex = m_MinIndex = -1;

    for( std::size_t k = 0; k < m_RAG.size(); ++k )
    {
        m_RAG[k].findMinMax();
        if( m_RAG[k].m_MaxIndex != -1 )
        {
            if( m_RAG[k].m_Max > m_Max || m_MaxIndex == -1 )
            {
                m_Max = m_RAG[k].m_Max;
                m_MaxIndex = tSize(k);
            }
        }
        if( m_RAG[k].m_MinIndex != -1 )
        {
            if( m_RAG[k].m_Min < m_Min || m_MinIndex == -1 )
            {
                m_Min = m_RAG[k].m_Min;
                m_MinIndex = tSize(k);
            }
        }
    }
}

