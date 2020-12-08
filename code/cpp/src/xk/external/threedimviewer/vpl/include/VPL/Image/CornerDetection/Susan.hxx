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
 * Copyright (c) 2003-2007 by PGMed@FIT         \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/21                          \n
 *
 * Description:
 * - Modified Susan corner detector.
 */


//==============================================================================
/*
 * Methods of the class vpl::img::CImageCornerDetector<I, ICD_SUSAN>.
 */

template <class I>
inline CSusanDetector<I>::CSusanDetector(double dThreshold, double dWidth)
    : m_dThreshold(dThreshold)
    , m_dWidth((dWidth > 0.0) ? dWidth : 1.0)
{
    VPL_ASSERT(dThreshold > 0.0 && dThreshold < 1.0 && dWidth > 0.0);

    m_dInvWidth = 1.0 / m_dWidth;

    initLUT();
}


template <class I>
bool CSusanDetector<I>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    static const tPixel Min = CPixelTraits<tPixel>::getPixelMin();
    static const tPixel Max = CPixelTraits<tPixel>::getPixelMax();
//    static const tFloatPixel Zero = tFloatPixel(0.0f);

    static const int iNumOfPixels = 37;
    static const double dNorm = 1.0 / (iNumOfPixels * MAX_LUT);

    // Image size and margin
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());
    tSize Margin = SrcImage.getMargin();

    // Check the margin
    if( Margin < 3 )
    {
        return false;
    }

    // Convert input image to Image8
    CImage8 HelperSrcImage;
    HelperSrcImage.convert(SrcImage);

    // Cornerness normalization
    double dScale = double(Max) - Min;

    // Helper image
    CFImage CornerImage(XCount, YCount, Margin);
    CornerImage.fillEntire(tPixel(0));

    // Area threshold
    int iThreshold = int(iNumOfPixels * MAX_LUT * m_dThreshold);

    // Evaluate cornerness
    tSize x, y;
    for( y = 0; y < YCount; ++y )
    {
        for( x = 0; x < XCount; ++x )
        {
            // Nucleus of the circle mask
            tPixel Value = HelperSrcImage(x,y);
            
            // Count the difference of pixels and the nucleus
            int cx = 0, cy = 0, iCornerness = 0;
            int iTemp = getDiff(HelperSrcImage(x-1,y-1), Value);;
            iCornerness += iTemp;
            cx -= iTemp;
            cy -= iTemp;
            
            iTemp = getDiff(HelperSrcImage(x,y-1), Value);;
            iCornerness += iTemp;
            cy -= iTemp;

            iTemp = getDiff(HelperSrcImage(x+1,y-1), Value);;
            iCornerness += iTemp;
            cx += iTemp;
            cy -= iTemp;

            iTemp = getDiff(HelperSrcImage(x-1,y), Value);;
            iCornerness += iTemp;
            cx -= iTemp;

            iTemp = getDiff(HelperSrcImage(x+1,y), Value);;
            iCornerness += iTemp;
            cx += iTemp;

            iTemp = getDiff(HelperSrcImage(x-1,y+1), Value);;
            iCornerness += iTemp;
            cx -= iTemp;
            cy += iTemp;

            iTemp = getDiff(HelperSrcImage(x,y+1), Value);;
            iCornerness += iTemp;
            cy += iTemp;

            iTemp = getDiff(HelperSrcImage(x+1,y+1), Value);;
            iCornerness += iTemp;
            cx += iTemp;
            cy += iTemp;
            
            // Compare the value against the threshold
            if( iCornerness > iThreshold )
            {
                continue;
            }
            
            // Remaining pixels of the circular mask
            iTemp = getDiff(HelperSrcImage(x-1,y-3), Value);;
            iCornerness += iTemp;
            cx -= iTemp;
            cy -= 3 * iTemp;
            
            iTemp = getDiff(HelperSrcImage(x,y-3), Value);;
            iCornerness += iTemp;
            cy -= 3 * iTemp;
            
            iTemp = getDiff(HelperSrcImage(x+1,y-3), Value);;
            iCornerness += iTemp;
            cx += iTemp;
            cy -= 3 * iTemp;


            iTemp = getDiff(HelperSrcImage(x+2,y-2), Value);;
            iCornerness += iTemp;
            cx += 2 * iTemp;
            cy -= 2 * iTemp;

            iTemp = getDiff(HelperSrcImage(x+1,y-2), Value);;
            iCornerness += iTemp;
            cx += iTemp;
            cy -= 2 * iTemp;

            iTemp = getDiff(HelperSrcImage(x,y-2), Value);;
            iCornerness += iTemp;
            cy -= 2 * iTemp;

            iTemp = getDiff(HelperSrcImage(x-1,y-2), Value);;
            iCornerness += iTemp;
            cx -= iTemp;
            cy -= 2 * iTemp;

            iTemp = getDiff(HelperSrcImage(x-2,y-2), Value);;
            iCornerness += iTemp;
            cx -= 2 * iTemp;
            cy -= 2 * iTemp;


            iTemp = getDiff(HelperSrcImage(x+3,y-1), Value);;
            iCornerness += iTemp;
            cx += 3 * iTemp;
            cy -= iTemp;

            iTemp = getDiff(HelperSrcImage(x+2,y-1), Value);;
            iCornerness += iTemp;
            cx += 2 * iTemp;
            cy -= iTemp;

            iTemp = getDiff(HelperSrcImage(x-2,y-1), Value);;
            iCornerness += iTemp;
            cx -= 2 * iTemp;
            cy -= iTemp;

            iTemp = getDiff(HelperSrcImage(x-3,y-1), Value);;
            iCornerness += iTemp;
            cx -= 3 * iTemp;
            cy -= iTemp;

            
            iTemp = getDiff(HelperSrcImage(x+3,y), Value);;
            iCornerness += iTemp;
            cx += 3 * iTemp;

            iTemp = getDiff(HelperSrcImage(x+2,y), Value);;
            iCornerness += iTemp;
            cx += 2 * iTemp;

            iTemp = getDiff(HelperSrcImage(x-2,y), Value);;
            iCornerness += iTemp;
            cx -= 2 * iTemp;

            iTemp = getDiff(HelperSrcImage(x-3,y), Value);;
            iCornerness += iTemp;
            cx -= 3 * iTemp;


            iTemp = getDiff(HelperSrcImage(x+3,y+1), Value);;
            iCornerness += iTemp;
            cx += 3 * iTemp;
            cy += iTemp;

            iTemp = getDiff(HelperSrcImage(x+2,y+1), Value);;
            iCornerness += iTemp;
            cx += 2 * iTemp;
            cy += iTemp;

            iTemp = getDiff(HelperSrcImage(x-2,y+1), Value);;
            iCornerness += iTemp;
            cx -= 2 * iTemp;
            cy += iTemp;

            iTemp = getDiff(HelperSrcImage(x-3,y+1), Value);;
            iCornerness += iTemp;
            cx -= 3 * iTemp;
            cy += iTemp;


            iTemp = getDiff(HelperSrcImage(x+2,y+2), Value);;
            iCornerness += iTemp;
            cx += 2 * iTemp;
            cy += 2 * iTemp;

            iTemp = getDiff(HelperSrcImage(x+1,y+2), Value);;
            iCornerness += iTemp;
            cx += iTemp;
            cy += 2 * iTemp;

            iTemp = getDiff(HelperSrcImage(x,y+2), Value);;
            iCornerness += iTemp;
            cy += 2 * iTemp;

            iTemp = getDiff(HelperSrcImage(x-1,y+2), Value);;
            iCornerness += iTemp;
            cx -= iTemp;
            cy += 2 * iTemp;

            iTemp = getDiff(HelperSrcImage(x-2,y+2), Value);;
            iCornerness += iTemp;
            cx -= 2 * iTemp;
            cy += 2 * iTemp;


            iTemp = getDiff(HelperSrcImage(x-1,y+3), Value);;
            iCornerness += iTemp;
            cx -= iTemp;
            cy += 3 * iTemp;

            iTemp = getDiff(HelperSrcImage(x,y+3), Value);;
            iCornerness += iTemp;
            cy += 3 * iTemp;

            iTemp = getDiff(HelperSrcImage(x+1,y+3), Value);;
            iCornerness += iTemp;
            cx += iTemp;
            cy += 3 * iTemp;
            
            // Compare the value against the threshold
            if( iCornerness > iThreshold )
            {
                continue;
            }
            
            // Check distance of the center of gravity from the nucleus
            // - The distance must be larger then 1/2
            int cxx = cx * cx;
            int cyy = cy * cy;
            if( 2 * (cxx + cyy) < (iCornerness * iCornerness) )
            {
                continue;
            }
            
            // Check all pixels in the direction of the center of gravity 
            if( cxx > cyy )
            {
                int dx = (cx > 0) ? 1 : -1;
                double dy = double(cy) / vpl::math::getAbs(cx);

                int iValue = getDiff(HelperSrcImage(x+dx,vpl::math::round2Int(y+dy)), Value);
                iValue += getDiff(HelperSrcImage(x+2*dx,vpl::math::round2Int(y+2*dy)), Value); 
                iValue += getDiff(HelperSrcImage(x+3*dx,vpl::math::round2Int(y+3*dy)), Value);

                if( iValue < DIFF_THRESHOLD )
                {
                    continue;
                }
            }
            else if( cyy > cxx )
            {
                double dx = double(cx) / vpl::math::getAbs(cy);
                int dy = (cy > 0) ? 1 : -1;

                int iValue = getDiff(HelperSrcImage(vpl::math::round2Int(x+dx),y+dy), Value);
                iValue += getDiff(HelperSrcImage(vpl::math::round2Int(x+2*dx),y+2*dy), Value); 
                iValue += getDiff(HelperSrcImage(vpl::math::round2Int(x+3*dx),y+2*dy), Value);

                if( iValue < DIFF_THRESHOLD )
                {
                    continue;
                }
            }
            else
            {
            	continue;
            }

            // Final cornerness
            CornerImage(x,y) = tFloatPixel(m_dThreshold - dNorm * iCornerness);
        }
    }

    // Clear the output image
    DstImage.fillEntire(tPixel(0));

    // Find local maxima (non-maxima suppression alorithm)
    for( y = 0; y < YCount; ++y )
    {
        for( x = 0; x < XCount; ++x )
        {
            // Cornerness value
            tFloatPixel Value = CornerImage(x,y);
            
            // Check the neighbours
            if( !checkNeighbours(CornerImage, x, y, Value) )
            {
                DstImage(x,y) = tPixel(Value * dScale);
            }
        }
    }

    // O.K.
    return true;
}


template <class I>
inline void CSusanDetector<I>::setThreshold(double dThreshold)
{
	VPL_ASSERT(dThreshold < 1.0 && dThreshold > 0.0);

    m_dThreshold = dThreshold;
}


template <class I>
inline void CSusanDetector<I>::setWidth(double dWidth)
{
    VPL_ASSERT(dWidth > 0.0);
    
    m_dWidth = (dWidth > 0.0) ? dWidth : 1.0;
    m_dInvWidth = 1.0 / m_dWidth;

    initLUT();
}


template <class I>
bool CSusanDetector<I>::checkNeighbours(CFImage& Image,
                                        tSize x,
                                        tSize y,
                                        tFloatPixel T
                                        )
{
    // Image properties
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


template <class I>
void CSusanDetector<I>::initLUT()
{
    for( tSize i = -MAX_LUT; i <= MAX_LUT; ++i )
    {
        double dTemp = m_dInvWidth * i;
        dTemp = dTemp * dTemp;
        m_LUT(i + MAX_LUT) = int(MAX_LUT * std::exp(-dTemp * dTemp * dTemp));
//        double dTemp = double(i) * i;
//        m_LUT(i + MAX_LUT) = int(MAX_LUT * std::exp(-m_dInvWidth * dTemp * dTemp * dTemp));
    }
}


template <class I>
inline int CSusanDetector<I>::getDiff(int a, int b)
{
    tSize Index = tSize(a) - tSize(b);
//    VPL_LOG_INFO(Index << " -> " << m_LUT(Index + MAX_LUT));
    return m_LUT(Index + MAX_LUT);
}

