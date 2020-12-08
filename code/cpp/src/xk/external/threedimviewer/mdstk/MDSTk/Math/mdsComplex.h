//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/20                          \n
 *
 * $Id: mdsComplex.h 2049 2012-01-09 13:04:08Z spanel $
 *
 * Description:
 * - Complex number definition.
 */

#ifndef MDS_COMPLEX_H
#define MDS_COMPLEX_H

#include "mdsBase.h"

// STL
#include <cmath>
#include <complex>
#include <iostream>


namespace mds
{
namespace math
{

//==============================================================================
/*!
 * Class representing a complex number.
 * - T is type of the complex number real and imaginary part.
 * - TODO: Get round the VC7 implementation of the STL std::complex<> class
 *   which is not functional and fully compatible with some parts of the
 *   code in this class.
 */
template <typename T>
class CComplex
{
public:
    //! Type of the complex number component.
    typedef T tComponent;

public:
    //! Default constructor.
    CComplex() : m_re(0), m_im(0) {}

    //! Constructor.
    CComplex(tComponent r, tComponent i) : m_re(r), m_im(i) {}

    //! Constructor.
    //! - Creates complex number from a given real number.
    explicit CComplex(tComponent r) : m_re(r), m_im(0) {}

    //! Constructor.
    explicit CComplex(const std::complex<T>& z) : m_re(z.real()), m_im(z.imag()) {}

    //! Destructor.
    ~CComplex() {}

    //! Copy constructor.
    CComplex(const CComplex& z) : m_re(z.m_re), m_im(z.m_im) {}

    //! Assignment operator.
    CComplex& operator =(const CComplex& z)
    {
        m_re = z.re();
        m_im = z.im();
        return *this;
    }

    //! Assignment operator.
    CComplex& operator =(const std::complex<T>& z)
    {
        re = z.real();
        im = z.imag();
        return *this;
    }

    //! Assignment operator.
    CComplex& operator =(tComponent r)
    {       
        m_re = r;
        m_im = 0;
        return *this;
    }

    //! Conversion to the STL complex number.
    std::complex<T> conv2Std() const
    {
        return std::complex<T>(m_re, m_im);
    }


    //! Returns real part of the complex number.
    tComponent& getReal() { return m_re; }
    const tComponent& getReal() const { return m_re; }

    //! Returns real part of the complex number.
    tComponent& re() { return m_re; }
    const tComponent& re() const { return m_re; }

    //! Returns imaginary part of the complex number.
    tComponent& getImag() { return m_im; }
    const tComponent& getImag() const { return m_im; }

    //! Returns imaginary part of the complex number.
    tComponent& im() { return m_im; }
    const tComponent& im() const { return m_im; }

    //! Returns both the real and the imaginary part of the complex number.
    CComplex& get(tComponent& r, tComponent& i)
    {
        r = m_re;
        i = m_im;
        return *this;
    }
    const CComplex& get(tComponent& r, tComponent& i) const
    {
        r = m_re;
        i = m_im;
        return *this;
    }

    //! Sets real part of the complex number.
    CComplex& setReal(tComponent r)
    {
        m_re = r;
        return *this;
    }

    //! Sets imaginary part of the complex number.
    CComplex& setImag(tComponent i)
    {
        m_im = i;
        return *this;
    }

    //! Sets real and imaginary part of the complex number.
    CComplex& set(tComponent r, tComponent i)
    {
        m_re = r;
        m_im = i;
        return *this;
    }


    //! Combined assignment operators.
    inline CComplex& operator +=(const CComplex& z);
    inline CComplex& operator -=(const CComplex& z);
    inline CComplex& operator *=(const CComplex& z);
    inline CComplex& operator /=(const CComplex& z);
    
    //! Others combined assignment operators.
    inline CComplex& operator +=(const T& c);
    inline CComplex& operator -=(const T& c);
    inline CComplex& operator *=(const T& c);
    inline CComplex& operator /=(const T& c);


    //! Returns absolute value (magnitude) of the complex number.
    tComponent getMag() const
    {
        tComponent x = m_re;
        tComponent y = m_im;
        const tComponent s = getMax(getAbs(x), getAbs(y));
        if( s == 0 )
        {
            return s;
        }
        x /= s;
        y /= s;
        return s * std::sqrt(x * x + y * y);
    }

    //! Returns squared absolute value of the complex number.
    tComponent getNorm() const
    {
        return m_re * m_re + m_im * m_im;
    }

    //! Returns argument (angle) of the complex number.
    tComponent getArg() const
    {
        return T(std::atan2(m_im, m_re));
    }

    //! Returns complex conjugate number.
    CComplex getConj() const
    {
        return CComplex(m_re, -m_im);
    }

    //! Normalizes the complex number so that the absolute value
    //! is equal to one.
    CComplex& normalize()
    {
        tComponent Temp = getMag();
        if( Temp != 0 )
        {
            tComponent InvTemp = 1 / Temp;
            m_re *= InvTemp;
            m_im *= InvTemp;
        }
        return *this;
    }

protected:
    //! Real and imaginary part of the complex number.
    T m_re, m_im;
};


//==============================================================================
/*
 * Specialization of some basic math functions.
 */

//! Returns absolute value (magnitude) of the complex number.
template <typename T>
inline T getAbs(const CComplex<T>& z)
{
    return z.getMag();
}


//! Function returns minimum of two values.
template <typename T>
inline CComplex<T> getMin(const CComplex<T>& a, const CComplex<T>& b)
{
    return CComplex<T>(getMin<T>(a.re(), b.re()), getMin<T>(a.im(), b.im()));
}


//! Function returns maximum of two values.
template <typename T>
inline CComplex<T> getMax(const CComplex<T>& a, const CComplex<T>& b)
{
    return CComplex<T>(getMax<T>(a.re(), b.re()), getMax<T>(a.im(), b.im()));
}


//! Function limits value x into the interval <a, b>.
template <typename T>
inline void limit(CComplex<T>& x, const CComplex<T>& a, const CComplex<T>& b)
{
    limit<T>(x.re(), a.re(), b.re());
    limit<T>(x.im(), a.im(), b.im());
}


//! Function remains values in the range <a, b> unchanged, othervise
//! a new value n is assigned.
template <typename T>
inline void cut(CComplex<T>& x, const CComplex<T>& a, const CComplex<T>& b, const CComplex<T>& n)
{
    cut(x.re(), a.re(), b.re(), n.re());
    cut(x.im(), a.im(), b.im(), n.im());
}


//==============================================================================
/*
 * Combined assignment operators.
 */

template <typename T>
inline CComplex<T>& CComplex<T>::operator +=(const CComplex<T>& z)
{
    m_re += z.re();
    m_im += z.im();
    return *this;
}


template <typename T>
inline CComplex<T>& CComplex<T>::operator -=(const CComplex<T>& z)
{
    m_re -= z.re();
    m_im -= z.im();
    return *this;
}


template <typename T>
inline CComplex<T>& CComplex<T>::operator *=(const CComplex<T>& z)
{
    T Temp = m_re * z.re() - m_im * z.im();
    m_im = m_re * z.im() + m_im * z.re();
    m_re = Temp;
    return *this;
}


template <typename T>
inline CComplex<T>& CComplex<T>::operator /=(const CComplex<T>& z)
{
    T ar = getAbs<T>(z.re());
    T ai = getAbs<T>(z.im());
    T nr, ni;
    if (ar <= ai)
    {
        T t = z.re() / z.im();
        T d = z.im() * (t * t + 1L);
        nr = (m_re * t + m_im) / d;
        ni = (m_im * t - m_re) / d;
    }
    else
    {
        T t = z.im() / z.re();
        T d = z.re() * (t * t + 1L);
        nr = (m_re + m_im * t) / d;
        ni = (m_im - m_re * t) / d;
    }
    m_re = nr;
    m_im = ni;
    return *this;
}


template <typename T>
inline CComplex<T>& CComplex<T>::operator +=(const T& c)
{
    m_re += c;
    return *this;
}


template <typename T>
inline CComplex<T>& CComplex<T>::operator -=(const T& c)
{
    m_re -= c;
    return *this;
}


template <typename T>
inline CComplex<T>& CComplex<T>::operator *=(const T& c)
{
    m_re *= c;
    m_im *= c;
    return *this;
}


template <typename T>
inline CComplex<T>& CComplex<T>::operator /=(const T& c)
{
    m_re /= c;
    m_im /= c;
    return *this;
}


//==============================================================================
/*
 * Others operators.
 */

template <typename T>
inline CComplex<T> operator +(const CComplex<T>& x, const CComplex<T>& y)
{
    return CComplex<T>(x.re() + y.re(), x.im() + y.im());
}


template <typename T, typename U>
inline CComplex<T> operator +(const CComplex<T>& x, const U& y)
{
    return CComplex<T>(T(x.re() + y), x.im());
}


template <typename T, typename U>
inline CComplex<T> operator +(const U& x, const CComplex<T>& y)
{
    return CComplex<T>(T(x + y.re()), y.im());
}


template <typename T>
inline CComplex<T> operator -(const CComplex<T>& x, const CComplex<T>& y)
{
    return CComplex<T>(x.re() - y.re(), x.im() - y.im());
}


template <typename T, typename U>
inline CComplex<T> operator -(const CComplex<T>& x, const U& y)
{
    return CComplex<T>(T(x.re() - y), x.im());
}


template <typename T, typename U>
inline CComplex<T> operator -(const U& x, const CComplex<T>& y)
{
    return CComplex<T>(T(x - y.re()), - y.im());
}


template <typename T>
inline CComplex<T> operator *(const CComplex<T>& x, const CComplex<T>& y)
{
    return CComplex<T>(x.re() * y.re() - x.im() * y.im(), x.re() * y.im() + x.im() * y.re());
}


template <typename T, typename U>
inline CComplex<T> operator *(const CComplex<T>& x, const U& y)
{
    return CComplex<T>(T(x.re() * y), T(x.im() * y));
}


template <typename T, typename U>
inline CComplex<T> operator *(const U& x, const CComplex<T>& y)
{
    return CComplex<T>(T(x * y.re()), T(x * y.im()));
}


template <typename T>
inline CComplex<T> operator /(const CComplex<T>& x, const CComplex<T>& y)
{
    T ar = getAbs<T>(y.re());
    T ai = getAbs<T>(y.im());
    T nr, ni;
    T t, d;
    if( ar <= ai )
    {
        t = y.re() / y.im();
        d = y.im() * (t*t + 1L);
        nr = (x.re() * t + x.im()) / d;
        ni = (x.im() * t - x.re()) / d;
    }
    else
    {
        t = y.im() / y.re();
        d = y.re() * (t*t + 1L);
        nr = (x.re() + x.im() * t) / d;
        ni = (x.im() - x.re() * t) / d;
    }
    return CComplex<T>(nr, ni);
}


template <typename T>
inline CComplex<T> operator /(const T& x, const CComplex<T>& y)
{
    T ar = getAbs<T>(y.re());
    T ai = getAbs<T>(y.im());
    T nr, ni;
    T t, d;
    if( ar <= ai )
    {
        t = y.re() / y.im();
        d = y.im() * (1 + t*t);
        nr = x * t / d;
        ni = -x / d;
    }
    else
    {
        t = y.im() / y.re();
        d = y.re() * (1 + t*t);
        nr = x / d;
        ni = -x * t / d;
    }
    return CComplex<T>(nr, ni);
}


template <typename T>
inline CComplex<T> operator /(const CComplex<T>& x, const T& y)
{
    return CComplex<T>(x.re() / y, x.im() / y);
}


template <typename T>
inline CComplex<T> operator +(const CComplex<T>& x)
{
    return x;
}


template <typename T>
inline CComplex<T> operator -(const CComplex<T>& x)
{
    return CComplex<T>(-x.re(), -x.im());
}


template <typename T>
inline bool operator ==(const CComplex<T>& x, const CComplex<T>& y)
{
    return x.re() == y.re() && x.im() == y.im();
}


template <typename T>
inline bool operator ==(const CComplex<T>& x, const T& y)
{
    return x.re() == y && x.im() == 0;
}


template <typename T>
inline bool operator ==(const T& x, const CComplex<T>& y)
{
    return x == y.re() && y.im() == 0;
}


template <typename T>
inline bool operator !=(const CComplex<T>& x, const CComplex<T>& y)
{
    return x.re() != y.re() || x.im() != y.im();
}


template <typename T>
inline bool operator !=(const CComplex<T>& x, const T& y)
{
    return x.re() != y || x.im() != 0;
}


template <typename T>
inline bool operator != (const T& x, const CComplex<T>& y)
{
    return x != y.re() || y.im() != 0;
}


//==============================================================================
/*
 * Global functions.
 */

//! Returns real part of a complex number.
template <typename T>
inline T getReal(const CComplex<T>& z)
{
    return z.re();
}


//! Returns m_imaginary part of a complex number.
template <typename T>
inline T getImag(const CComplex<T>& z)
{
    return z.im();
}


//! Creates a temporary complex number from polar coordinates.
//! - Angle is equal to zero.
template <typename T>
inline CComplex<T> polar(const T& x)
{
    return CComplex<T>(x, 0);
}


//! Creates a temporary complex number from polar coordinates.
template <typename T>
inline CComplex<T> polar(const T& x, const T& y)
{
    return CComplex<T>(x * cos(y), x * sin(y));
}


//! Returns squared absolute value of the complex number.
template <typename T>
inline T getNorm(const CComplex<T>& z)
{
    return z.getNorm();
}


//! Returns argument (phase) of the complex number.
template <typename T>
inline T getArg(const CComplex<T>& z)
{
    return z.getArg();
}


//! Returns complex conjugate number.
template <typename T>
inline CComplex<T> getConj(const CComplex<T>& z)
{
    return z.getConj();
}


//! Returns square root of the complex number.
template <typename T>
inline CComplex<T> getSqrt(const CComplex<T>& z)
{
    std::complex<T> s = std::sqrt(std::complex<T>(z.re(), z.im()));
    
    return CComplex<T>(s.real(), s.imag());
}


//! Returns exponential of the complex number.
template <typename T>
inline CComplex<T> getExp(const CComplex<T>& z)
{
    return polar(T(exp(z.re())), z.im());
}


//! Returns natural logarithm with base e of the complex number.
template <typename T>
inline CComplex<T> getLog(const CComplex<T>& z)
{
    std::complex<T> s = std::log(std::complex<T>(z.re(), z.im()));
    
    return CComplex<T>(s.real(), s.imag());
}
 
 
//! Returns logarithm with base 10 of the complex number.
template <typename T>
inline CComplex<T> getLog10(const CComplex<T>& z)
{
    std::complex<T> s = std::log10(std::complex<T>(z.re(), z.im()));
    
    return CComplex<T>(s.real(), s.imag());
}
 
 
//! Returns complex power.
template <typename T>
inline CComplex<T> getPow(const CComplex<T>& x, const CComplex<T>& y)
{
    std::complex<T> s = std::pow(std::complex<T>(x), std::complex<T>(y));
    
    return CComplex<T>(s.real(), s.imag());
}
 
 
//! Returns complex power.
template <typename T>
inline CComplex<T> getPow(const CComplex<T>& x, const T& y)
{
    std::complex<T> s = std::pow(std::complex<T>(x), y);
    
    return CComplex<T>(s.real(), s.imag());
}
 
 
//! Returns complex power.
template <typename T>
inline CComplex<T> getPow(const T& x, const CComplex<T>& y)
{
    std::complex<T> s = std::pow(x, std::complex<T>(y));
    
    return CComplex<T>(s.real(), s.imag());
}
 
 
//! Returns complex power of a complex number.
template <typename T>
inline CComplex<T> getPow(const CComplex<T>& x, int y)
{
    std::complex<T> s = std::pow(std::complex<T>(x), y);
    
    return CComplex<T>(s.real(), s.imag());
}


//! Returns cosine of the complex number.
template <typename T>
inline CComplex<T> getCos(const CComplex<T>& z)
{
    return CComplex<T>(cos(z.re()) * cosh(z.im()), -sin(z.re()) * sinh(z.im()));
}


//! Returns hyperbolic cosine of the complex number.
template <typename T>
inline CComplex<T> getCosh(const CComplex<T>& z)
{
    return CComplex<T>(cosh(z.re()) * cos(z.im()), sinh(z.re()) * sin(z.im()));
}


//! Returns sine of a complex number.
template <typename T>
inline CComplex<T> getSin(const CComplex<T>& z)
{
    return CComplex<T>(sin(z.re()) * cosh(z.im()), cos(z.re()) * sinh(z.im()));
}


//! Returns hyperbolic sine of a complex number.
template <typename T>
inline CComplex<T> getSinh(const CComplex<T>& z)
{
    return CComplex<T>(sinh(z.re()) * cos(z.im()), cosh(z.re()) * sin(z.im()));
}


//! Returns tangent of a complex number.
template <typename T>
inline CComplex<T> getTan(const CComplex<T>& z)
{
    std::complex<T> s = std::tan(std::complex<T>(z.re(), z.im()));
    
    return CComplex<T>(s.real(), s.imag());
}
 
 
//! Returns hyperbolic tangent of a complex number.
template <typename T> 
inline CComplex<T> getTanh(const CComplex<T>& z)
{
    std::complex<T> s = std::tanh(std::complex<T>(z.re(), z.im()));
    
    return CComplex<T>(s.real(), s.imag());
}


//! Writes complex number to an output stm_ream.
template <typename T>
inline std::ostream& operator <<(std::ostream& Stream, const CComplex<T>& z)
{
    Stream << std::complex<T>(z.re(), z.im());

    return Stream;
}


//! Reads complex number from an input stream.
template <typename T>
inline std::istream& operator >> (std::istream& Stream, CComplex<T>& z)
{
    std::complex<T> sz;
    Stream >> sz;
    z.re() = sz.real();
    z.im() = sz.imag();

    return Stream;
}


//=============================================================================
/*
 * Basic type definitions.
 */

//! Float complex number.
typedef CComplex<float>     CFComplex;

//! Double complex number.
typedef CComplex<double>    CDComplex;

//! Float complex number.
typedef CFComplex           tFComplex;

//! Double complex number.
typedef CDComplex           tDComplex;


} // namespace math
} // namespace mds

#endif // MDS_COMPLEX_H

