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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/09/15                          \n
 *
 * Description:
 * - N-dimensional gaussian function (mixture model component).
 * - Diagonal covariance matrix.
 */


//=============================================================================
/*
 * Methods templates.
 */

template <typename T, int N>
T CGaussianFunc<T,N>::m_MinCovariance = T(GaussianFunc::DEFAULT_MIN_COVARIANCE);


template <typename T, int N>
inline void CGaussianFunc<T,N>::computeInverse()
{
    if( !m_bModified )
    {
        return;
    }

    // Normalize the covariance matrix
    for( tSize m = 0; m < m_Cov.getSize(); ++m )
    {
        if( m_Cov(m) < m_MinCovariance )
        {
            m_Cov(m) = m_MinCovariance;
        }
    }

    // Compute determinant and inverse
    for( tSize i = 0; i < m_Cov.getSize(); ++i )
    {
        m_CovDet(i) = 1.0 / (SQRT_TWO_PI * std::sqrt(m_Cov(i)));
        m_InvCov(i) = 1.0 / m_Cov(i);
    }

    // Swith the helper flag
    m_bModified = false;
}


template <typename T, int N>
inline double CGaussianFunc<T,N>::getValue(const tVector& x)
{
    computeInverse();

    tVector D = x;
    D -= m_Mean;

    double dResult = 1.0;
    for( int i = 0; i < NUM_OF_DIMENSIONS; ++i )
    {
        double dExp = -0.5 * D(i) * D(i) * m_InvCov(i);
        dResult *= m_CovDet(i) * exp(dExp);
    }

    return dResult;
}

