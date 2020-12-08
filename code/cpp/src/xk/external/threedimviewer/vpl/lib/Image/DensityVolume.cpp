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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/07/11                       
 *
 * Description:
 * - Manipulation with the real volume data.
 */

#include <VPL/Image/DensityVolume.h>
#include "VPL/ImageIO/DicomSlice.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Implementation of the class vpl::img::CDensityVolume.
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
{
    copyProps(Volume);
}


CDensityVolume::CDensityVolume(const CDensityVolume& Volume, EMakeRef)
    : tBase(Volume, REFERENCE)
{
    copyProps(Volume);
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


CDensityVolume& CDensityVolume::resize(tSize XSize,
                                       tSize YSize,
                                       tSize ZSize,
                                       tSize Margin
                                       )
{
    tBase::resize(XSize, YSize, ZSize, Margin);
    return *this;
}


CDensityVolume& CDensityVolume::resize(const CSize3i& Size, tSize Margin)
{
    tBase::resize(Size, Margin);
    return *this;
}


CDensityVolume& CDensityVolume::copy(const CDensityVolume& Volume, tSize Margin)
{
    // Copy the volume data
    tBase::copy(Volume, Margin);

    // Volume properties
    copyProps(Volume);

    return *this;
}


CDensityVolume& CDensityVolume::copy(const tBase& Volume, tSize Margin)
{
    // Copy the volume data
    tBase::copy(Volume, Margin);

    return *this;
}


CDensityVolume& CDensityVolume::makeRef(const CDensityVolume& Volume)
{
    // Make reference to the volume data
    tBase::makeRef(Volume);

    // Volume properties
    copyProps(Volume);

    return *this;
}


CDensityVolume& CDensityVolume::makeRef(const tBase& Volume)
{
    // Make reference to the volume data
    tBase::makeRef(Volume);

    return *this;
}


CDensityVolume& CDensityVolume::operator =(const CDensityVolume& Volume)
{
    *(dynamic_cast<tBase *>(this)) = dynamic_cast<const tBase&>(Volume);

    copyProps(Volume);

    return *this;
}


CDensityVolume& CDensityVolume::copyProps(const CDensityVolume& Volume)
{
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

bool CDensityVolume::makeVolume(std::vector<vpl::img::CSlicePtr> slices, const vpl::img::CDVolume::tVoxel borderValue)
{
    VPL_CHECK(!slices.empty(), return false);

    // Collect information on volume from input Slices
    std::vector<vpl::img::CSlicePtr>::iterator it = slices.begin();
    const std::vector<vpl::img::CSlicePtr>::const_iterator itEnd = slices.end();

    vpl::tSize xSize = (*it)->getXSize();
    vpl::tSize ySize = (*it)->getYSize();
    double dMinPos = (*it)->getPosition();
    double dMaxPos = (*it)->getPosition();

    for (++it; it != itEnd; ++it)
    {
        xSize = vpl::math::getMax(xSize, (*it)->getXSize());
        ySize = vpl::math::getMax(ySize, (*it)->getYSize());
        dMinPos = vpl::math::getMin(dMinPos, (*it)->getPosition());
        dMaxPos = vpl::math::getMax(dMaxPos, (*it)->getPosition());
    }

	const vpl::tSize zSize = vpl::tSize(slices.size());

    // Create the volume
    resize(xSize, ySize, zSize);
    fillEntire(borderValue);


    // Krok pro vkladani rezu
    const double dStep = (dMaxPos - dMinPos) / double(slices.size() - 1);
    double dInvStep = 1.0;
    if (dStep > 0.0)
    {
        dInvStep = 1.0 / dStep;
    }

    // Put Slices in the pVolume
    it = slices.begin();
    while (it != itEnd)
    {
        double dTemp = ((*it)->getPosition() - dMinPos) * dInvStep;
        setPlaneXY(vpl::tSize(vpl::math::round2Int(dTemp)), *(*it));
        ++it;
    }

    // Set the voxel size
    setVoxel(slices[0]->getDX(),
        slices[0]->getDY(),
        //                      Slices[0]->getThickness()
        dStep
    );

    // O.K.
    return true;
}


void CDensityVolume::initSlice(CSlice &Slice, const EPlane eOrientation)
{
    // Oritentation selection
    switch( eOrientation )
    {
        case PLANE_XY:
            // Slice data creation by volume parameters
            Slice.resize(m_Size.x(), m_Size.y());
            Slice.setPixel(m_dDX, m_dDY);

            // Set other slice parameters by volume parameters
            Slice.setPosition(0.0);
            Slice.setIndex(0);
            Slice.setThickness(m_dDZ);
            Slice.setOrientation(PLANE_XY);
            break;

        case PLANE_XZ:
            // Slice data creation by volume parameters
            Slice.resize(m_Size.x(), m_Size.z());
            Slice.setPixel(m_dDX, m_dDZ);

            // Set other slice parameters by volume parameters
            Slice.setPosition(0.0);
            Slice.setIndex(0);
            Slice.setThickness(m_dDY);
            Slice.setOrientation(PLANE_XZ);
            break;

        case PLANE_YZ:
            // Slice data creation by volume parameters
            Slice.resize(m_Size.y(), m_Size.z());
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
} // namespace vpl

