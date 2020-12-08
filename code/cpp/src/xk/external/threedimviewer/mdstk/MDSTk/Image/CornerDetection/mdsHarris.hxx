//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)       \n
 * Copyright (c) 2003-2007 by PGMed@FIT            \n
 *
 * Author:  Petr Hyna, xhynap00@stud.fit.vutbr.cz  \n
 *          (modified by Michal Spanel)            \n
 * Date:    2007/04/25                             \n
 *
 * $Id: mdsHarris.hxx 2098 2012-02-16 23:50:36Z spanel $
 *
 * Description:
 * - Harris corner detector.
 */


//==============================================================================
/*
 * Methods of the class mds::img::CImageCornerDetector<I, ICD_HARRIS>.
 */

// Harris corner detector
template <class I>
bool CHarris<I>::operator()(const tImage& SrcImage, tImage& DstImage)
{
//    static const tPixel Min = CPixelTraits<tPixel>::getPixelMin();
    static const tPixel Max = CPixelTraits<tPixel>::getPixelMax();
    static const tFloatPixel Zero = tFloatPixel(0.0f);

    // Image size and margin
    tSize XCount = mds::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = mds::math::getMin(SrcImage.getYSize(), DstImage.getYSize());
    tSize Margin = SrcImage.getMargin();

    // Check the margin
    if( Margin < (m_GaussFilter.getSize() / 2) )
    {
        return false;
    }
    
	// Convert image to float
	CFImage FloatSrcImage;
	FloatSrcImage.convert(SrcImage);
    
    // Estimate cornerness
	CFImage CornerImage(XCount, YCount, Margin);

    // Clear the corner image
    CornerImage.fillEntire(Zero);

    // Gradient images
    CFImage IxxImage(XCount, YCount, Margin);
    CFImage IyyImage(XCount, YCount, Margin);
    CFImage IxyImage(XCount, YCount, Margin);

    // For each pixel estimate image derivatives
    tSize x, y;
    for( y = 0; y < YCount; ++y )
    {
        for( x = 0; x < XCount; ++x )
        {
            // Derivatives in x and y direction
            tFloatPixel cx = tFloatPixel(m_SobelX.getResponse(FloatSrcImage, x, y));
            tFloatPixel cy = tFloatPixel(m_SobelY.getResponse(FloatSrcImage, x, y));

/*            tFloatPixel cx = FloatSrcImage(x + 1, y) - FloatSrcImage(x - 1, y);
            tFloatPixel cy = FloatSrcImage(x, y + 1) - FloatSrcImage(x, y - 1);*/               
            
            // Final values 
            IxxImage(x,y) = cx * cx;
            IyyImage(x,y) = cy * cy;
            IxyImage(x,y) = cx * cy;
        }
    }
    
    // Estimate cornerness
    for( y = 0; y < YCount; ++y )
    {
        for( x = 0; x < XCount; ++x )
        {
            // Calculating weighted values Ixx, Iyy and Ixy
            double dIxx = m_GaussFilter.getResponse(IxxImage, x, y);
            double dIyy = m_GaussFilter.getResponse(IyyImage, x, y);
            double dIxy = m_GaussFilter.getResponse(IxyImage, x, y);

            // Harris & Stephens
//            double dTrace = dIxx + dIyy;
//            double dM = dIxx * dIyy - dIxy * dIxy - m_dKappa * dTrace * dTrace;

            // Shi & Tomasi
            double dValue1 = ((dIxx+dIyy) - std::sqrt(((dIxx-dIyy)*(dIxx-dIyy) + 4*dIxy*dIxy))) * 0.5;
            double dM = dValue1;

            CornerImage(x,y) = tFloatPixel(mds::math::getAbs(dM));
//            MDS_LOG_NOTE(dM);
        }
    }

    // Threshold for the non-maxima suppression
    double dMaxMagnitude = getMax<double>(CornerImage);
    double dThreshold = m_dThreshold * dMaxMagnitude;

    // Normalization
    double dNorm = double(Max) / (dMaxMagnitude + 0.001);
    
    // Clear the output image
    DstImage.fillEntire(tPixel(0));

    // Find local maxima (non-maxima suppression algorithm)
    for( y = 0; y < YCount; ++y )
    {
        for( x = 0; x < XCount; ++x )
        {
            // Get cornerness
            tFloatPixel Value = CornerImage(x,y);
            
            // Accept only those pixels whose magnitude exceeds the threshold
            // and simultaneously are local maximum
            if( Value < dThreshold )
            {
                continue;
            }
            
            // Check the neighbours
            if( !checkNeighbours(CornerImage, x, y, Value) )
            {
                DstImage(x,y) = tPixel(Value * dNorm);
            }
        }
    }
    
    // O.K.
    return true;
}


template <class I>
inline void CHarris<I>::setThreshold(double dThreshold)
{
	MDS_ASSERT(dThreshold <= 1000 && dThreshold >= 0);

    m_dThreshold = dThreshold;
}


template <class I>
inline void CHarris<I>::setKappa(double dKappa)
{
	MDS_ASSERT(dKappa <= 0.25 && dKappa >= 0.01);

    m_dKappa = dKappa;
}


template <class I>
bool CHarris<I>::checkNeighbours(CFImage& Image,
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

