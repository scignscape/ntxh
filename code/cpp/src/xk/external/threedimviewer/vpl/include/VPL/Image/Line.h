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
 * Date:    2004/04/27                       
 *
 * Description:
 * - Definition of graphic primitive line.
 */

#ifndef VPL_LINE_H
#define VPL_LINE_H

#include <VPL/Math/Base.h>

#include "ImageExport.h"
#include "Graphics.h"
#include "Vector3.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Class representing a line in 2D space.
 */
class VPL_IMAGE_EXPORT CLine : public CGraphics<CLine>
{
public:
    //! Base class.
    typedef CGraphics<CLine> tBase;

    //! Line end-points.
    CPoint3D m_Points[2];

public:
    //! Default constructor.
    CLine() {}

    //! Constructor.
    CLine(tCoordinate x1, tCoordinate y1,
          tCoordinate x2, tCoordinate y2,
          CColor Color
          )
        : tBase(Color)
    {
        m_Points[0].x() = x1;
        m_Points[0].y() = y1;
        m_Points[0].z() = 0;
        m_Points[1].x() = x2;
        m_Points[1].y() = y2;
        m_Points[1].z() = 0;
    }

    //! Constructor.
    CLine(tCoordinate x1, tCoordinate y1, tCoordinate z1,
          tCoordinate x2, tCoordinate y2, tCoordinate z2,
          CColor Color
          )
        : tBase(Color)
    {
        m_Points[0].x() = x1;
        m_Points[0].y() = y1;
        m_Points[0].z() = z1;
        m_Points[1].x() = x2;
        m_Points[1].y() = y2;
        m_Points[1].z() = z2;
    }

    //! Constructor.
    CLine(const CPoint3D& p1, const CPoint3D& p2, CColor Color)
        : tBase(Color)
    {
        m_Points[0] = p1;
        m_Points[1] = p2;
    }

    //! Copy constructor.
    CLine(const CLine& l)
        : tBase(l)
    {
        m_Points[0] = l.m_Points[0];
        m_Points[1] = l.m_Points[1];
    }

    //! Destructor.
    ~CLine() {}

    //! Assignment operator.
    CLine& operator =(const CLine& l)
    {
        m_Points[0] = l.m_Points[0];
        m_Points[1] = l.m_Points[1];
        m_Color = l.m_Color;
        return *this;
    }


    //! Miscellaneous combined assignment operators.
    CLine& operator +=(const CVector3D& v)
    {
        m_Points[0].x() += v.x();
        m_Points[0].y() += v.y();
        m_Points[0].z() += v.z();
        m_Points[1].x() += v.x();
        m_Points[1].y() += v.y();
        m_Points[1].z() += v.z();
        return *this;
    }

    CLine& operator -=(const CVector3D& v)
    {
        m_Points[0].x() -= v.x();
        m_Points[0].y() -= v.y();
        m_Points[0].z() -= v.z();
        m_Points[1].x() -= v.x();
        m_Points[1].y() -= v.y();
        m_Points[1].z() -= v.z();
        return *this;
    }

    CLine& operator *=(tCoordinate Scale)
    {
        m_Points[0].x() *= Scale;
        m_Points[0].y() *= Scale;
        m_Points[0].z() *= Scale;
        m_Points[1].x() *= Scale;
        m_Points[1].y() *= Scale;
        m_Points[1].z() *= Scale;
        return *this;
    }


    //! Draws the primitive to a given image.
    template <class I>
    void draw(CImageBase<I>& Image);

    //! Draws the primitive to a given volume.
    template <class V>
    void draw(CVolumeBase<V>& Volume);
};


//==============================================================================
/*
 * Methods templates.
 */
#include "Line.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_LINE_H

