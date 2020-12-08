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
 * - Volume histogram functions.
 */


//==============================================================================
/*
 * Functions templates.
 */

template <class V>
inline bool histogramEqualization(CVolumeBase<V>& Volume)
{
    typedef typename V::tVoxel tVoxel;
    V& VolumeImpl = Volume.getImpl();

    // Useful constants
    static const tVoxel VoxelMin = CPixelTraits<tVoxel>::getPixelMin();
    static const tVoxel VoxelMax = CPixelTraits<tVoxel>::getPixelMax();

    // Histogram of the image
    typedef CFullHistogram<V> tHistogram;
    tHistogram Histogram(VoxelMin, VoxelMax);
    if( !Histogram(VolumeImpl) )
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
    double dNorm = double(VoxelMax - VoxelMin) / double(Max);
    for( tSize k = 0; k < VolumeImpl.getZSize(); ++k )
    {
        for( tSize j = 0; j < VolumeImpl.getYSize(); ++j )
        {
            for( tSize i = 0; i < VolumeImpl.getXSize(); ++i )
            {
                tSize Index = Histogram.getIndex(VolumeImpl(i,j,k));
                VolumeImpl(i,j,k) = tVoxel(dNorm * Histogram.getCount(Index) + VoxelMin);
            }
        }
    }

    // O.K.
    return true;
}

template <class V>
inline bool singleThresholding(CVolumeBase<V>& Volume)
{
    typedef typename V::tVoxel tVoxel;
    typedef typename V::tIterator tIterator;
    V& VolumeImpl = Volume.getImpl();
    
    // Useful constants
    static const tSize NumOfBins = 128;
    static const tVoxel VoxelMin = CPixelTraits<tVoxel>::getPixelMin();
    static const tVoxel VoxelMax = CPixelTraits<tVoxel>::getPixelMax();
    
    // Histogram
    typedef CHistogram<V> tHistogram;
    tHistogram Histogram(NumOfBins, VoxelMin, VoxelMax);
    if( !Histogram(VolumeImpl) )
    {
        return false;
    }
    
    // Find an optimal threshold
    tVoxel Threshold = VoxelMax;
    if( !findSingleThreshold(Histogram, Threshold) )
    {
        return false;
    }
    
    // Compare voxels with the found threshold
    VolumeImpl.forEach(CSingleThresholding<tVoxel>(Threshold));
    
    // O.K.
    return true;
}


template <class V>
inline bool multiIterativeThresholding(CVolumeBase<V>& Volume, int NumOfThresholds)
{
    typedef typename V::tVoxel tVoxel;
    typedef typename V::tIterator tIterator;
    V& VolumeImpl = Volume.getImpl();
    
    // Useful constants
    static const tVoxel VoxelMin = CPixelTraits<tVoxel>::getPixelMin();
    static const tVoxel VoxelMax = CPixelTraits<tVoxel>::getPixelMax();
    
    // Histogram
    typedef CFullHistogram<V> tHistogram;
    tHistogram Histogram(VoxelMin, VoxelMax);
    if( !Histogram(VolumeImpl) )
    {
        return false;
    }
    
    // Find "optimal" thresholds using the iterative algorithm
    CMultiThresholding<tVoxel> Thresholds;
    if( !findThresholdsIterative(Histogram, NumOfThresholds, Thresholds) )
    {
        return false;
    }
    
    // Compare voxels with the found thresholds
    VolumeImpl.forEach(Thresholds);
    
    // O.K.
    return true;
}


template <class V>
inline bool singleOtsuThresholding(CVolumeBase<V>& Volume)
{
    typedef typename V::tVoxel tVoxel;
    typedef typename V::tIterator tIterator;
    V& VolumeImpl = Volume.getImpl();
    
    // Useful constants
    static const tVoxel VoxelMin = CPixelTraits<tVoxel>::getPixelMin();
    static const tVoxel VoxelMax = CPixelTraits<tVoxel>::getPixelMax();
        
    // Histogram
    typedef CFullHistogram<V> tHistogram;
    tHistogram Histogram(VoxelMin, VoxelMax);
    if( !Histogram(VolumeImpl) )
    {
        return false;
    }
    
    // Find an optimal threshold
    tVoxel Threshold = VoxelMax;
    if( !findSingleThresholdOtsu(Histogram, Threshold) )
    {
        return false;
    }
    
    // Final thresholding
    VolumeImpl.forEach(CSingleThresholding<tVoxel>(Threshold));
    
    // O.K.
    return true;
}

