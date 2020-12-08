//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2007-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/09/26                          \n
 *
 * $Id: configure.in 2049 2012-01-09 13:04:08Z spanel $
 *
 * Description:
 * - General compilation settings and options.
 * - NOTE: The 'configure.in' file is only a template for the CMake build
 *   system which creates the final 'configure.h' file during its configuration
 *   phase in the concrete build directory.
 */

#ifndef MDS_CONFIGURE_H
#define MDS_CONFIGURE_H


//==============================================================================
/*
 * MDSTk settings.
 */

//! Current MDSTk version.
#define MDS_MAJOR_VERSION 1
#define MDS_MINOR_VERSION 0
#define MDS_PATCH_VERSION 0

//! Macro completely disables logging.
// #define MDS_LOGGING_DISABLED

//! Macro enables support for multithreaded applications.
#define MDS_MULTITHREADED

//! Macro enables explicit template instantiation.
#define MDS_EXPLICIT_TEMPLATE_INSTANTIATION

//! Macro enables OpenMP support.
// #define MDS_OPENMP_ENABLED


//==============================================================================
/*
 * Optional 3rd party libraries.
 */

//! Enables the FFTW library (see its license).
// #define MDS_FFTW_ENABLED

//! Enables XML support via the TinyXML library.
// #define MDS_XML_ENABLED

//! Should the TinyXML use the STL library?
// #define TIXML_USE_STL

//! Enables the UMFPACK library.
// #define MDS_UMFPACK_ENABLED

//! Disables explicit vectorization within the Eigen library.
// #define EIGEN_DONT_VECTORIZE

//! Disables alignment within the Eigen library completely.
//! This will turn off vectorization.
// #define EIGEN_DONT_ALIGN

//! Enables some optimizations which might affect the accuracy of the result.
// #define EIGEN_FAST_MATH


//==============================================================================
/*
 * Experimental options.
 */

//! Enables support for the OpenCV library.
// #define MDS_OPENCV_ENABLED


#endif // MDS_CONFIGURE_H

