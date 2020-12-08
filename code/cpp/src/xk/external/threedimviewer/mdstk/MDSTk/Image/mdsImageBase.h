//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/12                          \n
 *
 * $Id: mdsImageBase.h 2098 2012-02-16 23:50:36Z spanel $
 *
 * Description:
 * - Base class for all images.
 */

#ifndef MDS_IMAGEBASE_H
#define MDS_IMAGEBASE_H

#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Base/mdsScalar.h>

#include "mdsSize.h"
#include "mdsPoint3.h"


namespace mds
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
#define MDS_IMAGE_TRAITS(ImageClass) \
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
    CSize2i& getSize() { return getImpl().getSize(); }
    const CSize2i& getSize() const { return getImpl().getSize(); }

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
    inline Function pforEach(Function Func)
    {
        return getImpl().pforEach(Func);
    }

    //! Calls a function object for every image pixel.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func) const
    {
        return getImpl().pforEach(Func);
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
} // namespace mds

#endif // MDS_IMAGEBASE_H

