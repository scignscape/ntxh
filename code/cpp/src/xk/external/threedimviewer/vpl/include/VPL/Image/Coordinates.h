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
 * Date:    2004/04/21                          \n
 *
 * Description:
 * - Coordinates in 3D space.
 */

#ifndef VPL_Coordinates_H
#define VPL_Coordinates_H

#include <VPL/Base/SmallObject.h>
#include <VPL/Math/Base.h>


namespace vpl
{
namespace img
{

//==============================================================================
/*!
* Class representing coordinates in 2D space.
*/
template <typename T>
class CCoordinates2 /*: public vpl::base::CSmallValueObject<>*/
{
public:
    //! Base class.
    //typedef vpl::base::CSmallValueObject<> tBase;
    
    //! Coordinate type.
    typedef T tComponent;
    
public:
    //! Default constructor.
    CCoordinates2() : m_x(), m_y() {}

    //! Constructor initializes 3D coordinates.
    CCoordinates2(const tComponent& px, const tComponent& py)
        : m_x(px)
        , m_y(py)
    {}

    //! Copy constructor.
    CCoordinates2(const CCoordinates2& p) : /*tBase(),*/ m_x(p.m_x), m_y(p.m_y) {}

    //! Destructor.
    ~CCoordinates2() {}

    //! Assignment operator.
    CCoordinates2& operator =(const CCoordinates2& p)
    {
        m_x = p.m_x;
        m_y = p.m_y;
        return *this;
    }

    //! Returns reference to the x-coordinate.
    const tComponent& getX() const { return m_x; }
    //! Returns reference to the y-coordinate.
    const tComponent& getY() const { return m_y; }
    //! Returns reference to the x-coordinate.
    const tComponent& x() const { return m_x; }
    //! Returns reference to the y-coordinate.
    const tComponent& y() const { return m_y; }

#ifndef SWIG
    //! Returns reference to the x-coordinate.
    tComponent& getX() { return m_x; }
    //! Returns reference to the y-coordinate.
    tComponent& getY() { return m_y; }
    //! Returns reference to the x-coordinate.
    tComponent& x() { return m_x; }
    //! Returns reference to the y-coordinate.
    tComponent& y() { return m_y; }
    

    //! Returns XY coordinates.
    CCoordinates2& getXY(tComponent& px, tComponent& py) const
    {
        px = m_x;
        py = m_y;
        return *this;
    }

#endif // !SWIG

    //! Changes coordinates.
    CCoordinates2& setX(const tComponent& px)
    {
        m_x = px;
        return *this;
    }
    CCoordinates2& setY(const tComponent& py)
    {
        m_y = py;
        return *this;
    }

    //! Sets XY point coordinates.
    CCoordinates2& setXY(const tComponent& px, const tComponent& py)
    {
        m_x = px;
        m_y = py;
        return *this;
    }


    // Comparison operators.
    bool operator ==(const CCoordinates2& r)
    {
        return (m_x == r.m_x) && (m_y == r.m_y);
    }
    bool operator !=(const CCoordinates2& r)
    {
        return (m_x != r.m_x) || (m_y != r.m_y);
    }


    // Arithmetic operations.
    CCoordinates2 operator +(const CCoordinates2& r)
    {
        return CCoordinates2(m_x + r.m_x, m_y + r.m_y);
    }
    CCoordinates2 operator -(const CCoordinates2& r)
    {
        return CCoordinates2(m_x - r.m_x, m_y - r.m_y);
    }
    CCoordinates2 operator *(const CCoordinates2& r)
    {
        return CCoordinates2(m_x * r.m_x, m_y * r.m_y);
    }
    CCoordinates2 operator /(const CCoordinates2& r)
    {
        return CCoordinates2(m_x / r.m_x, m_y / r.m_y);
    }

    // Miscellaneous combined assignment operators.
    CCoordinates2& operator +=(const CCoordinates2& p)
    {
        m_x += p.m_x;
        m_y += p.m_y;
        return *this;
    }
    CCoordinates2& operator -=(const CCoordinates2& p)
    {
        m_x -= p.m_x;
        m_y -= p.m_y;
        return *this;
    }
    CCoordinates2& operator *=(const CCoordinates2& p)
    {
        m_x *= p.m_x;
        m_y *= p.m_y;
        return *this;
    }
    CCoordinates2& operator /=(const CCoordinates2& p)
    {
        m_x /= p.m_x;
        m_y /= p.m_y;
        return *this;
    }

    // Combined assignment operators.
    CCoordinates2& operator +=(const tComponent& c)
    {
        m_x += c;
        m_y += c;
        return *this;
    }
    CCoordinates2& operator -=(const tComponent& c)
    {
        m_x -= c;
        m_y -= c;
        return *this;
    }
    CCoordinates2& operator *=(const tComponent& c)
    {
        m_x *= c;
        m_y *= c;
        return *this;
    }
    CCoordinates2& operator /=(const tComponent& c)
    {
        m_x /= c;
        m_y /= c;
        return *this;
    }


    //! Returns sum of all coordinates.
    tComponent getSum() const { return m_x + m_y; }

    //! Returns multiplication of all coordinates.
    tComponent getMult() const { return m_x * m_y; }

protected:
    //! Coordinates in 2D space.
    tComponent m_x, m_y;
};


//==============================================================================
/*!
* Class representing coordinates in 3D space.
*/
template <typename T>
class CCoordinates3 /*: public vpl::base::CSmallValueObject<>*/
{
public:
    //! Base class.
    //typedef vpl::base::CSmallValueObject<> tBase;

    //! Coordinate type.
    typedef T tComponent;

public:
    //! Default constructor.
    CCoordinates3() : m_x(), m_y(), m_z() {}
    
    //! Constructor initializes 3D coordinates.
    CCoordinates3(const tComponent& px,
        const tComponent& py,
        const tComponent& pz = tComponent()
    )
        : m_x(px)
        , m_y(py)
        , m_z(pz)
    {}
    
    //! Copy constructor.
    CCoordinates3(const CCoordinates3& p) : /*tBase(),*/ m_x(p.m_x), m_y(p.m_y), m_z(p.m_z) {}
    
    //! Destructor.
    ~CCoordinates3() {}
    
    //! Assignment operator.
    CCoordinates3& operator =(const CCoordinates3& p)
    {
        m_x = p.m_x;
        m_y = p.m_y;
        m_z = p.m_z;
        return *this;
    }
    //! Returns reference to the x-coordinate.
    const tComponent& getX() const { return m_x; }
    //! Returns reference to the y-coordinate.
    const tComponent& getY() const { return m_y; }
    //! Returns reference to the z-coordinate.
    const tComponent& getZ() const { return m_z; }
    //! Returns reference to the x-coordinate.
    const tComponent& x() const { return m_x; }
    //! Returns reference to the y-coordinate.
    const tComponent& y() const { return m_y; }
    //! Returns reference to the z-coordinate.
    const tComponent& z() const { return m_z; }

#ifndef SWIG

    //! Returns reference to the x-coordinate.
    tComponent& getX() { return m_x; }
    //! Returns reference to the y-coordinate.
    tComponent& getY() { return m_y; }
    //! Returns reference to the z-coordinate.
    tComponent& getZ() { return m_z; }
    //! Returns reference to the x-coordinate.
    tComponent& x() { return m_x; }
    //! Returns reference to the y-coordinate.
    tComponent& y() { return m_y; }
    //! Returns reference to the z-coordinate.
    tComponent& z() { return m_z; }
    //! Returns XY point coordinates.
    CCoordinates3& getXY(tComponent& px, tComponent& py) const
    {
        px = m_x;
        py = m_y;
        return *this;
    }
    
    //! Returns all point coordinates.
    CCoordinates3& getXYZ(tComponent& px, tComponent& py, tComponent& pz) const
    {
        px = m_x;
        py = m_y;
        pz = m_z;
        return *this;
    }
    
#endif
    
    //! Returns point coordinate.
    CCoordinates3& setX(const tComponent& px)
    {
        m_x = px;
        return *this;
    }
    CCoordinates3& setY(const tComponent& py)
    {
        m_y = py;
        return *this;
    }
    CCoordinates3& setZ(const tComponent& pz)
    {
        m_z = pz;
        return *this;
    }
    
    //! Sets XY point coordinates.
    CCoordinates3& setXY(const tComponent& px, const tComponent& py)
    {
        m_x = px;
        m_y = py;
        return *this;
    }
    
    //! Sets all point coordinates.
    CCoordinates3& setXYZ(const tComponent& px, const tComponent& py, const tComponent& pz)
    {
        m_x = px;
        m_y = py;
        m_z = pz;
        return *this;
    }
    
    
    // Comparison operators.
    bool operator ==(const CCoordinates3& r)
    {
        return (m_x == r.m_x) && (m_y == r.m_y) && (m_z == r.m_z);
    }
    bool operator !=(const CCoordinates3& r)
    {
        return (m_x != r.m_x) || (m_y != r.m_y) || (m_z != r.m_z);
    }
    
    
    // Arithmetic operations.
    CCoordinates3 operator +(const CCoordinates3& r)
    {
        return CCoordinates3(m_x + r.m_x, m_y + r.m_y, m_z + r.m_z);
    }
    CCoordinates3 operator -(const CCoordinates3& r)
    {
        return CCoordinates3(m_x - r.m_x, m_y - r.m_y, m_z - r.m_z);
    }
    CCoordinates3 operator *(const CCoordinates3& r)
    {
        return CCoordinates3(m_x * r.m_x, m_y * r.m_y, m_z * r.m_z);
    }
    CCoordinates3 operator /(const CCoordinates3& r)
    {
        return CCoordinates3(m_x / r.m_x, m_y / r.m_y, m_z / r.m_z);
    }
    
    // Miscellaneous combined assignment operators.
    CCoordinates3& operator +=(const CCoordinates3& p)
    {
        m_x += p.m_x;
        m_y += p.m_y;
        m_z += p.m_z;
        return *this;
    }
    CCoordinates3& operator -=(const CCoordinates3& p)
    {
        m_x -= p.m_x;
        m_y -= p.m_y;
        m_z -= p.m_z;
        return *this;
    }
    CCoordinates3& operator *=(const CCoordinates3& p)
    {
        m_x *= p.m_x;
        m_y *= p.m_y;
        m_z *= p.m_z;
        return *this;
    }
    CCoordinates3& operator /=(const CCoordinates3& p)
    {
        m_x /= p.m_x;
        m_y /= p.m_y;
        m_z /= p.m_z;
        return *this;
    }
    
    // Combined assignment operators.
    CCoordinates3& operator +=(const tComponent& c)
    {
        m_x += c;
        m_y += c;
        m_z += c;
        return *this;
    }
    CCoordinates3& operator -=(const tComponent& c)
    {
        m_x -= c;
        m_y -= c;
        m_z -= c;
        return *this;
    }
    CCoordinates3& operator *=(const tComponent& c)
    {
        m_x *= c;
        m_y *= c;
        m_z *= c;
        return *this;
    }
    CCoordinates3& operator /=(const tComponent& c)
    {
        m_x /= c;
        m_y /= c;
        m_z /= c;
        return *this;
    }
    
    
    //! Returns sum of all coordinates.
    tComponent getSum() const { return m_x + m_y + m_z; }
    
    //! Returns multiplication of all coordinates.
    tComponent getMult() const { return m_x * m_y * m_z; }
    
    protected:
        //! Coordinates in the 3D space.
        tComponent m_x, m_y, m_z;
    };
    
    
    } // namespace img
} // namespace vpl

#endif // VPL_Coordinates_H

