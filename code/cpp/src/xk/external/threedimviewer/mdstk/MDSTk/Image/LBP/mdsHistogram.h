//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2009/03/03                                \n
 *
 * $Id: mdsHistogram.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - LBP histogram class.
 */

#ifndef MDS_LBP_Histogram_H
#define MDS_LBP_Histogram_H

#include "mdsOperators.h"

#include <MDSTk/Image/FeatureExtraction/mdsFeatureVector.h>
#include <MDSTk/Math/VectorFunctions/mdsGeneral.h>


namespace mds
{
namespace lbp
{

//==============================================================================
/*!
 * LBP feature vector - histogram of LBP codes extracted from an image region.
 * - It may be extracted from any reliable set of image points.
 */
template <int N>
class CLBPHistogram : public mds::img::CFeatureVector<unsigned, N>
{
public:
    //! Base class.
    typedef mds::img::CFeatureVector<unsigned, N> tBase;

    //! Type representing a single feature value.
    typedef typename tBase::tFeature tFeature;

    //! Minimal number of points required to correctly evaluate the LBP histogram.
    enum { MIN_NUM_OF_POINTS = 64 };

    //! Normalized histogram (sum of all values = 1).
    typedef mds::img::CFeatureVector<float, N> tNormalized;

public:
    //! Default constructor.
    CLBPHistogram()
        : tBase(mds::img::FeatureVector::NOT_EVALUATED)
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
class CNormLBPHistogram : public mds::img::CFeatureVector<float, N>
{
public:
    //! Base class.
    typedef mds::img::CFeatureVector<float, N> tBase;

    //! Type representing a single feature value.
    typedef typename tBase::tFeature tFeature;

public:
    //! Default constructor.
    CNormLBPHistogram() : tBase(mds::img::FeatureVector::NOT_EVALUATED) {}

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

#include "mdsHistogram.hxx"


} // namespace lbp
} // namespace mds

#endif // MDS_LBP_Histogram_H
