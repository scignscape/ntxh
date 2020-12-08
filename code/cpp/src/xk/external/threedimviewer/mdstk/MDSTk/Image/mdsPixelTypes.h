//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/18                          \n
 *
 * $Id: mdsPixelTypes.h 2092 2012-02-15 12:50:59Z spanel $
 *
 * Description:
 * - Basic pixel types definition.
 */

#ifndef MDS_PIXELTYPES_H
#define MDS_PIXELTYPES_H

#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Math/mdsBase.h>
#include <MDSTk/Math/mdsComplex.h>

#include "mdsImageExport.h"
#include "mdsRGBA.h"


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Forwards declarations.
 */

class CRGBPixel;


//==============================================================================
/*
 * Basic pixel types definition.
 */

//! Pixel used for grayscale 8-bit images.
typedef mds::sys::tUInt8            tPixel8;

//! Pixel used for grayscale 16-bit images.
typedef mds::sys::tUInt16           tPixel16;

//! Pixel used for grayscale 32-bit images.
typedef mds::sys::tUInt32           tPixel32;

//! Pixel used for float images.
typedef float                       tFloatPixel;

//! Density pixel used by medical images (slices).
typedef mds::sys::tInt16            tDensityPixel;

//! Complex pixel definition.
typedef mds::math::CComplex<float>  tComplexPixel;

//! RGB pixel of a color image.
typedef CRGBPixel                   tRGBPixel;


//==============================================================================
/*!
 * RGB pixel definition.
 */

class MDS_IMAGE_EXPORT CRGBPixel : public CRGBA
{
public:
    //! Default constructor.
    CRGBPixel() {}

    //! Constructor.
    //! - Separated RGB color components
    CRGBPixel(tComponent Red, tComponent Green, tComponent Blue)
        : CRGBA(Red, Green, Blue, 255)
    {}

    //! Constructor
    //! - RGB pixel.
    CRGBPixel(tRGBA Pixel) : CRGBA(Pixel) {}

    //! Copy constructor.
    CRGBPixel(const CRGBPixel& Pixel) : CRGBA(Pixel) {}

    //! Assignment operator.
    CRGBPixel& operator =(CRGBPixel Pixel)
    {
        m_rgba = Pixel.m_rgba;
        return *this;
    }

    //! Assignment operator.
    CRGBPixel& operator =(tRGBA Pixel)
    {
        m_rgba = Pixel;
        return *this;
    }


    //! Component wise addition.
    CRGBPixel& operator +=(const CRGBPixel& p)
    {
        r() += p.r();
        g() += p.g();
        b() += p.b();
        return *this;
    }

    //! Component wise subtraction.
    CRGBPixel& operator -=(const CRGBPixel& p)
    {
        r() -= p.r();
        g() -= p.g();
        b() -= p.b();
        return *this;
    }

    //! Component wise multiplication.
    CRGBPixel& operator *=(const CRGBPixel& p)
    {
        r() *= p.r();
        g() *= p.g();
        b() *= p.b();
        return *this;
    }

    //! Component wise division.
    CRGBPixel& operator /=(const CRGBPixel& p)
    {
        r() /= p.r();
        g() /= p.g();
        b() /= p.b();
        return *this;
    }

    //! Adds scalar to all components.
    CRGBPixel& operator +=(tComponent c)
    {
        r() += c;
        g() += c;
        b() += c;
        return *this;
    }

    //! Subtracts scalar from all components.
    CRGBPixel& operator -=(tComponent c)
    {
        r() -= c;
        g() -= c;
        b() -= c;
        return *this;
    }

    //! Mutliplies all components by scalar.
    CRGBPixel& operator *=(double Value)
    {
        r() = tComponent(r() * Value);
        g() = tComponent(g() * Value);
        b() = tComponent(b() * Value);
        return *this;
    }

    //! Divides all components by scalar.
    CRGBPixel& operator /=(double Value)
    {
        double dInv = 1.0 / Value;
        r() = tComponent(r() * dInv);
        g() = tComponent(g() / dInv);
        b() = tComponent(b() / dInv);
        return *this;
    }
};


//=============================================================================
/*
 * Arithmetic operations.
 */

inline CRGBPixel operator +(const CRGBPixel& l, const CRGBPixel& r)
{
    return CRGBPixel(l.r() + r.r(), l.g() + r.g(), l.b() + r.b());
}


inline CRGBPixel operator -(const CRGBPixel& l, const CRGBPixel& r)
{
    return CRGBPixel(l.r() - r.r(), l.g() - r.g(), l.b() - r.b());
}


inline CRGBPixel operator *(const CRGBPixel& l, double Scalar)
{
    return CRGBPixel(CRGBPixel::tComponent(l.r() * Scalar),
                     CRGBPixel::tComponent(l.g() * Scalar),
                     CRGBPixel::tComponent(l.b() * Scalar)
                     );
}


inline CRGBPixel operator *(double Scalar, const CRGBPixel& r)
{
    return CRGBPixel(CRGBPixel::tComponent(r.r() * Scalar),
                     CRGBPixel::tComponent(r.g() * Scalar),
                     CRGBPixel::tComponent(r.b() * Scalar)
                     );
}


inline CRGBPixel operator -(const CRGBPixel& x)
{
    return CRGBPixel(x.r(), x.g(), x.b());
}

} // namespace img


//=============================================================================
/*
 * Specialization of some math functions for special pixel types.
 */

namespace math
{

//! Specialization of the function that returns an absolute value.
template <>
inline mds::img::tRGBPixel getAbs(const mds::img::tRGBPixel& a);

//! Specialization of the function that returns minimum of two values.
template <>
inline mds::img::tRGBPixel getMin(const mds::img::tRGBPixel& a, const mds::img::tRGBPixel& b);

//! Specialization of the function that returns maximum of two values.
template <>
inline mds::img::tRGBPixel getMax(const mds::img::tRGBPixel& a, const mds::img::tRGBPixel& b);

//! Specialization of the function that limits value x into an interval <a, b>.
template <>
inline void limit(mds::img::tRGBPixel& x,
                  const mds::img::tRGBPixel& a,
                  const mds::img::tRGBPixel& b
                  );

//! Specialization of the function that remains values
//! in the range <a, b> unchanged, othervise
//! a new value n is assigned.
template <>
inline void cut(mds::img::tRGBPixel& x,
                const mds::img::tRGBPixel& a,
                const mds::img::tRGBPixel& b,
                const mds::img::tRGBPixel& n
                );

} // namespace math


//=============================================================================
/*
 * Specialization of some math functions for special pixel types.
 */

#include "mdsPixelTypes.hxx"


} // namespace mds

#endif // MDS_PIXELTYPES_H

