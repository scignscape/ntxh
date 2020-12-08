//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)           \n
 * Copyright (c) 2003-2005 by Michal Spanel            \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz         \n
 *          Miroslav Svub, xsvubm00@stud.fit.vutbr.cz  \n
 * File:    mdsHistogramThresholding.h                 \n
 * Section: mVolumeSegHT                               \n
 * Date:    2005/01/25                                 \n
 *
 * $Id: mdsHistogramThresholding.h 967 2008-07-28 15:05:19Z spanel $
 *
 * File description:
 * - Simple segmentation method based on histogram thresholding.
 */

#ifndef MDS_HISTOGRAMTHRESHOLDING_H
#define MDS_HISTOGRAMTHRESHOLDING_H

#include <MDSTk/Base/mdsSetup.h>
#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Image/mdsVolume.h>

// STL
#include <iostream>
#include <cstring>
#include <list>


namespace mds
{
namespace volseg
{

//==============================================================================
/*!
 * Class encapsulating a simple segmentation method based on histogram
 * thresholding.
 */
class CVolumeHistogramThresholding
{
public:
    //! Image type
    typedef mds::img::CDVolume tVolume;

    //! Image pixel type
    typedef mds::img::CDVolume::tVoxel tVoxel;

public:
    //! Default constructor
    CVolumeHistogramThresholding(const int iTresholds, const int iColumns)
        : m_iTresholds(iTresholds)
        , m_iColumns(iColumns)
    {}

    //! Virtual destructor
    virtual ~CVolumeHistogramThresholding() {}

    //! Volume segmentation
    //! - Uses mds::CUVolume volume type
    //! - Voxel values of the output/destination volume represent segment indexes
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

protected:
    //! Histogram column description.
    struct SColumn
    {
        //! The number of pixels in the column
        int m_iCount;

        //! Minimal and maximal pixel value
        tVoxel m_Min, m_Max;

        //! Default constructor
        SColumn() : m_iCount(0), m_Min(0), m_Max(0) {}

        //! Initializes the column
        void set(const int iCount, const tVoxel Min, const tVoxel Max)
        {
            m_iCount = iCount;
            m_Min = Min;
            m_Max = Max;
        }

        //! Increases the number of pixels in the column
        void add(const int iCount) { m_iCount += iCount; }

        //! Counts distance between two column peaks
        double getDistance(const SColumn& rhs);
    };

    //! Histogram definition
    typedef std::list<SColumn> tHistList;

protected:
    //! The number of tresholds
    int m_iTresholds;

    //! Histogram resolution
    int m_iColumns;
};


} // namespace volseg
} // namespace mds

#endif // MDS_HISTOGRAMTHRESHOLDING_H

