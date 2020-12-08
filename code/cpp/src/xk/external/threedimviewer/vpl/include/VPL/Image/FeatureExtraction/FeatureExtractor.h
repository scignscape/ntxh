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
 * - Image feature extraction.
 */

#ifndef VPL_FeatureExtractor_H
#define VPL_FeatureExtractor_H

#include <VPL/Base/Exception.h>

#include "FeatureVector.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global definitions.
 */

namespace FeatureVector
{
    //! Exception send on feature vector evaluation failure.
    //! - See the CFeatureExtractor class for more details.
    VPL_DECLARE_EXCEPTION(CCannotEvaluate, "Cannot evaluate feature vector")
}


//==============================================================================
/*!
 * Base class for all image feature extractors.
 */
template <class V>
class CFeatureExtractor
{
public:
    //! Check that V is a feature vector type. You will see name of this enum
    //! somewhere in compiler error message if the type V can't be used.
    enum { FEATURE_VECTOR_MUST_BE_GIVEN = V::CLASS_FEATURE_VECTOR };

    //! Feature vector.
    typedef V tVector;

    //! Type representing single feature.
    typedef typename tVector::tFeature tFeature;

public:
    //! Default constructor.
    CFeatureExtractor() {}

    // Extracts and acumulates charakteristics ...
//    void accumulate(...);

    // Acumulates charakteristics from a given feature extractor.
//    void accumulate(const CFeatureExtractor& Extractor) = 0;

    // Evaluates features according to the acumulated characteristics
    // and writes result to a given feature vector.
    // - Throws CCannotEvaluate exception on failure.
    // - Changes internal state of the feature vector.
//    void evaluate(tVector& Vector) = 0;

    // Clears all internal structures and counters.
//    void clear() = 0;
};


} // namespace img
} // namespace vpl

#endif // VPL_FeatureExtractor_H
