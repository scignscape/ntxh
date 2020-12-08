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
 * Date:    2008/08/29                       
 *
 * Description:
 * - Gaussian Mixture Model (GMM) optimization using maximal likelihood
 *   estimation via the Expectation-Maximization (EM) algorithm.
 * - Weighted input feature vectors.
 */

#ifndef VPL_WeightedEM_H
#define VPL_WeightedEM_H

#include <VPL/Math/Algorithm/EM.h>


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Gaussian Mixture Model (GMM) optimization using maximal likelihood
 * estimation via the Expection-Maximization (EM) algorithm.
 * - Parameter C must be a container of feature vectors which will be clustered.
 * - Parameter N specifies dimensionality of input data.
 */
template <class C, tSize N>
class CWeightedEM : public vpl::base::CHasOptions
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
    typedef vpl::math::CGaussianFunc<double,N> tComponent;

    //! Used internal vector type.
    typedef vpl::math::CVector<double> tVector;

public:
    //! Default constructor.
    CWeightedEM(int Flags = vpl::math::MaxLikelihoodByEM::DEFAULT_FLAGS);

    //! Virtual destructor.
    virtual ~CWeightedEM() {}

    //! Changes the minimal required change of the log-likelihood function
    //! which results in a new component addition.
    CWeightedEM& setMinAddChange(double dValue);

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
    //! - Method can be called after successfull clustering process!
    tSize getNumOfComponents() const { return tSize(m_Components.size()); }

    //! Returns reference to the i-th gaussian component.
    //! - Method can be called after successfull clustering process!
    const tComponent& getComponent(tSize i) const { return m_Components[i]; }
    tComponent& getComponent(tSize i) { return m_Components[i]; }

    //! Returns soft membership function of the i-th input sample.
    //! - Method can be called after successfull clustering process!
    bool getMembership(tSize i, tVector& Membership);

    //! Returns index of the component into which the i-th input vector
    //! was classified (hard membership function).
    //! - Method can be called after successfull clustering process!
    tSize getMembership(tSize i);

protected:
    //! Gaussian functions representing mixture components/segments.
    typedef std::vector<tComponent> tComponents;

    //! Support maps.
    typedef vpl::math::CMatrix<double> tMaps;

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
    vpl::math::CUniformPRNG m_Uniform;

    //! Random number generator with normal distribution.
    vpl::math::CNormalPRNG m_Normal;

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
    void processMStep(const tContainer& Input, tSize NumOfSamples);

    //! Iterates both E-step and M-step.
    //! - Returns final value of the log-likelihood function
    double iterateEM(const tContainer& Input, double dMinChange, tSize NumOfSamples);

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
#include "WeightedEM.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_WeightedEM_H

