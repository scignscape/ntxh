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
#include <sstream>

namespace vpl
{
namespace test
{
//! \brief Access complex value, is converted to string.
template <typename T, class Object>
class ComplexString1D
{
public:

	//! \brief String from value getted by obj.at(index).
	//! \tparam Object Type of object.
	//! \param obj Data where value is obtained.
	//! \param index position in 1D.
	//! \return Converted string
    std::string operator()(const Object& obj,tSize index) const
    {
        std::stringstream stream;
        stream << obj.at(index);
        return std::string(stream.str());
    }
};

//! \brief String from value getted by obj.at(x,y).
//! \tparam Object Type of object.
//! \param obj Data where value is obtained.
//! \param x index in x axes.
//! \param y index in y axes. 
//! \return Converted string
template <typename T, class Object>
class ComplexString2D
{
public:
    std::string operator()(const Object& obj,tSize x, tSize y) const
    {
        std::stringstream stream;
        stream << obj.at(x,y);
        return std::string(stream.str());
    }
};

//! \brief String from value getted by obj.at(x,y,z).
//! \brief String from value getted by obj.at(x,y).
//! \tparam Object Type of object.
//! \param obj Data where value is obtained.
//! \param x index in x axes.
//! \param y index in y axes. 
//! \param z index in z axes.
//! \return Converted string
template <typename T, class Object>
class ComplexString3D
{
public:
    std::string operator()(const Object& obj, tSize x, tSize y, tSize z) const
    {
        std::stringstream stream;
        stream << obj.at(x, y, z);
        return std::string(stream.str());
    }
};


} // namespace vpl
} // namespace test
