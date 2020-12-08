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
 *          Miroslav Svub, xsvubm00@stud.fit.vutbr.cz  \n
 * Date:    2004/10/24                              
 *
 * File description:
 * - Simple segmentation method based on histogram thresholding.
 */

#ifndef VPL_HISTOGRAMTHRESHOLDING_H
#define VPL_HISTOGRAMTHRESHOLDING_H

#include <VPL/Base/Setup.h>
#include <VPL/Base/Assert.h>
#include <VPL/Image/Image.h>

// STL
#include <iostream>
#include <cstring>
#include <list>


namespace vpl
{
namespace imseg
{

//==============================================================================
/*!
 * Class encapsulating a simple segmentation method based on histogram
 * thresholding.
 */
class CHistogramThresholding
{
public:
    //! Image type
    typedef vpl::img::CDImage tImage;

    //! Image pixel type
    typedef vpl::img::CDImage::tPixel tPixel;

public:
    //! Default constructor
    CHistogramThresholding(const int iTresholds, const int iColumns)
        : m_iTresholds(iTresholds)
        , m_iColumns(iColumns)
    {}

    //! Virtual destructor
    virtual ~CHistogramThresholding() {}

    //! Segmentation of a given image
    //! - Pixel values of the output/destination image represent segment indexes
    //! - Returns false on failure
    bool operator()(const tImage& SrcImage, tImage& DstImage);

protected:
    //! Histogram column description.
    struct SColumn
    {
        //! The number of pixels in the column.
        int m_iCount;

        //! Minimal and maximal pixel value.
        tPixel m_Min, m_Max;

        //! Default constructor.
        SColumn() : m_iCount(0), m_Min(0), m_Max(0) {}

        //! Initializes the column.
        void set(const int iCount, const tPixel Min, const tPixel Max)
        {
            m_iCount = iCount;
            m_Min = Min;
            m_Max = Max;
        }

        //! Increases the number of pixels in the column.
        void add(const int iCount) { m_iCount += iCount; }

        //! Counts distance between two column peaks.
        double getDistance(const SColumn& rhs);
    };

    //! Histogram definition.
    typedef std::list<SColumn> tHistList;

protected:
    //! The number of tresholds.
    int m_iTresholds;

    //! Histogram resolution.
    int m_iColumns;
};


} // namespace imseg
} // namespace vpl

#endif // VPL_HISTOGRAMTHRESHOLDING_H

