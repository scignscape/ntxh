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
 * Copyright (c) 2012 by 3Dim Laboratory s.r.o. \n
 *
 * Author:  info@3dim-laboratory.cz
 * Date:    2012/01/08
 */

#ifndef VPL_Size_H
#define VPL_Size_H

#include "Coordinates.h"

namespace vpl
{
namespace img
{

//==============================================================================
/*!
* Class representing size of a rectangle in 2D space.
*/
template <typename T>
class CSize2 : public CCoordinates2<T>
{
public:
    //! tBase class.
    typedef CCoordinates2<T> tBase;

    //! Coordinates type.
    typedef typename tBase::tComponent tComponent;

public:
    //! Default constructor.
    CSize2() : tBase(0, 0) {}

    //! Constructor initializes the size.
    CSize2(const tComponent& size) : tBase(size, size) {}

    //! Constructor initializes the size.
    CSize2(const tComponent& px, const tComponent& py) : tBase(px, py) {}

    //! Copy constructor.
    CSize2(const tBase& p) : tBase(p) {}

    //! Destructor.
    ~CSize2() {}

    //! Assignment operator.
    CSize2& operator =(const tBase& p)
    {
        this->x() = p.x();
        this->y() = p.y();
        return *this;
    }


#ifndef SWIG
    //! Returns the volume size in x-axis (i.e. width).
    tComponent& getXSize() { return this->x(); }
    //! Returns the volume size in y-axis (i.e. height).
    tComponent& getYSize() { return this->y(); }
    //! Returns the volume width.
    tComponent& width() { return this->x(); }
    //! Returns the volume height.
    tComponent& height() { return this->y(); }
#endif
    //! Returns the volume size in x-axis (i.e. width).
    const tComponent& getXSize() const { return this->x(); }
    //! Returns the volume size in y-axis (i.e. height).
    const tComponent& getYSize() const { return this->y(); }
    //! Returns the volume width.
    const tComponent& width() const { return this->x(); }
    //! Returns the volume height.
    const tComponent& height() const { return this->y(); }
    
    
    
    
    //! Comparison operators.
    inline bool operator == (const CSize2& b)
    {
        return (CCoordinates2<T>::x() == b.x()) && (CCoordinates2<T>::y() == b.y());
    }
    inline bool operator != (const CSize2& b)
    {
        return (CCoordinates2<T>::x() != b.x()) || (CCoordinates2<T>::y() != b.y());
    }
    
    //! Operator calculates intersection of two given sizes.
    inline CSize2 operator & (const CSize2& b)
    {
        return CSize2(vpl::math::getMin(CCoordinates2<T>::x(), b.x()),
            vpl::math::getMin(CCoordinates2<T>::y(), b.y()));
    }
    inline CSize2& operator &= (const CSize2& a)
    {
        this->x() = vpl::math::getMin(this->x(), a.x());
        this->y() = vpl::math::getMin(this->y(), a.y());
        return *this;
    }
};


//==============================================================================
/*!
* Class representing size of a rectangle box in 3D space.
*/
template <typename T>
class CSize3 : public CCoordinates3<T>
{
public:
    //! tBase class.
    typedef CCoordinates3<T> tBase;

    //! Coordinates type.
    typedef typename tBase::tComponent tComponent;

public:
    //! Default constructor.
    CSize3() : tBase(0, 0, 0) {}

    //! Constructor initializes the size.
    CSize3(const tComponent& size) : tBase(size, size, size) {}

    //! Constructor initializes the size.
    CSize3(const tComponent& px,
        const tComponent& py,
        const tComponent& pz
    )
        : tBase(px, py, pz)
    {}

    //! Copy constructor.
    CSize3(const tBase& p) : tBase(p) {}

    //! Destructor.
    ~CSize3() {}

    //! Assignment operator.
    CSize3& operator =(const tBase& p)
    {
        this->x() = p.x();
        this->y() = p.y();
        this->z() = p.z();
        return *this;
    }

    //! Returns the volume size in x-axis (i.e. width).
    const tComponent& getXSize() const { return this->x(); }
    //! Returns the volume size in y-axis (i.e. height).
    const tComponent& getYSize() const { return this->y(); }
    //! Returns the volume size in z-axis (i.e. depth).
    const tComponent& getZSize() const { return this->z(); }
    //! Returns the volume width.
    const tComponent& width() const { return this->x(); }
    //! Returns the volume height.
    const tComponent& height() const { return this->y(); }

    //! Returns the volume depth.
    const tComponent& depth() const { return this->z(); }

#ifndef SWIG
    //! Returns the volume size in x-axis (i.e. width).
    tComponent& getXSize() { return this->x(); }
    //! Returns the volume size in y-axis (i.e. height).
    tComponent& getYSize() { return this->y(); }
    //! Returns the volume size in z-axis (i.e. depth).
    tComponent& getZSize() { return this->z(); }
    //! Returns the volume width.
    tComponent& width() { return this->x(); }
    //! Returns the volume height.
    tComponent& height() { return this->y(); }
    //! Returns the volume depth.
    tComponent& depth() { return this->z(); }
    
#endif

    //! Comparison operators.
    inline bool operator == (const CSize3& b)
    {
        return (CCoordinates3<T>::x() == b.x()) && (CCoordinates3<T>::y() == b.y()) && (CCoordinates3<T>::z() == b.z());
    }
    inline bool operator != (const CSize3& b)
    {
        return (CCoordinates3<T>::x() != b.x()) || (CCoordinates3<T>::y() != b.y()) || (CCoordinates3<T>::z() != b.z());
    }
    
    //! Operator calculates intersection of two given sizes.
    inline CSize3 operator & (const CSize3& b)
    {
        return CSize3(vpl::math::getMin(CCoordinates3<T>::x(), b.x()),
            vpl::math::getMin(CCoordinates3<T>::y(), b.y()),
            vpl::math::getMin(CCoordinates3<T>::z(), b.z()));
    }
    inline CSize3& operator &= (const CSize3& a)
    {
        this->x() = vpl::math::getMin(this->x(), a.x());
        this->y() = vpl::math::getMin(this->y(), a.y());
        this->z() = vpl::math::getMin(this->z(), a.z());
        return *this;
    }
};


//==============================================================================
/*
* Global definitions.
*/

//! Predefined 2D size types.
typedef CSize2<tSize>		CSize2i;
typedef CSize2<float>		CSize2f;
typedef CSize2<double>		CSize2d;

//! Predefined 3D size types.
typedef CSize3<tSize>		CSize3i;
typedef CSize3<float>		CSize3f;
typedef CSize3<double>		CSize3d;

//! Favoured representation of an image size.
typedef CSize2i				CImSize;

//! Favoured representation of a volume size.
typedef CSize3i				CVolSize;


} // namespace img
} // namespace vpl

#endif // VPL_Size_H
