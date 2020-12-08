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
 * Copyright (c) 2003-2007 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/04/17                       
 *
 * Description:
 * - Image histogram functions.
 */


//==============================================================================
/*
 * Functions templates.
 */

template <class I>
inline bool histogramEqualization(CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;
    I& ImageImpl = Image.getImpl();
    
    // Useful constants
    static const tPixel PixelMin = CPixelTraits<tPixel>::getPixelMin();
    static const tPixel PixelMax = CPixelTraits<tPixel>::getPixelMax();
    
    // Histogram of the image
    typedef CFullHistogram<I> tHistogram;
    tHistogram Histogram(PixelMin, PixelMax);
    if( !Histogram(ImageImpl) )
    {
        return false;
    }
    
    // Compute the cumulative histogram
    Histogram.cumulate();
    
    // Get the number of samples
    typename tHistogram::tBin Max = Histogram.getCount(Histogram.getSize() - 1);
    if( Max <= 0 )
    {
        return false;
    }
    
    // Histogram equalization
    double dNorm = double(PixelMax - PixelMin) / double(Max);
    for( tSize j = 0; j < ImageImpl.getYSize(); ++j )
    {
        for( tSize i = 0; i < ImageImpl.getXSize(); ++i )
        {
            tSize Index = Histogram.getIndex(ImageImpl(i,j));
            ImageImpl(i,j) = tPixel(dNorm * Histogram.getCount(Index) + PixelMin);
        }
    }
    
    // O.K.
    return true;
}


template <class I>
inline bool singleThresholding(CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;
    typedef typename I::tIterator tIterator;
    I& ImageImpl = Image.getImpl();
    
    // Useful constants
    static const tSize NumOfBins = 128;
    static const tPixel PixelMin = CPixelTraits<tPixel>::getPixelMin();
    static const tPixel PixelMax = CPixelTraits<tPixel>::getPixelMax();
    
    // Image histogram
    typedef CHistogram<I> tHistogram;
    tHistogram Histogram(NumOfBins, PixelMin, PixelMax);
    if( !Histogram(ImageImpl) )
    {
        return false;
    }
    
    // Find an optimal threshold
    tPixel Threshold = PixelMax;
    if( !findSingleThreshold(Histogram, Threshold) )
    {
        return false;
    }
    
    // Compare image pixels with the found threshold
    ImageImpl.forEach(CSingleThresholding<tPixel>(Threshold));
    
    // O.K.
    return true;
}


template <class I>
inline bool multiIterativeThresholding(CImageBase<I>& Image, int NumOfThresholds)
{
    typedef typename I::tPixel tPixel;
    typedef typename I::tIterator tIterator;
    I& ImageImpl = Image.getImpl();
    
    // Useful constants
    static const tPixel PixelMin = CPixelTraits<tPixel>::getPixelMin();
    static const tPixel PixelMax = CPixelTraits<tPixel>::getPixelMax();
    
    // Image histogram
    typedef CFullHistogram<I> tHistogram;
    tHistogram Histogram(PixelMin, PixelMax);
    if( !Histogram(ImageImpl) )
    {
        return false;
    }
    
    // Find "optimal" thresholds using the iterative algorithm
    CMultiThresholding<tPixel> Thresholds;
    if( !findThresholdsIterative(Histogram, NumOfThresholds, Thresholds) )
    {
        return false;
    }
    
    // Compare image pixels with the found thresholds
    ImageImpl.forEach(Thresholds);
    
    // O.K.
    return true;
}


template <class I>
inline bool singleOtsuThresholding(CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;
    typedef typename I::tIterator tIterator;
    I& ImageImpl = Image.getImpl();
    
    // Useful constants
    static const tPixel PixelMin = CPixelTraits<tPixel>::getPixelMin();
    static const tPixel PixelMax = CPixelTraits<tPixel>::getPixelMax();
    
    // Image histogram
    typedef CFullHistogram<I> tHistogram;
    tHistogram Histogram(PixelMin, PixelMax);
    if( !Histogram(ImageImpl) )
    {
        return false;
    }
    
    // Find "optimal" thresholds using the Otsu's algorithm
    tPixel Threshold = PixelMax;
    if( !findSingleThresholdOtsu(Histogram, Threshold) )
    {
        return false;
    }
    
    // Final thresholding
    ImageImpl.forEach(CSingleThresholding<tPixel>(Threshold));
    
    // O.K.
    return true;
}

