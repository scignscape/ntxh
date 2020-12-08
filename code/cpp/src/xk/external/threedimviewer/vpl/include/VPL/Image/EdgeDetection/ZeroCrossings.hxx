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
 * Author:  Michal Spanel, spanel@fit.vutbr.cz       
 * Date:    2005/10/07                               
 * 
 * Description:
 * - Zero crossings of the LoG filter.
 */


//==============================================================================
/*
 * Methods templates.
 */

template <class I>
bool CZeroCrossDetector<I>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    static const tPixel Zero = CPixelTraits<tPixel>::getZero();

    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());
    tSize Margin = SrcImage.getMargin();

    // Check the margin
    VPL_ASSERT(Margin >= 2);

    // LoG filter
    tImage FilteredImage(XCount, YCount, Margin);
    m_Filter(SrcImage, FilteredImage);

    // Compute the magnitude image
    tImage MagnitudeImage(XCount, YCount);
    MagnitudeImage.fillEntire(Zero);
    tSize x, y;
    for( y = 0; y < YCount; ++y )
    {
        for( x = 0; x < XCount; ++x )
        {
            if( isEdge(FilteredImage, x, y) )
            {
                MagnitudeImage(x, y) = tPixel(computeGradient(FilteredImage, x, y));
            }
        }
    }

    // Estimate threshold
    // TODO: Estimate threshold from image histogram!
    tPixel MaxMagnitude = getMax<tPixel>(MagnitudeImage);
    tPixel T = tPixel(m_dThreshold * MaxMagnitude);

    // Clear the output image
    DstImage.fillEntire(Zero);

    // Thresholding of the magnitude image
    for( y = 0; y < YCount; ++y )
    {
        for( x = 0; x < XCount; ++x )
        {
            tPixel Magnitude = MagnitudeImage(x, y);
            if( Magnitude > T )
            {
                DstImage.set(x, y, Magnitude);
            }
        }
    }

    // O.K.
    return true;
}


template <class I>
inline bool CZeroCrossDetector<I>::isEdge(const tImage& Image, tSize x, tSize y)
{
    static const double dGray = CPixelTraits<tPixel>::getGray();

    double dCenter = Image(x, y) - dGray;

    double dRight = Image(x + 1, y) - dGray;
    double dLeft = Image(x - 1, y) - dGray;
    if( (dCenter * dRight) <= 0.0 || (dCenter * dLeft) <= 0.0 )
    {
        if( (dRight * dLeft) < 0.0 )
        {
            return true;
        }
    }

    double dUpper = Image(x, y - 1) - dGray;
    double dLower = Image(x, y + 1) - dGray;
    if( (dCenter * dLower) <= 0.0 || (dCenter * dUpper) <= 0.0 )
    {
        if( (dLower * dUpper) < 0.0 )
        {
            return true;
        }
    }

    return false;
}


template <class I>
inline double CZeroCrossDetector<I>::computeGradient(const tImage& Image, tSize x, tSize y)
{
    static const double dGray = CPixelTraits<tPixel>::getGray();

    double dPosSum = 0.0;
    double dNegSum = 0.0;
    int iPosCount = 0;
    int iNegCount = 0;

    for( tSize j = -1; j <= 1; ++j )
    {
        for( tSize i = -1; i <= 1; ++i )
        {
            double dValue = Image(x + i, y + j) - dGray;
            if( dValue > 0.0 )
            {
                dPosSum += dValue;
                ++iPosCount;
            }
            else
            {
                dNegSum += dValue;
                ++iNegCount;
            }
        }
    }

    double dPos = 0.0;
    if( iPosCount > 0 )
    {
        dPos = dPosSum / iPosCount;
    }
    double dNeg = 0.0;
    if( iNegCount > 0 )
    {
        dNeg = dNegSum / iNegCount;
    }

    return (0.5 * (dPos - dNeg));
}


template <class I>
inline void CZeroCrossDetector<I>::setThreshold(double dThreshold)
{
    VPL_ASSERT(dThreshold <= 1.0 && dThreshold >= 0.0);

    m_dThreshold = dThreshold;
}

