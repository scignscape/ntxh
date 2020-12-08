//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/09/02                          \n
 *
 * $Id: mdsLogNum.h 2096 2012-02-16 19:34:46Z spanel $
 *
 * Description:
 * - Operations with numbers in logarithmic space.
 */

#ifndef MDS_LOGNUM_H
#define MDS_LOGNUM_H

#include <MDSTk/Base/mdsException.h>
#include <MDSTk/Math/mdsBase.h>

#include "mdsMathTraits.h"

// STL
#include <cmath>
#include <iostream>


namespace mds
{
namespace math
{

//==============================================================================
/*
 * Global definitions.
 */

namespace LogNum
{

//! Enum used to initialize number in the logarithmic space.
enum ELogValue { LOG_VALUE };

//! Exception thrown on negative result.
MDS_DECLARE_EXCEPTION(CNegativeResult, "Subtraction has failed (negative result)")

}


//==============================================================================
/*!
 * Class representing a number in logarithmic space.
 * - T is type representing the number (most frequently float or double).
 */
template <typename T>
class CLogNum
{
public:
    //! Type of the number.
    typedef T tNumber;

public:
    //! Value stored in the logarithmic space.
    T value;

public:
    //! Default constructor.
    CLogNum() { value = CMathTraits<T>::getLogZero(); }

    //! Constructor.
    //! - Creates number in the logarithmic space.
    CLogNum(const T& v) { value = getSafeLog(v); }

    //! Constructor.
    //! - Initializes number in the logarithmic space.
    CLogNum(const T& v, LogNum::ELogValue) : value(v) {}

    //! Copy constructor.
    template <typename U>
    CLogNum(const CLogNum<U>& n) : value(n.value) {}

    //! Destructor.
    ~CLogNum() {}

    //! Assignment operator.
    template <typename U>
    CLogNum& operator =(const CLogNum<U>& n)
    {
        value = n.value;
        return *this;
    }

    //! Assignment operator.
    CLogNum& operator =(const T& v)
    {
        value = getSafeLog(v);
        return *this;
    }


    //! Returns current value in original space.
    T get() const { return getSafeExp(value); }

    //! Returns current value in logarithmic space.
    T get(LogNum::ELogValue) const { return value; }

    //! Sets the current value in original space.
    //! - Safe computation of the log(x) function.
    void set(const T& v) { value = getSafeLog(v); }

    //! Sets the current value in logarithmic space.
    void set(const T& v, LogNum::ELogValue) { value = getSafeLog(v); }


    //! Combined assignment operators.
    inline CLogNum& operator +=(const CLogNum& n);
    inline CLogNum& operator -=(const CLogNum& n);
    inline CLogNum& operator *=(const CLogNum& n);
    inline CLogNum& operator /=(const CLogNum& n);

    //! Others combined assignment operators.
    inline CLogNum& operator +=(const T& c);
    inline CLogNum& operator -=(const T& c);
    inline CLogNum& operator *=(const T& c);
    inline CLogNum& operator /=(const T& c);


    //! Safe computation of the log(x) function.
    inline static T getSafeLog(T x);

    //! Safe computation of the exp(x) function.
    inline static T getSafeExp(T x);

    //! Returns x + y in the logarithmic space.
    inline static T logAdd(T x, T y);

    //! Returns x - y in the logarithmic space.
    //! - Throws LogNum::CNegativeResult exception on failure.
    inline static T logSub(T x, T y);
};


//==============================================================================
/*
 * Implementation of the class CLogNum.
 */

template <typename T>
inline T CLogNum<T>::getSafeLog(T x)
{
    if( x == T(0) )
    {
        return CMathTraits<T>::getLogZero();
    }

    T Result = std::log(x);

    if( Result < CMathTraits<T>::getLogSmall() )
    {
        Result = CMathTraits<T>::getLogZero();
    }

    return Result;
}


template <typename T>
inline T CLogNum<T>::getSafeExp(T x)
{
    if( x <= CMathTraits<T>::getLogZero() )
    {
        return T(0);
    }
    else
    {
        return std::exp(x);
    }
}


template <typename T>
inline T CLogNum<T>::logAdd(T x, T y)
{
    if( x < y )
    {
        mds::math::swap(x, y);
    }

    T Diff = y - x;

    if( Diff < CMathTraits<T>::getMinLogExp() )
    {
        if( x < CMathTraits<T>::getLogSmall() )
        {
            return CMathTraits<T>::getLogZero();
        }
        else
        {
            return x;
        }
    }
    else
    {
        T Exp = std::exp(Diff);
        return x + std::log(1 + Exp);
    }
}


template <typename T>
inline T CLogNum<T>::logSub(T x, T y)
{
    if( x < y )
    {
        throw LogNum::CNegativeResult();
    }

    T Diff = y - x;

    if( Diff < CMathTraits<T>::getMinLogExp() )
    {
        if( x < CMathTraits<T>::getLogSmall() )
        {
            return CMathTraits<T>::getLogZero();
        }
        else
        {
            return x;
        }
    }
    else
    {
        T Exp = 1 - std::exp(Diff);
        if( Exp < CMathTraits<T>::getMinLogArg() )
        {
            return CMathTraits<T>::getLogZero();
        }
        else
        {
            return x + std::log(Exp);
        }
    }
}


//==============================================================================
/*
 * Combined assignment operators.
 */

template <typename T>
inline CLogNum<T>& CLogNum<T>::operator +=(const CLogNum<T>& n)
{
    value = logAdd(value, n.value);
    return *this;
}


template <typename T>
inline CLogNum<T>& CLogNum<T>::operator -=(const CLogNum<T>& n)
{
    value = logSub(value, n.value);
    return *this;
}


template <typename T>
inline CLogNum<T>& CLogNum<T>::operator *=(const CLogNum<T>& n)
{
    value += n.value;
    return *this;
}


template <typename T>
inline CLogNum<T>& CLogNum<T>::operator /=(const CLogNum<T>& n)
{
    value -= n.value;
    return *this;
}


template <typename T>
inline CLogNum<T>& CLogNum<T>::operator +=(const T& c)
{
    value = logAdd(value, getSafeLog(c));
    return *this;
}


template <typename T>
inline CLogNum<T>& CLogNum<T>::operator -=(const T& c)
{
    value = logSub(value, getSafeLog(c));
    return *this;
}


template <typename T>
inline CLogNum<T>& CLogNum<T>::operator *=(const T& c)
{
    value += getSafeLog(c);
    return *this;
}


template <typename T>
inline CLogNum<T>& CLogNum<T>::operator /=(const T& c)
{
    value -= getSafeLog(c);
    return *this;
}


//==============================================================================
/*
 * Others operators.
 */

template <typename T>
inline CLogNum<T> operator +(const CLogNum<T>& x, const CLogNum<T>& y)
{
    return CLogNum<T>(CLogNum<T>::logAdd(x.value, y.value), LogNum::LOG_VALUE);
}


template <typename T>
inline CLogNum<T> operator +(const CLogNum<T>& x, T y)
{
    return CLogNum<T>(CLogNum<T>::logAdd(x.value, CLogNum<T>::getSafeLog(y)), LogNum::LOG_VALUE);
}


template <typename T>
inline CLogNum<T> operator +(T x, const CLogNum<T>& y)
{
    return CLogNum<T>(CLogNum<T>::logAdd(CLogNum<T>::getSafeLog(x), y.value), LogNum::LOG_VALUE);
}


template <typename T>
inline CLogNum<T> operator -(const CLogNum<T>& x, const CLogNum<T>& y)
{
    return CLogNum<T>(CLogNum<T>::logSub(x.value, y.value), LogNum::LOG_VALUE);
}


template <typename T>
inline CLogNum<T> operator -(const CLogNum<T>& x, T y)
{
    return CLogNum<T>(CLogNum<T>::logSub(x.value, CLogNum<T>::getSafeLog(y)), LogNum::LOG_VALUE);
}


template <typename T>
inline CLogNum<T> operator -(T x, const CLogNum<T>& y)
{
    return CLogNum<T>(CLogNum<T>::logSub(CLogNum<T>::getSafeLog(x), y.value), LogNum::LOG_VALUE);
}


template <typename T>
inline CLogNum<T> operator *(const CLogNum<T>& x, const CLogNum<T>& y)
{
    return CLogNum<T>(x.value + y.value, LogNum::LOG_VALUE);
}


template <typename T>
inline CLogNum<T> operator *(const CLogNum<T>& x, T y)
{
    return CLogNum<T>(x.value + CLogNum<T>::getSafeLog(y), LogNum::LOG_VALUE);
}


template <typename T>
inline CLogNum<T> operator *(T x, const CLogNum<T>& y)
{
    return CLogNum<T>(CLogNum<T>::getSafeLog(x) + y.value, LogNum::LOG_VALUE);
}


template <typename T>
inline CLogNum<T> operator /(const CLogNum<T>& x, const CLogNum<T>& y)
{
    return CLogNum<T>(x.value - y.value, LogNum::LOG_VALUE);
}


template <typename T>
inline CLogNum<T> operator /(const CLogNum<T>& x, T y)
{
    return CLogNum<T>(x.value - CLogNum<T>::getSafeLog(y), LogNum::LOG_VALUE);
}


template <typename T>
inline CLogNum<T> operator /(T x, const CLogNum<T>& y)
{
    return CLogNum<T>(CLogNum<T>::getSafeLog(x) - y.value, LogNum::LOG_VALUE);
}


template <typename T>
inline bool operator ==(const CLogNum<T>& x, const CLogNum<T>& y)
{
    return x.value == y.value;
}


template <typename T>
inline bool operator ==(const CLogNum<T>& x, T y)
{
    return x.value == CLogNum<T>::getSafeLog(y);
}


template <typename T>
inline bool operator ==(T x, const CLogNum<T>& y)
{
    return CLogNum<T>::getSafeLog(x) == y.value;
}


template <typename T>
inline bool operator !=(const CLogNum<T>& x, const CLogNum<T>& y)
{
    return x.value != y.value;
}


template <typename T>
inline bool operator !=(const CLogNum<T>& x, T y)
{
    return x.value != CLogNum<T>::getSafeLog(y);
}


template <typename T>
inline bool operator != (T x, const CLogNum<T>& y)
{
    return CLogNum<T>::getSafeLog(x) != y.value;
}


template <typename T>
inline bool operator <(const CLogNum<T>& x, const CLogNum<T>& y)
{
    return x.value < y.value;
}


template <typename T>
inline bool operator <(const CLogNum<T>& x, T y)
{
    return x.value < CLogNum<T>::getSafeLog(y);
}


template <typename T>
inline bool operator <(T x, const CLogNum<T>& y)
{
    return CLogNum<T>::getSafeLog(x) < y.value;
}


template <typename T>
inline bool operator <=(const CLogNum<T>& x, const CLogNum<T>& y)
{
    return x.value <= y.value;
}


template <typename T>
inline bool operator <=(const CLogNum<T>& x, T y)
{
    return x.value <= CLogNum<T>::getSafeLog(y);
}


template <typename T>
inline bool operator <=(T x, const CLogNum<T>& y)
{
    return CLogNum<T>::getSafeLog(x) <= y.value;
}


template <typename T>
inline bool operator >(const CLogNum<T>& x, const CLogNum<T>& y)
{
    return x.value > y.value;
}


template <typename T>
inline bool operator >(const CLogNum<T>& x, T y)
{
    return x.value > CLogNum<T>::getSafeLog(y);
}


template <typename T>
inline bool operator >(T x, const CLogNum<T>& y)
{
    return CLogNum<T>::getSafeLog(x) > y.value;
}


template <typename T>
inline bool operator >=(const CLogNum<T>& x, const CLogNum<T>& y)
{
    return x.value >= y.value;
}


template <typename T>
inline bool operator >=(const CLogNum<T>& x, T y)
{
    return x.value >= CLogNum<T>::getSafeLog(y);
}


template <typename T>
inline bool operator >=(T x, const CLogNum<T>& y)
{
    return CLogNum<T>::getSafeLog(x) >= y.value;
}


//==============================================================================
/*
 * Global functions.
 */

//! Writes number in the logarithmic space to an output stream.
template <typename T>
inline std::ostream& operator <<(std::ostream& Stream, const CLogNum<T>& n)
{
    Stream << n.value;

    return Stream;
}


//! Reads number in the logarithmic space to an input stream.
template <typename T>
inline std::istream& operator >> (std::istream& Stream, CLogNum<T>& n)
{
    Stream >> n.value;

    return Stream;
}


//=============================================================================
/*
 * Basic template instances and type definitions.
 */

//! Float number in logarithmic space.
typedef CLogNum<float>     CFLogNum;

//! Double number in logarithmic space.
typedef CLogNum<double>    CDLogNum;


//! Float number in logarithmic space.
typedef CFLogNum           tFLogNum;

//! Double number in logarithmic space.
typedef CDLogNum           tDLogNum;


} // namespace math
} // namespace mds

#endif // MDS_LOGNUM_H

