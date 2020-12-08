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
 * Date:    2005/09/20                       
 *
 * Description:
 * - Canny edge detector.
 */


//==============================================================================
/*
 * Methods of the class vpl::img::CImageEdgeDetector<I, IED_CANNY>.
 */

// Canny edge detector
template <class I>
bool CCanny<I>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    static const float fGray = CPixelTraits<tPixel>::getGray();

    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());
    tSize Margin = SrcImage.getMargin();

    // Check the margin
    VPL_ASSERT(Margin >= 1);

    // Gaussian smoothing of the input image
    tImage SmoothedImage(XCount, YCount, Margin);
    m_GaussFilter(SrcImage, SmoothedImage);

    // Mirror the image margin to avoid artifacts
    SmoothedImage.mirrorMargin();

    // Compute gradient in x-direction
    tImage GradImageX(XCount, YCount, Margin);
    m_SobelX(SmoothedImage, GradImageX);

    // Compute gradient in y-direction
    tImage GradImageY(XCount, YCount, Margin);
    m_SobelY(SmoothedImage, GradImageY);

    // Compute the magnitude image
    tImage MagnitudeImage(XCount, YCount, Margin);
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            float fValue = vpl::math::getAbs(float(GradImageX(x, y)) - fGray);
            fValue += vpl::math::getAbs(float(GradImageY(x, y)) - fGray);
            MagnitudeImage(x, y) = tPixel(0.5f * fValue);
        }
    }

    // Non-maximal suppression
    tImage NonMaxMagnitudeImage(XCount, YCount, Margin);
    nonMaxSuppression(GradImageX,
                      GradImageY,
                      MagnitudeImage,
                      NonMaxMagnitudeImage
                      );

    // Thresholds for the hystersis
    // TODO: Estimate both thresholds from image histogram!
    tPixel MaxMagnitude = getMax<tPixel>(NonMaxMagnitudeImage);
    tPixel T1 = tPixel(m_dT1 * MaxMagnitude);
    tPixel T2 = tPixel(m_dT2 * MaxMagnitude);

    // Hysteresis
    DstImage.fillEntire(CPixelTraits<tPixel>::getZero());
    hysteresis(NonMaxMagnitudeImage, DstImage, T1, T2);

    // O.K.
    return true;
}


template <class I>
inline void CCanny<I>::getThresholds(double& dT1, double& dT2)
{
    dT1 = m_dT1;
    dT2 = m_dT2;
}


template <class I>
inline void CCanny<I>::setThresholds(double dT1, double dT2)
{
    VPL_ASSERT(dT1 <= 1.0 && dT2 <= dT1 && dT2 >= 0.0);

    m_dT1 = dT1;
    m_dT2 = dT2;
}


template <class I>
void CCanny<I>::nonMaxSuppression(const tImage& GradImageX,
                                  const tImage& GradImageY,
                                  tImage& MagnitudeImage,
                                  tImage& Image
                                  )
{
    static const tPixel Zero = CPixelTraits<tPixel>::getZero();
    static const tCoordinate Gray = CPixelTraits<tPixel>::getGray();

    // For each pixel
    for( tSize y = 0; y < MagnitudeImage.getYSize(); ++y )
    {
        for( tSize x = 0; x < MagnitudeImage.getXSize(); ++x )
        {
            // Check the pixel value
            tPixel Value = MagnitudeImage(x, y);
            if( Value > Zero )
            {
                // Derivatives in x and y direction
                tCoordinate cx = tCoordinate(GradImageX(x, y)) - Gray;
                tCoordinate cy = tCoordinate(GradImageY(x, y)) - Gray;

                // Estimate orientation of the edge
                CVector3D Orient(cx, cy);
                Orient.normalize();
                Orient *= 0.75;
                if( vpl::math::getAbs(Orient.x()) < 0.01 && vpl::math::getAbs(Orient.y()) < 0.01 )
                {
                    continue;
                }

                // Pixel neighbours
                CPoint3D Left(x + Orient.x(), y + Orient.y());
                CPoint3D Right(x - Orient.x(), y - Orient.y());

                // Interpolate pixel value in place of neighbours
                tPixel LeftValue = MagnitudeImage.interpolate(Left);
                tPixel RightValue = MagnitudeImage.interpolate(Right);

                // Check if the pixel is local maximum
                if( Value > LeftValue && Value > RightValue )
                {
                    Image.set(x, y, Value);
                }
            }
        }
    }
}


template <class I>
void CCanny<I>::hysteresis(tImage& MagnitudeImage,
                           tImage& Image,
                           tPixel T1,
                           tPixel T2
                           )
{
    // Accept all pixels whose magnitude exceeds the T1 threshold
    typedef typename tImage::tIterator tImageIterator;
    tImageIterator it(MagnitudeImage);
    for( ; it; ++it )
    {
        if( *it >= T1 )
        {
            Image.set(it.x(), it.y(), *it);
        }
    }

    // The number of new edge pixels
    int iCount;

    // Until stability is achieved
    do {
        // Reset the number of new edge pixels
        iCount = 0;

        // For each pixel
        tImageIterator it(MagnitudeImage);
        for( ; it; ++it )
        {
            // Check the pixel value
            tPixel Value = *it;
            if( Value >= T2 && Value < T1 )
            {
                // Get the pixel position
                tSize x = it.x();
                tSize y = it.y();

                // Check the neighbours
                if( checkNeighbours(MagnitudeImage, x, y, T1) )
                {
                    Image.set(x, y, *it);
                    *it = T1;
                    ++iCount;
                }
            }
        }
    } while( iCount > 0 );
}


template <class I>
bool CCanny<I>::checkNeighbours(tImage& Image,
                                tSize x,
                                tSize y,
                                tPixel T
                                )
{
    // Volume properties
    tSize XOffset = Image.getXOffset();
    tSize YOffset = Image.getYOffset();

    // Index of the center
    tSize idx = Image.getIdx(x, y);

    // Check the neighbours
    return (Image(idx + YOffset) >= T
            || Image(idx - YOffset) >= T
            || Image(idx + XOffset) >= T
            || Image(idx + XOffset + YOffset) >= T
            || Image(idx + XOffset - YOffset) >= T
            || Image(idx - XOffset) >= T
            || Image(idx - XOffset + YOffset) >= T
            || Image(idx - XOffset - YOffset) >= T
            );
}

