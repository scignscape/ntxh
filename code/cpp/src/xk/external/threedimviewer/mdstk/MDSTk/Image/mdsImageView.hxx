//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2011 by 3Dim Laboratory s.r.o. \n
 *
 * Author:  info@3dim-laboratory.cz             \n
 * Date:    2011/01/11                          \n
 *
 * $Id:$
 *
 * Description:
 * - Templates providing views of an existing image.
 */

//==============================================================================
/*
 * Implementation of the mds::img::CRect class template.
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
                       const CSize2i& Size
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
    m_Pos.x() = mds::math::getMax(0, XRange.getFirst());
    m_Pos.y() = mds::math::getMax(0, YRange.getFirst());

    m_Size.x() = mds::math::getMin(Image.getXSize(), XRange.getLast() + 1) - m_Pos.x();
    m_Size.y() = mds::math::getMin(Image.getYSize(), YRange.getLast() + 1) - m_Pos.y();
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
    tSize XCount = mds::math::getMin(m_Size.x(), Image.getXSize());
    tSize YCount = mds::math::getMin(m_Size.y(), Image.getYSize());

#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += getXOffset(), idx2 += Image.getXOffset() )
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
    tSize XCount = mds::math::getMin(m_Size.x(), Image.getXSize());
    tSize YCount = mds::math::getMin(m_Size.y(), Image.getYSize());

#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += getXOffset(), idx2 += Image.getXOffset() )
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
    tSize XCount = mds::math::getMin(m_Size.x(), Image.getXSize());
    tSize YCount = mds::math::getMin(m_Size.y(), Image.getYSize());

#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += getXOffset(), idx2 += Image.getXOffset() )
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
    tSize XCount = mds::math::getMin(m_Size.x(), Image.getXSize());
    tSize YCount = mds::math::getMin(m_Size.y(), Image.getYSize());

#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += getXOffset(), idx2 += Image.getXOffset() )
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
    pforEach(mds::base::CAdd<tPixel>(tPixel(c)));

    return *this;
}


template <class I>
template <typename U>
inline CRect<I>& CRect<I>::operator -=(const U& c)
{
    pforEach(mds::base::CSub<tPixel>(tPixel(c)));

    return *this;
}


template <class I>
template <typename U>
inline CRect<I>& CRect<I>::operator *=(const U& c)
{
    pforEach(mds::base::CMult<tPixel,U>(c));

    return *this;
}


template <class I>
template <typename U>
inline CRect<I>& CRect<I>::operator /=(const U& c)
{
    pforEach(mds::base::CDiv<tPixel,U>(c));

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
inline Function CRect<I>::pforEach(Function Func)
{
#pragma omp parallel for schedule(static) default(shared)
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
inline Function CRect<I>::pforEach(Function Func) const
{
#pragma omp parallel for schedule(static) default(shared)
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
inline CRect<I>& CRect<I>::fill(const tPixel& c)
{
    pforEach(mds::base::CFill<tPixel>(c));

    return *this;
}


template <class I>
inline void CRect<I>::copyFrom(const tPixel *pSrc)
{
//#pragma omp parallel for schedule(static) default(shared)
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
//#pragma omp parallel for schedule(static) default(shared)
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
 * Implementation of the mds::img::CImageRow class template.
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
inline CImageRow<I>& CImageRow<I>::operator +=(const mds::math::CVectorBase<Derived>& Row)
{
    tSize Count = mds::math::getMin(getSize(), Row.getSize());

//#pragma omp parallel for schedule(static) default(shared)
    for( tSize i = 0; i < Count; ++i )
    {
        at(i) += Row.at(i);
    }

    return *this;
}


template <class I>
template <class Derived>
inline CImageRow<I>& CImageRow<I>::operator -=(const mds::math::CVectorBase<Derived>& Row)
{
    tSize Count = mds::math::getMin(getSize(), Row.getSize());

//#pragma omp parallel for schedule(static) default(shared)
    for( tSize i = 0; i < Count; ++i )
    {
        at(i) -= Row.at(i);
    }

    return *this;
}


template <class I>
template <class Derived>
inline CImageRow<I>& CImageRow<I>::operator *=(const mds::math::CVectorBase<Derived>& Row)
{
    tSize Count = mds::math::getMin(getSize(), Row.getSize());

//#pragma omp parallel for schedule(static) default(shared)
    for( tSize i = 0; i < Count; ++i )
    {
        at(i) *= Row.at(i);
    }

    return *this;
}


template <class I>
template <class Derived>
inline CImageRow<I>& CImageRow<I>::operator /=(const mds::math::CVectorBase<Derived>& Row)
{
    tSize Count = mds::math::getMin(getSize(), Row.getSize());

//#pragma omp parallel for schedule(static) default(shared)
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
    forEach(mds::base::CAdd<tPixel>(tPixel(c)));

    return *this;
}


template <class I>
template <typename U>
inline CImageRow<I>& CImageRow<I>::operator -=(const U& c)
{
    forEach(mds::base::CSub<tPixel>(tPixel(c)));

    return *this;
}


template <class I>
template <typename U>
inline CImageRow<I>& CImageRow<I>::operator *=(const U& c)
{
    forEach(mds::base::CMult<tPixel,U>(c));

    return *this;
}


template <class I>
template <typename U>
inline CImageRow<I>& CImageRow<I>::operator /=(const U& c)
{
    forEach(mds::base::CDiv<tPixel,U>(c));

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
inline Function CImageRow<I>::pforEach(Function Func)
{
#pragma omp parallel for schedule(static) default(shared)
    for( tSize i = 0; i < m_Image.getXSize(); ++i )
    {
        Func(m_Image(i, m_y));
    }
    return Func;
}


template <class I>
template <class Function>
inline Function CImageRow<I>::pforEach(Function Func) const
{
#pragma omp parallel for schedule(static) default(shared)
    for( tSize i = 0; i < m_Image.getXSize(); ++i )
    {
        Func(m_Image(i, m_y));
    }
    return Func;
}


template <class I>
inline CImageRow<I>& CImageRow<I>::fill(const tPixel& c)
{
    forEach(mds::base::CFill<tPixel>(c));

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
