//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/07/11                          \n
 *
 * $Id: mdsVolume.h 2110 2012-02-19 15:39:45Z spanel $
 *
 * Description:
 * - Template providing basic volume operations.
 */

#ifndef MDS_VOLUME_H
#define MDS_VOLUME_H

#include <MDSTk/Base/mdsPartedData.h>

#include "mdsImage.h"
#include "mdsVolumeBase.h"
#include "mdsVolumeIterator.h"
#include "mdsVolumeView.h"


namespace mds
{
namespace img
{

// Declare volume traits first...
MDS_VOLUME_TRAITS(CVolume)

//==============================================================================
/*!
 * Class template representing volumetric data.
 * - Parameter T is a voxel type.
 * - Volume data are stored in row-major format. Index of the row represents
 *   y-axis and is generally given as a second parameter of pixel subscripting
 *   functions.
 * - Data allocator should be a class template derived from
 *   mds::base::CDataAllocator<> and it has to adopt reference counting
 *   mechanism similar to the one implemented in mds::base::CRefData<>.
 */
//template <typename T, template <typename> class Allocator = mds::base::CRefData>
template <typename T, template <typename> class Allocator = mds::base::CPartedData>
class CVolume
    : public mds::base::CObject
    , public CVolumeBase<CVolume<T, Allocator> >
    , public mds::mod::CSerializable
{
public:
    // Base class.
    typedef CVolumeBase<CVolume<T, Allocator> > tBase;

    //! Templates that require members of the CVolume class can use
    //! this enum to check the existence.
    enum { CLASS_VOLUME };

    //! Declare smart pointer type tSmartPtr.
    MDS_SHAREDPTR(CVolume);

    //! Voxel type.
    typedef T tVoxel;

    //! Volume data storage type.
    typedef Allocator<T> tDataStorage;

    //! View of the volume (i.e. rectangular box).
    typedef CRectBox<CVolume> tRect;

    //! Volume row (the x coordinate is varying while y and z coordinates are fixed).
    typedef CVolumeRow<CVolume> tRow;

    //! Declare tterator types tIterator and tConstIterator.
    MDS_ITERATOR(CVolume, tVoxel, CVolumeIterator)

    //! Standard method getEntityName().
    MDS_ENTITY_TEMPLATE_NAME("Volume", CPixelTraits<T>::getPixelName())

    //! Standard method getEntityCompression().
    MDS_ENTITY_COMPRESSION(mds::mod::CC_GZIP)
//    MDS_ENTITY_COMPRESSION(mds::mod::CC_RLE16)

public:
    //! Default constructor creates volume of zero size.
    inline CVolume();

    //! Constructor.
    inline CVolume(tSize XSize,
                   tSize YSize,
                   tSize ZSize,
                   tSize Margin = 0
                   );

    //! Constructor.
    inline CVolume(const CSize3i& Size, tSize Margin = 0);

    //! Constructor.
    //! - Creates a subvolume of a given volume.
    //! - Makes own copy of the data.
    CVolume(const CVolume& Volume,
            tSize x,
            tSize y,
            tSize z,
            tSize XSize,
            tSize YSize,
            tSize ZSize
            );

    //! Constructor.
    //! - Creates a subvolume of a given volume.
    //! - Makes only a reference to the data.
    CVolume(const CVolume& Volume,
            tSize x,
            tSize y,
            tSize z,
            tSize XSize,
            tSize YSize,
            tSize ZSize,
            EMakeRef
            );

    //! Constructor.
    //! - Makes own copy of the data.
    CVolume(const tRect& Volume);

    //! Constructor.
    //! - Makes only a reference to the data.
    CVolume(const tRect& Volume, EMakeRef);

    //! Copy constructor.
    //! - Makes own copy of the data.
    CVolume(const CVolume& Volume);

    //! Copy constructor.
    //! - Makes reference to the data.
    CVolume(const CVolume& Volume, EMakeRef);

    //! Destructor.
    virtual ~CVolume();

    //! Resizes the volume data.
    CVolume& create(tSize XSize,
                    tSize YSize,
                    tSize ZSize,
                    tSize Margin = 0
                    );

    //! Resizes the volume data.
    CVolume& create(const CSize3i& Size, tSize Margin = 0);

    //! Creates a subvolume of a given volume.
    //! - Makes own copy of the data.
    CVolume& create(const CVolume& Volume,
                    tSize x,
                    tSize y,
                    tSize z,
                    tSize XSize,
                    tSize YSize,
                    tSize ZSize
                    );

    //! Creates a subvolume of a given volume.
    //! - Makes only a reference to the data.
    CVolume& create(const CVolume& Volume,
                    tSize x,
                    tSize y,
                    tSize z,
                    tSize XSize,
                    tSize YSize,
                    tSize ZSize,
                    EMakeRef
                    );

    //! Creates copy of a given subvolume.
    //! - Makes own copy of the data.
    CVolume& create(const tRect& Volume);

    //! Creates reference to a given subvolume.
    //! - Makes only a reference to the data.
    CVolume& create(const tRect& Volume, EMakeRef);

    //! Creates copy of a volume.
    CVolume& create(const CVolume& Volume);

    //! Creates reference to a given volume.
    CVolume& create(const CVolume& Volume, EMakeRef);
    
    //! Assignment operator.
    virtual CVolume& operator =(const CVolume& Volume);

    //! Conversion between volumes of different types.
    template <class Derived>
    CVolume& convert(const CVolumeBase<Derived>& Volume);


    //! Returns the volume size.
    CSize3i& getSize() { return m_Size; }
    const CSize3i& getSize() const { return m_Size; }

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

    //! Returns the subscripted voxel [x][y][z].
    T& at(tSize x, tSize y, tSize z)
    {
        return m_DataStorage.at(m_ZeroOffset + z * m_ZOffset + y * m_YOffset + x);
    }
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

    //! Returns the subscripted voxel.
    T& at(tSize i)
    {
        return m_DataStorage.at(m_ZeroOffset + i);
    }
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
    inline Function pforEach(Function Func);

    //! Calls a function object for every voxel.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func) const;


    //! Returns a specified sub-volume (i.e. rectangular box).
    inline tRect rect(const CPoint3i& Position, const CSize3i& Size);
    inline const tRect rect(const CPoint3i& Position, const CSize3i& Size) const;

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
    inline CVolume& fill(const T& c);
  
    //! Fills the entire volume including its margin using a given voxel value.
    inline CVolume& fillEntire(const T& c);

    //! Pads the volume margin with constant value.
    inline CVolume& fillMargin(const T& c);

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
                              tSize l = 2,
                              tSize m = 2,
                              tSize n = 2
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
    //! Volume dimensions.
    CSize3i m_Size;

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
MDS_SPECIALIZE_ENTITY_COMPRESSION(CVolume<tDensityPixel>, mds::mod::CC_DENSITY)


//=============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsVolume.hxx"


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


} // namespace img
} // namespace mds

#endif // MDS_VOLUME_H

