//==============================================================================
/*! \filter
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/13                          \n
 *
 * $Id: mdsSlice.h 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - Density slice.
 */

#ifndef MDS_SLICE_H
#define MDS_SLICE_H

#include "mdsImageExport.h"
#include "mdsImage.h"


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Global definitions.
 */

//! Slice orientation.
enum EPlane
{
    PLANE_NON   = -1,
    PLANE_XY    = 0,
    PLANE_XZ    = 1,
    PLANE_YZ    = 2
};


//==============================================================================
/*!
 * Class ecapsulating a density slice.
 */
class MDS_IMAGE_EXPORT CSlice : public CDImage
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CSlice);

    //! Standard method getEntityName().
    MDS_ENTITY_NAME("Slice");

    //! Standard method getEntityCompression().
    MDS_ENTITY_COMPRESSION(mds::mod::CC_RAW);

    //! Default size of the slice margin.
    enum { DEFAULT_MARGIN = 16 };

public:
    //! Default constructor.
    CSlice();

    //! Constructor.
    CSlice(tSize XSize, tSize YSize, tSize Margin = DEFAULT_MARGIN);

    //! Copy constructor.
    //! - Makes a new copy of the slice data.
    CSlice(const CSlice& Slice);

    //! Copy constructor.
    //! - Makes only reference to the exisiting data.
    CSlice(const CSlice& Slice, EMakeRef);

    //! Copy constructor.
    //! - Makes a new copy of the slice data.
    CSlice(const CDImage& Image);

    //! Copy constructor.
    //! - Makes only reference to the exisiting data.
    CSlice(const CDImage& Image, EMakeRef);

    //! Destructor.
    ~CSlice();

    //! Creates a new slice.
    CSlice& create(tSize XSize, tSize YSize, tSize Margin = DEFAULT_MARGIN);

    //! Creates a new slice.
    //! - Makes a new copy of the slice data.
    CSlice& create(const CSlice& Slice);

    //! Creates a new slice.
    //! - Makes only reference to the exisiting data.
    CSlice& create(const CSlice& Slice, EMakeRef);

    //! Image assignment operator.
    CSlice& operator =(const CSlice& Slice);


    //! Returns the real pixel size in x-axis.
    double getDX() const { return m_dDX; }

    //! Returns the real pixel size in y-axis.
    double getDY() const { return m_dDY; }

    //! Sets the pixel size.
    CSlice& setPixel(double dDX, double dDY)
    {
        m_dDX = dDX;
        m_dDY = dDY;
        return *this;
    }

    //! Returns the slice thickness.
    double getThickness() const { return m_dThickness; }

    //! Sets the slice thickness.
    CSlice& setThickness(double dThickness)
    {
        m_dThickness = dThickness;
        return *this;
    }

    //! Gets the slice position index.
    int getIndex() const { return m_iIndex; }

    //! Sets the position index.
    CSlice& setIndex(int iIndex)
    {
        m_iIndex = iIndex;
        return *this;
    }

    //! Returns the slice position.
    double getPosition() const { return m_dPosition; }

    //! Sets the slice position.
    CSlice& setPosition(double dPosition)
    {
        m_dPosition = dPosition;
        return *this;
    }

    //! Returns orientation of the slice plane.
    EPlane getOrientation() const { return m_eOrientation; }

    //! Sets the slice plane orientation.
    CSlice& setOrientation(EPlane ePlane)
    {
        m_eOrientation = ePlane;
        return *this;
    }

    //! Operator smaller for comparision of positions of two slices.
    bool operator <(const CSlice& Slice) { return (m_dPosition < Slice.m_dPosition); }


    //! Serializes all class members.
    template <class S>
    void serialize(mds::mod::CChannelSerializer<S>& Writer);

    //! Deserializes all class members.
    template <class S>
    void deserialize(mds::mod::CChannelSerializer<S>& Reader);

protected:
    //! Real pixel size
    double m_dDX, m_dDY;

    //! Slice thickness
    double m_dThickness;

    //! Slice position
    double m_dPosition;

    //! Position index
    int m_iIndex;

    //! Slice plane orientation
    EPlane m_eOrientation;
};


//=============================================================================
/*
 * Smart pointer to slice.
 */
typedef CSlice::tSmartPtr   CSlicePtr;


//=============================================================================
/*
 * Implementation...
 */
#include "mdsSlice.hxx"


} // namespace img
} // namespace mds

#endif // MDS_SLICE_H

