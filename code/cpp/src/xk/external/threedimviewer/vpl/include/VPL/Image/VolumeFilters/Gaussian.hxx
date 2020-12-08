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
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/26                       
 * 
 * Description:
 * - 3D Gaussian smoothing filter.
 */


//==============================================================================
/*
 * Useful constants.
 */

namespace gaussian3D
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
    initializeKernels(size2Sigma(Size));
}


template <class V>
inline void CVolumeGaussFilter<V>::setSigma(double dSigma)
{
    VPL_ASSERT(dSigma > 0.0);

    initializeKernels(dSigma);
}


template <class V>
inline tSize CVolumeGaussFilter<V>::sigma2Size(double dSigma)
{
    tSize Size = tSize(gaussian3D::SIGMA2SIZE * dSigma) + 1;
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
    return gaussian3D::SIZE2SIGMA * (Size - 1);
}


template <class V>
inline double CVolumeGaussFilter<V>::getGaussianFuncValue(double dX,
                                                            double dY,
                                                            double dZ,
                                                            double dSigma
                                                            )
{
    static const double dConst = 1.0 / pow(vpl::math::TWO_PI, 1.5);

    double dS3 = 1.0 / (dSigma * dSigma * dSigma);
    double dS2 = dS3 * dSigma;

    return dConst * dS3 * exp(-0.5 * dS2 * (dX * dX + dY * dY + dZ * dZ));
}


template <class V>
void CVolumeGaussFilter<V>::initializeKernels(double dSigma)
{
    // Set the standard deviation
    m_dSigma = dSigma;

    // Helper values
    const double INV_TWO_PI = 1.0 / vpl::math::TWO_PI;
    double dS = 1.0 / (dSigma * dSigma);
    double dA = INV_TWO_PI * dS;
    double dB = -0.5 * dS;

    // Compute 1D kernels sizes
    tSize dsize(sigma2Size(m_dSigma));
    base::initKernels(dsize);

    // Initialize x kernel
    tSize HalfSize = base::m_kernelX.getSize() / 2;
    for(tSize x = -HalfSize; x <= HalfSize; ++x)
    {
        double dValue = dA * std::exp( dB * x*x / (base::m_scaleX * base::m_scaleX));
        base::m_kernelX.set(x + HalfSize, dValue);
    }
    
    base::m_kernelX.normalize();

    // Initialize y kernel
    HalfSize = base::m_kernelY.getSize() / 2;
    for(tSize y = -HalfSize; y <= HalfSize; ++y)
    {
        double dValue = dA * std::exp( dB * y*y / (base::m_scaleY * base::m_scaleY));
        base::m_kernelY.set(y + HalfSize, dValue);
    }
    
    base::m_kernelY.normalize();

    // Initialize z kernel
    HalfSize = base::m_kernelZ.getSize() / 2;
    for(tSize z = -HalfSize; z <= HalfSize; ++z)
    {
        double dValue = dA * std::exp( dB * z*z / (base::m_scaleZ * base::m_scaleZ));
        base::m_kernelZ.set(z + HalfSize, dValue);
    }

    base::m_kernelZ.normalize();
}


// Volume filtering method
template <class V>
bool CVolumeGaussFilter<V>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    tSize margin(base::getNeededMargin());

    VPL_ASSERT(SrcVolume.getMargin() >= margin);

    CProgress::tProgressInitializer StartProgress(*this);

    // Volume size
    tSize XSize(vpl::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize()));
    tSize YSize(vpl::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize()));
    tSize ZSize(vpl::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize()));

    tSize XCount(XSize);
    tSize YCount(YSize);
    tSize ZCount(ZSize);
    
    // Initialize the progress observer
    CProgress::setProgressMax(ZCount);

    // This initializes kernel
    getResponse(SrcVolume, 0, 0, 0);

/*
    for(tSize z = 0; z < ZCount; ++z)
        for(tSize y = 0; y < YCount; ++y)
            for(tSize x = 0; x < XCount; ++x)
                DstVolume(x, y, z) = getResponse(SrcVolume, x, y, z);
    return true;
*/

    tVolume buffer1(BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, margin);
    tVolume buffer2(BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, margin);

    // Process input volume per blocks
    for(tSize k = 0; ZCount > 0; k += BLOCK_SIZE, ZCount -= BLOCK_SIZE)
    {
        // Compute remaining size
        tSize SZ = vpl::math::getMin<tSize>(BLOCK_SIZE, ZCount);

        YCount = YSize;
        for(tSize j = 0; YCount > 0; j += BLOCK_SIZE, YCount -= BLOCK_SIZE)
        {
            // Compute remaining size
            tSize SY = vpl::math::getMin<tSize>(BLOCK_SIZE, YCount);

            XCount = XSize;
            for(tSize i = 0; XCount > 0; i += BLOCK_SIZE, XCount -= BLOCK_SIZE)
            {
                // Compute remaining size
                tSize SX = vpl::math::getMin<tSize>(BLOCK_SIZE, XCount);

                // Copy data to the buffer
                for(tSize z = -margin; z < SZ + margin; ++z)
                    for(tSize y = -margin; y < SY + margin; ++y)
                        for(tSize x = -margin; x < SX + margin; ++x)
                        {
                            buffer1.set(x, y, z, SrcVolume.at(x + i, y + j, z + k));
                            buffer2.set(x, y, z, buffer1.at(x, y, z));
                        }

                // Filter along x axis
#pragma omp parallel for schedule(static) default(shared)
                for(tSize z = -margin; z < SZ + margin; ++z)
                    for(tSize y = -margin; y < SY + margin; ++y)
                        for(tSize x = 0; x < SX; ++x)
                            buffer2.set(x, y, z, convolveX<float, tVolume>(buffer1, x, y, z, base::m_kernelX));

                // Filter along y axis
#pragma omp parallel for schedule(static) default(shared)
                for(tSize z = -margin; z < SZ + margin; ++z)
                    for(tSize y = 0; y < SY; ++y)
                        for(tSize x = -margin; x < SX + margin; ++x)
                            buffer1.set(x, y, z, convolveY<float, tVolume>(buffer2, x, y, z, base::m_kernelY));
                
                // Filter along z axis and store to the output volume
#pragma omp parallel for schedule(static) default(shared)
                for(tSize z = 0; z < SZ; ++z)
                    for(tSize y = 0; y < SY; ++y)
                        for(tSize x = 0; x < SX; ++x)
                            DstVolume.set(x + i, y + j, z + k, convolveZ<float, tVolume>(buffer1, x, y, z, base::m_kernelZ));
            }
        }
    }

    // O.K.
    return true;
}

/**
 * Gets a response.
 *
 * \tparam  V   Generic type parameter.
 * \param   SrcVolume   Source volume.
 * \param   x           The tSize to process.
 * \param   y           The tSize to process.
 * \param   z           The tSize to process.
 *
 * \return  The response.
 */
template <class V>
typename vpl::img::CVolumeGaussFilter<V>::tVoxel vpl::img::CVolumeGaussFilter<V>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    tSize hsz(base::m_kernelZ.getSize() >> 1);
    tSize hsy(base::m_kernelY.getSize() >> 1);

    float sum(0.0);

    for(tSize k = -hsz; k <= hsz; ++k)
    {
        float sum_slice(0.0f);

        // Compute vertical convolution
        for(tSize j = -hsy; j <= hsy; ++j)
        {
            float response(convolveX<float, tVolume>(SrcVolume, x, y + j, z + k, base::m_kernelX));
            sum_slice += response * base::m_kernelY.at(j + hsy);
        }

        sum += sum_slice * base::m_kernelZ.at(k + hsz);
    }

    return tVoxel(sum);
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
    tSize XCount = vpl::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YCount = vpl::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZCount = vpl::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());

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

