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
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/20                       
 * 
 * Description:
 * - Canny edge detector.
 */

#ifndef VPL_IED_CANNY_H
#define VPL_IED_CANNY_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../PixelTraits.h"
#include "../ImageEdgeDetector.h"
#include "../ImageFiltering.h"
#include "../Vector3.h"

#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Canny edge detector.
 * - Parameter I is a used image type.
 */
template <class I>
class CCanny : public CImageEdgeDetector<I>
{
public:
    //! Image edge detector base.
    typedef CImageEdgeDetector<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

public:
    //! Default constructor.
    //! - Standard deviation ("sigma" parameter) of the Gaussian filter
    //!   which is used for the smoothing.
    //! - Thresholds for the hysteresis (0..1).
    CCanny(double dSigma, double dT1, double dT2)
        : m_GaussFilter(dSigma)
        , m_dT1(dT1)
        , m_dT2(dT2)
    {
        VPL_ASSERT(dT1 <= 1.0 && dT2 <= dT1 && dT2 >= 0.0);
    }

    //! Destructor.
    ~CCanny() {}


    //! Edge detection in a given image.
    //! - Magnitude image is produced.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns smoothing filter standard deviation.
    double getSigma() const { return m_GaussFilter.getSigma(); }

    //! Sets the smoothing filter standard deviation.
    void setSigma(double dSigma) { m_GaussFilter.setSigma(dSigma); }

    //! Returns thresholds of the non-maximal suppression algorithm.
    inline void getThresholds(double& dT1, double& dT2);

    //! Sets thresholds of the non-maximal suppression algorithm.
    inline void setThresholds(double dT1, double dT2);

protected:
    //! Gaussian smoothing filter.
    CGaussFilter<tImage> m_GaussFilter;

    //! Sobel operators.
    CSobelX<tImage, CShiftZero2Gray> m_SobelX;
    CSobelY<tImage, CShiftZero2Gray> m_SobelY;

    //! Thresholds used by hysteresis algorithm.
    double m_dT1, m_dT2;

protected:
    //! Non-maximal suppression.
    void nonMaxSuppression(const tImage& GradImageX,
                           const tImage& GradImageY,
                           tImage& MagnitudeImage,
                           tImage& Image
                           );

    //! Hystersis controlled by two given thresholds.
    //! - Applies the hysteresis to the provided slice. It checks each pixel
    //!   against an upper threshhold 'T1'. If the pixel value is equal
    //!   or higher, the current pixel is an edge pixel. Then all direct
    //!   neighbours of the pixel are compared to a lower threshhold 'T2'
    //!   and if their values are equal or higher than this threshhold,
    //!   they become edge pixels as well.
    //! - In practice the threshold T1 = (2-3) * T2.
    void hysteresis(tImage& MagnitudeImage,
                    tImage& Image,
                    tPixel T1,
                    tPixel T2
                    );

    //! Returns true if any neighbouring pixel has greater value
    //! than a given threshold.
    bool checkNeighbours(tImage& Image, tSize x, tSize y, tPixel T);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Canny.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IED_CANNY_H

