//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/08                          \n
 *
 * $Id: mdsImage.hxx 2099 2012-02-17 00:24:16Z spanel $
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
    : m_Size(XSize, YSize)
    , m_Margin(Margin)
    , m_DataStorage(EMPTY_CONST)
{
    // Helper value
    tSize Margins = m_Margin << 1;

    // Allocate the data
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.create(m_YOffset * (YSize + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;
}


template <typename T, template <typename> class A>
inline CImage<T,A>::CImage(const CSize2i& Size, tSize Margin)
    : m_Size(Size)
    , m_Margin(Margin)
    , m_DataStorage(EMPTY_CONST)
{
    // Helper value
    tSize Margins = m_Margin << 1;

    // Allocate the data
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.create(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;
}


template <typename T, template <typename> class A>
CImage<T,A>::CImage(const CImage<T,A>& Image,
                    tSize x,
                    tSize y,
                    tSize XSize,
                    tSize YSize
                    )
    : m_DataStorage(EMPTY_CONST)
{
    MDS_ASSERT(x >= 0 && XSize >= 0 && x < Image.m_Size.x()
               && y >= 0 && YSize >= 0 && y < Image.m_Size.y());

    tSize Margins = Image.m_Margin << 1;

    // Size of the image
    m_Size.x() = mds::math::getMin(x + XSize, Image.m_Size.x()) - x;
    m_Size.y() = mds::math::getMin(y + YSize, Image.m_Size.y()) - y;

    // Allocate the data
    m_Margin = Image.m_Margin;
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.create(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    // Size of the data to copy
    tSize XCount = m_Size.x() + Margins;
    tSize YCount = m_Size.y() + m_Margin;

    // Copy the data
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = -m_Margin; j < YCount; ++j )
    {
        mds::base::memCopy(getPtr(-m_Margin, j), 
                           Image.getPtr(-m_Margin + x, j + y),
                           XCount
                           );
    }
}


template <typename T, template <typename> class A>
CImage<T,A>::CImage(const CImage<T,A>& Image,
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
    MDS_ASSERT(x >= 0 && XSize >= 0 && x < Image.m_Size.x()
               && y >= 0 && YSize >= 0 && y < Image.m_Size.y());

    // Image size
    m_Size.x() = mds::math::getMin(x + XSize, Image.m_Size.x()) - x;
    m_Size.y() = mds::math::getMin(y + YSize, Image.m_Size.y()) - y;

    // Image data
    m_ZeroOffset += y * m_YOffset + x;
}


template <typename T, template <typename> class A>
CImage<T,A>::CImage(const tRect& Image)
    : m_Size(Image.getSize())
    , m_Margin(Image.getImageRef().m_Margin)
    , m_DataStorage(EMPTY_CONST)
{
    // Helper value
    tSize Margins = m_Margin << 1;

    // Data allocation
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.create(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    // Size of the data to copy
    tSize XCount = m_Size.x() + Margins;
    tSize YCount = m_Size.y() + m_Margin;

    // Copy the data
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = -m_Margin; j < YCount; ++j )
    {
        mds::base::memCopy(getPtr(-m_Margin, j), 
                           Image.getImageRef().getPtr(-m_Margin, j),
                           XCount
                           );
    }
}


template <typename T, template <typename> class A>
CImage<T,A>::CImage(const tRect& Image, EMakeRef)
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
CImage<T,A>::CImage(const CImage<T,A>& Image)
    : mds::base::CObject()
    , tBase()
    , m_Size(Image.m_Size)
    , m_Margin(Image.m_Margin)
    , m_DataStorage(EMPTY_CONST)
{
    // Helper value
    tSize Margins = Image.m_Margin << 1;

    // Allocate the data
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.create(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    // Size of the data to copy
    tSize XCount = m_Size.x() + Margins;
    tSize YCount = m_Size.y() + m_Margin;

    // Copy the data
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = -m_Margin; j < YCount; ++j )
    {
        mds::base::memCopy(getPtr(-m_Margin, j), 
                           Image.getPtr(-m_Margin, j),
                           XCount
                           );
    }
}


template <typename T, template <typename> class A>
CImage<T,A>::CImage(const CImage<T,A>& Image, EMakeRef)
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
inline CImage<T,A>& CImage<T,A>::create(tSize XSize, tSize YSize, tSize Margin)
{
    tSize Margins = Margin << 1;

    // Reallocate the data
    m_Size.x() = XSize;
    m_Size.y() = YSize;
    m_Margin = Margin;
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.create(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::create(const CSize2i& Size, tSize Margin)
{
    // Helper value
    tSize Margins = Margin << 1;

    // Reallocate the data
    m_Size = Size;
    m_Margin = Margin;
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.create(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    return *this;
}


template <typename T, template <typename> class A>
CImage<T,A>& CImage<T,A>::create(const CImage<T,A>& Image,
                                 tSize x,
                                 tSize y,
                                 tSize XSize,
                                 tSize YSize
                                 )
{
    // Check the position
    MDS_CHECK(x >= 0 && XSize >= 0 && x < Image.m_Size.x()
              && y >= 0 && YSize >= 0 && y < Image.m_Size.y(), return *this);

    // Helper value
    tSize Margins = Image.m_Margin << 1;
    
    // Image size
    m_Size.x() = mds::math::getMin(x + XSize, Image.m_Size.x()) - x;
    m_Size.y() = mds::math::getMin(y + YSize, Image.m_Size.y()) - y;

    // Reallocate the data
    m_Margin = Image.m_Margin;
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.create(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    // Size of the data to copy
    tSize XCount = m_Size.x() + Margins;
    tSize YCount = m_Size.y() + m_Margin;

    // Copy the data
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = -m_Margin; j < YCount; ++j )
    {
        mds::base::memCopy(getPtr(-m_Margin, j), 
                           Image.getPtr(-m_Margin + x, j + y),
                           XCount
                           );
    }

    return *this;
}


template <typename T, template <typename> class A>
CImage<T,A>& CImage<T,A>::create(const CImage<T,A>& Image,
                                 tSize x,
                                 tSize y,
                                 tSize XSize,
                                 tSize YSize,
                                 EMakeRef
                                 )
{
    // Check the position
    MDS_CHECK(x >= 0 && XSize >= 0 && x < Image.m_Size.x()
              && y >= 0 && YSize >= 0 && y < Image.m_Size.y(), return *this);

    // Image size
    m_Size.x() = mds::math::getMin(x + XSize, Image.m_Size.x()) - x;
    m_Size.y() = mds::math::getMin(y + YSize, Image.m_Size.y()) - y;

    // Create a reference to the image data
    m_Margin = Image.m_Margin;
    m_YOffset = Image.m_YOffset;
    m_DataStorage.create(Image.m_DataStorage, REFERENCE);
    m_ZeroOffset = Image.m_ZeroOffset + y * m_YOffset + x;

    return *this;
}


template <typename T, template <typename> class A>
CImage<T,A>& CImage<T,A>::create(const tRect& Image)
{
    // Helper value
    tSize Margins = Image.getImageRef().m_Margin << 1;

    // Reallocate the data
    m_Size = Image.getSize();
    m_Margin = Image.getImageRef().m_Margin;
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.create(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    // Size of the data to copy
    tSize XCount = m_Size.x() + Margins;
    tSize YCount = m_Size.y() + m_Margin;

    // Copy the data
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = -m_Margin; j < YCount; ++j )
    {
        mds::base::memCopy(getPtr(-m_Margin, j), 
                           Image.getImageRef().getPtr(-m_Margin, j),
                           XCount
                           );
    }

    return *this;
}


template <typename T, template <typename> class A>
CImage<T,A>& CImage<T,A>::create(const tRect& Image, EMakeRef)
{
    // Create a reference to the image data
    m_Size = Image.getSize();
    m_Margin = Image.getImageRef().m_Margin;
    m_YOffset = Image.getImageRef().m_YOffset;
    m_DataStorage.create(Image.getImageRef().m_DataStorage, REFERENCE);
    m_ZeroOffset = Image.getImageRef().m_ZeroOffset + Image.getPos().y() * m_YOffset + Image.getPos().x();

    return *this;
}


// Creates a new image
template <typename T, template <typename> class A>
CImage<T,A>& CImage<T,A>::create(const CImage<T,A>& Image)
{
    // Helper value
    tSize Margins = Image.m_Margin << 1;

    // Reallocate the data
    m_Size = Image.m_Size;
    m_Margin = Image.m_Margin;
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.create(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    // Size of the data to copy
    tSize XCount = m_Size.x() + Margins;
    tSize YCount = m_Size.y() + m_Margin;

    // Copy the data
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = -m_Margin; j < YCount; ++j )
    {
        mds::base::memCopy(getPtr(-m_Margin, j), 
                           Image.getPtr(-m_Margin, j),
                           XCount
                           );
    }

    return *this;
}


// Creates a new image
template <typename T, template <typename> class A>
CImage<T,A>& CImage<T,A>::create(const CImage<T,A>& Image, EMakeRef)
{
    // Make a reference to the data
    m_Size = Image.m_Size;
    m_Margin = Image.m_Margin;
    m_YOffset = Image.m_YOffset;
    m_DataStorage.create(Image.m_DataStorage, REFERENCE);
    m_ZeroOffset = Image.m_ZeroOffset;

    return *this;
}


// Image conversion
template <typename T, template <typename> class A>
template <typename Derived>
CImage<T,A>& CImage<T,A>::convert(const CImageBase<Derived>& Image)
{
    const Derived& SrcImage = Image.getImpl();
    typedef typename Derived::tPixel tSrcPixel;

    // Helper value
    tSize Margins = SrcImage.getMargin() << 1; // m_Margin * 2

    // Reallocate the data
    m_Size = SrcImage.getSize();
    m_Margin = SrcImage.getMargin();
    m_YOffset = m_Size.x() + Margins;
    m_DataStorage.create(m_YOffset * (m_Size.y() + Margins));
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    // Size of the image data to copy
    tSize XCount = m_Size.x() + m_Margin;
    tSize YCount = m_Size.y() + m_Margin;

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


// Assignment operator
template <typename T, template <typename> class A>
CImage<T,A>& CImage<T,A>::operator =(const CImage& Image)
{
    if( &Image == this )
    {
        return *this;
    }
    
    CSize2i Count = m_Size & Image.getSize();
    
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < Count.y(); ++j )
    {
        mds::base::memCopy(getRowPtr(j),
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
    CSize2i Count = m_Size & Image.getSize();

#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < Count.y(); ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < Count.x(); ++i, idx1 += getXOffset(), idx2 += Image.getXOffset() )
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
    CSize2i Count = m_Size & Image.getSize();

#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < Count.y(); ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < Count.x(); ++i, idx1 += getXOffset(), idx2 += Image.getXOffset() )
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
    CSize2i Count = m_Size & Image.getSize();

#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < Count.y(); ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < Count.x(); ++i, idx1 += getXOffset(), idx2 += Image.getXOffset() )
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
    CSize2i Count = m_Size & Image.getSize();

#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < Count.y(); ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, j);
        for( tSize i = 0; i < Count.x(); ++i, idx1 += getXOffset(), idx2 += Image.getXOffset() )
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
    pforEach(mds::base::CAdd<tPixel>(tPixel(c.value())));

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CImage<T,A>& CImage<T,A>::operator -=(const CScalar<U>& c)
{
    pforEach(mds::base::CSub<tPixel>(tPixel(c.value())));

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CImage<T,A>& CImage<T,A>::operator *=(const CScalar<U>& c)
{
    pforEach(mds::base::CMult<tPixel,U>(c.value()));

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CImage<T,A>& CImage<T,A>::operator /=(const CScalar<U>& c)
{
    pforEach(mds::base::CDiv<tPixel,U>(c.value()));

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
inline Function CImage<T,A>::pforEach(Function Func)
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


template <typename T, template <typename> class A>
template <class Function>
inline Function CImage<T,A>::pforEach(Function Func) const
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


template <typename T, template <typename> class A>
inline typename CImage<T,A>::tRect CImage<T,A>::rect(const CPoint2i& Position, const CSize2i& Size)
{
    return tRect(*this, Position, Size);
}


template <typename T, template <typename> class A>
inline const typename CImage<T,A>::tRect CImage<T,A>::rect(const CPoint2i& Position, const CSize2i& Size) const
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
inline CImage<T,A>& CImage<T,A>::fill(const T& c)
{
    pforEach(mds::base::CFill<tPixel>(c));
    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::fillEntire(const T& c)
{
    m_DataStorage.forEach(mds::base::CFill<tPixel>(c));
    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::fillMargin(const T& c)
{
    // Fill margin on the top and bottom
    tSize Count = m_Margin * m_YOffset;
    mds::base::memSet(getPtr(-m_Margin, -m_Margin), c, Count);
    mds::base::memSet(getPtr(-m_Margin, m_Size.y()), c, Count);

    // Fill left and right margin
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < m_Size.y(); ++j )
    {
        mds::base::memSet(getPtr(-m_Margin, j), c, m_Margin);
        mds::base::memSet(getPtr(m_Size.x(), j), c, m_Margin);
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
    pforEach(mds::base::CReplace<tPixel>(Value, NewValue));
    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::abs()
{
    pforEach(mds::base::CAbs<tPixel>());
    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::limit(const T& Lower, const T& Upper)
{
    pforEach(mds::base::CLimit<tPixel>(Lower, Upper));
    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::cut(const T& Lower, const T& Upper)
{
    static const T ClearValue = CPixelTraits<T>::getPixelMin();

    pforEach(mds::base::CCut<tPixel>(Lower, Upper, ClearValue));
    return *this;
}


template <typename T, template <typename> class A>
inline CImage<T,A>& CImage<T,A>::subSample(const CImage<T,A>& Image, tSize k, tSize l)
{
    MDS_CHECK(k > 0 && l > 0, return *this);

    tSize XCount = mds::math::getMin(Image.m_Size.x() / k, m_Size.x());
    tSize YCount = mds::math::getMin(Image.m_Size.y() / l, m_Size.y());

    for( tSize j = 0; j < YCount; ++j )
    {
        tSize idx1 = getIdx(0, j);
        tSize idx2 = Image.getIdx(0, l * j);
        for( tSize i = 0; i < XCount; ++i, idx1 += getXOffset(), idx1 += k * Image.getXOffset() )
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
void CImage<T,A>::serialize(mds::mod::CChannelSerializer<S>& Writer)
{
    // Begin of data serialization block
    Writer.beginWrite(*this);

    // Image info
    Writer.write(m_Size.x());
    Writer.write(m_Size.y());

    // Image data
    for( tSize j = 0; j < m_Size.y(); ++j )
    {
        Writer.write(getRowPtr(j), m_Size.x());
    }

    // End of the block
    Writer.endWrite(*this);
}


// Serialization over a shared memory
/*template <typename T, template <typename> class A>
void CImage<T,A>::serialize(mds::mod::CSHMSerializer& Writer)
{
    // Begin of data serialization block
    Writer.beginWrite(*this);

    // Complete image info
    Writer.write(m_Size.x());
    Writer.write(m_Size.y());
    Writer.write(m_Margin);
    Writer.write(m_YOffset);
    Writer.write(m_DataStorage);

    // End of the block
    Writer.endWrite(*this);
}*/


template <typename T, template <typename> class A>
template <class S>
void CImage<T,A>::deserialize(mds::mod::CChannelSerializer<S>& Reader)
{
    // Begin of data deserialization block
    Reader.beginRead(*this);

    // Read the image info struct
    Reader.read(m_Size.x());
    Reader.read(m_Size.y());

    // Create a new slice
    create(m_Size.x(), m_Size.y(), m_Margin);

    // Image data
    for( tSize j = 0; j < m_Size.y(); ++j )
    {
        Reader.read(getRowPtr(j), m_Size.x());
    }

    // End of the block
    Reader.endRead(*this);
}


/*template <typename T, template <typename> class A>
void CImage<T,A>::deserialize(mds::mod::CSHMSerializer& Reader)
{
    // Begin of data deserialization block
    Reader.beginRead(*this);

    // Image info
    Reader.read(m_Size.x());
    Reader.read(m_Size.y());
    Reader.read(m_Margin);
    Reader.read(m_YOffset);
    Reader.read(m_DataStorage);

    // Check image size
    tSize Size = m_YOffset * (m_Size.y() + 2 * m_Margin);
    if( Size < 0 || Size > m_DataStorage.getSize() )
    {
        throw mds::mod::Serializer::CReadFailed();
    }

    // Initialize the internal pointer
    m_ZeroOffset = (m_YOffset + 1) * m_Margin;

    // End of the block
    Reader.endRead(*this);
}*/

