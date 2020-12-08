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
 * Date:    2005/10/07                       
 *
 * Description:
 * - Difference of Gaussians filter.
 */


//==============================================================================
/*
 * Methods templates.
 */

template <class I, template <typename> class N>
inline void CDoGFilter<I,N>::getSigmas(double& dSigma1, double& dSigma2) const
{
    dSigma1 = m_Gaussian1.getSigma();
    dSigma2 = m_Gaussian2.getSigma();
}


template <class I, template <typename> class N>
inline void CDoGFilter<I,N>::setSigmas(double dSigma1, double dSigma2)
{
    m_Gaussian1.setSigma(dSigma1);
    m_Gaussian2.setSigma(dSigma2);
}


// Image filtering method
template <class I, template <typename> class N>
bool CDoGFilter<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Gaussian smoothing of the input image
    tImage Filtered1(XCount, YCount);
    m_Gaussian1(SrcImage, Filtered1);

    // Gaussian smoothing of the input image
    tImage Filtered2(XCount, YCount);
    m_Gaussian2(SrcImage, Filtered2);

    // Compute difference of both smoothed images
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            tResult Value = tResult(Filtered2(x, y)) - tResult(Filtered1(x, y));
            DstImage.set(x, y, base::m_NormFunc(Value));
        }
    }

    // O.K.
    return true;
}

