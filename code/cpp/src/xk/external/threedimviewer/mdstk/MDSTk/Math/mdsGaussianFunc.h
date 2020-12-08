//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/09/15                          \n
 *
 * $Id: mdsGaussianFunc.h 1865 2010-09-02 12:43:29Z spanel $
 *
 * Description:
 * - N-dimensional gaussian function (mixture model component).
 * - Diagonal covariance matrix.
 */

#ifndef MDS_GAUSSIANFUNC_H
#define MDS_GAUSSIANFUNC_H

#include "mdsBase.h"
#include "mdsStaticVector.h"
#include "mdsVectorFunctions.h"

// STL
#include <cmath>


namespace mds
{
namespace math
{

//==============================================================================
/*!
 * Global definitions.
 */

namespace GaussianFunc
{
    //! Default minimal allowed covariance.
    const double DEFAULT_MIN_COVARIANCE     = 0.001;
}


//==============================================================================
/*!
 * N-dimensional gaussian function having diagonal covariance matrix.
 * - Gaussian Mixture Model (GMM) component.
 */
template <typename T, int N>
class CGaussianFunc
{
public:
    //! The number of dimensions.
    enum { NUM_OF_DIMENSIONS = N };

    //! Type used for feature representation.
    typedef T tElement;

    //! Vector used to represent mean and diagonal covariance
    //! matrix of the gaussian function.
    typedef CStaticVector<T,N> tVector;

public:
    //! Default constructor.
    CGaussianFunc() {}

    //! Constructor.
    CGaussianFunc(double dWeight, const tVector& Mean, const tVector& Cov)
        : m_dWeight(dWeight)
        , m_Mean(Mean)
        , m_Cov(Cov)
        , m_bModified(true)
    {
        computeInverse();
    }

    //! Destructor.
    ~CGaussianFunc() {}

    //! Returns the number od dimensions.
    tSize getNumOfDimensions() const { return NUM_OF_DIMENSIONS; }

    //! Returns weight of the mixture component.
    double getWeight() const { return m_dWeight; }

    //! Sets weight of the component.
    void setWeight(double dWeight) { m_dWeight = dWeight; }


    //! Returns component mean.
    tVector& getMean() { return m_Mean; }
    const tVector& getMean() const { return m_Mean; }

    //! Returns component mean.
    T getMean(mds::tSize i) const { return m_Mean(i); }

    //! Sets mean of the gaussian function.
    void setMean(const tVector& Mean) { m_Mean = Mean; }

    //! Sets mean of the gaussian function.
    void setMean(mds::tSize i, T Value) { m_Mean(i) = Value; }


    //! Returns diagonal covariance matrix of the gaussian function.
    tVector& getCov() { return m_Cov; }
    const tVector& getCov() const { return m_Cov; }

    //! Sets diagonal covariance matrix of the gaussian function.
    void setCov(const tVector& Cov)
    {
        m_Cov = Cov;
        m_bModified = true;
    }

    //! Returns element of the diagonal covariance matrix.
    T getCov(mds::tSize i) const { return m_Cov(i); }

    //! Directly sets element of the diagonal covariance matrix.
    void setCov(mds::tSize i, T Value)
    {
        m_Cov(i) = Value;
        m_bModified = true;
    }

    //! Sets minimal allowed covariance value in the matrix.
    static void setMinCovariance(T Value)
    {
        m_MinCovariance = Value;
    }


    //! Normalizes the covariance matrix and computes its determinant
    //! and inverse.
    inline void computeInverse();

    //! Returns value of the gaussian function.
    inline double getValue(const tVector& x);

    //! Returns weighted value of the gaussian function.
    inline double getWeightedValue(const tVector& x)
    {
        return m_dWeight * getValue(x);
    }

protected:
    //! Minimal allowed covariance value.
    static T m_MinCovariance;

    //! Weight of the gaussian function.
    double m_dWeight;

    //! Mean value.
    tVector m_Mean;

    //! Diagonal covariance matrix and its inverse.
    tVector m_Cov, m_InvCov;

    //! Determinant of the covariance matrix.
    tVector m_CovDet;

    //! Helper flag;.
    bool m_bModified;
};


//=============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates.
#include "mdsGaussianFunc.hxx"


} // namespace math
} // namespace mds

#endif // MDS_GAUSSIANFUNC_H

