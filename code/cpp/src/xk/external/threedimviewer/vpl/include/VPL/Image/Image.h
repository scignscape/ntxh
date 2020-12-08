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
 * Date:    2003/12/08
 *
 * Description:
 * - Template providing basic image operations.
 */

#ifndef VPL_IMAGE_H
#define VPL_IMAGE_H

#include <VPL/Base/Assert.h>
#include <VPL/Base/Types.h>
#include <VPL/System/Memory.h>
#include <VPL/Base/RefData.h>
#include <VPL/Base/SharedPtr.h>
#include <VPL/Base/Range.h>
#include <VPL/Math/Base.h>
#include <VPL/Module/Serializer.h>

#include "ImageBase.h"
#include "ImageIterator.h"
#include "ImageFunctional.h"
#include "ImageView.h"
#include "PixelConversions.h"
#include "Color.h"

 // Check what version of the data allocator should be used
#define VPL_IMAGE_DATA_ALLOCATOR vpl::base::CRefData

namespace vpl
{
namespace img
{

// Declare image traits first...
VPL_IMAGE_TRAITS(CImage)

//==============================================================================
/*!
* Class template representing 2D image data.
* This imae class allows you to create new images as references
* to the existing ones (or their parts) without making true copy of data.
* - Parameter T is the image pixel type.
* - Image data are stored in row-major format. Index of the row represents
*   y-axis and is generally given as a second parameter of pixel subscripting
*   functions.
* - Data allocator should be a class template derived from
*   vpl::base::CDataAllocator<> and it has to adopt reference counting
*   mechanism similar to the one implemented in vpl::base::CRefData<>.
*/
template <typename T, template <typename> class Allocator = VPL_IMAGE_DATA_ALLOCATOR>
class CImage
    : public vpl::base::CObject
    , public CImageBase<CImage<T, Allocator> >
    , public vpl::mod::CSerializable
{
public:
    //! Base class
    typedef CImageBase<CImage<T, Allocator> > tBase;

    //! Templates that require members of the CImage class may use
    //! this enum to check the existence.
    enum { CLASS_IMAGE };

    //! Image pixel type.
    typedef T tPixel;

    //! Image data storage type.
    typedef Allocator<T> tDataStorage;

    //! View of the image (i.e. rectangle).
    typedef CRect<CImage> tRect;

    //! Image row (the x coordinate is varying while the y is fixed).
    typedef CImageRow<CImage> tRow;


#ifndef SWIG
    //! Declare smart pointer type tSmartPtr.
    VPL_SHAREDPTR(CImage);
    //! Declare iterator types tIterator and tConstIterator.
    VPL_ITERATOR(CImage, tPixel, CImageIterator)
        // Image serialization.
        VPL_ENTITY_TEMPLATE_NAME("Image", CPixelTraits<T>::getPixelName())
        //! Standard method getEntityCompression().
        VPL_ENTITY_COMPRESSION(vpl::mod::CC_GZIP)

#endif // SWIG

public:
    //! Default constructor creates image of zero size.
    inline CImage();

    //! Constructor that allocates volume data.
    inline CImage(tSize XSize, tSize YSize, tSize Margin = 0);

    //! Constructor that allocates volume data.
    inline CImage(const CSize2i& Size, tSize Margin = 0);

    //! Constructor that copies a subimage from a given source image.
    //! - Uses margin size of the source image.
    //! - Makes own copy of the data.
    inline CImage(const CImage& Image,
        tSize x,
        tSize y,
        tSize XSize,
        tSize YSize
    );

    //! Constructor that creates a subimage of a given source image.
    //! - Makes reference to the data.
    inline CImage(const CImage& Image,
        tSize x,
        tSize y,
        tSize XSize,
        tSize YSize,
        EMakeRef
    );

    //! Constructor creates a copy of a given source subimage.
    //! - Makes own copy of the data.
    inline CImage(const tRect& Image);

    //! Constructor makes a roference to a given subimage.
    //! - No image data are copied.
    inline CImage(const tRect& Image, EMakeRef);

    //! Copy constructor.
    //! - Makes own copy of the data.
    inline CImage(const CImage& Image);

    //! Constructor that makes only reference to the original data.
    //! - No image data are copied.
    inline CImage(const CImage& Image, EMakeRef);

    //! Destructor.
    virtual ~CImage();

    //! Resizes the image.
    inline CImage& resize(tSize XSize, tSize YSize, tSize Margin = 0);

    //! Resizes the image data.
    inline CImage& resize(const CSize2i& Size, tSize Margin = 0);

    //! Creates copy of an image.
    //! - Uses margin size of the source image if -1 is given as the parameter.
    CImage& copy(const CImage& Image, tSize Margin = -1);

    //! Creates a copy of a specified subimage.
    //! - Uses margin size of the source image if -1 is given as the parameter.
    //! - Makes own copy of the data.
    CImage& copy(const CImage& Image,
        tSize x,
        tSize y,
        tSize XSize,
        tSize YSize,
        tSize Margin = -1
    );

    //! Creates copy of a given image rectangle.
    //! - Uses margin size of the source image if -1 is given in the parameter.
    CImage& copy(const tRect& Image, tSize Margin = -1);

    //! Creates reference to an image.
    //! - No image data are copied.
    inline CImage& makeRef(const CImage& Image);

    //! Creates reference to a rectangle of a given image.
    //! - No image data are copied.
    inline CImage& makeRef(const CImage& Image,
        tSize x,
        tSize y,
        tSize XSize,
        tSize YSize
    );

    //! Creates reference to a given image rectangle.
    //! - No image data are copied.
    inline CImage& makeRef(const tRect& Image);

    //! Assignment operator.
    //! - Copies pixel values from one image to another.
    CImage& operator =(const CImage& Image);

    //! Conversion between images of different types.
    //! - Resizes the current image according to the source one.
    //! - Uses margin size of the source image if -1 is given in the parameter.
    template <typename Derived>
    CImage& convert(const CImageBase<Derived>& Image, tSize Margin = -1);


    //! Returns size of the rectangle.
    CSize2i& getSize() { return m_Size; }
    const CSize2i& getSize() const { return m_Size; }

    //! Returns the image size (dimensions).
    tSize getXSize() const { return m_Size.x(); }
    tSize getYSize() const { return m_Size.y(); }

    //! Returns the image size (dimensions).
    tSize width() const { return m_Size.x(); }
    tSize height() const { return m_Size.y(); }


    //! Returns column offset in x-axis. In other words, offset between
    //! two neighbouring image pixels in a row.
    tSize getXOffset() const { return 1; }

    //! Returns row offset in y-axis. In other words, offset between two
    //! neighbouring image pixels in a column.
    tSize getYOffset() const { return m_YOffset; }

    //! Returns the image margin size in pixels.
    tSize getMargin() const { return m_Margin; }


    //! Returns reference to the subscripted pixel [x][y].
    T& operator ()(tSize x, tSize y)
    {
        return m_DataStorage.at(m_ZeroOffset + y * m_YOffset + x);
    }
    const T& operator ()(tSize x, tSize y) const
    {
        return m_DataStorage.at(m_ZeroOffset + y * m_YOffset + x);
    }

#ifndef SWIG
    //! Returns reference to the pixel [x][y].
    T& at(tSize x, tSize y)
    {
        return m_DataStorage.at(m_ZeroOffset + y * m_YOffset + x);
    }
#endif
    //! Returns reference to the pixel [x][y].
    const T& at(tSize x, tSize y) const
    {
        return m_DataStorage.at(m_ZeroOffset + y * m_YOffset + x);
    }

    //! Sets the pixel at the position [x][y].
    CImage& set(tSize x, tSize y, const T& Value)
    {
        m_DataStorage.set(m_ZeroOffset + y * m_YOffset + x, Value);
        return *this;
    }


    //! Calculates index of a specified pixel.
    tSize getIdx(tSize x, tSize y) const
    {
        return y * m_YOffset + x;
    }

    //! Returns the subscripted pixel.
    T& operator ()(tSize i)
    {
        return m_DataStorage.at(m_ZeroOffset + i);
    }
    const T& operator ()(tSize i) const
    {
        return m_DataStorage.at(m_ZeroOffset + i);
    }

#ifndef SWIG
    //! Returns the subscripted pixel.
    T& at(tSize i)
    {
        return m_DataStorage.at(m_ZeroOffset + i);
    }
#endif
    const T& at(tSize i) const
    {
        return m_DataStorage.at(m_ZeroOffset + i);
    }

    //! Sets the subscripted voxel.
    CImage& set(tSize i, const T& Value)
    {
        m_DataStorage.set(m_ZeroOffset + i, Value);
        return *this;
    }


    //! Returns pointer to the image data.
    T *getPtr() { return m_DataStorage.getPtr(m_ZeroOffset); }
    const T *getPtr() const { return m_DataStorage.getPtr(m_ZeroOffset); }

    //! Returns pointer to the given pixel.
    T *getPtr(tSize x, tSize y)
    {
        return m_DataStorage.getPtr(m_ZeroOffset + y * m_YOffset + x);
    }
    const T *getPtr(tSize x, tSize y) const
    {
        return m_DataStorage.getPtr(m_ZeroOffset + y * m_YOffset + x);
    }

    //! Returns pointer to the first element of the image row.
    T *getRowPtr(tSize y)
    {
        return m_DataStorage.getPtr(m_ZeroOffset + y * m_YOffset);
    }
    const T *getRowPtr(tSize y) const
    {
        return m_DataStorage.getPtr(m_ZeroOffset + y * m_YOffset);
    }


    //! Pixel wise addition.
    template <class Derived>
    inline CImage& operator +=(const CImageBase<Derived>& Image);

    //! Pixel wise subtraction.
    template <class Derived>
    inline CImage& operator -=(const CImageBase<Derived>& Image);

    //! Pixel wise product.
    template <class Derived>
    inline CImage& operator *=(const CImageBase<Derived>& Image);

    //! Pixel wise division.
    template <class Derived>
    inline CImage& operator /=(const CImageBase<Derived>& Image);


    //! Adds scalar to all pixels.
    //! - An operator that allows conversion from U to T must be defined!
    template <class U>
    inline CImage& operator +=(const CScalar<U>& c);

    //! Subtracts scalar from all pixels.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CImage& operator -=(const CScalar<U>& c);

    //! Multiplies all pixels by scalar.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CImage& operator *=(const CScalar<U>& c);

    //! Divides all pixels by scalar.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CImage& operator /=(const CScalar<U>& c);


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
    inline tRect rect(const CPoint2i& Position, const CSize2i& Size);
    inline const tRect rect(const CPoint2i& Position, const CSize2i& Size) const;

    //! Returns a specified sub-image (i.e. rectangle).
    inline tRect rect(const CRange& XRange, const CRange& YRange);
    inline const tRect rect(const CRange& XRange, const CRange& YRange) const;

    //! Returns a specified row.
    inline tRow row(tSize y);
    inline const tRow row(tSize y) const;


    //! Fills the image using a given pixel value.
    //! - Returns reference to this.
    inline CImage& fill(const T c);

    //! Fills the entire image including its margin using a given pixel value.
    //! - Returns reference to this.
    inline CImage& fillEntire(const T c);

    //! Pads the image margin with constant value.
    //! - Returns reference to this.
    inline CImage& fillMargin(const T c);

    //! Pads the image margin using a simple mirroring.
    //! - Returns reference to this.
    inline CImage& mirrorMargin();


    //! Replaces all pixels of a given value by a specified value.
    //! - Returns reference to this.
    inline CImage& replace(const T& Value, const T& NewValue);

    //! Absolute value of all pixels.
    //! - Returns reference to this.
    inline CImage& abs();

    //! Clips a range of pixel values.
    //! - Returns reference to this.
    inline CImage& limit(const T& Lower, const T& Upper);

    //! Cuts range of pixel values.
    //! - Returns reference to this.
    inline CImage& cut(const T& Lower, const T& Upper);

    //! Subsamples a given image and stores the result.
    //! - Returns reference to this.
    inline CImage& subSample(const CImage& Image, const tSize k = 2, const tSize l = 2);


    //! Bilinear subpixel value interpolation.
    inline T interpolate(const CPoint3D& Point) const;

    //! Converts a specified color to the image pixel format and range.
    inline T color2Pixel(CColor color) const;

    //! Checks the pixel position.
    //! - Returns 'true' if a specified position is satisfactory.
    inline bool checkPosition(tSize x, tSize y) const;

    //! Serialize - nested version. This method must be used where beginWrite was already called before.
    template <class S>
    void serializeNested(vpl::mod::CChannelSerializer<S>& Writer);

    //! Deserialize - nested version. This method must be used where beginRead was already called before.
    template <class S>
    void deserializeNested(vpl::mod::CChannelSerializer<S>& Reader);

    //! Serializes all class members.
    template <class S>
    void serialize(vpl::mod::CChannelSerializer<S>& Writer);

    //! Deserializes all class members.
    template <class S>
    void deserialize(vpl::mod::CChannelSerializer<S>& Reader);

protected:
    //! Image dimensions.
    CImSize m_Size;

    //! Image margin size.
    tSize m_Margin;

    //! Offset used by subscripting functions.
    tSize m_YOffset;

    //! Offset of the first pixel (0,0) from the beginning of data.
    tSize m_ZeroOffset;

    //! Image data.
    tDataStorage m_DataStorage;
};


// Modify the image compression method with respect to a concrete pixel type.
VPL_SPECIALIZE_ENTITY_COMPRESSION(CImage<tDensityPixel>, vpl::mod::CC_DENSITY)


//=============================================================================
/*
* Methods templates.
*/

// Include file containing methods templates.
#include "Image.hxx"


//=============================================================================
/*
* Basic type definitions.
*/

//! Grayscale image, 8-bits per pixel.
typedef CImage<tPixel8>         CImage8;

//! Grayscale image, 16-bits per pixel.
typedef CImage<tPixel16>        CImage16;

//! Grayscale image, 32-bits per pixel.
typedef CImage<tPixel32>        CImage32;

//! Float image.
typedef CImage<tFloatPixel>     CFImage;

//! Density image.
typedef CImage<tDensityPixel>   CDImage;

//! Color RGB image.
typedef CImage<tRGBPixel>       CRGBImage;

//! Color RGBA image.
typedef CImage<tRGBAPixel>      CRGBAImage;

//! Complex image.
typedef CImage<tComplexPixel>   CComplexImage;


//! Smart pointer to grayscale image, 8-bit per pixel.
typedef CImage8::tSmartPtr          CImage8Ptr;

//! Smart pointer to grayscale image, 16-bit per pixel.
typedef CImage16::tSmartPtr         CImage16Ptr;

//! Smart pointer to grayscale image, 32-bit per pixel.
typedef CImage32::tSmartPtr         CImage32Ptr;

//! Smart pointer to float image.
typedef CFImage::tSmartPtr          CFImagePtr;

//! Smart pointer to density image.
typedef CDImage::tSmartPtr          CDImagePtr;

//! Smart pointer to color RGB image.
typedef CRGBImage::tSmartPtr        CRGBImagePtr;

//! Smart pointer to color RGBA image.
typedef CRGBAImage::tSmartPtr       CRGBAImagePtr;

//! Smart pointer to complex image.
typedef CComplexImage::tSmartPtr    CComplexImagePtr;


} // namespace img
} // namespace vpl

#endif // VPL_IMAGE_H

