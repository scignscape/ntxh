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


//==============================================================================
/*
 * Useful constants.
 */

namespace gaussian
{
//! Conversion of the filter standard deviation to the kernel size.
const double SIGMA2SIZE     = 5.0;

//! Conversion of the kernel size to the standard deviation.
const double SIZE2SIGMA     = 1 / 5.0;

//! Constant 1 / (2 * pi).
const double INV_TWO_PI     = 1.0 / vpl::math::TWO_PI;
}


//==============================================================================
/*
 * Methods templates.
 */

template <class I>
inline void CGaussFilter<I>::resize(tSize Size)
{
    initializeKernels(size2Sigma(Size));
}


template <class I>
inline void CGaussFilter<I>::setSigma(double dSigma)
{
    VPL_ASSERT(dSigma > 0.0);

    initializeKernels(dSigma);
}


template <class I>
inline tSize CGaussFilter<I>::sigma2Size(double dSigma)
{
    tSize Size = tSize(gaussian::SIGMA2SIZE * dSigma) + 1;
    if( (Size % 2) == 1 )
    {
        return Size;
    }
    else
    {
        return Size + 1;
    }
}


template <class I>
inline double CGaussFilter<I>::size2Sigma(tSize Size)
{
    return gaussian::SIZE2SIGMA * (Size - 1);
}


template <class I>
inline double CGaussFilter<I>::getGaussianFuncValue(double dX,
                                                           double dY,
                                                           double dSigma
                                                           )
{
    double dS = 1.0 / (dSigma * dSigma);

    return gaussian::INV_TWO_PI * dS * std::exp(-0.5 * dS * (dX * dX + dY * dY));
}


template <class I>
void CGaussFilter<I>::initializeKernels(double dSigma)
{
    // Set the standard deviation
    m_dSigma = dSigma;

    // Helper values
    double dS = 1.0 / (dSigma * dSigma);
    double dA = gaussian::INV_TWO_PI * dS;
    double dB = -0.5 * dS;

    // Compute 1D kernel sizes
    double dsize(sigma2Size(m_dSigma));
    double max_size(std::max(base::m_dDX, base::m_dDY));

    VPL_ASSERT(max_size > 0.0 && dsize > 0.0);

    double scaleX(max_size / base::m_dDX);
    
    vpl::tSize xsize(dsize * scaleX);
    if((xsize % 2) != 1) ++xsize;

    double scaleY(max_size / base::m_dDY);

    vpl::tSize ysize(dsize * scaleY);
    if((ysize % 2) != 1) ++ysize;

    // Create kernels
    base::m_kernelX.resize(xsize);
    base::m_kernelY.resize(ysize);
    
    // Initialize x kernel
    tSize HalfSize = base::m_kernelX.getSize()/ 2;
    for(tSize x = -HalfSize; x <= HalfSize; ++x)
    {
        double dValue = dA * std::exp( dB * x*x / (base::m_scaleX * base::m_scaleX));
        base::m_kernelX.set(x + HalfSize, dValue);
    }

    base::m_kernelX.normalize();

    // Initialize y kernel
    HalfSize = base::m_kernelY.getSize()/ 2;
    for(tSize y = -HalfSize; y <= HalfSize; ++y)
    {
        double dValue = dA * std::exp( dB * y*y / (base::m_scaleY * base::m_scaleY));
        base::m_kernelY.set(y + HalfSize, dValue);
    }

    base::m_kernelY.normalize();
}


// Image filtering method
template <class I>
bool CGaussFilter<I>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    if(XCount == 0 || YCount == 0)
        return false;

    // This initializes kernel
    getResponse(SrcImage, 0, 0);

    CFImage buffer(XCount, YCount, SrcImage.getMargin());
    buffer.fillEntire(0.0f);

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            //DstImage.set(x, y, getResponse(SrcImage, x, y));
            buffer.set(x, y, convolveX<float, tImage>(SrcImage, x, y, base::m_kernelX));
        }
    }

#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            //DstImage.set(x, y, getResponse(SrcImage, x, y));
            DstImage.set(x, y, convolveY<float, CFImage>(buffer, x, y, base::m_kernelY));
        }
    }

    // O.K.
    return true;
}


template <class I>
typename CGaussFilter<I>::tPixel CGaussFilter<I>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    tSize hsy(base::m_kernelY.getSize() >> 1);

    float sum(0.0f);

    // Compute vertical convolution
    for(tSize j = -hsy; j <= hsy; ++j)
    {
        float response(convolveX<float, tImage>(SrcImage, x, y + j, base::m_kernelX));
        sum += response * base::m_kernelY.at(j + hsy);
    }

    return tPixel(sum);
}
