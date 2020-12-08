//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2009/03/03                                \n
 *
 * $Id: mdsHistogram.hxx 2100 2012-02-17 07:36:55Z spanel $
 *
 * Description:
 * - LBP histogram class.
 */


//=============================================================================
/*
 * Implementation...
 */

template <int N>
inline CLBPHistogram<N>& CLBPHistogram<N>::operator =(const CLBPHistogram<N>& Histogram)
{
    static_cast<tBase&>(*this) = static_cast<const tBase&>(Histogram);
    m_iNumOfPoints = Histogram.m_iNumOfPoints;

    return *this;
}


template <int N>
void CLBPHistogram<N>::normalize(tNormalized& Normalized)
{
    if( m_iNumOfPoints < MIN_NUM_OF_POINTS )
    {
        Normalized.setState(mds::img::FeatureVector::NOT_EVALUATED);
        Normalized.fill(0.0f);
        return;
    }

    double dInvSum = mds::math::getSum<double>(*this);
    dInvSum = (dInvSum > 0.0) ? 1.0 / dInvSum : 1.0;
    for( tSize i = 0; i < N; ++i )
    {
        Normalized(i) = float(this->at(i) * dInvSum);
    }

    Normalized.setState(mds::img::FeatureVector::VALID);
}

