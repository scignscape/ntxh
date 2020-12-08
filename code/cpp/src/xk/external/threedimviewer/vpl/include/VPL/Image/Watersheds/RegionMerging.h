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
 * Copyright (c) 2003-2009 by Michal Spanel          
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz       
 * Date:    2009/01/15                               
 *
 * $Id:
 *
 * File description:
 * - Region merging algorithm.
 */

#ifndef VPL_RegionMerging_H
#define VPL_RegionMerging_H

#include <VPL/Base/StaticAssert.h>
#include <VPL/Base/HasOptions.h>
#include <VPL/Math/Vector.h>
#include <VPL/Base/Logging.h>
#include <VPL/Base/Array.h>

#include "../FeatureExtraction/PixelStatsExtractor.h"
#include "../FeatureExtraction/SimilarityMeasure.h"
#include "../Utilities/AdjacencyGraph.h"

// STL
#include <vector>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Type definitions.
 */

namespace RegionMerging
{
    //! Region merging options.
    enum EOptions
    {
        MEAN_VALUE  = 1,            //! Merging based on mean pixel value.
        VARIANCE    = 2,            //! Merging based on pixel value variance.
        DEFAULT     = MEAN_VALUE
    };

    //! Default similarity threshold.
//    const double DEFAULT_SIMILARITY_THRESHOLD = 0.5;
    const double DEFAULT_SIMILARITY_THRESHOLD = 0.001;

    //! Default stopping criterion - ratio of the current and minimum similarity.
    const double DEFAULT_SIMILARITY_RATIO = 2.5;
}


//==============================================================================
/*!
 * Class providing watershed transform.
 * - Parameter I is an image type.
 */
template <class I, template <typename> class Measure = CMeanValueSimilarity>
class CRegionMerging : public vpl::base::CHasOptions, public Measure<CPixelStats>
{
public:
    //! Check that I is an image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Input image type.
	typedef typename I::tImage tImage;

	//! Input image pixel type.
	typedef typename I::tPixel tPixel;

    //! Output image containing labels of found image regions.
    typedef CImage32 tRegionImage;

	//! Output image pixel type.
	typedef typename CImage32::tPixel tRegionNumber;

    //! Used feature vector.
	typedef CPixelStats tFeatureVector;

	//! Used feature extractor.
	typedef CPixelStatsExtractor<tPixel> tFeatureExtractor;

	//! Similarity measure.
    using Measure<CPixelStats>::calculate;

public:
    //! Constructor.
    CRegionMerging(int Flags = 0)
        : vpl::base::CHasOptions(Flags)
        , m_dSimThreshold(RegionMerging::DEFAULT_SIMILARITY_THRESHOLD)
        , m_dSimRatio(RegionMerging::DEFAULT_SIMILARITY_RATIO)
    {}

    //! Destructor.
	~CRegionMerging() {}

	//! Provides region merging algorithm using the region adjacency graph.
	//! - Produces a label image whose image pixels represent indexes
	//!   of image regions.
	//! - Modifies the input RegionImage.
	bool operator()(const tImage& SrcImage, tRegionImage& RegionImage);

    //! Sets the similarity threshold.
    CRegionMerging& setSimilarityThreshold(double dValue)
    {
        m_dSimThreshold = dValue;
        return *this;
    }

    //! Sets the stopping criterion.
    CRegionMerging& setSimilarityRatio(double dValue)
    {
        m_dSimRatio = dValue;
        return *this;
    }

protected:
    //! Region adjacency graph.
    typedef CAdjacencyGraph<double> tRAG;

protected:
    //! Similarity threshold (= minimal value of the similarity measure that results
    //! in region merging).
    double m_dSimThreshold;

    //! Stopping criterion (= maximal allowed ratio of the current similarity and
    //! the minimum similarity that has been observed in previous merging steps).
    double m_dSimRatio;

protected:
    //! Re-assignes labels to image regions so that there will be no skipped values.
    //! - Returns the final number of regions in the image.
    tRegionNumber reassignRegions(tRegionImage& RegionImage);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "RegionMerging.hxx"


} // namespace vpl
} // namespace img

#endif // VPL_RegionMerging_H

