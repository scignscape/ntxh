//==============================================================================
/*! \file
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

#ifndef MDS_RegionMerging_H
#define MDS_RegionMerging_H

#include <MDSTk/Base/mdsStaticAssert.h>
#include <MDSTk/Base/mdsHasOptions.h>
#include <MDSTk/Math/mdsVector.h>
#include <MDSTk/Base/mdsGlobalLog.h>

#include "../FeatureExtraction/mdsPixelStatsExtractor.h"
#include "../FeatureExtraction/mdsSimilarityMeasure.h"
#include "../Utilities/mdsAdjacencyGraph.h"
#include "../mdsArray.h"

// STL
#include <vector>


namespace mds
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
    const double DEFAULT_SIMILARITY_THRESHOLD = 0.5;

    //! Default stopping criterion - ratio of the current and minimum similarity.
    const double DEFAULT_SIMILARITY_RATIO = 2.5;
}


//==============================================================================
/*!
 * Class providing watershed transform.
 * - Parameter I is an image type.
 */
template <class I, template <typename> class Measure = CMeanValueSimilarity>
class CRegionMerging : public mds::base::CHasOptions, public Measure<CPixelStats>
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
        : mds::base::CHasOptions(Flags)
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
#include "mdsRegionMerging.hxx"


} // namespace mds
} // namespace img

#endif // MDS_RegionMerging_H

