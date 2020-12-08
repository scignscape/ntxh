//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)             \n
 * Copyright (c) 2003-2005 by Michal Spanel              \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz           \n
 *          Martin Skotnica, xskotn01@stud.fit.vutbr.cz  \n
 * File:    mdsRegionGrowing.h                           \n
 * Section: mVolumeSegRG                                 \n
 * Date:    2005/01/25                                   \n
 *
 * $Id: mdsRegionGrowing.h 967 2008-07-28 15:05:19Z spanel $
 *
 * File description:
 * - Simple segmentation method based on region growing and merging.
 */

#ifndef MDS_REGIONGROWING_H
#define MDS_REGIONGROWING_H

#include <MDSTk/Base/mdsSetup.h>
#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Image/mdsVolume.h>
#include <MDSTk/Image/Utilities/mdsBlobLabeling.h>

// STL
#include <map>
#include <deque>
#include <vector>


namespace mds
{
namespace volseg
{

//==============================================================================
/*
 * Global variables and definitions.
 */

//! Structure encapsulating an image point.
struct SMySeed
{
    //! Point position.
    mds::tSize m_x, m_y, m_z;

    //! Region index.
    int m_iIndex;

    //! Default constructor.
    SMySeed() : m_x(0), m_y(0), m_z(0), m_iIndex(0) {}

    //! Constructor.
    SMySeed(tSize x,
            tSize y,
            tSize z,
            int iIndex
            )
        : m_x(x)
        , m_y(y)
        , m_z(z)
        , m_iIndex(iIndex)
    {}
};


//! Information on region of voxels.
struct SMyRegion
{
    //! Total sum of voxel values.
    double m_dTotal;

    //! The number of voxels in the region.
    long int m_liCount;

    //! Precomputed mean value.
    double m_dMean;

    //! Default constructor.
    SMyRegion() : m_dTotal(0.0), m_liCount(0), m_dMean(0.0) {}

    //! Constructor.
    SMyRegion(int iValue)
        : m_dTotal(iValue)
        , m_liCount(1)
        , m_dMean(iValue)
    {}

    //! Returns true if theere is no pixel in the region.
    bool isEmpty() { return (m_liCount == 0); }

    //! Inserts a given pixel to the region.
    void insert(int iValue)
    {
        m_dTotal += iValue;
        ++m_liCount;
        m_dMean = m_dTotal / (double)m_liCount;
    }

    //! Remove a given pixel to the region.
    void remove(int iValue)
    {
        m_dTotal -= iValue;
        --m_liCount;
        m_dMean = m_dTotal / (double)m_liCount;
    }

    //! Changes the region statistics.
    void add(double dValue, long liNumber)
    {
        m_dTotal += dValue;
        m_liCount += liNumber;
        m_dMean = m_dTotal / (double)m_liCount;
    }

    //! Returns mean pixel value.
    double getMean() { return m_dMean; }
};


//==============================================================================
/*!
 * Class encapsulating simple segmentation method based on region growing
 * and joining.
 */
class CVolumeRegionGrowing
{
public:
    //! Image type.
    typedef mds::img::CDVolume tVolume;

    //! Image pixel type.
    typedef mds::img::CDVolume::tVoxel tVoxel;

public:
    //! Constructor.
    CVolumeRegionGrowing(double dDiffWeight,
                         double dEdgeWeight,
                         double dThreshold,
                         bool bMerge = false
                         );

    //! Virtual destructor.
    virtual ~CVolumeRegionGrowing() {}

    //! Volume segmentation.
    //! - Voxel values of the output/destination volume represent segment indexes.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

protected:
    //! Vector of segmented regions subscripted by their indexes.
    typedef mds::img::CBlobLabeling<SMyRegion> tRegions;

    //! Queue of seeds.
    typedef std::deque<SMySeed> tSeeds;

protected:
    //! Vector of segmented regions subscripted by their indexes.
    tRegions m_Regions;

    //! Vector of seeds.
    tSeeds m_Seeds;

    //! Treshold used for inserting a pixel to a region.
    double m_dThreshold;

    //! Weight used to combine pixel difference and edge detection.
    double m_dDiffWeight;

    //! Weight used to combine edge detection results and simple
    //! pixel difference.
    double m_dEdgeWeight;

    //! Enables/disables region merging after the segmentation.
    bool m_bMerge;

protected:
    //! Creates new seeds from a given one.
    void createSeeds(const SMySeed& Seed,
                     tVolume& Volume,
                     int XDim,
                     int YDim,
                     int ZDim
                     );    
};


} // namespace volseg
} // namespace mds

#endif // MDS_REGIONGROWING_H

