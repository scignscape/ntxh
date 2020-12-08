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
 *   estimation via the Expection-Maximization (EM) algorithm.
 * - Weighted input feature vectors.
 */

//==============================================================================
/*
 * Implementation of the CWeightedEM class.
 */
template <class C, tSize N>
CWeightedEM<C,N>::CWeightedEM(int Flags)
    : vpl::base::CHasOptions(Flags)
    , m_dMinAddChange(vpl::math::MaxLikelihoodByEM::MIN_ADD_CHANGE)
{
    VPL_ASSERT(m_dMinAddChange > 0.0);
}


template <class C, tSize N>
CWeightedEM<C,N>& CWeightedEM<C,N>::setMinAddChange(double dValue)
{
    VPL_ASSERT(dValue > 0.0);

    m_dMinAddChange = dValue;
    return *this;
}


template <class C, tSize N>
bool CWeightedEM<C,N>::execute(const tContainer& Input)
{
    // Count the number of samples
    tConstIterator it(Input);
    tSize NumOfSamples = 0, NumOfRealSamples = 0;
    for( ; it; ++it )
    {
        ++NumOfSamples;
        NumOfRealSamples += it->getNumOfSamples();
    }

    // Check the number of samples
    VPL_CHECK(NumOfSamples > 0, return false);

    // Check size of the input vectors
    VPL_CHECK(NUM_OF_DIMENSIONS <= it->getSize(), return false);

    // Initialize the number of components
    tSize NumOfMixtures = 1;

    // Initial log-likelihood
//    double dLogLikelihood = 1.0;

    // Initial MDL
//    double dMDL = -DBL_MAX;
    double dMDL = DBL_MAX;

    if( this->checkOption(vpl::math::MaxLikelihoodByEM::LOGGING_ENABLED) )
    {
        VPL_LOG_INFO("CWeightedEM::execute(): Initial MDL = " << dMDL);
    }

    // Resize the support maps
    m_Maps.resize(NumOfMixtures, NumOfSamples);

    // Resize the vector of gaussian compontents
    m_Components.resize(NumOfMixtures);

    // Initialize the first component
    initFirstComponent(Input);

    // Best support maps
    tMaps BestMaps;
    tComponents BestComponents;

    // Test various numbers of clusters
    for( ;; )
    {
        // Compute the EM
        double dNewValue = iterateEM(Input, vpl::math::MaxLikelihoodByEM::MIN_CHANGE, NumOfRealSamples);

        // Estimate change of the log-likelihood
/*        double dDelta = getAbs(dNewValue / dLogLikelihood - 1.0);

        // Estimate changes
        if( dDelta < m_dMinAddChange )
        {
            break;
        }*/

        // Estimate the new MDL
//        double dNewMDL = computeMDL(dNewValue, NumOfSamples);
        double dNewMDL = computeMDL(dNewValue, NumOfRealSamples);

        if( this->checkOption(vpl::math::MaxLikelihoodByEM::LOGGING_ENABLED) )
        {
            VPL_LOG_INFO("CWeightedEM::execute(): MDL = " << dNewMDL);
        }

        // Estimate changes
//        if( dNewMDL < dMDL )
        if( dNewMDL > dMDL )
        {
            break;
        }

        // Save the current support maps
        BestMaps.resize(NumOfMixtures, NumOfSamples);
        BestMaps = m_Maps;

        // Update current log-likelihood
//        dLogLikelihood = dNewValue;

        // Update current MDL
        dMDL = dNewMDL;

        // Find the largest component
        tSize ComponentToSplit = findComponent();

        // Increment the number of components
        ++NumOfMixtures;

        // Resize support maps
        m_Maps.resize(NumOfMixtures, NumOfSamples);

        // Resize vector of components
        BestComponents = m_Components;
        m_Components.resize(NumOfMixtures);

        // Split the largest component
        splitComponent(ComponentToSplit, NumOfMixtures - 1);
    }

    // Use the best result
    --NumOfMixtures;
    m_Maps.copy(BestMaps);
    m_Components.swap(BestComponents);

    // O.K.
    return true;
}


template <class C, tSize N>
bool CWeightedEM<C,N>::execute(const tContainer& Input, tSize NumOfClasses)
{
    // Number of samples
    tConstIterator it(Input);
    tSize NumOfSamples = 0, NumOfRealSamples = 0;
    for( ; it; ++it )
    {
        ++NumOfSamples;
        NumOfRealSamples += it->getNumOfSamples();
    }

    // Check the number of samples
    VPL_CHECK(NumOfSamples > 0, return false);

    // Check size of the input vectors
    VPL_CHECK(NUM_OF_DIMENSIONS <= it->getSize(), return false);

    // Initialize the number of clusters
    tSize NumOfMixtures = 1;

    // Resize the support maps
    m_Maps.resize(NumOfMixtures, NumOfSamples);

    // Resize the vector of segment parameters
    m_Components.resize(NumOfMixtures);

    // Initialize the first component
    initFirstComponent(Input);

    // Test various numbers of clusters
    for( int c = 0; c < NumOfClasses; ++c )
    {
        // Training
        iterateEM(Input, vpl::math::MaxLikelihoodByEM::MIN_CHANGE, NumOfRealSamples);

        // Do not split the last component
        if( NumOfMixtures == NumOfClasses )
        {
            break;
        }

        // Find the largest component
        tSize ComponentToSplit = findComponent();

        // Increment the number of components
        ++NumOfMixtures;

        // Resize support maps
        m_Maps.resize(NumOfMixtures, NumOfSamples);

        // Resize vector of components
        m_Components.resize(NumOfMixtures);

        // Split the largest component
        splitComponent(ComponentToSplit, NumOfMixtures - 1);
    }

    // O.K.
    return true;
}


template <class C, tSize N>
bool CWeightedEM<C,N>::getMembership(tSize i, tVector& Membership)
{
    VPL_CHECK(i >= 0 && i < m_Maps.getNumOfCols(), return false);

    Membership.asEigen() = m_Maps.asEigen().block(0, i, m_Maps.getNumOfRows(), 1);

    return true;
}


template <class C, tSize N>
tSize CWeightedEM<C,N>::getMembership(tSize i)
{
    VPL_CHECK(i >= 0 && i < m_Maps.getNumOfCols(), return -1);

    tSize Max = 0;
    for( vpl::tSize j = 1; j < m_Maps.getNumOfRows(); ++j )
    {
        if( m_Maps(j, i) > m_Maps(Max, i) )
        {
            Max = j;
        }
    }
    return Max;
}


template <class C, tSize N>
void CWeightedEM<C,N>::clearSupportMaps()
{
    m_Maps.zeros();
}


template <class C, tSize N>
void CWeightedEM<C,N>::initComponentMean(tSize i, const tContainer& Input)
{
    static const tSize MIN_NUM_OF_SAMPLES = 100;
    static const tSize MAX_NUM_OF_SAMPLES = 1000;

    tSize NumOfSamples = m_Maps.getNumOfCols();

    // Randomly choose a small subset of samples
    tSize First = vpl::math::round2Int(m_Uniform.random(0, NumOfSamples -1 ));

    //?tSize Size = vpl::math::getMin(vpl::math::round2Int(m_Uniform.random(MIN_NUM_OF_SAMPLES, MAX_NUM_OF_SAMPLES)), NumOfSamples - First);
    tSize Size = vpl::math::getMin(vpl::math::round2Int(m_Uniform.random(MIN_NUM_OF_SAMPLES, MAX_NUM_OF_SAMPLES)),
                                   (int) (NumOfSamples - First) );

    // Mean
    tMean Mean;
    Mean.fill(0.0);

    // Find first sample of the subset
    tConstIterator it = Input.getBegin();
    for( tSize j = 0; j < First; ++j )
    {
        ++it;
    }

    // Compute mean of features
    int Count = 0;
    for( tSize k = 0; k < Size; ++k, ++it )
    {
//        inplaceMultAdd(Mean, *it, double(it->getNumOfSamples()));
        Mean.asEigen() += it->asEigen() * double(it->getNumOfSamples());
        Count += it->getNumOfSamples();
    }

    // Mean
    Mean *= 1.0 / Count;

    // Initialize the mixture component
    m_Components[i].setMean(Mean);
}


template <class C, tSize N>
void CWeightedEM<C,N>::initComponentCov(tSize i)
{
    static const double dConst = 1.0 / (2 * tComponent::NUM_OF_DIMENSIONS);

    tComponent& Component = m_Components[i];

    double dMin = DBL_MAX;
    for( tSize j = 0; j < getNumOfComponents(); ++j )
    {
        if( j != i )
        {
            tMean Temp = Component.getMean();
            Temp -= m_Components[j].getMean();
            double dValue = vpl::math::getProd<double>(Temp, Temp);
            if( dValue < dMin )
            {
                dMin = dValue;
            }
        }
    }
    dMin *= dConst;

    for( tSize m = 0; m < tComponent::NUM_OF_DIMENSIONS; ++m )
    {
        Component.setCov(m, dMin);
    }
}


template <class C, tSize N>
void CWeightedEM<C,N>::initComponentWeight(tSize i, double dWeight)
{
    m_Components[i].setWeight(dWeight);
}


template <class C, tSize N>
bool CWeightedEM<C,N>::initFirstComponent(const tContainer& Input)
{
    VPL_CHECK(getNumOfComponents() == 1 && m_Maps.getNumOfCols() > 0, return false);

    // Compute mean value of all samples
    tMean Mean;
    Mean.fill(0.0);
    int Count = 0;
    for( tConstIterator it(Input); it; ++it )
    {
//        inplaceMultAdd(Mean, *it, double(it->getNumOfSamples()));
        Mean.asEigen() += it->asEigen() * double(it->getNumOfSamples());
        Count += it->getNumOfSamples();
    }

    // Mean
    double dInvNum = 1.0 / Count;
    Mean *= vpl::CScalard(dInvNum);

    // Compute covariance matrix of all input values
    tCov Cov;
    Cov.fill(0.0);
    for( tConstIterator it(Input); it; ++it )
    {
        tMean Diff(*it);
        Diff -= Mean;

        // Covariance matrix
        for( tSize m = 0; m < tComponent::NUM_OF_DIMENSIONS; ++m )
        {
            Cov(m) += double(it->getNumOfSamples()) * Diff(m) * Diff(m);
        }
    }

    // Mean
    Cov *= vpl::CScalard(dInvNum);

    // Initialize the mixture component
    m_Components[0].setMean(Mean);
    m_Components[0].setCov(Cov);
    m_Components[0].setWeight(1.0);

    // O.K.
    return true;
}


template <class C, tSize N>
void CWeightedEM<C,N>::addRandomNoise(double dNoiseCoeff)
{
    // Find maximal variance in each dimension
/*    tCov AuxCov = m_Components[0].getCov();
    for( tSize k = 0; k < tComponent::NUM_OF_DIMENSIONS; ++k )
    {
        for( tSize l = 1; l < getNumOfComponents(); ++l )
        {
            AuxCov(k) = vpl::math::getMax(AuxCov(k), m_Components[l].getCov().get(k));
        }
        AuxCov(k) = std::sqrt(AuxCov(k));
    }*/

    for( tSize i = 0; i < getNumOfComponents(); ++i )
    {
        tMean& Mean = m_Components[i].getMean();
        tCov& Cov = m_Components[i].getCov();

        for( tSize j = 0; j < tComponent::NUM_OF_DIMENSIONS; ++j )
        {
            Mean(j) += m_Normal.random(0.0, dNoiseCoeff * std::sqrt(Cov(j)));
//            Mean(j) += m_Normal.random(0.0, dNoiseCoeff * AuxCov(j));
        }
    }
}


template <class C, tSize N>
double CWeightedEM<C,N>::computeLogLikelihood(const tContainer& Input)
{
    // Value stored in the logarithmic space
    vpl::math::CLogNum<double> Result = 1.0;

    // Traverse input data
    tMean Mean;
    Mean.fill(0.0);
    for( tConstIterator it(Input); it; ++it )
    {
        // Sum of probabilities
        double dSum = 0.0;
        for( tSize j = 0; j < getNumOfComponents(); ++j )
        {
            dSum += m_Components[j].getWeightedValue(*it);
        }

        // TODO: Modify this...
        for( int i = 0; i < it->getNumOfSamples(); ++i )
        {
            Result *= dSum;
        }
    }

    return Result.get(vpl::math::LogNum::LOG_VALUE);
}


template <class C, tSize N>
double CWeightedEM<C,N>::computeMDL(double dLogLikelihood, tSize NumOfSamples)
{
    tSize k = getNumOfComponents();
    tSize d = getNumOfDimensions();

//    return dLogLikelihood - 0.5 * (k - 1 + 2 * k * d) * std::log(double(NumOfSamples));
    return -2.0 * dLogLikelihood + (k - 1 + 2 * k * d) * std::log(double(NumOfSamples));
}


template <class C, tSize N>
bool CWeightedEM<C,N>::areSeparated(tSize i, tSize j, int c)
{
    VPL_CHECK(i >= 0 && i < getNumOfComponents(), return false);
    VPL_CHECK(j >= 0 && j < getNumOfComponents(), return false);

    tMean& Mean1 = m_Components[i].getMean();
    tCov& Cov1 = m_Components[i].getCov();

    tMean& Mean2 = m_Components[j].getMean();
    tCov& Cov2 = m_Components[j].getCov();

//    double dMaxTrace = vpl::math::getMax(vpl::math::getSum<double>(Cov1), vpl::math::getSum<double>(Cov2));
    double dMaxTrace = 0.5 * vpl::math::getSum<double>(Cov1) + 0.5 * vpl::math::getSum<double>(Cov2);
    double dMax = c * std::sqrt(dMaxTrace);

    tMean M = Mean1;
    M -= Mean2;
    double dValue = std::sqrt(vpl::math::getSumOfSquares<double>(M));

    if( this->checkOption(vpl::math::MaxLikelihoodByEM::LOGGING_ENABLED) )
    {
        VPL_LOG_INFO("CWeightedEM::areSeparated(): " << dValue << " >= " << dMax);
    }

    return (dValue >= dMax);
}


template <class C, tSize N>
int CWeightedEM<C,N>::getDegreeOfSeparation(tSize NumOfComponents)
{
    static const int MIN = 4;
    static const int DIV = 2;

    if( NumOfComponents <= MIN )
    {
        return 1;
    }

    return 1 + (NumOfComponents - MIN) / DIV;
}


template <class C, tSize N>
tSize CWeightedEM<C,N>::findComponent()
{
    VPL_ASSERT(getNumOfComponents() > 0);

    if( getNumOfComponents() == 1 )
    {
        return 0;
    }

    double dMaxValue = vpl::math::getSum<double>(m_Components[0].getCov());

    tSize Max = 0;
    for( tSize i = 1; i < getNumOfComponents(); ++i )
    {
        double dValue = vpl::math::getSum<double>(m_Components[i].getCov());
        if( dValue > dMaxValue )
        {
            Max = i;
            dMaxValue = dValue;
        }
    }

    return Max;
}


template <class C, tSize N>
void CWeightedEM<C,N>::splitComponent(tSize Index, tSize NewIndex)
{
    VPL_ASSERT(Index < getNumOfComponents() && NewIndex < getNumOfComponents());

    tMean& Mean = m_Components[Index].getMean();
    tCov& Cov = m_Components[Index].getCov();
    double dWeight = m_Components[Index].getWeight();

    // Find maximum
    tSize Max = 0;
    double dMaxValue = Cov(0);
    for( tSize i = 1; i < tComponent::NUM_OF_DIMENSIONS; ++i )
    {
        if( Cov(i) > dMaxValue )
        {
            Max = i;
            dMaxValue = Cov(i);
        }
    }

    // New values
    double dNewMean = vpl::math::MaxLikelihoodByEM::SPLITTING_COEFF * std::sqrt(dMaxValue);
    double dNewWeight = 0.5 * dWeight;

    // Create a new component
    m_Components[NewIndex].setMean(Mean);
    m_Components[NewIndex].setCov(Cov);

    // Modify the original component
    Mean(Max) += dNewMean;
    m_Components[Index].setWeight(dNewWeight);

    // Modify the new component
    m_Components[NewIndex].getMean().at(Max) -= dNewMean;
    m_Components[NewIndex].setWeight(dNewWeight);
}


template <class C, tSize N>
bool CWeightedEM<C,N>::checkForSimilarComponents()
{
    if( getNumOfComponents() < 2 )
    {
        return false;
    }

    // Compute degree of separation
    int iC = getDegreeOfSeparation(getNumOfComponents());

    // Check similarity of all possible pairs of components
    for( tSize i = 0; i < getNumOfComponents(); ++i )
    {
        for( tSize j = i + 1; j < getNumOfComponents(); ++j )
        {
            // Degree of separation
            if( !areSeparated(i, j, iC) )
            {
                // Splitting of the largest component
                tSize k = findComponent();
                if( k != j )
                {
                    splitComponent(k, j);
                }
                else
                {
                    splitComponent(k, i);
                }

                // Terminate the function
                // - Just one component could be reinitialized at the moment
                if( this->checkOption(vpl::math::MaxLikelihoodByEM::LOGGING_ENABLED) )
                {
                    VPL_LOG_INFO("CWeightedEM::checkForSimilarComponents():");
                    VPL_LOG_INFO("  Splitting " << k << " component...");
                }

                return true;
            }
        }
    }

    // No change
    return false;
}


template <class C, tSize N>
void CWeightedEM<C,N>::processEStep(const tContainer& Input)
{
    // Clear all support maps
    clearSupportMaps();

    // Traverse all samples
    tConstIterator it(Input);
    for( tSize j = 0; it; ++j, ++it )
    {
        // Add probabilities to the support maps
        double dSum = 0.0;
        tSize i;
        for( i = 0; i < getNumOfComponents(); ++i )
        {
//            double dTemp = double(it->getNumOfSamples()) * m_Components[i].getWeightedValue(*it);
            double dTemp = m_Components[i].getWeightedValue(*it);
            m_Maps(i,j) += dTemp;
            dSum += dTemp;
        }

        // Invert the computed sum
        double dInvSum = (dSum > 0.0) ? 1.0 / dSum : 1.0;

        // Divide the value in each support map
        for( i = 0; i < getNumOfComponents(); ++i )
        {
            m_Maps(i,j) *= dInvSum;
        }
    }
}


template <class C, tSize N>
void CWeightedEM<C,N>::processMStep(const tContainer& Input, tSize NumOfSamples)
{
    // Helper value
//    double dInvNum = 1.0 / m_Maps.getNumOfCols();
    double dInvNum = 1.0 / NumOfSamples;

    // For each segment form new values of its parameters
    for( tSize i = 0; i < getNumOfComponents(); ++i )
    {
        // Mixture component mean
        tMean& Mean = m_Components[i].getMean();

        // Clear the mean value and covariance matrix
        tMean NewMean;
        NewMean.fill(0.0);
        tCov NewCov;
        NewCov.fill(0.0);

        // Initialize sums
        double dPSum = 0.0;

        // For each sample
        tConstIterator it(Input);
        for( tSize j = 0; it; ++j, ++it )
        {
            dPSum += double(it->getNumOfSamples()) * m_Maps(i, j);
//            dPSum += m_Maps(i, j);

            NewMean.asEigen() += it->asEigen() * (double(it->getNumOfSamples()) * m_Maps(i, j));
//            NewMean.asEigen() += it->asEigen() * m_Maps(i, j);
//            inplaceMultAdd(NewMean, *it, it->getNumOfSamples() * m_Maps(i, j));
//            inplaceMultAdd(NewMean, *it, m_Maps(i, j));

            tMean Temp = *it;
            Temp -= Mean;
            for( tSize m = 0; m < tComponent::NUM_OF_DIMENSIONS; ++m )
            {
                NewCov(m) += Temp(m) * Temp(m) * double(it->getNumOfSamples()) * m_Maps(i, j);
//                NewCov(m) += Temp(m) * Temp(m) * m_Maps(i, j);
            }
        }

        // Safe invert of the sum
        double dInvPSum = (dPSum > 0.0) ? 1.0 / dPSum : 1.0;

        // Final values of the component mean and covariance matrix
        NewMean *= vpl::CScalard(dInvPSum);
        NewCov *= vpl::CScalard(dInvPSum);

        // Update the current component
        m_Components[i].setWeight(dPSum * dInvNum);
        m_Components[i].setMean(NewMean);
        m_Components[i].setCov(NewCov);

        // Component inverse of the covariance matrix
        m_Components[i].computeInverse();
    }
}


template <class C, tSize N>
double CWeightedEM<C,N>::iterateEM(const tContainer& Input, double dMinChange, tSize NumOfSamples)
{
//    static const double INITIAL_NOISE_COEFF = 1.0;
//    static const double INITIAL_NOISE_COEFF = 0.5;
//    static const double INITIAL_NOISE_COEFF = 1.5;
    static const double INITIAL_NOISE_COEFF = 0.5;

    // Initial value of the log-likelihood function
    double dLogLikelihoodFunc = 1.0;

    // Initial coefficient of the random noise
    double dRandNoise = INITIAL_NOISE_COEFF;

    // Second level iterations
    for( tSize j = 0; j < vpl::math::MaxLikelihoodByEM::MAX_ITERS2; ++j )
    {
        if( this->checkOption(vpl::math::MaxLikelihoodByEM::ADD_RAND_NOISE) )
        {
            // Add random noise to every mixture component
            addRandomNoise(dRandNoise);

            // Modify the random noise coefficient
            dRandNoise *= vpl::math::MaxLikelihoodByEM::RAND_NOISE_COEFF;
        }

        // Re-initialization of similar components
        if( checkForSimilarComponents() )
        {
            dRandNoise = INITIAL_NOISE_COEFF;
        }

        // Initial value of the log-likelihood function
        dLogLikelihoodFunc = 1.0;

        // Iterate while the function converges
        for( tSize i = 0; i < vpl::math::MaxLikelihoodByEM::MAX_ITERS; ++i )
        {
            // E-step
            processEStep(Input);

            // M-step
            processMStep(Input, NumOfSamples);

            // Evaluate the log-likelihood function
            double dNewValue = computeLogLikelihood(Input);

            // Eestimate change of the log-likelihood function
            double dDelta = vpl::math::getAbs(dNewValue / dLogLikelihoodFunc - 1.0);

            if( this->checkOption(vpl::math::MaxLikelihoodByEM::LOGGING_ENABLED) )
            {
                VPL_LOG_INFO("CWeightedEM::iterateEM()");
//            VPL_LOG_INFO("CWeightedEM::iterateEM()");
                VPL_LOG_INFO("  Log-likelihood Function = " << dNewValue);
                VPL_LOG_INFO("  Delta = " << dDelta);
            }

            // Estimate changes
            if( dDelta < dMinChange /*|| dNewValue < dMinChange*/ )
            {
                break;
            }

            // Update the current value
            dLogLikelihoodFunc = dNewValue;
        }

        if( getNumOfComponents() == 0 )
        {
            break;
        }
    }

    if( this->checkOption(vpl::math::MaxLikelihoodByEM::LOGGING_ENABLED) )
    {
        VPL_LOG_INFO("CWeightedEM::iterateEM()");
        for( tSize k = 0; k < getNumOfComponents(); ++k )
        {
            VPL_LOG_INFO("  Component " << k << ":");
            VPL_LOG_INFO("    Weight = " << m_Components[k].getWeight());
            VPL_LOG_INFO("    Mean = " << m_Components[k].getMean());
            VPL_LOG_INFO("    Cov = " << m_Components[k].getCov());
        }
    }

    // Final log-likelihood function value
    return dLogLikelihoodFunc;
}

