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
 * Copyright (c) 2003-2009 by Michal Spanel        
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz     
 * Date:    2009/03/03                             
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
        Normalized.setState(vpl::img::FeatureVector::NOT_EVALUATED);
        Normalized.fill(0.0f);
        return;
    }

    double dInvSum = vpl::math::getSum<double>(*this);
    dInvSum = (dInvSum > 0.0) ? 1.0 / dInvSum : 1.0;
    for( tSize i = 0; i < N; ++i )
    {
        Normalized(i) = float(this->at(i) * dInvSum);
    }

    Normalized.setState(vpl::img::FeatureVector::VALID);
}

