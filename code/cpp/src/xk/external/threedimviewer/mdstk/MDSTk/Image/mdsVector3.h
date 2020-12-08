//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/06/29                          \n
 *
 * $Id: mdsVector3.h 2094 2012-02-16 01:54:45Z spanel $
 *
 * Description:
 * - Vector in 3D space.
 */

#ifndef MDS_Vector3_H
#define MDS_Vector3_H

#include "mdsPoint3.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Class representing a vector in 2D space.
 */
template <typename T>
class CVector2 : public CCoordinates2<T>
{
public:
    //! Base class.
    typedef CCoordinates2<T> tBase;
    
    //! Coordinates type.
    typedef typename tBase::tComponent tComponent;

    //! Corresponding point.
    typedef CPoint2<T> tPoint;
    
public:
    //! Default constructor.
    CVector2() {}

    //! Constructor initializes vector coordinates.
    CVector2(const tComponent& px, const tComponent& py) : tBase(px, py) {}

    //! Constructor creates vector from two given points.
    CVector2(const tPoint& p0, const tPoint& p1)
        : tBase(p1.x() - p0.x(), p1.y() - p0.y())
    {}

    //! Copy constructor.
    CVector2(const tBase& p) : tBase(p) {}

    //! Destructor.
    ~CVector2() {}

    //! Assignment operator.
    CVector2& operator =(const tBase& p)
    {
        this->x() = p.x();
        this->y() = p.y();
        return *this;
    }

    //! Creates the vector from two given points.
    void create(const tPoint& p0, const tPoint& p1)
    {
        this->x() = p1.x() - p0.x();
        this->y() = p1.y() - p0.y();
    }


    //! Returns true if two vectors are almost the same.
    bool isSimilarTo(const CVector2& r)
    {
        return (mds::math::getAbs(this->x() - r.x()) < Point::getResolution<tComponent>()
                && mds::math::getAbs(this->y() - r.y()) < Point::getResolution<tComponent>());
    }

    //! Dot product of two vectors.
    static tComponent dotProduct(const CVector2& u, const CVector2& v)
    {
        return u.x() * v.x() + u.y() * v.y();
    }


    //! Returns the vector length.
    tComponent getLength() const
    {
        return tComponent(std::sqrt(this->x() * this->x() + this->y() * this->y()));
    }

    //! Normalizes the vector coordinates.
    CVector2& normalize()
    {
        tComponent Temp = getLength();
        if( mds::math::getAbs(Temp) < Point::getResolution<tComponent>() )
        {
            this->x() = tComponent();
            this->y() = tComponent();
        }
        else
        {
            tComponent InvTemp = 1 / Temp;
            this->x() *= InvTemp;
            this->y() *= InvTemp;
        }
        return *this;
    }
};


//==============================================================================
/*!
 * Class representing a vector in 3D space.
 */
template <typename T>
class CVector3 : public CCoordinates3<T>
{
public:
    //! Base class.
    typedef CCoordinates3<T> tBase;
    
    //! Coordinates type.
    typedef typename tBase::tComponent tComponent;

    //! Corresponding point.
    typedef CPoint3<T> tPoint;
    
public:
    //! Default constructor.
    CVector3() {}

    //! Constructor initializes vector coordinates.
    CVector3(const tComponent& px,
             const tComponent& py,
             const tComponent& pz = tComponent())
        : tBase(px, py, pz)
    {}

    //! Constructor creates vector from two given points.
    CVector3(const tPoint& p0, const tPoint& p1)
        : tBase(p1.x() - p0.x(), p1.y() - p0.y(), p1.z() - p0.z())
    {}

    //! Copy constructor.
    CVector3(const tBase& p) : tBase(p) {}

    //! Destructor.
    ~CVector3() {}

    //! Assignment operator.
    CVector3& operator =(const tBase& p)
    {
        this->x() = p.x();
        this->y() = p.y();
        this->z() = p.z();
        return *this;
    }

    //! Creates the vector from two given points.
    void create(const tPoint& p0, const tPoint& p1)
    {
        this->x() = p1.x() - p0.x();
        this->y() = p1.y() - p0.y();
        this->z() = p1.z() - p0.z();
    }


    //! Returns true if two vectors are almost the same.
    bool isSimilarTo(const CVector3& r)
    {
        return (mds::math::getAbs(this->x() - r.x()) < Point::getResolution<tComponent>()
                && mds::math::getAbs(this->y() - r.y()) < Point::getResolution<tComponent>()
                && mds::math::getAbs(this->z() - r.z()) < Point::getResolution<tComponent>()
                );
    }

    //! Vector product of two vectors.
    CVector3& vectorProduct(const CVector3& u, const CVector3& v)
    {
        this->x() = u.y() * v.z() - u.z() * v.y();
        this->y() = u.z() * v.x() - u.x() * v.z();
        this->z() = u.x() * v.y() - u.y() * v.x();
        return *this;
    }

    //! Dot product of two vectors.
    static tComponent dotProduct(const CVector3& u, const CVector3& v)
    {
        return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
    }


    //! Returns the vector length.
    tComponent getLength() const
    {
        return tComponent(std::sqrt(this->x() * this->x() + this->y() * this->y() + this->z() * this->z()));
    }

    //! Normalizes the vector coordinates.
    CVector3& normalize()
    {
        tComponent Temp = getLength();
        if( mds::math::getAbs(Temp) < Point::getResolution<tComponent>() )
        {
            this->x() = tComponent();
            this->y() = tComponent();
            this->z() = tComponent();
        }
        else
        {
            tComponent InvTemp = 1 / Temp;
            this->x() *= InvTemp;
            this->y() *= InvTemp;
            this->z() *= InvTemp;
        }
        return *this;
    }

    //! Computes normalized normal vector of given points.
    CVector3& makeNormal(const tPoint& p0,
                         const tPoint& p1,
                         const tPoint& p2
                         )
    {
        CVector3 v01(p0, p1), v02(p0, p2);
        this->x() = v01.x() * v02.z() - v01.z() * v02.y();
        this->y() = v01.z() * v02.x() - v01.x() * v02.z();
        this->z() = v01.x() * v02.y() - v01.y() * v02.x();
        normalize();
        return *this;
    }
};


//==============================================================================
/*
 * Basic definitions.
 */

//! Vector in 2D space.
typedef CVector2<int>    CVector2i;
typedef CVector2<float>  CVector2f;
typedef CVector2<double> CVector2d;

//! Vector in 3D space.
typedef CVector3<int>    CVector3i;
typedef CVector3<float>  CVector3f;
typedef CVector3<double> CVector3d;

//! Favoured representation of a vector in 3D space.
typedef CVector3<tCoordinate>   CVector3D;


} // namespace img
} // namespace mds

#endif // MDS_Vector3_H
