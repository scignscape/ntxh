//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/16                          \n
 *
 * $Id: mdsBase.h 2065 2012-02-02 23:29:38Z spanel $
 *
 * Description:
 * - Definition of various useful constants, functions and macros.
 */

#ifndef MDS_MathBase_H
#define MDS_MathBase_H

#include <MDSTk/Base/mdsTypeTraits.h>
#include <MDSTk/Base/mdsStaticAssert.h>


namespace mds
{
namespace math
{

//=============================================================================
/*
 * Definitions of various constants.
 */

//! Euler's constant.
const double E              = 2.718281828459045;

//! Constant pi.
const double PI             = 3.141592653589793;

//! Constant 2*pi.
const double TWO_PI         = 2.0 * PI;

//! Constant pi/2.
const double HALF_PI        = 0.5 * PI;

//! Constant sqrt(2*pi).
const double SQRT_TWO_PI    = 2.506628274631001;

//! Square root of the number 2.
const double SQRT2          = 1.414213562373095;

//! Square root of the number 3.
const double SQRT3          = 1.732050807568877;

//! Square root of the number 6.
const double SQRT6          = 2.449489742783178;


//=============================================================================
/*
 * Several useful template functions.
 */

//! Returns the Euler's constant.
template <typename T>
inline const T& getE()
{
    static const T Value = T(E);
    return Value;
}


//! Returns the constant pi.
template <typename T>
inline const T& getPi()
{
    static const T Value = T(PI);
    return Value;
}


//! Returns the value 2*pi.
template <typename T>
inline const T& get2Pi()
{
    static const T Value = T(TWO_PI);
    return Value;
}


//! Returns the value pi/2.
template <typename T>
inline const T& getHalfPi()
{
    static const T Value = T(HALF_PI);
    return Value;
}


//! Returns the value sqrt(2*pi).
template <typename T>
inline const T& getSqrt2Pi()
{
    static const T Value = T(SQRT_TWO_PI);
    return Value;
}


//! Returns square root of the number 2.
template <typename T>
inline const T& getSqrt2()
{
    return T(SQRT2);
}


//! Returns square root of the number 3.
template <typename T>
inline const T& getSqrt3()
{
    return T(SQRT3);
}


//! Returns square root of the number 6.
template <typename T>
inline const T& getSqrt6()
{
    return T(SQRT6);
}


//=============================================================================
/*
 * Several useful template functions.
 */

//! Returns maximum of two values.
template <typename T>
inline T getMax(const T& a, const T& b)
{
    return ((a > b) ? a : b);
}


//! Returns maximum of three values.
template <typename T>
inline T getMax(const T& a, const T& b, const T& c)
{
    return getMax(getMax(a, b), c);
}


//! Returns maximum of four values.
template <typename T>
inline T getMax(const T& a, const T& b, const T& c, const T& d)
{
    return getMax(getMax(getMax(a, b), c), d);
}


//! Returns minimum of two values.
template <typename T>
inline T getMin(const T& a, const T& b)
{
    return ((a < b) ? a : b);
}


//! Returns minimum of three values.
template <typename T>
inline T getMin(const T& a, const T& b, const T& c)
{
    return getMin(getMin(a, b), c);
}


//! Returns minimum of four values.
template <typename T>
inline T getMin(const T& a, const T& b, const T& c, const T& d)
{
    return getMin(getMin(getMin(a, b), c), d);
}


//! Absolute value.
template <typename T>
inline T getAbs(const T& a)
{
    return ((a > 0) ? a : -a);
}


//! Specialization of the function that returns an absolute value.
template <>
inline unsigned int getAbs(const unsigned int& a)
{
    return a;
}


//! Specialization of the function that returns an absolute value.
template <>
inline unsigned short getAbs(const unsigned short& a)
{
    return a;
}


//! Specialization of the function that returns an absolute value.
template <>
inline unsigned long getAbs(const unsigned long& a)
{
    return a;
}


//! Exchanges two values.
template <typename T>
inline void swap(T& a, T& b)
{
    T Temp = a;
    a = b;
    b = Temp;
}

//! Exchanges two int numbers.
template <>
inline void swap(int& a, int& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

//! Exchanges two unsigned int numbers.
template <>
inline void swap(unsigned& a, unsigned& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}


//! Exchanges two long numbers.
template <>
inline void swap(long& a, long& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}


//! Exchanges two unsigned long numbers.
template <>
inline void swap(unsigned long& a, unsigned long& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}


//! Rounds a given floating point number to integer.
template <typename T>
inline int round2Int(const T& x)
{
    MDS_STATIC_ASSERT(CTypeTraits<T>::isFloat, Bad_template_parameter_type);

    static const T Half = 0.5f;

    return int(x + Half);
}


//! Conversion of a given number to bool.
template <typename T>
inline bool conv2Bool(const T& x)
{
    static const T Zero = 0;

    return ((x == Zero) ? false : true);
}


//! Converts degrees to radians.
inline double deg2Rad(double Degrees)
{
    static const double dNorm = PI / 180.0;

    return (Degrees * dNorm);
}


//! Converts degrees to radians.
inline double rad2deg(double Radians)
{
    static const double dNorm = 180.0 / PI;

    return (Radians * dNorm);
}


//! Value x is mirrored into a given interval <a, b>.
template <typename T>
inline void mirror(T& x, const T& a, const T& b)
{
    while( (x < a) || (x > b) )
    {
        if( x < a )
        {
            x = 2 * a - x;
        }
        if( x > b )
        {
            x = 2 * b - x;
        }
    }
}


//! Value x is limited into an interval <a, b>.
template <typename T>
inline void limit(T& x, const T& a, const T& b)
{
    if( x < a )
    {
        x = a;
    }
    else if( x > b )
    {
        x = b;
    }
}


//! Values in the range <a, b> remain unchanged, othervise
//! a new value n is assigned.
template <typename T>
inline void cut(T& x, const T& a, const T& b, const T& n)
{
    if( x < a || x > b )
    {
        x = n;
    }
}


//! Returns true if a given integer number is odd.
template <typename T>
inline bool isOdd(const T& x)
{
    MDS_STATIC_ASSERT(CTypeTraits<T>::isIntegral, Bad_template_parameter_type);

    return (x & 1) == 1;
}


//! Returns true if a given integer number is even.
template <typename T>
inline bool isEven(const T& x)
{
    MDS_STATIC_ASSERT(CTypeTraits<T>::isIntegral, Bad_template_parameter_type);

    return (x & 1) == 0;
}


} // namespace math
} // namespace mds

#endif // MDS_MathBase_H

