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
 * Copyright (c) 2010 by Michal Spanel       
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/18                       
 *
 * Description:
 * - Class template providing image representation based on OpenCV library.
 */


//==============================================================================
/*
 * Methods templates.
 */

template <typename T>
inline CvImage<T>::CvImage()
    : m_Margin(0)
    , m_Data(EMPTY_CONST)
{
    m_Data.resize(0, 0);
    m_pData = m_Data.getPtr();
}


template <typename T>
inline CvImage<T>::CvImage(tSize XSize, tSize YSize, tSize Margin)
    : m_Data(EMPTY_CONST)
{
    resize(XSize, YSize, Margin);
}


template <typename T>
inline CvImage<T>::CvImage(const CImSize& Size, tSize Margin)
    : m_Data(EMPTY_CONST)
{
    resize(Size, Margin);
}


template <typename T>
inline CvImage<T>::CvImage(const CvImage<T>& Image,
                           tSize x,
                           tSize y,
                           tSize XSize,
                           tSize YSize
                           )
    : m_Data(EMPTY_CONST)
{
    VPL_ASSERT(x >= 0 && XSize >= 0 && x < Image.getXSize()
               && y >= 0 && YSize >= 0 && y < Image.getYSize());

    copy(Image, x, y, XSize, YSize, -1);
}


template <typename T>
inline CvImage<T>::CvImage(const CvImage<T>& Image,
                           tSize x,
                           tSize y,
                           tSize XSize,
                           tSize YSize,
                           EMakeRef
                           )
    : m_Data(EMPTY_CONST)
{
    VPL_ASSERT(x >= 0 && XSize >= 0 && x < Image.getXSize()
               && y >= 0 && YSize >= 0 && y < Image.getYSize());

    makeRef(Image, x, y, XSize, YSize);
}


template <typename T>
inline CvImage<T>::CvImage(const tRect& Image)
    : m_Data(EMPTY_CONST)
{
    copy(Image, -1);
}


template <typename T>
inline CvImage<T>::CvImage(const tRect& Image, EMakeRef)
    : m_Data(EMPTY_CONST)
{
    makeRef(Image);
}


// Copy constructor
template <typename T>
inline CvImage<T>::CvImage(const CvImage<T>& Image)
    : vpl::base::CObject()
    , tBase()
    ,  m_Data(EMPTY_CONST)
{
    copy(Image, -1);
}


template <typename T>
inline CvImage<T>::CvImage(IplImage *pImage)
    : m_Margin(0)
    , m_Data(EMPTY_CONST)
{
    m_Data.fromIpl(pImage);
    m_pData = m_Data.getPtr();
}


template <typename T>
inline CvImage<T>::CvImage(const CvImage<T>& Image, EMakeRef)
    : m_Margin(Image.getMargin())
    , m_Data(EMPTY_CONST)
{
    m_Data.makeRef(Image.m_Data);
    m_pData = Image.m_pData;
}


template <typename T>
CvImage<T>::~CvImage()
{
}


template <typename T>
inline CvImage<T>& CvImage<T>::resize(tSize XSize, tSize YSize, tSize Margin)
{
    VPL_ASSERT(Margin >= 0);

    m_Margin = Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Allocate the data
    m_Data.resize(XSize + Margins, YSize + Margins);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    return *this;
}


template <typename T>
CvImage<T>& CvImage<T>::resize(const CImSize& Size, tSize Margin)
{
    VPL_ASSERT(Margin >= 0);

    m_Margin = Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Allocate the data
    m_Data.resize(Size.x() + Margins, Size.y() + Margins);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    return *this;
}


template <typename T>
CvImage<T>& CvImage<T>::copy(const CvImage<T>& Image, tSize Margin)
{
    // Margin size
    m_Margin = (Margin < 0) ? Image.getMargin() : Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Reallocate the data
    m_Data.resize(Image.getXSize() + Margins, Image.getYSize() + Margins);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    // Size of the data to copy
    const tSize MCount = vpl::math::getMin(m_Margin, Image.getMargin());
    const tSize XCount = getXSize() + (MCount << 1);
    const tSize YCount = getYSize() + MCount;

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


template <typename T>
CvImage<T>& CvImage<T>::copy(const CvImage<T>& Image,
                             tSize x,
                             tSize y,
                             tSize XSize,
                             tSize YSize,
                             tSize Margin
                             )
{
    VPL_ASSERT(x >= 0 && XSize >= 0 && x < Image.getXSize()
               && y >= 0 && YSize >= 0 && y < Image.getYSize());

    // Image size
    tSize sx = vpl::math::getMin(x + XSize, Image.getXSize()) - x;
    tSize sy = vpl::math::getMin(y + YSize, Image.getYSize()) - y;

    // Margin size
    m_Margin = (Margin < 0) ? Image.getMargin() : Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Reallocate the data
    m_Data.resize(sx + Margins, sy + Margins);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    // Size of the data to copy
    const tSize MCount = vpl::math::getMin(m_Margin, Image.getMargin());
    const tSize XCount = sx + (MCount << 1);
    const tSize YCount = sy + MCount;
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


template <typename T>
CvImage<T>& CvImage<T>::copy(const tRect& Image, tSize Margin)
{
    // Margin size
    m_Margin = (Margin < 0) ? Image.getMargin() : Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Allocate the data
    m_Data.resize(Image.getXSize() + Margins, Image.getYSize() + Margins);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    // Size of the data to copy
    const tSize MCount = vpl::math::getMin(m_Margin, Image.getMargin());
    const tSize XCount = Image.getXSize() + (MCount << 1);
    const tSize YCount = Image.getYSize() + MCount;

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


template <typename T>
inline CvImage<T>& CvImage<T>::makeRef(const CvImage<T>& Image)
{
    m_Margin = Image.m_Margin;
    m_Data.makeRef(Image.m_Data);
    m_pData = Image.m_pData;

    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::makeRef(const CvImage<T>& Image,
                                       tSize x,
                                       tSize y,
                                       tSize XSize,
                                       tSize YSize
                                       )
{
    VPL_ASSERT(x >= 0 && XSize >= 0 && x < Image.getXSize()
               && y >= 0 && YSize >= 0 && y < Image.getYSize());

    m_Margin = Image.getMargin();
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Allocate and copy the data
    m_Data.makeRef(Image.m_Data, x, y, XSize + Margins, YSize + Margins);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::makeRef(const tRect& Image)
{
    m_Margin = Image.getMargin();
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Allocate and copy the data
    m_Data.makeRef(Image.getImageRef().m_Data,
                   Image.getPos().x(),
                   Image.getPos().y(),
                   Image.getSize().x() + Margins,
                   Image.getSize().y() + Margins
                   );
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::fromIpl(IplImage *pImage)
{
    m_Margin = 0;
    m_Data.fromIpl(pImage);
    m_pData = m_Data.getPtr();

    return *this;
}


template <typename T>
template <typename Derived>
CvImage<T>& CvImage<T>::convert(const CImageBase<Derived>& Image, tSize Margin)
{
    typedef typename Derived::tPixel tSrcPixel;
    const Derived& SrcImage = Image.getImpl();

    // Margin size
    m_Margin = (Margin < 0) ? SrcImage.getMargin() : Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Reallocate the data
    m_Data.resize(SrcImage.getXSize() + Margins, SrcImage.getYSize() + Margins);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    // Size of the image data to copy
    const tSize MCount = vpl::math::getMin(m_Margin, SrcImage.getMargin());
    const tSize XCount = getXSize() + MCount;
    const tSize YCount = getYSize() + MCount;
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


template <typename T>
CvImage<T>& CvImage<T>::operator =(const CvImage<T>& Image)
{
    if( &Image == this )
    {
        return *this;
    }

    const tSize XCount = vpl::math::getMin(getXSize(), Image.getXSize());
    const tSize YCount = vpl::math::getMin(getYSize(), Image.getYSize());

#pragma omp parallel for schedule(static) default(none) shared(Image) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YCount; ++j )
    {
        vpl::sys::memCopy(getRowPtr(j),
                          Image.getRowPtr(j),
                          XCount
                          );
    }

    return *this;
}


template <typename T>
CvImage<T>& CvImage<T>::operator =(IplImage *pImage)
{
    if( m_Data.asIpl() == pImage )
    {
        return *this;
    }

    m_Margin = 0;
    m_Data.fromIpl(pImage);
    m_pData = m_Data.getPtr();

    return *this;
}


template <typename T>
template <class Derived>
inline CvImage<T>& CvImage<T>::operator +=(const CImageBase<Derived>& Image)
{
    const tSize XCount = vpl::math::getMin(getXSize(), Image.getXSize());
    const tSize YCount = vpl::math::getMin(getYSize(), Image.getYSize());
    const tSize Offset = getXOffset();
    const tSize SrcOffset = Image.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Image) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += Offset, idx2 += SrcOffset )
        {
            at(idx1) += Image.at(idx2);
        }
    }

    return *this;
}


template <typename T>
template <class Derived>
inline CvImage<T>& CvImage<T>::operator -=(const CImageBase<Derived>& Image)
{
    const tSize XCount = vpl::math::getMin(getXSize(), Image.getXSize());
    const tSize YCount = vpl::math::getMin(getYSize(), Image.getYSize());
    const tSize Offset = getXOffset();
    const tSize SrcOffset = Image.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Image) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += Offset, idx2 += SrcOffset )
        {
            at(idx1) -= Image.at(idx2);
        }
    }

    return *this;
}


template <typename T>
template <class Derived>
inline CvImage<T>& CvImage<T>::operator *=(const CImageBase<Derived>& Image)
{
    const tSize XCount = vpl::math::getMin(getXSize(), Image.getXSize());
    const tSize YCount = vpl::math::getMin(getYSize(), Image.getYSize());
    const tSize Offset = getXOffset();
    const tSize SrcOffset = Image.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Image) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += Offset, idx2 += SrcOffset )
        {
            at(idx1) *= Image.at(idx2);
        }
    }

    return *this;
}


template <typename T>
template <class Derived>
inline CvImage<T>& CvImage<T>::operator /=(const CImageBase<Derived>& Image)
{
    const tSize XCount = vpl::math::getMin(getXSize(), Image.getXSize());
    const tSize YCount = vpl::math::getMin(getYSize(), Image.getYSize());
    const tSize Offset = getXOffset();
    const tSize SrcOffset = Image.getXOffset();

#pragma omp parallel for schedule(static) default(none) shared(Image) if(XCount * YCount > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < XCount; ++i, idx1 += Offset, idx2 += SrcOffset )
        {
            at(idx1) /= Image.at(idx2);
        }
    }

    return *this;
}


template <typename T>
template <typename U>
inline CvImage<T>& CvImage<T>::operator +=(const CScalar<U>& c)
{
    pforEach(vpl::base::CAdd<tPixel>(tPixel(c.value())));

    return *this;
}


template <typename T>
template <typename U>
inline CvImage<T>& CvImage<T>::operator -=(const CScalar<U>& c)
{
    pforEach(vpl::base::CSub<tPixel>(tPixel(c.value)));

    return *this;
}


template <typename T>
template <typename U>
inline CvImage<T>& CvImage<T>::operator *=(const CScalar<U>& c)
{
    pforEach(vpl::base::CMult<tPixel,U>(c.value()));

    return *this;
}


template <typename T>
template <typename U>
inline CvImage<T>& CvImage<T>::operator /=(const CScalar<U>& c)
{
    pforEach(vpl::base::CDiv<tPixel,U>(c.value()));

    return *this;
}


template <typename T>
template <class Function>
inline Function CvImage<T>::forEach(Function Func)
{
    for( tSize j = 0; j < getYSize(); ++j )
    {
        tPixel *p = m_pData + j * getYOffset();
        for( tSize i = 0; i < getXSize(); ++i, p += getXOffset() )
        {
            Func(*p);
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CvImage<T>::forEach(Function Func) const
{
    for( tSize j = 0; j < getYSize(); ++j )
    {
        const tPixel *p = m_pData + j * getYOffset();
        for( tSize i = 0; i < getXSize(); ++i, p += getXOffset() )
        {
            Func(*p);
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline void CvImage<T>::pforEach(Function Func)
{
    const tSize XSize = getXSize();
    const tSize YSize = getYSize();
	const tSize Offset = getXOffset();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(XSize * YSize > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YSize; ++j )
    {
        tPixel *p = getPtr(0, j);
        for( tSize i = 0; i < XSize; ++i, p += Offset )
        {
            Func(*p);
        }
    }
}


template <typename T>
template <class Function>
inline void CvImage<T>::pforEach(Function Func) const
{
    const tSize XSize = getXSize();
    const tSize YSize = getYSize();
	const tSize Offset = getXOffset();

#pragma omp parallel for schedule(static) default(none) firstprivate(Func) if(XSize * YSize > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YSize; ++j )
    {
        tPixel *p = getPtr(0, j);
        for( tSize i = 0; i < XSize; ++i, p += Offset )
        {
            Func(*p);
        }
    }
}


template <typename T>
inline typename CvImage<T>::tRect CvImage<T>::rect(const CPoint2i& Position, const CImSize& Size)
{
    return tRect(*this, Position, Size);
}


template <typename T>
inline const typename CvImage<T>::tRect CvImage<T>::rect(const CPoint2i& Position, const CImSize& Size) const
{
    return tRect(*this, Position, Size);
}


template <typename T>
inline typename CvImage<T>::tRect CvImage<T>::rect(const CRange& XRange, const CRange& YRange)
{
    return tRect(*this, XRange, YRange);
}

    
template <typename T>
inline const typename CvImage<T>::tRect CvImage<T>::rect(const CRange& XRange, const CRange& YRange) const
{
    return tRect(*this, XRange, YRange);
}


template <typename T>
inline typename CvImage<T>::tRow CvImage<T>::row(tSize y)
{
    return tRow(*this, y);
}


template <typename T>
inline const typename CvImage<T>::tRow CvImage<T>::row(tSize y) const
{
    return tRow(*this, y);
}


template <typename T>
inline CvImage<T>& CvImage<T>::fill(const T c)
{
    pforEach(vpl::base::CFill<tPixel>(c));
    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::fillEntire(const T c)
{
    vpl::sys::memSet(m_Data.getPtr(), c, m_Data.getSize());
    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::fillMargin(const T c)
{
    // Fill margin on the top and bottom
    tSize Count = m_Margin * getYOffset();
    vpl::sys::memSet(getPtr(-m_Margin, -m_Margin), c, Count);
    vpl::sys::memSet(getPtr(-m_Margin, getYSize()), c, Count);

    // Fill left and right margin
    const tSize XSize = getXSize();
    const tSize YSize = getYSize();
    const tSize Margin = m_Margin;
    const T Val = c;

#pragma omp parallel for schedule(static) default(none) if(XSize * YSize > VPL_MIN_OMP_COMPLEXITY)
    for( tSize j = 0; j < YSize; ++j )
    {
        vpl::sys::memSet(getPtr(-Margin, j), Val, Margin);
        vpl::sys::memSet(getPtr(XSize, j), Val, Margin);
    }

    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::mirrorMargin()
{
    for( tSize j = -m_Margin; j < getYSize() + m_Margin; ++j )
    {
        tSize jj = j;
        if( j < 0 )
        {
            jj = -j;
        }
        else if ( j >= getYSize() )
        {
            jj = 2 * getYSize() - 2 - j;
        }
        tSize i;
        for( i = 1; i <= m_Margin; ++i )
        {
            at(-i, j) = at(i, jj);
            at(getXSize() - 1 + i, j) = at(getXSize() - 1 - i, jj);
        }
        if( j < 0 || j >= getYSize() )
        {
            for( i = 0; i < getXSize(); ++i )
            {
                at(i, j) = at(i, jj);
            }
        }
    }

    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::replace(const T& Value, const T& NewValue)
{
    pforEach(vpl::base::CReplace<tPixel>(Value, NewValue));
    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::abs()
{
    pforEach(vpl::base::CAbs<tPixel>());
    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::limit(const T& Lower, const T& Upper)
{
    pforEach(vpl::base::CLimit<tPixel>(Lower, Upper));
    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::cut(const T& Lower, const T& Upper)
{
    static const T ClearValue = CPixelTraits<T>::getPixelMin();

    pforEach(vpl::base::CCut<tPixel>(Lower, Upper, ClearValue));
    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::subSample(const CvImage<T>& Image, const tSize k, const tSize l)
{
    VPL_CHECK(k > 0 && l > 0, return *this);

    tSize XCount = vpl::math::getMin(Image.getXSize() / k, getXSize());
    tSize YCount = vpl::math::getMin(Image.getYSize() / l, getYSize());

    for( tSize j = 0; j < YCount; ++j )
    {
        T *p = m_pData + j * getYOffset();
        const T *pI = Image.m_pData + l * j * Image.getYOffset();
        for( tSize i = 0; i < XCount; ++i )
        {
            *(p++) = *pI;
            pI += k;
        }
    }

    return *this;
}


template <typename T>
inline T CvImage<T>::interpolate(const CPoint3D& Point) const
{
    tSize iX = int(Point.x());
    tSize iY = int(Point.y());

    double dX = Point.x() - double(iX);
    double dY = Point.y() - double(iY);
    double dTempX = 1.0 - dX;
    double dTempY = 1.0 - dY;

    const T *p = m_pData + iY * getYOffset() + iX;

    // Interpolate subpixel value
    tPixel Value = tPixel(dTempX * dTempY * *(p));
    Value += tPixel(dX * dTempY * *(p + 1));
    Value += tPixel(dTempX * dY * *(p + getYOffset()));
    Value += tPixel(dX * dY * *(p + getYOffset() + 1));

    // Return the interpolated pixel value
    return Value;
}


template <typename T>
inline T CvImage<T>::color2Pixel(CColor Color) const
{
    // Return the pixel value
    return CPixelConversion<tRGBPixel,T>::convert(tRGBPixel(Color.rgba()));
}


template <typename T>
inline bool CvImage<T>::checkPosition(tSize x, tSize y) const
{
    return (x >= 0 && x < getXSize() && y >= 0 && y < getYSize());
}


//==============================================================================
/*
 * Image data serialization functions.
 */

template <typename T>
template <class S>
void CvImage<T>::serialize(vpl::mod::CChannelSerializer<S>& Writer)
{
    // Begin of data serialization block
    Writer.beginWrite(*this);

    // Image info
    Writer.write(vpl::sys::tInt32(getXSize()));
	Writer.write(vpl::sys::tInt32(getYSize()));

    // Image data
    for( tSize j = 0; j < getYSize(); ++j )
    {
        Writer.write(m_pData + j * getYOffset(), getXSize());
    }

    // End of the block
    Writer.endWrite(*this);
}


template <typename T>
template <class S>
void CvImage<T>::deserialize(vpl::mod::CChannelSerializer<S>& Reader)
{
    // Begin of data deserialization block
    Reader.beginRead(*this);

    // Read the image info struct
	vpl::sys::tInt32 XSize, YSize;
    Reader.read(XSize);
    Reader.read(YSize);

    // Create a new slice
    resize(XSize, YSize, m_Margin);

    // Image data
    for( tSize j = 0; j < getYSize(); ++j )
    {
        Reader.read(m_pData + j * getYOffset(), getXSize());
    }

    // End of the block
    Reader.endRead(*this);
}
