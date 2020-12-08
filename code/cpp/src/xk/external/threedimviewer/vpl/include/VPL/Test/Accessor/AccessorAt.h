//==============================================================================
/* This file is part of
*
* VPL - Voxel Processing Library
* Copyright 2014 3Dim Laboratory s.r.o.
* All rights reserved.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#pragma once
#include <VPL/Base/Types.h>

namespace vpl
{
namespace test
{
//! \brief Access single value from object per "at" method.
template <typename T, class Object>
class AccessorAt1D
{
public:
    //! \brief Executed obj.at(index).
    //! \tparam T Type of obtained value.
    //! \tparam Object Type of object.
    //! \param obj Data where value is obtained.
    //! \param index position in 1D.
    //! \return Obtained value.
    const T& operator()(const Object& obj, vpl::tSize index) const;
};

//! \brief Access single value from object per "at" method.
template <typename T, class Object>
class AccessorAt2D
{
public:
    //! \brief Executed obj.at(x,y).
    //! \tparam T Type of obtained value.
    //! \tparam Object Type of object.
    //! \param obj Data where value is obtained.
    //! \param x index in x axes.
    //! \param y index in y axes. 
    //! \return Obtained value.
    const T& operator()(const Object& obj, vpl::tSize x, vpl::tSize y) const;
};

//! \brief Access single value from object per "at" method.
template <typename T, class Object>
class AccessorAt3D
{
public:
    //! \brief Executed obj.at(x,y,z).
    //! \tparam T Type of obtained value.
    //! \tparam Object Type of object.
    //! \param obj Data where value is obtained.
    //! \param x index in x axes.
    //! \param y index in y axes.
    //! \param z index in z axes.
    //! \return Obtained value.
    const T& operator()(const Object& obj, vpl::tSize x, vpl::tSize y, vpl::tSize z) const;
};

//=============================================================
// Implementations

template <typename T, class Object>
const T& AccessorAt1D<T,Object>::operator()(const Object& obj, vpl::tSize index) const
{
    return obj.at(index);
}
template <typename T, class Object>
const T& AccessorAt2D<T, Object>::operator()(const Object& obj, vpl::tSize x, vpl::tSize y) const
{
    return obj.at(x, y);
}
template <typename T, class Object>
const T& AccessorAt3D<T, Object>::operator()(const Object& obj, vpl::tSize x, vpl::tSize y, vpl::tSize z) const
{
    return obj.at(x, y, z);
}

} // namespace vpl
} // namespace test
