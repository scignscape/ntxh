//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2010 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/18                          \n
 *
 * $Id: mdsCvImage.h 2113 2012-02-20 08:38:12Z spanel $
 *
 * Description:
 * - Class template providing image representation based on OpenCV library.
 */

#ifndef MDS_CvImage_H
#define MDS_CvImage_H

#include <MDSTk/Base/mdsSetup.h>

#ifdef MDS_OPENCV_ENABLED

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Base/mdsMemory.h>
#include <MDSTk/Base/mdsSharedPtr.h>
#include <MDSTk/Math/mdsBase.h>
#include <MDSTk/Module/mdsSerializer.h>

#include "mdsImageBase.h"
#include "mdsImageIterator.h"
#include "mdsImageFunctional.h"
#include "mdsImageView.h"
#include "mdsPoint3.h"
#include "mdsPixelConversions.h"
#include "mdsColor.h"
#include "mdsCvImageRef.h"

// OpenCV
#include <cv.h>


namespace mds
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
    : public mds::base::CObject
    , public CImageBase<CvImage<T> >
    , public mds::mod::CSerializable
{
public:
    //! Base class
    typedef CImageBase<CvImage<T> > tBase;

    //! Templates that require members of an image class may use
    //! this enum to check the existence.
    enum { CLASS_IMAGE };

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CvImage);

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
    MDS_ITERATOR(CvImage, tPixel, CImageIterator);

    // Image serialization.
    MDS_ENTITY_TEMPLATE_NAME("Image", CPixelTraits<T>::getPixelName());

    //! Standard method getEntityCompression().
    MDS_ENTITY_COMPRESSION(mds::mod::CC_GZIP);

public:
    //! Default constructor creates a new image having zero size.
    CvImage();

    //! Constructor.
    CvImage(tSize XSize, tSize YSize, tSize Margin = 0);

    //! Constructor.
    inline CvImage(const CSize2i& Size, tSize Margin = 0);

    //! Constructor.
    //! - Creates a subimage of a given image.
    //! - Makes own copy of the data.
    CvImage(const CvImage& Image,
           tSize x,
           tSize y,
           tSize XSize,
           tSize YSize
           );

    //! Constructor.
    //! - Creates a subimage of a given image.
    //! - Makes reference to the data.
    CvImage(const CvImage& Image,
           tSize x,
           tSize y,
           tSize XSize,
           tSize YSize,
           EMakeRef
           );

    //! Constructor.
    //! - Makes own copy of the data.
    CvImage(const tRect& Image);

    //! Constructor.
    //! - Makes only a reference to the data.
    CvImage(const tRect& Image, EMakeRef);

    //! Copy constructor.
    //! - Makes own copy of the data.
    CvImage(const CvImage& Image);

    //! Direct constructor from OpenCV image.
    //! - Takes full control over the image including deallocation of the memory.
    inline CvImage(IplImage *pImage);

    //! Copy constructor.
    //! - Makes reference to the data.
    CvImage(const CvImage& Image, EMakeRef);

    //! Destructor.
    virtual ~CvImage();

    //! Creates a new image.
    CvImage& create(tSize XSize, tSize YSize, tSize Margin = 0);

    //! Creates a new image.
    CvImage& create(const CSize2i& Size, tSize Margin = 0);

    //! Creates a subimage of a given image.
    //! - Makes own copy of the data.
    CvImage& create(const CvImage& Image,
                    tSize x,
                    tSize y,
                    tSize XSize,
                    tSize YSize
                    );

    //! Creates a subimage of a given image.
    //! - Makes reference to the data.
    CvImage& create(const CvImage& Image,
                    tSize x,
                    tSize y,
                    tSize XSize,
                    tSize YSize,
                    EMakeRef
                    );

    //! Creates copy of a given image rectangle.
    //! - Makes own copy of the data.
    CvImage& create(const tRect& Image);

    //! Creates reference to a given image rectangle.
    //! - Makes only a reference to the data.
    CvImage& create(const tRect& Image, EMakeRef);

    //! Creates a new image.
    //! - Makes own copy of the data.
    CvImage& create(const CvImage& Image);

    //! Creates image from OpenCV image.
    //! - Takes full control over the image including deallocation of the memory.
    //! - Returns reference to this.
    CvImage& create(IplImage *pImage);

    //! Creates a new image.
    //! - Makes reference to the data of a given image.
    CvImage& create(const CvImage& Image, EMakeRef);

    //! Assignment operator.
    CvImage& operator =(const CvImage& Image);

    //! Assignment operator.
    //! - Takes full control over OpenCV image including deallocation of the memory.
    inline CvImage& operator=(IplImage *pImage);

    //! Conversion of images of different types.
    template <typename Derived>
    CvImage& convert(const CImageBase<Derived>& Image);


    //! Returns pointer to the underlying OpenCV image.
    //! - The returned image represents image data including the margin!
    const IplImage *asIpl() const { return m_Data.asIpl(); }
    IplImage *asIpl() { return m_Data.asIpl(); }

    //! Returns size of the rectangle.
    CSize2i getSize() const { return CSize2i(getXSize(), getYSize()); }

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
    inline Function pforEach(Function Func);

    //! Calls function object for every image pixel.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func) const;


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
    inline CvImage& fill(const T& c);

    //! Fills the entire image including its margin using a given pixel value.
    //! - Returns reference to this.
    inline CvImage& fillEntire(const T& c);

    //! Pads the image margin with constant value.
    //! - Returns reference to this.
    inline CvImage& fillMargin(const T& c);

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
    inline CvImage& subSample(const CvImage& Image, tSize k = 2, tSize l = 2);


    //! Bilinear subpixel value interpolation.
    inline T interpolate(const CPoint3D& Point) const;

    //! Converts a specified color to the image pixel format and range.
    inline T color2Pixel(CColor color) const;

    //! Checks the pixel position.
    //! - Returns 'true' if a specified position is satisfactory.
    inline bool checkPosition(tSize x, tSize y) const;


    //! Serializes all class members.
    template <class S>
    void serialize(mds::mod::CChannelSerializer<S>& Writer);

    //! Deserializes all class members.
    template <class S>
    void deserialize(mds::mod::CChannelSerializer<S>& Reader);

protected:
    //! Image margin.
    tSize m_Margin;

    //! Image data.
    tDataStorage m_Data;

    //! Direct pointer to the image data.
    T *m_pData;
};


// Modify the image compression method with respect to a concrete pixel type.
MDS_SPECIALIZE_ENTITY_COMPRESSION(CvImage<tDensityPixel>, mds::mod::CC_DENSITY);


//=============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates.
#include "mdsCvImage.hxx"


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
} // namespace mds

#endif // MDS_OPENCV_ENABLED
#endif // MDS_CvImage_H

