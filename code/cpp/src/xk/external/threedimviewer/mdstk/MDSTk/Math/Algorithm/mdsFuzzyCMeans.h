//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/09/02                          \n
 *
 * $Id: mdsFuzzyCMeans.h 2096 2012-02-16 19:34:46Z spanel $
 *
 * Description:
 * - Fuzzy C-means clustering algortihm.
 */

#ifndef MDS_FuzzyCMeans_H
#define MDS_FuzzyCMeans_H

#include <MDSTk/Base/mdsGlobalLog.h>
#include <MDSTk/Base/mdsHasOptions.h>

#include <MDSTk/Math/mdsRandom.h>
#include <MDSTk/Math/mdsLogNum.h>
#include <MDSTk/Math/mdsMatrix.h>
#include <MDSTk/Math/mdsVector.h>
#include <MDSTk/Math/mdsGaussianFunc.h>
#include <MDSTk/Math/mdsMatrixFunctions.h>
#include <MDSTk/Math/mdsVectorFunctions.h>

// STL
#include <cmath>


namespace mds
{
namespace math
{

//==============================================================================
/*
 * Global constants and definitions.
 */

namespace FuzzyCMeans
{
    //! Flags which may be passed to the FCM algorithm.
    enum EOptions
    {
        //! Enables advanced logging.
        LOGGING_ENABLED     = 1 << 0,

        //! Default flags.
        DEFAULT_FLAGS       = LOGGING_ENABLED
    };

    //! Default weighting factor (>1).
    const double DEFAULT_WEIGHT     = 1.5;

    //! Minimal required change of the objective function.
    const double MIN_CHANGE         = 1.0e-6;

    //! Maximal allowed number of iterations.
    const tSize MAX_ITERS           = 100;
}


//==============================================================================
/*
 * Fuzzy c-Means clustering algorithm.
 * - Only static vectors and fundamental types of container items are allowed.
 * - Parameter C is a container type whose items will be clustered.
 * - Dimensionality of the input data is given by the N parameter.
 */
template <class C, tSize N>
class CFuzzyCMeans : public mds::base::CHasOptions
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
    typedef CStaticVector<double,N> tCluster;

    //! Used internal vector type.
    typedef CVector<double> tVector;

public:
    //! Default constructor.
    CFuzzyCMeans(int Flags = FuzzyCMeans::DEFAULT_FLAGS);

    //! Virtual destructor.
    virtual ~CFuzzyCMeans() {}

    //! Changes the weighting factor.
    CFuzzyCMeans& setWeight(double dWeight);

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
    typedef CMatrix<double> tMatrix;

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
    CUniformPRNG m_Uniform;

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
#include "mdsFuzzyCMeans.hxx"


} // namespace math
} // namespace mds

#endif // MDS_FuzzyCMeans_H

