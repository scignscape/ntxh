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
 * Date:    2003/12/05                          \n
 *
 * Description:
 * - Vector template implementation.
 */


//=============================================================================
/*
 * Methods templates.
 */

/**
 *  Simple constructor
 */
template <typename T>
vpl::math::CQuat<T>::CQuat() : m_quaternion()
{

}

/**
 * Initializing constructor
 */
template <typename T>
vpl::math::CQuat<T>::CQuat(tElement x, tElement y, tElement z, tElement w)
    : m_quaternion(w, x, y, z)
{

}

/**
 * Initializing constructor
 *
 * \tparam  V   Axis vector type parameter.
 * \param   a   The angle.
 * \param   v   The axis. Axis must be normalized before use!
 *
 * \return  .
 */

template <typename T>
template<typename V>
vpl::math::CQuat<T>::CQuat(tElement a, const V &v)
    : m_quaternion(Eigen::AngleAxis<tElement>(a, v.asEigen()))
{
}

/**
 * = casting assignment operator.
 *
 * \tparam  T   Quaternion type parameter.
 * \param   q   Assigned quaternion.
 *
 * \return  The result of the operation.
 */
template <typename T>
vpl::math::CQuat<T> & vpl::math::CQuat<T>::operator=(const CQuat &q)
{
    if(this != &q)
    {
        m_quaternion = q.m_quaternion;
    }

    return *this;
}

/**
 * == casting operator.
 *
 * \tparam  T   Quaternion type parameter.
 * \param   q   Compared quaternion.
 *
 * \return  The result of the operation.
 */
template <typename T>
bool vpl::math::CQuat<T>::operator==(const CQuat &q) const
{
    return q.m_quaternion == m_quaternion;
}

/**
 * == casting operator.
 *
 * \tparam  T   Quaternion type parameter.
 * \param   q   Compared quaternion.
 *
 * \return  The result of the operation.
 */
template <typename T>
bool vpl::math::CQuat<T>::operator!=(const CQuat &q) const
{
    return q.m_quaternion != m_quaternion;
}


/**
 * == casting operator.
 *
 * \tparam  T   Quaternion type parameter.
 * \param   q   Compared quaternion.
 *
 * \return  The result of the operation.
 */
template <typename T>
bool vpl::math::CQuat<T>::operator<(const CQuat &q) const
{
    if (m_quaternion[0]<q.m_quaternion[0]) return true;
    else if (m_quaternion[0]>q.m_quaternion[0]) return false;
    else if (m_quaternion[1]<q.m_quaternion[1]) return true;
    else if (m_quaternion[1]>q.m_quaternion[1]) return false;
    else if (m_quaternion[2]<q.m_quaternion[2]) return true;
    else if (m_quaternion[2]>q.m_quaternion[2]) return false;
    else return (m_quaternion[3]<q.m_quaternion[3]);
}

/**
 * Sets.
 *
 * \tparam  T   Generic type parameter.
 * \param   x   The tElement to process.
 * \param   y   The tElement to process.
 * \param   z   The tElement to process.
 * \param   w   The tElement to process.
 */
template <typename T>
void vpl::math::CQuat<T>::set(tElement x, tElement y, tElement z, tElement w)
{
    m_quaternion = tStorage(w, x, y, z);
}


/**
 * Sets.
 *
 * \param   a   The angle.
 * \param   v   The axis vector. Axis must be normalized before use!
 */
template <typename T>
template<typename V>
void vpl::math::CQuat<T>::set(tElement a, const V &v)
{
    m_quaternion = Eigen::AngleAxis<tElement>(a, v);
}


/**
 * Sets quaternion from matrix.
 *
 * \param   m  The rotation matrix.
 */
template <typename T>
template<typename M>
void vpl::math::CQuat<T>::set(const M &m)
{
    *this = m.getRotate();
}

/**
 * Gets rotation matrix.
 *
 * \param [in,out]  m   The rotation matrix to get.
 */
template <typename T>
template<typename M>
void vpl::math::CQuat<T>::get(M &m)
{
    m.makeRotate(*this);
}

/**
 * Makes a rotation quaternion from angle and axis.
 *
 * \tparam  T   Generic type parameter.
 * \param   angle   The angle.
 * \param   x       The axis coordinate x.
 * \param   y       The axis coordinate y.
 * \param   z       The axis coordinate z.
 */
template <typename T>
void vpl::math::CQuat<T>::makeRotate(tElement angle, tElement x, tElement y, tElement z)
{
    m_quaternion = Eigen::AngleAxis<tElement>(angle, v(x, y, z));
}


/**
 * Makes a rotation quaternion from angle and axis.
 *
 * \tparam  T   Generic type parameter.
 * \param   angle   The angle.
 * \param   axis    The rotation axis.
 */
template <typename T>
template<typename V>
void vpl::math::CQuat<T>::makeRotate(tElement angle, const V &axis)
{
    m_quaternion = Eigen::AngleAxis<tElement>(angle, axis.asEigen());
}

/**
 * Creates rotation from one vector to another
 */
template <typename T>
template<typename V>
void vpl::math::CQuat<T>::makeRotate(const V &from, const V &to)
{
    m_quaternion.setFromTwoVectors(from.asEigen(), to.asEigen());
}

/**
 * Gets a rotation parameters.
 *
 * \tparam  T   Generic type parameter.
 * \param [in,out]  angle   The angle.
 * \param [in,out]  x       The axis coordinate x.
 * \param [in,out]  y       The axis coordinate y.
 * \param [in,out]  z       The axis coordinate z.
 */
template <typename T>
void vpl::math::CQuat<T>::getRotate(tElement &angle, tElement &x, tElement &y, tElement &z)
{
    // Get sinus of half angle (quaternion length)
    tElement halfangle_sinus(sqrt( m_quaternion.squaredNorm() ));

    // Compute angle
    angle = 2.0 * atan2( halfangle_sinus, m_quaternion.w() );

    // If any rotation 
    if(halfangle_sinus)
    {
        // Compute axis parameters
        x = m_quaternion.x() / halfangle_sinus;
        y = m_quaternion.y() / halfangle_sinus;
        z = m_quaternion.z() / halfangle_sinus;
    }
    else
    {
        // Zero rotation
        x = 0.0;
        y = 0.0;
        z = 1.0;
    }
}

/**
 * Gets a rotation parameters.
 *
 * \tparam  V   Generic type parameter.
 * \param [in,out]  angle   The angle.
 * \param [in,out]  v       The axis vector.
 */
template<typename T>
template<typename V>
void vpl::math::CQuat<T>::getRotate(tElement &angle, V &v)
{
    tElement x, y, z;
    getRotate(angle, x, y, z);
    v = V(x, y, z);
}

/**
 * Computes spherical linear interpolation between quaternions.
 */
template <typename T>
vpl::math::CQuat<T> vpl::math::CQuat<T>::slerp(tElement t, const CQuat &from, const CQuat &to)
{
    tStorage _from(from.asEigen());
    return(_from.slerp(t, to.asEigen())); 
}

/**
 * Rotate vector by quaternion.
 *
 * \param   v   The rotated vector.
 *
 * \return  The result of the operation.
 */
template<typename T>
template<typename VE>
const CStaticVector<VE, 3> vpl::math::CQuat<T>::operator*(const CStaticVector<VE, 3> &v) const
{
    Eigen::Transform<tElement, 3, Eigen::Affine> t(m_quaternion);
    return t.linear() * v.asEigen();
}

/**
 * \brief   Compute quaternions multiplication.
 *
 * \tparam  T   Element type.
 * \param   q   The const CQuat &amp; to process.
 *
 * \return  The result of the operation.
 */
template <typename T>
const vpl::math::CQuat<T> vpl::math::CQuat<T>::operator*(const CQuat &q) const
{
    return CQuat( 
        q.m_quaternion.w()*m_quaternion.x() + q.m_quaternion.x()*m_quaternion.w() + q.m_quaternion.y()*m_quaternion.z() - q.m_quaternion.z()*m_quaternion.y(),
        q.m_quaternion.w()*m_quaternion.y() - q.m_quaternion.x()*m_quaternion.z() + q.m_quaternion.y()*m_quaternion.w() + q.m_quaternion.z()*m_quaternion.x(),
        q.m_quaternion.w()*m_quaternion.z() + q.m_quaternion.x()*m_quaternion.y() - q.m_quaternion.y()*m_quaternion.x() + q.m_quaternion.z()*m_quaternion.w(),
        q.m_quaternion.w()*m_quaternion.w() - q.m_quaternion.x()*m_quaternion.x() - q.m_quaternion.y()*m_quaternion.y() - q.m_quaternion.z()*m_quaternion.z() 
    );
}


template <typename T>
vpl::math::CQuat<T> & vpl::math::CQuat<T>::operator*=(const CQuat &q)
{
    tElement x = q.m_quaternion.w()*m_quaternion.x() + q.m_quaternion.x()*m_quaternion.w() + q.m_quaternion.y()*m_quaternion.z() - q.m_quaternion.z()*m_quaternion.y();
    tElement y = q.m_quaternion.w()*m_quaternion.y() - q.m_quaternion.x()*m_quaternion.z() + q.m_quaternion.y()*m_quaternion.w() + q.m_quaternion.z()*m_quaternion.x();
    tElement z = q.m_quaternion.w()*m_quaternion.z() + q.m_quaternion.x()*m_quaternion.y() - q.m_quaternion.y()*m_quaternion.x() + q.m_quaternion.z()*m_quaternion.w();
    
    m_quaternion.w()   = q.m_quaternion.w()*m_quaternion.w() - q.m_quaternion.x()*m_quaternion.x() - q.m_quaternion.y()*m_quaternion.y() - q.m_quaternion.z()*m_quaternion.z();

    m_quaternion.z() = z;
    m_quaternion.y() = y;
    m_quaternion.x() = x;

    return (*this);
}



