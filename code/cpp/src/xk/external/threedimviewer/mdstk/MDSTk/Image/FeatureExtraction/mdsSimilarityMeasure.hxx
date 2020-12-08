//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/01/15                          \n
 *
 * $Id: mdsSimilarityMeasure.hxx 1868 2010-09-02 22:27:07Z spanel $
 *
 * Description:
 * - Feature vector similarity measures.
 */


//==============================================================================
/*
 * Implementation of the class CMeanValueSimilarity.
 */

template <class V>
const double CMeanValueSimilarity<V>::DEFAULT_RHO = 500.0;

template <class V>
const double CMeanValueSimilarity<V>::DEFAULT_THRESHOLD = 0.1;


//==============================================================================
/*
 * Implementation of the class CVarianceSimilarity.
 */

template <class V>
const double CVarianceSimilarity<V>::DEFAULT_THRESHOLD = 0.8;


template <class V>
inline double CVarianceSimilarity<V>::calculate(const tFeatureVector& v1, const tFeatureVector& v2)
{
    int N1 = v1.getNumOfSamples();
    int N2 = v2.getNumOfSamples();
    int N = N1 + N2;
    if( N == 0 )
    {
        return 0.0;
    }

    double dInvN = 1.0 / N;
    double dM0 = (N1 * v1.get(0) + N2 * v2.get(0)) * dInvN;

    double dTemp = dM0 - v1.get(0);
    double dV10 = v1.get(1) + dTemp * dTemp;

    dTemp = dM0 - v2.get(0);
    double dV20 = v2.get(1) + dTemp * dTemp;

    double dV0 = (N1 * dV10 + N2 * dV20) * dInvN;
    double dValue = std::sqrt(v1.get(1)) * std::sqrt(v2.get(1));
    return (dValue + 0.0001) / (dV0 + 0.0001);
}

