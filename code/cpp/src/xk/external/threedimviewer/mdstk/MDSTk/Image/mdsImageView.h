//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2012 by 3Dim Laboratory s.r.o. \n
 *
 * Author:  info@3dim-laboratory.cz             \n
 * Date:    2012/02/11                          \n
 *
 * $Id:$
 *
 * Description:
 * - Templates providing views of an existing image.
 */

#ifndef MDS_ImageView_H
#define MDS_ImageView_H

#include <MDSTk/Base/mdsRange.h>
#include <MDSTk/Math/mdsVectorBase.h>

#include "mdsImageBase.h"
#include "mdsPoint3.h"
#include "mdsSize.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Base class for all classes providing a view of an existing image.
 */
struct CImageView
{
    //! Simple tag of "image view" classes.
    enum { CLASS_IMAGE_VIEW };
};


//==============================================================================
/*!
 * Class template representing a rectangle within an existing image.
 * - Parameter I is an image type.
 */
template <class I>
class CRect : public CImageView, public CImageBase<CRect<I> >
{
public:
    //! Base class.
    typedef CImageBase<CRect<I> > tBase;

    //! Check that I is a image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Image type.   
    typedef I tImage;

    //! Pixel type.
    typedef typename I::tPixel tPixel;

public:
    //! Constructor...
    inline CRect(const tImage& Image,
                 tSize x,
                 tSize y,
                 tSize XSize,
                 tSize YSize
                 );

    //! Yet another constructor...
    inline CRect(const tImage& Image, const CPoint2i& Pos, const CSize2i& Size);

    //! Yet another constructor...
    inline CRect(const tImage& Image,
                 const CRange& XRange,
                 const CRange& YRange
                 );

    //! Copy constructor.
    inline CRect(const CRect&);

    //! Returns size of the rectangle.
    CSize2i& getSize() { return m_Size; }
    const CSize2i& getSize() const { return m_Size; }

    //! Returns position of the left upper corner.
    CPoint2i& getPos() { return m_Pos; }
    const CPoint2i& getPos() const { return m_Pos; }

    //! Returns reference to the original image.
    tImage& getImageRef() const { return m_Image; }


    //! Returns the image size (dimensions).
    tSize getXSize() const { return m_Size.getXSize(); }
    tSize getYSize() const { return m_Size.getYSize(); }

    //! Returns the image size (dimensions).
    tSize width() const { return m_Size.width(); }
    tSize height() const { return m_Size.height(); }


    //! Returns offset between two neigbouring pixels in x-axis.
    tSize getXOffset() const { return m_Image.getXOffset(); }

    //! Returns offset between two neigbouring pixels in y-axis.
    tSize getYOffset() const { return m_Image.getYOffset(); }

    //! Returns the image margin size in pixels.
    tSize getMargin() const { return m_Image.getMargin(); }


    //! Returns the subscripted pixel [x][y].
    tPixel& operator ()(tSize x, tSize y)
    {
        return m_Image.at(x + m_Pos.x(), y + m_Pos.y());
    }
    const tPixel& operator ()(tSize x, tSize y) const
    {
        return m_Image.at(x + m_Pos.x(), y + m_Pos.y());
    }

    //! Returns the pixel [x][y].
    tPixel& at(tSize x, tSize y)
    {
        return m_Image.at(x + m_Pos.x(), y + m_Pos.y());
    }
    const tPixel& at(tSize x, tSize y) const
    {
        return m_Image.at(x + m_Pos.x(), y + m_Pos.y());
    }

    //! Sets the pixel at the position [x][y].
    CRect& set(tSize x, tSize y, const tPixel& Value)
    {
        m_Image.set(x + m_Pos.x(), y + m_Pos.y(), Value);
        return *this;
    }


    //! Calculates index of the pixel [x][y].
    tSize getIdx(tSize x, tSize y) const
    {
        return m_Image.getIdx(x + m_Pos.x(), y + m_Pos.y());
    }

    //! Returns the subscripted pixel.
    tPixel& operator ()(tSize i)
    {
        return m_Image.at(i);
    }
    const tPixel& operator ()(tSize i) const
    {
        return m_Image.at(i);
    }

    //! Returns the subscripted pixel.
    tPixel& at(tSize i)
    {
        return m_Image.at(i);
    }
    const tPixel& at(tSize i) const
    {
        return m_Image.at(i);
    }

    //! Sets the subsripted pixel.
    CRect& set(tSize i, const tPixel& Value)
    {
        m_Image.set(i, Value);
        return *this;
    }


    //! Pixel wise addition.
    template <class Derived>
    inline CRect& operator +=(const CImageBase<Derived>& Image);

    //! Pixel wise subtraction.
    template <class Derived>
    inline CRect& operator -=(const CImageBase<Derived>& Image);

    //! Pixel wise product.
    template <class Derived>
    inline CRect& operator *=(const CImageBase<Derived>& Image);

    //! Pixel wise division.
    template <class Derived>
    inline CRect& operator /=(const CImageBase<Derived>& Image);


    //! Adds scalar to all pixels.
    //! - An operator that allows conversion from U to T must be defined!
    template <typename U>
    inline CRect& operator +=(const U& c);

    //! Subtracts scalar from all pixels.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CRect& operator -=(const U& c);

    //! Multiplies all pixels by scalar.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CRect& operator *=(const U& c);

    //! Divides all pixels by scalar.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CRect& operator /=(const U& c);


    //! Calls a function object for every pixel in the rectangle.
    template <class Function>
    inline Function forEach(Function Func);

    //! Calls a function object for every pixel in the rectangle.
    template <class Function>
    inline Function forEach(Function Func) const;

    //! Calls a function object for every pixel in the rectangle.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func);

    //! Calls a function object for every pixel in the rectangle.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func) const;


    //! Fills the rectangle using a given pixel value.
    inline CRect& fill(const tPixel& c);

    //! Fills the rectangle using a given input buffer.
    void copyFrom(const tPixel *pSrc);

    //! Copies the data to the output buffer.
    void copyTo(tPixel *pDst) const;
    
protected:
    //! Coordinates of the origin.
    CPoint2i m_Pos;

    //! Size of the rectangle.
    CSize2i m_Size;

    //! Reference to the original image.
    tImage& m_Image;

protected:
    //! Proctected assignment operator.
    CRect& operator =(const CRect&) { return *this; }
};


//==============================================================================
/*!
 * Class template representing a single row of an existing image.
 * - Parameter I is an image type.
 */
template <class I>
class CImageRow : public CImageView, public mds::math::CVectorBase<CImageRow<I> >
{
public:
    //! Base class.
    typedef mds::math::CVectorBase<CImageRow<I> > tBase;

    //! Check that I is a image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Image type.
    typedef I tImage;

    //! Pixel type.
    typedef typename I::tPixel tPixel;

public:
    //! Constructor.
    inline CImageRow(const tImage& Image, tSize y);

    //! Copy constructor.
    inline CImageRow(const CImageRow& Row);

    //! Returns the row size.
    tSize getSize() const { return m_Image.getXSize(); }

    //! Returns the row size.
    tSize size() const { return m_Image.width(); }

    //! Returns stride between two neigbouring elements.
    tSize getStride() const { return m_Image.getXOffset(); }


    //! Returns a subscripted pixel of the row.
    tPixel& operator ()(tSize x)
    {
        return m_Image.at(x, m_y);
    }
    const tPixel& operator ()(tSize x) const
    {
        return m_Image.at(x, m_y);
    }

    //! Returns a subscripted pixel of the row.
    tPixel& at(tSize x)
    {
        return m_Image.at(x, m_y);
    }
    const tPixel& at(tSize x) const
    {
        return m_Image.at(x, m_y);
    }

    //! Changes value of a pixel in the row.
    CImageRow& set(tSize x, const tPixel& Value)
    {
        m_Image.set(x, m_y, Value);
        return *this;
    }


    //! Pixel wise addition.
    template <class Derived>
    inline CImageRow& operator +=(const mds::math::CVectorBase<Derived>& Row);

    //! Pixel wise subtraction.
    template <class Derived>
    inline CImageRow& operator -=(const mds::math::CVectorBase<Derived>& Row);

    //! Pixel wise product.
    template <class Derived>
    inline CImageRow& operator *=(const mds::math::CVectorBase<Derived>& Row);

    //! Pixel wise division.
    template <class Derived>
    inline CImageRow& operator /=(const mds::math::CVectorBase<Derived>& Row);


    //! Adds scalar to all pixels.
    //! - An operator that allows conversion from U to T must be defined!
    template <typename U>
    inline CImageRow& operator +=(const U& c);

    //! Subtracts scalar from all pixels.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CImageRow& operator -=(const U& c);

    //! Multiplies all pixels by scalar.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CImageRow& operator *=(const U& c);

    //! Divides all pixels by scalar.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CImageRow& operator /=(const U& c);


    //! Calls a function object for every pixel in the row.
    template <class Function>
    inline Function forEach(Function Func);

    //! Calls a function object for every pixel in the row.
    template <class Function>
    inline Function forEach(Function Func) const;

    //! Calls a function object for every pixel in the row.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func);

    //! Calls a function object for every pixel in the row.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func) const;


    //! Fills the row using a given pixel value.
    inline CImageRow& fill(const tPixel& c);

    //! Fills the row using a given input buffer.
    void copyFrom(const tPixel *pSrc);

    //! Copies the row data to the output buffer.
    void copyTo(tPixel *pDst) const;
    
protected:
    //! Coordinate of the image row.
    tSize m_y;

    //! Reference to the original image.
    tImage& m_Image;

protected:
    //! Proctected assignment operator.
    CImageRow& operator =(const CImageRow&) { return *this; }
};


//=============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsImageView.hxx"


} // namespace img
} // namespace mds

#endif // MDS_ImageView_H
