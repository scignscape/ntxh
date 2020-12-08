//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/24                          \n
 *
 * $Id: mdsCanny.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Canny edge detector in 3D.
 */

#ifndef MDS_VED_CANNY_H
#define MDS_VED_CANNY_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsPixelTraits.h"
#include "../mdsVolumeEdgeDetector.h"
#include "../mdsVolumeFiltering.h"
#include "../mdsVector3.h"

#include <cmath>


namespace mds
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
        MDS_ASSERT(dT1 <= 1.0 && dT2 <= dT1 && dT2 >= 0.0);
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
#include "mdsCanny.hxx"


} // namespace img
} // namespace mds

#endif // MDS_VED_CANNY_H

