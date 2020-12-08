//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/07/11                          \n
 *
 * $Id: mdsDensityVolume.cpp 2110 2012-02-19 15:39:45Z spanel $
 *
 * Description:
 * - Manipulation with the real volume data.
 */

#include <MDSTk/Image/mdsDensityVolume.h>


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Implementation of the class mds::img::CDensityVolume.
 */
CDensityVolume::CDensityVolume()
    : tBase(0, 0, 0, DEFAULT_MARGIN)
    , m_dDX(1.0)
    , m_dDY(1.0)
    , m_dDZ(1.0)
{
}


CDensityVolume::CDensityVolume(tSize XSize,
                               tSize YSize,
                               tSize ZSize,
                               tSize Margin
                               )
    : tBase(XSize, YSize, ZSize, Margin)
    , m_dDX(1.0)
    , m_dDY(1.0)
    , m_dDZ(1.0)
{
}


CDensityVolume::CDensityVolume(const CDensityVolume& Volume)
    : tBase(Volume)
    , m_dDX(Volume.m_dDX)
    , m_dDY(Volume.m_dDY)
    , m_dDZ(Volume.m_dDZ)
{
}


CDensityVolume::CDensityVolume(const CDensityVolume& Volume, EMakeRef)
    : tBase(Volume, REFERENCE)
    , m_dDX(Volume.m_dDX)
    , m_dDY(Volume.m_dDY)
    , m_dDZ(Volume.m_dDZ)
{
}


CDensityVolume::CDensityVolume(const tBase& Volume)
    : tBase(Volume)
    , m_dDX(1.0)
    , m_dDY(1.0)
    , m_dDZ(1.0)
{
}


CDensityVolume::CDensityVolume(const tBase& Volume, EMakeRef)
    : tBase(Volume, REFERENCE)
    , m_dDX(1.0)
    , m_dDY(1.0)
    , m_dDZ(1.0)
{
}


CDensityVolume::~CDensityVolume()
{
}


CDensityVolume& CDensityVolume::create(tSize XSize,
                                       tSize YSize,
                                       tSize ZSize,
                                       tSize Margin
                                       )
{
    tBase::create(XSize, YSize, ZSize, Margin);
    return *this;
}


CDensityVolume& CDensityVolume::create(const CDensityVolume& Volume)
{
    // Copy the volume data
    tBase::create(Volume);

    // Volume properties
    m_dDX = Volume.m_dDX;
    m_dDY = Volume.m_dDY;
    m_dDZ = Volume.m_dDZ;

    return *this;
}


CDensityVolume& CDensityVolume::create(const CDensityVolume& Volume, EMakeRef)
{
    // Make reference to the volume data
    tBase::create(Volume, REFERENCE);

    // Volume properties
    m_dDX = Volume.m_dDX;
    m_dDY = Volume.m_dDY;
    m_dDZ = Volume.m_dDZ;

    return *this;
}


CDensityVolume& CDensityVolume::create(const tBase& Volume)
{
    // Copy the volume data
    tBase::create(Volume);

    return *this;
}


CDensityVolume& CDensityVolume::create(const tBase& Volume, EMakeRef)
{
    // Make reference to the volume data
    tBase::create(Volume, REFERENCE);

    return *this;
}


CDensityVolume& CDensityVolume::operator =(const CDensityVolume& Volume)
{
    *((tBase *)this) = (const tBase&)Volume;

    m_dDX = Volume.m_dDX;
    m_dDY = Volume.m_dDY;
    m_dDZ = Volume.m_dDZ;

    return *this;
}


bool CDensityVolume::getSliceXY(tSize z, CSlice& Plane)
{
    // Cut data from CVolume
    if (tBase::getPlaneXY(z, Plane))
    {
        Plane.setIndex(z);
        Plane.setPosition(z * m_dDZ);
        return true;
    }

    return false;
}


bool CDensityVolume::getSliceXZ(tSize y, CSlice& Plane)
{
    // Cut data from CVolume
    if( tBase::getPlaneXZ(y, Plane) )
    {
        Plane.setIndex(y);
        Plane.setPosition(y * m_dDY);
        return true;
    }

    return false;
}


bool CDensityVolume::getSliceYZ(tSize x, CSlice& Plane)
{
    // Cut data from CVolume
    if( tBase::getPlaneYZ(x, Plane) )
    {
        Plane.setIndex(x);
        Plane.setPosition(x * m_dDX);
        return true;
    }

    return false;
}


bool CDensityVolume::getSliceXY(double dZ, CSlice& Plane)
{
    // Index calculating from given real position
    // tSize Index = tSize(dZ / m_dDZ + 0.5);
    tSize Index = tSize(dZ / m_dDZ);

    // Cut data from CVolume
    if( tBase::getPlaneXY(Index, Plane) )
    {
        Plane.setIndex(Index);
        Plane.setPosition(dZ);
        return true;
    }

    return false;
}


bool CDensityVolume::getSliceXZ(double dY, CSlice& Plane)
{
    // index calculating from given real position
    // tSize Index = tSize(dY / m_dDY + 0.5);
    tSize Index = tSize(dY / m_dDY);

    // Cut data from CVolume
    if( tBase::getPlaneXZ(Index, Plane) )
    {
        Plane.setIndex(Index);
        Plane.setPosition(dY);
        return true;
    }

    return false;
}


bool CDensityVolume::getSliceYZ(double dX, CSlice& Plane)
{
    // Index calculating from given real position
    // tSize Index = tSize(dX / m_dDX + 0.5);
    tSize Index = tSize(dX / m_dDX);

    // Cut data from CVolume
    if( tBase::getPlaneYZ(Index, Plane) )
    {
        Plane.setIndex(Index);
        Plane.setPosition(dX);
        return true;
    }

    return false;
}


bool CDensityVolume::getSlice(double dPosition, CSlice& Plane)
{
    tSize Index;        // Calculated index

    switch (Plane.getOrientation())
    {
        case PLANE_XY:
            // Index calculating from given real position
            Index = tSize(dPosition / m_dDZ);

            // Cut data from CVolume
            if( tBase::getPlaneXY(Index, Plane) )
            {
                Plane.setIndex(Index);
                Plane.setPosition(dPosition);
                return true;
            }
            break;

        case PLANE_XZ:
            // index calculating from given real position
            Index = tSize(dPosition / m_dDY);

            // Cut data from CVolume
            if( tBase::getPlaneXZ(Index, Plane) )
            {
                Plane.setIndex(Index);
                Plane.setPosition(dPosition);
                return true;
            }
            break;

        case PLANE_YZ:
            // Index calculating from given real position
            Index = tSize(dPosition / m_dDX);

            // Cut data from CVolume
            if( tBase::getPlaneYZ(Index, Plane) )
            {
                Plane.setIndex(Index);
                Plane.setPosition(dPosition);
                return true;
            }
            break;

        default:
            break;
    }

    return false;
}


void CDensityVolume::initSlice(CSlice &Slice, EPlane eOrientation)
{
    // Oritentation selection
    switch( eOrientation )
    {
        case PLANE_XY:
            // Slice data creation by volume parameters
            Slice.create(m_Size.x(), m_Size.y());
            Slice.setPixel(m_dDX, m_dDY);

            // Set other slice parameters by volume parameters
            Slice.setPosition(0.0);
            Slice.setIndex(0);
            Slice.setThickness(m_dDZ);
            Slice.setOrientation(PLANE_XY);
            break;

        case PLANE_XZ:
            // Slice data creation by volume parameters
            Slice.create(m_Size.x(), m_Size.z());
            Slice.setPixel(m_dDX, m_dDZ);

            // Set other slice parameters by volume parameters
            Slice.setPosition(0.0);
            Slice.setIndex(0);
            Slice.setThickness(m_dDY);
            Slice.setOrientation(PLANE_XZ);
            break;

        case PLANE_YZ:
            // Slice data creation by volume parameters
            Slice.create(m_Size.y(), m_Size.z());
            Slice.setPixel(m_dDY, m_dDZ);

            // Set other slice parameters by volume parameters
            Slice.setPosition(0.0);
            Slice.setIndex(0);
            Slice.setThickness(m_dDX);
            Slice.setOrientation(PLANE_YZ);
            break;

        default:
            break;
    }
}


} // namespace img
} // namespace mds

