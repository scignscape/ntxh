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
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/08/29                          \n
 *
 * Description:
 * - Dynamic library export settings.
 */

#ifndef VPL_ImageIOExport_H
#define VPL_ImageIOExport_H


//=============================================================================
/*
 * Setup export settings.
 * - VPL_LIBRARY_STATIC ~ using static library
 * - VPL_LIBRARY_SHARED + VPL_MAKING_IMAGEIO_LIBRARY ~ making dynamic library
 * - VPL_LIBRARY_SHARED ~ using dynamic library
 */

#ifdef _WIN32
#   if defined( VPL_LIBRARY_SHARED )
#       ifdef VPL_MAKING_IMAGEIO_LIBRARY
#           define VPL_IMAGEIO_EXPORT __declspec(dllexport)
#       else
#           define VPL_IMAGEIO_EXPORT __declspec(dllimport)
#       endif
#   else
#       define VPL_IMAGEIO_EXPORT
#   endif
#else
#   define VPL_IMAGEIO_EXPORT
#endif


#endif // VPL_ImageIOExport_H

