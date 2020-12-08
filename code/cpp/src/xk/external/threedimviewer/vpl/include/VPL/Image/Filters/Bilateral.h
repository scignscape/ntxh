/* This file is part of
 *
 * VPL - Voxel Processing Library
 * Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef VPL_IF_BILATERAL_H
#define VPL_IF_BILATERAL_H

#include "../ImageFilter.h"
#include "../Kernel.h"

namespace vpl
{
namespace img
{

/**
 * This class template implements bilateral filter. BF is a edge preserving, noise reducing non-linear filter.
 * The density value for each pixel in a volume is replaced by a weighted average of intensity values from nearby pixels. 
 * This weights are based on a Gaussian distribution of the pixel density values.
 *
 * I = 1/W Sum( Ii * Fr (|Ii - Ix|) * Gs(|Xi - X|) )
 *
 * W = Sum( (|Ii - Ix|) * Gs(|Xi - X|) )
 *
 * Where:
 * I    - is new intensity value
 * W    - is normalization term 
 * Sum  - sum for all pixels in the neighborhood
 * Fr   - range kernel for smoothing differences in intenisty (gaussian function is used)
 * Ii   - current pixel intensity
 * Ix   - replaced pixel intensity
 * Gs   - spatial kernel for smoothing differences in coordinates (gaussian function is used)
 * Xi   - replaced pixel coordinate
 * X    - current pixel coordinate
 */
template<class I>
class CBilateralFilter : public CImageFilter<I>
{
public:
    //! Image filter base.
    typedef CImageFilter<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

public:
    //! Constructor
    CBilateralFilter(double sigma_range, double sigma_distance);

    //! Destructor
    ~CBilateralFilter() {}


    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tPixel getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation - distance domain.
    double getSigmaDistance() const { return m_sigmaD; }

    //! Sets the filter standard deviation - distance domain.
    inline void setSigmaDistance(double dSigma);

    //! Returns filter standard deviation - range (density) domain.
    double getSigmaRange() const { return m_sigmaR; }

    //! Sets the filter standard deviation - range (density) domain.
    inline void setSigmaRange(double dSigma) {m_sigmaR = dSigma;}

    //! Returns filter standard deviation.
    tSize getSize() const { return std::max(m_wx, m_wy); }

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
    CKernel2D m_gaussianKernel;

    //! Range sigma
    double m_sigmaR;

    //! Distance domain sigma
    double m_sigmaD;

    //! Window sizes
    tSize m_wx, m_wy;

}; // class CBilateralFilter

//==============================================================================
/*
 * Methods templates.
 */

#include "Bilateral.hxx"

}
}

#endif // VPL_IF_BILATERAL_H
