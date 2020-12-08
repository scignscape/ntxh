//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/08/29                          \n
 *
 * $Id: mdsEM.h 2096 2012-02-16 19:34:46Z spanel $
 *
 * Description:
 * - Gaussian Mixture Model (GMM) optimization using maximal likelihood
 *   estimation via the Expection-Maximization (EM) algorithm.
 */

#ifndef MDS_EM_H
#define MDS_EM_H

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
#include <vector>
#include <cfloat>
#include <cmath>


namespace mds
{
namespace math
{

//==============================================================================
/*
 * Global constants and definitions.
 */

namespace MaxLikelihoodByEM
{
    //! Flags which may be passed to the EM algorithm.
    enum EOptions
    {
        //! Enables advanced logging.
        LOGGING_ENABLED     = 1 << 0,

        //! Enables adding of random noise during iterations.
        ADD_RAND_NOISE      = 1 << 1,

        //! Default flags.
        DEFAULT_FLAGS       = LOGGING_ENABLED | ADD_RAND_NOISE
    };

    //! Minimal required change of the log-likelihood function
    //! which results in a new component addition.
    const double MIN_ADD_CHANGE     = 0.001;

    //! Minimal required change of the log-likelihood function
    //! while iterating.
    const double MIN_CHANGE         = 1.0e-6;

    //! Coefficient used to split a gaussian component.
    const double SPLITTING_COEFF    = 0.5;

    //! Maximal allowed number of iterations.
    const tSize MAX_ITERS           = 10;

    //! Maximal allowed number of internal iterations.
    const tSize MAX_ITERS2          = 10;

    //! Random noise.
    const double RAND_NOISE_COEFF   = 0.5;
}


//==============================================================================
/*!
 * Gaussian Mixture Model (GMM) optimization using maximal likelihood
 * estimation via the Expection-Maximization (EM) algorithm.
 * - Parameter C is a container type whose items will be clustered.
 * - Only static vectors and fundamental types of container items are allowed.
 * - Parameter N specifies dimensionality of input data.
 */
template <class C, tSize N>
class CMaxLikelihoodByEM : public mds::base::CHasOptions
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

    //! Gaussian function.
    typedef CGaussianFunc<double,N> tComponent;

    //! Used internal vector type.
    typedef CVector<double> tVector;

public:
    //! Default constructor.
    CMaxLikelihoodByEM(int Flags = MaxLikelihoodByEM::DEFAULT_FLAGS);

    //! Virtual destructor.
    virtual ~CMaxLikelihoodByEM() {}

    //! Changes the minimal required change of the log-likelihood function
    //! which results in a new component addition.
    CMaxLikelihoodByEM& setMinAddChange(double dValue);

    //! Returns the number od dimensions.
    tSize getNumOfDimensions() const { return NUM_OF_DIMENSIONS; }

    //! Estimates GMM of input data.
    //! - Return false on failure.
    bool execute(const tContainer& Input);

    //! Estimates GMM of input data.
    //! - Fixed number of mixture components.
    //! - Return false on failure.
    bool execute(const tContainer& Input, tSize NumOfClasses);

    //! Returns the number of components.
    //! - Method can be called after successfull clustering!
    tSize getNumOfComponents() const { return tSize(m_Components.size()); }

    //! Returns reference to the i-th gaussian component.
    //! - Method can be called after successfull clustering!
    const tComponent& getComponent(tSize i) const { return m_Components[i]; }
    tComponent& getComponent(tSize i) { return m_Components[i]; }

    //! Returns soft membership function of the i-th input sample.
    //! - Method can be called after successfull clustering!
    bool getMembership(tSize i, tVector& Membership);

    //! Returns index of the component into which the i-th input vector
    //! was classified (hard membership function).
    //! - Method can be called after successfull clustering!
    tSize getMembership(tSize i);

protected:
    //! Gaussian functions representing mixture components/segments.
    typedef std::vector<tComponent> tComponents;

    //! Support maps.
    typedef CMatrix<double> tMaps;

    //! Gaussian component mean.
    typedef typename tComponent::tVector tMean;

    //! Diagonal of the gaussian component covariance matrix.
    typedef typename tComponent::tVector tCov;

protected:
    //! Minimal required change of the log-likelihood function
    //! which results in component addition.
    double m_dMinAddChange;

    //! Mixture model components.
    tComponents m_Components;

    //! Support maps.
    tMaps m_Maps;

    //! Uniform random number generator.
    CUniformPRNG m_Uniform;

    //! Random number generator with normal distribution.
    CNormalPRNG m_Normal;

protected:
    //! Clears all support maps.
    void clearSupportMaps();

    //! Random intialization of i-th component mean value.
    void initComponentMean(tSize i, const tContainer& Input);

    //! Intialization of a component covariance matrix
    void initComponentCov(tSize i);

    //! Intialization of a component weight.
    void initComponentWeight(tSize i, double dWeight);

    //! Initialization of the first mixture component.
    bool initFirstComponent(const tContainer& Input);

    //! Add random noise to i-th component.
    void addRandomNoise(double dNoiseCoeff);

    //! Returns value of the objective function.
    double computeLogLikelihood(const tContainer& Input);

    //! Compute the MDL (Minimum Descriptive Length) coefficient.
    double computeMDL(double dLogLikelihood, tSize NumOfSamples);

    //! E-step of the algorithm.
    void processEStep(const tContainer& Input);

    //! M-step of the algorithm.
    void processMStep(const tContainer& Input);

    //! Iterates both E-step and M-step.
    //! - Returns final value of the log-likelihood function
    double iterateEM(const tContainer& Input, double dMinChange);

    //! Checks degree of separation of two given components.
    bool areSeparated(tSize i, tSize j, int c);

    //! Returns degree of separation.
    int getDegreeOfSeparation(tSize NumOfComponents);

    //! Finds component which can be further splitted.
    //! - Returns index of such componnet.
    tSize findComponent();

    //! Splits a given component.
    void splitComponent(tSize Index, tSize NewIndex);

    //! Checks for similar components.
    //! - If there are two similar components, one of them is re-initialized.
    bool checkForSimilarComponents();
};


//==============================================================================
/*
 * Method templates.
 */

// Include the file containing method templates.
#include "mdsEM.hxx"


} // namespace math
} // namespace mds

#endif // MDS_EM_H

