//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/21                          \n
 *
 * $Id: mdsOtsu.hxx 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Otsu's histogram thresholding algorithm.
 */


//==============================================================================
/*
 * Implementation ...
 */

template <class H>
inline bool findSingleThresholdOtsu(const CHistogramBase<H>& Histogram,
                                    typename H::tItem& Threshold
                                    )
{
    typedef typename H::tHistogram tHistogram;
    typedef typename H::tBin tBin;
    typedef typename H::tItem tItem;
    const tHistogram& HistogramImpl = Histogram.getImpl();
    
    // Number of histogram bins
    tSize NumOfBins = HistogramImpl.getSize();
    tBin NumOfSamples = HistogramImpl.getTotalCount();
    
    // Normalize the histogram
    mds::math::CVector<double> Hist(NumOfBins);
    double dInvCount = 1.0 / double(NumOfSamples);
    double dMean = 0.0;
    for( tSize i = 0; i < NumOfBins; ++i )
    {
        Hist(i) = double(HistogramImpl.getCount(i)) * dInvCount;
        dMean += Hist(i) * i;
    }
    
    // Recursive implementation of the Otsu's algorithm
    double dU0 = 0.0;
    double dN0 = 0.000001;
    double dU1 = dMean;
    double dN1 = 1.0 - dN0;
    
    // For each possible threshold value
    double dMaxValue = -1.0;
    for( tSize j = 0; j < NumOfBins - 1; ++j )
    {
        if( HistogramImpl.getCount(j) == 0 )
        {
            continue;
        }
        
        double dTemp = dN0;
        dN0 += Hist(j);
        dN1 -= Hist(j);
        dU0 = (dTemp * dU0 + j * Hist(j)) / dN0;
        dU1 = (dMean - dN0 * dU0) / dN1;
        
        // Between-class variance
        dTemp = dU0 - dU1;
        double dValue = dN0 * dN1 * dTemp * dTemp;
        if( dValue > dMaxValue )
        {
            Threshold = HistogramImpl.getLowerBound(j + 1);
            dMaxValue = dValue;
        }
    }
    
    // Threshold found
    return (dMaxValue > 0.0);
}

