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
 * Date:    2004/07/11                       
 *
 * Description:
 * - Template providing basic volume operations.
 */

#ifndef VPL_VOLUME_H
#define VPL_VOLUME_H

#include <VPL/Base/PartedData.h>

#include "Image.h"
#include "VolumeBase.h"
#include "VolumeIterator.h"
#include "VolumeView.h"

// Check what version of the data allocator should be used
#ifdef VPL_VOLUME_DATA_ALLOCATION_IN_BLOCKS
#   define VPL_VOLUME_DATA_ALLOCATOR vpl::base::CPartedData
#else
#   define VPL_VOLUME_DATA_ALLOCATOR vpl::base::CRefData
#endif


namespace vpl
{
namespace img
{

// Declare volume traits first...
VPL_VOLUME_TRAITS(CVolume)

//==============================================================================
/*!
 * Class template representing volumetric data.
 * - Parameter T is a voxel type.
 * - Volume data are stored in row-major format. Index of the row represents
 *   y-axis and is generally given as a second parameter of pixel subscripting
 *   functions.
 * - Data allocator should be a class template derived from
 *   vpl::base::CDataAllocator<> and it has to adopt reference counting
 *   mechanism similar to the one implemented in vpl::base::CRefData<>.
 */
template <typename T, template <typename> class Allocator = VPL_VOLUME_DATA_ALLOCATOR>
class CVolume
    : public vpl::base::CObject
    , public CVolumeBase<CVolume<T, Allocator> >
    , public vpl::mod::CSerializable
{
public:
    // Base class.
    typedef CVolumeBase<CVolume<T, Allocator> > tBase;

    //! Templates that require members of the CVolume class can use
    //! this enum to check the existence.
    enum { CLASS_VOLUME };



    //! Voxel type.
    typedef T tVoxel;

    //! Volume data storage type.
    typedef Allocator<T> tDataStorage;

    //! View of the volume (i.e. rectangular box).
    typedef CRectBox<CVolume> tRect;

    //! Volume row (the x coordinate is varying while y and z coordinates are fixed).
    typedef CVolumeRow<CVolume> tRow;

    //! Declare smart pointer type tSmartPtr.
    VPL_SHAREDPTR(CVolume);

    //! Declare tterator types tIterator and tConstIterator.
    VPL_ITERATOR(CVolume, tVoxel, CVolumeIterator)

#ifndef SWIG
    //! Standard method getEntityName().
    VPL_ENTITY_TEMPLATE_NAME("Volume", CPixelTraits<T>::getPixelName())
#endif
    //! Standard method getEntityCompression().
    VPL_ENTITY_COMPRESSION(vpl::mod::CC_GZIP)



public:
    //! Default constructor creates volume of zero size.
    inline CVolume();

    //! Constructor that allocates volume data.
    inline CVolume(tSize XSize,
                   tSize YSize,
                   tSize ZSize,
                   tSize Margin = 0
                   );

    //! Constructor that allocates volume data.
    inline CVolume(const CVolSize& Size, tSize Margin = 0);

    //! Constructor that copies a subvolume from a given source volume.
    //! - Uses margin size of the source volume.
    //! - Makes own copy of the data.
    inline CVolume(const CVolume& Volume,
                   const tSize x,
                   const tSize y,
                   const tSize z,
                   const tSize XSize,
                   const tSize YSize,
                   const tSize ZSize
                   );

    //! Constructor that creates a subvolume of a given source volume.
    //! - Makes only a reference to the data.
    inline CVolume(const CVolume& Volume,
                   tSize x,
                   tSize y,
                   tSize z,
                   tSize XSize,
                   tSize YSize,
                   tSize ZSize,
                   EMakeRef
                   );

    //! Constructor creates a copy of a given source subvolume.
    //! - Makes own copy of the data.
    inline CVolume(const tRect& Volume);

    //! Constructor makes a roference to a given subvolume.
    //! - No image data are copied.
    inline CVolume(const tRect& Volume, EMakeRef);

    //! Copy constructor.
    //! - Makes own copy of the data.
    inline CVolume(const CVolume& Volume);

    //! Constructor that makes only reference to the original data.
    //! - No image data are copied.
    inline CVolume(const CVolume& Volume, EMakeRef);

    //! Destructor.
    virtual ~CVolume();

    //! Resizes the volume data.
    inline CVolume& resize(tSize XSize,
                           tSize YSize,
                           tSize ZSize,
                           tSize Margin = 0
                           );

    //! Resizes the volume data.
    inline CVolume& resize(const CVolSize& Size, tSize Margin = 0);

    //! Creates copy of a volume.
    //! - Uses margin size of the source image if -1 is given as the parameter.
    CVolume& copy(const CVolume& Volume, tSize Margin = -1);

    //! Creates a copy of a specified subvolume.
    //! - Uses margin size of the source image if -1 is given as the parameter.
    //! - Makes own copy of the data.
    CVolume& copy(const CVolume& Volume,
                  const tSize x,
                  const tSize y,
                  const tSize z,
                  const tSize XSize,
                  const tSize YSize,
                  const tSize ZSize,
                  const tSize Margin = -1
                  );

    //! Creates copy of a given subvolume.
    //! - Uses margin size of the source image if -1 is given as the parameter.
    CVolume& copy(const tRect& Volume, tSize Margin = -1);

    //! Creates reference to a given volume.
    //! - No volume data are copied.
    inline CVolume& makeRef(const CVolume& Volume);

    //! Creates reference to a subvolume of a given volume.
    //! - No volume data are copied.
    inline CVolume& makeRef(const CVolume& Volume,
                            tSize x,
                            tSize y,
                            tSize z,
                            tSize XSize,
                            tSize YSize,
                            tSize ZSize
                            );

    //! Creates reference to a given subvolume.
    //! - No volume data are copied.
    inline CVolume& makeRef(const tRect& Volume);
    
    //! Assignment operator.
    //! - Copies voxel values from one volume to another.
    virtual CVolume& operator =(const CVolume& Volume);

    //! Conversion between volumes of different types.
    //! - Resizes the current volume according to the source one.
    //! - Uses margin size of the source volume if -1 is given in the parameter.
    template <class Derived>
    CVolume& convert(const CVolumeBase<Derived>& Volume, tSize Margin = -1);


    //! Returns the volume size.
    CVolSize& getSize() { return m_Size; }
    const CVolSize& getSize() const { return m_Size; }

    //! Returns the volume size (dimensions).
    tSize getXSize() const { return m_Size.x(); }
    tSize getYSize() const { return m_Size.y(); }
    tSize getZSize() const { return m_Size.z(); }

    //! Returns the volume size (dimensions).
    tSize width() const { return m_Size.x(); }
    tSize height() const { return m_Size.y(); }
    tSize depth() const { return m_Size.z(); }


    //! Returns offset between two neigbouring voxels in x-axis.
    tSize getXOffset() const { return 1; }

    //! Returns offset between two neigbouring voxels in y-axis.
    tSize getYOffset() const { return m_YOffset; }

    //! Returns offset between two neigbouring voxels in z-axis.
    tSize getZOffset() const { return m_ZOffset; }

    //! Returns the volume Margin size in voxels.
    tSize getMargin() const { return m_Margin; }


    //! Returns the subscripted voxel [x][y][z].
    T& operator ()(tSize x, tSize y, tSize z)
    {
        return m_DataStorage.at(m_ZeroOffset + z * m_ZOffset + y * m_YOffset + x);
    }
    const T& operator ()(tSize x, tSize y, tSize z) const
    {
        return m_DataStorage.at(m_ZeroOffset + z * m_ZOffset + y * m_YOffset + x);
    }

#ifndef SWIG
    //! Returns the subscripted voxel [x][y][z].
    T& at(tSize x, tSize y, tSize z)
    {
        return m_DataStorage.at(m_ZeroOffset + z * m_ZOffset + y * m_YOffset + x);
    }
#endif
    const T& at(tSize x, tSize y, tSize z) const
    {
        return m_DataStorage.at(m_ZeroOffset + z * m_ZOffset + y * m_YOffset + x);
    }


    //! Sets the voxel at the position [x][y][z].
    CVolume& set(tSize x, tSize y, tSize z, const T& Value)
    {
        m_DataStorage.set(m_ZeroOffset + z * m_ZOffset + y * m_YOffset + x, Value);
        return *this;
    }


    //! Calculates index of a voxel.
    tSize getIdx(tSize x, tSize y, tSize z) const
    {
        return z * m_ZOffset + y * m_YOffset + x;
    }

    //! Returns the subscripted voxel.
    T& operator ()(tSize i)
    {
        return m_DataStorage.at(m_ZeroOffset + i);
    }
    const T& operator ()(tSize i) const
    {
        return m_DataStorage.at(m_ZeroOffset + i);
    }

#ifndef SWIG
    //! Returns the subscripted voxel.
    T& at(tSize i)
    {
        return m_DataStorage.at(m_ZeroOffset + i);
    }
#endif // !SWIG
    
    //! Returns the subscripted voxel.
    const T& at(tSize i) const
    {
        return m_DataStorage.at(m_ZeroOffset + i);
    }

    //! Sets the subscripted voxel.
    CVolume& set(tSize i, const T& Value)
    {
        m_DataStorage.set(m_ZeroOffset + i, Value);
        return *this;
    }


    //! Returns pointer to the volume data.
    T *getPtr() { return m_DataStorage.getPtr(m_ZeroOffset); }
    const T *getPtr() const { return m_DataStorage.getPtr(m_ZeroOffset); }

    //! Returns pointer to the given voxel.
    T *getPtr(tSize x, tSize y, tSize z)
    {
        return m_DataStorage.getPtr(m_ZeroOffset + z * m_ZOffset + y * m_YOffset + x);
    }
    const T *getPtr(tSize x, tSize y, tSize z) const
    {
        return m_DataStorage.getPtr(m_ZeroOffset + z * m_ZOffset + y * m_YOffset + x);
    }

    //! Returns pointer to the first element of the volume row.
    //! - x coordinate is taken to be zero.
    T *getRowPtr(tSize y, tSize z)
    {
        return m_DataStorage.getPtr(m_ZeroOffset + z * m_ZOffset + y * m_YOffset);
    }
    const T *getRowPtr(tSize y, tSize z) const
    {
        return m_DataStorage.getPtr(m_ZeroOffset + z * m_ZOffset + y * m_YOffset);
    }


    //! Pixel wise addition.
    template <class Derived>
    inline CVolume& operator +=(const CVolumeBase<Derived>& Volume);

    //! Pixel wise subtraction.
    template <class Derived>
    inline CVolume& operator -=(const CVolumeBase<Derived>& Volume);

    //! Pixel wise product.
    template <class Derived>
    inline CVolume& operator *=(const CVolumeBase<Derived>& Volume);

    //! Pixel wise division.
    template <class Derived>
    inline CVolume& operator /=(const CVolumeBase<Derived>& Volume);


    //! Adds scalar to all pixels.
    //! - An operator that allows conversion from U to T must be defined!
    template <typename U>
    inline CVolume& operator +=(const CScalar<U>& c);

    //! Subtracts scalar from all pixels.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CVolume& operator -=(const CScalar<U>& c);

    //! Multiplies all pixels by scalar.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CVolume& operator *=(const CScalar<U>& c);

    //! Divides all pixels by scalar.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CVolume& operator /=(const CScalar<U>& c);


    //! Calls a function object for every voxel.
    template <class Function>
    inline Function forEach(Function Func);

    //! Calls a function object for every voxel.
    template <class Function>
    inline Function forEach(Function Func) const;

    //! Calls a function object for every voxel.
    //! - Parallel version.
    template <class Function>
    inline void pforEach(Function Func);

    //! Calls a function object for every voxel.
    //! - Parallel version.
    template <class Function>
    inline void pforEach(Function Func) const;


    //! Returns a specified sub-volume (i.e. rectangular box).
    inline tRect rect(const CPoint3i& Position, const CVolSize& Size);
    inline const tRect rect(const CPoint3i& Position, const CVolSize& Size) const;

    //! Returns a specified sub-volume (i.e. rectangular box).
    inline tRect rect(const CRange& XRange,
                      const CRange& YRange,
                      const CRange& ZRange
                      );
    inline const tRect rect(const CRange& XRange,
                            const CRange& YRange,
                            const CRange& ZRange
                            ) const;
    
    //! Returns a specified row.
    inline tRow row(tSize y, tSize z);
    inline const tRow row(tSize y, tSize z) const;


    //! Fills the volume using a given voxel value.
    inline CVolume& fill(const T c);
  
    //! Fills the entire volume including its margin using a given voxel value.
    inline CVolume& fillEntire(const T c);

    //! Pads the volume margin with constant value.
    inline CVolume& fillMargin(const T c);

    //! Pads the volume margin using a simple mirroring.
    inline CVolume& mirrorMargin();


    //! Replaces all voxels of a given value by a specified value.
    inline CVolume& replace(const T& Value, const T& NewValue);

    //! Absolute value of all voxels.
    inline CVolume& abs();

    //! Limits the range of voxel values.
    inline CVolume& limit(const T& Lower, const T& Upper);

    //! Cuts range of voxel values.
    inline CVolume& cut(const T& Lower, const T& Upper);

    //! Subsample the volume.
    inline CVolume& subSample(const CVolume& Volume,
                              const tSize l = 2,
                              const tSize m = 2,
                              const tSize n = 2
                              );


    //! Bilinear subvoxel value interpolation.
    inline T interpolate(const CPoint3D& Point) const;

    //! Converts a specified color to the volume voxel format and range.
    inline T color2Voxel(CColor Color) const;

    //! Checks the voxel position.
    //! - Returns true if a specified position is satisfactory.
    inline bool checkPosition(tSize x, tSize y, tSize z) const;


    //! Cuts the volume using plane XY and saves obtained data to a given
    //! image. Position of the plane is specified by the z coordinate.
    inline bool getPlaneXY(tSize z, CImage<T>& Plane);

    //! Cuts the volume using plane XZ and saves obtained data to a given
    //! image. Position of the plane is specified by the y coordinate.
    inline bool getPlaneXZ(tSize y, CImage<T>& Plane);

    //! Cuts the volume using plane YZ and saves obtained data to a given
    //! image. Position of the plane is specified by the x coordinate.
    inline bool getPlaneYZ(tSize x, CImage<T>& Plane);

    //! Projects a given image data to the volume using a specified plane.
    inline bool setPlaneXY(tSize z, const CImage<T>& Plane);

    //! Projects a given image data to the volume using a specified plane.
    inline bool setPlaneXZ(tSize y, const CImage<T>& Plane);

    //! Projects a given image data to the volume using a specified plane.
    inline bool setPlaneYZ(tSize x, const CImage<T>& Plane);


    //! Serializes all class members.
    template <class S>
    void serialize(vpl::mod::CChannelSerializer<S>& Writer);

    //! Deserializes all class members.
    template <class S>
    void deserialize(vpl::mod::CChannelSerializer<S>& Reader);


    //! Makes the volume dummy which means that only one voxel will be allocated
    //! internaly and all access to data will point to this single voxel.
    //! - You must re-size the volume for the changes to take effect!
    inline CVolume& enableDummyMode(bool Enable);

    //! Returns true if the dummy mode is enabled.
    inline bool isDummy() const;

protected:
    //! Volume dimensions.
    CVolSize m_Size;

    //! Volume margin size.
    tSize m_Margin;

    //! Offsets used by subscripting functions.
    tSize m_YOffset, m_ZOffset;

    //! Offset of the first voxel (0,0,0) from the beginning of data.
    tSize m_ZeroOffset;

    //! Volume data storage.
    tDataStorage m_DataStorage;
};


// Modify the compression method with respect to a concrete voxel type.
VPL_SPECIALIZE_ENTITY_COMPRESSION(CVolume<tDensityPixel>, vpl::mod::CC_DENSITY)


//=============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Volume.hxx"


//=============================================================================
/*
 * Basic type definitions.
 */

//! Grayscale volume, 8-bits per pixel
typedef CVolume<tPixel8>        CVolume8;

//! Grayscale volume, 16-bits per pixel
typedef CVolume<tPixel16>       CVolume16;

//! Grayscale volume, 32-bits per pixel
typedef CVolume<tPixel32>       CVolume32;

//! Float volume
typedef CVolume<tFloatPixel>    CFVolume;

//! Density volume
typedef CVolume<tDensityPixel>  CDVolume;

//! Color RGB volume
typedef CVolume<tRGBPixel>      CRGBVolume;

//! Color RGBA volume
typedef CVolume<tRGBAPixel>     CRGBAVolume;


//! Grayscale volume, 8-bit per pixel
typedef CVolume8::tSmartPtr     CVolume8Ptr;

//! Grayscale volume, 16-bit per pixel
typedef CVolume16::tSmartPtr    CVolume16Ptr;

//! Grayscale volume, 32-bit per pixel
typedef CVolume32::tSmartPtr    CVolume32Ptr;

//! Float volume
typedef CFVolume::tSmartPtr     CFVolumePtr;

//! Density volume
typedef CDVolume::tSmartPtr     CDVolumePtr;

//! Color RGB volume
typedef CRGBVolume::tSmartPtr   CRGBVolumePtr;

//! Color RGBA volume
typedef CRGBAVolume::tSmartPtr  CRGBAVolumePtr;


} // namespace img
} // namespace vpl

#endif // VPL_VOLUME_H

