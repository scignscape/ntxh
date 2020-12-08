//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/12/16                          \n
 *
 * $Id: mdsInterpolate.h 2084 2012-02-13 10:23:58Z spanel $
 *
 * Description:
 * - Image pixel interpolation...
 */

#ifndef MDS_Interpolate_H
#define MDS_Interpolate_H

#include <MDSTk/Math/mdsBase.h>

#include "../mdsImageTypes.h"
#include "../mdsImage.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Base class for all policies providing image pixel interpolation.
 * - Parameter I is an image type.
 */
template <class I>
struct CImageInterpolator
{
    //! Check that I is an image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Image type.
    typedef typename I::tImage tImage;

    //! Image pixel type.
    typedef typename I::tPixel tPixel;
};


//==============================================================================
/*!
 * The simplest nearest neighbour interpolator.
 */
template <class I>
class CNearest : public CImageInterpolator<I>
{
public:
    //! Base types.
    typedef CImageInterpolator<I> tBase;
    typedef typename tBase::tImage tImage;
    typedef typename tBase::tPixel tPixel;

public:
    //! Returns the interpolated subpixel value.
    static tPixel interpolate(const tImage& Image, tCoordinate x, tCoordinate y)
    {
        mds::tSize i = mds::math::round2Int(x);
        mds::tSize j = mds::math::round2Int(y);
        return Image.at(i, j);
    }
};


//==============================================================================
/*!
 * Bilinear interpolation.
 */
template <class I>
class CBilinear : public CImageInterpolator<I>
{
public:
    //! Base types.
    typedef CImageInterpolator<I> tBase;
    typedef typename tBase::tImage tImage;
    typedef typename tBase::tPixel tPixel;

public:
    //! Returns the interpolated subpixel value.
    static tPixel interpolate(const tImage& Image, tCoordinate x, tCoordinate y)
    {
        tSize i = tSize(x);
        tSize j = tSize(y);

        tCoordinate dX = x - tCoordinate(i);
        tCoordinate dY = y - tCoordinate(j);
        tCoordinate dTempX = 1.0f - dX;
        tCoordinate dTempY = 1.0f - dY;

        tSize idx = Image.getIdx(i, j);

        // Interpolate subpixel value
        tCoordinate Value = dTempX * dTempY * tCoordinate(Image(idx));
        Value += dX * dTempY * tCoordinate(Image(idx + Image.getXOffset()));
        Value += dTempX * dY * tCoordinate(Image(idx + Image.getYOffset()));
        Value += dX * dY * tCoordinate(Image(idx + Image.getYOffset() + Image.getXOffset()));

        // Return the interpolated pixel value
        return tPixel(Value);
    }
};


//==============================================================================
/*!
 * Bicubic interpolation.
 */
template <class I>
class CBicubic : public CImageInterpolator<I>
{
public:
    //! Base types.
    typedef CImageInterpolator<I> tBase;
    typedef typename tBase::tImage tImage;
    typedef typename tBase::tPixel tPixel;

public:
    //! Default constructor.
    CBicubic(tCoordinate a = -0.75f) : m_A(a) {}

    //! Sets parameters of the Bicubic interpolation.
    void setParam(tCoordinate a) { m_A = a; }

    //! Returns the interpolated subpixel value.
    tPixel interpolate(const tImage& Image, tCoordinate x, tCoordinate y)
    {
        tSize i = tSize(x);
        tSize j = tSize(y);

        tCoordinate dX = x - tCoordinate(i);
        tCoordinate dY = y - tCoordinate(j);

        tCoordinate w0 = calcWeight2(1.0f + dX);
        tCoordinate w1 = calcWeight1(dX);
        tCoordinate w2 = calcWeight1(1.0f - dX);
        tCoordinate w3 = calcWeight2(2.0f - dX);

        tCoordinate a = w0 * Image(i - 1, j - 1)
            + w1 * Image(i, j - 1)
            + w2 * Image(i + 1, j - 1)
            + w3 * Image(i + 2, j - 1);

        tCoordinate b = w0 * Image(i - 1, j)
            + w1 * Image(i, j)
            + w2 * Image(i + 1, j)
            + w3 * Image(i + 2, j);

        tCoordinate c = w0 * Image(i - 1, j + 1)
            + w1 * Image(i, j + 1)
            + w2 * Image(i + 1, j + 1)
            + w3 * Image(i + 2, j + 1);

        tCoordinate d = w0 * Image(i - 1, j + 2)
            + w1 * Image(i, j + 2)
            + w2 * Image(i + 1, j + 2)
            + w3 * Image(i + 2, j + 2);

        tCoordinate Value = a * calcWeight2(1.0f + dY)
            + b * calcWeight1(dY)
            + c * calcWeight1(1.0f - dY)
            + d * calcWeight2(2.0f - dY);

        return tPixel(Value);
    }

protected:
    //! Optional parameter of the bicubic interpolation.
    tCoordinate m_A;

protected:
    //! Calculates concrete pixel weight (0<x<1).
    tCoordinate calcWeight1(tCoordinate x)
    {
        return ((m_A + 2.0) * x - (m_A + 3.0)) * x * x + 1.0;
    }

    //! Calculates concrete pixel weight (1<x<2).
    tCoordinate calcWeight2(tCoordinate x)
    {
        return ((m_A * x - 5.0 * m_A) * x + 8.0 * m_A) * x - 4.0 * m_A;
    }
};


//==============================================================================
/*!
 * Sinc interpolation.
 */
template <class I>
class CSinc : public CImageInterpolator<I>
{
public:
    //! Base types.
    typedef CImageInterpolator<I> tBase;
    typedef typename tBase::tImage tImage;
    typedef typename tBase::tPixel tPixel;

public:
    //! Default constructor.
    CSinc() {}

    //! Returns the interpolated subpixel value.
    tPixel interpolate(const tImage& Image, tCoordinate x, tCoordinate y)
    {
        tSize i = tSize(x);
        tSize j = tSize(y);

        tCoordinate dX = x - tCoordinate(i);
        tCoordinate dY = y - tCoordinate(j);

        // Prepare weights
        tCoordinate WeightsX[16], WeightsY[16];
        for( int w = 0; w < 8; ++w )
        {
            WeightsX[w] = calcWeight(7 + dX - w);
            WeightsX[w + 8] = calcWeight(1 - dX + w);

            WeightsY[w] = calcWeight(7 + dY - w);
            WeightsY[w + 8] = calcWeight(1 - dY + w);
        }

        tCoordinate Values[16];
        for( int l = 0; l < 16; ++l )
        {
            Values[l] = 0.0f;
            for( int k = 0; k < 16; ++k )
            {
                Values[l] += Image(i - 7 + k, j - 7 + l) * WeightsX[k];
            }
        }

        tCoordinate Value = 0.0f;
        for( int m = 0; m < 16; ++m )
        {
            Value += Values[m] * WeightsY[m];
        }

        return tPixel(Value);
    }

protected:
    //! Calculates concrete pixel weight (0<x<1).
    tCoordinate calcWeight(tCoordinate x)
    {
        if( x == 0.0f )
        {
            return 1.0f;
        }

        tCoordinate A = x * tCoordinate(mds::math::PI);
        tCoordinate InvA = 1.0f / A;

        return (std::sin(A) * InvA) * (std::sin(A * 0.125f) * InvA * 8.0);
    }
};


} // namespace img
} // namespace mds

#endif // MDS_Interpolate_H

