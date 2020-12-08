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
 * Medical Data Segmentation Toolkit (MDSTk)   \n
 * Copyright (c) 2003-2010 by Michal Spanel    \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz \n
 * Date:    2003/12/03                         \n
 *
 * Description:
 * - Class template providing basic matrix operations.
 */

#ifndef VPL_QUATERNION_H
#define VPL_QUATERNION_H

#include <Eigen/Geometry>
#include <VPL/Base/SharedPtr.h>
#include <VPL/Math/StaticVector.h>
#include "QuaternionBase.h"
#include "MathExceptions.h"



namespace vpl
{
namespace math
{
// Declare vector traits first...
VPL_QUATERNION_TRAITS(CQuat)

//==============================================================================
/*!
 * Class template providing quaternion computation 
 */
template <typename T>
class CQuat : public vpl::base::CObject, public CQuaternionBase<CQuat<T> >
{
public:
    //! Base class.
    typedef CQuaternionBase<CStaticVector<T, 4> > tBase;

    //! Templates that require members of the CVector class can use
    //! this enum to check the existence.
    enum { CLASS_QUATERNION };

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CQuat);

    //! Vector element type.
    typedef T tElement;

    //! Underlying data (see the Eigen math library).
    typedef Eigen::Quaternion< tElement, Eigen::ColMajor | Eigen::AutoAlign > tStorage;

public:
// Constructors
    //! Simple constructor
    CQuat();

    //! Initializing constructor - by elements
    CQuat(tElement x, tElement y, tElement z, tElement w);

    //! Initializing constructor - by vector
    template<typename V> 
    CQuat(const V &v): m_quaternion(0, v[0], v[1], v[2])   { }

    //! Initializing constructor - by angle (in radians), axis
    template<typename V>
    CQuat(tElement a, const V &v);

    //! Initializing constructor - by two vectors
    template<typename V>
    CQuat(const V &from, const V &to) {makeRotate(from, to);}

    //! Initialize by eigen quaternion
    CQuat(const tStorage &q ) : m_quaternion(q) { } 

    //! Get internal data
    const tStorage &asEigen() const {return m_quaternion; }
    tStorage &asEigen() {return m_quaternion; }

// Operators
    //! Assignment operator
    CQuat & operator=(const CQuat &q);
    //! Equality
    bool operator==(const CQuat &q) const;
    //! Inequality
    bool operator!=(const CQuat &q) const;
    //! Compare
    bool operator<(const CQuat &q) const;

    //! Multiply by scalar
    const CQuat operator * (tElement s) const { return CQuat(*this) *= s; }
    //! Unary multiply by scalar
    CQuat & operator *= (tElement s) { m_quaternion.x() *= s; m_quaternion.y() *= s; m_quaternion.z() *= s; m_quaternion.w() *= s; return *this; }
    //! Divide by scalar
    const CQuat operator / (tElement s) const { return CQuat(*this) /= s; }
    //! Unary divide by scalar
    CQuat & operator /= (tElement s) { m_quaternion.x() /= s; m_quaternion.y() /= s; m_quaternion.z() /= s; m_quaternion.w() /= s; return *this; }
    //! Multiply by quaternion
    const CQuat operator * (const CQuat &q) const;
    //! Unary multiply by quaternion
    CQuat & operator *= (const CQuat &q); 
    //! Divide by quaternion
    const CQuat operator / (const CQuat &q) const {return CQuat(*this * q.inverse()); }
    //! Divide by quaternion - unary operator
    CQuat & operator /= (const CQuat &q) { *this = *this * q.inverse(); return *this; }

// Initialization
    //! Set by elements
    void set(tElement x, tElement y, tElement z, tElement w);
    //! Set by angle-axis
    template<typename V>
    void set(tElement a, const V &v);
    //! Set by matrix
    template<typename M>
    void set(const M &m);

// Data access
    //! Convert quaternion to rotation matrix
    template<typename M> 
    void get(M &m);
    //! Element access
    tElement & operator[](vpl::tSize i) {switch(i){case 0: return m_quaternion.x(); case 1: return m_quaternion.y(); case 2: return m_quaternion.z(); } return m_quaternion.w();}
    //! Element access
    const tElement & operator[](vpl::tSize i) const {switch(i){case 0: return m_quaternion.x(); case 1: return m_quaternion.y(); case 2: return m_quaternion.z(); } return m_quaternion.w();}
    //! Element access
    tElement & operator()(vpl::tSize i) {switch(i){case 0: return m_quaternion.x(); case 1: return m_quaternion.y(); case 2: return m_quaternion.z(); } return m_quaternion.w();}
    //! Element access
    tElement operator()(vpl::tSize i) const {switch(i){case 0: return m_quaternion.x(); case 1: return m_quaternion.y(); case 2: return m_quaternion.z(); } return m_quaternion.w();}
    //! Element access
    tElement & at(vpl::tSize i) { switch (i) { case 0: return m_quaternion.x(); case 1: return m_quaternion.y(); case 2: return m_quaternion.z(); } return m_quaternion.w(); }
    //! Element access
    tElement at(vpl::tSize i) const { switch (i) { case 0: return m_quaternion.x(); case 1: return m_quaternion.y(); case 2: return m_quaternion.z(); } return m_quaternion.w(); }

    //! Element access
    tElement & x() { return m_quaternion.x(); }
    tElement & y() { return m_quaternion.y(); }
    tElement & z() { return m_quaternion.z(); }
    tElement & w() { return m_quaternion.w(); }
    tElement x() const { return m_quaternion.x(); }
    tElement y() const { return m_quaternion.y(); }
    tElement z() const { return m_quaternion.z(); }
    tElement w() const { return m_quaternion.w(); }
    //! Returns true if quaternion represents zero rotation
    bool zeroRotate()  const { return m_quaternion.x() == 0.0 && m_quaternion.y() == 0.0 && m_quaternion.z() == 0.0 && m_quaternion.w() == 1.0; }

// Create rotations
    void makeRotate(tElement angle, tElement x, tElement y, tElement z);
    template<typename V>
    void makeRotate(tElement angle, const V &axis);
    template<typename V>
    void makeRotate(const V &from, const V &to);

// Get rotation
    //! Get rotation parameters  
    void getRotate(tElement &angle, tElement &x, tElement &y, tElement &z);
    //! Get rotation parameters - axis store to vector
    template<typename V>
    void getRotate(tElement &angle, V &v);

// Slerp
    //! Compute Spherical linear interpolation
    static CQuat slerp(tElement t, const CQuat &from, const CQuat &to);

// Vector manipulation
    // Rotate vector by quaternion
    template<typename VE>
    const CStaticVector<VE, 3> operator *(const CStaticVector<VE, 3> &v) const;

// Others
    //! Invert quaternion
    void invert() {m_quaternion = m_quaternion.inverse();}
    //! Return inversed quaternion
    tStorage inverse() const {return m_quaternion.inverse(); }
    //! Return length (norm) of quaternion
    tElement length() const { return m_quaternion.norm();}
    //! Return squared length (norm) of quaternion
    tElement length2() const {return m_quaternion.squaredNorm(); }
protected:
    //! Quaternion data
    tStorage m_quaternion;

}; // class CQuat


#include "Quaternion.hxx"

//=============================================================================
/*
 * Basic type definitions.
 */

//! Quaternion with double parameters
typedef CQuat<double> CDQuat;

//! Quaternion with float parameters
typedef CQuat<float> CFQuat;

//! Pointer to quaternion with double parameters
typedef CQuat<double>::tSmartPtr CDQuatPtr;

//! Pointer to quaternion with float parameters
typedef CQuat<float>::tSmartPtr CFQuatPtr;

} // namespace math
} // namespace vpl

// VPL_QUATERNION_H
#endif

