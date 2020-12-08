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
 * Date:    2004/06/05                          \n
 * 
 * Description:
 * - Static matrix template implementation.
 */

#define INIT_ROW(R, a, b, c, d) {tBase::m_Matrix(R, 0) = (a); tBase::m_Matrix(R, 1) = (b); tBase::m_Matrix(R, 2) = (c); tBase::m_Matrix(R, 3) = (d);}
#define INIT_COLUMN(C, a, b, c, d) {tBase::m_Matrix(0, C) = (a); tBase::m_Matrix(1, C) = (b); tBase::m_Matrix(2, C) = (c); tBase::m_Matrix(3, C) = (d);}

//==============================================================================
/*
 * Method templates
 */
template <typename T>
inline CTransformMatrix<T>::CTransformMatrix() : tBase()
{
    tBase::unit();
}


// Copy constructor
template <typename T>
template <typename U>
inline CTransformMatrix<T>::CTransformMatrix(const CTransformMatrix<U>& Matrix)
    : tBase(Matrix)
{
}


template <typename T>
template <typename Derived>
inline CTransformMatrix<T>::CTransformMatrix(const Eigen::MatrixBase<Derived>& Matrix)
    : tBase(Matrix)
{
}


// Copy constructor
template <typename T>
inline CTransformMatrix<T>::CTransformMatrix(const CTransformMatrix<T>& Matrix)
    : tBase(Matrix)
{
}

template <typename T>
vpl::math::CTransformMatrix<T>::CTransformMatrix(tElement v00, tElement v01, tElement v02, tElement v03, tElement v10, tElement v11, tElement v12, tElement v13, tElement v20, tElement v21, tElement v22, tElement v23, tElement v30, tElement v31, tElement v32, tElement v33)
    : tBase()
{
    INIT_ROW(0, v00, v01, v02, v03);
    INIT_ROW(1, v10, v11, v12, v13);
    INIT_ROW(2, v20, v21, v22, v23);
    INIT_ROW(3, v30, v31, v32, v33);
}

// Set matrix values
template <typename T>
void vpl::math::CTransformMatrix<T>::set(tElement v00, tElement v01, tElement v02, tElement v03, tElement v10, tElement v11, tElement v12, tElement v13, tElement v20, tElement v21, tElement v22, tElement v23, tElement v30, tElement v31, tElement v32, tElement v33)
{
    INIT_ROW(0, v00, v01, v02, v03);
    INIT_ROW(1, v10, v11, v12, v13);
    INIT_ROW(2, v20, v21, v22, v23);
    INIT_ROW(3, v30, v31, v32, v33);
}

//------------------------------------------------------------------------------------------------

/**
 * \brief   Makes a scale matrix.
 *
 * \tparam  T   Matrix element type.
 * \param   sx  The scale on x.
 * \param   sy  The scale on y.
 * \param   sz  The scale on z.
 */
template <typename T>
void vpl::math::CTransformMatrix<T>::makeScale(tElement sx, tElement sy, tElement sz)
{
    INIT_ROW(0, sx, 0, 0, 0 )
    INIT_ROW(1, 0, sy, 0, 0 )
    INIT_ROW(2, 0, 0, sz, 0 )
    INIT_ROW(3, 0, 0, 0,  1 )
}

/**
 * \brief   Makes a translation matrix.
 *
 * \tparam  T   Matrix element type.
 * \param   sx  The translation on x.
 * \param   sy  The translation on y.
 * \param   sz  The translation on z.
 */
template <typename T>
void vpl::math::CTransformMatrix<T>::makeTranslate(tElement sx, tElement sy, tElement sz)
{
    INIT_COLUMN(0,  1,  0,  0,  0 )
    INIT_COLUMN(1,  0,  1,  0,  0 )
    INIT_COLUMN(2,  0,  0,  1,  0 )
    INIT_COLUMN(3, sx, sy, sz,  1 )
}

/**
 * \brief   Makes a rotation matrix.
 *
 * \param   quaternion  The quaternion describing rotation.
 */
template <typename T>
template<typename QE>
void vpl::math::CTransformMatrix<T>::makeRotate(const CQuat<QE> &quaternion)
{
    identity();
    setRotate(quaternion);
}

/**
 * \brief   Makes a rotation matrix from two vectors.
 *
 * \param   from    Source for the.
 * \param   to      to.
 */
template <typename T>
template<typename VE>
void vpl::math::CTransformMatrix<T>::makeRotate(const CStaticVector<VE, 3>& from, const CStaticVector<VE, 3>& to)
{
    CQuat<tElement> quaternion(from, to);
    identity();
    setRotate(quaternion);
}

/**
 * \brief   Makes a rotation matrix from angle and axis given by vector.
 *
 * \tparam  VE  Type of the ve.
 * \param   angle   The angle.
 * \param   axis    The axis.
 */
template <typename T>
template<typename VE>
void vpl::math::CTransformMatrix<T>::makeRotate(tElement angle, const CStaticVector<VE, 3> & axis)
{
    CQuat<tElement> quaternion(angle, axis);
    identity();
    setRotate(quaternion);
}


/**
 * \brief   Makes a rotation matrix from angle and axis given by its elements.
 *
 * \tparam  VE  Type of the ve.
 * \param   angle   The angle.
 * \param   axis    The axis.
 */
template <typename T>
void vpl::math::CTransformMatrix<T>::makeRotate(tElement angle, tElement x, tElement y, tElement z)
{
    CQuat<tElement> quaternion(angle, CStaticVector<T, 3>(x, y, z));
    identity();
    setRotate(quaternion);
}

/**
 * \brief   Create and return identity matrix.
 *
 * \tparam  T   Element type.
 *
 * \return  created matrix.
 */
template <typename T>
vpl::math::CTransformMatrix<T> vpl::math::CTransformMatrix<T>::identity(void)
{
    CTransformMatrix m; m.unit();
    return m;
}

/**
 * \brief   Create scale matrix.
 *
 * \param   sv  The scale vector.
 *
 * \return  created matrix.
 */
template<typename T>
template<typename VE>
vpl::math::CTransformMatrix<T> vpl::math::CTransformMatrix<T>::scale(const CStaticVector<VE, 3> & sv)
{
    CTransformMatrix m;
    m.makeScale(sv);
    return m;
}

/**
 * \brief   Create scale matrix.
 *
 * \tparam  T   Matrix element type parameter.
 * \param   sx  The x component.
 * \param   sy  The y component.
 * \param   sz  The z component.
 *
 * \return  created matrix.
 */
template<typename T>
vpl::math::CTransformMatrix<T> vpl::math::CTransformMatrix<T>::scale(tElement sx, tElement sy, tElement sz)
{
    CTransformMatrix m;
    m.makeScale(sx, sy, sz);
    return m;
}

/**
 * \brief   Create translation matrix from translation vector.
 *
 * \tparam  T   Matrix element type parameter.
 * \param   dv  The translation vector.
 *
 * \return  created matrix.
 */
template<typename T>
template<typename VE>
vpl::math::CTransformMatrix<T> vpl::math::CTransformMatrix<T>::translate(const CStaticVector<VE, 3> & dv)
{
    CTransformMatrix m;
    m.makeTranslate(dv);
    return m;
}

/**
 * \brief   Create translation matrix.
 *
 * \tparam  T   Matrix element type parameter.
 * \param   x   The x component of translation vector.
 * \param   y   The y component of translation vector.
 * \param   z   The z component of translation vector.
 *
 * \return  crated matrix.
 */
template <typename T>
vpl::math::CTransformMatrix<T> vpl::math::CTransformMatrix<T>::translate(tElement x, tElement y, tElement z)
{
    CTransformMatrix m;
    m.makeTranslate(x, y, z);
    return m;
}

/**
 * \brief   Create rotation matrix from two vectors.
 *
 * \tparam  T   Matrix element type parameter.
 * \param   from    Starting orientation.
 * \param   to      Ending orientation.
 *
 * \return  Created matrix.
 */
template<typename T>
template<typename VE>
vpl::math::CTransformMatrix<T> vpl::math::CTransformMatrix<T>::rotate(const CStaticVector<VE, 3> & from, const CStaticVector<VE, 3> & to)
{
    return CTransformMatrix(CQuat<T>(from, to));
}

/**
 * \brief   Create rotation matrix from angle and axis components.
 *
 * \tparam  T   Matrix element type parameter.
 * \param   angle   The rotation angle.
 * \param   x       The x component of the rotation axis.
 * \param   y       The y component of the rotation axis.
 * \param   z       The z component of the rotation axis.
 *
 * \return  created matrix.
 */
template <typename T>
vpl::math::CTransformMatrix<T> vpl::math::CTransformMatrix<T>::rotate(tElement angle, tElement x, tElement y, tElement z)
{
    return CTransformMatrix(CQuat<T>(angle, CStaticVector<T, 3>(x, y, z)));
}

/**
 * \brief   Create rotation matrix.
 *
 * \tparam  T   Matrix element type parameter.
 * \param   angle   The rotation angle.
 * \param   axis    The rotation axis.
 *
 * \return  Created matrix.
 */
template<typename T>
template<typename VE>
vpl::math::CTransformMatrix<T> vpl::math::CTransformMatrix<T>::rotate(T angle, const CStaticVector<VE, 3> & axis)
{
    return CTransformMatrix(CQuat<T>(angle, axis));
}

template<typename T>
template<typename QE>
//! Set matrix rotation component
void vpl::math::CTransformMatrix<T>::setRotate(const CQuat<QE>& q)
{
    tBase::unit();
    Eigen::Transform<T, 3, Eigen::Affine, Eigen::RowMajor> tr;
    tr *= q.asEigen(); //= tr.rotate(q.asEigen());

    tBase::m_Matrix.topLeftCorner(3, 3) = q.asEigen().matrix();
}

/**
 * \brief   Transform - multiply vector by matrix.
 *
 * \param   v   The const CStaticVector&lt;VE,3&gt; &amp; to process.
 *
 * \return  The result of the operation.
 */
template<typename T>
inline CStaticVector<T, 3>
    vpl::math::CTransformMatrix<T>::operator*(const CStaticVector<T, 3> & v) const
{
    typename CStaticVector<T, 4>::tStorage ev;
    ev(0) = v(0);
    ev(1) = v(1);
    ev(2) = v(2);
    ev(3) = 1;

    ev = tBase::m_Matrix * ev;
 
    return CStaticVector<T, 3>(ev(0), ev(1), ev(2));
}


/**
 * \brief   Sets the translation.
 *
 * \tparam  T   Matrix element type parameter.
 * \param   tx  The translation on x axis.
 * \param   ty  The translation on y axis.
 * \param   tz  The translation on z axis.
 */
template <typename T>
void vpl::math::CTransformMatrix<T>::setTrans(tElement tx, tElement ty, tElement tz)
{
    INIT_COLUMN(3, tx, ty, tz, 1.0);
}

/**
 * \brief   Sets the trans.
 *
 * \tparam  VE  Type of the vector element.
 * \param   v   The translation vector.
 */
template <typename T>
template<typename VE>
void vpl::math::CTransformMatrix<T>::setTrans(const CStaticVector<VE, 3> & v)
{
    INIT_COLUMN(3, v(0), v(1), v(2), 1.0);
}

/**
 * \brief   Pre multiply matrix by translation matrix given by translation elements.
 *
 * \tparam  T   Matrix element type parameter.
 * \param   tx  The transmit.
 * \param   ty  The ty.
 * \param   tz  The tz.
 */
template <typename T>
void vpl::math::CTransformMatrix<T>::preMultTranslate(tElement tx, tElement ty, tElement tz)
{
#define ADD_MULT(i, j, k, l, val) tBase::m_Matrix(i, j) += tBase::m_Matrix(k, l) * val;

    ADD_MULT(0, 0, 3, 0, tx);
    ADD_MULT(0, 1, 3, 1, tx);
    ADD_MULT(0, 2, 3, 2, tx);
    ADD_MULT(0, 3, 3, 3, tx);

    ADD_MULT(1, 0, 3, 0, ty);
    ADD_MULT(1, 1, 3, 1, ty);
    ADD_MULT(1, 2, 3, 2, ty);
    ADD_MULT(1, 3, 3, 3, ty);

    ADD_MULT(2, 0, 3, 0, tz);
    ADD_MULT(2, 1, 3, 1, tz);
    ADD_MULT(2, 2, 3, 2, tz);
    ADD_MULT(2, 3, 3, 3, tz);
}

/**
 * \brief   Pre multiply by scale matrix given by scale vector elements.
 *
 * \tparam  T   Transform matrix element type.
 * \param   sx  The scale x component.
 * \param   sy  The scale y component.
 * \param   sz  The scale z component.
 */
template <typename T>
void vpl::math::CTransformMatrix<T>::preMultScale(tElement sx, tElement sy, tElement sz)
{
#define MULT_ROW(row, value) tBase::m_Matrix(row, 0) *= value; tBase::m_Matrix(row, 1) *= value; tBase::m_Matrix(row, 2) *= value; tBase::m_Matrix(row, 3) *= value; 

    MULT_ROW(0, sx);
    MULT_ROW(1, sy);
    MULT_ROW(2, sz);
}

/**
 * \brief   Post multiply matrix by translation matrix given by translation elements.
 *
 * \tparam  T   Matrix element type parameter.
 * \param   tx  The transmit.
 * \param   ty  The ty.
 * \param   tz  The tz.
 */
template <typename T>
void vpl::math::CTransformMatrix<T>::postMultTranslate(tElement tx, tElement ty, tElement tz)
{

    ADD_MULT(0, 3, 0, 0, tx);
    ADD_MULT(1, 3, 1, 0, tx);
    ADD_MULT(2, 3, 2, 0, tx);
    ADD_MULT(3, 3, 3, 0, tx);

    ADD_MULT(0, 3, 0, 1, ty);
    ADD_MULT(1, 3, 1, 1, ty);
    ADD_MULT(2, 3, 2, 1, ty);
    ADD_MULT(3, 3, 3, 1, ty);

    ADD_MULT(0, 3, 0, 2, tz);
    ADD_MULT(1, 3, 1, 2, tz);
    ADD_MULT(2, 3, 2, 2, tz);
    ADD_MULT(3, 3, 3, 2, tz);
}


/**
 * \brief   Post multiply by scale matrix given by scale vector elements.
 *
 * \tparam  T   Transform matrix element type.
 * \param   sx  The scale x component.
 * \param   sy  The scale y component.
 * \param   sz  The scale z component.
 */
template <typename T>
void vpl::math::CTransformMatrix<T>::postMultScale(tElement sx, tElement sy, tElement sz)
{
#define MULT_COL(col, value) tBase::m_Matrix(0, col) *= value; tBase::m_Matrix(1, col) *= value; tBase::m_Matrix(2, col) *= value; tBase::m_Matrix(3, col) *= value; 

    MULT_COL(0, sx);
    MULT_COL(1, sy);
    MULT_COL(2, sz);
}

/**
 * \brief   Gets the rotation quaternion.
 *
 * \tparam  T   Generic type parameter.
 *
 * \return  The rotation quaternion.
 */
template <typename T>
template<typename QE>
vpl::math::CQuat<QE> vpl::math::CTransformMatrix<T>::getRotate() const
{
    Eigen::Transform<double, 3, Eigen::Affine> transform(tBase::m_Matrix);
    Eigen::Matrix3d rm, sm;
    transform.computeRotationScaling(&rm, &sm);

    return typename CQuat<QE>::tStorage(rm);
}


/**
 * \brief   Decomposes transformation to translation, rotation and scale.
 *
 * \tparam  T   Generic type parameter.
 * \param [in,out]  translation The translation.
 * \param [in,out]  rotation    The rotation.
 * \param [in,out]  scale       The scale.
 */
template <typename T>
void vpl::math::CTransformMatrix<T>::decompose(CTransformMatrix &translation, CTransformMatrix &rotation, CTransformMatrix &scale)
{
    Eigen::Transform<double, 3, Eigen::Affine> transform(tBase::m_Matrix);
    Eigen::Matrix3d rm, sm;
    transform.computeRotationScaling(&rm, &sm);

    // Compute decomposed matrices
    translation = translate(CStaticVector<tElement, 3>(tBase::m_Matrix(0, 3), tBase::m_Matrix(1, 3), tBase::m_Matrix(2, 3)));
    rotation.m_Matrix.topLeftCorner(3, 3) = rm;
    scale.m_Matrix.topLeftCorner(3, 3) = sm;
}

/**
 * \brief   Decomposes to translation vector, rotation quaternion and scale vector.
 *
 * \tparam  VE  Type of the vector element.
 * \tparam  QE  Type of the quaternion element.
 * \param [in,out]  translation The translation.
 * \param [in,out]  rotation    The rotation.
 * \param [in,out]  scale       The scale.
 */
template <typename T>
template<typename VE, typename QE>
void vpl::math::CTransformMatrix<T>::decompose(CStaticVector<VE, 3> &translation, CQuat<QE> &rotation, CStaticVector<VE, 3> &scale)
{
    Eigen::Transform<double, 3, Eigen::Affine> transform(tBase::m_Matrix);
    Eigen::Matrix3d rm, sm;
    transform.computeRotationScaling(&rm, &sm);

    translation = CStaticVector<tElement, 3>(tBase::m_Matrix(0, 3), tBase::m_Matrix(1, 3), tBase::m_Matrix(2, 3));

    rotation.asEigen() = typename CQuat<QE>::tStorage(rm);

    CStaticVector<VE, 3> x_vec(sm(0, 0),sm(1, 0),sm(2, 0));
    CStaticVector<VE, 3> y_vec(sm(0, 1),sm(1, 1),sm(2, 1));
    CStaticVector<VE, 3> z_vec(sm(0, 2),sm(1, 2),sm(2, 2));
    scale = CStaticVector<VE, 3>(x_vec.length(), y_vec.length(), z_vec.length());
}
