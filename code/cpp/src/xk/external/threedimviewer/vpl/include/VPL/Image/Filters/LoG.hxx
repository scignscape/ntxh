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


//==============================================================================
/*
 * Useful constants.
 */

namespace log_filter
{
//! Conversion of the filter standard deviation to the kernel size.
const double SIGMA2SIZE     = 5.0;

//! Conversion of the kernel size to the standard deviation.
const double SIZE2SIGMA     = 1 / 5.0;

//! Constant -1 / pi.
const double NEG_INV_PI     = -1.0 / vpl::math::PI;
}


//==============================================================================
/*
 * Methods templates.
 */

template <class I, template <typename> class N>
inline void CLoGFilter<I,N>::resize(tSize Size)
{
    CKernel2D::resize(Size);

    initKernel(size2Sigma(Size));
}


template <class I, template <typename> class N>
inline void CLoGFilter<I,N>::setSigma(double dSigma)
{
    VPL_ASSERT(dSigma > 0.0);

    CKernel2D::resize(sigma2Size(dSigma));

    initKernel(dSigma);
}


template <class I, template <typename> class N>
inline tSize CLoGFilter<I,N>::sigma2Size(double dSigma)
{
    tSize Size = tSize(log_filter::SIGMA2SIZE * dSigma) + 1;
    if( (Size % 2) == 1 )
    {
        return Size;
    }
    else
    {
        return Size + 1;
    }
}


template <class I, template <typename> class N>
inline double CLoGFilter<I,N>::size2Sigma(tSize Size)
{
    return log_filter::SIZE2SIGMA * (Size - 1);
}


template <class I, template <typename> class N>
inline double CLoGFilter<I,N>::getLoGFuncValue(double dX,
                                                    double dY,
                                                    double dSigma
                                                    )
{
    double dS = 1.0 / (dSigma * dSigma);
    double dC = -0.5 * dS * (dX * dX + dY * dY);

    return log_filter::NEG_INV_PI * dS * dS * (1.0 + dC) * std::exp(dC);
}


template <class I, template <typename> class N>
void CLoGFilter<I,N>::initKernel(double dSigma)
{
    // Set the standard deviation
    m_dSigma = dSigma;

    // Helper value
    double dS = 1.0 / (dSigma * dSigma);
    double dA = log_filter::NEG_INV_PI * dS * dS;
    double dB = -0.5 * dS;

    // Half of the kernel size
    tSize HalfSize = getSize() / 2;

    // Initialize the filter kernel
    for( tSize j = -HalfSize; j <= HalfSize; ++j )
    {
        for( tSize i = -HalfSize; i <= HalfSize; ++i )
        {
            double dC = dB * (i * i + j * j);
            double dValue = dA * (1.0 + dC) * exp(dC);
            set(i + HalfSize, j + HalfSize, tData(dValue));
        }
    }
}


// Image filtering method
template <class I, template <typename> class N>
bool CLoGFilter<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            tResult Value = getResponse(SrcImage, x, y);
            DstImage.set(x, y, base::normalize(Value));
        }
    }

    // O.K.
    return true;
}
