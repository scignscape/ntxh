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
 * Copyright (c) 2003-2008 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/21                       
 *
 * Description:
 * - Functional objects applicable to image pixels.
 */

#ifndef VPL_ImageFunctional_H
#define VPL_ImageFunctional_H

#include <VPL/Base/Functional.h>

#include "PixelTraits.h"

// STL
#include <vector>


namespace vpl
{
namespace img
{

//=============================================================================
/*
 * Functional objects which may be applied to image pixels.
 */

//! Functor providing pixel value thresholding.
//! - Applying the functor results in a binary image containing zeros or ones.
template <typename T>
class CSingleThresholding
{
public:
    //! Default constructor.
    CSingleThresholding(const T& Value) : m_Threshold(Value) {}

	//! Operator multiplies a given parameter.
	void operator ()(T& Value)
	{
        Value = (Value >= m_Threshold) ? T(1) : T(0);
    }

protected:
    //! The applied threshold.
    T m_Threshold;
};


//! Functor providing pixel value thresholding.
//! - Applying the functor results in a binary image containing zeros or ones.
template <typename T>
class CMinMaxThresholding
{
public:
    //! Default constructor.
    CMinMaxThresholding(const T& Min, const T& Max)
        : m_Min(Min)
        , m_Max(Max)
    {}

    //! Operator multiplies a given parameter.
    void operator ()(T& Value)
    {
        Value = (Value >= m_Min && Value <= m_Max) ? T(1) : T(0);
    }

protected:
    //! Thresholded interval.
    T m_Min, m_Max;
};


//! Functor providing pixel value thresholding.
template <typename T>
class CMultiThresholding
{
public:
    //! Default constructor.
    CMultiThresholding() : m_bCheckPrevious(false) {}
    
    //! Operator multiplies a given parameter.
    void operator ()(T& Value)
    {
        if( m_bCheckPrevious && Value == m_Previous )
        {
            Value = m_NewValue;
            return;
        }
        
        m_Previous = Value;
        Value = vpl::img::CPixelTraits<T>::getZero();
        
        typename tThresholds::iterator it = m_Thresholds.begin();
        typename tThresholds::iterator itEnd = m_Thresholds.end();
        for( ; it != itEnd; ++it )
        {
            if( m_Previous >= *it )
            {
                Value += 1;
            }
        }
        
        m_NewValue = Value;
        m_bCheckPrevious = true;
    }
    
    //! Adds a new threshold.
    void add(const T& Value) { m_Thresholds.push_back(Value); }
    
    //! Returns the number of thresholds.
    tSize getSize() const { return tSize(m_Thresholds.size()); }
    
    //! Returns the i-th threshold.
    T& get(tSize i) { return m_Thresholds[i]; }
    const T& get(tSize i) const { return m_Thresholds[i]; }
    
    //! Sets the i-th threshold.
    void set(tSize i, const T& Value) { m_Thresholds[i] = Value; }
    
protected:
    //! Vector of thresholds.
    typedef std::vector<T> tThresholds;
    
    //! Applied thresholds.
    tThresholds m_Thresholds;
    
    //! Previously treated values.
    T m_Previous, m_NewValue;
    
    //! Internal flag meaning that previously treated values are valid.
    bool m_bCheckPrevious;
};


//! Functor compares two pixels and returns true if both pixels are equal.
template <typename T>
class CIsEqual
{
public:
    //! Default constructor.
    CIsEqual() {}

    //! Operator compares two pixels.
    bool operator ()(const T& a, const T& b)
    {
        return (a == b);
    }
};


//! Functor compares two pixels and checks if both pixels are almost equal.
//! - Returns true if the following equation holds |a - b| < Threshold
template <typename T>
class CCheckDiff
{
public:
    //! Default constructor.
    CCheckDiff(const T& Threshold) : m_Threshold(Threshold) {}

    //! Operator compares two pixels.
    bool operator ()(const T& a, const T& b)
    {
        T Diff = (a > b) ? a - b : b - a;
        return (Diff < m_Threshold);
    }
    
protected:
    //! The applied threshold.
    T m_Threshold;
};


} // namespace img
} // namespace vpl



#endif // VPL_ImageFunctional_H

