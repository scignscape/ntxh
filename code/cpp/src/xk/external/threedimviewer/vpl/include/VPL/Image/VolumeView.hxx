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
 * Copyright (c) 2011 by 3Dim Laboratory s.r.o. \n
 *
 * Author:  info@3dim-laboratory.cz          
 * Date:    2011/01/11                       
 *
 * Description:
 * - Templates providing views of an existing volume.
 */

//==============================================================================
/*
 * Implementation of the vpl::img::CRectBox class template.
 */

template <class V>
inline CRectBox<V>::CRectBox(const tVolume& Volume,
                             tSize x,
                             tSize y,
                             tSize z,
                             tSize XSize,
                             tSize YSize,
                             tSize ZSize
                             )
    : m_Pos(x, y, z)
    , m_Size(XSize, YSize, ZSize)
    , m_Volume(const_cast<tVolume&>(Volume))
{
}


template <class V>
inline CRectBox<V>::CRectBox(const tVolume& Volume,
                             const CPoint3i& Pos, 
                             const CVolSize& Size
                             )
    : m_Pos(Pos)
    , m_Size(Size)
    , m_Volume(const_cast<tVolume&>(Volume))
{
}


template <class V>
inline CRectBox<V>::CRectBox(const tVolume& Volume,
                             const CRange& XRange,
                             const CRange& YRange,
                             const CRange& ZRange
                             )
    : m_Volume(const_cast<tVolume&>(Volume))
{
	m_Pos.x() = vpl::math::getMax<tSize>(0, XRange.getFirst());
	m_Pos.y() = vpl::math::getMax<tSize>(0, YRange.getFirst());
	m_Pos.z() = vpl::math::getMax<tSize>(0, ZRange.getFirst());

    m_Size.x() = vpl::math::getMin(Volume.getXSize(), XRange.getLast() + 1) - m_Pos.x();
    m_Size.y() = vpl::math::getMin(Volume.getYSize(), YRange.getLast() + 1) - m_Pos.y();
    m_Size.z() = vpl::math::getMin(Volume.getZSize(), ZRange.getLast() + 1) - m_Pos.z();
}


template <class V>
inline CRectBox<V>::CRectBox(const CRectBox& Rect)
    : tBase()
    , m_Pos(Rect.m_Pos)
    , m_Size(Rect.m_Size)
    , m_Volume(Rect.m_Volume)
{
}


template <class V>
template <class Derived>
inline CRectBox<V>& CRectBox<V>::operator +=(const CVolumeBase<Derived>& Volume)
{
    const tSize XCount = vpl::math::getMin(m_Size.x(), Volume.getXSize());
    const tSize YCount = vpl::math::getMin(m_Size.y(), Volume.getYSize());
    const tSize ZCount = vpl::math::getMin(m_Size.z(), Volume.getZSize());
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Volume.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Volume) if(XCount * YCount * ZCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < ZCount; ++k )
    {
        for( tSize j = 0; j < YCount; ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < XCount; ++i, idx1 += Offset1, idx2 += Offset2 )
            {
                at(idx1) += Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <class V>
template <class Derived>
inline CRectBox<V>& CRectBox<V>::operator -=(const CVolumeBase<Derived>& Volume)
{
    const tSize XCount = vpl::math::getMin(m_Size.x(), Volume.getXSize());
    const tSize YCount = vpl::math::getMin(m_Size.y(), Volume.getYSize());
    const tSize ZCount = vpl::math::getMin(m_Size.z(), Volume.getZSize());
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Volume.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Volume) if(XCount * YCount * ZCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < ZCount; ++k )
    {
        for( tSize j = 0; j < YCount; ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < XCount; ++i, idx1 += Offset1, idx2 += Offset2 )
            {
                at(idx1) -= Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <class V>
template <class Derived>
inline CRectBox<V>& CRectBox<V>::operator *=(const CVolumeBase<Derived>& Volume)
{
    const tSize XCount = vpl::math::getMin(m_Size.x(), Volume.getXSize());
    const tSize YCount = vpl::math::getMin(m_Size.y(), Volume.getYSize());
    const tSize ZCount = vpl::math::getMin(m_Size.z(), Volume.getZSize());
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Volume.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Volume) if(XCount * YCount * ZCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < ZCount; ++k )
    {
        for( tSize j = 0; j < YCount; ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < XCount; ++i, idx1 += Offset1, idx2 += Offset2 )
            {
                at(idx1) *= Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <class V>
template <class Derived>
inline CRectBox<V>& CRectBox<V>::operator /=(const CVolumeBase<Derived>& Volume)
{
    const tSize XCount = vpl::math::getMin(m_Size.x(), Volume.getXSize());
    const tSize YCount = vpl::math::getMin(m_Size.y(), Volume.getYSize());
    const tSize ZCount = vpl::math::getMin(m_Size.z(), Volume.getZSize());
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Volume.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Volume) if(XCount * YCount * ZCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize k = 0; k < ZCount; ++k )
    {
        for( tSize j = 0; j < YCount; ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < XCount; ++i, idx1 += Offset1, idx2 += Offset2 )
            {
                at(idx1) /= Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <class V>
template <typename U>
inline CRectBox<V>& CRectBox<V>::operator +=(const U& c)
{
    pforEach(vpl::base::CAdd<tVoxel>(tVoxel(c)));

    return *this;
}


template <class V>
template <typename U>
inline CRectBox<V>& CRectBox<V>::operator -=(const U& c)
{
    pforEach(vpl::base::CSub<tVoxel>(tVoxel(c)));

    return *this;
}


template <class V>
template <typename U>
inline CRectBox<V>& CRectBox<V>::operator *=(const U& c)
{
    pforEach(vpl::base::CMult<tVoxel,U>(c));

    return *this;
}


template <class V>
template <typename U>
inline CRectBox<V>& CRectBox<V>::operator /=(const U& c)
{
    pforEach(vpl::base::CDiv<tVoxel,U>(c));

    return *this;
}


template <class V>
template <class Function>
inline Function CRectBox<V>::forEach(Function Func)
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


template <class V>
template <class Function>
inline Function CRectBox<V>::forEach(Function Func) const
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


template <class V>
template <class Function>
inline void CRectBox<V>::pforEach(Function Func)
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


template <class V>
template <class Function>
inline void CRectBox<V>::pforEach(Function Func) const
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


template <class V>
inline CRectBox<V>& CRectBox<V>::fill(const tVoxel& c)
{
    pforEach(vpl::base::CFill<tVoxel>(c));

    return *this;
}


template <class V>
inline void CRectBox<V>::copyFrom(const tVoxel *pSrc)
{
    for( tSize k = 0; k < m_Size.z(); ++k )
    {
        const tVoxel *p = pSrc + k * m_Size.y() * m_Size.x();
        for( tSize j = 0; j < m_Size.y(); ++j )
        {
            tSize idx = getIdx(0, j, k);
            for( tSize i = 0; i < m_Size.x(); ++i, idx += getXOffset() )
            {
                at(idx) = *(p++);
            }
        }
    }
}


template <class V>
inline void CRectBox<V>::copyTo(tVoxel *pDst) const
{
    for( tSize k = 0; k < m_Size.z(); ++k )
    {
        tVoxel *p = pDst + k * m_Size.y() * m_Size.x();
        for( tSize j = 0; j < m_Size.y(); ++j )
        {
            tSize idx = getIdx(0, j, k);
            for( tSize i = 0; i < m_Size.x(); ++i, idx += getXOffset() )
            {
                *(p++) = at(idx);
            }
        }
    }
}


//==============================================================================
/*
 * Implementation of the vpl::img::CVolumeRow class template.
 */

template <class V>
inline CVolumeRow<V>::CVolumeRow(const tVolume& Volume, tSize y, tSize z)
    : m_y(y)
    , m_z(z)
    , m_Volume(const_cast<tVolume&>(Volume))
{
}


template <class V>
inline CVolumeRow<V>::CVolumeRow(const CVolumeRow& Row)
    : tBase()
    , m_y(Row.m_y)
    , m_z(Row.m_z)
    , m_Volume(Row.m_Volume)
{
}


template <class V>
template <class Derived>
inline CVolumeRow<V>& CVolumeRow<V>::operator +=(const vpl::math::CVectorBase<Derived>& Row)
{
    tSize Count = vpl::math::getMin(getSize(), Row.getSize());

    for( tSize i = 0; i < Count; ++i )
    {
        at(i) += Row.at(i);
    }

    return *this;
}


template <class V>
template <class Derived>
inline CVolumeRow<V>& CVolumeRow<V>::operator -=(const vpl::math::CVectorBase<Derived>& Row)
{
    tSize Count = vpl::math::getMin(getSize(), Row.getSize());

    for( tSize i = 0; i < Count; ++i )
    {
        at(i) -= Row.at(i);
    }

    return *this;
}


template <class V>
template <class Derived>
inline CVolumeRow<V>& CVolumeRow<V>::operator *=(const vpl::math::CVectorBase<Derived>& Row)
{
    tSize Count = vpl::math::getMin(getSize(), Row.getSize());

    for( tSize i = 0; i < Count; ++i )
    {
        at(i) *= Row.at(i);
    }

    return *this;
}


template <class V>
template <class Derived>
inline CVolumeRow<V>& CVolumeRow<V>::operator /=(const vpl::math::CVectorBase<Derived>& Row)
{
    tSize Count = vpl::math::getMin(getSize(), Row.getSize());

    for( tSize i = 0; i < Count; ++i )
    {
        at(i) /= Row.at(i);
    }

    return *this;
}


template <class V>
template <typename U>
inline CVolumeRow<V>& CVolumeRow<V>::operator +=(const U& c)
{
    forEach(vpl::base::CAdd<tVoxel>(tVoxel(c)));

    return *this;
}


template <class V>
template <typename U>
inline CVolumeRow<V>& CVolumeRow<V>::operator -=(const U& c)
{
    forEach(vpl::base::CSub<tVoxel>(tVoxel(c)));

    return *this;
}


template <class V>
template <typename U>
inline CVolumeRow<V>& CVolumeRow<V>::operator *=(const U& c)
{
    forEach(vpl::base::CMult<tVoxel,U>(c));

    return *this;
}


template <class V>
template <typename U>
inline CVolumeRow<V>& CVolumeRow<V>::operator /=(const U& c)
{
    forEach(vpl::base::CDiv<tVoxel,U>(c));

    return *this;
}


template <class V>
template <class Function>
inline Function CVolumeRow<V>::forEach(Function Func)
{
    tSize idx = m_Volume.getIdx(0, m_y, m_z);
    for( tSize i = 0; i < m_Volume.getXSize(); ++i, idx += m_Volume.getXOffset() )
    {
        Func(m_Volume.at(idx));
    }
    return Func;
}


template <class V>
template <class Function>
inline Function CVolumeRow<V>::forEach(Function Func) const
{
    tSize idx = m_Volume.getIdx(0, m_y, m_z);
    for( tSize i = 0; i < m_Volume.getXSize(); ++i, idx += m_Volume.getXOffset() )
    {
        Func(m_Volume.at(idx));
    }
    return Func;
}


template <class V>
template <class Function>
inline void CVolumeRow<V>::pforEach(Function Func)
{
    const tSize sx = m_Volume.getXSize();
    const tSize y = m_y;
    const tSize z = m_z;

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(sx > VPL_MIN_OMP_COMPLEXITY)
    for( tSize i = 0; i < sx; ++i )
    {
        Func(m_Volume(i, y, z));
    }
}


template <class V>
template <class Function>
inline void CVolumeRow<V>::pforEach(Function Func) const
{
    const tSize sx = m_Volume.getXSize();
    const tSize y = m_y;
    const tSize z = m_z;

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(sx > VPL_MIN_OMP_COMPLEXITY)
    for( tSize i = 0; i < sx; ++i )
    {
        Func(m_Volume(i, y, z));
    }
}


template <class V>
inline CVolumeRow<V>& CVolumeRow<V>::fill(const tVoxel& c)
{
    forEach(vpl::base::CFill<tVoxel>(c));

    return *this;
}


template <class V>
inline void CVolumeRow<V>::copyFrom(const tVoxel *pSrc)
{
    tSize idx = m_Volume.getIdx(0, m_y, m_z);
    for( tSize i = 0; i < m_Volume.getXSize(); ++i, idx += m_Volume.getXOffset() )
    {
        m_Volume.at(idx) = *(pSrc++);
    }
}


template <class V>
inline void CVolumeRow<V>::copyTo(tVoxel *pDst) const
{
    tSize idx = m_Volume.getIdx(0, m_y, m_z);
    for( tSize i = 0; i < m_Volume.getXSize(); ++i, idx += m_Volume.getXOffset() )
    {
        *(pDst++) = m_Volume.at(idx);
    }
}
