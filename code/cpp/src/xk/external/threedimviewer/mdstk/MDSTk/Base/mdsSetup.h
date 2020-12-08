//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/12/06                          \n
 *
 * $Id: mdsSetup.h 2106 2012-02-18 21:55:47Z spanel $
 *
 * Description:
 * - General compilation settings and options.
 * - This header file must be included first before any other!
 */

#ifndef MDS_SETUP_H
#define MDS_SETUP_H

// Configuration file
#include <MDSTk/configure.h>

// Platform dependent definitions
#include <MDSTk/System/mdsEnvironment.h>


namespace mds
{

//=============================================================================
/*
 * Check MDSTk settings
 */

// Check for C++ compiler.
#ifndef __cplusplus
#   error C++ compiler must be used!
#endif

// Check that one of the macros _LINUX or _WIN32 is defined.
#if defined(_WIN32) && defined(_LINUX)
#   error Macros _WIN32 and _LINUX cannot be defined together!
#elif !defined(_WIN32) && !defined(_LINUX)
#   error Please, define one of the macros _WIN32 or _LINUX to specify your OS!
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

#ifdef _OPENMP
    #include <omp.h>

    //! Function sets default OpenMP settings and returns the number
    //! of parallel threads that will be used or -1 if OpenMP is not supported.
    inline int ompDefaultSettings()
    {
        omp_set_nested(1);
        //omp_set_max_active_levels(8);
        omp_set_dynamic(0);
        int iNumOfProcs = omp_get_num_procs();
        int iNumOfThreads = (iNumOfProcs > 2) ? iNumOfProcs / 2 + 1: iNumOfProcs;
        omp_set_num_threads(iNumOfThreads);
        return iNumOfThreads;
    }

    //! Function returns the maximum number of threads in a parallel section,
    //! or 1 if OpenMP is not supported.
    inline int ompGetMaxThreads()
    {
        return omp_get_max_threads();
    }

    //! Function returns ID of the current thread in parallel section.
    //! or 0 if OpenMP is not supported.
    inline int ompGetThreadNum()
    {
        return omp_get_thread_num();
    }
#else
    //! Function sets default OpenMP settings and returns the number
    //! of parallel threads that will be used or -1 if OpenMP is not supported.
    inline int ompDefaultSettings()
    {
        return -1;
    }

    //! Function returns the maximum number of threads in a parallel section,
    //! or 1 if OpenMP is not supported.
    inline int ompGetMaxThreads()
    {
        return 1;
    }

    //! Function returns ID of the current thread in parallel section.
    //! or 0 if OpenMP is not supported.
    inline int ompGetThreadNum()
    {
        return 0;
    }
#endif // _OPENMP


//=============================================================================
/*
 * Helper macros
 */

//! Macro that can be used to prevent compiler warnings when a function
//! parameter is not used in code.
//! Usage: void func(int MDS_UNUSED(Test));
#if defined(__GNUC__)
#   define MDS_UNUSED(x) UNUSED_ ## x __attribute__((unused))
#elif defined(__cplusplus)
#   define MDS_UNUSED(x)
#else
#   define MDS_UNUSED(x) x
#endif

//! Macro that can be used to prevent compiler warnings when a local
//! variable is not further used in code.
//! Usage:
//!   int x, y, z;
//!   MDS_UNUSED_VAR(x);
#define MDS_UNUSED_VAR(x)   ((void)(x))


} // namespace mds

#endif // MDS_SETUP_H

