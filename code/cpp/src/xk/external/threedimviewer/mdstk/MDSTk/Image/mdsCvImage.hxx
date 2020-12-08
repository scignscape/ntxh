//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2010 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/18                          \n
 *
 * $Id: mdsCvImage.hxx 2117 2012-02-20 09:31:23Z spanel $
 *
 * Description:
 * - Class template providing image representation based on OpenCV library.
 */


//==============================================================================
/*
 * Methods templates.
 */

template <typename T>
CvImage<T>::CvImage()
    : m_Margin(0)
    , m_Data(EMPTY_CONST)
{
    m_Data.create(0, 0);
    m_pData = m_Data.getPtr();
}


template <typename T>
CvImage<T>::CvImage(tSize XSize, tSize YSize, tSize Margin)
    : m_Margin(Margin)
    , m_Data(EMPTY_CONST)
{
    tSize Margins = m_Margin << 1; // m_Margin * 2

    m_Data.create(XSize + Margins, YSize + Margins);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;
}


template <typename T>
CvImage<T>::CvImage(const CSize2i& Size, tSize Margin)
    : m_Margin(Margin)
    , m_Data(EMPTY_CONST)
{
    tSize Margins = m_Margin << 1; // m_Margin * 2

    m_Data.create(Size.x() + Margins, Size.y() + Margins);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;
}


template <typename T>
CvImage<T>::CvImage(const CvImage<T>& Image,
                    tSize x,
                    tSize y,
                    tSize XSize,
                    tSize YSize
                    )
    : m_Data(EMPTY_CONST)
{
    create(Image, x, y, XSize, YSize);
}


template <typename T>
CvImage<T>::CvImage(const CvImage<T>& Image,
                    tSize x,
                    tSize y,
                    tSize XSize,
                    tSize YSize,
                    EMakeRef
                    )
    : m_Data(EMPTY_CONST)
{
    create(Image, x, y, XSize, YSize, REFERENCE);
}


template <typename T>
CvImage<T>::CvImage(const tRect& Image)
    : m_Data(EMPTY_CONST)
{
    create(Image);
}


template <typename T>
CvImage<T>::CvImage(const tRect& Image, EMakeRef)
    : m_Data(EMPTY_CONST)
{
    create(Image, REFERENCE);
}


template <typename T>
CvImage<T>::CvImage(const CvImage<T>& Image)
    : mds::base::CObject()
    , tBase()
    , m_Margin(Image.getMargin())
    , m_Data(EMPTY_CONST)
{
    m_Data.create(Image.m_Data);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;
}


template <typename T>
CvImage<T>::CvImage(IplImage *pImage)
    : m_Margin(0)
    , m_Data(EMPTY_CONST)
{
    m_Data.create(pImage);
    m_pData = m_Data.getPtr();
}


template <typename T>
CvImage<T>::CvImage(const CvImage<T>& Image, EMakeRef)
    : m_Margin(Image.getMargin())
    , m_Data(EMPTY_CONST)
{
    m_Data.create(Image.m_Data, REFERENCE);
    m_pData = Image.m_pData;
}


template <typename T>
CvImage<T>::~CvImage()
{
}


template <typename T>
CvImage<T>& CvImage<T>::create(tSize XSize, tSize YSize, tSize Margin)
{
    m_Margin = Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Allocate the data
    m_Data.create(XSize + Margins, YSize + Margins);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    return *this;
}


template <typename T>
CvImage<T>& CvImage<T>::create(const CSize2i& Size, tSize Margin)
{
    m_Margin = Margin;
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Allocate the data
    m_Data.create(Size.x() + Margins, Size.y() + Margins);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    return *this;
}


template <typename T>
CvImage<T>& CvImage<T>::create(const CvImage<T>& Image,
                               tSize x,
                               tSize y,
                               tSize XSize,
                               tSize YSize
                               )
{
    MDS_ASSERT(x >= 0 && XSize >= 0 && x < Image.getXSize()
               && y >= 0 && YSize >= 0 && y < Image.getYSize());

    m_Margin = Image.getMargin();
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Allocate and copy the data
    m_Data.create(Image.m_Data, x, y, XSize + Margins, YSize + Margins);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    return *this;
}


template <typename T>
CvImage<T>& CvImage<T>::create(const CvImage<T>& Image,
                               tSize x,
                               tSize y,
                               tSize XSize,
                               tSize YSize,
                               EMakeRef
                               )
{
    MDS_ASSERT(x >= 0 && XSize >= 0 && x < Image.getXSize()
               && y >= 0 && YSize >= 0 && y < Image.getYSize());

    m_Margin = Image.getMargin();
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Allocate and copy the data
    m_Data.create(Image.m_Data, x, y, XSize + Margins, YSize + Margins, REFERENCE);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    return *this;
}


template <typename T>
CvImage<T>& CvImage<T>::create(const tRect& Image)
{
    m_Margin = Image.getMargin();
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Allocate and copy the data
    m_Data.create(Image.getImageRef().m_Data,
                  Image.getPos().x() - m_Margin,
                  Image.getPos().y() - m_Margin,
                  Image.getSize().x() + Margins,
                  Image.getSize().y() + Margins
                  );
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    return *this;
}


template <typename T>
CvImage<T>& CvImage<T>::create(const tRect& Image, EMakeRef)
{
    m_Margin = Image.getMargin();
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Allocate and copy the data
    m_Data.create(Image.getImageRef().m_Data,
                  Image.getPos().x() - m_Margin,
                  Image.getPos().y() - m_Margin,
                  Image.getSize().x() + Margins,
                  Image.getSize().y() + Margins,
                  REFERENCE
                  );
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    return *this;
}


template <typename T>
CvImage<T>& CvImage<T>::create(const CvImage<T>& Image)
{
    // Create copy of the existing image
    m_Margin = Image.getMargin();
    m_Data.create(Image.m_Data);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    return *this;
}


template <typename T>
CvImage<T>& CvImage<T>::create(IplImage *pImage)
{
    m_Margin = 0;
    m_Data.create(pImage);
    m_pData = m_Data.getPtr();

    return *this;
}


template <typename T>
CvImage<T>& CvImage<T>::create(const CvImage<T>& Image, EMakeRef)
{
    m_Margin = Image.m_Margin;
    m_Data.create(Image.m_Data, REFERENCE);
    m_pData = Image.m_pData;

    return *this;
}


template <typename T>
template <typename Derived>
CvImage<T>& CvImage<T>::convert(const CImageBase<Derived>& Image)
{
    typedef typename Derived::tPixel tSrcPixel;
    const Derived& SrcImage = Image.getImpl();

    m_Margin = SrcImage.getMargin();
    tSize Margins = m_Margin << 1; // m_Margin * 2

    // Reallocate the data
    m_Data.create(SrcImage.getXSize() + Margins, SrcImage.getYSize() + Margins);
    m_pData = m_Data.getPtr() + (getYOffset() + 1) * m_Margin;

    // Size of the image data to copy
    tSize XCount = getXSize() + m_Margin;
    tSize YCount = getYSize() + m_Margin;

    // Convert image pixels
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = -m_Margin; j < YCount; ++j )
    {
        tSize idx1 = getIdx(-m_Margin, j);
        tSize idx2 = SrcImage.getIdx(-m_Margin, j);
        for( tSize i = -m_Margin; i < XCount; ++i, idx1 += getXOffset(), idx2 += SrcImage.getXOffset() )
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

    tSize XCount = mds::math::getMin(getXSize(), Image.getXSize());
    tSize YCount = mds::math::getMin(getYSize(), Image.getYSize());

#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YCount; ++j )
    {
        mds::base::memCopy(m_pData + j * getYOffset(),
                           Image.m_pData + j * Image.getYOffset(),
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
    m_Data.create(pImage);
    m_pData = m_Data.getPtr();

    return *this;
}


template <typename T>
template <class Derived>
inline CvImage<T>& CvImage<T>::operator +=(const CImageBase<Derived>& Image)
{
    tSize XCount = mds::math::getMin(getXSize(), Image.getXSize());
    tSize YCount = mds::math::getMin(getYSize(), Image.getYSize());

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


template <typename T>
template <class Derived>
inline CvImage<T>& CvImage<T>::operator -=(const CImageBase<Derived>& Image)
{
    tSize XCount = mds::math::getMin(getXSize(), Image.getXSize());
    tSize YCount = mds::math::getMin(getYSize(), Image.getYSize());

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


template <typename T>
template <class Derived>
inline CvImage<T>& CvImage<T>::operator *=(const CImageBase<Derived>& Image)
{
    tSize XCount = mds::math::getMin(getXSize(), Image.getXSize());
    tSize YCount = mds::math::getMin(getYSize(), Image.getYSize());

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


template <typename T>
template <class Derived>
inline CvImage<T>& CvImage<T>::operator /=(const CImageBase<Derived>& Image)
{
    tSize XCount = mds::math::getMin(getXSize(), Image.getXSize());
    tSize YCount = mds::math::getMin(getYSize(), Image.getYSize());

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


template <typename T>
template <typename U>
inline CvImage<T>& CvImage<T>::operator +=(const CScalar<U>& c)
{
    pforEach(mds::base::CAdd<tPixel>(tPixel(c.value())));

    return *this;
}


template <typename T>
template <typename U>
inline CvImage<T>& CvImage<T>::operator -=(const CScalar<U>& c)
{
    pforEach(mds::base::CSub<tPixel>(tPixel(c.value)));

    return *this;
}


template <typename T>
template <typename U>
inline CvImage<T>& CvImage<T>::operator *=(const CScalar<U>& c)
{
    pforEach(mds::base::CMult<tPixel,U>(c.value()));

    return *this;
}


template <typename T>
template <typename U>
inline CvImage<T>& CvImage<T>::operator /=(const CScalar<U>& c)
{
    pforEach(mds::base::CDiv<tPixel,U>(c.value()));

    return *this;
}


template <typename T>
template <class Function>
inline Function CvImage<T>::forEach(Function Func)
{
    for( tSize j = 0; j < getYSize(); ++j )
    {
        tPixel *p = m_pData + j * getYOffset();
        for( tSize i = 0; i < getXSize(); ++i, ++p )
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
        for( tSize i = 0; i < getXSize(); ++i, ++p )
        {
            Func(*p);
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CvImage<T>::pforEach(Function Func)
{
    tSize YSize = getYSize();

#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YSize; ++j )
    {
        tPixel *p = m_pData + j * getYOffset();
        for( tSize i = 0; i < getXSize(); ++i, ++p )
        {
            Func(*p);
        }
    }
    return Func;
}


template <typename T>
template <class Function>
inline Function CvImage<T>::pforEach(Function Func) const
{
    tSize YSize = getYSize();

#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YSize; ++j )
    {
        const tPixel *p = m_pData + j * getYOffset();
        for( tSize i = 0; i < getXSize(); ++i, ++p )
        {
            Func(*p);
        }
    }
    return Func;
}


template <typename T>
inline typename CvImage<T>::tRect CvImage<T>::rect(const CPoint2i& Position, const CSize2i& Size)
{
    return tRect(*this, Position, Size);
}


template <typename T>
inline const typename CvImage<T>::tRect CvImage<T>::rect(const CPoint2i& Position, const CSize2i& Size) const
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
inline CvImage<T>& CvImage<T>::fill(const T& c)
{
    pforEach(mds::base::CFill<tPixel>(c));
    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::fillEntire(const T& c)
{
    mds::base::memSet(m_Data.getPtr(), c, m_Data.getSize());
    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::fillMargin(const T& c)
{
    // Fill margin on the top and bottom
    tSize Count = m_Margin * getYOffset();
    mds::base::memSet(getPtr(-m_Margin, -m_Margin), c, Count);
    mds::base::memSet(getPtr(-m_Margin, getYSize()), c, Count);

    // Fill left and right margin
    tSize YSize = getYSize();
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YSize; ++j )
    {
        mds::base::memSet(getPtr(-m_Margin, j), c, m_Margin);
        mds::base::memSet(getPtr(getXSize(), j), c, m_Margin);
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
    pforEach(mds::base::CReplace<tPixel>(Value, NewValue));
    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::abs()
{
    pforEach(mds::base::CAbs<tPixel>());
    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::limit(const T& Lower, const T& Upper)
{
    pforEach(mds::base::CLimit<tPixel>(Lower, Upper));
    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::cut(const T& Lower, const T& Upper)
{
    static const T ClearValue = CPixelTraits<T>::getPixelMin();

    pforEach(mds::base::CCut<tPixel>(Lower, Upper, ClearValue));
    return *this;
}


template <typename T>
inline CvImage<T>& CvImage<T>::subSample(const CvImage<T>& Image, tSize k, tSize l)
{
    MDS_CHECK(k > 0 && l > 0, return *this);

    tSize XCount = mds::math::getMin(Image.getXSize() / k, getXSize());
    tSize YCount = mds::math::getMin(Image.getYSize() / l, getYSize());

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
void CvImage<T>::serialize(mds::mod::CChannelSerializer<S>& Writer)
{
    // Begin of data serialization block
    Writer.beginWrite(*this);

    // Image info
    Writer.write(getXSize());
    Writer.write(getYSize());

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
void CvImage<T>::deserialize(mds::mod::CChannelSerializer<S>& Reader)
{
    // Begin of data deserialization block
    Reader.beginRead(*this);

    // Read the image info struct
    Reader.read(getXSize());
    Reader.read(getYSize());

    // Create a new slice
    create(getXSize(), getYSize(), m_Margin);

    // Image data
    for( tSize j = 0; j < getYSize(); ++j )
    {
        Reader.read(m_pData + j * getYOffset(), getXSize());
    }

    // End of the block
    Reader.endRead(*this);
}
