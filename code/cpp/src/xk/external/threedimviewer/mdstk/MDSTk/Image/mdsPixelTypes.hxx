//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/18                          \n
 *
 * $Id: mdsPixelTypes.hxx 1707 2010-05-05 11:00:46Z spanel $
 *
 * Description:
 * - Basic pixel types definition.
 */

namespace math
{

//=============================================================================
/*
 * Specialization of some math functions for RGB pixel type.
 */

template <>
inline mds::img::tRGBPixel getAbs(const mds::img::tRGBPixel& a)
{
    return a;
}


template <>
inline mds::img::tRGBPixel getMin(const mds::img::tRGBPixel& a, const mds::img::tRGBPixel& b)
{
    return mds::img::tRGBPixel(mds::math::getMin(a.r(), b.r()),
                               mds::math::getMin(a.g(), b.g()),
                               mds::math::getMin(a.b(), b.b())
                               );
}


template <>
inline mds::img::tRGBPixel getMax(const mds::img::tRGBPixel& a, const mds::img::tRGBPixel& b)
{
    return mds::img::tRGBPixel(mds::math::getMax(a.r(), b.r()),
                               mds::math::getMax(a.g(), b.g()),
                               mds::math::getMax(a.b(), b.b())
                               );
}


template <>
inline void limit(mds::img::tRGBPixel& x,
                  const mds::img::tRGBPixel& a,
                  const mds::img::tRGBPixel& b
                  )
{
    mds::math::limit(x.r(), a.r(), b.r());
    mds::math::limit(x.g(), a.g(), b.g());
    mds::math::limit(x.b(), a.b(), b.b());
}


template <>
inline void cut(mds::img::tRGBPixel& x,
                const mds::img::tRGBPixel& a,
                const mds::img::tRGBPixel& b,
                const mds::img::tRGBPixel& n
                )
{
    mds::math::cut(x.r(), a.r(), b.r(), n.r());
    mds::math::cut(x.g(), a.g(), b.g(), n.g());
    mds::math::cut(x.b(), a.b(), b.b(), n.b());
}


} // namespace math
