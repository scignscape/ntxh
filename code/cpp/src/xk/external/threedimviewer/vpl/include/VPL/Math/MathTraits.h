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
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/09/04                          \n
 *
 * Description:
 * - Numerical traits used by math.
 */

#ifndef VPL_MATHTRAITS_H
#define VPL_MATHTRAITS_H

#include <VPL/Base/TypeTraits.h>

// STL
#include <cmath>


namespace vpl
{
namespace math
{

//==============================================================================
/*!
 * Numerical traits used by math (e.g. arithmetic in logarithmic space).
 */
template <typename T>
class CMathTraits : public vpl::CTypeTraits<T>
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
} // namespace vpl

#endif // VPL_MATHTRAITS_H

