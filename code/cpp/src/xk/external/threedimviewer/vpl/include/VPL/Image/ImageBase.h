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
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/12                       
 *
 * Description:
 * - Base class for all images.
 */

#ifndef VPL_IMAGEBASE_H
#define VPL_IMAGEBASE_H

#include <VPL/Base/Types.h>
#include <VPL/Base/Scalar.h>

#include "Size.h"
#include "Point3.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Traits used to implement curiously recurring template pattern for images.
 */
template <typename I>
struct CImageTraits
{
    //! Pixel type.
    typedef tNull tPixel;
};


//! Helper macro used to declare image traits before an image class template.
#define VPL_IMAGE_TRAITS(ImageClass) \
    template <typename T, template <typename> class A> class ImageClass; \
    template <typename T, template <typename> class A> \
    struct CImageTraits<ImageClass<T, A> > \
    { \
        typedef T tPixel; \
    };


//==============================================================================
/*!
 * Base class for all images.
 * - Base class takes a template parameter I. This parameter is the type
 *   of the class which derives from it (so called curiously recurring template
 *   pattern).
 */
template <class I>
class CImageBase
{
public:
    //! Image type.
    typedef I tImage;

    //! Pixel type.
    typedef typename CImageTraits<I>::tPixel tPixel;

public:
    //! Returns reference to the image implementation.
    tImage& getImpl()
    {
        return *static_cast<tImage *>(this);
    }
    const tImage& getImpl() const
    {
        return *static_cast<const tImage *>(this);
    }

public:
    //! Returns size of the image.
    CImSize& getSize() { return getImpl().getSize(); }
    const CImSize& getSize() const { return getImpl().getSize(); }
    
    //! Returns the image size (dimensions).
    tSize getXSize() const { return getImpl().getXSize(); }
    tSize getYSize() const { return getImpl().getYSize(); }

    //! Returns the image size (dimensions).
    tSize width() const { return getImpl().width(); }
    tSize height() const { return getImpl().height(); }


    //! Returns offset between two neigbouring pixels in x-axis.
    tSize getXOffset() const { return getImpl().getXOffset(); }

    //! Returns offset between two neigbouring pixels in y-axis.
    tSize getYOffset() const { return getImpl().getYOffset(); }

    //! Returns the image margin size in pixels.
    tSize getMargin() const { return getImpl().getMargin(); }


    //! Returns the subscripted pixel [x][y].
    tPixel& operator ()(tSize x, tSize y)
    {
        return getImpl().at(x, y);
    }
    const tPixel& operator ()(tSize x, tSize y) const
    {
        return getImpl().at(x, y);
    }

    //! Returns the subscripted Pixel [x][y].
    tPixel& at(tSize x, tSize y)
    {
        return getImpl().at(x, y);
    }
    const tPixel& at(tSize x, tSize y) const
    {
        return getImpl().at(x, y);
    }

    //! Sets the pixel at the position [x][y][z].
    tImage& set(tSize x, tSize y, const tPixel& Value)
    {
        return getImpl().set(x, y, Value);
    }


    //! Calculates pixel index.
    tSize getIdx(tSize x, tSize y) const
    {
        return getImpl().getIdx(x, y);
    }

    //! Returns the subscripted pixel.
    tPixel& operator ()(tSize i)
    {
        return getImpl().at(i);
    }
    const tPixel& operator ()(tSize i) const
    {
        return getImpl().at(i);
    }

    //! Returns the subscripted pixel.
    tPixel& at(tSize i)
    {
        return getImpl().at(i);
    }
    const tPixel& at(tSize i) const
    {
        return getImpl().at(i);
    }

    //! Sets the subscripted pixel.
    tImage& set(tSize i, const tPixel& Value)
    {
        return getImpl().set(i, Value);
    }


    //! Calls a function object for every image pixel.
    template <class Function>
    inline Function forEach(Function Func)
    {
        return getImpl().forEach(Func);
    }

    //! Calls a function object for every image pixel.
    template <class Function>
    inline Function forEach(Function Func) const
    {
        return getImpl().forEach(Func);
    }

    //! Calls a function object for every image pixel.
    //! - Parallel version.
    template <class Function>
    inline void pforEach(Function Func)
    {
        getImpl().pforEach(Func);
    }

    //! Calls a function object for every image pixel.
    //! - Parallel version.
    template <class Function>
    inline void pforEach(Function Func) const
    {
        getImpl().pforEach(Func);
    }

protected:
    //! Default constructor.
    CImageBase() {}

    //! Copy constructor.
    CImageBase(const CImageBase&) {}

    //! Assignment operator.
    CImageBase& operator =(const CImageBase&) { return *this; }
};


} // namespace img
} // namespace vpl

#endif // VPL_IMAGEBASE_H

