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
 * Copyright (c) 2009 by Michal Spanel       
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/01/09                       
 *
 * Description:
 * - Extraction of basic statistics from any set of image pixels.
 */

#ifndef VPL_PixelStatsExtractor_H
#define VPL_PixelStatsExtractor_H

#include <VPL/Image/Image.h>

#include "FeatureExtractor.h"
#include "PixelStats.h"

// STl
#include <cmath>


namespace vpl
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
#include "PixelStatsExtractor.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_PixelStatsExtractor_H
