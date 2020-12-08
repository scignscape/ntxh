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
 * - Laplacian of Gaussian filter.
 */

#ifndef VPL_IF_LOG_H
#define VPL_IF_LOG_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../ImageFilter.h"
#include "../ImageFunctions.h"
#include "../Kernel.h"

#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Laplacian of Gaussian image filter.
 * - Parameter I is a used image type.
 * - Policy N is used for filter response normalization.
 * - Its kernel is defined by the following equation: \n
 *                         1               x^2 + y^2            x^2 + y^2
 *   L_sigma(x,y) = - ------------ * [1 - -----------] * exp(- -----------) \n
 *                    pi * sigma^4        2 * sigma^2          2 * sigma^2  \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CLoGFilter
    : public CNormImageFilter<I,N>
    , public CKernel2D
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

public:
    //! Constructor that creates Log filter having a given standard
    //! deviation ("sigma" parameter).
    CLoGFilter(double dSigma) : CKernel2D(sigma2Size(dSigma))
    {
        VPL_ASSERT(dSigma > 0.0);

        initKernel(dSigma);
    }

    //! Constructor that creates a Gaussian filter having the standard
    //! deviation corresponding to a given kernel size.
    CLoGFilter(tSize Size) : CKernel2D(Size)
    {
        initKernel(size2Sigma(Size));
    }

    //! Destructor
    ~CLoGFilter() {}


    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tResult getResponse(const tImage& SrcImage, tSize x, tSize y)
    {
        // Compute filter response
        return convolve<tResult>(SrcImage, x, y, *this);
    }

    //! Returns filter standard deviation.
    double getSigma() const { return m_dSigma; }

    //! Sets the filter size.
    inline void resize(tSize Size);

    //! Sets the filter standard deviation.
    inline void setSigma(double dSigma);


    //! Returns kernel size corresponding to a given sigma parameter.
    inline static tSize sigma2Size(double dSigma);

    //! Returns sigma parametr according to a given kernel size.
    inline static double size2Sigma(tSize Size);

    //! Returns value of the Laplacian of Gaussian function.
    inline static double getLoGFuncValue(double dX, double dY, double dSigma);

protected:
    //! Standard deviation ("sigma") of the Gaussian filter.
    double m_dSigma;

protected:
    //! Computes the LoG filter kernel.
    void initKernel(double dSigma);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "LoG.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IF_LOG_H

