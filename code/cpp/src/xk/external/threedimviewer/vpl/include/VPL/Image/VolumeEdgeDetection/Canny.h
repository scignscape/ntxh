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
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/24                       
 *
 * Description:
 * - Canny edge detector in 3D.
 */

#ifndef VPL_VED_CANNY_H
#define VPL_VED_CANNY_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../PixelTraits.h"
#include "../VolumeEdgeDetector.h"
#include "../VolumeFiltering.h"
#include "../Vector3.h"

#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Canny edge detector in 3D space.
 * - Parameter V is a used volume type.
 */
template <class V>
class CVolumeCanny : public CVolumeEdgeDetector<V>
{
public:
    //! Volume filter base.
    typedef CVolumeEdgeDetector<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

    //! Size of the processing block (volume window). The input volume
    //! is divided into smaller blocks - cubes for the processing.
    //! - This is used to reduce amount of the memory required by the
    //!   filtering.
//    enum { BLOCK_SIZE = 64 };
    enum { BLOCK_SIZE = 128 };

public:
    //! Default constructor.
    //! - Thresholds for the hysteresis (0..1).
    CVolumeCanny(double dT1, double dT2)
        : m_dT1(dT1)
        , m_dT2(dT2)
    {
        VPL_ASSERT(dT1 <= 1.0 && dT2 <= dT1 && dT2 >= 0.0);
    }

    //! Destructor.
    ~CVolumeCanny() {}

    //! Edge detection.
    //! - Magnitude volume is produced.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns thresholds of the non-maximal suppression algorithm.
    inline void getThresholds(double& dT1, double& dT2);

    //! Sets thresholds of the non-maximal suppression algorithm.
    inline void setThresholds(double dT1, double dT2);

protected:
    //! Gaussian smoothing filter.
    CVolumeGauss3Filter<tVolume> m_GaussFilter;

    //! Sobel operators.
    CVolumeSobelX<tVolume, CShiftZero2Gray> m_SobelX;
    CVolumeSobelY<tVolume, CShiftZero2Gray> m_SobelY;
    CVolumeSobelZ<tVolume, CShiftZero2Gray> m_SobelZ;

    //! Thresholds used by hysteresis algorithm.
    double m_dT1, m_dT2;

protected:
    //! Non-maximal suppression.
    void nonMaxSuppression(const tVolume& GradVolumeX,
                           const tVolume& GradVolumeY,
                           const tVolume& GradVolumeZ,
                           tVolume& MagnitudeVolume,
                           tVolume& Volume,
                           tSize x,
                           tSize y,
                           tSize z,
                           tSize XSize,
                           tSize YSize,
                           tSize ZSize
                           );

    //! Hystersis controlled by two given thresholds.
    //! - Applies the hysteresis to the provided volume. It checks each voxel
    //!   against an upper threshhold 'T1'. If the voxel value is equal
    //!   or higher, the current voxel is an edge voxel. Then all direct
    //!   neighbours of the voxel are compared to a lower threshhold 'T2'
    //!   and if their values are equal or higher than this threshhold,
    //!   they become edge voxels as well.
    //! - In practice the threshold T1 = (2-3) * T2.
    void hysteresis(tVolume& MagnitudeVolume,
                    tVolume& Volume,
                    tSize x,
                    tSize y,
                    tSize z,
                    tSize XSize,
                    tSize YSize,
                    tSize ZSize,
                    tVoxel T1,
                    tVoxel T2
                    );

    //! Returns true if any neighbouring voxel has greater value
    //! than a given threshold.
    bool checkNeighbours(tVolume& Volume,
                         tSize x,
                         tSize y,
                         tSize z,
                         tVoxel T
                         );
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Canny.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_VED_CANNY_H

