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
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.c
 * Date:    2005/09/14                          \n
 *
 * Description:
 * - Basic types definition.
 */

#ifndef VPL_SYSTEMTYPES_H
#define VPL_SYSTEMTYPES_H

#include <VPL/Base/Setup.h>

// Windows version
#ifdef _WIN32
#    include <stdio.h>
#endif // _WIN32

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <sys/types.h>
#endif // _LINUX || _MACOSX


namespace vpl
{
namespace sys
{

//=============================================================================
/*
 * Global definitions.
 * - Windows version.
 */

#ifdef _WIN32

//! Basic system types.
typedef __int8              tInt8;
typedef unsigned __int8     tUInt8;
typedef __int16             tInt16;
typedef unsigned __int16    tUInt16;
typedef __int32             tInt32;
typedef unsigned __int32    tUInt32;
typedef __int64             tInt64;
typedef unsigned __int64    tUInt64;

#endif // _WIN32


//=============================================================================
/*
 * Global definitions.
 * - Linux and Mac OS X version.
 */

#if defined(_LINUX) || defined(_MACOSX)

//! Basic system types.
typedef __int8_t            tInt8;
typedef __uint8_t           tUInt8;
typedef __int16_t           tInt16;
typedef __uint16_t          tUInt16;
typedef __int32_t           tInt32;
typedef __uint32_t          tUInt32;
typedef __int64_t           tInt64;
typedef __uint64_t          tUInt64;

#endif // _LINUX || _MACOSX


} // namespace sys
} // namespace vpl

#endif // VPL_SYSTEMTYPES_H
