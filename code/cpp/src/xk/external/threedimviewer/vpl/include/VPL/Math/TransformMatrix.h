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
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/06                          \n
 *
 * Description:
 * - Static dense matrix 4x4 useable form geometry computations.
 */

#ifndef VPL_TRANSFORM_MATRIX_H
#define VPL_TRANSFORM_MATRIX_H

#include "StaticMatrix.h"
#include "Quaternion.h"

namespace vpl
{
namespace math
{

// Declare matrix traits first
VPL_MATRIX_TRAITS(CTransformMatrix)

/** 
 * Transform matrix adds useful initializing and homogeneous transformations 
 * computation methods to the static matrix class. These transformations can be 
 * concatenated together as obvious and applied on vectors. 
 *  
 * For further info see http://en.wikipedia.org/wiki/Transformation_matrix
 */
template <typename T>
class CTransformMatrix : public CStaticMatrix<T, 4, 4>
{
public:
    //! Base matrix type
    typedef CStaticMatrix<T, 4, 4> tBase;

    //! Matrix type
    typedef CTransformMatrix<T> tType;
    
    //! Element type
    typedef T tElement;
    
    //! Underlying matrix data (see the Eigen math library).
    typedef typename tBase::tStorage tStorage;

public:
    //! Constructor.
    inline CTransformMatrix();

    //! Copy constructor.
    template <typename U>
    explicit inline CTransformMatrix(const CTransformMatrix<U>& Matrix);

    //! Conversion constructor.
    template <typename Derived>
    inline CTransformMatrix(const Eigen::MatrixBase<Derived>& Matrix);

    //! Copy constructor specialization.
    inline CTransformMatrix(const CTransformMatrix& Matrix);

    //! Initializing constructor - by matrix elements
    inline CTransformMatrix(tElement v00, tElement v01, tElement v02, tElement v03, 
                            tElement v10, tElement v11, tElement v12, tElement v13, 
                            tElement v20, tElement v21, tElement v22, tElement v23, 
                            tElement v30, tElement v31, tElement v32, tElement v33);

    //! Set matrix values
    void set(tElement v00, tElement v01, tElement v02, tElement v03, 
             tElement v10, tElement v11, tElement v12, tElement v13, 
             tElement v20, tElement v21, tElement v22, tElement v23, 
             tElement v30, tElement v31, tElement v32, tElement v33);
    

    //! Initialize as rotation matrix
    template<typename QE>
    inline CTransformMatrix(const CQuat<QE> &quaternion) { makeRotate(quaternion); }

    //! Destructor.
    ~CTransformMatrix() {}

    //! Multiplication of matrices
    inline CTransformMatrix operator * (const CTransformMatrix& Matrix) const { return tBase::m_Matrix * Matrix.m_Matrix; } 
 
// Initializing method 
    //! Create identity matrix
    void makeIdentity() { tBase::unit(); }

    //! Create scale matrix
    template<typename VE>
    void makeScale(const CStaticVector<VE, 3> & v) { makeScale(v[0], v[1], v[2]); }

    //! Create scale matrix from elements
    void makeScale(tElement sx, tElement sy, tElement sz);

    //! Create translation matrix from translation vector
    template<typename VE>
    void makeTranslate(const CStaticVector<VE, 3> & v) { makeTranslate(v[0], v[1], v[2]); }

    //! Create scale matrix from elements
    void makeTranslate(tElement sx, tElement sy, tElement sz);

    //! Create rotation matrix from quaternion
    template<typename QE>
    void makeRotate(const CQuat<QE> &quaternion);

    //! Create rotation from two vectors
    template<typename VE>
    void makeRotate( const CStaticVector<VE, 3>& from, const CStaticVector<VE, 3>& to );

    //! Create rotation from angle and vector axis
    template<typename VE>
    void makeRotate( tElement angle, const CStaticVector<VE, 3> & axis );

    //! Create rotation from angle and axis components
    void makeRotate( tElement angle, tElement x, tElement y, tElement z );

// Methods creating new matrices
    //! Create identity matrix
    inline static CTransformMatrix identity( void );
    
    //! Create scale matrix from scale vector
    template<typename VE>
    inline static CTransformMatrix scale( const CStaticVector<VE, 3> & sv);
    
    //! Create scale matrix from scale components
    inline static CTransformMatrix scale( tElement sx, tElement sy, tElement sz);
    
    //! Create translation matrix from vector
    template<typename VE>
    inline static CTransformMatrix translate( const CStaticVector<VE, 3> & dv);
    
    //! Create translation vector from components
    inline static CTransformMatrix translate( tElement x, tElement y, tElement z);
    
    //! Create rotation matrix from one vector to another
    template<typename VE>
    inline static CTransformMatrix rotate( const CStaticVector<VE, 3>  & from, const CStaticVector<VE, 3> & to);
    
    //! Create rotation matrix from angle and axis components
    inline static CTransformMatrix rotate( tElement angle, tElement x, tElement y, tElement z);
    
    //! Create rotation matrix from angle and axis set by vector
    template<typename VE>
    inline static CTransformMatrix rotate( tElement angle, const CStaticVector<VE, 3> & axis);
    
    //! Create rotation matrix from quaternion
    template<typename QE>
    inline static CTransformMatrix rotate( const CQuat<QE>& quat) { return CTransformMatrix(quat);}

    //! Compute inverse matrix
    inline static CTransformMatrix inverse( const CTransformMatrix &m) { CTransformMatrix _m(m); _m.m_Matrix = m.m_Matrix.inverse(); return _m; }

    //! Invert matrix
    inline bool invert() { tBase::m_Matrix = tBase::m_Matrix.inverse(); return true;}

    //! Invert given matrix and store to me
    inline bool invert(const CTransformMatrix &m) { tBase::m_Matrix = m.m_Matrix.inverse(); return true;}

    //! Set matrix rotation component
    template<typename QE>
    void setRotate(const CQuat<QE>& q);

    //! Get rotation component. This will return incorrect values for scaled matrices!
    template<typename QE>
    CQuat<QE> getRotate() const;

    //! Set translation 
    void setTrans( tElement tx, tElement ty, tElement tz );

    //! Set translation
    template<typename VE>
    void setTrans( const CStaticVector<VE, 3> & v );

    //! Get translation 
    template<typename VE>
    inline CStaticVector<VE, 3> getTrans() const
    {
        return CStaticVector<VE, 3>(tBase::m_Matrix(0, 3), tBase::m_Matrix(1, 3), tBase::m_Matrix(2, 3));
    }

    //! Get Scale vector
    template<typename VE>
    inline CStaticVector<VE, 3> getScale() const 
    {
        CStaticVector<VE, 3> x_vec(tBase::m_Matrix(0, 0), tBase::m_Matrix(1, 0), tBase::m_Matrix(2, 0));
        CStaticVector<VE, 3> y_vec(tBase::m_Matrix(0, 1), tBase::m_Matrix(1, 1), tBase::m_Matrix(2, 1));
        CStaticVector<VE, 3> z_vec(tBase::m_Matrix(0, 2), tBase::m_Matrix(1, 2), tBase::m_Matrix(2, 2));
        return CStaticVector<VE, 3>(x_vec.length(), y_vec.length(), z_vec.length());
    }

    //! Pre-multiply by matrix
    inline CTransformMatrix & preMult(const CTransformMatrix &m) { tBase::m_Matrix = m.asEigen() * tBase::m_Matrix; return *this; }

    //! Post-multiply by matrix
    inline CTransformMatrix & postMult(const CTransformMatrix &m) { tBase::m_Matrix = tBase::m_Matrix * m.asEigen(); return *this; }

    //! Optimized pre-multiplication by translation matrix (given by translation vector)
    template<typename VE>
    inline void preMultTranslate(const CStaticVector<VE, 3> &v) { preMultTranslate(v(0), v(1), v(2)); }

    //! Optimized pre-multiplication by translation matrix (given by translation four element vector)
    template<typename VE>
    inline void preMultTranslate(const CStaticVector<VE, 4> &v) { preMultTranslate(v(0), v(1), v(2)); }

    //! Optimized pre-multiplication by translation matrix (given by three scalars)
    inline void preMultTranslate(tElement tx, tElement ty, tElement tz);

    //! Pre-multiply matrix by rotation given by quaternion
    template<typename QE>
    inline void preMultRotate(const CQuat<QE> &q) { if(q.zeroRotate()) return; preMult(CTransformMatrix(q)); }

    //! Pre-multiply by scale matrix given by vector
    template<typename VE>
    inline void preMultScale(const CStaticVector<VE, 3> &v) { preMultScale(v(0), v(1), v(2)); }

    //! Optimized pre-multiplication by scale matrix (given by four element vector)
    template<typename VE>
    inline void preMultScale(const CStaticVector<VE, 4> &v) { preMultScale(v(0), v(1), v(2)); }

    //! Optimized pre-multiplication by translation matrix (given by three scalars)
    inline void preMultScale(tElement sx, tElement sy, tElement sz);

    //! Optimized post-multiplication by translation matrix (given by translation vector)
    template<typename VE>
    inline void postMultTranslate(const CStaticVector<VE, 3> &v) { postMultTranslate(v(0), v(1), v(2)); }

    //! Optimized post-multiplication by translation matrix (given by translation four element vector)
    template<typename VE>
    inline void postMultTranslate(const CStaticVector<VE, 4> &v) { postMultTranslate(v(0), v(1), v(2)); }

    //! Optimized post-multiplication by translation matrix (given by three scalars)
    inline void postMultTranslate(tElement tx, tElement ty, tElement tz);

    //! Post-multiply matrix by rotation given by quaternion
    template<typename QE>
    inline void postMultRotate(const CQuat<QE> &q) { if(q.zeroRotate()) return; postMult(CTransformMatrix(q)); }

    //! Post-multiply by scale matrix given by vector
    template<typename VE>
    inline void postMultScale(const CStaticVector<VE, 3> &v) { postMultScale(v(0), v(1), v(2)); }

    //! Optimized post-multiplication by scale matrix (given by four element vector)
    template<typename VE>
    inline void postMultScale(const CStaticVector<VE, 4> &v) { postMultScale(v(0), v(1), v(2)); }

    //! Optimized post-multiplication by translation matrix (given by three scalars)
    inline void postMultScale(tElement sx, tElement sy, tElement sz);

// Apply on vector operations

    //! Multiply vector by matrix
    inline CStaticVector<tElement, 4> operator* ( const CStaticVector<tElement, 4> & v ) const { return this->m_Matrix * v.asEigen(); }

    //! Multiply vector by matrix
    inline CStaticVector<tElement, 3> operator* ( const CStaticVector<tElement, 3> & v ) const;

// Transform decomposition
    //! Decompose to three matrices
    void decompose(CTransformMatrix &translation, CTransformMatrix &rotation, CTransformMatrix &scale);

    //! Decompose to translation vector, rotation quaternion and scale vector
    template<typename VE, typename QE>
    void decompose(CStaticVector<VE, 3> &translation, CQuat<QE> &rotation, CStaticVector<VE, 3> &scale);
  
}; // class CTransformMatrix


//==============================================================================
/*
 * Method templates.
 */

// Include the file containing method templates.
#include "TransformMatrix.hxx"


//==============================================================================
/*
 * Basic type definitions.
 */

//! Matrix of float numbers.
typedef CTransformMatrix<float>      CFTransformMatrix;

//! Matrix of double numbers.
typedef CTransformMatrix<double>     CDTransformMatrix;

} // namespace math
} // namespace vpl

// VPL_TRANSFORM_MATRIX_H
#endif

