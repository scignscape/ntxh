//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/01/15                          \n
 *
 * $Id: mdsSimilarityMeasure.h 2101 2012-02-17 08:20:21Z spanel $
 *
 * Description:
 * - Feature vectors similarity measure.
 */

#ifndef MDS_SimilarityMeasure_H
#define MDS_SimilarityMeasure_H

#include "mdsFeatureVector.h"

// STL
#include <cmath>


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Base class for all similarity measures.
 * - Parameter V specifies concrete feature vector.
 */
template <class V>
struct CSimilarityMeasure
{
    //! Check that V is a feature vector type. You will see name of this enum
    //! somewhere in compiler error message if the type V can't be used.
    enum { FEATURE_VECTOR_MUST_BE_GIVEN = V::CLASS_FEATURE_VECTOR };

    //! Feature vector type.
    typedef V tFeatureVector;

    //! Calculates similarity between two given feature vectors.
//    static double calculate(const tFeatureVector& v1, const tFeatureVector& v2);
};


//==============================================================================
/*!
 * Basic similarity measure comparing mean pixel value.
 * - The mean value must be stored as a first value in the feature vector
 *   (see CPixelStats class for detailes)!
 */
template <class V>
class CMeanValueSimilarity : public CSimilarityMeasure<V>
{
public:
    //! Base types
    typedef V tFeatureVector;

    //! Default parameters.
    static const double DEFAULT_RHO;
    static const double DEFAULT_THRESHOLD;

public:
    //! Default constructor.
    CMeanValueSimilarity(double dRho = DEFAULT_RHO)
    {
        MDS_ASSERT(dRho > 0.0);

        m_dInvRho = -0.5 / (dRho * dRho);
    }

    //! Calculates similarity between two given feature vectors.
    double calculate(const tFeatureVector& v1, const tFeatureVector& v2)
    {
//        double dTemp = v1.get(0) - v2.get(0);
//        return std::exp(m_dInvRho * dTemp * dTemp);

        double dTemp = v1(0) - v2(0);
        int N1 = v1.getNumOfSamples();
        int N2 = v2.getNumOfSamples();
        double dW = double(N1 + N2) / (double(N1) * double(N2));
        return dW * std::exp(m_dInvRho * dTemp * dTemp);
    }

protected:
    //! Parameter affecting sensitivity of the measure.
    double m_dInvRho;
};


//==============================================================================
/*!
 * Statistical test of the similarity based on pixel value variance.
 * - The variance must be stored as a second value of the feature vector
 *   (see CPixelStats class for detailes)!
 */
template <class V>
class CVarianceSimilarity : public CSimilarityMeasure<V>
{
public:
    //! Base types
    typedef V tFeatureVector;

    //! Default threshold.
    static const double DEFAULT_THRESHOLD;

public:
    //! Calculates similarity between two given feature vectors.
    inline double calculate(const tFeatureVector& v1, const tFeatureVector& v2);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods implementation
#include "mdsSimilarityMeasure.hxx"


} // namespace img
} // namespace mds

#endif // MDS_SimilarityMeasure_H

