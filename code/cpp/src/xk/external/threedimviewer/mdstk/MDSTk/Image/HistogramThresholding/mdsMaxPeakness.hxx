//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/21                          \n
 *
 * $Id: mdsMaxPeakness.hxx 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Simple mode-based histogram thresholding.
 */

//==============================================================================
/*
 * Implementation ...
 */

template <class H>
inline bool findSingleThreshold(const CHistogramBase<H>& Histogram,
                                typename H::tItem& Threshold
                                )
{
    static const tSize MIN_DISTANCE = 2;
    
    typedef typename H::tHistogram tHistogram;
    typedef typename H::tBin tBin;
    typedef typename H::tItem tItem;
    const tHistogram& HistogramImpl = Histogram.getImpl();
    
    // Number of bins
    tSize NumOfBins = HistogramImpl.getSize();
    
    // Find all maxima and minima
    std::vector<tSize> MaxList;
    mds::math::CVector<bool> IsMinimum(NumOfBins);
    IsMinimum.fill(false);
    for( tSize i = 1; i < NumOfBins - 1; ++i )
    {
        tBin Value = HistogramImpl.getCount(i);
        tBin Previous = HistogramImpl.getCount(i - 1);
        tBin Next = HistogramImpl.getCount(i + 1);
        
        if( Value > Previous && Value > Next )
        {
            MaxList.push_back(i);
        }
        else if( Value < Previous && Value < Next )
        {
            IsMinimum(i) = true;
        }
    }
    
    tSize Count = tSize(MaxList.size());
    if( Count < 2 )
    {
        return false;
    }
    
    // For every possible pair of maximal values
    double dMaxValue = -1.0;
    for( tSize k = 0; k < Count; ++k )
    {
        for( tSize l = k + 1; l < Count; ++l )
        {
            double dKL = double(HistogramImpl.getCount(MaxList[k]));
            dKL += double(HistogramImpl.getCount(MaxList[l]));
            
            // Evaluate peakness for all minima between the tested maxima
            tSize Last = MaxList[l] - MIN_DISTANCE;
            for( tSize m = MaxList[k] + MIN_DISTANCE; m < Last; ++m )
            {
                if( IsMinimum(m) )
                {
                    double dPeakness = dKL / double(HistogramImpl.getCount(m) + 1); 
                    if( dPeakness > dMaxValue )
                    {
                        Threshold = HistogramImpl.getLowerBound(m);
                        dMaxValue = dPeakness;
                    }
                }
            }
        }
    }
    
    return (dMaxValue > 0.0);
}

