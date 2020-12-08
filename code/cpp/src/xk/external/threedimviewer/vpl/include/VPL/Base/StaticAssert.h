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
 * Date:    2004/11/29                          \n
 * 
 * Description:
 * - Static assert macro definition
 */

#ifndef VPL_STATICASSERT_H
#define VPL_STATICASSERT_H

#include "Setup.h"


namespace vpl
{

//==============================================================================
/*!
 * Helper structure for the static assertation macro.
 */
template <int>
struct SCompileTimeError;

//! Specialization of the sCompileTimeError helper structure.
template <>
struct SCompileTimeError<true> {};


//==============================================================================
/*
 * Macros
 */

//! Static assertation macro. Parameter cond is a compile-time integral
//! or pointer expression. If cond is zero, msg will appear in a compile-time
//! error message.
#define VPL_STATIC_ASSERT(cond, msg) \
{ \
    vpl::SCompileTimeError<((cond) != 0)> VPL_ERROR_##msg; (void)VPL_ERROR_##msg; \
}


} // namespace vpl

#endif // VPL_STATICASSERT_H

