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
 * Date:    2003/10/22                          \n
 * 
 * Description:
 * - Date and time of the last compilation.
 */

#ifndef VPL_BuildDate_H
#define VPL_BuildDate_H

#include "BaseExport.h"

// STL
#include <string>


namespace vpl
{

//==============================================================================
/*
 * Build date and time
 */

//! Date of the compilation
VPL_BASE_EXPORT const std::string BUILD_DATE = __DATE__;

//! Time of the compilation
VPL_BASE_EXPORT const std::string BUILD_TIME = __TIME__;


} // namespace vpl

#endif // VPL_BuildDate_H

