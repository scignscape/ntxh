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
 * Copyright (c) 2003-2010 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/18                       
 *
 * Description:
 * - Basic pixel types definition.
 */

#ifndef VPL_PIXELTYPES_H
#define VPL_PIXELTYPES_H

#include <VPL/Base/Types.h>
#include <VPL/Math/Base.h>
#include <VPL/Math/Complex.h>

#include "ImageExport.h"
#include "RGBA.h"


namespace vpl
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
typedef vpl::sys::tUInt8            tPixel8;

//! Pixel used for grayscale 16-bit images.
typedef vpl::sys::tUInt16           tPixel16;

//! Pixel used for grayscale 32-bit images.
typedef vpl::sys::tUInt32           tPixel32;

//! Pixel used for float images.
typedef float                       tFloatPixel;

//! Density pixel used by medical images (slices).
typedef vpl::sys::tInt16            tDensityPixel;

//! Complex pixel definition.
typedef vpl::math::CComplex<float>  tComplexPixel;

//! RGB pixel of a color image.
typedef CRGBPixel                   tRGBPixel;

//! RGBA pixel of a color image.
typedef CRGBPixel                   tRGBAPixel;


//==============================================================================
/*!
 * RGB pixel definition.
 */

class VPL_IMAGE_EXPORT CRGBPixel : public CRGBA
{
public:
    //! Default constructor.
    CRGBPixel() {}

    //! Constructor from separated RGB color components
    CRGBPixel(tComponent Red, tComponent Green, tComponent Blue, tComponent Alpha = 255)
        : CRGBA(Red, Green, Blue, Alpha)
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
    //! - Does not modify the alpha component!
    CRGBPixel& operator +=(const CRGBPixel& p)
    {
        r() += p.r();
        g() += p.g();
        b() += p.b();
        return *this;
    }

    //! Component wise subtraction.
    //! - Does not modify the alpha component!
    CRGBPixel& operator -=(const CRGBPixel& p)
    {
        r() -= p.r();
        g() -= p.g();
        b() -= p.b();
        return *this;
    }

    //! Component wise multiplication.
    //! - Does not modify the alpha component!
    CRGBPixel& operator *=(const CRGBPixel& p)
    {
        r() *= p.r();
        g() *= p.g();
        b() *= p.b();
        return *this;
    }

    //! Component wise division.
    //! - Does not modify the alpha component!
    CRGBPixel& operator /=(const CRGBPixel& p)
    {
        r() /= p.r();
        g() /= p.g();
        b() /= p.b();
        return *this;
    }

    //! Adds scalar to all components.
    //! - Does not modify the alpha component!
    CRGBPixel& operator +=(tComponent c)
    {
        r() += c;
        g() += c;
        b() += c;
        return *this;
    }

    //! Subtracts scalar from all components.
    //! - Does not modify the alpha component!
    CRGBPixel& operator -=(tComponent c)
    {
        r() -= c;
        g() -= c;
        b() -= c;
        return *this;
    }

    //! Mutliplies all components by scalar.
    //! - Does not modify the alpha component!
    CRGBPixel& operator *=(double Value)
    {
        r() = tComponent(r() * Value);
        g() = tComponent(g() * Value);
        b() = tComponent(b() * Value);
        return *this;
    }

    //! Divides all components by scalar.
    //! - Does not modify the alpha component!
    CRGBPixel& operator /=(double Value)
    {
        double dInv = 1.0 / Value;
        r() = tComponent(r() * dInv);
        g() = tComponent(g() / dInv);
        b() = tComponent(b() / dInv);
        return *this;
    }

    //! Adds argument CRGBPixel to actual CRGBPixel and return as new.
    CRGBPixel operator +(const CRGBPixel& x)
    {
        return CRGBPixel(r() + x.r(), g() + x.g(), b() + x.b());
    }

    //! Subtracts argument CRGBPixel to actual CRGBPixel and return as new.
    CRGBPixel operator -(const CRGBPixel& x)
    {
        return CRGBPixel(r() - x.r(), g() - x.g(), b() - x.b());
    }

    //! Mutliplies argument CRGBPixel to actual CRGBPixel and return as new.
    CRGBPixel operator *(double Scalar)
    {
        return CRGBPixel(CRGBPixel::tComponent(r() * Scalar),
            CRGBPixel::tComponent(g() * Scalar),
            CRGBPixel::tComponent(b() * Scalar)
        );
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

inline CRGBPixel operator *(const CRGBPixel& l, const CRGBPixel& r)
{
    return CRGBPixel(CRGBPixel::tComponent(l.r() * r.r()),
        CRGBPixel::tComponent(l.g() * r.g()),
        CRGBPixel::tComponent(l.b() * r.b())
    );
}

inline CRGBPixel operator /(const CRGBPixel& l, const CRGBPixel& r)
{
    return CRGBPixel(CRGBPixel::tComponent(l.r() / r.r()),
        CRGBPixel::tComponent(l.g() / r.g()),
        CRGBPixel::tComponent(l.b() / r.b())
    );
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


//! RGBA pixel definition.
typedef CRGBPixel CRGBAPixel;




} // namespace img


//=============================================================================
/*
 * Specialization of some math functions for special pixel types.
 */

namespace math
{

//! Specialization of the function that returns an absolute value.
template <>
inline vpl::img::tRGBPixel getAbs(const vpl::img::tRGBPixel& a);

//! Specialization of the function that returns minimum of two values.
template <>
inline vpl::img::tRGBPixel getMin(const vpl::img::tRGBPixel& a, const vpl::img::tRGBPixel& b);

//! Specialization of the function that returns maximum of two values.
template <>
inline vpl::img::tRGBPixel getMax(const vpl::img::tRGBPixel& a, const vpl::img::tRGBPixel& b);

//! Specialization of the function that limits value x into an interval <a, b>.
template <>
inline void limit(vpl::img::tRGBPixel& x,
                  const vpl::img::tRGBPixel& a,
                  const vpl::img::tRGBPixel& b
                  );

//! Specialization of the function that remains values
//! in the range <a, b> unchanged, othervise
//! a new value n is assigned.
template <>
inline void cut(vpl::img::tRGBPixel& x,
                const vpl::img::tRGBPixel& a,
                const vpl::img::tRGBPixel& b,
                const vpl::img::tRGBPixel& n
                );

} // namespace math


//=============================================================================
/*
 * Specialization of some math functions for special pixel types.
 */

#include "PixelTypes.hxx"


} // namespace vpl

#endif // VPL_PIXELTYPES_H

