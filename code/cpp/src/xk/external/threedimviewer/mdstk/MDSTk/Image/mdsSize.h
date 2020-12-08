//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2012 by 3Dim Laboratory s.r.o. \n
 *
 * Author:  info@3dim-laboratory.cz             \n
 * Date:    2012/01/08                          \n
 *
 * $Id:$
 */

#ifndef MDS_Size_H
#define MDS_Size_H

#include "mdsCoordinates.h"


namespace mds
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
    //! Returns the volume size in x-axis (i.e. width).
    const tSize& getXSize() const { return this->x(); }
    tSize& getXSize() { return this->x(); }

    //! Returns the volume size in y-axis (i.e. height).
    const tSize& getYSize() const { return this->y(); }
    tSize& getYSize() { return this->y(); }
   
    //! Returns the volume size.
    const tSize& width() const { return this->x(); }
    tSize& width() { return this->x(); }

    const tSize& height() const { return this->y(); }
    tSize& height() { return this->y(); }

    //! Comparison operators.
    inline friend bool operator == (const CSize2& a, const CSize2& b)
    {
        return (a.x() == b.x()) && (a.y() == b.y());
    }
    inline friend bool operator != (const CSize2& a, const CSize2& b)
    { 
        return (a.x() != b.x()) || (a.y() != b.y());
    }

    //! Operator calculates intersection of two given sizes.
    inline friend CSize2 operator & (const CSize2& a, const CSize2& b)
    {
        return CSize2(mds::math::getMin(a.x(), b.x()), 
                      mds::math::getMin(a.y(), b.y()));
    }
    inline CSize2& operator &= (const CSize2& a)
    {
        this->x() = mds::math::getMin(this->x(), a.x());
        this->y() = mds::math::getMin(this->y(), a.y());
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
    const tSize& getXSize() const { return this->x(); }
    tSize& getXSize() { return this->x(); }

    //! Returns the volume size in y-axis (i.e. height).
    const tSize& getYSize() const { return this->y(); }
    tSize& getYSize() { return this->y(); }

    //! Returns the volume size in z-axis (i.e. depth).
    const tSize& getZSize() const { return this->z(); }
    tSize& getZSize() { return this->z(); }
    
    //! Returns the volume size.
    const tSize& width() const { return this->x(); }
    tSize& width() { return this->x(); }

    const tSize& height() const { return this->y(); }
    tSize& height() { return this->y(); }

    const tSize& depth() const { return this->z(); }
    tSize& depth() { return this->z(); }

    //! Comparison operators.
    inline friend bool operator == (const CSize3& a, const CSize3& b)
    {
        return (a.x() == b.x()) && (a.y() == b.y()) && (a.z() == b.z());
    }
    inline friend bool operator != (const CSize3& a, const CSize3& b)
    { 
        return (a.x() != b.x()) || (a.y() != b.y()) || (a.z() != b.z());
    }

    //! Operator calculates intersection of two given sizes.
    inline friend CSize3 operator & (const CSize3& a, const CSize3& b)
    {
        return CSize3(mds::math::getMin(a.x(), b.x()), 
                      mds::math::getMin(a.y(), b.y()), 
                      mds::math::getMin(a.z(), b.z()));
    }
    inline CSize3& operator &= (const CSize3& a)
    {
        this->x() = mds::math::getMin(this->x(), a.x());
        this->y() = mds::math::getMin(this->y(), a.y());
        this->z() = mds::math::getMin(this->z(), a.z());
        return *this;
    }
};


//==============================================================================
/*
 * Global definitions.
 */

//! Predefined 2D size types.
typedef CSize2<int>     CSize2i;
typedef CSize2<float>   CSize2f;
typedef CSize2<double>  CSize2d;

//! Predefined 3D size types.
typedef CSize3<int>     CSize3i;
typedef CSize3<float>   CSize3f;
typedef CSize3<double>  CSize3d;

//! Favoured representation of an image size.
typedef CSize2i         CImSize;

//! Favoured representation of a volume size.
typedef CSize3i         CVolSize;


} // namespace img
} // namespace mds

#endif // MDS_Size_H
