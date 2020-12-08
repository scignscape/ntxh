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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2010 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/18                          \n
 *
 * Description:
 * - Class template providing image representation based on OpenCV library.
 */

#ifndef VPL_CvImage_H
#define VPL_CvImage_H

#include <VPL/Base/Setup.h>

#ifdef VPL_OPENCV_ENABLED

#include <VPL/Base/Assert.h>
#include <VPL/Base/Types.h>
#include <VPL/System/Memory.h>
#include <VPL/Base/SharedPtr.h>
#include <VPL/Math/Base.h>
#include <VPL/Module/Serializer.h>

#include "ImageBase.h"
#include "ImageIterator.h"
#include "ImageFunctional.h"
#include "ImageView.h"
#include "Point3.h"
#include "PixelConversions.h"
#include "Color.h"

#include "CvImageRef.h"


namespace vpl
{
namespace img
{

// Forward declarations
template <typename T> class CvImage;

// Declare image traits first...
template <typename T>
struct CImageTraits<CvImage<T> >
{
    typedef T tPixel;
};


//==============================================================================
/*!
 * Class template providing basic image operations. Image data are stored
 * in OpenCV format internaly.
 * - Parameter T is an image pixel type.
 * - Index of a row represents y-axis and is generally given
 *   as a second parameter of pixel subscripting functions.
 */
template <typename T>
class CvImage
    : public vpl::base::CObject
    , public CImageBase<CvImage<T> >
    , public vpl::mod::CSerializable
{
public:
    //! Base class
    typedef CImageBase<CvImage<T> > tBase;

    //! Templates that require members of an image class may use
    //! this enum to check the existence.
    enum { CLASS_IMAGE };

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CvImage);

    //! Image pixel type.
    typedef T tPixel;

    //! Image data storage.
    typedef CvImageRef<T> tDataStorage;

    //! View of the image (i.e. rectangle).
    typedef CRect<CvImage> tRect;

    //! Image row (the x coordinate is varying while the y is fixed).
    typedef CImageRow<CvImage> tRow;

    //! Iterator type.
    //! - Declares type tIterator.
    VPL_ITERATOR(CvImage, tPixel, CImageIterator)

    // Image serialization.
    VPL_ENTITY_TEMPLATE_NAME("Image", CPixelTraits<T>::getPixelName())

    //! Standard method getEntityCompression().
    VPL_ENTITY_COMPRESSION(vpl::mod::CC_GZIP)

public:
    //! Default constructor creates a new image having zero size.
    inline CvImage();

    //! Constructor.
    inline CvImage(tSize XSize, tSize YSize, tSize Margin = 0);

    //! Constructor.
    inline CvImage(const CImSize& Size, tSize Margin = 0);

    //! Constructor.
    //! - Creates a subimage of a given source image.
    //! - Uses margin size of the source image.
    //! - Makes own copy of the data.
    inline CvImage(const CvImage& Image,
           tSize x,
           tSize y,
           tSize XSize,
           tSize YSize
           );

    //! Constructor.
    //! - Creates a subimage of a given image.
    //! - Makes reference to the data.
    inline CvImage(const CvImage& Image,
           tSize x,
           tSize y,
           tSize XSize,
           tSize YSize,
           EMakeRef
           );

    //! Constructor.
    //! - Makes own copy of the data.
    inline CvImage(const tRect& Image);

    //! Constructor.
    //! - Makes only a reference to the data.
    inline CvImage(const tRect& Image, EMakeRef);

    //! Copy constructor.
    //! - Makes own copy of the data.
    inline CvImage(const CvImage& Image);

    //! Copy constructor.
    //! - Makes reference to the data.
    inline CvImage(const CvImage& Image, EMakeRef);

    //! Constructor from OpenCV image.
    //! - Takes full control over the image including deallocation of the memory.
    inline CvImage(IplImage *pImage);

    //! Destructor.
    virtual ~CvImage();

    //! Resizes the image.
    inline CvImage& resize(tSize XSize, tSize YSize, tSize Margin = 0);

    //! Resizes the image.
    inline CvImage& resize(const CImSize& Size, tSize Margin = 0);

    //! Creates a copy of an image.
    //! - Uses margin size of the source image if -1 is given as the parameter.
    CvImage& copy(const CvImage& Image, tSize Margin = -1);

    //! Creates a subimage of a given image.
    //! - Uses margin size of the source image if -1 is given as the parameter.
    //! - Makes own copy of the data.
    CvImage& copy(const CvImage& Image,
                    tSize x,
                    tSize y,
                    tSize XSize,
                    tSize YSize,
                    tSize Margin = -1
                    );

    //! Creates copy of a given image rectangle.
    //! - Uses margin size of the source image if -1 is given in the parameter.
    inline CvImage& copy(const tRect& Image, tSize Margin = -1);

    //! Creates reference or an image.
    //! - No data are copied.
    inline CvImage& makeRef(const CvImage& Image);

    //! Creates subimage of a given image.
    //! - Makes only a reference to the data.
    inline CvImage& makeRef(const CvImage& Image,
                            tSize x,
                            tSize y,
                            tSize XSize,
                            tSize YSize
                            );

    //! Creates reference to a given image rectangle.
    //! - Makes only a reference to the data.
    inline CvImage& makeRef(const tRect& Image);

    //! Creates image from an OpenCV image.
    //! - Takes full control over the image including deallocation of the memory.
    inline CvImage& fromIpl(IplImage *pImage);

    //! Assignment operator.
    //! - Copies pixel values from one image to another.
    CvImage& operator =(const CvImage& Image);

    //! Assignment operator.
    //! - Takes full control over OpenCV image including deallocation of the memory.
    inline CvImage& operator=(IplImage *pImage);

    //! Conversion of images of different types.
    //! - Resizes the current image according to the source one.
    //! - Uses margin size of the source image if -1 is given in the parameter.
    template <typename Derived>
    CvImage& convert(const CImageBase<Derived>& Image, tSize Margin = -1);


    //! Returns pointer to the underlying OpenCV image.
    //! - The returned image represents image data including the margin!
    const IplImage *asIpl() const { return m_Data.asIpl(); }
    IplImage *asIpl() { return m_Data.asIpl(); }

    //! Returns size of the rectangle.
    CImSize getSize() const { return CImSize(getXSize(), getYSize()); }

    //! Returns the image size (dimensions).
    tSize getXSize() const { return m_Data.getWidth() - (m_Margin << 1); }
    tSize getYSize() const { return m_Data.getHeight() - (m_Margin << 1); }

    //! Returns the image size (dimensions).
    tSize width() const { return getXSize(); }
    tSize height() const { return getYSize(); }


    //! Returns offset between two neighbouring image pixels in a row.
    tSize getXOffset() const { return m_Data.getColOffset(); }

    //! Returns offset between two neighbouring image pixels in a column.
    tSize getYOffset() const { return m_Data.getRowOffset(); }

    //! Returns the image margin size in pixels.
    tSize getMargin() const { return m_Margin; }


    //! Returns reference to the subscripted pixel [x][y].
    T& operator ()(tSize x, tSize y)
    {
        return *(m_pData + y * getYOffset() + x);
    }
    const T& operator ()(tSize x, tSize y) const
    {
        return *(m_pData + y * getYOffset() + x);
    }

    //! Returns reference to the pixel [x][y].
    T& at(tSize x, tSize y)
    {
        return *(m_pData + y * getYOffset() + x);
    }
    const T& at(tSize x, tSize y) const
    {
        return *(m_pData + y * getYOffset() + x);
    }

    //! Sets the pixel at the position [x][y].
    void set(tSize x, tSize y, const T& Value)
    {
        *(m_pData + y * getYOffset() + x) = Value;
    }


    //! Calculates index of a specified pixel.
    tSize getIdx(tSize x, tSize y) const
    {
        return y * getYOffset() + x;
    }

    //! Returns the subscripted pixel.
    T& operator ()(tSize i)
    {
        return *(m_pData + i);
    }
    const T& operator ()(tSize i) const
    {
        return *(m_pData + i);
    }

    //! Returns the subscripted pixel.
    T& at(tSize i)
    {
        return *(m_pData + i);
    }
    const T& at(tSize i) const
    {
        return *(m_pData + i);
    }

    //! Sets the subscripted voxel.
    CvImage& set(tSize i, const T& Value)
    {
        *(m_pData + i) = Value;
        return *this;
    }


    //! Returns pointer to the image data.
    T *getPtr() { return m_pData; }
    const T *getPtr() const { return m_pData; }

    //! Returns pointer to the pixel [x][y].
    T *getPtr(tSize x, tSize y)
    {
        return (m_pData + y * getYOffset() + x);
    }
    const T *getPtr(tSize x, tSize y) const
    {
        return (m_pData + y * getYOffset() + x);
    }

    //! Returns pointer to the first element of the image row.
    T *getRowPtr(tSize y)
    {
        return (m_pData + y * getYOffset());
    }
    const T *getRowPtr(tSize y) const
    {
        return (m_pData + y * getYOffset());
    }


    //! Pixel wise addition.
    template <class Derived>
    inline CvImage& operator +=(const  CImageBase<Derived>& Image);

    //! Pixel wise subtraction.
    template <class Derived>
    inline CvImage& operator -=(const  CImageBase<Derived>& Image);

    //! Pixel wise product.
    template <class Derived>
    inline CvImage& operator *=(const  CImageBase<Derived>& Image);

    //! Pixel wise division.
    template <class Derived>
    inline CvImage& operator /=(const  CImageBase<Derived>& Image);


    //! Adds scalar to all pixels.
    //! - An operator that allow conversion U -> T must be defined!
    template <typename U>
    inline CvImage& operator +=(const CScalar<U>& c);

    //! Subtracts scalar from all pixels.
    //! - An operator that allow conversion U -> T must be defined!
    template <typename U>
    inline CvImage& operator -=(const CScalar<U>& c);

    //! Multiplies all pixels by scalar.
    //! - An operator that allow conversion U -> T must be defined!
    template <typename U>
    inline CvImage& operator *=(const CScalar<U>& c);

    //! Divides all pixels by scalar.
    //! - An operator that allow conversion U -> T must be defined!
    template <typename U>
    inline CvImage& operator /=(const CScalar<U>& c);


    //! Calls function object for every image pixel.
    template <class Function>
    inline Function forEach(Function Func);

    //! Calls function object for every image pixel.
    template <class Function>
    inline Function forEach(Function Func) const;

    //! Calls function object for every image pixel.
    //! - Parallel version.
    template <class Function>
    inline void pforEach(Function Func);

    //! Calls function object for every image pixel.
    //! - Parallel version.
    template <class Function>
    inline void pforEach(Function Func) const;


    //! Returns a specified sub-image (i.e. rectangle).
    inline tRect rect(const CPoint2i& Position, const CImSize& Size);
    inline const tRect rect(const CPoint2i& Position, const CImSize& Size) const;

    //! Returns a specified sub-image (i.e. rectangle).
    inline tRect rect(const CRange& XRange, const CRange& YRange);
    inline const tRect rect(const CRange& XRange, const CRange& YRange) const;
    
    //! Returns a specified row.
    inline tRow row(tSize y);
    inline const tRow row(tSize y) const;


    //! Fills the image using a given pixel value.
    //! - Returns reference to this.
    inline CvImage& fill(const T c);

    //! Fills the entire image including its margin using a given pixel value.
    //! - Returns reference to this.
    inline CvImage& fillEntire(const T c);

    //! Pads the image margin with constant value.
    //! - Returns reference to this.
    inline CvImage& fillMargin(const T c);

    //! Pads the image margin using a simple mirroring.
    //! - Returns reference to this.
    inline CvImage& mirrorMargin();


    //! Replaces all pixels of a given value by a specified value.
    //! - Returns reference to this.
    inline CvImage& replace(const T& Value, const T& NewValue);

    //! Absolute value of all pixels.
    //! - Returns reference to this.
    inline CvImage& abs();

    //! Clips a range of pixel values.
    //! - Returns reference to this.
    inline CvImage& limit(const T& Lower, const T& Upper);

    //! Cuts range of pixel values.
    //! - Returns reference to this.
    inline CvImage& cut(const T& Lower, const T& Upper);

    //! Subsamples a given image and stores the result.
    //! - Returns reference to this.
    inline CvImage& subSample(const CvImage& Image, const tSize k = 2, const tSize l = 2);


    //! Bilinear subpixel value interpolation.
    inline T interpolate(const CPoint3D& Point) const;

    //! Converts a specified color to the image pixel format and range.
    inline T color2Pixel(CColor color) const;

    //! Checks the pixel position.
    //! - Returns 'true' if a specified position is satisfactory.
    inline bool checkPosition(tSize x, tSize y) const;


    //! Serializes all class members.
    template <class S>
    void serialize(vpl::mod::CChannelSerializer<S>& Writer);

    //! Deserializes all class members.
    template <class S>
    void deserialize(vpl::mod::CChannelSerializer<S>& Reader);

protected:
    //! Image margin.
    tSize m_Margin;

    //! Image data.
    tDataStorage m_Data;

    //! Direct pointer to the image data.
    T *m_pData;
};


// Modify the image compression method with respect to a concrete pixel type.
VPL_SPECIALIZE_ENTITY_COMPRESSION(CvImage<tDensityPixel>, vpl::mod::CC_DENSITY)


//=============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates.
#include "CvImage.hxx"


//=============================================================================
/*
 * Basic type definitions.
 */

//! Grayscale image, 8-bits per pixel.
typedef CvImage<tPixel8>            CvImage8;

//! Grayscale image, 16-bits per pixel.
typedef CvImage<tPixel16>           CvImage16;

//! Grayscale image, 32-bits per pixel.
typedef CvImage<tPixel32>           CvImage32;

//! Float image.
typedef CvImage<tFloatPixel>        CvFImage;

//! Density image.
typedef CvImage<tDensityPixel>      CvDImage;

//! Color RGB image.
typedef CvImage<tRGBPixel>          CvRGBImage;

//! Complex image.
typedef CvImage<tComplexPixel>      CvComplexImage;


//! Smart pointer to grayscale image, 8-bit per pixel.
typedef CvImage8::tSmartPtr         CvImage8Ptr;

//! Smart pointer to grayscale image, 16-bit per pixel.
typedef CvImage16::tSmartPtr        CvImage16Ptr;

//! Smart pointer to grayscale image, 32-bit per pixel.
typedef CvImage32::tSmartPtr        CvImage32Ptr;

//! Smart pointer to float image.
typedef CvFImage::tSmartPtr         CvFImagePtr;

//! Smart pointer to density image.
typedef CvDImage::tSmartPtr         CvDImagePtr;

//! Smart pointer to color RGB image.
typedef CvRGBImage::tSmartPtr       CvRGBImagePtr;

//! Smart pointer to complex image.
typedef CvComplexImage::tSmartPtr   CvComplexImagePtr;


} // namespace img
} // namespace vpl

#endif // VPL_OPENCV_ENABLED
#endif // VPL_CvImage_H

