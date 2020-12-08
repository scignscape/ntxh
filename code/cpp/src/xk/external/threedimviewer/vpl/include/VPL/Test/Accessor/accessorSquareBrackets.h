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
#include "VPL/Image/Size.h"

namespace vpl
{
namespace test
{
//! \brief Access single value from object per "operator[]".
template <typename T, class Object>
class AccessorSquareBrackets1D
{
public:
    //! \brief Executed obj(index).
    //! \tparam T Type of obtained value.
    //! \tparam Object Type of object.
    //! \param obj Data where value is obtained.
    //! \param index position in 1D.
    //! \return Obtained value.
    const T& operator()(const Object& obj, tSize index) const;
};



//! \brief Access single value from object per "operator[]".
template <typename T, class Object>
class AccessorSquareBrackets2D
{
public:
    //! \brief Executed obj(x,y).
    //! \tparam T Type of obtained value.
    //! \tparam Object Type of object.
    //! \param obj Data where value is obtained.
    //! \param x index in x axes.
    //! \param y index in y axes. 
    //! \return Obtained value.
    const T& operator()(const Object& obj, tSize x, tSize y) const;
};


//! \brief Access single value from object per "operator[]".
template <typename T, class Object>
class AccessorSquareBrackets3D
{
public:
    //! \brief Executed obj(x,y,z).
    //! \tparam T Type of obtained value.
    //! \tparam Object Type of object.
    //! \param obj Data where value is obtained.
    //! \param x index in x axes.
    //! \param y index in y axes.
    //! \param z index in z axes.
    //! \return Obtained value.
    const T& operator()(const Object& obj, tSize x, tSize y, tSize z) const;
};


//! \brief Access single value from object per "operator[]".
template <typename T, class Object>
class AccessorSquareBracketsPtr1D
{
public:
    //! \brief Executed obj(index).
    //! \tparam T Type of obtained value.
    //! \tparam Object Type of object.
    //! \param obj Data where value is obtained.
    //! \param index position in 1D.
    //! \return Obtained value.
    const T& operator()(const Object& obj, tSize index) const;
};



//! \brief Access single value from object per "operator[]".
template <typename T, class Object>
class AccessorSquareBracketsPtr2D
{
public:
    //! \brief Executed obj(x,y).
    //! \tparam T Type of obtained value.
    //! \tparam Object Type of object.
    //! \param obj Data where value is obtained.
    //! \param x index in x axes.
    //! \param y index in y axes. 
    //! \return Obtained value.
    const T& operator()(const Object& obj, tSize x, tSize y) const;
};


//! \brief Access single value from object per "operator[]".
template <typename T, class Object>
class AccessorSquareBracketsPtr3D
{
public:
    //! \brief Executed obj(x,y,z).
    //! \tparam T Type of obtained value.
    //! \tparam Object Type of object.
    //! \param obj Data where value is obtained.
    //! \param x index in x axes.
    //! \param y index in y axes.
    //! \param z index in z axes.
    //! \return Obtained value.
    const T& operator()(const Object& obj, tSize x, tSize y, tSize z) const;
};

//=============================================================
// Implementations

template <typename T, class Object>
const T& AccessorSquareBrackets1D<T, Object>::operator()(const Object& obj, tSize index) const
{
    return obj[index];
}
template <typename T, class Object>
const T& AccessorSquareBrackets2D<T, Object>::operator()(const Object& obj, tSize x, tSize y) const
{
    return obj[x, y];
}

template <typename T, class Object>
const T& AccessorSquareBrackets3D<T, Object>::operator()(const Object& obj, tSize x, tSize y, tSize z) const
{
    return obj[x, y, z];
}

template <typename T, class Object>
const T& AccessorSquareBracketsPtr1D<T, Object>::operator()(const Object& obj, tSize index) const
{
    return *obj[index];
}
template <typename T, class Object>
const T& AccessorSquareBracketsPtr2D<T, Object>::operator()(const Object& obj, tSize x, tSize y) const
{
    return obj[x][y];
}

template <typename T, class Object>
const T& AccessorSquareBracketsPtr3D<T, Object>::operator()(const Object& obj, tSize x, tSize y, tSize z) const
{
    return obj[x][y][z];
}
} // namespace vpl
} // namespace test

