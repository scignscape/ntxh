//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2009 by Michal Spanel          \n
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/01/09                          \n
 *
 * $Id: mdsFeatureVector.h 2100 2012-02-17 07:36:55Z spanel $
 *
 * Description:
 * - Feature vector characterizing an image region.
 */

#ifndef MDS_FeatureVector_H
#define MDS_FeatureVector_H

#include <MDSTk/Math/mdsStaticVector.h>


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Global definitions.
 */

namespace FeatureVector
{
    //! Internal feature vector state.
    enum EState
    {
        UNKNOWN                 = 0,        //! An unknown state.
        VALID                   = 1 << 0,   //! Feature vector has been successfully evaluated.
        NOT_EVALUATED           = 1 << 1,   //! Feature vector is not yet evaluated.
        CANNOT_EVALUATE         = 1 << 2,   //! An error occurred during the evaluation.
        DEFAULT                 = UNKNOWN   //! The default state is unknown.
    };
}


//==============================================================================
/*!
 * Base class for all feature vectors encapsulating statistics extracted
 * from an image region.
 */
template <typename T, int Size>
class CFeatureVector : public mds::math::CStaticVector<T, Size>
{
public:
    //! Templates that require members of the CFeatureVector class may use
    //! this enum to check the existence.
    enum { CLASS_FEATURE_VECTOR };

    //! Base class.
    typedef mds::math::CStaticVector<T, Size> tBase;

    //! Feature vector.
    typedef mds::math::CStaticVector<T, Size> tVector;

    //! Type representing feature value.
    typedef typename tVector::tElement tFeature;

public:
    //! Default constructor.
    CFeatureVector(int State = FeatureVector::UNKNOWN) : m_State(State), m_NumOfSamples(0) {}

    //! Copy constructor.
    CFeatureVector(const CFeatureVector& Vector)
        : tBase(Vector)
        , m_State(Vector.m_State)
        , m_NumOfSamples(Vector.m_NumOfSamples)
    {}

    //! Destructor.
    ~CFeatureVector() {}

    //! Assignement operator.
    CFeatureVector& operator =(const CFeatureVector& Vector)
    {
        static_cast<tBase&>(*this) = static_cast<const tBase&>(Vector);
        m_State = Vector.m_State;
        m_NumOfSamples = Vector.m_NumOfSamples;

        return *this;
    }


    //! Returns the current internal state.
    int getState() const { return m_State; }

    //! Returns true if the feature vector is evaluated correctly.
    bool isValid() const { return (m_State == FeatureVector::VALID); }

    //! Sets the internal state.
    CFeatureVector& setState(int State)
    {
        m_State = State;
        return *this;
    }

    //! Checks the concrete state.
    bool checkState(int State) const { return (m_State & State) == State; }


    //! Returns size of the feature vector.
    tSize getNumOfFeatures() const { return tSize(Size); }

    //! Returns value of a subscripted feature.
    tFeature& getFeature(tSize i) { return this->get(i); }
    const tFeature& getFeature(tSize i) const { return this->get(i); }

    //! Sets value of the i-th feature.
    CFeatureVector& setFeature(tSize i, const tFeature& Value)
    {
        this->set(i, Value);
        return *this;
    }


    //! Returns the number of samples taken into account.
    int getNumOfSamples() const { return m_NumOfSamples; }

    //! Sets the number of samples.
    CFeatureVector& setNumOfSamples(int Value)
    {
        m_NumOfSamples = Value;
        return *this;
    }

    //! Inceases the number of sampels.
    CFeatureVector& incNumOfSamples(int Value)
    {
        m_NumOfSamples += Value;
        return *this;
    }

protected:
    //! Current internal state.
    int m_State;

    //! Total number of samples counted.
    int m_NumOfSamples;
};


} // namespace img
} // namespace mds

#endif // MDS_FeatureVector_H

