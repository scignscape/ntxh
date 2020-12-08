/* This file is part of
 *
 * VPL - Voxel Processing Library
 * Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

namespace bilateral3D
{
    //! Conversion of the filter standard deviation to the kernel size.
    const double SIGMA2SIZE     = 5.0;

    //! Conversion of the kernel size to the standard deviation.
    const double SIZE2SIGMA     = 1 / 5.0;

    //! Constant 1 / (2 * pi).
    const double INV_TWO_PI     = 1.0 / vpl::math::TWO_PI;
}


template<class V>
vpl::img::CVolumeBilateralFilter<V>::CVolumeBilateralFilter(double sigma_range, double sigma_distance)
    : m_gaussianKernel(1)
    , m_sigmaR(sigma_range)
    , m_sigmaD(sigma_distance)
{
    initializeKernel(sigma_range, sigma_distance);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   Sets a sigma of the range domain.
//!
//!\tparam  I   image type.
//!\param   dSigma  The sigma.
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class V>
void vpl::img::CVolumeBilateralFilter<V>::setSigmaDistance(double dSigma)
{
    VPL_ASSERT(dSigma > 0.0);

    initializeKernel(m_sigmaR, dSigma);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   Resizes filter.
//!
//!\tparam  I   Image type.
//!\param   Size    The size.
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class V>
void vpl::img::CVolumeBilateralFilter<V>::resize(tSize Size)
{
    initializeKernel(m_sigmaR, size2Sigma(Size));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   Sigma to size.
//!
//!\tparam  I   Image type.
//!\param   dSigma  The sigma.
//!
//!\return  .
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class V>
tSize vpl::img::CVolumeBilateralFilter<V>::sigma2Size(double dSigma)
{
    tSize Size = tSize(bilateral3D::SIGMA2SIZE * dSigma) + 1;
    if( (Size % 2) == 1 )
    {
        return Size;
    }
    else
    {
        return Size + 1;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   Size to sigma.
//!
//!\tparam  I   Image size.
//!\param   Size    The size.
//!
//!\return  .
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class V>
double vpl::img::CVolumeBilateralFilter<V>::size2Sigma(tSize Size)
{
    return bilateral3D::SIZE2SIGMA * (Size - 1);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   Gets a filter response.
//!
//!\tparam  I   Image type.
//!\param   SrcImage    Source image.
//!\param   x           The x coordinate.
//!\param   y           The y coordinate.
//!
//!\return  The response.
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class V>
typename vpl::img::CVolumeBilateralFilter<V>::tVoxel vpl::img::CVolumeBilateralFilter<V>::getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
{
    tSize hwx(m_wx >> 1), hwy(m_wy >> 1), hwz(m_wz >> 1);

    // Get current pixel value
    double intensity_source(SrcVolume.at(x, y, z));

    // Intensity part multiplier
    double ipd = 1.0 / (m_sigmaR*m_sigmaR*2.0);

    double sum(0.0), sum_weights(0.0);

    for(tSize k = -hwz; k < hwz; ++k)
    {
        for(tSize j = -hwy; j < hwy; ++j)
        {
            for(tSize i = -hwx; i < hwx; ++i)
            {
                // Get intensity of current pixel
                double intensity_current(SrcVolume.at(x + i, y + j, z + k));

                // Compute range part of weight
                double rp = m_gaussianKernel(i + hwx, j + hwy, k + hwz);

                // Compute intensity part of weight
                double ip = std::abs(intensity_source - intensity_current);
                ip *= ip*ipd;

                // Compute weight
                double weight = exp(-rp-ip);

                // Finalize
                sum_weights += weight;
                sum += weight * intensity_current;
            }
        }
    }

    if(sum_weights == 0.0)
        return tVoxel(0);

    return tVoxel(sum / sum_weights);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   Initializes the kernel.
//!
//!\tparam  I   Image type.
//!\param   sigmaR  The sigma r.
//!\param   sigmaS  The sigma s.
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class V>
void vpl::img::CVolumeBilateralFilter<V>::initializeKernel(double sigmaR, double sigmaD)
{
    // Store sigmas
    m_sigmaR = sigmaR;
    m_sigmaD = sigmaD;

    // Compute needed filter maximal size
    double max_size(std::max(this->m_dDX, std::max(this->m_dDY, this->m_dDZ)));

    VPL_ASSERT(max_size > 0.0);

    // Compute scales
    double scaleX = max_size / this->m_dDX;
    double scaleY = max_size / this->m_dDY;
    double scaleZ = max_size / this->m_dDZ;

    // Compute maximal window size
    tSize dsize(sigma2Size(m_sigmaD));

    // Store window sizes
    m_wx = dsize / scaleX;
    m_wy = dsize / scaleY;
    m_wz = dsize / scaleZ;

    // Resize gaussian kernel
    m_gaussianKernel.resize(dsize);

    // Fill is inaccessible so use this slow approach
    for(tSize k = 0; k < dsize; ++k)
        for(tSize j = 0; j < dsize; ++j)
            for(tSize i = 0; i < dsize; ++i)
                m_gaussianKernel.set(i, j, k, 0.0);

    double dS = bilateral3D::INV_TWO_PI / (m_sigmaD * m_sigmaD);

    // Initialize gaussian kernel
    for(tSize k = 0; k < m_wz; ++k)
    {
        // Out of center distance
        double ocz(m_wz/2.0 - k);
        ocz *= scaleZ;

        for(tSize j = 0; j < m_wy; ++j)
        {
            // Out of center distance
            double ocy(m_wy/2.0 - j);
            ocy *= scaleY;

            for(tSize i = 0; i < m_wx; ++i)
            {
                // Out of center distance 
                double ocx(m_wx/2.0 - i);
                ocx *= scaleX;

                // Compute gaussian function
                double gaussian = dS * std::exp(-0.5 * dS * (ocx * ocx + ocy * ocy + ocz * ocz));

                // Store to the kernel
                m_gaussianKernel.set(i, j, k, gaussian);        
            }
        }
    }
}


template<class V>
bool vpl::img::CVolumeBilateralFilter<V>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    // Volume size
    tSize XCount = vpl::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YCount = vpl::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZCount = vpl::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());

    if(XCount == 0 || YCount == 0 || ZCount == 0)
        return false;

    // This initializes kernel
    getResponse(SrcVolume, 0, 0, 0);

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize z = 0; z < ZCount; ++z )
        for( tSize y = 0; y < YCount; ++y )
            for( tSize x = 0; x < XCount; ++x )
                DstVolume.set(x, y, z, getResponse(SrcVolume, x, y, z));

    return true;
}
