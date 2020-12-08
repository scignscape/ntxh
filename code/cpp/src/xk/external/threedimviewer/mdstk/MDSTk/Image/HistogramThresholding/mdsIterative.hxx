//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/21                          \n
 *
 * $Id: mdsIterative.hxx 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Itearative histogram thresholding.
 */

//==============================================================================
/*
 * Implementation ...
 */

template <class H>
inline bool findThresholdsIterative(const CHistogramBase<H>& Histogram,
                                    int NumOfThresholds,
                                    CMultiThresholding<typename H::tItem>& Thresholds
                                    )
{
    static const int NUM_OF_ITERS = 10;
    
    typedef typename H::tHistogram tHistogram;
    typedef typename H::tBin tBin;
    typedef typename H::tItem tItem;
    const tHistogram& HistogramImpl = Histogram.getImpl();
    
    // Number of histogram bins
    tSize NumOfBins = HistogramImpl.getSize();
    
    // Number of regions
    tSize NumOfRegions = NumOfThresholds + 1;
    
    // Check the given number of thresholds
    if( NumOfThresholds < 1 || NumOfRegions > NumOfBins )
    {
        return false;
    }
    
    // Initialize thresholds
    tSize Stride = NumOfBins / NumOfRegions;
    for( tSize i = 0; i < NumOfThresholds; ++i )
    {
        Thresholds.add(HistogramImpl.getLowerBound(Stride + i * Stride));
    }
    
    // Helper arrays
    mds::math::CVector<double> Mean(NumOfRegions);
    mds::math::CVector<tBin> Count(NumOfRegions);
    mds::math::CVector<tSize> RegionIndex(NumOfBins);
    
    // Iterative estimation of "optimal" thresholds
    for( int iter = 0; iter < NUM_OF_ITERS; ++iter )
    {
        // Prepare the index field
        RegionIndex.fill(0);
        for( tSize t = 0; t < NumOfThresholds; ++t )
        {
            tSize HistBin = HistogramImpl.getIndex(Thresholds.get(t));
//            for( tSize j = HistBin + 1; j < NumOfBins; ++j )
            for( tSize j = HistBin; j < NumOfBins; ++j )
            {
                RegionIndex(j) += 1;
            }
        }
        
        // Estimate mean values of all regions
        Mean.fill(0.0);
        Count.fill(0);
        for( tSize j = 0; j < NumOfBins; ++j )
        {
            Mean(RegionIndex(j)) += HistogramImpl.getCount(j) * double(HistogramImpl.getLowerBound(j));
            Count(RegionIndex(j)) += HistogramImpl.getCount(j);
        }
        for( tSize r = 0; r < NumOfRegions; ++r )
        {
            if( Count(r) > 0 )
            {
                Mean(r) /= double(Count(r));
            }
        }
        
        // Modify thresholds
        for( tSize n = 0; n < NumOfThresholds; ++n )
        {
            Thresholds.set(n, tItem(0.5 * (Mean(n) + Mean(n+1))));
        }
    }
    
    // O.K.
    return true;
}

