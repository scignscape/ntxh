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
 * Medical Data Segmentation Toolkit (MDSTk)          
 * Copyright (c) 2003-2005 by Michal Spanel           
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz        
 *          Martin Skotnica, xskotn01@stud.fit.vutbr.cz  \n
 * File:    mdsRegionGrowing.h                        
 * Section: mSliceSegRG                               
 * Date:    2004/03/01                                
 *
 * Description:
 * - Simple segmentation method based on region growing and merging.
 */

#ifndef VPL_REGIONGROWING_H
#define VPL_REGIONGROWING_H

#include <VPL/Base/Setup.h>
#include <VPL/Base/Assert.h>
#include <VPL/Image/Image.h>
#include <VPL/Image/Utilities/BlobLabeling.h>

// STL
#include <map>
#include <deque>
#include <vector>


namespace vpl
{
namespace imseg
{

//==============================================================================
/*
 * Global variables and definitions.
 */

//! Structure encapsulating an image point.
struct SMySeed
{
    //! Point position.
    vpl::tSize m_x, m_y;

    //! Region index.
    int m_iIndex;

    //! Default constructor.
    SMySeed() : m_x(0), m_y(0), m_iIndex(0) {}

    //! Constructor.
    SMySeed(tSize x,
            tSize y,
            int iIndex
            )
        : m_x(x)
        , m_y(y)
        , m_iIndex(iIndex)
    {}
};


//! Information on a region of image points.
struct SMyRegion
{
    //! Total sum of pixels.
    double m_dTotal;

    //! The number of pixels in the region.
    long int m_liCount;

    //! Precomputed mean value.
    double m_dMean;

    //! Default constructor.
    SMyRegion() : m_dTotal(0.0), m_liCount(0), m_dMean(0.0) {}

    //! Constructor.
    SMyRegion(const int iValue)
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
class CRegionGrowing
{
public:
    //! Image type
    typedef vpl::img::CDImage tImage;

    //! Image pixel type
    typedef vpl::img::CDImage::tPixel tPixel;

public:
    //! Constructor
    CRegionGrowing(double dDiffWeight,
                   double dEdgeWeight,
                   double dThreshold,
                   bool bMerge = false
                   );

    //! Virtual destructor
    virtual ~CRegionGrowing() {}

    //! Segmentation of a given image
    //! - pixel values of the output/destination image represent segment indexes
    //! - returns false on failure
    bool operator()(const tImage& SrcImage, tImage& DstImage);

protected:
    //! Vector of segmented regions subscripted by their indexes.
    typedef vpl::img::CBlobLabeling<SMyRegion> tRegions;

    //! Queue of seeds
    typedef std::deque<SMySeed> tSeeds;

protected:
    //! Vector of segmented regions subscripted by their indexes
    tRegions m_Regions;

    //! Vector of seeds
    tSeeds m_Seeds;

    //! Treshold used for inserting a pixel to a region
    double m_dThreshold;

    //! Weight used to combine pixel difference and edge detection
    double m_dDiffWeight;

    //! Weight used to combine edge detection results and simple
    //! pixel difference.
    double m_dEdgeWeight;

    //! Enables/disables region merging after the segmentation
    bool m_bMerge;

protected:
    //! Creates new seeds from a given one
    void createSeeds(SMySeed& Seed,
                     tImage& Image,
                     int XDim,
                     int YDim
                     );
};


} // namespace imseg
} // namespace vpl

#endif // VPL_REGIONGROWING_H

