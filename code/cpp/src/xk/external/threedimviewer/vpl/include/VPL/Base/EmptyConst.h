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
 * Copyright (c) 2012 by 3Dim Laboratory s.r.o. \n
 *
 * Author:  info@3dim-laboratory.cz             \n
 * Date:    2012/01/29                          \n
 *
 * Description:
 * - Data allocator policy.
 */

#ifndef VPL_EmptyConst_H
#define VPL_EmptyConst_H

#include "Setup.h"


namespace vpl
{

//==============================================================================
/*
 * Global definitions.
 */

//! Enumeration constant used for calling empty constructor of a class
//! that doesn't initialize any class members! It is usually a parameter
//! of the class constructor.
//! - Use with care!
enum EEmptyConst
{
    EMPTY_CONST
};


} // namespace vpl

#endif // VPL_EmptyConst_H
