//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/26                          \n
 *
 * $Id: mdsGaussian.hxx 2105 2012-02-18 06:36:50Z spanel $
 * 
 * Description:
 * - 3D Gaussian smoothing filter.
 */


//==============================================================================
/*
 * Useful constants.
 */

namespace gaussian
{
//! Conversion of the filter standard deviation to the kernel size.
const double SIGMA2SIZE        = 5.0;

//! Conversion of the kernel size to the standard deviation.
const double SIZE2SIGMA        = 1 / 5.0;
}


//==============================================================================
/*
 * Methods templates.
 */

template <class V>
inline void CVolumeGaussFilter<V>::resize(tSize Size)
{
    CKernel2D::create(Size);

    initKernel(size2Sigma(Size));
}


template <class V>
inline void CVolumeGaussFilter<V>::setSigma(double dSigma)
{
    MDS_ASSERT(dSigma > 0.0);

    CKernel2D::create(sigma2Size(dSigma));

    initKernel(dSigma);
}


template <class V>
inline tSize CVolumeGaussFilter<V>::sigma2Size(double dSigma)
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


template <class V>
inline double CVolumeGaussFilter<V>::size2Sigma(tSize Size)
{
    return gaussian::SIZE2SIGMA * (Size - 1);
}


template <class V>
inline double CVolumeGaussFilter<V>::getGaussianFuncValue(double dX,
                                                            double dY,
                                                            double dZ,
                                                            double dSigma
                                                            )
{
    static const double dConst = 1.0 / pow(mds::math::TWO_PI, 1.5);

    double dS3 = 1.0 / (dSigma * dSigma * dSigma);
    double dS2 = dS2 * dSigma;

    return dConst * dS3 * exp(-0.5 * dS2 * (dX * dX + dY * dY + dZ * dZ));
}


template <class V>
void CVolumeGaussFilter<V>::initKernel(double dSigma)
{
    static const double dConst = 1.0 / pow(mds::math::TWO_PI, 1.5);

    // Set the standard deviation
    m_dSigma = dSigma;

    // Helper values
    double dS3 = 1.0 / (dSigma * dSigma * dSigma);
    double dS2 = dS3 * dSigma;
    double dA = dConst * dS3;
    double dB = -0.5 * dS2;

    // Half of the kernel size
    tSize HalfSize = getSize() / 2;

    // Initialize the filter kernel
    for( tSize k = -HalfSize; k <= HalfSize; ++k )
    {
        for( tSize j = -HalfSize; j <= HalfSize; ++j )
        {
            for( tSize i = -HalfSize; i <= HalfSize; ++i )
            {
                double dValue = dA * exp(dB * (i * i + j * j + k * k));
                set(i + HalfSize, j + HalfSize, k + HalfSize, tData(dValue));
            }
        }
    }
}


// Volume filtering method
template <class V>
bool CVolumeGaussFilter<V>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    CProgress::tProgressInitializer StartProgress(*this);

    // Volume size
    tSize XCount = mds::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YCount = mds::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZCount = mds::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());

    // Initialize the progress observer
    CProgress::setProgressMax(ZCount);

    // Filter the image
    for( tSize z = 0; z < ZCount; ++z )
    {
#pragma omp parallel for schedule(static) default(shared)
        for( tSize y = 0; y < YCount; ++y )
        {
            for( tSize x = 0; x < XCount; ++x )
            {
                DstVolume.set(x, y, z, getResponse(SrcVolume, x, y, z));
            }
        }

        // Notify progress observers...
        if( !CProgress::progress() )
        {
            return false;
        }
    }

    // O.K.
    return true;
}


//==============================================================================
/*
 * Methods templates.
 */

// Filter kernel
template <class V>
const CKernel3D::tData CVolumeGauss3Filter<V>::KERNEL[] =
{
    0.0f,  1.0f,  0.0f,
    1.0f,  3.0f,  1.0f,
    0.0f,  1.0f,  0.0f,

    1.0f,  3.0f,  1.0f,
    3.0f,  9.0f,  3.0f,
    1.0f,  3.0f,  1.0f,

    0.0f,  1.0f,  0.0f,
    1.0f,  3.0f,  1.0f,
    0.0f,  1.0f,  0.0f
};


// Volume filtering method
template <class V>
bool CVolumeGauss3Filter<V>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    CProgress::tProgressInitializer StartProgress(*this);

    // Volume size
    tSize XCount = mds::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YCount = mds::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZCount = mds::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());

    // Initialize the progress observer
    CProgress::setProgressMax(ZCount);

    // Filter the volume
    for( tSize z = 0; z < ZCount; ++z )
    {
#pragma omp parallel for schedule(static) default(shared)
        for( tSize y = 0; y < YCount; ++y )
        {
            for( tSize x = 0; x < XCount; ++x )
            {
                DstVolume.set(x, y, z, getResponse(SrcVolume, x, y, z));
            }
        }

        // Notify progress observers...
        if( !CProgress::progress() )
        {
            return false;
        }
    }

    // O.K.
    return true;
}


// Volume filter response
template <class V>
typename CVolumeGauss3Filter<V>::tVoxel CVolumeGauss3Filter<V>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    // Output normalization
    static const CKernel3D::tData Denom = 1.0f / DENOM;

    // Filter kernel
    static const CKernel3D Kernel(KERNEL, getSize());

    // Compute filter response
    return tVoxel(Denom * convolve<CKernel3D::tData>(SrcVolume, x, y, z, Kernel));
}

