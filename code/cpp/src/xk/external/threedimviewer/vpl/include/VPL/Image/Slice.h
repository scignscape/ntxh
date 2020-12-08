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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/13                          \n
 *
 * Description:
 * - Density slice.
 */

#ifndef VPL_SLICE_H
#define VPL_SLICE_H

#include "ImageExport.h"
#include "Image.h"


namespace vpl
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
 * Class that further extends a basic image by thinking of the image
 * as a slice throught density volume.
 */
class VPL_IMAGE_EXPORT CSlice : public CDImage
{
public:
    //! Base class.
    typedef CDImage tBase;

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CSlice);

    //! Standard method getEntityName().
    VPL_ENTITY_NAME("Slice");

    //! Standard method getEntityCompression().
    VPL_ENTITY_COMPRESSION(vpl::mod::CC_RAW);

    //! Default size of the slice margin.
    enum { DEFAULT_MARGIN = 16 };

public:
    //! Default constructor.
    CSlice();

    //! Constructor allocates underlying image data.
    CSlice(tSize XSize, tSize YSize, tSize Margin = DEFAULT_MARGIN);

    //! Copy constructor.
    //! - Makes a new copy of the slice data.
    CSlice(const CSlice& Slice);

    //! Constructor makes only a reference to given source slice image data.
    CSlice(const CSlice& Slice, EMakeRef);

    //! Copy constructor.
    //! - Makes a new copy of the image data.
    explicit CSlice(const tBase& Image);

    //! Constructor makes only a reference to a given source image.
    explicit CSlice(const tBase& Image, EMakeRef);

    //! Destructor.
    ~CSlice();

    //! Resizes the slice.
    CSlice& resize(tSize XSize, tSize YSize, tSize Margin = DEFAULT_MARGIN);

    //! Resizes the underlying image data.
    CSlice& resize(const CSize2i& Size, tSize Margin = DEFAULT_MARGIN);

    //! Makes a copy of a given source image.
    //! - Uses margin size of the source slice if -1 is given as the parameter.
    //! - No other slice properties are copied.
    CSlice& copy(const tBase& Image, tSize Margin = -1);

    //! Makes a copy of a given source slice.
    //! - Uses margin size of the source slice if -1 is given as the parameter.
    CSlice& copy(const CSlice& Slice, tSize Margin = -1);

    //! Creates a reference to a given image.
    //! - No image data are copied.
    //! - No other slice properties are copied.
    CSlice& makeRef(const tBase& Image);

    //! Creates a reference to image data of a given source slice.
    //! - No image data are copied.
    CSlice& makeRef(const CSlice& Slice);

    //! Assignment operator.
    //! - Copies pixel values and other member values from one slice to another.
    CSlice& operator =(const CSlice& Slice);

    //! Copies slice properties from one slice to another.
    CSlice& copyProps(const CSlice& Slice);


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
    tSize getIndex() const { return m_Index; }

    //! Sets the position index.
    CSlice& setIndex(tSize Index)
    {
        m_Index = Index;
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
    void serialize(vpl::mod::CChannelSerializer<S>& Writer);

    //! Deserializes all class members.
    template <class S>
    void deserialize(vpl::mod::CChannelSerializer<S>& Reader);

protected:
    //! Real pixel size
    double m_dDX, m_dDY;

    //! Slice thickness
    double m_dThickness;

    //! Slice position
    double m_dPosition;

    //! Position index
    tSize m_Index;

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
#include "Slice.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_SLICE_H

