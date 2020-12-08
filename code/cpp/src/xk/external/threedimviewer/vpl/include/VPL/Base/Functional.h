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
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/08                          \n
 *
 * Description:
 * - Basic functional objects.
 */

#ifndef VPL_Functional_H
#define VPL_Functional_H

#include <VPL/Math/Base.h>
#include <VPL/Math/Complex.h>

#include "IteratorBase.h"


namespace vpl
{
namespace base
{

//==============================================================================
/*
 * Global functions.
 */

//! Applies a given function object to all items (STL-like version).
template <typename Iterator, typename Function>
Function forEach(Iterator First, Iterator Last, Function Func)
{
    for( ; First != Last; ++First )
    {
        Func(*First);
    }
    return Func;
}


//! Applies a given function object to all items.
template <typename Derived, typename Function>
Function forEach(CIteratorBase<Derived> It, Function Func)
{
    for( ; It; ++It )
    {
        Func(*It);
    }
    return Func;
}


//==============================================================================
/*
 * Elementary functional objects.
 */

//! Functor makes an absolute value.
template <typename T>
class CAbs
{
public:
    //! Default constructor.
    CAbs() {}

    //! Makes absolute value of a parameter.
    void operator ()(T& Value)
    {
        Value = vpl::math::getAbs(Value);
    }
};


//! Functor adds a given value.
template <typename T>
class CAdd
{
public:
    //! Default constructor.
    CAdd(const T& Value) : m_Value(Value) {}

	//! Operator adds predefined value to a given parameter.
    void operator ()(T& Value)
    {
        Value += m_Value;
    }

protected:
    //! Added value.
    T m_Value;
};


//! Functor subtracts a given value.
template <typename T>
class CSub
{
public:
    //! Default constructor.
    CSub(const T& Value) : m_Value(Value) {}

	//! Operator subtracts a value from a given parameter.
    void operator ()(T& Value)
    {
        Value -= m_Value;
    }

protected:
    //! Decrement.
    T m_Value;
};


//! Functor multiplies by a given value.
template <typename T1, typename T2 = T1>
class CMult
{
public:
    //! Default constructor.
    CMult(const T2& Value) : m_Value(Value) {}

	//! Operator multiplies a given parameter.
    void operator ()(T1& Value)
    {
        Value = T1(Value * m_Value);
    }

protected:
    //! The value to multiply by.
    T2 m_Value;
};


//! Functor divides by a given value.
template <typename T1, typename T2 = T1>
class CDiv
{
public:
    //! Default constructor.
    CDiv(const T2& Value) : m_Value(Value) {}

	//! Operator divides a given parameter.
    void operator ()(T1& Value)
    {
        Value = T1(Value / m_Value);
    }

protected:
    //! The value to divide by.
    T2 m_Value;
};


//! Functor changes observed value.
template <typename T>
class CFill
{
public:
    //! Default constructor.
    CFill(const T& Value) : m_Value(Value) {}

	//! Operator changes value of a given parameter.
    void operator ()(T& Value)
    {
        Value = m_Value;
    }

protected:
    //! The value to set.
    T m_Value;
};


//! Functor changes value of an observed variable.
template <typename T>
class CReplace
{
public:
    //! Default constructor.
    CReplace(const T& Value, const T& NewValue) : m_Value(Value), m_NewValue(NewValue) {}

    //! Checks and eventually replaces value of a given parameter.
    void operator ()(T& Value)
    {
        if( Value == m_Value )
        {
            Value = m_NewValue;
        }
    }

protected:
    //! Original and the new value.
    T m_Value, m_NewValue;
};


//! Functor limits an observed value to a specified range.
template <typename T>
class CLimit
{
public:
    //! Default constructor.
    CLimit(const T& Min, const T& Max) : m_Min(Min), m_Max(Max) {}

    //! Limits value of a given parameter.
    void operator ()(T& Value)
    {
        vpl::math::limit(Value, m_Min, m_Max);
    }

protected:
    //! Original and new value.
    T m_Min, m_Max;
};


//! Functor remains unchanged a specified interval of values. All other
//! values are cleared.
template <typename T>
class CCut
{
public:
    //! Default constructor.
    CCut(const T& Min, const T& Max, const T& NewValue = T())
        : m_Min(Min)
        , m_Max(Max)
        , m_NewValue(NewValue)
    {}

    //! Function cuts out a predefined range of values.
    void operator ()(T& Value)
    {
        vpl::math::cut(Value, m_Min, m_Max, m_NewValue);
    }

protected:
    //! Range and new value.
    T m_Min, m_Max, m_NewValue;
};


//==============================================================================
/*
 * Templates of functional objects having some internal state and returning
 * some final value.
 */

//! Functional object which can be used to find maximal value.
template <typename T>
class CMax
{
public:
    //! Default constructor.
    CMax(const T& Value = T()) : m_Max(Value) {}

    //! Operator compares a given value to the actual maximum.
    void operator ()(const T& Value)
    {
        m_Max = vpl::math::getMax(Value, m_Max);
    }
	
	//! Returns the maximum.
	T& getValue() { return m_Max; }

protected:
    //! Current maximal value.
    T m_Max;
};


//! Functional object which can be used to find minimal value.
template <typename T>
class CMin
{
public:
    //! Default constructor.
    CMin(const T& Value = T()) : m_Min(Value) {}

    //! Operator compares a given value to the actual minimum.
    void operator ()(const T& Value)
    {
        m_Min = vpl::math::getMin(Value, m_Min);
    }

	//! Returns the actual minimum.
	T& getValue() { return m_Min; }

protected:
    //! Actual minimal value.
    T m_Min;
};


//==============================================================================
/*
 * Templates of functional objects having some internal state and returning
 * value of a different type.
 */

//! The functional object can be used to estimate mean value of a sequence
//! of numbers.
template <typename R, typename T>
class CMeanValue
{
public:
    //! Default constructor.
    CMeanValue() : m_Sum(), m_NumOfValues(0) {}
    
    //! Operator compares a given value to the actual minimum.
    void operator ()(const T& Value)
    {
        m_Sum += R(Value);
        ++m_NumOfValues;
    }

    //! Returns the actual minimum.
    R& getValue()
    {
        if( m_NumOfValues > 0 )
        {
            m_Sum /= R(m_NumOfValues);
        }
        return m_Sum;
    }

protected:
    //! Sum of all values.
    R m_Sum;
    
    //! Total number of values.
    long m_NumOfValues;
};


//! The functional object estimates variance of a sequence of numbers.
template <typename R, typename T>
class CVariance
{
public:
    //! Default constructor.
    CVariance() : m_Sum(), m_SumSqr(), m_NumOfValues(0) {}

    //! Functional operator.
    void operator ()(const T& Value)
    {
        m_Sum += R(Value);
        m_SumSqr += R(Value) * R(Value);
        ++m_NumOfValues;
    }
    
    //! Returns the actual minimum.
    R getValue()
    {
        if( m_NumOfValues > 0 )
        {
            R Temp = R(1) / R(m_NumOfValues);
            return m_SumSqr * Temp - (m_Sum * Temp * m_Sum * Temp);
        }
        else
        {
            return R();
        }
    }

protected:
    //! Sum of all values.
    R m_Sum, m_SumSqr;

    //! Total number of values.
    long m_NumOfValues;
};


//! The functional object can be used to estimate sum of a sequence of numbers.
template <typename R, typename T>
class CSum
{
public:
    //! Default constructor.
    CSum() : m_Sum() {}

	//! Functional operator.
	void operator ()(const T& Value) { m_Sum += R(Value); }

	//! Returns the actual minimum.
	R& getValue() { return m_Sum; }

protected:
    //! Sum of all values.
    R m_Sum;
};


//! Estimates sum of squares of a sequence of numbers.
template <typename R, typename T>
class CSumOfSquares
{
public:
    //! Default constructor.
    CSumOfSquares() : m_Sum() {}

	//! Functional operator.
	void operator ()(const T& Value) { m_Sum += R(Value) * R(Value); }

	//! Returns the actual minimum.
	R& getValue() { return m_Sum; }

protected:
    //! Sum of all values.
    R m_Sum;
};


//! The functional object can be used to estimate multiplication of a sequence of numbers.
template <typename R, typename T>
class CCumulativeMult
{
public:
    //! Default constructor.
    CCumulativeMult() : m_Result() {}

    //! Functional operator.
    void operator ()(const T& Value) { m_Result *= R(Value); }

    //! Returns the actual minimum.
    R& getValue() { return m_Result; }

protected:
    //! Multiplication of all values.
    R m_Result;
};


} // namespace base
} // namespace vpl

#endif // VPL_Functional_H

