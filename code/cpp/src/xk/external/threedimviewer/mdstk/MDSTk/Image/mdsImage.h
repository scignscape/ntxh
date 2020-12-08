//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/08                          \n
 *
 * $Id: mdsImage.h 2099 2012-02-17 00:24:16Z spanel $
 *
 * Description:
 * - Template providing basic image operations.
 */

#ifndef MDS_IMAGE_H
#define MDS_IMAGE_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Base/mdsMemory.h>
#include <MDSTk/Base/mdsRefData.h>
//#include <MDSTk/Base/mdsSHMData.h>
#include <MDSTk/Base/mdsSharedPtr.h>
#include <MDSTk/Base/mdsRange.h>
#include <MDSTk/Math/mdsBase.h>
#include <MDSTk/Module/mdsSerializer.h>
//#include <MDSTk/Module/mdsSHMSerializer.h>

#include "mdsImageBase.h"
#include "mdsImageIterator.h"
#include "mdsImageFunctional.h"
#include "mdsImageView.h"
#include "mdsPixelConversions.h"
#include "mdsColor.h"


namespace mds
{
namespace img
{

// Declare image traits first...
MDS_IMAGE_TRAITS(CImage)

//==============================================================================
/*!
 * Class template representing 2D image data.
 * - Parameter T is image pixel type.
 * - Image data are stored in row-major format. Index of the row represents
 *   y-axis and is generally given as a second parameter of pixel subscripting
 *   functions.
 * - Data allocator should be a class template derived from
 *   mds::base::CDataAllocator<> and it has to adopt reference counting
 *   mechanism similar to the one implemented in mds::base::CRefData<>.
 */
template <typename T, template <typename> class Allocator = mds::base::CRefData>
class CImage
    : public mds::base::CObject
    , public CImageBase<CImage<T, Allocator> >
    , public mds::mod::CSerializable
{
public:
    //! Base class
    typedef CImageBase<CImage<T, Allocator> > tBase;

    //! Templates that require members of the CImage class may use
    //! this enum to check the existence.
    enum { CLASS_IMAGE };

    //! Declare smart pointer type tSmartPtr.
    MDS_SHAREDPTR(CImage);

    //! Image pixel type.
    typedef T tPixel;

    //! Image data storage type.
    typedef Allocator<T> tDataStorage;

    //! View of the image (i.e. rectangle).
    typedef CRect<CImage> tRect;

    //! Image row (the x coordinate is varying while the y is fixed).
    typedef CImageRow<CImage> tRow;

    //! Declare iterator types tIterator and tConstIterator.
    MDS_ITERATOR(CImage, tPixel, CImageIterator)

    // Image serialization.
    MDS_ENTITY_TEMPLATE_NAME("Image", CPixelTraits<T>::getPixelName())

    //! Standard method getEntityCompression().
    MDS_ENTITY_COMPRESSION(mds::mod::CC_GZIP)
//    MDS_ENTITY_COMPRESSION(mds::mod::CC_RLE16)

public:
    //! Default constructor creates image of zero size.
    inline CImage();

    //! Constructor.
    inline CImage(tSize XSize, tSize YSize, tSize Margin = 0);

    //! Constructor.
    inline CImage(const CSize2i& Size, tSize Margin = 0);

    //! Constructor.
    //! - Creates a subimage of a given image.
    //! - Makes own copy of the data.
    CImage(const CImage& Image,
           tSize x,
           tSize y,
           tSize XSize,
           tSize YSize
           );

    //! Constructor.
    //! - Creates a subimage of a given image.
    //! - Makes only reference to the data.
    CImage(const CImage& Image,
           tSize x,
           tSize y,
           tSize XSize,
           tSize YSize,
           EMakeRef
           );

    //! Constructor.
    //! - Makes own copy of the data.
    CImage(const tRect& Image);

    //! Constructor.
    //! - Makes only a reference to the data.
    CImage(const tRect& Image, EMakeRef);

    //! Copy constructor.
    //! - Makes own copy of the data.
    CImage(const CImage& Image);

    //! Copy constructor.
    //! - Only reference to the original data.
    CImage(const CImage& Image, EMakeRef);

    //! Destructor.
    virtual ~CImage();

    //! Resizes the image.
    CImage& create(tSize XSize, tSize YSize, tSize Margin = 0);

    //! Resizes the image data.
    CImage& create(const CSize2i& Size, tSize Margin = 0);

    //! Creates subimage of a given image.
    //! - Makes own copy of the data.
    CImage& create(const CImage& Image,
                   tSize x,
                   tSize y,
                   tSize XSize,
                   tSize YSize
                   );

    //! Creates subimage of a given image.
    //! - Makes only reference to the data.
    inline CImage& create(const CImage& Image,
                          tSize x,
                          tSize y,
                          tSize XSize,
                          tSize YSize,
                          EMakeRef
                          );

    //! Creates copy of a given image rectangle.
    //! - Makes own copy of the data.
    CImage& create(const tRect& Image);

    //! Creates reference to a given image rectangle.
    //! - Makes only a reference to the data.
    CImage& create(const tRect& Image, EMakeRef);

    //! Creates copy of an image.
    CImage& create(const CImage& Image);

    //! Creates reference to an image.
    CImage& create(const CImage& Image, EMakeRef);

    //! Assignment operator.
    CImage& operator =(const CImage& Image);

    //! Conversion of images of different types.
    template <typename Derived>
    CImage& convert(const CImageBase<Derived>& Image);


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

    //! Returns reference to the pixel [x][y].
    T& at(tSize x, tSize y)
    {
        return m_DataStorage.at(m_ZeroOffset + y * m_YOffset + x);
    }
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

    //! Returns the subscripted pixel.
    T& at(tSize i)
    {
        return m_DataStorage.at(m_ZeroOffset + i);
    }
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
    inline CImage& fill(const T& c);

    //! Fills the entire image including its margin using a given pixel value.
    //! - Returns reference to this.
    inline CImage& fillEntire(const T& c);

    //! Pads the image margin with constant value.
    //! - Returns reference to this.
    inline CImage& fillMargin(const T& c);

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
    inline CImage& subSample(const CImage& Image, tSize k = 2, tSize l = 2);


    //! Bilinear subpixel value interpolation.
    inline T interpolate(const CPoint3D& Point) const;

    //! Converts a specified color to the image pixel format and range.
    inline T color2Pixel(CColor color) const;

    //! Checks the pixel position.
    //! - Returns 'true' if a specified position is satisfactory.
    inline bool checkPosition(tSize x, tSize y) const;


    // Serializes all class members.
    // - Serialization over a shared memory.
//    void serialize(mds::mod::CSHMSerializer& Writer);

    // Deserializes all class members.
    // - Serialization over a shared memory.
//    void deserialize(mds::mod::CSHMSerializer& Reader);

    //! Serializes all class members.
    template <class S>
    void serialize(mds::mod::CChannelSerializer<S>& Writer);

    //! Deserializes all class members.
    template <class S>
    void deserialize(mds::mod::CChannelSerializer<S>& Reader);

protected:
    //! Image dimensions.
    CSize2i m_Size;

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
MDS_SPECIALIZE_ENTITY_COMPRESSION(CImage<tDensityPixel>, mds::mod::CC_DENSITY)


//=============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates.
#include "mdsImage.hxx"


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

//! Smart pointer to complex image.
typedef CComplexImage::tSmartPtr    CComplexImagePtr;


} // namespace img
} // namespace mds

#endif // MDS_IMAGE_H

