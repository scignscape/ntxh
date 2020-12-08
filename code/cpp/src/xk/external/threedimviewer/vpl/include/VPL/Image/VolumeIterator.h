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
 * Date:    2005/02/08                       
 *
 * Description:
 * - Volume iterator definition.
 */

#ifndef VPL_VOLUMEITERATOR_H
#define VPL_VOLUMEITERATOR_H

#include <VPL/Base/IteratorBase.h>


namespace vpl
{

// Declare iterator traits first...
VPL_ITERATOR_TEMPLATE_TRAITS(img, CVolumeIterator)

namespace img
{

//==============================================================================
/*!
 * Iterator used to traverse volume by lines.
 * - Template parameter V is the volume type.
 * - Parameter T is the voxel type.
 */
template <class V, typename T>
class CVolumeIterator : public vpl::base::CIteratorBase<CVolumeIterator<V, T> >
{
public:
    //! Check that type V is a volume. You will see name of this enum somewhere
    //! in compiler error message if the type V is not volume.
    enum { TEMPLATE_PARAMETER_IS_NOT_VOLUME = V::CLASS_VOLUME };

    //! Volume type.
    typedef V tVolume;

    //! Voxel type.
    typedef T tVoxel;

public:
    //! Constructor.
    CVolumeIterator(tVolume& Volume)
        : m_Volume(Volume)
        , m_x(0)
        , m_y(0)
        , m_z(0)
    {}

    //! Destructor.
    ~CVolumeIterator() {}

    //! Returns the current iterator position.
    tSize x() const { return m_x; }
    tSize y() const { return m_y; }
    tSize z() const { return m_z; }

    //! Moves iterator to the next voxel.
    void advance()
    {
        if( ++m_x >= m_Volume.getXSize() )
        {
            m_x = 0;
            if( ++m_y >= m_Volume.getYSize() )
            {
                m_y = 0;
                ++m_z;
            }
        }
    }

    //! Returns true if the iterator points after the end.
    bool atEnd() const
    {
        return (m_z >= m_Volume.getZSize());
    }

    //! Returns the current voxel.
    const tVoxel& value() const
    {
        return m_Volume.at(m_x, m_y, m_z);
    }

    //! Returns reference to the current voxel.
    tVoxel& valueRef() const
    {
        return m_Volume.at(m_x, m_y, m_z);
    }

    //! Returns pointer to the current voxel.
    tVoxel *valuePtr() const
    {
        return m_Volume.getPtr(m_x, m_y, m_z);
    }

    //! Returns size of the volume in voxels.
    tSize getSize() const
    {
        return m_Volume.getXSize() * m_Volume.getYSize() * m_Volume.getZSize();
    }

protected:
    //! Reference to the volume.
    tVolume& m_Volume;

    //! Iterator position.
    tSize m_x, m_y, m_z;

private:
    //! Private assignmet operator.
    CVolumeIterator& operator =(const CVolumeIterator& ) { return this; }
};


} // namespace img
} // namespace vpl

#endif // VPL_VOLUMEITERATOR_H

