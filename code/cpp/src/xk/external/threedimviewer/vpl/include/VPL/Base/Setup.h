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
 * Date:    2004/12/06                          \n
 *
 * Description:
 * - General compilation settings and options.
 * - This header file must be included first before any other!
 */

#ifndef VPL_SETUP_H
#define VPL_SETUP_H

#ifdef _OPENMP
#   include <omp.h>
#endif

// Configuration file prepared by CMake
#include <VPL/configure.h>

// Platform dependent definitions
#include <VPL/System/Environment.h>

#include <VPL/Base/BaseExport.h>


namespace vpl
{

//=============================================================================
/*
 * Check MDSTk settings
 */

// Check for C++ compiler.
#ifndef __cplusplus
#   error C++ compiler must be used!
#endif

// Check that one of the macros _LINUX, _WIN32 or _MACOSX is defined.
#if defined(_WIN32) && defined(_LINUX)
#   error Macros _WIN32 and _LINUX cannot be defined together!
#elif defined(_WIN32) && defined(_MACOSX)
#   error Macros _WIN32 and _MACOSX cannot be defined together!
#elif defined(_LINUX) && defined(_MACOSX)
#   error Macros _LINUX and _MACOSX cannot be defined together!
#elif !defined(_WIN32) && !defined(_LINUX) && !defined(_MACOSX)
#   error Please, define one of the macros _WIN32, _LINUX or _MACOSX to specify your OS!
#endif

// Win32 options
#ifdef _WIN32
#   define WIN32_LEAN_AND_MEAN
#   define NOMINMAX
#endif // _WIN32


//=============================================================================
/*
 * OpenMP settings
 */

//! Simple parallel task processing pixels/values with spatial complexity
//! (i.e. # of items) smaller than this won't be parallelized.
const int VPL_MIN_OMP_COMPLEXITY = 1024;

#ifdef _OPENMP

    //! Function sets default OpenMP settings and returns the number
    //! of parallel threads that will be used or -1 if OpenMP is not supported.
    VPL_BASE_EXPORT int ompDefaultSettings();

    //! Function returns the maximum number of threads in a parallel section,
    //! or 1 if OpenMP is not supported.
    VPL_BASE_EXPORT int ompGetMaxThreads();

    //! Function returns ID of the current thread in parallel section.
    //! or 0 if OpenMP is not supported.
    VPL_BASE_EXPORT int ompGetThreadNum();

#else // _OPENMP not defined

    //! Function sets default OpenMP settings and returns the number
    //! of parallel threads that will be used or -1 if OpenMP is not supported.
    VPL_BASE_EXPORT int ompDefaultSettings();

    //! Function returns the maximum number of threads in a parallel section,
    //! or 1 if OpenMP is not supported.
    VPL_BASE_EXPORT int ompGetMaxThreads();

    //! Function returns ID of the current thread in parallel section.
    //! or 0 if OpenMP is not supported.
    VPL_BASE_EXPORT int ompGetThreadNum();

#endif // _OPENMP


//=============================================================================
/*
 * Helper macros
 */

//! Macro that can be used to prevent compiler warnings when a function
//! parameter is not used in code.
//! Usage: void func(int VPL_UNUSED(Test));
#if defined(__GNUC__)
#   define VPL_UNUSED(x) UNUSED_ ## x __attribute__((unused))
#elif defined(__cplusplus)
#   define VPL_UNUSED(x)
#else
#   define VPL_UNUSED(x) x
#endif

//! Macro that can be used to prevent compiler warnings when a local
//! variable is not further used in code.
//! Usage:
//!   int x, y, z;
//!   VPL_UNUSED_VAR(x);
#define VPL_UNUSED_VAR(x)   ((void)(x))


} // namespace vpl

#endif // VPL_SETUP_H
