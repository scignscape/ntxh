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
 * Copyright (c) 2007-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/09/26                          \n
 *
 * Description:
 * - General compilation settings and options.
 * - NOTE: The 'configure.in' file is only a template for the CMake build
 *   system which creates the final 'configure.h' file during its configuration
 *   phase in the concrete build directory.
 */

#ifndef VPL_CONFIGURE_H
#define VPL_CONFIGURE_H

//==============================================================================
/*
 * VPL settings.
 */

//! Current MDSTk version.
#define VPL_MAJOR_VERSION 1
#define VPL_MINOR_VERSION 0
#define VPL_PATCH_VERSION 0

//! Macro completely disables logging.
#define VPL_LOGGING_DISABLED

//! Macro enables support for multithreaded applications.
#define VPL_MULTITHREADED

//! Macro enables explicit template instantiation.
#define VPL_EXPLICIT_TEMPLATE_INSTANTIATION

//! Macro enables OpenMP support.
//#define VPL_OPENMP_ENABLED

//! Macro enables volumetric data allocation in smaller blocks
//! instead of a single large block. This option might be usefull on 32-bit
//! systems to prevent allocation failures because of memory fragmentation.
//#define VPL_VOLUME_DATA_ALLOCATION_IN_BLOCKS

//! Enables usage of aligned mallocs for images so that the memory
//! will be aligned to a typical cache line size (64 bytes).
#define VPL_USE_ALIGNED_MEMORY_ALLOCATIONS

//! Enables creation of large volumetric images
//! by using 64-bit integer as the size type vpl::base::tSize.
#define VPL_USE_64BIT_SIZE_TYPE

//! Macro is defined if libc++ is used instead of libstdc++ on Mac OS X
//#define VPL_USE_LIBC_ON_MAC

//==============================================================================
/*
 * Optional 3rd party libraries.
 */

//! Enables the FFTW library (see its license).
// #define VPL_FFTW_ENABLED

//! Enables XML support via the TinyXML library.
// #define VPL_XML_ENABLED

//! Should the TinyXML use the STL library?
// #define TIXML_USE_STL

//! Enables the UMFPACK library.
// #define VPL_UMFPACK_ENABLED

//! Disables explicit vectorization within the Eigen library.
// #define EIGEN_DONT_VECTORIZE

//! Disables alignment within the Eigen library completely.
//! This will turn off vectorization.
// #define EIGEN_DONT_ALIGN

//! Enables some optimizations which might affect the accuracy of the result.
//// #define EIGEN_FAST_MATH
// #define01 EIGEN_FAST_MATH

//! Enables use of GDCM derived classes in VPL
// #define VPL_USE_GDCM

//==============================================================================
/*
 * Experimental options.
 */

//! Enables support for the OpenCV library.
// #define VPL_OPENCV_ENABLED


#endif // VPL_CONFIGURE_H

