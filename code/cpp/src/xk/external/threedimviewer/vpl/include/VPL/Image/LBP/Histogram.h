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

#ifndef VPL_LBP_Histogram_H
#define VPL_LBP_Histogram_H

#include "Operators.h"

#include <VPL/Image/FeatureExtraction/FeatureVector.h>
#include <VPL/Math/VectorFunctions/General.h>


namespace vpl
{
namespace lbp
{

//==============================================================================
/*!
 * LBP feature vector - histogram of LBP codes extracted from an image region.
 * - It may be extracted from any reliable set of image points.
 */
template <int N>
class CLBPHistogram : public vpl::img::CFeatureVector<unsigned, N>
{
public:
    //! Base class.
    typedef vpl::img::CFeatureVector<unsigned, N> tBase;

    //! Type representing a single feature value.
    typedef typename tBase::tFeature tFeature;

    //! Minimal number of points required to correctly evaluate the LBP histogram.
    enum { MIN_NUM_OF_POINTS = 64 };

    //! Normalized histogram (sum of all values = 1).
    typedef vpl::img::CFeatureVector<float, N> tNormalized;

public:
    //! Default constructor.
    CLBPHistogram()
        : tBase(vpl::img::FeatureVector::NOT_EVALUATED)
        , m_iNumOfPoints(0)
    {}

    //! Copy constructor.
    CLBPHistogram(const CLBPHistogram& Histogram)
        : tBase(Histogram)
        , m_iNumOfPoints(Histogram.m_iNumOfPoints)
    {}

    //! Destructor.
    ~CLBPHistogram() {}

    //! Assignment operator.
    inline CLBPHistogram& operator =(const CLBPHistogram& Histogram);


    //! Returns the number of points taken into account.
    int getNumOfPoints() const { return m_iNumOfPoints; }

    //! Increases the number of points.
    void addPoints(int Value = 1) { m_iNumOfPoints += Value; }

    //! Sets the number of pixels.
    CLBPHistogram& setNumOfPoints(int iValue)
    {
        m_iNumOfPoints = iValue;
        return *this;
    }


    //! Normalizes the LBP histogram so that the sum of all colums
    //! will be equal to one.
    void normalize(tNormalized& Normalized);

protected:
    //! Total number of image pixels.
    int m_iNumOfPoints;
};


//==============================================================================
/*!
 * Normalized histogram of LBP codes (sum of all values = 1).
 */
template <int N>
class CNormLBPHistogram : public vpl::img::CFeatureVector<float, N>
{
public:
    //! Base class.
    typedef vpl::img::CFeatureVector<float, N> tBase;

    //! Type representing a single feature value.
    typedef typename tBase::tFeature tFeature;

public:
    //! Default constructor.
    CNormLBPHistogram() : tBase(vpl::img::FeatureVector::NOT_EVALUATED) {}

    //! Copy constructor.
    CNormLBPHistogram(const CNormLBPHistogram& Histogram) : tBase(Histogram) {}

    //! Destructor.
    ~CNormLBPHistogram() {}

    //! Assignment operator.
    CNormLBPHistogram& operator =(const CNormLBPHistogram& Histogram)
    {
        static_cast<tBase&>(*this) = static_cast<const tBase&>(Histogram);
        return *this;
    }
};


//=============================================================================
/*
 * Implementation...
 */

#include "Histogram.hxx"


} // namespace lbp
} // namespace vpl

#endif // VPL_LBP_Histogram_H
