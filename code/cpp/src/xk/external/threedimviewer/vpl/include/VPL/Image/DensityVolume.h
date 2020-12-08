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

#ifndef VPL_DENSITYVOLUME_H
#define VPL_DENSITYVOLUME_H

#include <VPL/Base/Assert.h>
#include <VPL/Base/Types.h>
#include <VPL/Base/SharedPtr.h>
#include <VPL/Base/PartedData.h>

#include "ImageExport.h"
#include "Slice.h"
#include "Volume.h"
#include "VPL/ImageIO/DicomSlice.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Class ecapsulating volumetric density data.
 */
class VPL_IMAGE_EXPORT CDensityVolume : public CDVolume
{
public:
    //! Base class.
    typedef CDVolume tBase;

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CDensityVolume);

    //! Standard method getEntityName().
    VPL_ENTITY_NAME("DensityVolume");

    //! Standard method getEntityCompression().
    VPL_ENTITY_COMPRESSION(vpl::mod::CC_RAW);

    //! Default size of the volume margin.
    enum { DEFAULT_MARGIN = 3 };

public:
    //! Default constructor.
    CDensityVolume();

    //! Constructor allocates underlying volume data.
    CDensityVolume(tSize XSize,
                   tSize YSize,
                   tSize ZSize,
                   tSize Margin = DEFAULT_MARGIN
                   );

    //! Copy constructor.
    //! - Makes a new copy of the volume data.
    CDensityVolume(const CDensityVolume& Volume);

    //! Constructor makes only a reference to given source volume data.
    CDensityVolume(const CDensityVolume& Volume, EMakeRef);

    //! Copy constructor.
    //! - Makes a new copy of the volume data.
    explicit CDensityVolume(const tBase& Volume);

    //! Constructor makes only a reference to given volume data.
    explicit CDensityVolume(const tBase& Volume, EMakeRef);

    //! Destructor.
    virtual ~CDensityVolume();

    //! Resizes the volume data.
    CDensityVolume& resize(tSize XSize,
                           tSize YSize,
                           tSize ZSize,
                           tSize Margin = DEFAULT_MARGIN
                           );

    //! Resizes the volume data.
    CDensityVolume& resize(const CSize3i& Size, tSize Margin = DEFAULT_MARGIN);

    //! Makes a copy of the volume data.
    //! - Uses margin size of the source volume if -1 is given as the parameter.
    //! - No other density volume properties are copied.
    CDensityVolume& copy(const tBase& Volume, tSize Margin = -1);

    //! Makes a copy of the volume data.
    //! - Uses margin size of the source volume if -1 is given as the parameter.
    CDensityVolume& copy(const CDensityVolume& Volume, tSize Margin = -1);

    //! Creates a reference to image data of a given source volume.
    //! - No image data are copied.
    CDensityVolume& makeRef(const tBase& Volume);

    //! Creates a reference to image data of a given source volume.
    //! - No image data are copied.
    //! - No other density volume properties are copied.
    CDensityVolume& makeRef(const CDensityVolume& Volume);

    //! Volume assignment operator.
    //! - Copies voxel values and other preperties from one density volume to another.
    CDensityVolume& operator =(const CDensityVolume& Volume);

    //! Copies density volume properties from one volume to another.
    CDensityVolume& copyProps(const CDensityVolume& Volume);


    //! Returns the real voxel size in x-axis.
    double getDX() const { return m_dDX; }

    //! Returns the real voxel size in y-axis.
    double getDY() const { return m_dDY; }

    //! Returns the real voxel size in z-axis.
    double getDZ() const { return m_dDZ; }

    //! Set the real voxel size in x-axis.
    CDensityVolume& setDX(double dValue)
    {
        m_dDX = dValue;
        return *this;
    }

    //! Set the real voxel size in y-axis.
    CDensityVolume& setDY(double dValue)
    {
        m_dDY = dValue;
        return *this;
    }

    //! Set the real voxel size in z-axis.
    CDensityVolume& setDZ(double dValue)
    {
        m_dDZ = dValue;
        return *this;
    }

    //! Sets voxel dimensions.
    CDensityVolume& setVoxel(double dDX, double dDY, double dDZ)
    {
        m_dDX = dDX; m_dDY = dDY; m_dDZ = dDZ;
        return *this;
    }

    //! Creates a new volume from given slices,
    //! resize current volume and set voxel from input. 
    bool makeVolume(std::vector<vpl::img::CSlicePtr> Slices, vpl::img::CDVolume::tVoxel BorderValue = CPixelTraits<tDensityPixel>::getPixelMin());


    //! Cuts the volume using plane XY and saves obtained data to a given
    //! slice. Position of the plane is specified by the Z index.
    bool getSliceXY(tSize z, CSlice& Plane);

    //! Cuts the volume using plane XZ and saves obtained data to a given
    //! slice. Position of the plane is specified by the Y index.
    bool getSliceXZ(tSize y, CSlice& Plane);

    //! Cuts the volume using plane YZ and saves obtained data to a given
    //! slice. Position of the plane is specified by the X index.
    bool getSliceYZ(tSize x, CSlice& Plane);

    //! Cuts the volume using plane XY and saves obtained data to a given
    //! slice. Position of the plane is specified by the Z real position.
    bool getSliceXY(double dZ, CSlice& Plane);

    //! Cuts the volume using plane XZ and saves obtained data to a given
    //! slice. Position of the plane is specified by the Y real position.
    bool getSliceXZ(double dY, CSlice& Plane);

    //! Cuts the volume using plane YZ and saves obtained data to a given
    //! slice. Position of the plane is specified by the X real position.
    bool getSliceYZ(double dX, CSlice& Plane);

    //! Cuts the volume using plane by given slice and saves obtained data
    //! to the slice. Position of the plane is specified by the real position.
    bool getSlice(double dPosition, CSlice& Plane);



    //! Initializes slice parameters (size and etc.) with respect to the volume
    //! parameters in a given direction.
    void initSlice(CSlice &Slice, EPlane eOrientation);



    //! Serializes all class members.
    template <class S>
    void serialize(vpl::mod::CChannelSerializer<S>& Writer);

    //! Deserializes all class members.
    template <class S>
    void deserialize(vpl::mod::CChannelSerializer<S>& Reader);



protected:
    //! Real voxel size.
    double m_dDX, m_dDY, m_dDZ;
};



//=============================================================================
/*
 * Smart pointer to density volume.
 */
typedef CDensityVolume::tSmartPtr   CDensityVolumePtr;


//=============================================================================
/*
 * Implementation...
 */
#include "DensityVolume.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_DENSITYVOLUME_H

