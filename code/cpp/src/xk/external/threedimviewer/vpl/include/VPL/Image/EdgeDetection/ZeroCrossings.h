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
 * Date:    2005/10/07                           
 * 
 * Description:
 * - Zero crossings of the LoG filter.
 */

#ifndef VPL_IED_ZEROCROSSINGS_H
#define VPL_IED_ZEROCROSSINGS_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../PixelTraits.h"
#include "../ImageEdgeDetector.h"
#include "../ImageFiltering.h"

#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Zero crossings of the LoG filter.
 * - Parameter I is a used image type.
 */
template <class I>
class CZeroCrossDetector : public CImageEdgeDetector<I>
{
public:
    //! Image edge detector base.
    typedef CImageEdgeDetector<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

public:
    //! Default constructor.
    //! - Standard deviation ("sigma" parameter) of the LoG filter.
    //! - Threshold for the gradient magnitude.
    CZeroCrossDetector(double dSigma, double dThreshold)
        : m_Filter(dSigma)
        , m_dThreshold(dThreshold)
    {
        VPL_ASSERT(dThreshold <= 1.0 && dThreshold >= 0.0);
    }

    //! Destructor.
    ~CZeroCrossDetector() {}


    //! Edge detection in a given image.
    //! - Returns false on failure
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns LoG filter standard deviation.
    double getSigma() const { return m_Filter.getSigma(); }

    //! Sets the LoG filter standard deviation.
    void setSigma(double dSigma) { m_Filter.setSigma(dSigma); }

    //! Return threshold for the gradient magnitude.
    double getThreshold() { return m_dThreshold; }

    //! Returns gradient magnitude threshold.
    inline void setThreshold(double dThreshold);

protected:
    //! LoG filter.
    CLoGFilter<tImage, CShiftZero2Gray> m_Filter;

    //! Magnitude threshold.
    double m_dThreshold;

protected:
    //! Checks if the pixel is on edge.
    inline bool isEdge(const tImage& Image, tSize x, tSize y);

    //! Computes the gradient magnitude.
    inline double computeGradient(const tImage& Image, tSize x, tSize y);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "ZeroCrossings.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IED_ZEROCROSSINGS_H

