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
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.c
 * Date:    2003/10/26                          \n
 *
 * Description:
 * - Definition of various system constants and macros.
 */

#ifndef VPL_SYSTEM_H
#define VPL_SYSTEM_H


//=============================================================================
/*
 * Global definitions.
 * - Windows version.
 */

#ifdef _WIN32

//! Slash used in path.
#define SLASHC                  '\\'
#define SLASHSTR                "\\"

//! Infinite waiting.
#define VPL_WAIT_INFINITE       INFINITE

#endif // _WIN32


//=============================================================================
/*
 * Global definitions.
 * - Linux version
 */

#if defined(_LINUX) || defined(_MACOSX)

//! Slash used in path.
#define SLASHC                  '/'
#define SLASHSTR                "/"

//! Infinite waiting.
#define VPL_WAIT_INFINITE       0xFFFFFF

#endif // _LINUX || _MACOSX


#endif // VPL_SYSTEM_H

