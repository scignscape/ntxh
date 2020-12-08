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
 * Authors: Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/10                       
 *
 * Description:
 * - Feature vectors distance measure.
 */

#ifndef VPL_DistanceMeasure_H
#define VPL_DistanceMeasure_H

#include "FeatureVector.h"

// STL
#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Base class for all distance measures.
 * - Parameter V specifies concrete feature vector.
 */
template <class V>
struct CDistanceMeasure
{
    //! Check that V is a feature vector type. You will see name of this enum
    //! somewhere in compiler error message if the type V can't be used.
    enum { FEATURE_VECTOR_MUST_BE_GIVEN = V::CLASS_FEATURE_VECTOR };

    //! Feature vector type.
    typedef V tFeatureVector;

    //! Calculates distance between two given feature vectors.
//    static double calculate(const tFeatureVector& v1, const tFeatureVector& v2);
};


//==============================================================================
/*!
 * The Chi-Square distance measure.
 */
template <class V>
class CChiSquare : public CDistanceMeasure<V>
{
public:
    // Base types
    typedef CDistanceMeasure<V> tBase;
    typedef typename tBase::tFeatureVector tFeatureVector;

public:
    //! Calculates similarity between two given feature vectors.
    static double calculate(const tFeatureVector& v1, const tFeatureVector& v2)
    {
        double Sum = 0.0;
        for( int i = 0; i < v1.getSize(); ++i )
        {
            double a = double(v1(i));
            double b = double(v2(i));
            double t = a - b;
            Sum += (t * t) / (a + b + 0.000001);
        }
        return Sum;
    }
};


//==============================================================================
/*!
 * The G-Statistics distance measure.
 */
template <typename R, class V>
class CGStat : public CDistanceMeasure<V>
{
public:
    // Base types
    typedef CDistanceMeasure<V> tBase;
    typedef typename tBase::tFeatureVector tFeatureVector;

public:
    //! Calculates distance between two given feature vectors.
    //! - Features must be normalized into the range <0,1>!
    static double calculate(const tFeatureVector& v1, const tFeatureVector& v2)
    {
        double Sum = 0.0;
        for( int i = 0; i < v1.getSize(); ++i )
        {
            double s = double(v2(i));
            double m = double(v1(i));
            if( m > 0.0 )
            {
                Sum += s * std::log10(m);
            }
        }
        return -Sum;
    }
};


//==============================================================================
/*!
 * The union distance measure.
 */
template <typename R, class V>
class CUnion : public CDistanceMeasure<V>
{
public:
    // Base types
    typedef CDistanceMeasure<V> tBase;
    typedef typename tBase::tFeatureVector tFeatureVector;

public:
    //! Calculates distance between two given feature vectors.
    //! - Features must be greater then zero!
    static double calculate(const tFeatureVector& v1, const tFeatureVector& v2)
    {
        double Sum = 0.0;
        for( int i = 0; i < v1.getSize(); ++i )
        {
            Sum += double(vpl::math::getMin(v1(i), v2(i)));
        }
        return Sum;
    }
};


} // namespace img
} // namespace vpl

#endif // VPL_DistanceMeasure_H

