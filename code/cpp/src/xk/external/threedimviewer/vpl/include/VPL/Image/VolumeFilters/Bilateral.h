/* This file is part of
 *
 * VPL - Voxel Processing Library
 * Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef VPL_VF_BILATERAL_H
#define VPL_VF_BILATERAL_H

#include "../VolumeFilter.h"
#include "../Kernel.h"
#include <VPL/Math/Base.h>

namespace vpl
{
namespace img
{

/**
 * This class template implements bilateral filter. BF is a edge preserving, noise reducing non-linear filter.
 * The density value for each voxel in a volume is replaced by a weighted average of intensity values from nearby voxels. 
 * This weights are based on a Gaussian distribution of the voxel density values.
 *
 * I = 1/W Sum( Ii * Fr (|Ii - Ix|) * Gs(|Xi - X|) )
 *
 * W = Sum( (|Ii - Ix|) * Gs(|Xi - X|) )
 *
 * Where:
 * I    - is new intensity value
 * W    - is normalization term 
 * Sum  - sum for all voxels in the neighborhood
 * Fr   - range kernel for smoothing differences in intenisty (gaussian function is used)
 * Ii   - current voxel intensity
 * Ix   - replaced voxel intensity
 * Gs   - spatial kernel for smoothing differences in coordinates (gaussian function is used)
 * Xi   - replaced voxel coordinate
 * X    - current voxel coordinate
 */
template<class V>
class CVolumeBilateralFilter : public CVolumeFilter<V>
{
public:
    //! Volume filter base.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

    //! Subvolume block size
    enum { BLOCK_SIZE = 128 };

public:
    //! Constructor
    CVolumeBilateralFilter(double sigma_range, double sigma_spatial);

    //! Destructor
    ~CVolumeBilateralFilter() {}


    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tVoxel getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter standard deviation - distance domain.
    double getSigmaDistance() const { return m_sigmaD; }

    //! Sets the filter standard deviation - distance domain.
    inline void setSigmaDistance(double dSigma);

    //! Returns filter standard deviation - range (density) domain.
    double getSigmaRange() const { return m_sigmaR; }

    //! Sets the filter standard deviation - range (density) domain.
    inline void setSigmaRange(double dSigma) {m_sigmaR = dSigma;}

    //! Returns filter standard deviation.
    tSize getSize() const { return std::max(m_wx, std::max(m_wy, m_wz)); }

    //! Sets the filter size.
    inline void resize(tSize Size);

    //! Returns kernel size corresponding to a given sigma parameter.
    inline static tSize sigma2Size(double dSigma);

    //! Returns sigma parameter according to a given kernel size.
    inline static double size2Sigma(tSize Size);

protected:
    //! Recompute kernel and store window parameters
    void initializeKernel(double sigmaR, double sigmaS);

protected:
    //! Used precomputed gaussian kernel
    CKernel3D m_gaussianKernel;

    //! Range (density) sigma
    double m_sigmaR;

    //! Distance sigma
    double m_sigmaD;

    //! Window sizes
    tSize m_wx, m_wy, m_wz;

}; // class CBilateralFilter

//==============================================================================
/*
 * Methods templates.
 */

#include "Bilateral.hxx"

}
}

#endif // VPL_VF_BILATERAL_H
