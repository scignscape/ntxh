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
 * Medical Data Segmentation Toolkit (MDSTk)            \n
 * Copyright (c) 2003-2009 by Michal Spanel             \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz          \n
 * Date:    2009/01/15                                  \n
 *
 * $Id:
 *
 * File description:
 * - Region merging algorithm.
 */


//==============================================================================
/*
 * Implementation of the class CRegionMerging.
 */

template <class I, template <typename> class M>
bool CRegionMerging<I,M>::operator()(const tImage& SrcImage, tRegionImage& RegionImage)
{
    static const tSize NeighbourX[4] = { -1, 1, 0, 0 };
    static const tSize NeighbourY[4] = { 0, 0, -1, 1 };

    // Shake down used indexes of regions
    tRegionNumber NumOfRegions = reassignRegions(RegionImage);

    VPL_LOG_INFO("Initial number of regions = " << NumOfRegions);

    // Create the RAG (Region Adjacency Graph)
    typedef vpl::img::CAdjacencyGraph<double> tRAG;
    tRAG RAG(NumOfRegions);

    // Initial mapping of regions
    vpl::math::CVector<tRegionNumber> Mapping(NumOfRegions);
    for( tRegionNumber i = 0; i < NumOfRegions; ++i )
    {
        Mapping(i) = i;
    }

    // Feature extractors
    typedef std::vector<tFeatureExtractor> tExtractors;
    tExtractors Extractors(NumOfRegions);

    // Image size
    tSize XSize = vpl::math::getMin(SrcImage.getXSize(), RegionImage.getXSize());
    tSize YSize = vpl::math::getMin(SrcImage.getYSize(), RegionImage.getYSize());

    // Evaluate features of all regions and create the RAG graph
    for( tSize j = 0; j < YSize; ++j )
    {
        for( tSize i = 0; i < XSize; ++i )
        {
            // Get region
            tRegionNumber Region = RegionImage(i, j);

            // Accumulate image features
            Extractors[Region].accumulate(SrcImage(i, j));

            // Initialize the RAG
            for( int n = 0; n < 4; ++n )
            {
                tRegionNumber Region2 = RegionImage(i + NeighbourX[n], j + NeighbourY[n]);
                if( Region2 != Region )
                {
                    // Check if the RAG is already filled or not
                    if( RAG.get(Region, Region2, -1.0) == -1.0 )
                    {
                        // Set the RAG
                        RAG.set(Region, Region2, 0.0);
                    }
                }
            }
        }
    }

    // Image features
    typedef vpl::base::CArray<tFeatureVector> tFeatures;
    tFeatures Features(NumOfRegions);

    // Evaluate image features of all regions
    tRegionNumber Count = NumOfRegions;
    for( tRegionNumber r = 0; r < NumOfRegions; ++r )
    {
        try {
            Extractors[r].evaluate(Features(r));
        }
        catch( const FeatureVector::CCannotEvaluate& )
        {
            RAG.clear(r);
            --Count;
        }
    }

    // Evaluate similarity of all regions
    for( tSize r2 = 0; r2 < RAG.getNumOfRegions(); ++r2 )
    {
        tRAG::tIterator it(RAG.getNeighbours(r2).begin(), RAG.getNeighbours(r2).end());
        for( ; it; ++it )
        {
            // Get region index and value
            tSize r1 = RAG.getRegion(it);
            double dValue = RAG.getValue(it);

            // Evaluate the similarity
            if( dValue <= 0.0 )
            {
                RAG.set(r2, r1, calculate(Features(r2), Features(r1)));
            }
        }
    }

    // Minimal number of regions
    tRegionNumber NumOfPossibleMerges = Count / 10;
    tRegionNumber MinCount = (NumOfPossibleMerges > 5) ? Count - NumOfPossibleMerges : Count;

    // Helper mapping of regions
    bool bRestoreMapping = false;
    vpl::math::CVector<tRegionNumber> SavedMapping(Mapping);

    // While any two regions can be merged
    double dMinSimilarity = 1.0e6;
    for( ; Count > 0; )
    {
        // Find maximum similarity
        tSize Max1 = 0, Max2 = 0;
        double dMaxSimilarity = RAG.getMax(Max1, Max2, -1.0);

        VPL_LOG_INFO("Maximal similarity = " << dMaxSimilarity << ", r1 = " << Max1 << ", r2 = " << Max2);

        // Check the maximal similarity
        if( dMaxSimilarity <= m_dSimThreshold )
        {
            break;
        }

        // Check the termination criterion
        if( /*NumOfRegions == -1 &&*/ Count <= MinCount )
        {
            double dDelta = dMaxSimilarity / dMinSimilarity;

            VPL_LOG_INFO("Min/Max similarity ratio = " << dDelta);

            if( dDelta > m_dSimRatio )
            {
                bRestoreMapping = true;
                break;
            }
        }

        // Save the minimal similarity
        dMinSimilarity = vpl::math::getMin(dMaxSimilarity, dMinSimilarity);

        // Choose the larger region
        if( Features(Max1).getNumOfPixels() < Features(Max2).getNumOfPixels() )
        {
            vpl::math::swap2(Max1, Max2);
        }

        // Update the RAG
        RAG.merge(Max2, Max1);

        // Update feature vectors
        Extractors[Max1].accumulate(Extractors[Max2]);
        Extractors[Max1].evaluate(Features(Max1));

        // Re-compute similarity of the regions
        tRAG::tIterator it(RAG.getNeighbours(Max1).begin(), RAG.getNeighbours(Max1).end());
        for( ; it; ++it )
        {
            // Get region
            tSize i = RAG.getRegion(it);

            // Evaluate the similarity
            RAG.set(Max1, i, calculate(Features(Max1), Features(i)));
        }

        SavedMapping = Mapping;

        // Update the mapping of regions
        for( tRegionNumber m = 0; m < NumOfRegions; ++m )
        {
            if( Mapping(m) == tRegionNumber(Max2) )
            {
                Mapping(m) = tRegionNumber(Max1);
            }
        }

        // Decrease the number of regions
        --Count;
    }

    if( bRestoreMapping )
    {
        Mapping = SavedMapping;
    }

    // Re-assign all image pixels
    for( tSize j = 0; j < YSize; ++j )
    {
        for( tSize i = 0; i < XSize; ++i )
        {
            // Get region
            tRegionNumber Region = RegionImage(i, j);

            // Assign index of the new region
            RegionImage(i, j) = Mapping(Region);
        }
    }

    // Shake down used indexes of regions
    NumOfRegions = reassignRegions(RegionImage);

    VPL_LOG_INFO("Final number of regions = " << NumOfRegions);

    // O.K.
    return true;
}


template <class I, template <typename> class M>
typename CRegionMerging<I,M>::tRegionNumber CRegionMerging<I,M>::reassignRegions(tRegionImage& RegionImage)
{
    // Get the number of regions
    tRegionNumber MaxRegion = vpl::img::getMax<tRegionNumber>(RegionImage);
    if( MaxRegion <= 0 )
    {
        return 0;
    }

    // Mapping of regions
    vpl::math::CVector<tRegionNumber> Mapping(MaxRegion + 2);
    Mapping.fill(0);

    // Re-assign regions
    tRegionNumber NewIndex = 1;
    for( tSize j = 0; j < RegionImage.getYSize(); ++j )
    {
        for( tSize i = 0; i < RegionImage.getXSize(); ++i )
        {
            // Get the region label
            tRegionNumber Region = RegionImage(i, j);

            // Assign index of the new region
            if( Mapping(Region) == 0 )
            {
                Mapping(Region) = NewIndex++;
            }

            // Set region number
            RegionImage(i, j) = Mapping(Region) - 1;
        }
    }

    // Return the final number of regions
    return (NewIndex - 1);
}

