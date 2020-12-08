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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/08/29                          \n
 *
 * Description:
 * - Gaussian Mixture Model (GMM) optimization using maximal likelihood
 *   estimation via the Expection-Maximization (EM) algorithm.
 */


//==============================================================================
/*
 * Implementation of the CMaxLikelihoodByEM class.
 */
template <class C, tSize N>
CMaxLikelihoodByEM<C,N>::CMaxLikelihoodByEM(int Flags)
    : vpl::base::CHasOptions(Flags)
    , m_dMinAddChange(MaxLikelihoodByEM::MIN_ADD_CHANGE)
{
    VPL_ASSERT(m_dMinAddChange > 0.0);
}


template <class C, tSize N>
CMaxLikelihoodByEM<C,N>& CMaxLikelihoodByEM<C,N>::setMinAddChange(double dValue)
{
    VPL_ASSERT(dValue > 0.0);

    m_dMinAddChange = dValue;
    return *this;
}


template <class C, tSize N>
bool CMaxLikelihoodByEM<C,N>::execute(const tContainer& Input)
{
    // Number of samples
    tConstIterator it(Input);
    tSize NumOfSamples = it.getSize();

    // Check the number of samples
    VPL_CHECK(NumOfSamples > 0, return false);

    // Check size of the input vectors
    VPL_CHECK(NUM_OF_DIMENSIONS <= makeVector(*it).getSize(), return false);

    // Initialize the number of components
    tSize NumOfMixtures = 1;

    // Initial log-likelihood
//    double dLogLikelihood = 1.0;

    // Initial MDL
//    double dMDL = -DBL_MAX;
    double dMDL = DBL_MAX;

    if( this->checkOption(MaxLikelihoodByEM::LOGGING_ENABLED) )
    {
        VPL_LOG_INFO("CMaxLikelihoodByEM::execute(): Initial MDL = " << dMDL);
    }

    // Resize the support maps
    m_Maps.resize(NumOfMixtures, NumOfSamples);

    // Resize the vector of gaussian components
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
        double dNewValue = iterateEM(Input, MaxLikelihoodByEM::MIN_CHANGE);

        // Estimate change of the log-likelihood
/*        double dDelta = getAbs(dNewValue / dLogLikelihood - 1.0);

        // Estimate changes
        if( dDelta < m_dMinAddChange )
        {
            break;
        }*/

        // Estimate the new MDL
        double dNewMDL = computeMDL(dNewValue, NumOfSamples);

        if( this->checkOption(MaxLikelihoodByEM::LOGGING_ENABLED) )
        {
            VPL_LOG_INFO("CMaxLikelihoodByEM::execute(): MDL = " << dNewMDL);
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
bool CMaxLikelihoodByEM<C,N>::execute(const tContainer& Input, tSize NumOfClasses)
{
    // Number of samples
    tConstIterator it(Input);
    tSize NumOfSamples = it.getSize();

    // Check the number of samples
    VPL_CHECK(NumOfSamples > 0, return false);

    // Check size of the input vectors
    VPL_CHECK(NUM_OF_DIMENSIONS <= makeVector(*it).getSize(), return false);

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
        iterateEM(Input, MaxLikelihoodByEM::MIN_CHANGE);

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
bool CMaxLikelihoodByEM<C,N>::getMembership(tSize i, tVector& Membership)
{
    VPL_CHECK(i >= 0 && i < m_Maps.getNumOfCols(), return false);

    Membership.asEigen() = m_Maps.asEigen().block(0, i, m_Maps.getNumOfRows(), 1);

    return true;
}


template <class C, tSize N>
tSize CMaxLikelihoodByEM<C,N>::getMembership(tSize i)
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
void CMaxLikelihoodByEM<C,N>::clearSupportMaps()
{
    m_Maps.zeros();
}


template <class C, tSize N>
void CMaxLikelihoodByEM<C,N>::initComponentMean(tSize i, const tContainer& Input)
{
    static const tSize MIN_NUM_OF_SAMPLES = 100;
    static const tSize MAX_NUM_OF_SAMPLES = 1000;

    tSize NumOfSamples = m_Maps.getNumOfCols();

    // Randomly choose a small subset of samples
    tSize First = round2Int(m_Uniform.random(0, NumOfSamples -1 ));

    //?    tSize Size = getMin(round2Int(m_Uniform.random(MIN_NUM_OF_SAMPLES, MAX_NUM_OF_SAMPLES)), NumOfSamples - First);
    tSize Size = getMin(round2Int(m_Uniform.random(MIN_NUM_OF_SAMPLES, MAX_NUM_OF_SAMPLES)),
                        (int) (NumOfSamples - First) );


    // Mean
    tMean Mean(0.0);

    // Find first sample of the subset
    tConstIterator it(Input);
    for( tSize j = 0; j < First; ++j )
    {
        ++it;
    }

    // Compute mean of tetrahedron features
    for( tSize k = 0; k < Size; ++k, ++it )
    {
        Mean += makeVector(*it);
    }

    // Mean
    Mean *= 1.0 / Size;

    // Initialize the mixture component
    m_Components[i].setMean(Mean);
}


template <class C, tSize N>
void CMaxLikelihoodByEM<C,N>::initComponentCov(tSize i)
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
            double dValue = getProd<double>(Temp, Temp);
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
void CMaxLikelihoodByEM<C,N>::initComponentWeight(tSize i, double dWeight)
{
    m_Components[i].setWeight(dWeight);
}


template <class C, tSize N>
bool CMaxLikelihoodByEM<C,N>::initFirstComponent(const tContainer& Input)
{
    VPL_CHECK(getNumOfComponents() == 1 && m_Maps.getNumOfCols() > 0, return false);

    // Compute mean value of all samples
    tMean Mean;
    Mean.fill(0.0);
    for( tConstIterator it(Input); it; ++it )
    {
        inplaceAdd(Mean, makeVector(*it));
    }

    // Mean
    double dInvNum = 1.0 / m_Maps.getNumOfCols();
    Mean *= vpl::CScalar<double>(dInvNum);

    // Compute covariance matrix of all input values
    tCov Cov;
    Cov.fill(0.0);
    for( tConstIterator it(Input); it; ++it )
    {
        tMean Diff(makeVector(*it));
        Diff -= Mean;

        // Covariance matrix
        for( tSize m = 0; m < tComponent::NUM_OF_DIMENSIONS; ++m )
        {
            Cov(m) += Diff(m) * Diff(m);
        }
    }

    // Mean
    Cov *= vpl::CScalar<double>(dInvNum);

    // Initialize the mixture component
    m_Components[0].setMean(Mean);
    m_Components[0].setCov(Cov);
    m_Components[0].setWeight(1.0);

    // O.K.
    return true;
}


template <class C, tSize N>
void CMaxLikelihoodByEM<C,N>::addRandomNoise(double dNoiseCoeff)
{
    for( tSize i = 0; i < getNumOfComponents(); ++i )
    {
        tMean& Mean = m_Components[i].getMean();
        tCov& Cov = m_Components[i].getCov();

        for( tSize j = 0; j < tComponent::NUM_OF_DIMENSIONS; ++j )
        {
            Mean(j) += m_Normal.random(0.0, dNoiseCoeff * std::sqrt(Cov(j)));
        }
    }
}


template <class C, tSize N>
double CMaxLikelihoodByEM<C,N>::computeLogLikelihood(const tContainer& Input)
{
    // Value stored in the logarithmic space
    CLogNum<double> Result = 1.0;

    // Traverse input data
    tMean Mean;
    Mean.fill(0.0);
    for( tConstIterator it(Input); it; ++it )
    {
        // Sum of probabilities
        double dSum = 0.0;
        for( tSize j = 0; j < getNumOfComponents(); ++j )
        {
            dSum += m_Components[j].getWeightedValue(makeVector(*it));
        }
        Result *= dSum;
    }

    return Result.get(LogNum::LOG_VALUE);
}


template <class C, tSize N>
double CMaxLikelihoodByEM<C,N>::computeMDL(double dLogLikelihood, tSize NumOfSamples)
{
    tSize k = getNumOfComponents();
    tSize d = getNumOfDimensions();

//    return dLogLikelihood - 0.5 * (k - 1 + 2 * k * d) * std::log(double(NumOfSamples));
    return -2.0 * dLogLikelihood + (k - 1 + 2 * k * d) * std::log(double(NumOfSamples));
}


template <class C, tSize N>
bool CMaxLikelihoodByEM<C,N>::areSeparated(tSize i, tSize j, int c)
{
    VPL_CHECK(i >= 0 && i < getNumOfComponents(), return false);
    VPL_CHECK(j >= 0 && j < getNumOfComponents(), return false);

    tMean& Mean1 = m_Components[i].getMean();
    tCov& Cov1 = m_Components[i].getCov();

    tMean& Mean2 = m_Components[j].getMean();
    tCov& Cov2 = m_Components[j].getCov();

//    double dMaxTrace = getMax(getSum<double>(Cov1), getSum<double>(Cov2));
    double dMaxTrace = 0.5 * getSum<double>(Cov1) + 0.5 * getSum<double>(Cov2);
    double dMax = c * std::sqrt(dMaxTrace);

    tMean M = Mean1;
    M -= Mean2;
    double dValue = std::sqrt(getSumOfSquares<double>(M));

    if( this->checkOption(MaxLikelihoodByEM::LOGGING_ENABLED) )
    {
        VPL_LOG_INFO("CMaxLikelihoodByEM::areSeparated(): " << dValue << " >= " << dMax);
    }

    return (dValue >= dMax);
}


template <class C, tSize N>
int CMaxLikelihoodByEM<C,N>::getDegreeOfSeparation(tSize NumOfComponents)
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
tSize CMaxLikelihoodByEM<C,N>::findComponent()
{
    VPL_ASSERT(getNumOfComponents() > 0);

    if( getNumOfComponents() == 1 )
    {
        return 0;
    }

    double dMaxValue = getSum<double>(m_Components[0].getCov());

    tSize Max = 0;
    for( tSize i = 1; i < getNumOfComponents(); ++i )
    {
        double dValue = getSum<double>(m_Components[i].getCov());
        if( dValue > dMaxValue )
        {
            Max = i;
            dMaxValue = dValue;
        }
    }

    return Max;
}


template <class C, tSize N>
void CMaxLikelihoodByEM<C,N>::splitComponent(tSize Index, tSize NewIndex)
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
    double dNewMean = MaxLikelihoodByEM::SPLITTING_COEFF * std::sqrt(dMaxValue);
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
bool CMaxLikelihoodByEM<C,N>::checkForSimilarComponents()
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
                return true;
            }
        }
    }

    // No change
    return false;
}


template <class C, tSize N>
void CMaxLikelihoodByEM<C,N>::processEStep(const tContainer& Input)
{
    // Clear all support maps
    clearSupportMaps();

    // Traverse all triangles
    tConstIterator it(Input);
    for( tSize j = 0; it; ++j, ++it )
    {
        // Add probabilities to the support maps
        double dSum = 0.0;
        tSize i;
        for( i = 0; i < getNumOfComponents(); ++i )
        {
            double dTemp = m_Components[i].getWeightedValue(makeVector(*it));
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
void CMaxLikelihoodByEM<C,N>::processMStep(const tContainer& Input)
{
    // Helper value
    double dInvNum = 1.0 / m_Maps.getNumOfCols();

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
            dPSum += m_Maps(i, j);

            inplaceMultAdd(NewMean, makeVector(*it), m_Maps(i, j));

            tMean Temp = makeVector(*it);
            Temp -= Mean;
            for( tSize m = 0; m < tComponent::NUM_OF_DIMENSIONS; ++m )
            {
                NewCov(m) += Temp(m) * Temp(m) * m_Maps(i, j);
            }
        }

        // Safe invert of the sum
        double dInvPSum = (dPSum > 0.0) ? 1.0 / dPSum : 1.0;

        // Final values of the component mean and covariance matrix
        NewMean *= vpl::CScalar<double>(dInvPSum);
        NewCov *= vpl::CScalar<double>(dInvPSum);

        // Update the current component
        m_Components[i].setWeight(dPSum * dInvNum);
        m_Components[i].setMean(NewMean);
        m_Components[i].setCov(NewCov);

        // Component inverse of the covariance matrix
        m_Components[i].computeInverse();
    }
}


template <class C, tSize N>
double CMaxLikelihoodByEM<C,N>::iterateEM(const tContainer& Input, double dMinChange)
{
//    static const double INITIAL_NOISE_COEFF = 1.5;
    static const double INITIAL_NOISE_COEFF = 0.2;

    // Initial value of the log-likelihood function
    double dLogLikelihoodFunc = 1.0;

    // Initial coefficient of the random noise
    double dRandNoise = INITIAL_NOISE_COEFF;

    // Second level iterations
    for( tSize j = 0; j < MaxLikelihoodByEM::MAX_ITERS2; ++j )
    {
        if( this->checkOption(MaxLikelihoodByEM::ADD_RAND_NOISE) )
        {
            // Add random noise to every mixture component
            addRandomNoise(dRandNoise);

            // Modify the random noise coefficient
            dRandNoise *= MaxLikelihoodByEM::RAND_NOISE_COEFF;
        }

        // Re-initialization of similar components
        if( checkForSimilarComponents() )
        {
            dRandNoise = INITIAL_NOISE_COEFF;
        }

        // Initial value of the log-likelihood function
        dLogLikelihoodFunc = 1.0;

        // Iterate while the function converges
        for( tSize i = 0; i < MaxLikelihoodByEM::MAX_ITERS; ++i )
        {
            // E-step
            processEStep(Input);

            // M-step
            processMStep(Input);

            // Evaluate the log-likelihood function
            double dNewValue = computeLogLikelihood(Input);

            // Eestimate change of the log-likelihood function
            double dDelta = getAbs(dNewValue / dLogLikelihoodFunc - 1.0);

            if( this->checkOption(MaxLikelihoodByEM::LOGGING_ENABLED) )
            {
                VPL_LOG_INFO("CMaxLikelihoodByEM::iterateEM()");
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
    }

    if( this->checkOption(MaxLikelihoodByEM::LOGGING_ENABLED) )
    {
        VPL_LOG_INFO("CMaxLikelihoodByEM::iterateEM()");
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

