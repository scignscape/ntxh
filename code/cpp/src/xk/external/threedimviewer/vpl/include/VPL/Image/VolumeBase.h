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
 * - Base class for all volumes.
 */

#ifndef VPL_VOLUMEBASE_H
#define VPL_VOLUMEBASE_H

#include <VPL/Base/Scalar.h>

#include "Size.h"
#include "Point3.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Traits used to implement curiously recurring template pattern for volumes.
 */
template <typename M>
struct CVolumeTraits
{
    //! Voxel type.
    typedef tNull tVoxel;   
};


//! Helper macro used to declare volume traits before a volume class template.
#define VPL_VOLUME_TRAITS(VolumeClass) \
    template <typename T, template <typename> class A> class VolumeClass; \
    template <typename T, template <typename> class A> \
    struct CVolumeTraits<VolumeClass<T, A> > \
    { \
        typedef T tVoxel; \
    };


//==============================================================================
/*!
 * Base class for all volumes.
 * - Base class takes a template parameter V. This parameter is the type
 *   of the class which derives from it (so called curiously recurring template
 *   pattern).
 */
template <class V>
class CVolumeBase
{
public:
    //! Volume type.
    typedef V tVolume;

    //! Voxel type.
    typedef typename CVolumeTraits<V>::tVoxel tVoxel;

public:
    //! Returns reference to the volume data implementation.
    tVolume& getImpl()
    {
        return *static_cast<tVolume *>(this);
    }
    const tVolume& getImpl() const
    {
        return *static_cast<const tVolume *>(this);
    }

public:
    //! Returns size of the volume.
    CVolSize& getSize() { return getImpl().getSize(); }
    const CVolSize& getSize() const { return getImpl().getSize(); }

    //! Returns the volume size (dimensions).
    tSize getXSize() const { return getImpl().getXSize(); }
    tSize getYSize() const { return getImpl().getYSize(); }
    tSize getZSize() const { return getImpl().getZSize(); }

    //! Returns the volume size (dimensions).
    tSize width() const { return getImpl().width(); }
    tSize height() const { return getImpl().height(); }
    tSize depth() const { return getImpl().depth(); }


    //! Returns offset between two neigbouring voxels in x-axis.
    tSize getXOffset() const { return getImpl().getXOffset(); }

    //! Returns offset between two neigbouring voxels in y-axis.
    tSize getYOffset() const { return getImpl().getYOffset(); }

    //! Returns offset between two neigbouring voxels in z-axis.
    tSize getZOffset() const { return getImpl().getZOffset(); }

    //! Returns the volume Margin size in voxels.
    tSize getMargin() const { return getImpl().getMargin(); }


    //! Returns the subscripted voxel [x][y][z].
    tVoxel& operator ()(tSize x, tSize y, tSize z)
    {
        return getImpl().at(x, y, z);
    }
    const tVoxel& operator ()(tSize x, tSize y, tSize z) const
    {
        return getImpl().at(x, y, z);
    }

    //! Returns the subscripted voxel [x][y][z].
    tVoxel& at(tSize x, tSize y, tSize z)
    {
        return getImpl().at(x, y, z);
    }
    const tVoxel& at(tSize x, tSize y, tSize z) const
    {
        return getImpl().at(x, y, z);
    }

    //! Sets the voxel at the position [x][y][z].
    tVolume& set(tSize x, tSize y, tSize z, const tVoxel& Value)
    {
        return getImpl().set(x, y, z, Value);
    }


    //! Calculates index of a voxel.
    tSize getIdx(tSize x, tSize y, tSize z) const
    {
        return getImpl().getIdx(x, y, z);
    }

    //! Returns the subscripted voxel.
    tVoxel& operator ()(tSize i)
    {
        return getImpl().at(i);
    }
    const tVoxel& operator ()(tSize i) const
    {
        return getImpl().at(i);
    }

    //! Returns the subscripted voxel.
    tVoxel& at(tSize i)
    {
        return getImpl().at(i);
    }
    const tVoxel& at(tSize i) const
    {
        return getImpl().at(i);
    }

    //! Sets the subscripted voxel.
    tVolume& set(tSize i, const tVoxel& Value)
    {
        return getImpl().set(i, Value);
    }


    //! Calls a function object for every voxel.
    template <class Function>
    inline Function forEach(Function Func)
    {
        return getImpl().forEach(Func);
    }

    //! Calls a function object for every voxel.
    template <class Function>
    inline Function forEach(Function Func) const
    {
        return getImpl().forEach(Func);
    }

    //! Calls a function object for every voxel.
    //! - Parallel version.
    template <class Function>
    inline void pforEach(Function Func)
    {
        getImpl().pforEach(Func);
    }

    //! Calls a function object for every voxel.
    //! - Parallel version.
    template <class Function>
    inline void pforEach(Function Func) const
    {
        getImpl().pforEach(Func);
    }

protected:
    //! Default constructor.
    CVolumeBase() {}

    //! Protected copy constructor.
    CVolumeBase(const CVolumeBase&) {}

    //! Assignment operator.
    CVolumeBase& operator =(const CVolumeBase&) { return *this; }
};


} // namespace img
} // namespace vpl

#endif // VPL_VOLUMEBASE_H

