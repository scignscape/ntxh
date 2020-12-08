//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2009 by Michal Spanel          \n
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/01/09                          \n
 *
 * $Id: mdsPixelStatsExtractor.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Extraction of basic statistics from any set of image pixels.
 */

#ifndef MDS_PixelStatsExtractor_H
#define MDS_PixelStatsExtractor_H

#include <MDSTk/Image/mdsImage.h>

#include "mdsFeatureExtractor.h"
#include "mdsPixelStats.h"

// STl
#include <cmath>


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Class used to extract image features for a triangle.
 * - Parameter T specifies image pixel type.
 */
template <typename T>
class CPixelStatsExtractor : public CFeatureExtractor<CPixelStats>
{
public:
    //! Base class.
    typedef CFeatureExtractor<CPixelStats> tBase;

    //! Type representing feature value.
    typedef typename tBase::tFeature tFeature;

    //! Feature vector.
    typedef typename tBase::tVector tVector;

    //! Image pixel type.
    typedef T tPixel;

public:
    //! Default constructor.
    CPixelStatsExtractor()
        : m_dSum(0.0)
        , m_dSumSqr(0.0)
        , m_iNumOfPixels(0)
    {}

    //! Copy constructor.
    CPixelStatsExtractor(const CPixelStatsExtractor& Extractor)
        : m_dSum(Extractor.m_dSum)
        , m_dSumSqr(Extractor.m_dSumSqr)
        , m_iNumOfPixels(Extractor.m_iNumOfPixels)
    {}

    //! Destructor.
    ~CPixelStatsExtractor() {}

    //! Assignement operator.
    inline CPixelStatsExtractor& operator =(const CPixelStatsExtractor& Extractor);


    //! Extracts and acumulates image charakteristics from a given pixel value.
    inline void accumulate(tPixel Value);

    //! Acumulates image charakteristics from a given feature extractor.
    inline void accumulate(const CPixelStatsExtractor& Extractor);

    // Evaluates features according to the acumulated characteristics
    // and writes result to a given feature vector.
    // - Throws CCannotEvaluate exception on failure.
    // - Changes internal state of the feature vector.
    void evaluate(tVector& Vector);

    //! Clears all internal statistics.
    inline void clear();

protected:
    //! Sum of all pixels.
    double m_dSum, m_dSumSqr;

    //! Number of pixels counted.
    int m_iNumOfPixels;
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsPixelStatsExtractor.hxx"


} // namespace img
} // namespace mds

#endif // MDS_PixelStatsExtractor_H
