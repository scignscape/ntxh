//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/09/02                          \n
 *
 * $Id: mdsFuzzyCMeans.hxx 2097 2012-02-16 20:19:05Z spanel $
 *
 * Description:
 * - Fuzzy C-means clustering algortihm.
 */

//==============================================================================
/*
 * Implementation of the CFuzzyCMeans class.
 */
template <class C, tSize N>
CFuzzyCMeans<C,N>::CFuzzyCMeans(int Flags)
    : mds::base::CHasOptions(Flags)
    , m_dWeight(FuzzyCMeans::DEFAULT_WEIGHT)
{
    MDS_ASSERT(m_dWeight >= 1.0);

    m_dExponent = 2.0 / (m_dWeight - 1.0);
}


template <class C, tSize N>
CFuzzyCMeans<C,N>& CFuzzyCMeans<C,N>::setWeight(double dWeight)
{
    MDS_ASSERT(dWeight >= 1.0);

    m_dWeight = dWeight;
    m_dExponent = 2.0 / (m_dWeight - 1.0);

    return *this;
}


template <class C, tSize N>
bool CFuzzyCMeans<C,N>::execute(const tContainer& Input)
{
    // Number of samples
    tConstIterator it(Input);
    tSize NumOfSamples = it.getSize();

    // Check the number of samples
    MDS_CHECK(NumOfSamples > 0, return false);

    // Check size of the feature vector
    MDS_CHECK(NUM_OF_DIMENSIONS <= makeVector(*it).getSize(), return false);

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
        m_Membership.create(NumOfClusters, NumOfSamples);
        m_Powers.create(NumOfClusters, NumOfSamples);

        // Resize the vector of cluster centers
        m_Clusters.create(NumOfClusters, NUM_OF_DIMENSIONS);

        // Compute the FCM
        iterateFCM(Input, FuzzyCMeans::MIN_CHANGE);

        // Compute the Dunn's coefficient
        double dNewValue = computeDunnCoefficient();

        if( this->checkOption(FuzzyCMeans::LOGGING_ENABLED) )
        {
            MDS_LOG_NOTE("CFuzzyCMeans::operator():");
            MDS_LOG_NOTE("  Dunn's coeficient:  " << dNewValue);
        }

        // Estimate changes
//        if( dNewValue < dDunnCoeff )
        if( dNewValue < dDunnCoeff || dNewValue > 1.0 )
        {
            break;
        }

        // Save the current membership function
        BestMembership.create(NumOfClusters, NumOfSamples);
        BestMembership = m_Membership;

        // Save the current clusters
        BestClusters.create(NumOfClusters, NUM_OF_DIMENSIONS);
        BestClusters = m_Clusters;

        // Update current Dunn's coefficient
        dDunnCoeff = dNewValue;

        // Increment the number of clusters
        ++NumOfClusters;
    }

    // Use the best result
    --NumOfClusters;
    m_Membership.create(NumOfClusters, NumOfSamples);
    m_Membership = BestMembership;
    m_Clusters.create(NumOfClusters, NUM_OF_DIMENSIONS);
    m_Clusters = BestClusters;

    // O.K.
    return true;
}


template <class C, tSize N>
bool CFuzzyCMeans<C,N>::execute(const tContainer& Input, tSize NumOfClusters)
{
    MDS_CHECK(NumOfClusters > 0, return false);

    // Number of samples
    tConstIterator it(Input);
    tSize NumOfSamples = it.getSize();

    // Check the number of samples
    MDS_CHECK(NumOfSamples > 0, return false);

    // Check size of the feature vector
    MDS_CHECK(NUM_OF_DIMENSIONS <= makeVector(*it).getSize(), return false);

    // Resize the membership matrix
    m_Membership.create(NumOfClusters, NumOfSamples);
    m_Powers.create(NumOfClusters, NumOfSamples);

    // Resize the vector of cluster centers
    m_Clusters.create(NumOfClusters, NUM_OF_DIMENSIONS);

    // Compute the FCM
    iterateFCM(Input, FuzzyCMeans::MIN_CHANGE);

    // O.K.
    return true;
}


template <class C, tSize N>
bool CFuzzyCMeans<C,N>::getCluster(tSize i, tCluster& Cluster)
{
    MDS_CHECK(i >= 0 && i < m_Clusters.getNumOfRows(), return false);

    Cluster.asEigen() = m_Clusters.asEigen().block(i, 0, 1, m_Clusters.getNumOfCols());

    return true;
}


template <class C, tSize N>
bool CFuzzyCMeans<C,N>::getMembership(tSize i, tVector& Membership)
{
    MDS_CHECK(i >= 0 && i < m_Membership.getNumOfCols(), return false);

    Membership.asEigen() = m_Membership.asEigen().block(0, i, m_Membership.getNumOfRows(), 1);

    return true;
}


template <class C, tSize N>
tSize CFuzzyCMeans<C,N>::getMembership(tSize i)
{
    MDS_CHECK(i >= 0 && i < m_Membership.getNumOfCols(), return -1);

    mds::tSize Max = 0;
    for( mds::tSize j = 1; j < m_Membership.getNumOfRows(); ++j )
    {
        if( m_Membership(j, i) > m_Membership(Max, i) )
        {
            Max = j;
        }
    }
    return Max;
}


template <class C, tSize N>
void CFuzzyCMeans<C,N>::iterateFCM(const tContainer& Input, double dMinChange)
{
    // Random membership function
    initMembership();

    // Initial value of the objective function
    double dObjectiveFunc = 1.0;

    // Iterate while the function converges
    for( int i = 0; i < FuzzyCMeans::MAX_ITERS; i++ )
    {
        // Recompute matrix of membership powers
        recomputePowers();

        // Update cluster centers
        recomputeClusterCenters(Input);

        if( this->checkOption(FuzzyCMeans::LOGGING_ENABLED) )
        {
            MDS_LOG_NOTE("CFuzzyCMeans::iterateFCM():");
            for( mds::tSize k = 0; k < m_Clusters.getNumOfRows(); ++k )
            {
                MDS_LOG_NOTE("  Cluster " << k << ": " << m_Clusters.asEigen().block(k, 0, 1, m_Clusters.getNumOfCols()));
            }
        }

        // Update the membership matrix
        recomputeMembership(Input);

        // Evaluate the objective function
        double dNewValue = recomputeObjectiveFunction(Input);

        // Change of the objective function
        double dDelta = getAbs(dNewValue / dObjectiveFunc - 1.0);

        if( this->checkOption(FuzzyCMeans::LOGGING_ENABLED) )
        {
            MDS_LOG_NOTE("CFuzzyCMeans::iterateFCM():");
            MDS_LOG_NOTE("  Objective Function = " << dNewValue);
            MDS_LOG_NOTE("  Delta = " << dDelta);
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
void CFuzzyCMeans<C,N>::initMembership()
{
    tSize NumOfClusters = m_Membership.getNumOfRows();

    m_Membership.zeros();

    for( tSize j = 0; j < m_Membership.getNumOfCols(); ++j )
    {
        tSize Index = round2Int(m_Uniform.random(0, NumOfClusters - 1));
        m_Membership(Index, j) = 1;
    }
}


template <class C, tSize N>
bool CFuzzyCMeans<C,N>::checkMembership()
{
    double dTemp = getSum<double>(m_Membership) / m_Membership.getNumOfCols();

    return (getAbs(dTemp - 0.1) < 0.001);
}


template <class C, tSize N>
double CFuzzyCMeans<C,N>::getMembership(const tItem& Sample, tSize i)
{
    tVector Cluster(m_Clusters.getNumOfCols());
    Cluster.asEigen() = m_Clusters.asEigen().block(i, 0, 1, m_Clusters.getNumOfCols());

    double dNumerator = getError<double>(makeVector(Sample), Cluster);

    double dMembership = 0.0;
    for( tSize j = 0; j < m_Clusters.getNumOfRows(); ++j )
    {
        Cluster.asEigen() = m_Clusters.asEigen().block(j, 0, 1, m_Clusters.getNumOfCols());

        double dTemp = getError<double>(makeVector(Sample), Cluster);
        dTemp = (dTemp > 0.0) ? dNumerator / dTemp : 0.0;
        dMembership += pow(dTemp, m_dExponent);
    }

    return (dMembership > 0.0) ? 1.0 / dMembership : 1.0;
}


template <class C, tSize N>
void CFuzzyCMeans<C,N>::recomputeMembership(const tContainer& Input)
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
void CFuzzyCMeans<C,N>::recomputePowers()
{
    for( mds::tSize i = 0; i < m_Powers.getNumOfRows(); ++i )
    {
        for( mds::tSize j = 0; j < m_Powers.getNumOfCols(); ++j )
        {
            m_Powers(i, j) = std::pow(m_Membership(i, j), m_dWeight);
        }
    }
}


template <class C, tSize N>
void CFuzzyCMeans<C,N>::recomputeClusterCenters(const tContainer& Input)
{
    tVector Cluster(m_Clusters.getNumOfCols());

    for( mds::tSize i = 0; i < m_Clusters.getNumOfRows(); ++i )
    {
        Cluster.asEigen() = m_Clusters.asEigen().block(i, 0, 1, m_Clusters.getNumOfCols());

        double dDenom = 0.0;
        Cluster.zeros();

        tConstIterator it(Input);
        for( tSize j = 0; it; ++it, ++j )
        {
            inplaceMultAdd(Cluster, makeVector(*it), m_Powers(i, j));
            dDenom += m_Powers(i, j);
        }

        if( dDenom > 0.0 )
        {
            double dInvDenom = 1.0 / dDenom;
            Cluster *= mds::CScalar<double>(dInvDenom);
        }

        m_Clusters.asEigen().block(i, 0, 1, m_Clusters.getNumOfCols()) = Cluster.asEigen();
    }
}


template <class C, tSize N>
double CFuzzyCMeans<C,N>::recomputeObjectiveFunction(const tContainer& Input)
{
    double dResult = 0.0;

    tVector Cluster(m_Clusters.getNumOfCols());

    for( tSize i = 0; i < m_Clusters.getNumOfRows(); ++i )
    {
        Cluster.asEigen() = m_Clusters.asEigen().block(i, 0, 1, m_Clusters.getNumOfCols());

        tConstIterator it(Input);
        for( tSize j = 0; it; ++it, ++j )
        {
            double dTemp = getError<double>(makeVector(*it), Cluster);
            dResult += m_Powers(i, j) * dTemp * dTemp;
        }
    }

    return dResult;
}


template <class C, tSize N>
double CFuzzyCMeans<C,N>::computeDunnCoefficient()
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

