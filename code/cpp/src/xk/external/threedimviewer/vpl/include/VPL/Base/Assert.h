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
 * Date:    2003/10/16                          \n
 *
 * Description:
 * - Assert macro definition.
 */

#ifndef VPL_ASSERT_H
#define VPL_ASSERT_H

#include "Setup.h"

// STL
#include <cassert>


//==============================================================================
/*
 * Macros
 */

//! Assertion macro.
#ifdef _DEBUG
#	define VPL_ASSERT(cond)		assert(cond)
#else
#	define VPL_ASSERT(cond)
#endif

//! Condition checking macro.
#define VPL_CHECK(cond, stmt)	{ if( (!(cond)) ) { stmt; } }


#endif // VPL_ASSERT_H

