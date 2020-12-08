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
 * Copyright (c) 2003-2007 by PGMed@FIT         \n
 *
 * Author:  Miroslav Svub, svub@fit.vutbr.cz    \n
 * Date:    2007/04/01                          \n
 *
 * Description:
 * - UMFPACK functions.
 */

#ifndef VPL_UMFPACK_H
#define VPL_UMFPACK_H

#include <VPL/Base/Setup.h>

#ifdef VPL_UMFPACK_ENABLED

// Include UMFPACK
//extern "C"
//{
#include <umfpack.h> 
//}

#endif // VPL_UMFPACK_ENABLED
#endif // VPL_UMFPACK_H

