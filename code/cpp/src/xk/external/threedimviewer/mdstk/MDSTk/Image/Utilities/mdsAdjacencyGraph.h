//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)        \n
 * Copyright (c) 2003-2008 by Michal Spanel         \n
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz      \n
 * Date:    2006/12/29                              \n
 *
 * $Id: mdsAdjacencyGraph.h 2101 2012-02-17 08:20:21Z spanel $
 *
 * Description:
 * - Region Adjacency Graph (RAG).
 */

#ifndef MDS_AdjacencyGraph_H
#define MDS_AdjacencyGraph_H

// MDSTk
#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Base/mdsSharedPtr.h>
#include <MDSTk/Base/mdsSTLIterator.h>
#include <MDSTk/Math/mdsBase.h>

// STL
#include <map>
#include <vector>


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Class representing the Region Adjacency Graph (RAG).
 * - Parameter T is type of the RAG element which is stored for every
 *   pair of adjacent regions. This value usually represents similarity
 *   of both regions.
 */
template <typename T>
class CAdjacencyGraph : public mds::base::CObject
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CAdjacencyGraph);

    //! Type of the RAG element.
    typedef T tElement;

    //! Class representing one row of the Region Adjacency Graph (RAG).
    struct SRegionInfo
    {
        //! Status returned from the set() method.
        enum EReturnCode
        {
            //! Both values are still valid.
            VALID       = 0,

            //! Minimum/maximum has been decreased/increased.
            CHANGED     = 1 << 0,

            //! Minimum/maximum is invalid, the method findMinMax() must be called.
            DIRTY       = 1 << 1
        };

        //! Container of neighbouring regions.
        typedef std::map<tSize,T> tRow;

        //! All neighbouring regions.
        tRow m_Row;

        //! Maximum and minimum.
        tElement m_Max, m_Min;

        //! Indexes of the regions.
        tSize m_MaxIndex, m_MinIndex;

        //! Internal flags.
        int m_Flags;

        //! Default constructor.
        inline SRegionInfo();

        //! Adds a new neighbouring region.
        //! - Returns the return code.
        inline int set(tSize i, const T& Value);

        //! Returns value of the subscripted element.
        //! - If the element was not found, the default value is returned.
        inline T get(tSize i, const T& DefaultValue) const;

        //! Removes a given neighbouring region.
        //! - Returns the status!
        inline int remove(tSize i);

        //! Removes all neighbours.
        inline void clear();

        //! Inserts all neighbours in a given row.
        //! - Returns the status!
        inline int insert(const SRegionInfo& Info);

        //! Returns value and index of the minimum.
        inline T getMin(tSize& i, const T& DefaultValue);

        //! Returns value and index of the maximum.
        inline T getMax(tSize& i, const T& DefaultValue);

        //! Finds maximum and minimum value.
        inline void findMinMax();
    };

    //! Internal representation of the RAG.
    typedef std::vector<SRegionInfo> tRAG;

    //! Iterator used to traverse all region neighbours.
    typedef mds::base::CSTLIterator<typename SRegionInfo::tRow::iterator> tIterator;

    //! Const iterator used to traverse all region neighbours.
    typedef mds::base::CSTLIterator<typename SRegionInfo::tRow::const_iterator> tConstIterator;

public:
    //! Default constructor.
    CAdjacencyGraph(tSize NumOfRegions)
        : m_RAG(NumOfRegions)
        , m_MaxIndex(-1)
        , m_MinIndex(-1)
        , m_Flags(0)
    {}

    //! Destructor.
    ~CAdjacencyGraph() {}

    //! Returns the total number of regions.
    tSize getNumOfRegions() const { return tSize(m_RAG.size()); }

    //! Sets number of regions in the RAG.
    void setNumOfRegions(tSize NumOfRegions) { m_RAG.resize(NumOfRegions); }


    //! Sets subscripted RAG element.
    inline void set(tSize i, tSize j, const T& Value);

    //! Returns value of the subscripted element.
    //! - If the element is not found, a given default value is returned.
    inline T get(tSize i, tSize j, const T& DefaultValue) const;

    //! Removes all elements of the RAG corresponding to given region index.
    inline void clear(tSize i);

    //! Removes all elements from the RAG.
    void clear();

    //! Merges two specified regions. Adds the first region having index
    //! i to the second region j.
    void merge(tSize i, tSize j);


    //! Returns reference to the container of all neighbours of i-th region.
    typename SRegionInfo::tRow& getNeighbours(tSize i) { return m_RAG[i].m_Row; }
    const typename SRegionInfo::tRow& getNeighbours(tSize i) const { return m_RAG[i].m_Row; }

    //! Returns the element region.
    tSize getRegion(const tIterator& it) { return it->first; }
    tSize getRegion(const tConstIterator& it) const  { return it->first; }

    //! Returns element value.
    T& getValue(const tIterator& it) { return it->second; }
    const T& getValue(const tConstIterator& it) const { return it->second; }


    //! Returns value and region labels of the minimal RAG element.
    inline T getMin(tSize& i, tSize& j, const T& DefaultValue);

    //! Returns value and region labels of the maximal RAG element.
    inline T getMax(tSize& i, tSize& j, const T& DefaultValue);

protected:
    //! The RAG stored as a sparse matrix in std::map.
    tRAG m_RAG;

    //! Minimal and maximal value.
    T m_Max, m_Min;

    //! Index of the row where the maximum can be found.
    tSize m_MaxIndex, m_MinIndex;

    //! Internal flags.
    int m_Flags;

protected:
    //! Finds maximum and minimum value.
    inline void findMinMax();
};


//==============================================================================
/*
 * Method templates.
 */

// Include file containing method templates.
#include "mdsAdjacencyGraph.hxx"


} // namespace img
} // namespace mds

#endif // MDS_AdjacencyGraph_H

