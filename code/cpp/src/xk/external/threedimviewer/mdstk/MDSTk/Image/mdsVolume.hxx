//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/07/11                          \n
 *
 * $Id: mdsVolume.hxx 2106 2012-02-18 21:55:47Z spanel $
 *
 * Description:
 * - Template providing basic volume operations.
 */


//=============================================================================
/*
 * Implementation of the mds::img::CVolume class.
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
    : m_Size(XSize, YSize, ZSize)
    , m_Margin(Margin)
    , m_DataStorage(EMPTY_CONST)
{
    // Helper value
    tSize Margins = 2 * m_Margin;

    // Data allocation
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.create(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>::CVolume(const CSize3i& Size, tSize Margin)
    : m_Size(Size)
    , m_Margin(Margin)
    , m_DataStorage(EMPTY_CONST)
{
    // Helper value
    tSize Margins = 2 * m_Margin;

    // Data allocation
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.create(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;
}


template <typename T, template <typename> class A>
CVolume<T,A>::CVolume(const CVolume<T,A>& Volume,
                      tSize x,
                      tSize y,
                      tSize z,
                      tSize XSize,
                      tSize YSize,
                      tSize ZSize
                      )
    : m_DataStorage(EMPTY_CONST)
{
    MDS_ASSERT(x >= 0 && XSize >= 0 && x < Volume.m_Size.x()
               && y >= 0 && YSize >= 0 && y < Volume.m_Size.y()
               && z >= 0 && ZSize >= 0 && z < Volume.m_Size.z());

    // Helper value
    tSize Margins = 2 * Volume.m_Margin;

    // Size of the volume data to copy
    m_Size.x() = mds::math::getMin(x + XSize, Volume.m_Size.x()) - x;
    m_Size.y() = mds::math::getMin(y + YSize, Volume.m_Size.y()) - y;
    m_Size.z() = mds::math::getMin(z + ZSize, Volume.m_Size.z()) - z;

    // Data allocation
    m_Margin = Volume.m_Margin;
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.create(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    // Size of the volume data to copy
    tSize XCount = m_Size.x() + m_Margin;
    tSize YCount = m_Size.y() + m_Margin;
    tSize ZCount = m_Size.z() + m_Margin;

    // Copy the data
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = -m_Margin; k < ZCount; ++k )
    {
        for( tSize j = -m_Margin; j < YCount; ++j )
        {
            tSize idx1 = getIdx(-m_Margin, j, k);
            tSize idx2 = Volume.getIdx(-m_Margin + x, j + y, k + z);
            for( tSize i = -m_Margin; i < XCount; ++i, idx1 += getXOffset(), idx2 += Volume.getXOffset() )
            {
                at(idx1) = Volume.at(idx2);
            }
        }
    }
}


template <typename T, template <typename> class A>
CVolume<T,A>::CVolume(const CVolume<T,A>& Volume,
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
    MDS_ASSERT(x >= 0 && XSize >= 0 && x < Volume.m_Size.x()
               && y >= 0 && YSize >= 0 && y < Volume.m_Size.y()
               && z >= 0 && ZSize >= 0 && z < Volume.m_Size.z());

    // Image size
    m_Size.x() = mds::math::getMin(x + XSize, Volume.m_Size.x()) - x;
    m_Size.y() = mds::math::getMin(y + YSize, Volume.m_Size.y()) - y;
    m_Size.z() = mds::math::getMin(z + ZSize, Volume.m_Size.z()) - z;

    // Image data
    m_ZeroOffset += z * m_ZOffset + y * m_YOffset + x;
}


template <typename T, template <typename> class A>
CVolume<T,A>::CVolume(const tRect& Volume)
    : m_Size(Volume.getSize())
    , m_Margin(Volume.getVolumeRef().m_Margin)
    , m_DataStorage(EMPTY_CONST)
{
    // Helper value
    tSize Margins = 2 * m_Margin;

    // Data allocation
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.create(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    // Size of the volume data to copy
    tSize XCount = m_Size.x() + m_Margin;
    tSize YCount = m_Size.y() + m_Margin;
    tSize ZCount = m_Size.z() + m_Margin;

    // Copy the data
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = -m_Margin; k < ZCount; ++k )
    {
        for( tSize j = -m_Margin; j < YCount; ++j )
        {
            tSize idx1 = getIdx(-m_Margin, j, k);
            tSize idx2 = Volume.getIdx(-m_Margin, j, k);
            for( tSize i = -m_Margin; i < XCount; ++i, idx1 += getXOffset(), idx2 += Volume.getXOffset() )
            {
                at(idx1) = Volume.at(idx2);
            }
        }
    }
}


template <typename T, template <typename> class A>
CVolume<T,A>::CVolume(const tRect& Volume, EMakeRef)
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
CVolume<T,A>::CVolume(const CVolume<T,A>& Volume)
    : mds::base::CObject()
    , tBase()
    , m_Size(Volume.m_Size)
    , m_Margin(Volume.m_Margin)
    , m_DataStorage(EMPTY_CONST)
{
    // Helper value
    tSize Margins = 2 * Volume.m_Margin;

    // Data allocation
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.create(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    // Size of the volume data to copy
    tSize XCount = m_Size.x() + m_Margin;
    tSize YCount = m_Size.y() + m_Margin;
    tSize ZCount = m_Size.z() + m_Margin;

    // Copy the data
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = -m_Margin; k < ZCount; ++k )
    {
        for( tSize j = -m_Margin; j < YCount; ++j )
        {
            tSize idx1 = getIdx(-m_Margin, j, k);
            tSize idx2 = Volume.getIdx(-m_Margin, j, k);
            for( tSize i = -m_Margin; i < XCount; ++i, idx1 += getXOffset(), idx2 += Volume.getXOffset() )
            {
                at(idx1) = Volume.at(idx2);
            }
        }
    }
}


template <typename T, template <typename> class A>
CVolume<T,A>::CVolume(const CVolume<T,A>& Volume, EMakeRef)
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
inline CVolume<T,A>& CVolume<T,A>::create(tSize XSize,
                                          tSize YSize,
                                          tSize ZSize,
                                          tSize Margin
                                          )
{
    // Helper value
    tSize Margins = 2 * Margin;

    // Reallocate the data
    m_Size.x() = XSize;
    m_Size.y() = YSize;
    m_Size.z() = ZSize;
    m_Margin = Margin;
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.create(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::create(const CSize3i& Size, tSize Margin)
{
    // Helper value
    tSize Margins = 2 * Margin;

    // Reallocate the data
    m_Size = Size;
    m_Margin = Margin;
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.create(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    return *this;
}


template <typename T, template <typename> class A>
CVolume<T,A>& CVolume<T,A>::create(const CVolume<T,A>& Volume,
                                   tSize x,
                                   tSize y,
                                   tSize z,
                                   tSize XSize,
                                   tSize YSize,
                                   tSize ZSize
                                   )
{
    // Check the position
    MDS_CHECK(x >= 0 && XSize >= 0 && x < Volume.m_Size.x()
              && y >= 0 && YSize >= 0 && y < Volume.m_Size.y()
              && z >= 0 && ZSize >= 0 && z < Volume.m_Size.z(), return *this);

    // Helper value
    tSize Margins = 2 * Volume.m_Margin;

    // Size of the image
    m_Size.x() = mds::math::getMin(x + XSize, Volume.m_Size.x()) - x;
    m_Size.y() = mds::math::getMin(y + YSize, Volume.m_Size.y()) - y;
    m_Size.z() = mds::math::getMin(z + ZSize, Volume.m_Size.z()) - z;

    // Reallocate the data
    m_Margin = Volume.m_Margin;
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.create(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    // Image size
    tSize XCount = m_Size.x() + m_Margin;
    tSize YCount = m_Size.y() + m_Margin;
    tSize ZCount = m_Size.z() + m_Margin;

    // Copy the data
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = -m_Margin; k < ZCount; ++k )
    {
        for( tSize j = -m_Margin; j < YCount; ++j )
        {
            tSize idx1 = getIdx(-m_Margin, j, k);
            tSize idx2 = Volume.getIdx(-m_Margin + x, j + y, k + z);
            for( tSize i = -m_Margin; i < XCount; ++i, idx1 += getXOffset(), idx2 += Volume.getXOffset() )
            {
                at(idx1) = Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
CVolume<T,A>& CVolume<T,A>::create(const CVolume<T,A>& Volume,
                                   tSize x,
                                   tSize y,
                                   tSize z,
                                   tSize XSize,
                                   tSize YSize,
                                   tSize ZSize,
                                   EMakeRef
                                   )
{
    // Check the position
    MDS_CHECK(x >= 0 && XSize >= 0 && x < Volume.m_Size.x()
              && y >= 0 && YSize >= 0 && y < Volume.m_Size.y()
              && z >= 0 && ZSize >= 0 && z < Volume.m_Size.z(), return *this);

    // Image size
    m_Size.x() = mds::math::getMin(x + XSize, Volume.m_Size.x()) - x;
    m_Size.y() = mds::math::getMin(y + YSize, Volume.m_Size.y()) - y;
    m_Size.z() = mds::math::getMin(z + ZSize, Volume.m_Size.z()) - z;

    // Create a reference to the image data
    m_Margin = Volume.m_Margin;
    m_YOffset = Volume.m_YOffset;
    m_ZOffset = Volume.m_ZOffset;
    m_DataStorage.create(Volume.m_DataStorage, REFERENCE);
    m_ZeroOffset = Volume.m_ZeroOffset + z * m_ZOffset + y * m_YOffset + x;

    return *this;
}


template <typename T, template <typename> class A>
CVolume<T,A>& CVolume<T,A>::create(const tRect& Volume)
{
    // Helper value
    tSize Margins = 2 * Volume.getVolumeRef().m_Margin;

    // Reallocate the data
    m_Size = Volume.getSize();
    m_Margin = Volume.getVolumeRef().m_Margin;
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.create(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    // Image size
    tSize XCount = m_Size.x() + m_Margin;
    tSize YCount = m_Size.y() + m_Margin;
    tSize ZCount = m_Size.z() + m_Margin;

    // Copy the data
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = -m_Margin; k < ZCount; ++k )
    {
        for( tSize j = -m_Margin; j < YCount; ++j )
        {
            tSize idx1 = getIdx(-m_Margin, j, k);
            tSize idx2 = Volume.getIdx(-m_Margin, j, k);
            for( tSize i = -m_Margin; i < XCount; ++i, idx1 += getXOffset(), idx2 += Volume.getXOffset() )
            {
                at(idx1) = Volume.at(idx2);
            }
        }
    }

    return *this;
}


template <typename T, template <typename> class A>
CVolume<T,A>& CVolume<T,A>::create(const tRect& Volume, EMakeRef)
{
    // Create a reference to the image data
    m_Size = Volume.getSize();
    m_Margin = Volume.getVolumeRef().m_Margin;
    m_YOffset = Volume.getVolumeRef().m_YOffset;
    m_ZOffset = Volume.getVolumeRef().m_ZOffset;
    m_DataStorage.create(Volume.getVolumeRef().m_DataStorage, REFERENCE);
    m_ZeroOffset = Volume.getVolumeRef().m_ZeroOffset + Volume.getPos().z() * m_ZOffset + Volume.getPos().y() * m_YOffset + Volume.getPos().x();

    return *this;
}


template <typename T, template <typename> class A>
CVolume<T,A>& CVolume<T,A>::create(const CVolume<T,A>& Volume)
{
    // Helper value
    tSize Margins = 2 * Volume.m_Margin;

    // Reallocate the data
    m_Size = Volume.m_Size;
    m_Margin = Volume.m_Margin;
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.create(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    // Image size
    tSize XCount = Volume.m_Size.x() + m_Margin;
    tSize YCount = Volume.m_Size.y() + m_Margin;
    tSize ZCount = Volume.m_Size.z() + m_Margin;

    // Copy the data
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = -m_Margin; k < ZCount; ++k )
    {
        for( tSize j = -m_Margin; j < YCount; ++j )
        {
            tSize idx1 = getIdx(-m_Margin, j, k);
            tSize idx2 = Volume.getIdx(-m_Margin, j, k);
            for( tSize i = -m_Margin; i < XCount; ++i, idx1 += getXOffset(), idx2 += Volume.getXOffset() )
            {
                at(idx1) = Volume.at(idx2);
            }
        }
    }

    return *this;
}


// Creates a new volume
template <typename T, template <typename> class A>
CVolume<T,A>& CVolume<T,A>::create(const CVolume<T,A>& Volume, EMakeRef)
{
    // Make a reference to the data
    m_Size = Volume.m_Size;
    m_Margin = Volume.m_Margin;
    m_YOffset = Volume.m_YOffset;
    m_ZOffset = Volume.m_ZOffset;
    m_DataStorage.create(Volume.m_DataStorage, REFERENCE);
    m_ZeroOffset = Volume.m_ZeroOffset;

    return *this;
}


// Image conversion
template <typename T, template <typename> class A>
template <typename Derived>
CVolume<T,A>& CVolume<T,A>::convert(const CVolumeBase<Derived>& Volume)
{
    const Derived& SrcVolume = Volume.getImpl();
    typedef typename Derived::tVoxel tSrcVoxel;

    // Helper value
    tSize Margins = SrcVolume.getMargin() * 2;

    // Reallocate the data
    m_Size = SrcVolume.getSize();
    m_Margin = SrcVolume.getMargin();
    m_YOffset = m_Size.x() + Margins;
    m_ZOffset = m_YOffset * (m_Size.y() + Margins);
    m_DataStorage.create(m_ZOffset * (m_Size.z() + Margins));
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin;

    // Image size
    tSize XCount = m_Size.x() + m_Margin;
    tSize YCount = m_Size.y() + m_Margin;
    tSize ZCount = m_Size.z() + m_Margin;

    // Convert voxels
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = -m_Margin; k < ZCount; ++k )
    {
        for( tSize j = -m_Margin; j < YCount; ++j )
        {
            tSize idx1 = getIdx(-m_Margin, j, k);
            tSize idx2 = SrcVolume.getIdx(-m_Margin, j, k);
            for( tSize i = -m_Margin; i < XCount; ++i, idx1 += getXOffset(), idx2 += SrcVolume.getXOffset() )
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

    CSize3i Count = m_Size & Volume.getSize();

#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < Count.z(); ++k )
    {
        for( tSize j = 0; j < Count.y(); ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Count.x(); ++i, idx1 += getXOffset(), idx2 += Volume.getXOffset() )
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
    CSize3i Count = m_Size & Volume.getSize();

#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < Count.z(); ++k )
    {
        for( tSize j = 0; j < Count.y(); ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Count.x(); ++i, idx1 += getXOffset(), idx2 += Volume.getXOffset() )
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
    CSize3i Count = m_Size & Volume.getSize();

#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < Count.z(); ++k )
    {
        for( tSize j = 0; j < Count.y(); ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Count.x(); ++i, idx1 += getXOffset(), idx2 += Volume.getXOffset() )
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
    CSize3i Count = m_Size & Volume.getSize();

#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < Count.z(); ++k )
    {
        for( tSize j = 0; j < Count.y(); ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Count.x(); ++i, idx1 += getXOffset(), idx2 += Volume.getXOffset() )
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
    CSize3i Count = m_Size & Volume.getSize();

#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < Count.z(); ++k )
    {
        for( tSize j = 0; j < Count.y(); ++j )
        {
            tSize idx1 = getIdx(0, j, k);
            tSize idx2 = Volume.getIdx(0, j, k);
            for( tSize i = 0; i < Count.x(); ++i, idx1 += getXOffset(), idx2 += Volume.getXOffset() )
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
    pforEach(mds::base::CAdd<tVoxel>(tVoxel(c.value())));

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CVolume<T,A>& CVolume<T,A>::operator -=(const CScalar<U>& c)
{
    pforEach(mds::base::CSub<tVoxel>(tVoxel(c.value())));

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CVolume<T,A>& CVolume<T,A>::operator *=(const CScalar<U>& c)
{
    pforEach(mds::base::CMult<tVoxel,U>(c.value()));

    return *this;
}


template <typename T, template <typename> class A>
template <typename U>
inline CVolume<T,A>& CVolume<T,A>::operator /=(const CScalar<U>& c)
{
    pforEach(mds::base::CDiv<tVoxel,U>(c.value()));

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
inline Function CVolume<T,A>::pforEach(Function Func)
{
#pragma omp parallel for schedule(static) default(shared)
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
inline Function CVolume<T,A>::pforEach(Function Func) const
{
#pragma omp parallel for schedule(static) default(shared)
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
inline typename CVolume<T,A>::tRect CVolume<T,A>::rect(const CPoint3i& Position, const CSize3i& Size)
{
    return tRect(*this, Position, Size);
}


template <typename T, template <typename> class A>
inline const typename CVolume<T,A>::tRect CVolume<T,A>::rect(const CPoint3i& Position, const CSize3i& Size) const
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
inline CVolume<T,A>& CVolume<T,A>::fill(const T& c)
{
    pforEach(mds::base::CFill<tVoxel>(c));
    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::fillEntire(const T& c)
{
    m_DataStorage.forEach(mds::base::CFill<tVoxel>(c));
    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::fillMargin(const T& c)
{
    // Fill front and back margin
    tSize Count = m_Margin * m_ZOffset;
    tSize Offset = m_ZeroOffset - m_Margin * m_YOffset - m_Margin;
    m_DataStorage.forRange(Offset - m_Margin * m_ZOffset,
                           Offset - m_Margin * m_ZOffset + Count - 1,
                           mds::base::CFill<tVoxel>(c)
                           );
    m_DataStorage.forRange(Offset + m_Size.z() * m_ZOffset,
                           Offset + m_Size.z() * m_ZOffset + Count - 1,
                           mds::base::CFill<tVoxel>(c)
                           );

    // Fill top and bottom margin
    Count = m_Margin * m_YOffset;
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < m_Size.z(); ++k )
    {
        Offset = m_ZeroOffset + k * m_ZOffset - m_Margin;
        m_DataStorage.forRange(Offset - m_Margin * m_YOffset,
                               Offset - m_Margin * m_YOffset + Count - 1,
                               mds::base::CFill<tVoxel>(c)
                               );
        m_DataStorage.forRange(Offset + m_Size.y() * m_YOffset,
                               Offset + m_Size.y() * m_YOffset + Count - 1,
                               mds::base::CFill<tVoxel>(c)
                               );
    }

    // Fill left and right margin
    Count = m_Margin;
#pragma omp parallel for schedule(static) default(shared)
    for( tSize k = 0; k < m_Size.z(); ++k )
    {
        for( tSize j = 0; j < m_Size.y(); ++j )
        {
            Offset = m_ZeroOffset + k * m_ZOffset + j * m_YOffset;
            m_DataStorage.forRange(Offset - m_Margin,
                                   Offset - m_Margin + Count - 1,
                                   mds::base::CFill<tVoxel>(c)
                                   );
            m_DataStorage.forRange(Offset + m_Size.x(),
                                   Offset + m_Size.x() + Count - 1,
                                   mds::base::CFill<tVoxel>(c)
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
    pforEach(mds::base::CReplace<tVoxel>(Value, NewValue));
    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::abs()
{
    pforEach(mds::base::CAbs<tVoxel>());
    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::limit(const T& Lower, const T& Upper)
{
    pforEach(mds::base::CLimit<tVoxel>(Lower, Upper));
    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::cut(const T& Lower, const T& Upper)
{
    static const T NewValue = CPixelTraits<T>::getPixelMin();

    pforEach(mds::base::CCut<tVoxel>(Lower, Upper, NewValue));
    return *this;
}


template <typename T, template <typename> class A>
inline CVolume<T,A>& CVolume<T,A>::subSample(const CVolume<T,A>& Volume,
                                             tSize l,
                                             tSize m,
                                             tSize n
                                             )
{
    MDS_CHECK(l > 0 && m > 0 && n > 0, return *this);

    tSize XCount = mds::math::getMin(Volume.m_Size.x() / l, m_Size.x());
    tSize YCount = mds::math::getMin(Volume.m_Size.y() / m, m_Size.y());
    tSize ZCount = mds::math::getMin(Volume.m_Size.z() / n, m_Size.z());

#pragma omp parallel for schedule(static) default(shared)
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
    MDS_CHECK(z >= 0 && z < m_Size.z(), return false);
    
    tSize XCount = mds::math::getMin(m_Size.x(), Plane.getXSize());
    tSize YCount = mds::math::getMin(m_Size.y(), Plane.getYSize());
    
#pragma omp parallel for schedule(static) default(shared)
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
    MDS_CHECK(y >= 0 && y < m_Size.y(), return false);

    tSize XCount = mds::math::getMin(m_Size.x(), Plane.getXSize());
    tSize ZCount = mds::math::getMin(m_Size.z(), Plane.getYSize());

#pragma omp parallel for schedule(static) default(shared)
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
    MDS_CHECK(x >= 0 && x < m_Size.x(), return false);

    tSize YCount = mds::math::getMin(m_Size.y(), Plane.getXSize());
    tSize ZCount = mds::math::getMin(m_Size.z(), Plane.getYSize());

#pragma omp parallel for schedule(static) default(shared)
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
    MDS_CHECK(z >= 0 && z < m_Size.z(), return false);

    tSize XCount = mds::math::getMin(m_Size.x(), Plane.getXSize());
    tSize YCount = mds::math::getMin(m_Size.y(), Plane.getYSize());

#pragma omp parallel for schedule(static) default(shared)
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
    MDS_CHECK(y >= 0 && y < m_Size.y(), return false);

    tSize XCount = mds::math::getMin(m_Size.x(), Plane.getXSize());
    tSize ZCount = mds::math::getMin(m_Size.z(), Plane.getYSize());

#pragma omp parallel for schedule(static) default(shared)
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
    MDS_CHECK(x >= 0 && x < m_Size.x(), return false);

    tSize YCount = mds::math::getMin(m_Size.y(), Plane.getXSize());
    tSize ZCount = mds::math::getMin(m_Size.z(), Plane.getYSize());

#pragma omp parallel for schedule(static) default(shared)
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
void CVolume<T,A>::serialize(mds::mod::CChannelSerializer<S>& Writer)
{
    // Begin of data serialization block
    Writer.beginWrite(*this);

    // Volume info
    Writer.write(m_Size.x());
    Writer.write(m_Size.y());
    Writer.write(m_Size.z());

    Writer.setProgressMax(m_Size.z());

    // Volume data
    mds::base::CData<tVoxel> Buffer(m_Size.x());
    for( tSize k = 0; k < m_Size.z(); ++k )
    {
        for( tSize j = 0; j < m_Size.y(); ++j )
        {
            row(j, k).copyTo(Buffer.getPtr());

            Writer.write(Buffer.getPtr(), m_Size.x());
        }
        if( !Writer.progress() )
        {
            throw mds::mod::Serializer::CWriteFailed();
        }
    }

    // End of the block
    Writer.endWrite(*this);
}


/*template <typename T, template <typename> class A>
void CVolume<T,A>::serialize(mds::mod::CSHMSerializer& Writer)
{
    // Begin of data serialization block
    Writer.beginWrite(*this);

    // Complete volume info
    Writer.write(m_Size.x());
    Writer.write(m_Size.y());
    Writer.write(m_Size.z());
    Writer.write(m_Margin);
    Writer.write(m_YOffset);
    Writer.write(m_ZOffset);
    Writer.write(m_DataStorage);

    // End of the block
    Writer.endWrite(*this);
}*/


template <typename T, template <typename> class A>
template <class S>
void CVolume<T,A>::deserialize(mds::mod::CChannelSerializer<S>& Reader)
{
    // Begin of data deserialization block
    Reader.beginRead(*this);

    // Read the volume info struct
    Reader.read(m_Size.x());
    Reader.read(m_Size.y());
    Reader.read(m_Size.z());

    Reader.setProgressMax(m_Size.z());

    // Create a new volume
    create(m_Size.x(), m_Size.y(), m_Size.z(), m_Margin);

    // Volume data
    mds::base::CData<tVoxel> Buffer(m_Size.x());
    for( tSize k = 0; k < m_Size.z(); ++k )
    {
        for( tSize j = 0; j < m_Size.y(); ++j )
        {
            Reader.read(Buffer.getPtr(), m_Size.x());

            row(j, k).copyFrom(Buffer.getPtr());
        }
        if( !Reader.progress() )
        {
            throw mds::mod::Serializer::CReadFailed();
        }
    }

    // End of the block
    Reader.endRead(*this);
}


/*template <typename T, template <typename> class A>
void CVolume<T,A>::deserialize(mds::mod::CSHMSerializer& Reader)
{
    // Begin of data deserialization block
    Reader.beginRead(*this);

    // Volume info
    Reader.read(m_Size.x());
    Reader.read(m_Size.y());
    Reader.read(m_Size.z());
    Reader.read(m_Margin);
    Reader.read(m_YOffset);
    Reader.read(m_ZOffset);
    Reader.read(m_DataStorage);

    // Check volume size
    tSize Size = m_ZOffset * (m_Size.z() + 2 * m_Margin);
    if( Size < 0 || Size > m_DataStorage.getSize() )
    {
        throw mds::mod::Serializer::CReadFailed();
    }

    // Initialize the internal pointer
    m_ZeroOffset = (m_ZOffset + m_YOffset + 1) * m_Margin);

    // End of the block
    Reader.endRead(*this);
}*/

