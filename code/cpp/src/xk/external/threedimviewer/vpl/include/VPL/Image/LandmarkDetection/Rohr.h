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
 * - Volume corner/landmark detector based on Rohr's 3D differential operators.
 * - Algorithm is partially similar to the well-known Harris image corner detector.
 */

#ifndef VPL_LD_ROHR_H
#define VPL_LD_ROHR_H

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
 * - Volume 3D corner/landmark detector based on Rohr's 3D differential operators.
 * - Algorithm is partially similar to the well-known Harris image corner detector.
 * - Parameter V is a used volume type.
 */
template <class V>
class CRohrLandmarks : public CLandmarkDetector<V>
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

public:
    //! Default constructor.
    //! - Size of the window (must be an odd number) used to estimate eigen values.
    //! - Cornerness threshold.
    //! - Threshold used to suppress landmarks on edges.
    CRohrLandmarks(tSize Size, double dThreshold, double dEdgeThreshold)
        : m_WindowSize(Size)
        , m_dThreshold(dThreshold)
        , m_dEdgeThreshold(dEdgeThreshold)
    {
        VPL_ASSERT(Size > 0 && vpl::math::isOdd(Size)
            && dThreshold >= 0.0 && dThreshold <= 1.0
            && dEdgeThreshold >= 0.0 && dEdgeThreshold <= 1.0
            );
    }

    //! Destructor.
    ~CRohrLandmarks() {}


    //! Volume landmark detection.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tCorners& Corners);

    //! Evaluates cornerness function of all voxels.
    //! - Returns false on failure. 
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns cornerness threshold.
    double getThreshold() const { return m_dThreshold; }

    //! Sets cornerness threshold.
    inline void setThreshold(double dThreshold);

    //! Returns threshold used for suppression of landmarks lying on edges.
    double getEdgeThreshold() const { return m_dEdgeThreshold; }

    //! Sets threshold used for suppression of landmarks lying on edges.
    inline void setEdgeThreshold(double dEdgeThreshold);

protected:
    //! Sobel operators.
    CVolumeDiffXFilter<CFVolume> m_SobelX;
    CVolumeDiffYFilter<CFVolume> m_SobelY;
    CVolumeDiffZFilter<CFVolume> m_SobelZ;

    //! Size of the window used to estimate eigen values.
    tSize m_WindowSize;

    //! Corner detector parameters.
    double m_dThreshold, m_dEdgeThreshold;

protected:
    //! Returns true if any neighbouring voxel has greater value
    //! than a given threshold.
    inline bool checkNeighbours(CFVolume& Volume,
                                tSize x,
                                tSize y,
                                tSize z,
                                tFloatPixel T
                                );
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Rohr.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_LD_ROHR_H

