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

namespace math
{

//=============================================================================
/*
 * Specialization of some math functions for RGB pixel type.
 */

template <>
inline vpl::img::tRGBPixel getAbs(const vpl::img::tRGBPixel& a)
{
    return a;
}


template <>
inline vpl::img::tRGBPixel getMin(const vpl::img::tRGBPixel& a, const vpl::img::tRGBPixel& b)
{
    return vpl::img::tRGBPixel(vpl::math::getMin(a.r(), b.r()),
                               vpl::math::getMin(a.g(), b.g()),
                               vpl::math::getMin(a.b(), b.b())
                               );
}


template <>
inline vpl::img::tRGBPixel getMax(const vpl::img::tRGBPixel& a, const vpl::img::tRGBPixel& b)
{
    return vpl::img::tRGBPixel(vpl::math::getMax(a.r(), b.r()),
                               vpl::math::getMax(a.g(), b.g()),
                               vpl::math::getMax(a.b(), b.b())
                               );
}


template <>
inline void limit(vpl::img::tRGBPixel& x,
                  const vpl::img::tRGBPixel& a,
                  const vpl::img::tRGBPixel& b
                  )
{
    vpl::math::limit(x.r(), a.r(), b.r());
    vpl::math::limit(x.g(), a.g(), b.g());
    vpl::math::limit(x.b(), a.b(), b.b());
}


template <>
inline void cut(vpl::img::tRGBPixel& x,
                const vpl::img::tRGBPixel& a,
                const vpl::img::tRGBPixel& b,
                const vpl::img::tRGBPixel& n
                )
{
    vpl::math::cut(x.r(), a.r(), b.r(), n.r());
    vpl::math::cut(x.g(), a.g(), b.g(), n.g());
    vpl::math::cut(x.b(), a.b(), b.b(), n.b());
}


} // namespace math
