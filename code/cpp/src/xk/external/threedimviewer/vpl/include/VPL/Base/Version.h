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
 * Copyright (c) 2003-2020 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/22                       
 *
 * Description:
 * - Version information.
 */

#ifndef VPL_Version_H
#define VPL_Version_H

// Configuration file
#include <VPL/configure.h>

// STL
#include <string>


namespace vpl
{

//==============================================================================
/*
 * MDSTk informations.
 */

//! VPL label
const std::string LABEL     = "VPL";

//! Helper macro converts its parameter to string literal.
#define VPL_MAKE_STRING(Param)  #Param
#define VPL_P2STR(Param)        VPL_MAKE_STRING(Param)

//! Current VPL version
const std::string VERSION   = VPL_P2STR(VPL_MAJOR_VERSION) "." VPL_P2STR(VPL_MINOR_VERSION) "." VPL_P2STR(VPL_PATCH_VERSION);

//! Listing of VPL authors
const std::string AUTHORS   = "Michal Spanel, et al., 3Dim Laboratory s.r.o.";

//! E-mail of the VPL
const std::string EMAIL     = "info@3dim-laboratory.cz";


} // namespace vpl

#endif // VPL_Version_H

