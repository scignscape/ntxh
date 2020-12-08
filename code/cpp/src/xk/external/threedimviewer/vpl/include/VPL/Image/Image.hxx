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
 * Date:    2003/12/08                       
 *
 * Description:
 * - Class template providing basic image operations.
 */


//==============================================================================
/*
 * Methods templates.
 */

template <typename T, template <typename> class A>
inline CImage<T,A>::CImage()
    : m_Size(0, 0)
    , m_Margin(0)
    , m_YOffset(0)
    , m_ZeroOffset(0)
    , m_DataStorage(0)
{
}


template <typename T, template <typename> class A>
inline CImage<T,A>::CImage(tSize XSize, tSize YSize, tSize Margin)
    : m_DataStorage(EMPTY_CONST)
{
    resize(XSize, YSize, Margin);
}


template <typename T, template <typename> class A>
inline CImage<T,A>::CImage(const CImSize& Size, tSize Margin)
    : m_DataStorage(EMPTY_CONST)
{
    resize(Size, Margin);
}


template <typename T, template <typename> class A>
inline CImage<T,A>::CImage(const CImage<T,A>& Image,
                           tSize x,
                           tSize y,
                           tSize XSize,
                           tSize YSize
                           )
    : m_DataStorage(EMPTY_CONST)
{
    VPL_ASSERT(x >= 0 && XSize >= 0 && x < Image.m_Size.x()
               && y >= 0 && YSize >= 0 && y < Image.m_Size.y());
    
    copy(Image, x, y, XSize, YSize, -1);
}


template <typename T, template <typename> class A>
inline CImage<T,A>::CImage(const CImage<T,A>& Image,
                           tSize x,
                           tSize y,
                           tSize XSize,
                           tSize YSize,
                           EMakeRef
                           )
    : m_Margin(Image.m_Margin)
    , m_YOffset(Image.m_YOffset)
    , m_ZeroOffset(Image.m_ZeroOffset)
    , m_DataStorage(Image.m_DataStorage, REFERENCE)
{
    VPL_ASSERT(x >= 0 && XSize >= 0 && x < Image.m_Size.x()
               && y >= 0 && YSize >= 0 && y < Image.m_Size.y());

    // Image size
    m_Size.x() = vpl::math::getMin(x + XSize, Image.m_Size.x()) - x;
    m_Size.y() = vpl::math::getMin(y + YSize, Image.m_Size.y()) - y;

    // Image data
    m_ZeroOffset += y * m_YOffset + x;
}


template <typename T, template <typename> class A>
inline CImage<T,A>::CImage(const tRect& Image)
    : m_DataStorage(EMPTY_CONST)
{
    copy(Image, -1);
}


template <typename T, template <typename> class A>
inline CImage<T,A>::CImage(const tRect& Image, EMakeRef)
    : m_Size(Image.getSize())
    , m_Margin(Image.getImageRef().m_Margin)
    , m_YOffset(Image.getImageRef().m_YOffset)
    , m_ZeroOffset(Image.getImageRef().m_ZeroOffset)
    , m_DataStorage(Image.getImageRef().m_DataStorage, REFERENCE)
{
    // Image data
    m_ZeroOffset += Image.getPos().y() * m_YOffset + Image.getPos().x();
}


// Copy constructor
template <typename T, template <typename> class A>
inline CImage<T,A>::CImage(const CImage<T,A>& Image)
    : vpl::base::CObject()
    , tBase()
    , m_DataStorage(EMPTY_CONST)
{
    copy(Image, -1);
}


template <typename T, template <typename> class A>
inline CImage<T,A>::CImage(const CImage<T,A>& Image, EMakeRef)
    : m_Size(Image.m_Size)
    , m_Margin(Image.m_Margin)
    , m_YOffset(Image.m_YOffset)
    , m_ZeroOffset(Image.m_ZeroOffset)
    , m_DataStorage(Image.m_DataStorage, REFERENCE)
{
}


template <typename T, template <typename> class A>
CImage<T,A>::~CImage()
{
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::resize(tSize XSize, tSize YSize, tSize Margin)
{
    VPL_ASSERT(Margin >= 0);

    m_Margin = Margin;
    tSize Margins = Margin << 1; // m_Margin * 2

    // Reallocate the data
    m_Size.x() = XSize;
    m_Size.y() = YSize;
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.resize(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::resize(const CImSize& Size, tSize Margin)
{
    VPL_ASSERT(Margin >= 0);

    m_Margin = Margin;
    tSize Margins = Margin << 1; // m_Margin * 2

    // Reallocate the data
    m_Size = Size;
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.resize(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    return *this;
}


template <typename T, template <typename> class A>
CImage<T,A>& CImage<T,A>::copy(const CImage<T,A>& Image, tSize Margin)
{
    // Margin size
    m_Margin = (Margin < 0) ? Image.m_Margin : Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Reallocate the data
    m_Size = Image.m_Size;
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.resize(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    // Size of the data to copy
    const tSize MCount = vpl::math::getMin(m_Margin, Image.m_Margin);
    const tSize XCount = m_Size.x() + (MCount << 1);
    const tSize YCount = m_Size.y() + MCount;

    // Copy the data
#pragma omp parallel for schedule(static) default(none) shared(Image) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = -MCount; j < YCount; ++j )
    {
        vpl::sys::memCopy(getPtr(-MCount, j),
                           Image.getPtr(-MCount, j),
                           XCount
                           );
    }

    return *this;
}


template <typename T, template <typename> class A>
CImage<T,A>& CImage<T,A>::copy(const CImage<T,A>& Image,
                               tSize x,
                               tSize y,
                               tSize XSize,
                               tSize YSize,
                               tSize Margin
                               )
{
    // Check the position
    VPL_CHECK(x >= 0 && XSize >= 0 && x < Image.m_Size.x()
              && y >= 0 && YSize >= 0 && y < Image.m_Size.y(), return *this);
   
    // Image size
    m_Size.x() = vpl::math::getMin(x + XSize, Image.m_Size.x()) - x;
    m_Size.y() = vpl::math::getMin(y + YSize, Image.m_Size.y()) - y;

    // Margin size
    m_Margin = (Margin < 0) ? Image.m_Margin : Margin;
    tSize Margins = m_Margin << 1;

    // Reallocate the data
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.resize(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    // Size of the data to copy
    const tSize MCount = vpl::math::getMin(m_Margin, Image.m_Margin);
    const tSize XCount = m_Size.x() + (MCount << 1);
    const tSize YCount = m_Size.y() + MCount;
    const tSize cx = x;
    const tSize cy = y;

    // Copy the data
#pragma omp parallel for schedule(static) default(none) shared(Image) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = -MCount; j < YCount; ++j )
    {
        vpl::sys::memCopy(getPtr(-MCount, j),
                          Image.getPtr(-MCount + cx, j + cy),
                          XCount
                          );
    }

    return *this;
}


template <typename T, template <typename> class A>
CImage<T,A>& CImage<T,A>::copy(const tRect& Image, tSize Margin)
{
    // Margin size
    m_Margin = (Margin < 0) ? Image.getMargin() : Margin;
    tSize Margins = m_Margin << 1;

    // Reallocate the data
    m_Size = Image.getSize();
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.resize(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    // Size of the data to copy
    const tSize MCount = vpl::math::getMin(m_Margin, Image.getMargin());
    const tSize XCount = m_Size.x() + (MCount << 1);
    const tSize YCount = m_Size.y() + MCount;

    // Copy the data
#pragma omp parallel for schedule(static) default(none) shared(Image) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = -MCount; j < YCount; ++j )
    {
        vpl::sys::memCopy(getPtr(-MCount, j),
                          Image.getImageRef().getPtr(-MCount, j),
                          XCount
                          );
    }

    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::makeRef(const CImage<T,A>& Image)
{
    // Make a reference to the data
    m_Size = Image.m_Size;
    m_Margin = Image.m_Margin;
    m_YOffset = Image.m_YOffset;
    m_DataStorage.makeRef(Image.m_DataStorage);
    m_ZeroOffset = Image.m_ZeroOffset;

    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::makeRef(const CImage<T,A>& Image,
                                         tSize x,
                                         tSize y,
                                         tSize XSize,
                                         tSize YSize
                                         )
{
    // Check the position
    VPL_CHECK(x >= 0 && XSize >= 0 && x < Image.m_Size.x()
              && y >= 0 && YSize >= 0 && y < Image.m_Size.y(), return *this);

    // Image size
    m_Size.x() = vpl::math::getMin(x + XSize, Image.m_Size.x()) - x;
    m_Size.y() = vpl::math::getMin(y + YSize, Image.m_Size.y()) - y;

    // Create a reference to the image data
    m_Margin = Image.m_Margin;
    m_YOffset = Image.m_YOffset;
    m_DataStorage.makeRef(Image.m_DataStorage);
    m_ZeroOffset = Image.m_ZeroOffset + y * m_YOffset + x;

    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::makeRef(const tRect& Image)
{
    // Create a reference to the image data
    m_Size = Image.getSize();
    m_Margin = Image.getImageRef().m_Margin;
    m_YOffset = Image.getImageRef().m_YOffset;
    m_DataStorage.makeRef(Image.getImageRef().m_DataStorage);
    m_ZeroOffset = Image.getImageRef().m_ZeroOffset + Image.getPos().y() * m_YOffset + Image.getPos().x();

    return *this;
}


// Image conversion
template <typename T, template <typename> class A>
template <typename Derived>
CImage<T,A>& CImage<T,A>::convert(const CImageBase<Derived>& Image, tSize Margin)
{
    const Derived& SrcImage = Image.getImpl();
    typedef typename Derived::tPixel tSrcPixel;

    // Margin size
    m_Margin = (Margin < 0) ? SrcImage.getMargin() : Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Reallocate the data
    m_Size = SrcImage.getSize();
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.resize(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    // Size of the image data to copy
    const tSize MCount = vpl::math::getMin(m_Margin, SrcImage.getMargin());
    const tSize XCount = m_Size.x() + MCount;
    const tSize YCount = m_Size.y() + MCount;
    const tSize Offset = getXOffset();
    const tSize SrcOffset = SrcImage.getXOffset();

    // Convert image pixels
#pragma omp parallel for schedule(static) default(none) shared(SrcImage) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = -MCount; j < YCount; ++j )
    {
        tSize idx1 = getIdx(-MCount, j);
        tSize idx2 = SrcImage.getIdx(-MCount, j);
        for( tSize i = -MCount; i < XCount; ++i, idx1 += Offset, idx2 += SrcOffset )
        {
            at(idx1) = CPixelConversion<tSrcPixel,T>::convert(SrcImage.at(idx2));
        }
    }

    return *this;
}


// Assignment operator
template <typename T, template <typename> class A>
CImage<T,A>& CImage<T,A>::operator =(const CImage& Image)
{
    if( &Image == this )
    {
        return *this;
    }
    
    const CImSize Count = m_Size & Image.getSize();
    
#pragma omp parallel for schedule(static) default(none) shared(Image) if(Count.x() * Count.y() > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < Count.y(); ++j )
    {
        vpl::sys::memCopy(getRowPtr(j),
                          Image.getRowPtr(j),
                          Count.x()
                          );
    }
    
    return *this;
}


template <typename T, template <typename> class A>
template <class Derived>
inline CImage<T,A>& CImage<T,A>::operator +=(const CImageBase<Derived>& Image)
{
    const CImSize Count = m_Size & Image.getSize();
    const tSize Offset = getXOffset();
    const tSize SrcOffset = Image.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Image) if(Count.x() * Count.y() > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < Count.y(); ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < Count.x(); ++i, idx1 += Offset, idx2 += SrcOffset )
        {
            at(idx1) += Image.at(idx2);
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
template <class Derived>
inline CImage<T,A>& CImage<T,A>::operator -=(const CImageBase<Derived>& Image)
{
    const CImSize Count = m_Size & Image.getSize();
    const tSize Offset = getXOffset();
    const tSize SrcOffset = Image.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Image) if(Count.x() * Count.y() > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < Count.y(); ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < Count.x(); ++i, idx1 += Offset, idx2 += SrcOffset )
        {
            at(idx1) -= Image.at(idx2);
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
template <class Derived>
inline CImage<T,A>& CImage<T,A>::operator *=(const CImageBase<Derived>& Image)
{
    const CImSize Count = m_Size & Image.getSize();
    const tSize Offset = getXOffset();
    const tSize SrcOffset = Image.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Image) if(Count.x() * Count.y() > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < Count.y(); ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < Count.x(); ++i, idx1 += Offset, idx2 += SrcOffset )
        {
            at(idx1) *= Image.at(idx2);
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
template <class Derived>
inline CImage<T,A>& CImage<T,A>::operator /=(const CImageBase<Derived>& Image)
{
    const CImSize Count = m_Size & Image.getSize();
    const tSize Offset = getXOffset();
    const tSize SrcOffset = Image.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Image) if(Count.x() * Count.y() > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < Count.y(); ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < Count.x(); ++i, idx1 += Offset, idx2 += SrcOffset )
        {
            at(idx1) /= Image.at(idx2);
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CImage<T,A>& CImage<T,A>::operator +=(const CScalar<U>& c)
{
    pforEach(vpl::base::CAdd<tPixel>(tPixel(c.value())));

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CImage<T,A>& CImage<T,A>::operator -=(const CScalar<U>& c)
{
    pforEach(vpl::base::CSub<tPixel>(tPixel(c.value())));

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CImage<T,A>& CImage<T,A>::operator *=(const CScalar<U>& c)
{
    pforEach(vpl::base::CMult<tPixel,U>(c.value()));

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CImage<T,A>& CImage<T,A>::operator /=(const CScalar<U>& c)
{
    pforEach(vpl::base::CDiv<tPixel,U>(c.value()));

    return *this;
}


template <typename T, template <typename> class A>
template <class Function>
inline Function CImage<T,A>::forEach(Function Func)
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


template <typename T, template <typename> class A>
template <class Function>
inline Function CImage<T,A>::forEach(Function Func) const
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


template <typename T, template <typename> class A>
template <class Function>
inline void CImage<T,A>::pforEach(Function Func)
{
	const tSize sx = m_Size.x();
	const tSize sy = m_Size.y();
	const tSize offset = getXOffset();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(sx * sy > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < sy; ++j )
    {
        tSize idx = getIdx(0, j);
        for( tSize i = 0; i < sx; ++i, idx += offset )
        {
            Func(at(idx));
        }
    }
}


template <typename T, template <typename> class A>
template <class Function>
inline void CImage<T,A>::pforEach(Function Func) const
{
	const tSize sx = m_Size.x();
	const tSize sy = m_Size.y();
	const tSize offset = getXOffset();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(sx * sy > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < sy; ++j )
    {
        tSize idx = getIdx(0, j);
        for( tSize i = 0; i < sx; ++i, idx += offset )
        {
            Func(at(idx));
        }
    }
}


template <typename T, template <typename> class A>
inline typename CImage<T,A>::tRect CImage<T,A>::rect(const CPoint2i& Position, const CImSize& Size)
{
    return tRect(*this, Position, Size);
}


template <typename T, template <typename> class A>
inline const typename CImage<T,A>::tRect CImage<T,A>::rect(const CPoint2i& Position, const CImSize& Size) const
{
    return tRect(*this, Position, Size);
}


template <typename T, template <typename> class A>
inline typename CImage<T,A>::tRect CImage<T,A>::rect(const CRange& XRange, const CRange& YRange)
{
    return tRect(*this, XRange, YRange);
}

    
template <typename T, template <typename> class A>
inline const typename CImage<T,A>::tRect CImage<T,A>::rect(const CRange& XRange, const CRange& YRange) const
{
    return tRect(*this, XRange, YRange);
}


template <typename T, template <typename> class A>
inline typename CImage<T,A>::tRow CImage<T,A>::row(tSize y)
{
    return tRow(*this, y);
}


template <typename T, template <typename> class A>
inline const typename CImage<T,A>::tRow CImage<T,A>::row(tSize y) const
{
    return tRow(*this, y);
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::fill(const T c)
{
    pforEach(vpl::base::CFill<tPixel>(c));
    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::fillEntire(const T c)
{
    m_DataStorage.forEach(vpl::base::CFill<tPixel>(c));
    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::fillMargin(const T c)
{
    // Fill margin on the top and bottom
    tSize Count = m_Margin * m_YOffset;
    vpl::sys::memSet(getPtr(-m_Margin, -m_Margin), c, Count);
    vpl::sys::memSet(getPtr(-m_Margin, m_Size.y()), c, Count);

    // Fill left and right margin
    const tSize sx = m_Size.x();
    const tSize sy = m_Size.y();
    const tSize Margin = m_Margin;
    const T Val = c;

#pragma omp parallel for schedule(static) default(none) if(sx * sy > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < sy; ++j )
    {
        vpl::sys::memSet(getPtr(-Margin, j), Val, Margin);
        vpl::sys::memSet(getPtr(sx, j), Val, Margin);
    }
    
    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::mirrorMargin()
{
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
            at(-i, j) = at(i, jj);
            at(m_Size.x() - 1 + i, j) = at(m_Size.x() - 1 - i, jj);
        }
        if( j < 0 || j >= m_Size.y() )
        {
            for( i = 0; i < m_Size.x(); ++i )
            {
                at(i, j) = at(i, jj);
            }
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::replace(const T& Value, const T& NewValue)
{
    pforEach(vpl::base::CReplace<tPixel>(Value, NewValue));
    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::abs()
{
    pforEach(vpl::base::CAbs<tPixel>());
    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::limit(const T& Lower, const T& Upper)
{
    pforEach(vpl::base::CLimit<tPixel>(Lower, Upper));
    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::cut(const T& Lower, const T& Upper)
{
    static const T ClearValue = CPixelTraits<T>::getPixelMin();

    pforEach(vpl::base::CCut<tPixel>(Lower, Upper, ClearValue));
    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::subSample(const CImage<T,A>& Image, const tSize k, const tSize l)
{
    VPL_CHECK(k > 0 && l > 0, return *this);

    tSize XCount = vpl::math::getMin(Image.m_Size.x() / k, m_Size.x());
    tSize YCount = vpl::math::getMin(Image.m_Size.y() / l, m_Size.y());

    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, l * j);
        for( tSize i = 0; i < XCount; ++i, idx1 += getXOffset(), idx2 += k * Image.getXOffset() )
        {
            at(idx1) = Image.at(idx2);
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
inline T CImage<T,A>::interpolate(const CPoint3D& Point) const
{
    tSize iX = tSize(Point.x());
    tSize iY = tSize(Point.y());

    double dX = Point.x() - double(iX);
    double dY = Point.y() - double(iY);
    double dTempX = 1.0 - dX;
    double dTempY = 1.0 - dY;

    tSize idx = getIdx(iX, iY);

    // Interpolate subpixel value
    tPixel Value = tPixel(dTempX * dTempY * at(idx));
    Value += tPixel(dX * dTempY * at(idx + 1));
    Value += tPixel(dTempX * dY * at(idx + m_YOffset));
    Value += tPixel(dX * dY * at(idx + m_YOffset + 1));

    // Return the interpolated pixel value
    return Value;
}


template <typename T, template <typename> class A>
inline T CImage<T,A>::color2Pixel(CColor Color) const
{
    // Return the pixel value
    return CPixelConversion<tRGBPixel,T>::convert(tRGBPixel(Color.rgba()));
}


template <typename T, template <typename> class A>
inline bool CImage<T,A>::checkPosition(tSize x, tSize y) const
{
    return (x >= 0 && x < m_Size.x() && y >= 0 && y < m_Size.y());
}


//==============================================================================
/*
 * Image data serialization functions.
 */

template <typename T, template <typename> class A>
template <class S>
void CImage<T, A>::serializeNested(vpl::mod::CChannelSerializer<S>& Writer)
{
    // Image info
    Writer.write(vpl::sys::tInt32(m_Size.x()));
    Writer.write(vpl::sys::tInt32(m_Size.y()));

    // Image data
    for (tSize j = 0; j < m_Size.y(); ++j)
    {
        Writer.write(getRowPtr(j), m_Size.x());
    }
}

template <typename T, template <typename> class A>
template <class S>
void CImage<T,A>::serialize(vpl::mod::CChannelSerializer<S>& Writer)
{
    // Begin of data serialization block
    Writer.beginWrite(*this);
    // Write
    serializeNested(Writer);
    // End of the block
    Writer.endWrite(*this);
}

template <typename T, template <typename> class A>
template <class S>
void CImage<T, A>::deserializeNested(vpl::mod::CChannelSerializer<S>& Reader)
{
    // Read the image info struct
    vpl::sys::tInt32 Size;
    Reader.read(Size);
    m_Size.x() = Size;
    Reader.read(Size);
    m_Size.y() = Size;

    // Create a new slice
    resize(m_Size.x(), m_Size.y(), m_Margin);

    // Image data
    for (tSize j = 0; j < m_Size.y(); ++j)
    {
        Reader.read(getRowPtr(j), m_Size.x());
    }
}


template <typename T, template <typename> class A>
template <class S>
void CImage<T,A>::deserialize(vpl::mod::CChannelSerializer<S>& Reader)
{
    // Begin of data deserialization block
    Reader.beginRead(*this);
    // Read the image 
    deserializeNested(Reader);
    // End of the block
    Reader.endRead(*this);
}
