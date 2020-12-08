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
 * Copyright (c) 2003-2010 by Michal Spanel  
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/09/02                       
 *
 * Description:
 * - Fuzzy C-means clustering algorithm.
 * - Weighted input feature vectors.
 */

#ifndef VPL_WeightedFCM_H
#define VPL_WeightedFCM_H

#include <VPL/Math/Algorithm/FuzzyCMeans.h>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Fuzzy c-Means clustering algorithm.
 * - Parameter C must be a container of feature vectors which will be clustered.
 * - Dimensionality of the input data is given by the N parameter.
 */
template <class C, tSize N>
class CWeightedFCM : public vpl::base::CHasOptions
{
public:
    //! Check that C has an iterator declared. You will see name of this enum somewhere
    //! in compiler error message if the type C can't be used with iterators.
    enum { NO_ITERATOR_IS_DECLARED_FOR_TEMPLATE_PARAMETER = C::ITERATOR_DECLARED };

    //! Dimensionality of input data.
    enum { NUM_OF_DIMENSIONS = N };

    //! Container type.
    typedef C tContainer;

    //! Container iterator type.
    typedef typename C::tConstIterator tConstIterator;

    //! Container item.
    typedef typename tConstIterator::tItem tItem;

    //! Vector representing one cluster.
    typedef vpl::math::CStaticVector<double,N> tCluster;

    //! Used internal vector type.
    typedef vpl::math::CVector<double> tVector;

public:
    //! Default constructor.
    CWeightedFCM(int Flags = vpl::math::FuzzyCMeans::DEFAULT_WEIGHT);

    //! Virtual destructor.
    virtual ~CWeightedFCM() {}

    //! Changes the weighting factor.
    CWeightedFCM& setWeight(double dWeight);

    //! Returns the number od dimensions.
    tSize getNumOfDimensions() const { return NUM_OF_DIMENSIONS; }

    //! Clustering of a given set of numbers or vectors.
    //! - Optimal number of clusters is estimated.
    //! - Return false on failure.
    bool execute(const tContainer& Input);

    //! Clustering of a given set of numbers or vectors.
    //! - Return false on failure.
    bool execute(const tContainer& Input, tSize NumOfClusters);

    //! Returns the number of clusters.
    //! - Method can be called after successfull clustering process!
    tSize getNumOfClusters() const { return m_Clusters.getNumOfRows(); }

    //! Returns center of the i-th cluster.
    //! - Method can be called after successfull clustering process!
    bool getCluster(tSize i, tCluster& Cluster);

    //! Returns soft membership function of the i-th input sample.
    //! - Method can be called after successfull clustering process!
    bool getMembership(tSize i, tVector& Membership);

    //! Returns index of the cluster into which the i-th input vector
    //! was classified (hard membership function).
    //! - Method can be called after successfull clustering process!
    tSize getMembership(tSize i);

protected:
    //! Used internal matrix type.
    typedef vpl::math::CMatrix<double> tMatrix;

    //! Weighting factor.
    double m_dWeight;

    //! Helper variables.
    double m_dExponent;

    //! Membership matrix.
    tMatrix m_Membership;

    //! Helper matrix.
    tMatrix m_Powers;

    //! Cluster centers.
    tMatrix m_Clusters;

    //! Uniform random number generator.
    vpl::math::CUniformPRNG m_Uniform;

protected:
    //! Iterates FCM.
    void iterateFCM(const tContainer& Input, double dMinChange);

    //! Randomly initializes the membership matrix.
    void initMembership();

    //! Checks if the membership matrix is O.K.
    bool checkMembership();

    //! Returns membership of a given sample in i-th cluster.
    double getMembership(const tItem& Sample, tSize i);

    //! Re-computes membership for every sample.
    void recomputeMembership(const tContainer& Input);

    //! Re-computes matrix of powers of the membership function.
    void recomputePowers();

    //! Compute new positions of cluster centers.
    void recomputeClusterCenters(const tContainer& Input);

    //! Returns value of the objective function.
    double recomputeObjectiveFunction(const tContainer& Input);

    //! Computes the Dunn's partitions coefficient.
    double computeDunnCoefficient();
};


//==============================================================================
/*
 * Method templates.
 */

// Include the file containing method templates.
#include "WeightedFCM.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_WeightedFCM_H

