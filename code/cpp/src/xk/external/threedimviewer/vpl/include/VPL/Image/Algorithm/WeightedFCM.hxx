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
 * - Fuzzy C-means clustering algortihm.
 * - Weighted input feature vectors.
 */


//==============================================================================
/*
 * Implementation of the CWeightedFCM class.
 */
template <class C, tSize N>
CWeightedFCM<C,N>::CWeightedFCM(int Flags)
    : vpl::base::CHasOptions(Flags)
    , m_dWeight(vpl::math::FuzzyCMeans::DEFAULT_WEIGHT)
{
    VPL_ASSERT(m_dWeight >= 1.0);

    m_dExponent = 2.0 / (m_dWeight - 1.0);
}


template <class C, tSize N>
CWeightedFCM<C,N>& CWeightedFCM<C,N>::setWeight(double dWeight)
{
    VPL_ASSERT(dWeight >= 1.0);

    m_dWeight = dWeight;
    m_dExponent = 2.0 / (m_dWeight - 1.0);

    return *this;
}


template <class C, tSize N>
bool CWeightedFCM<C,N>::execute(const tContainer& Input)
{
    // Number of samples
    tConstIterator it(Input);
    tSize NumOfSamples = it.getSize();

    // Check the number of samples
    VPL_CHECK(NumOfSamples > 0, return false);

    // Check size of the feature vector
    VPL_CHECK(NUM_OF_DIMENSIONS <= it->getSize(), return false);

    // Initialize the number of clusters
    tSize NumOfClusters = 1;

    // Initial Dunn's coefficient
    double dDunnCoeff = -1.0;

    // Membership function having the best Dunn's coefficient
    tMatrix BestMembership, BestClusters;

    // Test various numbers of clusters
    for( ;; )
    {
        // Resize the membership matrix
        m_Membership.resize(NumOfClusters, NumOfSamples);
        m_Powers.resize(NumOfClusters, NumOfSamples);

        // Resize the vector of cluster centers
        m_Clusters.resize(NumOfClusters, NUM_OF_DIMENSIONS);

        // Compute the FCM
        iterateFCM(Input, vpl::math::FuzzyCMeans::MIN_CHANGE);

        // Compute the Dunn's coefficient
        double dNewValue = computeDunnCoefficient();

        if( this->checkOption(vpl::math::FuzzyCMeans::LOGGING_ENABLED) )
        {
            VPL_LOG_INFO("CWeightedFCM::operator():");
            VPL_LOG_INFO("  Dunn's coeficient:  " << dNewValue);
        }

        // Estimate changes
//        if( dNewValue < dDunnCoeff )
        if( dNewValue < dDunnCoeff || dNewValue > 1.0 )
        {
            break;
        }

        // Save the current membership function
        BestMembership.resize(NumOfClusters, NumOfSamples);
        BestMembership = m_Membership;

        // Save the current clusters
        BestClusters.resize(NumOfClusters, NUM_OF_DIMENSIONS);
        BestClusters = m_Clusters;

        // Update current Dunn's coefficient
        dDunnCoeff = dNewValue;

        // Increment the number of clusters
        ++NumOfClusters;
    }

    // Use the best result
    --NumOfClusters;
    m_Membership.resize(NumOfClusters, NumOfSamples);
    m_Membership = BestMembership;
    m_Clusters.resize(NumOfClusters, NUM_OF_DIMENSIONS);
    m_Clusters = BestClusters;

    // O.K.
    return true;
}


template <class C, tSize N>
bool CWeightedFCM<C,N>::execute(const tContainer& Input, tSize NumOfClusters)
{
    VPL_CHECK(NumOfClusters > 0, return false);

    // Number of samples
    tConstIterator it(Input);
    tSize NumOfSamples = it.getSize();

    // Check the number of samples
    VPL_CHECK(NumOfSamples > 0, return false);

    // Check size of the feature vector
    VPL_CHECK(NUM_OF_DIMENSIONS <= it->getSize(), return false);

    // Resize the membership matrix
    m_Membership.resize(NumOfClusters, NumOfSamples);
    m_Powers.resize(NumOfClusters, NumOfSamples);

    // Resize the vector of cluster centers
    m_Clusters.resize(NumOfClusters, NUM_OF_DIMENSIONS);

    // Compute the FCM
    iterateFCM(Input, vpl::math::FuzzyCMeans::MIN_CHANGE);

    // O.K.
    return true;
}


template <class C, tSize N>
bool CWeightedFCM<C,N>::getCluster(tSize i, tCluster& Cluster)
{
    VPL_CHECK(i >= 0 && i < m_Clusters.getNumOfRows(), return false);

    Cluster.asEigen() = m_Clusters.asEigen().block(i, 0, 1, m_Clusters.getNumOfCols());

    return true;
}


template <class C, tSize N>
bool CWeightedFCM<C,N>::getMembership(tSize i, tVector& Membership)
{
    VPL_CHECK(i >= 0 && i < m_Membership.getNumOfCols(), return false);

    Membership.asEigen() = m_Membership.asEigen().block(0, i, m_Membership.getNumOfRows(), 1);

    return true;
}


template <class C, tSize N>
tSize CWeightedFCM<C,N>::getMembership(tSize i)
{
    VPL_CHECK(i >= 0 && i < m_Membership.getNumOfCols(), return -1);

    vpl::tSize Max = 0;
    for( vpl::tSize j = 1; j < m_Membership.getNumOfRows(); ++j )
    {
        if( m_Membership(j, i) > m_Membership(Max, i) )
        {
            Max = j;
        }
    }
    return Max;
}


template <class C, tSize N>
void CWeightedFCM<C,N>::iterateFCM(const tContainer& Input, double dMinChange)
{
    // Random membership function
    initMembership();

    // Initial value of the objective function
    double dObjectiveFunc = 1.0;

    // Iterate while the function converges
    for( int i = 0; i < vpl::math::FuzzyCMeans::MAX_ITERS; i++ )
    {
        // Recompute matrix of membership powers
        recomputePowers();

        // Update cluster centers
        recomputeClusterCenters(Input);

        if( this->checkOption(vpl::math::FuzzyCMeans::LOGGING_ENABLED) )
        {
            VPL_LOG_INFO("CWeightedFCM::iterateFCM():");
            for( vpl::tSize k = 0; k < m_Clusters.getNumOfRows(); ++k )
            {
                VPL_LOG_INFO("  Cluster " << k << ": " << m_Clusters.asEigen().block(k, 0, 1, m_Clusters.getNumOfCols()));
            }
        }

        // Update the membership matrix
        recomputeMembership(Input);

        // Evaluate the objective function
        double dNewValue = recomputeObjectiveFunction(Input);

        // Change of the objective function
        double dDelta = vpl::math::getAbs(dNewValue / dObjectiveFunc - 1.0);

        if( this->checkOption(vpl::math::FuzzyCMeans::LOGGING_ENABLED) )
        {
            VPL_LOG_INFO("CWeightedFCM::iterateFCM():");
            VPL_LOG_INFO("  Objective Function = " << dNewValue);
            VPL_LOG_INFO("  Delta = " << dDelta);
        }

        // Estimate changes
        if( dDelta < dMinChange || dNewValue < dMinChange )
        {
            break;
        }

        // Update the current value
        dObjectiveFunc = dNewValue;
    }
}


template <class C, tSize N>
void CWeightedFCM<C,N>::initMembership()
{
    tSize NumOfClusters = m_Membership.getNumOfRows();

    m_Membership.zeros();

    for( tSize j = 0; j < m_Membership.getNumOfCols(); ++j )
    {
        tSize Index = vpl::math::round2Int(m_Uniform.random(0, NumOfClusters - 1));
        m_Membership(Index, j) = 1;
    }
}


template <class C, tSize N>
bool CWeightedFCM<C,N>::checkMembership()
{
    double dTemp = vpl::math::getSum<double>(m_Membership) / m_Membership.getNumOfCols();

    return (vpl::math::getAbs(dTemp - 0.1) < 0.001);
}


template <class C, tSize N>
double CWeightedFCM<C,N>::getMembership(const tItem& Sample, tSize i)
{
    tVector Cluster(m_Clusters.getNumOfCols());
    Cluster.asEigen() = m_Clusters.asEigen().block(i, 0, 1, m_Clusters.getNumOfCols());

    double dNumerator = vpl::math::getError<double>(Sample, Cluster);

    double dMembership = 0.0;
    for( tSize j = 0; j < m_Clusters.getNumOfRows(); ++j )
    {
        Cluster.asEigen() = m_Clusters.asEigen().block(j, 0, 1, m_Clusters.getNumOfCols());

        double dTemp = vpl::math::getError<double>(Sample, Cluster);
        dTemp = (dTemp > 0.0) ? dNumerator / dTemp : 0.0;
        dMembership += pow(dTemp, m_dExponent);
    }

    return (dMembership > 0.0) ? 1.0 / dMembership : 1.0;
}


template <class C, tSize N>
void CWeightedFCM<C,N>::recomputeMembership(const tContainer& Input)
{
    for( tSize i = 0; i < m_Membership.getNumOfRows(); ++i )
    {
        tConstIterator it(Input);
        for( tSize j = 0; it; ++it, ++j )
        {
            m_Membership(i, j) = getMembership(*it, i);
        }
    }
}


template <class C, tSize N>
void CWeightedFCM<C,N>::recomputePowers()
{
    for( vpl::tSize i = 0; i < m_Powers.getNumOfRows(); ++i )
    {
        for( vpl::tSize j = 0; j < m_Powers.getNumOfCols(); ++j )
        {
            m_Powers(i, j) = std::pow(m_Membership(i, j), m_dWeight);
        }
    }
}


template <class C, tSize N>
void CWeightedFCM<C,N>::recomputeClusterCenters(const tContainer& Input)
{
    tVector Cluster(m_Clusters.getNumOfCols());

    for( vpl::tSize i = 0; i < m_Clusters.getNumOfRows(); ++i )
    {
        Cluster.asEigen() = m_Clusters.asEigen().block(i, 0, 1, m_Clusters.getNumOfCols());

        double dDenom = 0.0;
        Cluster.zeros();

        tConstIterator it(Input);
        for( tSize j = 0; it; ++it, ++j )
        {
            Cluster.asEigen() += it->asEigen() * (m_Powers(i,j) * it->getNumOfSamples());
//            inplaceMultAdd(Cluster, *it, m_Powers(i, j) * it->getNumOfSamples());
            dDenom += m_Powers(i, j) * it->getNumOfSamples();
        }

        if( dDenom > 0.0 )
        {
            double dInvDenom = 1.0 / dDenom;
            Cluster *= vpl::CScalard(dInvDenom);
        }

        m_Clusters.asEigen().block(i, 0, 1, m_Clusters.getNumOfCols()) = Cluster.asEigen();
    }
}


template <class C, tSize N>
double CWeightedFCM<C,N>::recomputeObjectiveFunction(const tContainer& Input)
{
    double dResult = 0.0;

    tVector Cluster(m_Clusters.getNumOfCols());

    for( tSize i = 0; i < m_Clusters.getNumOfRows(); ++i )
    {
        Cluster.asEigen() = m_Clusters.asEigen().block(i, 0, 1, m_Clusters.getNumOfCols());

        tConstIterator it(Input);
        for( tSize j = 0; it; ++it, ++j )
        {
            double dTemp = vpl::math::getError<double>(*it, Cluster);
            dResult += it->getNumOfSamples() * m_Powers(i, j) * dTemp * dTemp;
        }
    }

    return dResult;
}


template <class C, tSize N>
double CWeightedFCM<C,N>::computeDunnCoefficient()
{
    double dInvNumOfClusters = 1.0 / m_Membership.getNumOfRows();
    double dInvNumOfSamples = 1.0 / m_Membership.getNumOfCols();

    double dCoefficient = 0.0;
    for( tSize i = 0; i < m_Membership.getNumOfRows(); ++i )
    {
        for( tSize j = 0; j < m_Membership.getNumOfCols(); ++j )
        {
            dCoefficient += m_Membership(i, j) * m_Membership(i, j) * dInvNumOfSamples;
        }
    }

    return (dCoefficient - dInvNumOfClusters) / (1.0 - dInvNumOfClusters + 0.000001);
}

