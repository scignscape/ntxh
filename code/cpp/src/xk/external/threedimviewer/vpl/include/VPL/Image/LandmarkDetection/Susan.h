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
 * Copyright (c) 2003-2007 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/07/03                       
 *
 * Description:
 * - Volume corner/landmark detector based on Susan image corner detector.
 */

#ifndef VPL_LD_SUSAN_H
#define VPL_LD_SUSAN_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>
#include <VPL/Math/StaticMatrix.h>
#include <VPL/Math/MatrixFunctions.h>

#include "../PixelTraits.h"
#include "../LandmarkDetector.h"
#include "../VolumeFiltering.h"

#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * - Volume corner/landmark detector based on Susan image corner detector.
 * - Parameter V is a used volume type.
 */
template <class V>
class CSusanLandmarks : public CLandmarkDetector<V>
{
public:
    //! Volume filter base.
    typedef CLandmarkDetector<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tCorners tCorners;

    //! Size of the processing block (volume window). The input volume
    //! is divided into smaller blocks - cubes for the processing.
    //! - This is used to reduce amount of the memory required by the
    //!   filtering.
    enum { BLOCK_SIZE = 64 };

    //! Maximal value stored in the internal lookup table.
    enum { MAX_LUT = 255 };

    //! Size of the internal lookup table.
    enum { LUT_SIZE = 2 * MAX_LUT + 1 };

    //! Threshold used to suppress non-corner points.
    enum { DIFF_THRESHOLD = 700 };

public:
    //! Default constructor.
    //! - Detection threshold.
    //! - Third parameter affects evaluation of difference of two voxels.
    inline CSusanLandmarks(double dThreshold, double dWidth = 20.0);

    //! Destructor.
    ~CSusanLandmarks() {}


    //! Volume landmark detection.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tCorners& Corners);

    //! Returns cornerness threshold.
    double getThreshold() { return m_dThreshold; }

    //! Sets cornerness threshold.
    inline void setThreshold(double dThreshold);

    //! Returns the width parameter.
    double getWidth() { return m_dWidth; }

    //! Sets the width parameter.
    inline void setWidth(double dWidth);

protected:
    //! Corner detector parameters.
    double m_dThreshold, m_dWidth, m_dInvWidth;

    //! Internal lookup table used for fast computation of the exp() function.
    vpl::math::CStaticVector<int, LUT_SIZE> m_LUT;

protected:
    //! Returns true if any neighbouring voxel has greater value
    //! than a given threshold.
    inline bool checkNeighbours(CFVolume& Volume,
                                tSize x,
                                tSize y,
                                tSize z,
                                tFloatPixel T
                                );

    //! Initializes internal lookup table.
    void initLUT();

    //! Returns difference of two given pixels.
    inline int getDiff(tPixel8 a, tPixel8 b);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Susan.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_LD_SUSAN_H

