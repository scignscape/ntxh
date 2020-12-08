//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/08                          \n
 *
 * $Id: mdsGaussian.hxx 2084 2012-02-13 10:23:58Z spanel $
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
const double INV_TWO_PI     = 1.0 / mds::math::TWO_PI;
}


//==============================================================================
/*
 * Methods templates.
 */

template <class I>
inline void CGaussFilter<I>::resize(tSize Size)
{
    CKernel2D::create(Size);

    initKernel(size2Sigma(Size));
}


template <class I>
inline void CGaussFilter<I>::setSigma(double dSigma)
{
    MDS_ASSERT(dSigma > 0.0);

    CKernel2D::create(sigma2Size(dSigma));

    initKernel(dSigma);
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
void CGaussFilter<I>::initKernel(double dSigma)
{
    // Set the standard deviation
    m_dSigma = dSigma;

    // Helper values
    double dS = 1.0 / (dSigma * dSigma);
    double dA = gaussian::INV_TWO_PI * dS;
    double dB = -0.5 * dS;

    // Half of the kernel size
    tSize HalfSize = getSize() / 2;

    // Initialize the filter kernel
    for( tSize j = -HalfSize; j <= HalfSize; ++j )
    {
        for( tSize i = -HalfSize; i <= HalfSize; ++i )
        {
            double dValue = dA * std::exp(dB * (i * i + j * j));
            set(i + HalfSize, j + HalfSize, tData(dValue));
        }
    }
}


// Image filtering method
template <class I>
bool CGaussFilter<I>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = mds::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = mds::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            DstImage.set(x, y, getResponse(SrcImage, x, y));
        }
    }

    // O.K.
    return true;
}

