//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/23                          \n
 *
 * $Id: mdsBlobLabeling.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Based on the code by Ali Rahimi, ali@mit.edu, Jun 2001.
 *
 * Description:
 * - Help class usefull for image blobs labeling.
 */

#ifndef MDS_BlobLabeling_H
#define MDS_BlobLabeling_H

#include <MDSTk/Base/mdsSharedPtr.h>

// STL
#include <vector>
#include <algorithm>


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Class encapsulating mapping of labels for image blobs. It allows you
 * to modify the mapping, merge two blobs, etc. Such mapping is useful
 * for algorithms like region growing or connected component labeling.
 * - Parameter T represents application specific user data
 *   stored for every blob. A default constructor and an assignment operator
 *   must by defined for this type.
 */
template <typename T>
class CBlobLabeling : public mds::base::CObject
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CBlobLabeling);

    //! Default size hint.
    enum { DEFAULT_SIZE = 4096 };

    //! User specific data.
    typedef T tData;

public:
    //! Default constructor.
    CBlobLabeling(int SizeHint = DEFAULT_SIZE) { clear(SizeHint); }

    //! Destructor.
    ~CBlobLabeling() {}

    //! Returns the label for a specified blob.
    int getLabel(int i) { return m_Labels[getRoot(i)].m_Tag; }

    //! Returns reference to user specific data.
    tData& getData(int i) { return m_Labels[getRoot(i)].m_Data; }

    //! Returns a new label.
    int newLabel()
    {
        if( m_HighestLabel + 1 > int(m_Labels.capacity()) )
        {
            m_Labels.reserve(m_HighestLabel * 2);
        }
        m_Labels.resize(m_HighestLabel + 1);
        m_Labels[m_HighestLabel].m_Label = m_HighestLabel;
        m_Labels[m_HighestLabel].m_Tag = m_HighestLabel;
        return m_HighestLabel++;
    }

    //! Returns a new label.
    int newLabel(const tData& Data)
    {
        int iNewLabel = newLabel();
        m_Labels[iNewLabel].m_Data = Data;
        return iNewLabel;
    }

    //! Modifies the mapping so that the two given blobs share the same label.
    //! - The i-th blob becomes equal to the j-th one.
    void merge(int i, int j)
    {
        if( !isEquivalent(i, j) )
        {
            m_Labels[getRoot(i)].m_Label = getRoot(j);
        }
    }

    //! Re-orders labels so that there will be no gaps in the numbering.
    void relabel(int StartingValue = 0)
    {
        int NewTag = StartingValue;
        for( int i = 0; i < int(m_Labels.size()); ++i )
        {
	        if( isRoot(i) )
	        {
	           m_Labels[i].m_Tag = NewTag++;
            }
        }
    }

    //! Clears the mapping.
    void clear(int SizeHint = DEFAULT_SIZE)
    {
        m_HighestLabel = 0;
        m_Labels.resize(SizeHint);
        std::for_each(m_Labels.begin(), m_Labels.end(), SInitLabel());
    }

    //! Returns the current number of blobs.
    int getSize() const { return m_HighestLabel; }

protected:
    //! Information about a blob label.
    struct SLabelInfo
    {
        //! Currently assigned label and the final label.
        int m_Label, m_Tag;

        //! User data.
        tData m_Data;

        //! Default constructor
		SLabelInfo() : m_Label(0), m_Tag(0), m_Data() {}
    };

    //! Function object used to initialize the mapping.
    struct SInitLabel
    {
        //! Progressively incremented label.
        int m_Label;

        //! Default constructor.
        SInitLabel() : m_Label(0) {}

        //! Initializes SLabelInfo structure...
        void operator() (SLabelInfo& Info)
        {
            Info.m_Tag = Info.m_Label = m_Label++;
            Info.m_Data = tData();
        }
    };

    //! Mapping of labels.
    typedef std::vector<SLabelInfo> tLabels;
    tLabels m_Labels;

    //! First available label.
    int m_HighestLabel;

protected:
    //! Returns true if a subscripted blob is a root (its label is equal
    //! to the given blob number.
    bool isRoot(int i) const
    {
		return (m_Labels[i].m_Label == i);
    }

    //! Finds root for a given blob.
    int getRoot(int i)
    {
        while( !isRoot(i) )
        {
            // Link this node to its parent to shorten the tree
            m_Labels[i].m_Label = m_Labels[m_Labels[i].m_Label].m_Label;
            i = m_Labels[i].m_Label;
        }
        return i;
    }

    //! Returns true if two given blobs have been merged.
    bool isEquivalent(int i, int j)
    {
        return (getRoot(i) == getRoot(j));
    }
};


} // namespace img
} // namespace mds

#endif // MDS_BlobLabeling_H

