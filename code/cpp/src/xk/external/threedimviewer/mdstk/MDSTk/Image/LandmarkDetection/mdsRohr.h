//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/07/03                          \n
 *
 * $Id: mdsRohr.h 2065 2012-02-02 23:29:38Z spanel $
 *
 * Description:
 * - Volume corner/landmark detector based on Rohr's 3D differential operators.
 * - Algorithm is partially similar to the well-known Harris image corner detector.
 */

#ifndef MDS_LD_ROHR_H
#define MDS_LD_ROHR_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>
#include <MDSTk/Math/mdsStaticMatrix.h>
#include <MDSTk/Math/mdsMatrixFunctions.h>

#include "../mdsPixelTraits.h"
#include "../mdsLandmarkDetector.h"
#include "../mdsVolumeFiltering.h"

#include <cmath>


namespace mds
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
        MDS_ASSERT(Size > 0 && mds::math::isOdd(Size)
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
#include "mdsRohr.hxx"


} // namespace img
} // namespace mds

#endif // MDS_LD_ROHR_H

