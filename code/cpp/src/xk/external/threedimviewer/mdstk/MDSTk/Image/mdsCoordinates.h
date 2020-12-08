//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/04/21                          \n
 *
 * $Id: mdsCoordinates.h 2092 2012-02-15 12:50:59Z spanel $
 *
 * Description:
 * - Coordinates in 3D space.
 */

#ifndef MDS_Coordinates_H
#define MDS_Coordinates_H

#include <MDSTk/Base/mdsSmallObject.h>
#include <MDSTk/Math/mdsBase.h>


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Class representing coordinates in 2D space.
 */
template <typename T>
class CCoordinates2 : public mds::base::CSmallValueObject<>
{
public:
    //! Base class.
    typedef mds::base::CSmallValueObject<> tBase;

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
    CCoordinates2(const CCoordinates2& p) : tBase(), m_x(p.m_x), m_y(p.m_y) {}

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
    tComponent& getX() { return m_x; }
    const tComponent& getX() const { return m_x; }
    
    //! Returns reference to the y-coordinate.
    tComponent& getY() { return m_y; }
    const tComponent& getY() const { return m_y; }

    //! Returns reference to the x-coordinate.
    tComponent& x() { return m_x; }
    const tComponent& x() const { return m_x; }
    
    //! Returns reference to the y-coordinate.
    tComponent& y() { return m_y; }
    const tComponent& y() const { return m_y; }

    //! Returns XY coordinates.
    CCoordinates2& getXY(tComponent& px, tComponent& py) const
    {
        px = m_x;
        py = m_y;
        return *this;
    }

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
    friend bool operator ==(const CCoordinates2& l, const CCoordinates2& r)
    {
        return (l.m_x == r.m_x) && (l.m_y == r.m_y);
    }
    friend bool operator !=(const CCoordinates2& l, const CCoordinates2& r)
    {
        return (l.m_x != r.m_x) || (l.m_y != r.m_y);
    }


    // Arithmetic operations.
    friend CCoordinates2 operator +(const CCoordinates2& l, const CCoordinates2& r)
    {
        return CCoordinates2(l.m_x + r.m_x, l.m_y + r.m_y);
    }
    friend CCoordinates2 operator -(const CCoordinates2& l, const CCoordinates2& r)
    {
        return CCoordinates2(l.m_x - r.m_x, l.m_y - r.m_y);
    }
    friend CCoordinates2 operator *(const CCoordinates2& l, const CCoordinates2& r)
    {
        return CCoordinates2(l.m_x * r.m_x, l.m_y * r.m_y);
    }
    friend CCoordinates2 operator /(const CCoordinates2& l, const CCoordinates2& r)
    {
        return CCoordinates2(l.m_x / r.m_x, l.m_y / r.m_y);
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
class CCoordinates3 : public mds::base::CSmallValueObject<>
{
public:
    //! Base class.
    typedef mds::base::CSmallValueObject<> tBase;

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
    CCoordinates3(const CCoordinates3& p) : tBase(), m_x(p.m_x), m_y(p.m_y), m_z(p.m_z) {}

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
    tComponent& getX() { return m_x; }
    const tComponent& getX() const { return m_x; }
    
    //! Returns reference to the y-coordinate.
    tComponent& getY() { return m_y; }
    const tComponent& getY() const { return m_y; }

    //! Returns reference to the z-coordinate.
    tComponent& getZ() { return m_z; }
    const tComponent& getZ() const { return m_z; }

    //! Returns reference to the x-coordinate.
    tComponent& x() { return m_x; }
    const tComponent& x() const { return m_x; }
    
    //! Returns reference to the y-coordinate.
    tComponent& y() { return m_y; }
    const tComponent& y() const { return m_y; }

    //! Returns reference to the z-coordinate.
    tComponent& z() { return m_z; }
    const tComponent& z() const { return m_z; }

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
    friend bool operator ==(const CCoordinates3& l, const CCoordinates3& r)
    {
        return (l.m_x == r.m_x) && (l.m_y == r.m_y) && (l.m_z == r.m_z);
    }
    friend bool operator !=(const CCoordinates3& l, const CCoordinates3& r)
    {
        return (l.m_x != r.m_x) || (l.m_y != r.m_y) || (l.m_z != r.m_z);
    }


    // Arithmetic operations.
    friend CCoordinates3 operator +(const CCoordinates3& l, const CCoordinates3& r)
    {
        return CCoordinates3(l.m_x + r.m_x, l.m_y + r.m_y, l.m_z + r.m_z);
    }
    friend CCoordinates3 operator -(const CCoordinates3& l, const CCoordinates3& r)
    {
        return CCoordinates3(l.m_x - r.m_x, l.m_y - r.m_y, l.m_z - r.m_z);
    }
    friend CCoordinates3 operator *(const CCoordinates3& l, const CCoordinates3& r)
    {
        return CCoordinates3(l.m_x * r.m_x, l.m_y * r.m_y, l.m_z * r.m_z);
    }
    friend CCoordinates3 operator /(const CCoordinates3& l, const CCoordinates3& r)
    {
        return CCoordinates3(l.m_x / r.m_x, l.m_y / r.m_y, l.m_z / r.m_z);
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
} // namespace mds

#endif // MDS_Coordinates_H

