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


//=============================================================================
/*
 * Implementation of the vpl::img::CVolume class.
 */

template <typename T, template <typename> class A>
inline CVolume<T,A>::CVolume()
    : m_Size(0, 0, 0)
    , m_Margin(0)
    , m_YOffset(0)
    , m_ZOffset(0)
    , m_ZeroOffset(0)
    , m_DataStorage(0)
{
}


template <typename T, template <typename> class A>
inline CVolume<T,A>::CVolume(tSize XSize,
                             tSize YSize,
                             tSize ZSize,
                             tSize Margin
                             )
    : m_DataStorage(EMPTY_CONST)
{
    resize(XSize, YSize, ZSize, Margin);
}


template <typename T, template <typename> class A>
inline CVolume<T,A>::CVolume(const CVolSize& Size, tSize Margin)
    : m_DataStorage(EMPTY_CONST)
{
    resize(Size, Margin);
}


template <typename T, template <typename> class A>
inline CVolume<T,A>::CVolume(const CVolume<T,A>& Volume,
                             const tSize x,
                             const tSize y,
                             const tSize z,
                             const tSize XSize,
                             const tSize YSize,
                             const tSize ZSize
                             )
    : m_DataStorage(EMPTY_CONST)
{
    VPL_ASSERT(x >= 0 && XSize >= 0 && x < Volume.m_Size.x()
               && y >= 0 && YSize >= 0 && y < Volume.m_Size.y()
               && z >= 0 && ZSize >= 0 && z < Volume.m_Size.z());

    copy(Volume, x, y, z, XSize, YSize, ZSize, -1);
}


template <typename T, template <typename> class A>
inline CVolume<T,A>::CVolume(const CVolume<T,A>& Volume,
                             tSize x,
                             tSize y,
                             tSize z,
                             tSize XSize,
                             tSize YSize,
                             tSize ZSize,
                             EMakeRef
                             )
    : m_Margin(Volume.m_Margin)
    , m_YOffset(Volume.m_YOffset)
    , m_ZOffset(Volume.m_ZOffset)
    , m_ZeroOffset(Volume.m_ZeroOffset)
    , m_DataStorage(Volume.m_DataStorage, REFERENCE)
{
    VPL_ASSERT(x >= 0 && XSize >= 0 && x < Volume.m_Size.x()
               && y >= 0 && YSize >= 0 && y < Volume.m_Size.y()
               && z >= 0 && ZSize >= 0 && z < Volume.m_Size.z());

    // Image size
    m_Size.x() = vpl::math::getMin(x + XSize, Volume.m_Size.x()) - x;
    m_Size.y() = vpl::math::getMin(y + YSize, Volume.m_Size.y()) - y;
    m_Size.z() = vpl::math::getMin(z + ZSize, Volume.m_Size.z()) - z;

    // Image data
    m_ZeroOffset += z * m_ZOffset + y * m_YOffset + x;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>::CVolume(const tRect& Volume)
    : m_DataStorage(EMPTY_CONST)
{
    copy(Volume, -1);
}


template <typename T, template <typename> class A>
inline CVolume<T,A>::CVolume(const tRect& Volume, EMakeRef)
    : m_Size(Volume.getSize())
    , m_Margin(Volume.getVolumeRef().m_Margin)
    , m_YOffset(Volume.getVolumeRef().m_YOffset)
    , m_ZOffset(Volume.getVolumeRef().m_ZOffset)
    , m_ZeroOffset(Volume.getVolumeRef().m_ZeroOffset)
    , m_DataStorage(Volume.getVolumeRef().m_DataStorage, REFERENCE)
{
    // Image data
    m_ZeroOffset += Volume.getPos().z() * m_ZOffset + Volume.getPos().y() * m_YOffset + Volume.getPos().x();
}


// Copy constructor
template <typename T, template <typename> class A>
inline CVolume<T,A>::CVolume(const CVolume<T,A>& Volume)
    : vpl::base::CObject()
    , tBase()
    , m_DataStorage(EMPTY_CONST)
{
    copy(Volume, -1);
}


template <typename T, template <typename> class A>
inline CVolume<T,A>::CVolume(const CVolume<T,A>& Volume, EMakeRef)
    : m_Size(Volume.m_Size)
    , m_Margin(Volume.m_Margin)
    , m_YOffset(Volume.m_YOffset)
    , m_ZOffset(Volume.m_ZOffset)
    , m_ZeroOffset(Volume.m_ZeroOffset)
    , m_DataStorage(Volume.m_DataStorage, REFERENCE)
{
}


// Destructor
template <typename T, template <typename> class A>
CVolume<T,A>::~CVolume()
{
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::resize(tSize XSize,
                                          tSize YSize,
                                          tSize ZSize,
                                          tSize Margin
                                          )
{
    VPL_ASSERT(Margin >= 0);

    m_Margin = Margin;
    tSize Margins = 2 * Margin; // m_Margin * 2

    // Reallocate the data
	m_Size.x() = XSize;
	m_Size.y() = YSize;
	m_Size.z() = ZSize;
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.resize(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::resize(const CVolSize& Size, tSize Margin)
{
    VPL_ASSERT(Margin >= 0);

    m_Margin = Margin;
    tSize Margins = 2 * Margin; // m_Margin * 2

    // Reallocate the data
    m_Size = Size;
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.resize(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    return *this;
}


template <typename T, template <typename> class A>
CVolume<T,A>& CVolume<T,A>::copy(const CVolume<T,A>& Volume, tSize Margin)
{
    // Margin size
    m_Margin = (Margin < 0) ? Volume.m_Margin : Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Reallocate the data
    m_Size = Volume.m_Size;
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.resize(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    // Image size
    const tSize MCount = vpl::math::getMin(m_Margin, Volume.m_Margin);
    const tSize XCount = m_Size.x() + MCount;
    const tSize YCount = m_Size.y() + MCount;
    const tSize ZCount = m_Size.z() + MCount;
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Volume.getXOffset();

    // Copy the data
#pragma omp parallel for schedule(static) default(none) shared(Volume) if(XCount * YCount * ZCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = -MCount; k < ZCount; ++k )
    {
        for( tSize j = -MCount; j < YCount; ++j )
        {
            tSize idx1 = getIdx(-MCount, j, k);
            tSize idx2 = Volume.getIdx(-MCount, j, k);
            for( tSize i = -MCount; i < XCount; ++i, idx1 += Offset1, idx2 += Offset2 )
            {
                at(idx1) = Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
CVolume<T,A>& CVolume<T,A>::copy(const CVolume<T,A>& Volume,
                                 const tSize x,
                                 const tSize y,
                                 const tSize z,
                                 const tSize XSize,
                                 const tSize YSize,
                                 const tSize ZSize,
                                 const tSize Margin
                                 )
{
    // Check the position
    VPL_CHECK(x >= 0 && XSize >= 0 && x < Volume.m_Size.x()
              && y >= 0 && YSize >= 0 && y < Volume.m_Size.y()
              && z >= 0 && ZSize >= 0 && z < Volume.m_Size.z(), return *this);

    // Margin size
    m_Margin = (Margin < 0) ? Volume.m_Margin : Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Size of the image
    m_Size.x() = vpl::math::getMin(x + XSize, Volume.m_Size.x()) - x;
    m_Size.y() = vpl::math::getMin(y + YSize, Volume.m_Size.y()) - y;
    m_Size.z() = vpl::math::getMin(z + ZSize, Volume.m_Size.z()) - z;

    // Reallocate the data
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.resize(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    // Image size
    const tSize MCount = vpl::math::getMin(m_Margin, Volume.m_Margin);
    const tSize XCount = m_Size.x() + MCount;
    const tSize YCount = m_Size.y() + MCount;
    const tSize ZCount = m_Size.z() + MCount;
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Volume.getXOffset();

    // Copy the data
#pragma omp parallel for schedule(static) default(none) shared(Volume) if(XCount * YCount * ZCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = -MCount; k < ZCount; ++k )
    {
        for( tSize j = -MCount; j < YCount; ++j )
        {
            tSize idx1 = getIdx(-MCount, j, k);
            tSize idx2 = Volume.getIdx(-MCount + x, j + y, k + z);
            for( tSize i = -MCount; i < XCount; ++i, idx1 += Offset1, idx2 += Offset2 )
            {
                at(idx1) = Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
CVolume<T,A>& CVolume<T,A>::copy(const tRect& Volume, tSize Margin)
{
    // Margin size
    m_Margin = (Margin < 0) ? Volume.getMargin() : Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Reallocate the data
    m_Size = Volume.getSize();
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.resize(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    // Image size
    const tSize MCount = vpl::math::getMin(m_Margin, Volume.getMargin());
    const tSize XCount = m_Size.x() + MCount;
    const tSize YCount = m_Size.y() + MCount;
    const tSize ZCount = m_Size.z() + MCount;
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Volume.getXOffset();

    // Copy the data
#pragma omp parallel for schedule(static) default(none) shared(Volume) if(XCount * YCount * ZCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = -MCount; k < ZCount; ++k )
    {
        for( tSize j = -MCount; j < YCount; ++j )
        {
            tSize idx1 = getIdx(-MCount, j, k);
            tSize idx2 = Volume.getIdx(-MCount, j, k);
            for( tSize i = -MCount; i < XCount; ++i, idx1 += Offset1, idx2 += Offset2 )
            {
                at(idx1) = Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::makeRef(const CVolume<T,A>& Volume)
{
    // Make a reference to the data
    m_Size = Volume.m_Size;
    m_Margin = Volume.m_Margin;
    m_YOffset = Volume.m_YOffset;
    m_ZOffset = Volume.m_ZOffset;
    m_DataStorage.makeRef(Volume.m_DataStorage);
    m_ZeroOffset = Volume.m_ZeroOffset;

    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::makeRef(const CVolume<T,A>& Volume,
                                           tSize x,
                                           tSize y,
                                           tSize z,
                                           tSize XSize,
                                           tSize YSize,
                                           tSize ZSize
                                           )
{
    // Check the position
    VPL_CHECK(x >= 0 && XSize >= 0 && x < Volume.m_Size.x()
              && y >= 0 && YSize >= 0 && y < Volume.m_Size.y()
              && z >= 0 && ZSize >= 0 && z < Volume.m_Size.z(), return *this);

    // Image size
    m_Size.x() = vpl::math::getMin(x + XSize, Volume.m_Size.x()) - x;
    m_Size.y() = vpl::math::getMin(y + YSize, Volume.m_Size.y()) - y;
    m_Size.z() = vpl::math::getMin(z + ZSize, Volume.m_Size.z()) - z;

    // Create a reference to the image data
    m_Margin = Volume.m_Margin;
    m_YOffset = Volume.m_YOffset;
    m_ZOffset = Volume.m_ZOffset;
    m_DataStorage.makeRef(Volume.m_DataStorage);
    m_ZeroOffset = Volume.m_ZeroOffset + z * m_ZOffset + y * m_YOffset + x;

    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::makeRef(const tRect& Volume)
{
    // Create a reference to the image data
    m_Size = Volume.getSize();
    m_Margin = Volume.getVolumeRef().m_Margin;
    m_YOffset = Volume.getVolumeRef().m_YOffset;
    m_ZOffset = Volume.getVolumeRef().m_ZOffset;
    m_DataStorage.makeRef(Volume.getVolumeRef().m_DataStorage);
    m_ZeroOffset = Volume.getVolumeRef().m_ZeroOffset + Volume.getPos().z() * m_ZOffset + Volume.getPos().y() * m_YOffset + Volume.getPos().x();

    return *this;
}


// Volume conversion
template <typename T, template <typename> class A>
template <typename Derived>
CVolume<T,A>& CVolume<T,A>::convert(const CVolumeBase<Derived>& Volume, tSize Margin)
{
    const Derived& SrcVolume = Volume.getImpl();
    typedef typename Derived::tVoxel tSrcVoxel;

    // Margin size
    m_Margin = (Margin < 0) ? SrcVolume.getMargin() : Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Reallocate the data
    m_Size = SrcVolume.getSize();
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.resize(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    // Image size
    const tSize MCount = vpl::math::getMin(m_Margin, SrcVolume.getMargin());
    const tSize XCount = m_Size.x() + MCount;
    const tSize YCount = m_Size.y() + MCount;
    const tSize ZCount = m_Size.z() + MCount;
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = SrcVolume.getXOffset();

    // Copy the data
#pragma omp parallel for schedule(static) default(none) shared(SrcVolume) if(XCount * YCount * ZCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = -MCount; k < ZCount; ++k )
    {
        for( tSize j = -MCount; j < YCount; ++j )
        {
            tSize idx1 = getIdx(-MCount, j, k);
            tSize idx2 = SrcVolume.getIdx(-MCount, j, k);
            for( tSize i = -MCount; i < XCount; ++i, idx1 += Offset1, idx2 += Offset2 )
            {
                at(idx1) = CPixelConversion<tSrcVoxel,T>::convert(SrcVolume.at(idx2));
            }
        }
    }

    return *this;
}


// Assignment operator
template <typename T, template <typename> class A>
CVolume<T,A>& CVolume<T,A>::operator =(const CVolume<T,A>& Volume)
{
    if( &Volume == this )
    {
        return *this;
    }

    const CVolSize Count = m_Size & Volume.getSize();
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Volume.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Volume) if(Count.x() * Count.y() * Count.z() > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < Count.z(); ++k )
    {
        for( tSize j = 0; j < Count.y(); ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Count.x(); ++i, idx1 += Offset1, idx2 += Offset2 )
            {
                at(idx1) = Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
template <class Derived>
inline CVolume<T,A>& CVolume<T,A>::operator +=(const CVolumeBase<Derived>& Volume)
{
    const CVolSize Count = m_Size & Volume.getSize();
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Volume.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Volume) if(Count.x() * Count.y() * Count.z() > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < Count.z(); ++k )
    {
        for( tSize j = 0; j < Count.y(); ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Count.x(); ++i, idx1 += Offset1, idx2 += Offset2 )
            {
                at(idx1) += Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
template <class Derived>
inline CVolume<T,A>& CVolume<T,A>::operator -=(const CVolumeBase<Derived>& Volume)
{
    const CVolSize Count = m_Size & Volume.getSize();
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Volume.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Volume) if(Count.x() * Count.y() * Count.z() > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < Count.z(); ++k )
    {
        for( tSize j = 0; j < Count.y(); ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Count.x(); ++i, idx1 += Offset1, idx2 += Offset2 )
            {
                at(idx1) -= Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
template <class Derived>
inline CVolume<T,A>& CVolume<T,A>::operator *=(const CVolumeBase<Derived>& Volume)
{
    const CVolSize Count = m_Size & Volume.getSize();
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Volume.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Volume) if(Count.x() * Count.y() * Count.z() > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < Count.z(); ++k )
    {
        for( tSize j = 0; j < Count.y(); ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Count.x(); ++i, idx1 += Offset1, idx2 += Offset2 )
            {
                at(idx1) *= Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
template <class Derived>
inline CVolume<T,A>& CVolume<T,A>::operator /=(const CVolumeBase<Derived>& Volume)
{
    const CVolSize Count = m_Size & Volume.getSize();
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Volume.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Volume) if(Count.x() * Count.y() * Count.z() > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < Count.z(); ++k )
    {
        for( tSize j = 0; j < Count.y(); ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Count.x(); ++i, idx1 += Offset1, idx2 += Offset2 )
            {
                at(idx1) /= Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CVolume<T,A>& CVolume<T,A>::operator +=(const CScalar<U>& c)
{
    pforEach(vpl::base::CAdd<tVoxel>(tVoxel(c.value())));

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CVolume<T,A>& CVolume<T,A>::operator -=(const CScalar<U>& c)
{
    pforEach(vpl::base::CSub<tVoxel>(tVoxel(c.value())));

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CVolume<T,A>& CVolume<T,A>::operator *=(const CScalar<U>& c)
{
    pforEach(vpl::base::CMult<tVoxel,U>(c.value()));

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CVolume<T,A>& CVolume<T,A>::operator /=(const CScalar<U>& c)
{
    pforEach(vpl::base::CDiv<tVoxel,U>(c.value()));

    return *this;
}


template <typename T, template <typename> class A>
template <class Function>
inline Function CVolume<T,A>::forEach(Function Func)
{
    for( tSize k = 0; k < m_Size.z(); ++k )
    {
        for( tSize j = 0; j < m_Size.y(); ++j )
        {
            tSize idx = getIdx(0, j, k);
            for( tSize i = 0; i < m_Size.x(); ++i, idx += getXOffset() )
            {
                Func(at(idx));
            }
        }
    }
    return Func;
}


template <typename T, template <typename> class A>
template <class Function>
inline Function CVolume<T,A>::forEach(Function Func) const
{
    for( tSize k = 0; k < m_Size.z(); ++k )
    {
        for( tSize j = 0; j < m_Size.y(); ++j )
        {
            tSize idx = getIdx(0, j, k);
            for( tSize i = 0; i < m_Size.x(); ++i, idx += getXOffset() )
            {
                Func(at(idx));
            }
        }
    }
    return Func;
}


template <typename T, template <typename> class A>
template <class Function>
inline void CVolume<T,A>::pforEach(Function Func)
{
	const tSize sx = m_Size.x();
	const tSize sy = m_Size.y();
	const tSize sz = m_Size.z();
	const tSize Offset = getXOffset();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(sx * sy * sz > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < sz; ++k )
    {
        for( tSize j = 0; j < sy; ++j )
        {
            tSize idx = getIdx(0, j, k);
            for( tSize i = 0; i < sx; ++i, idx += Offset )
            {
                Func(at(idx));
            }
        }
    }
}


template <typename T, template <typename> class A>
template <class Function>
inline void CVolume<T,A>::pforEach(Function Func) const
{
	const tSize sx = m_Size.x();
	const tSize sy = m_Size.y();
	const tSize sz = m_Size.z();
	const tSize Offset = getXOffset();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(sx * sy * sz > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < sz; ++k )
    {
        for( tSize j = 0; j < sy; ++j )
        {
            tSize idx = getIdx(0, j, k);
            for( tSize i = 0; i < sx; ++i, idx += Offset )
            {
                Func(at(idx));
            }
        }
    }
}


template <typename T, template <typename> class A>
inline typename CVolume<T,A>::tRect CVolume<T,A>::rect(const CPoint3i& Position, const CVolSize& Size)
{
    return tRect(*this, Position, Size);
}


template <typename T, template <typename> class A>
inline const typename CVolume<T,A>::tRect CVolume<T,A>::rect(const CPoint3i& Position, const CVolSize& Size) const
{
    return tRect(*this, Position, Size);
}


template <typename T, template <typename> class A>
inline typename CVolume<T,A>::tRect CVolume<T,A>::rect(const CRange& XRange,
                                                       const CRange& YRange,
                                                       const CRange& ZRange
                                                       )
{
    return tRect(*this, XRange, YRange, ZRange);
}


template <typename T, template <typename> class A>
inline const typename CVolume<T,A>::tRect CVolume<T,A>::rect(const CRange& XRange,
                                                             const CRange& YRange,
                                                             const CRange& ZRange
                                                             ) const
{
    return tRect(*this, XRange, YRange, ZRange);
}


template <typename T, template <typename> class A>
inline typename CVolume<T,A>::tRow CVolume<T,A>::row(tSize y, tSize z)
{
    return tRow(*this, y, z);
}


template <typename T, template <typename> class A>
inline const typename CVolume<T,A>::tRow CVolume<T,A>::row(tSize y, tSize z) const
{
    return tRow(*this, y, z);
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::fill(const T c)
{
    pforEach(vpl::base::CFill<tVoxel>(c));
    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::fillEntire(const T c)
{
    m_DataStorage.forEach(vpl::base::CFill<tVoxel>(c));
    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::fillMargin(const T c)
{
    // Fill front and back margin
    const tSize Count = m_Margin * m_ZOffset;
    const tSize Offset = m_ZeroOffset - m_Margin * m_YOffset - m_Margin;
    m_DataStorage.forRange(Offset - m_Margin * m_ZOffset,
                           Offset - m_Margin * m_ZOffset + Count - 1,
                           vpl::base::CFill<tVoxel>(c)
                           );
    m_DataStorage.forRange(Offset + m_Size.z() * m_ZOffset,
                           Offset + m_Size.z() * m_ZOffset + Count - 1,
                           vpl::base::CFill<tVoxel>(c)
                           );

    // Fill top and bottom margin
    const tSize Count2 = m_Margin * m_YOffset;
    const tSize sx = m_Size.x();
    const tSize sy = m_Size.y();
    const tSize sz = m_Size.z();
    const tSize Margin = m_Margin;
    const tSize YOffset = m_YOffset;
    const tSize ZOffset = m_ZOffset;
    const tSize ZeroOffset = m_ZeroOffset;

#pragma omp parallel for schedule(static) default(none) if(sx * sy * sz > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < sz; ++k )
    {
        tSize Offset2 = ZeroOffset + k * ZOffset - Margin;
        m_DataStorage.forRange(Offset2 - Margin * YOffset,
                               Offset2 - Margin * YOffset + Count2 - 1,
                               vpl::base::CFill<tVoxel>(c)
                               );
        m_DataStorage.forRange(Offset2 + sy * YOffset,
                               Offset2 + sy * YOffset + Count2 - 1,
                               vpl::base::CFill<tVoxel>(c)
                               );
    }

    // Fill left and right margin
    const tSize Count3 = m_Margin;

#pragma omp parallel for schedule(static) default(none) if(sx * sy * sz > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < sz; ++k )
    {
        for( tSize j = 0; j < sy; ++j )
        {
            tSize Offset3 = ZeroOffset + k * ZOffset + j * YOffset;
            m_DataStorage.forRange(Offset3 - Margin,
                                   Offset3 - Margin + Count3 - 1,
                                   vpl::base::CFill<tVoxel>(c)
                                   );
            m_DataStorage.forRange(Offset3 + sx,
                                   Offset3 + sx + Count3 - 1,
                                   vpl::base::CFill<tVoxel>(c)
                                   );
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::mirrorMargin()
{
    for( tSize k = -m_Margin; k < m_Size.z() + m_Margin; ++k )
    {
        tSize kk = k;
        if( k < 0 )
        {
            kk = -k;
        }
        else if ( k >= m_Size.z() )
        {
            kk = 2 * m_Size.z() - 2 - k;
        }
        for( tSize j = -m_Margin; j < m_Size.y() + m_Margin; ++j )
        {
            tSize jj = j;
            if( j < 0 )
            {
                jj = -j;
            }
            else if ( j >= m_Size.y() )
            {
                jj = 2 * m_Size.y() - 2 - j;
            }
            tSize i;
            for( i = 1; i <= m_Margin; ++i )
            {
                at(-i, j, k) = at(i, jj, kk);
                at(m_Size.x() - 1 + i, j, k) = at(m_Size.x() - 1 - i, jj, kk);
            }
            if( j < 0 || j >= m_Size.y() || k < 0 || k >= m_Size.z() )
            {
                for( i = 0; i < m_Size.x(); ++i )
                {
                    at(i, j, k) = at(i, jj, kk);
                }
            }
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::replace(const T& Value, const T& NewValue)
{
    pforEach(vpl::base::CReplace<tVoxel>(Value, NewValue));
    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::abs()
{
    pforEach(vpl::base::CAbs<tVoxel>());
    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::limit(const T& Lower, const T& Upper)
{
    pforEach(vpl::base::CLimit<tVoxel>(Lower, Upper));
    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::cut(const T& Lower, const T& Upper)
{
    static const T NewValue = CPixelTraits<T>::getPixelMin();

    pforEach(vpl::base::CCut<tVoxel>(Lower, Upper, NewValue));
    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::subSample(const CVolume<T,A>& Volume,
                                             const tSize l,
                                             const tSize m,
                                             const tSize n
                                             )
{
    VPL_CHECK(l > 0 && m > 0 && n > 0, return *this);

    const tSize XCount = vpl::math::getMin(Volume.m_Size.x() / l, m_Size.x());
    const tSize YCount = vpl::math::getMin(Volume.m_Size.y() / m, m_Size.y());
    const tSize ZCount = vpl::math::getMin(Volume.m_Size.z() / n, m_Size.z());

#pragma omp parallel for schedule(static) default(none) shared(Volume) if(XCount * YCount * ZCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < ZCount; ++k )
    {
        tSize kk = k * n;
        for( tSize j = 0, jj = 0; j < YCount; ++j, jj += m )
        {
            for( tSize i = 0, ii = 0; i < XCount; ++i, ii += l )
            {
                at(i, j, k) = Volume.at(ii, jj, kk);
            }
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
inline T CVolume<T,A>::interpolate(const CPoint3D& Point) const
{
    tSize iX = tSize(Point.x());
    tSize iY = tSize(Point.y());
    tSize iZ = tSize(Point.z());

    double dX = Point.x() - double(iX);
    double dY = Point.y() - double(iY);
    double dZ = Point.z() - double(iZ);
    double dInvX = 1.0 - dX;
    double dInvY = 1.0 - dY;
    double dInvZ = 1.0 - dZ;

    tSize idx = getIdx(iX, iY, iZ);

    // Interpolate voxel value
    tVoxel Value = tVoxel(dInvX * dInvY * dInvZ * at(idx));
    Value += tVoxel(dX * dInvY * dInvZ * at(idx + 1));
    Value += tVoxel(dInvX * dY * dInvZ * at(idx + m_YOffset));
    Value += tVoxel(dX * dY * dInvZ * at(idx + 1 + m_YOffset));
    Value += tVoxel(dInvX * dInvY * dZ * at(idx + m_ZOffset));
    Value += tVoxel(dX * dInvY * dZ * at(idx + 1 + m_ZOffset));
    Value += tVoxel(dInvX * dY * dZ * at(idx + m_YOffset + m_ZOffset));
    Value += tVoxel(dX * dY * dZ * at(idx + 1 + m_YOffset + m_ZOffset));

    // Return the interpolated value
    return Value;
}


template <typename T, template <typename> class A>
inline T CVolume<T,A>::color2Voxel(CColor Color) const
{
    // Return the pixel value
    return CPixelConversion<tRGBPixel,T>::convert(tRGBPixel(Color.rgba()));
}


template <typename T, template <typename> class A>
inline bool CVolume<T,A>::checkPosition(tSize x, tSize y, tSize z) const
{
    return (x >= 0 && x < m_Size.x()
            && y >= 0 && y < m_Size.y()
            && z >= 0 && z < m_Size.z());
}


template <typename T, template <typename> class A>
inline bool CVolume<T,A>::getPlaneXY(tSize z, CImage<T>& Plane)
{
    VPL_CHECK(z >= 0 && z < m_Size.z(), return false);
    
    const tSize XCount = vpl::math::getMin(m_Size.x(), Plane.getXSize());
    const tSize YCount = vpl::math::getMin(m_Size.y(), Plane.getYSize());
    
#pragma omp parallel for schedule(static) default(none) shared(Plane) firstprivate(z) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YCount; ++j )
    {
        for( tSize i = 0; i < XCount; ++i )
        {
            Plane(i, j) = at(i, j, z);
        }
    }
    
    return true;
}


template <typename T, template <typename> class A>
inline bool CVolume<T,A>::getPlaneXZ(tSize y, CImage<T>& Plane)
{
    VPL_CHECK(y >= 0 && y < m_Size.y(), return false);

    const tSize XCount = vpl::math::getMin(m_Size.x(), Plane.getXSize());
    const tSize ZCount = vpl::math::getMin(m_Size.z(), Plane.getYSize());

#pragma omp parallel for schedule(static) default(none) shared(Plane) firstprivate(y) if(XCount * ZCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < ZCount; ++j )
    {
        for( tSize i = 0; i < XCount; ++i )
        {
            Plane(i, j) = at(i, y, j);
        }
    }

    return true;
}


template <typename T, template <typename> class A>
inline bool CVolume<T,A>::getPlaneYZ(tSize x, CImage<T>& Plane)
{
    VPL_CHECK(x >= 0 && x < m_Size.x(), return false);

    const tSize YCount = vpl::math::getMin(m_Size.y(), Plane.getXSize());
    const tSize ZCount = vpl::math::getMin(m_Size.z(), Plane.getYSize());

#pragma omp parallel for schedule(static) default(none) shared(Plane) firstprivate(x) if(YCount * ZCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < ZCount; ++j )
    {
        for( tSize i = 0; i < YCount; ++i )
        {
            Plane(i, j) = at(x, i, j);
        }
    }

    return true;
}


template <typename T, template <typename> class A>
inline bool CVolume<T,A>::setPlaneXY(tSize z, const CImage<T>& Plane)
{
    VPL_CHECK(z >= 0 && z < m_Size.z(), return false);

    const tSize XCount = vpl::math::getMin(m_Size.x(), Plane.getXSize());
    const tSize YCount = vpl::math::getMin(m_Size.y(), Plane.getYSize());

#pragma omp parallel for schedule(static) default(none) shared(Plane) firstprivate(z) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YCount; ++j )
    {
        for( tSize i = 0; i < XCount; ++i )
        {
            at(i, j, z) = Plane(i, j);
        }
    }

    return true;
}


template <typename T, template <typename> class A>
inline bool CVolume<T,A>::setPlaneXZ(tSize y, const CImage<T>& Plane)
{
    VPL_CHECK(y >= 0 && y < m_Size.y(), return false);

    const tSize XCount = vpl::math::getMin(m_Size.x(), Plane.getXSize());
    const tSize ZCount = vpl::math::getMin(m_Size.z(), Plane.getYSize());

#pragma omp parallel for schedule(static) default(none) shared(Plane) firstprivate(y) if(XCount * ZCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < ZCount; ++j )
    {
        for( tSize i = 0; i < XCount; ++i )
        {
            at(i, y, j) = Plane(i, j);
        }
    }

    return true;
}


template <typename T, template <typename> class A>
inline bool CVolume<T,A>::setPlaneYZ(tSize x, const CImage<T>& Plane)
{
    VPL_CHECK(x >= 0 && x < m_Size.x(), return false);

    const tSize YCount = vpl::math::getMin(m_Size.y(), Plane.getXSize());
    const tSize ZCount = vpl::math::getMin(m_Size.z(), Plane.getYSize());

#pragma omp parallel for schedule(static) default(none) shared(Plane) firstprivate(x) if(YCount * ZCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < ZCount; ++j )
    {
        for( tSize i = 0; i < YCount; ++i )
        {
            at(x, i, j) = Plane(i, j);
        }
    }

    return true;
}


//==============================================================================
/*
 * - Volume data serialization functions.
 */

template <typename T, template <typename> class A>
template <class S>
void CVolume<T,A>::serialize(vpl::mod::CChannelSerializer<S>& Writer)
{
    // Begin of data serialization block
    Writer.beginWrite(*this);

    // Volume dimensions
    Writer.write(vpl::sys::tInt32(m_Size.x()));
	Writer.write(vpl::sys::tInt32(m_Size.y()));

    if( isDummy() )
    {
        // If the volume is dummy, the Z dimension is stored as a negative value
        Writer.write(-1 * vpl::sys::tInt32(m_Size.z()));

        Writer.setProgressMax(1);

        // ...and a single voxel value is saved
        Writer.write(getPtr(), 1);

        if( !Writer.progress() )
        {
            throw vpl::mod::Serializer::CWriteFailed();
        }
    }
    else
    {
        // Z dimension
        Writer.write(vpl::sys::tInt32(m_Size.z()));

        Writer.setProgressMax(int(m_Size.z()));

        // Volume data
        vpl::base::CData<tVoxel> buffer(m_Size.x());
        for (tSize k = 0; k < m_Size.z(); ++k)
        {
            for (tSize j = 0; j < m_Size.y(); ++j)
            {
                row(j, k).copyTo(buffer.getPtr());

                Writer.write(buffer.getPtr(), m_Size.x());
            }
            if (!Writer.progress())
            {
                throw vpl::mod::Serializer::CWriteFailed();
            }
        }
    }

    // End of the block
    Writer.endWrite(*this);
}


template <typename T, template <typename> class A>
template <class S>
void CVolume<T,A>::deserialize(vpl::mod::CChannelSerializer<S>& Reader)
{
    // Begin of data deserialization block
    Reader.beginRead(*this);

    // Read the volume info struct
	vpl::sys::tInt32 Size;
    Reader.read(Size);
	m_Size.x() = Size;
    Reader.read(Size);
	m_Size.y() = Size;
	Reader.read(Size);

    // Check whether a dummy volume was serialized (i.e. the Z dimension is negative)
    if( Size < 0 )
    {
        // Z dimension
        m_Size.z() = -1 * Size;

        Reader.setProgressMax(1);

        // Create a new volume
        enableDummyMode(true);
        resize(m_Size.x(), m_Size.y(), m_Size.z(), m_Margin);

        // ...read just a single voxel value
        Reader.read(getPtr(), 1);

        if (!Reader.progress())
        {
            throw vpl::mod::Serializer::CReadFailed();
        }
    }
    else
    {
        // Z dimension
        m_Size.z() = Size;

        Reader.setProgressMax(int(m_Size.z()));

        // Create a new volume
        enableDummyMode(false);
        resize(m_Size.x(), m_Size.y(), m_Size.z(), m_Margin);

        // Volume data
        vpl::base::CData<tVoxel> Buffer(m_Size.x());
        for (tSize k = 0; k < m_Size.z(); ++k)
        {
            for (tSize j = 0; j < m_Size.y(); ++j)
            {
                Reader.read(Buffer.getPtr(), m_Size.x());

                row(j, k).copyFrom(Buffer.getPtr());
            }
            if (!Reader.progress())
            {
                throw vpl::mod::Serializer::CReadFailed();
            }
        }
    }

    // End of the block
    Reader.endRead(*this);
}


template <typename T, template <typename> class A>
inline CVolume<T, A>& CVolume<T, A>::enableDummyMode(bool Enable)
{
    if( Enable )
    {
        m_DataStorage.getSampling().setSizing(0, 1).setIndexing(0, 0);
    }
    else
    {
        m_DataStorage.getSampling().defaultSizing().defaultIndexing();
    }
    return *this;
}


template <typename T, template <typename> class A>
inline bool CVolume<T, A>::isDummy() const
{
    return !m_DataStorage.getSampling().isDefault();
}
