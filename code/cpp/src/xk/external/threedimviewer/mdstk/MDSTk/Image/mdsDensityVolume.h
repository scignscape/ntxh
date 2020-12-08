//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/07/11                          \n
 *
 * $Id: mdsDensityVolume.h 2110 2012-02-19 15:39:45Z spanel $
 *
 * Description:
 * - Manipulation with the real volume data.
 */

#ifndef MDS_DENSITYVOLUME_H
#define MDS_DENSITYVOLUME_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Base/mdsSharedPtr.h>
#include <MDSTk/Base/mdsPartedData.h>
#include <MDSTk/Math/mdsBase.h>

#include "mdsImageExport.h"
#include "mdsSlice.h"
#include "mdsVolume.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Class ecapsulating volumetric density data.
 */
class MDS_IMAGE_EXPORT CDensityVolume : public CDVolume
//class MDS_IMAGE_EXPORT CDensityVolume : public CVolume<tDensityPixel, mds::base::CPartedData>
{
public:
    //! Base type.
    typedef CDVolume tBase;
//    typedef CVolume<tDensityPixel, mds::base::CPartedData> tBase;

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CDensityVolume);

    //! Standard method getEntityName().
    MDS_ENTITY_NAME("DensityVolume");

    //! Standard method getEntityCompression().
    MDS_ENTITY_COMPRESSION(mds::mod::CC_RAW);

    //! Default size of the volume margin.
    enum { DEFAULT_MARGIN = 3 };

public:
    //! Default constructor.
    CDensityVolume();

    //! Constructor.
    CDensityVolume(tSize XSize,
                   tSize YSize,
                   tSize ZSize,
                   tSize Margin = DEFAULT_MARGIN
                   );

    //! Copy constructor.
    //! - Makes a new copy of the volume data.
    CDensityVolume(const CDensityVolume& Volume);

    //! Copy constructor.
    //! - Makes only a reference to the exisiting data.
    CDensityVolume(const CDensityVolume& Volume, EMakeRef);

    //! Copy constructor.
    //! - Makes a new copy of the volume data.
    CDensityVolume(const tBase& Volume);

    //! Copy constructor.
    //! - Makes only a reference to the exisiting data.
    CDensityVolume(const tBase& Volume, EMakeRef);

    //! Destructor.
    virtual ~CDensityVolume();

    //! Creates a new volume.
    CDensityVolume& create(tSize XSize,
                           tSize YSize,
                           tSize ZSize,
                           tSize Margin = DEFAULT_MARGIN
                           );

    //! Creates a new volume.
    //! - Makes a new copy of the volume data.
    CDensityVolume& create(const tBase& Volume);

    //! Creates a new volume.
    //! - Makes only a reference to the exisiting data.
    CDensityVolume& create(const tBase& Volume, EMakeRef);

    //! Creates a new volume.
    //! - Makes a new copy of the volume data.
    CDensityVolume& create(const CDensityVolume& Volume);

    //! Creates a new volume.
    //! - Makes only a reference to the exisiting data.
    CDensityVolume& create(const CDensityVolume& Volume, EMakeRef);

    //! Volume assignment operator.
    CDensityVolume& operator =(const CDensityVolume& Volume);


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
    void serialize(mds::mod::CChannelSerializer<S>& Writer);

    //! Deserializes all class members.
    template <class S>
    void deserialize(mds::mod::CChannelSerializer<S>& Reader);

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
#include "mdsDensityVolume.hxx"


} // namespace img
} // namespace mds

#endif // MDS_DENSITYVOLUME_H

