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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/04/19                       
 * 
 * Description:
 * - Basic types definition.
 */

#ifndef VPL_TYPES_H
#define VPL_TYPES_H

#include <VPL/System/SystemTypes.h>


namespace vpl
{

//==============================================================================
/*
 * Additional types definitions.
 */

//! Type used to represent matrix, vector and image dimensions, subscribe pixels, etc.
//! - VPL library prescribes this type to be a signed integer!
#ifdef VPL_USE_64BIT_SIZE_TYPE
	typedef vpl::sys::tInt64 tSize;
#else
	typedef vpl::sys::tInt32 tSize;
#endif

} // namespace vpl

#endif // VPL_TYPES_H
