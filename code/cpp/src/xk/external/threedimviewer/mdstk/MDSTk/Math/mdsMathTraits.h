//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/09/04                          \n
 *
 * $Id: mdsMathTraits.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Numerical traits used by math.
 */

#ifndef MDS_MATHTRAITS_H
#define MDS_MATHTRAITS_H

#include <MDSTk/Base/mdsTypeTraits.h>

// STL
#include <cmath>


namespace mds
{
namespace math
{

//==============================================================================
/*!
 * Numerical traits used by math (e.g. arithmetic in logarithmic space).
 */
template <typename T>
class CMathTraits : public mds::CTypeTraits<T>
{
public:
    //! Type representing the number in logarithmic space.
    typedef T tNumber;

public:
    //! Returns value representing log(0) in the logarithmic space.
    inline static T getLogZero();

    //! Returns number in the logarithmic space that is small enough
    //! so it is considered to be the log(0) value.
    inline static T getLogSmall();

    //! Lowest argument of the exp() function (= log(getMinLogArg())).
    inline static T getMinExpArg();

    //! Lowest argument of the log() function (= exp(getMinExpArg())).
    inline static T getMinLogArg();

    //! Returns minimal exponent of a number in logarithmic space.
    inline static T getMinLogExp()
    {
        static const T MinLogExp = -std::log(-getLogZero());

        return MinLogExp;
    }
};


//==============================================================================
/*
 * Implementation of the class CMathTraits.
 */

// Specialization of the function for the float type.
template <>
inline float CMathTraits<float>::getLogZero()
{
    return -1.0e5f;
}


// Specialization of the function for the double type.
template <>
inline double CMathTraits<double>::getLogZero()
{
    return -1.0e10;
}


// Specialization of the function for the float type.
template <>
inline float CMathTraits<float>::getLogSmall()
{
    return -0.5e5f;
}


// Specialization of the function for the double type.
template <>
inline double CMathTraits<double>::getLogSmall()
{
    return -0.5e10;
}


// Specialization of the function for the float type.
template <>
inline float CMathTraits<float>::getMinExpArg()
{
    return -86.0f;
}


// Specialization of the function for the double type.
template <>
inline double CMathTraits<double>::getMinExpArg()
{
    return -708.3;
}


// Specialization of the function for the float type.
template <>
inline float CMathTraits<float>::getMinLogArg()
{
    return 4.47e-38f;
}


// Specialization of the function for the double type.
template <>
inline double CMathTraits<double>::getMinLogArg()
{
    return 2.45e-308;
}


} // namespace math
} // namespace mds

#endif // MDS_MATHTRAITS_H

