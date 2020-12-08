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
 * - Templates providing views of an existing image.
 */

//==============================================================================
/*
 * Implementation of the vpl::img::CRect class template.
 */

template <class I>
inline CRect<I>::CRect(const tImage& Image,
                       tSize x,
                       tSize y,
                       tSize XSize,
                       tSize YSize
                       )
    : m_Pos(x, y)
    , m_Size(XSize, YSize)
    , m_Image(const_cast<tImage&>(Image))
{
}


template <class I>
inline CRect<I>::CRect(const tImage& Image,
                       const CPoint2i& Pos, 
                       const CImSize& Size
                       )
    : m_Pos(Pos)
    , m_Size(Size)
    , m_Image(const_cast<tImage&>(Image))
{
}


template <class I>
inline CRect<I>::CRect(const tImage& Image,
                       const CRange& XRange,
                       const CRange& YRange
                       )
   : m_Image(const_cast<tImage&>(Image))
{
    m_Pos.x() = vpl::math::getMax<tSize>(0, XRange.getFirst());
	m_Pos.y() = vpl::math::getMax<tSize>(0, YRange.getFirst());

    m_Size.x() = vpl::math::getMin(Image.getXSize(), XRange.getLast() + 1) - m_Pos.x();
    m_Size.y() = vpl::math::getMin(Image.getYSize(), YRange.getLast() + 1) - m_Pos.y();
}


template <class I>
inline CRect<I>::CRect(const CRect& Rect)
    : tBase()
    , m_Pos(Rect.m_Pos)
    , m_Size(Rect.m_Size)
    , m_Image(Rect.m_Image)
{
}


template <class I>
template <class Derived>
inline CRect<I>& CRect<I>::operator +=(const CImageBase<Derived>& Image)
{
    const tSize XCount = vpl::math::getMin(m_Size.x(), Image.getXSize());
    const tSize YCount = vpl::math::getMin(m_Size.y(), Image.getYSize());
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Image.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Image) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += Offset1, idx2 += Offset2 )
        {
            at(idx1) += Image.at(idx2);
        }
    }

    return *this;
}


template <class I>
template <class Derived>
inline CRect<I>& CRect<I>::operator -=(const CImageBase<Derived>& Image)
{
    const tSize XCount = vpl::math::getMin(m_Size.x(), Image.getXSize());
    const tSize YCount = vpl::math::getMin(m_Size.y(), Image.getYSize());
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Image.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Image) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += Offset1, idx2 += Offset2 )
        {
            at(idx1) -= Image.at(idx2);
        }
    }

    return *this;
}


template <class I>
template <class Derived>
inline CRect<I>& CRect<I>::operator *=(const CImageBase<Derived>& Image)
{
    const tSize XCount = vpl::math::getMin(m_Size.x(), Image.getXSize());
    const tSize YCount = vpl::math::getMin(m_Size.y(), Image.getYSize());
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Image.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Image) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += Offset1, idx2 += Offset2 )
        {
            at(idx1) *= Image.at(idx2);
        }
    }

    return *this;
}


template <class I>
template <class Derived>
inline CRect<I>& CRect<I>::operator /=(const CImageBase<Derived>& Image)
{
    const tSize XCount = vpl::math::getMin(m_Size.x(), Image.getXSize());
    const tSize YCount = vpl::math::getMin(m_Size.y(), Image.getYSize());
    const tSize Offset1 = getXOffset();
    const tSize Offset2 = Image.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Image) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += Offset1, idx2 += Offset2 )
        {
            at(idx1) /= Image.at(idx2);
        }
    }

    return *this;
}


template <class I>
template <typename U>
inline CRect<I>& CRect<I>::operator +=(const U& c)
{
    pforEach(vpl::base::CAdd<tPixel>(tPixel(c)));

    return *this;
}


template <class I>
template <typename U>
inline CRect<I>& CRect<I>::operator -=(const U& c)
{
    pforEach(vpl::base::CSub<tPixel>(tPixel(c)));

    return *this;
}


template <class I>
template <typename U>
inline CRect<I>& CRect<I>::operator *=(const U& c)
{
    pforEach(vpl::base::CMult<tPixel,U>(c));

    return *this;
}


template <class I>
template <typename U>
inline CRect<I>& CRect<I>::operator /=(const U& c)
{
    pforEach(vpl::base::CDiv<tPixel,U>(c));

    return *this;
}


template <class I>
template <class Function>
inline Function CRect<I>::forEach(Function Func)
{
    for( tSize j = 0; j < m_Size.y(); ++j )
    {
        tSize idx = getIdx(0, j);
        for( tSize i = 0; i < m_Size.x(); ++i, idx += getXOffset() )
        {
            Func(at(idx));
        }
    }
    return Func;
}


template <class I>
template <class Function>
inline Function CRect<I>::forEach(Function Func) const
{
    for( tSize j = 0; j < m_Size.y(); ++j )
    {
        tSize idx = getIdx(0, j);
        for( tSize i = 0; i < m_Size.x(); ++i, idx += getXOffset() )
        {
            Func(at(idx));
        }
    }
    return Func;
}


template <class I>
template <class Function>
inline void CRect<I>::pforEach(Function Func)
{
	const tSize sx = m_Size.x();
	const tSize sy = m_Size.y();
	const tSize Offset = getXOffset();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(sx * sy > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < sy; ++j )
    {
        tSize idx = getIdx(0, j);
        for( tSize i = 0; i < sx; ++i, idx += Offset )
        {
            Func(at(idx));
        }
    }
}


template <class I>
template <class Function>
inline void CRect<I>::pforEach(Function Func) const
{
	const tSize sx = m_Size.x();
	const tSize sy = m_Size.y();
	const tSize Offset = getXOffset();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(sx * sy > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < sy; ++j )
    {
        tSize idx = getIdx(0, j);
        for( tSize i = 0; i < sx; ++i, idx += getXOffset() )
        {
            Func(at(idx));
        }
    }
}


template <class I>
inline CRect<I>& CRect<I>::fill(const tPixel& c)
{
    pforEach(vpl::base::CFill<tPixel>(c));

    return *this;
}


template <class I>
inline void CRect<I>::copyFrom(const tPixel *pSrc)
{
    for( tSize j = 0; j < m_Size.y(); ++j )
    {
        const tPixel *p = pSrc + j * m_Size.y();
        tSize idx = getIdx(0, j);
        for( tSize i = 0; i < m_Size.x(); ++i, idx += getXOffset() )
        {
            at(idx) = *(p++);
        }
    }
}


template <class I>
inline void CRect<I>::copyTo(tPixel *pDst) const
{
    for( tSize j = 0; j < m_Size.y(); ++j )
    {
        tPixel *p = pDst + j * m_Size.y();
        tSize idx = getIdx(0, j);
        for( tSize i = 0; i < m_Size.x(); ++i, idx += getXOffset() )
        {
            *(p++) = at(idx);
        }
    }
}


//==============================================================================
/*
 * Implementation of the vpl::img::CImageRow class template.
 */

template <class I>
inline CImageRow<I>::CImageRow(const tImage& Image, tSize y)
    : m_y(y)
    , m_Image(const_cast<tImage&>(Image))
{
}


template <class I>
inline CImageRow<I>::CImageRow(const CImageRow& Row)
    : tBase()
    , m_y(Row.m_y)
    , m_Image(Row.m_Image)
{
}


template <class I>
template <class Derived>
inline CImageRow<I>& CImageRow<I>::operator +=(const vpl::math::CVectorBase<Derived>& Row)
{
    tSize Count = vpl::math::getMin(getSize(), Row.getSize());

    for( tSize i = 0; i < Count; ++i )
    {
        at(i) += Row.at(i);
    }

    return *this;
}


template <class I>
template <class Derived>
inline CImageRow<I>& CImageRow<I>::operator -=(const vpl::math::CVectorBase<Derived>& Row)
{
    tSize Count = vpl::math::getMin(getSize(), Row.getSize());

    for( tSize i = 0; i < Count; ++i )
    {
        at(i) -= Row.at(i);
    }

    return *this;
}


template <class I>
template <class Derived>
inline CImageRow<I>& CImageRow<I>::operator *=(const vpl::math::CVectorBase<Derived>& Row)
{
    tSize Count = vpl::math::getMin(getSize(), Row.getSize());

    for( tSize i = 0; i < Count; ++i )
    {
        at(i) *= Row.at(i);
    }

    return *this;
}


template <class I>
template <class Derived>
inline CImageRow<I>& CImageRow<I>::operator /=(const vpl::math::CVectorBase<Derived>& Row)
{
    tSize Count = vpl::math::getMin(getSize(), Row.getSize());

    for( tSize i = 0; i < Count; ++i )
    {
        at(i) /= Row.at(i);
    }

    return *this;
}


template <class I>
template <typename U>
inline CImageRow<I>& CImageRow<I>::operator +=(const U& c)
{
    forEach(vpl::base::CAdd<tPixel>(tPixel(c)));

    return *this;
}


template <class I>
template <typename U>
inline CImageRow<I>& CImageRow<I>::operator -=(const U& c)
{
    forEach(vpl::base::CSub<tPixel>(tPixel(c)));

    return *this;
}


template <class I>
template <typename U>
inline CImageRow<I>& CImageRow<I>::operator *=(const U& c)
{
    forEach(vpl::base::CMult<tPixel,U>(c));

    return *this;
}


template <class I>
template <typename U>
inline CImageRow<I>& CImageRow<I>::operator /=(const U& c)
{
    forEach(vpl::base::CDiv<tPixel,U>(c));

    return *this;
}


template <class I>
template <class Function>
inline Function CImageRow<I>::forEach(Function Func)
{
    tSize idx = m_Image.getIdx(0, m_y);
    for( tSize i = 0; i < m_Image.getXSize(); ++i, idx += m_Image.getXOffset() )
    {
        Func(m_Image.at(idx));
    }
    return Func;
}


template <class I>
template <class Function>
inline Function CImageRow<I>::forEach(Function Func) const
{
    tSize idx = m_Image.getIdx(0, m_y);
    for( tSize i = 0; i < m_Image.getXSize(); ++i, idx += m_Image.getXOffset() )
    {
        Func(m_Image.at(idx));
    }
    return Func;
}


template <class I>
template <class Function>
inline void CImageRow<I>::pforEach(Function Func)
{
    const tSize sz = m_Image.getXSize();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(sz > VPL_MIN_OMP_COMPLEXITY)
    for( tSize i = 0; i < sz; ++i )
    {
        Func(m_Image(i, m_y));
    }
}


template <class I>
template <class Function>
inline void CImageRow<I>::pforEach(Function Func) const
{
    const tSize sz = m_Image.getXSize();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(sz > VPL_MIN_OMP_COMPLEXITY)
    for( tSize i = 0; i < sz; ++i )
    {
        Func(m_Image(i, m_y));
    }
}


template <class I>
inline CImageRow<I>& CImageRow<I>::fill(const tPixel& c)
{
    forEach(vpl::base::CFill<tPixel>(c));

    return *this;
}


template <class I>
inline void CImageRow<I>::copyFrom(const tPixel *pSrc)
{
    tSize idx = m_Image.getIdx(0, m_y);
    for( tSize i = 0; i < m_Image.getXSize(); ++i, idx += m_Image.getXOffset() )
    {
        m_Image.at(idx) = *(pSrc++);
    }
}


template <class I>
inline void CImageRow<I>::copyTo(tPixel *pDst) const
{
    tSize idx = m_Image.getIdx(0, m_y);
    for( tSize i = 0; i < m_Image.getXSize(); ++i, idx += m_Image.getXOffset() )
    {
        *(pDst++) = m_Image.at(idx);
    }
}
