//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/04/21                          \n
 *
 * $Id: mdsPoint3.h 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - Point in 3D representation.
 */

#ifndef MDS_Point3_H
#define MDS_Point3_H

#include <MDSTk/Math/mdsBase.h>

#include "mdsImageTypes.h"
#include "mdsCoordinates.h"

#include <cmath>


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Global definitions.
 */
namespace Point
{
    //! Returns minimal distance to recognize two neighbouring points.
    template <typename T>
    inline const T& getResolution()
    {
        static const T Resolution = T(0.00001f);
        return Resolution;
    }
}


//==============================================================================
/*!
 * Class representing a point in 2D space.
 */
template <typename T>
class CPoint2 : public CCoordinates2<T>
{
public:
    //! tBase class.
    typedef CCoordinates2<T> tBase;
    
    //! Coordinates type.
    typedef typename tBase::tComponent tComponent;
    
public:
    //! Default constructor.
    CPoint2() {}

    //! Constructor initializes point position.
    CPoint2(const tComponent& px, const tComponent& py) : tBase(px, py) {}

    //! Copy constructor.
    CPoint2(const tBase& p) : tBase(p) {}

    //! Destructor.
    ~CPoint2() {}

    //! Assignment operator.
    CPoint2& operator =(const tBase& p)
    {
        this->x() = p.x();
        this->y() = p.y();
        return *this;
    }


    //! Returns true if two points are almost the same.
    bool isSimilarTo(const CPoint2& p)
    {
        return (mds::math::getAbs(this->x() - p.x()) < Point::getResolution<tComponent>()
                && mds::math::getAbs(this->y() - p.y()) < Point::getResolution<tComponent>()
                );
    }

    //! Euclidean distance of two points.
    tComponent getDistance(const CPoint2& p) const
    {
        tComponent dx = p.x() - this->x();
        tComponent dy = p.y() - this->y();
        return tComponent(std::sqrt(dx * dx + dy * dy));
    }

    //! Square of the Euclidean distance of two points.
    tComponent getSquareDistance(const CPoint2& p) const
    {
        tComponent dx = p.x() - this->x();
        tComponent dy = p.y() - this->y();
        return dx * dx + dy * dy;
    }
};


//==============================================================================
/*!
 * Class representing a point in the 3D space.
 */
template <typename T>
class CPoint3 : public CCoordinates3<T>
{
public:
    //! tBase class.
    typedef CCoordinates3<T> tBase;
    
    //! Coordinates type.
    typedef typename tBase::tComponent tComponent;
    
public:
    //! Default constructor.
    CPoint3() {}

    //! Constructor initializes point position.
    CPoint3(const tComponent& px,
            const tComponent& py,
            const tComponent& pz = tComponent()
            )
        : tBase(px, py, pz)
    {}

    //! Copy constructor.
    CPoint3(const tBase& p) : tBase(p) {}

    //! Destructor.
    ~CPoint3() {}

    //! Assignment operator.
    CPoint3& operator =(const tBase& p)
    {
        this->x() = p.x();
        this->y() = p.y();
        this->z() = p.z();
        return *this;
    }

    //! Returns true if two points are almost the same.
    bool isSimilarTo(const CPoint3& p)
    {
        return (mds::math::getAbs(this->x() - p.x()) < Point::getResolution<tComponent>()
                && mds::math::getAbs(this->y() - p.y()) < Point::getResolution<tComponent>()
                && mds::math::getAbs(this->z() - p.z()) < Point::getResolution<tComponent>()
                );
    }

    //! Euclidean distance of two points.
    tComponent getDistance(const CPoint3& p) const
    {
        tComponent dx = p.x() - this->x();
        tComponent dy = p.y() - this->y();
        tComponent dz = p.z() - this->z();
        return tComponent(std::sqrt(dx * dx + dy * dy + dz * dz));
    }

    //! Square of the Euclidean distance of two points.
    tComponent getSquareDistance(const CPoint3& p) const
    {
        tComponent dx = p.x() - this->x();
        tComponent dy = p.y() - this->y();
        tComponent dz = p.z() - this->z();
        return dx * dx + dy * dy + dz * dz;
    }
};


//==============================================================================
/*
 * Basic definitions.
 */

//! Point in 2D space.
typedef CPoint2<int>    CPoint2i;
typedef CPoint2<float>  CPoint2f;
typedef CPoint2<double> CPoint2d;

//! Point in 3D space.
typedef CPoint3<int>    CPoint3i;
typedef CPoint3<float>  CPoint3f;
typedef CPoint3<double> CPoint3d;

//! Favoured representation of a point in 3D space.
typedef CPoint3<tCoordinate> CPoint3D;


} // namespace img
} // namespace mds

#endif // MDS_Point3_H
