//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2011 by 3Dim Laboratory s.r.o. \n
 *
 * Author:  info@3dim-laboratory.cz             \n
 * Date:    2011/12/30                          \n
 *
 * $Id:$
 *
 * Description:
 * - Templates providing views of an existing volume.
 */

#ifndef MDS_VolumeView_H
#define MDS_VolumeView_H

#include <MDSTk/Base/mdsRange.h>
#include <MDSTk/Math/mdsVectorBase.h>

#include "mdsVolumeBase.h"
#include "mdsPoint3.h"
#include "mdsSize.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Base class for all classes providing a view of an existing volume.
 */
struct CVolumeView
{
    //! Simple tag of "volume view" classes.
    enum { CLASS_VOLUME_VIEW };
};


//==============================================================================
/*!
 * Class template representing a rectangular box within an existing volume.
 * - Parameter V is a volume type.
 */
template <class V>
class CRectBox : public CVolumeView, public CVolumeBase<CRectBox<V> >
{
public:
    //! Base class.
    typedef CVolumeBase<CRectBox<V> > tBase;

    //! Check that V is a volume. You will see name of this enum somewhere
    //! in compiler error message if the type V is not volume.
    enum { TEMPLATE_PARAMETER_IS_NOT_VOLUME = V::CLASS_VOLUME };

    //! Volume type.
    typedef V tVolume;

    //! Voxel type.
    typedef typename V::tVoxel tVoxel;

public:
    //! Constructor...
    inline CRectBox(const tVolume& Volume,
                    tSize x,
                    tSize y,
                    tSize z,
                    tSize XSize,
                    tSize YSize,
                    tSize ZSize
                    );

    //! Yet another constructor...
    inline CRectBox(const tVolume& Volume, const CPoint3i& Pos, const CSize3i& Size);

    //! Yet another constructor...
    inline CRectBox(const tVolume& Volume,
                    const CRange& XRange,
                    const CRange& YRange,
                    const CRange& ZRange
                    );

    //! Copy constructor.
    inline CRectBox(const CRectBox& Box);

    //! Returns size of the rectangle.
    CSize3i& getSize() { return m_Size; }
    const CSize3i& getSize() const { return m_Size; }

    //! Returns position of the left upper corner.
    CPoint3i& getPos() { return m_Pos; }
    const CPoint3i& getPos() const { return m_Pos; }

    //! Returns reference to the original volume.
    tVolume& getVolumeRef() const { return m_Volume; }


    //! Returns the volume size (dimensions).
    tSize getXSize() const { return m_Size.getXSize(); }
    tSize getYSize() const { return m_Size.getYSize(); }
    tSize getZSize() const { return m_Size.getZSize(); }

    //! Returns the volume size (dimensions).
    tSize width() const { return m_Size.width(); }
    tSize height() const { return m_Size.height(); }
    tSize depth() const { return m_Size.depth(); }


    //! Returns offset between two neigbouring voxels in x-axis.
    tSize getXOffset() const { return m_Volume.getXOffset(); }

    //! Returns offset between two neigbouring voxels in y-axis.
    tSize getYOffset() const { return m_Volume.getYOffset(); }

    //! Returns offset between two neigbouring voxels in z-axis.
    tSize getZOffset() const { return m_Volume.getZOffset(); }

    //! Returns the volume Margin size in voxels.
    tSize getMargin() const { return m_Volume.getMargin(); }


    //! Returns the subscripted voxel [x][y][z].
    tVoxel& operator ()(tSize x, tSize y, tSize z)
    {
        return m_Volume.at(x + m_Pos.x(), y + m_Pos.y(), z + m_Pos.z());
    }
    const tVoxel& operator ()(tSize x, tSize y, tSize z) const
    {
        return m_Volume.at(x + m_Pos.x(), y + m_Pos.y(), z + m_Pos.z());
    }

    //! Returns the voxel [x][y][z].
    tVoxel& at(tSize x, tSize y, tSize z)
    {
        return m_Volume.at(x + m_Pos.x(), y + m_Pos.y(), z + m_Pos.z());
    }
    const tVoxel& at(tSize x, tSize y, tSize z) const
    {
        return m_Volume.at(x + m_Pos.x(), y + m_Pos.y(), z + m_Pos.z());
    }

    //! Sets the voxel at the position [x][y][z].
    CRectBox& set(tSize x, tSize y, tSize z, const tVoxel& Value)
    {
        m_Volume.set(x + m_Pos.x(), y + m_Pos.y(), z + m_Pos.z(), Value);
        return *this;
    }


    //! Calculates index of the voxel [x][y][z].
    tSize getIdx(tSize x, tSize y, tSize z) const
    {
        return m_Volume.getIdx(x + m_Pos.x(), y + m_Pos.y(), z + m_Pos.z());
    }

    //! Returns the subscripted voxel.
    tVoxel& operator ()(tSize i)
    {
        return m_Volume.at(i);
    }
    const tVoxel& operator ()(tSize i) const
    {
        return m_Volume.at(i);
    }

    //! Returns the subscripted voxel.
    tVoxel& at(tSize i)
    {
        return m_Volume.at(i);
    }
    const tVoxel& at(tSize i) const
    {
        return m_Volume.at(i);
    }

    //! Sets the subsripted voxel.
    CRectBox& set(tSize i, const tVoxel& Value)
    {
        m_Volume.set(i, Value);
        return *this;
    }


    //! Voxel wise addition.
    template <class Derived>
    inline CRectBox& operator +=(const CVolumeBase<Derived>& Volume);

    //! Voxel wise subtraction.
    template <class Derived>
    inline CRectBox& operator -=(const CVolumeBase<Derived>& Volume);

    //! Voxel wise product.
    template <class Derived>
    inline CRectBox& operator *=(const CVolumeBase<Derived>& Volume);

    //! Voxel wise division.
    template <class Derived>
    inline CRectBox& operator /=(const CVolumeBase<Derived>& Volume);


    //! Adds scalar to all voxels.
    //! - An operator that allows conversion from U to T must be defined!
    template <typename U>
    inline CRectBox& operator +=(const U& c);

    //! Subtracts scalar from all voxels.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CRectBox& operator -=(const U& c);

    //! Multiplies all voxels by scalar.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CRectBox& operator *=(const U& c);

    //! Divides all voxels by scalar.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CRectBox& operator /=(const U& c);


    //! Calls a function object for every voxel in the box.
    template <class Function>
    inline Function forEach(Function Func);

    //! Calls a function object for every voxel in the box.
    template <class Function>
    inline Function forEach(Function Func) const;

    //! Calls a function object for every voxel in the box.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func);

    //! Calls a function object for every voxel in the box.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func) const;


    //! Fills the box using a given voxel value.
    inline CRectBox& fill(const tVoxel& c);

    //! Fills the box using a given input buffer.
    void copyFrom(const tVoxel *pSrc);

    //! Copies the box data to the output buffer.
    void copyTo(tVoxel *pDst) const;
    
protected:
    //! Coordinates of the box origin.
    CPoint3i m_Pos;

    //! Size of the box.
    CSize3i m_Size;

    //! Reference to the original volume.
    tVolume& m_Volume;

protected:
    //! Proctected assignment operator.
    CRectBox& operator =(const CRectBox&) { return *this; }
};


//==============================================================================
/*!
 * Class template representing a single row of an existing volume.
 * - Parameter V is a volume type.
 */
template <class V>
class CVolumeRow : public CVolumeView, public mds::math::CVectorBase<CVolumeRow<V> >
{
public:
    //! Base class.
    typedef mds::math::CVectorBase<CVolumeRow<V> > tBase;

    //! Check that V is a volume. You will see name of this enum somewhere
    //! in compiler error message if the type V is not volume.
    enum { TEMPLATE_PARAMETER_IS_NOT_VOLUME = V::CLASS_VOLUME };

    //! Volume type.
    typedef V tVolume;

    //! Voxel type.
    typedef typename V::tVoxel tVoxel;

public:
    //! Constructor.
    inline CVolumeRow(const tVolume& Volume, tSize y, tSize z);

    //! Copy constructor.
    inline CVolumeRow(const CVolumeRow& Row);

    //! Returns the row size.
    tSize getSize() const { return m_Volume.getXSize(); }

    //! Returns the row size.
    tSize size() const { return m_Volume.width(); }

    //! Returns stride between two neigbouring elements.
    tSize getStride() const { return m_Volume.getXOffset(); }


    //! Returns a subscripted voxel of the row.
    tVoxel& operator ()(tSize x)
    {
        return m_Volume.at(x, m_y, m_z);
    }
    const tVoxel& operator ()(tSize x) const
    {
        return m_Volume.at(x, m_y, m_z);
    }

    //! Returns a subscripted voxel of the row.
    tVoxel& at(tSize x)
    {
        return m_Volume.at(x, m_y, m_z);
    }
    const tVoxel& at(tSize x) const
    {
        return m_Volume.at(x, m_y, m_z);
    }

    //! Changes value of a voxel in the row.
    CVolumeRow& set(tSize x, const tVoxel& Value)
    {
        m_Volume.set(x, m_y, m_z, Value);
        return *this;
    }


    //! Voxel wise addition.
    template <class Derived>
    inline CVolumeRow& operator +=(const mds::math::CVectorBase<Derived>& Row);

    //! Voxel wise subtraction.
    template <class Derived>
    inline CVolumeRow& operator -=(const mds::math::CVectorBase<Derived>& Row);

    //! Voxel wise product.
    template <class Derived>
    inline CVolumeRow& operator *=(const mds::math::CVectorBase<Derived>& Row);

    //! Voxel wise division.
    template <class Derived>
    inline CVolumeRow& operator /=(const mds::math::CVectorBase<Derived>& Row);


    //! Adds scalar to all voxels.
    //! - An operator that allows conversion from U to T must be defined!
    template <typename U>
    inline CVolumeRow& operator +=(const U& c);

    //! Subtracts scalar from all voxels.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CVolumeRow& operator -=(const U& c);

    //! Multiplies all voxels by scalar.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CVolumeRow& operator *=(const U& c);

    //! Divides all voxels by scalar.
    //! - An operator that allows conversion U -> T must be defined!
    template <typename U>
    inline CVolumeRow& operator /=(const U& c);


    //! Calls a function object for every voxel in the row.
    template <class Function>
    inline Function forEach(Function Func);

    //! Calls a function object for every voxel in the row.
    template <class Function>
    inline Function forEach(Function Func) const;

    //! Calls a function object for every voxel in the row.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func);

    //! Calls a function object for every voxel in the row.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func) const;


    //! Fills the row using a given voxel value.
    inline CVolumeRow& fill(const tVoxel& c);

    //! Fills the row using a given input buffer.
    void copyFrom(const tVoxel *pSrc);

    //! Copies the row data to the output buffer.
    void copyTo(tVoxel *pDst) const;
    
protected:
    //! Coordinates of the volume row.
    tSize m_y, m_z;

    //! Reference to the original volume.
    tVolume& m_Volume;

protected:
    //! Proctected assignment operator.
    CVolumeRow& operator =(const CVolumeRow&) { return *this; }
};


//=============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsVolumeView.hxx"


} // namespace img
} // namespace mds

#endif // MDS_VolumeView_H
