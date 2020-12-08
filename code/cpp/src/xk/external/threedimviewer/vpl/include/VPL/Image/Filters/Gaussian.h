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
 * Date:    2005/09/08                       
 *
 * Description:
 * - Gaussian smoothing filter.
 */

#ifndef VPL_IF_GAUSSIAN_H
#define VPL_IF_GAUSSIAN_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../SeparableImageFilter.h"
#include "../ImageFunctions.h"


#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Gaussian smoothing filter.
 * - Parameter I is a used image type.
 * - Policy N is used for filter response normalization.
 * - Its kernel is defined by the following function: \n
 *                         1                 (x^2 + y^2)  \n
 *   G_sigma(x,y) = ---------------- * exp(- -----------) \n
 *                  2 * pi * sigma^2         2 * sigma^2  \n
 */
template <class I>
class CGaussFilter : public CSeparableImageFilter<I>
{
public:
    //! Image filter base.
    typedef CSeparableImageFilter<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

public:
    //! Constructor that creates Gaussian filter having a specified standard
    //! deviation ("sigma" parameter).
    CGaussFilter(double dSigma)
    {
        VPL_ASSERT(dSigma > 0.0);

        initializeKernels(dSigma);
    }

    //! Constructor that creates Gaussian filter having the standard
    //! deviation corresponding to a given kernel size.
    CGaussFilter(tSize Size)
    {
        initializeKernels(size2Sigma(Size));
    }

    //! Destructor
    ~CGaussFilter() {}


    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tPixel getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    double getSigma() const { return m_dSigma; }

    //! Returns filter standard deviation.
    tSize getSize() const
    {
        return std::max(base::m_kernelX.getSize(), base::m_kernelY.getSize());
    }

    //! Sets the filter size.
    inline void resize(tSize Size);

    //! Sets the filter standard deviation.
    inline void setSigma(double dSigma);


    //! Returns kernel size corresponding to a given sigma parameter.
    inline static tSize sigma2Size(double dSigma);

    //! Returns sigma parameter according to a given kernel size.
    inline static double size2Sigma(tSize Size);

    //! Returns value of the Gaussian function.
    inline static double getGaussianFuncValue(double dX,
                                              double dY,
                                              double dSigma
                                              );

protected:
    //! Standard deviation ("sigma") of the Gaussian filter.
    double m_dSigma;

protected:
    //! Computes the Gaussian filter kernel.
    void initializeKernels(double dSigma);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Gaussian.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IF_GAUSSIAN_H
