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
 * Copyright (c) 2003-2008 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/21                       
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
    vpl::math::CVector<double> Mean(NumOfRegions);
    vpl::math::CVector<tBin> Count(NumOfRegions);
    vpl::math::CVector<tSize> RegionIndex(NumOfBins);
    
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

