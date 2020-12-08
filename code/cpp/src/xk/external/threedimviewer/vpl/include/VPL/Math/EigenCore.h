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
 * Copyright (c) 2011 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2011/05/28                          \n
 *
 * Description:
 * - Please, use this header file to include Eigen3 core!
 */

#ifndef VPL_EigenCore_H
#define VPL_EigenCore_H

#include <VPL/Base/Setup.h>

// Disable annoying warnings in Eigen code
#if defined(_WIN32) && defined(_MSC_VER)
#   pragma warning( disable: 4308 )
#   pragma warning( disable: 4307 )
#endif // _MSC_VER

// Fix for missing alloca on Mac OS X and Eigen 3.2.
#if defined(_LINUX) || defined(_MACOSX)
#   include <alloca.h>
#endif

// Eigen3
#include <Eigen/Core>

// MDSTk-specific definitions
#include "EigenNumTraits.h"


#endif // VPL_EigenCore_H
