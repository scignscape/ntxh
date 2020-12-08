#==============================================================================
# This file comes from MDSTk software and was modified for
#
# VPL - Voxel Processing Library
# Changes are Copyright 2014 3Dim Laboratory s.r.o.
# All rights reserved.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
#
# The original MDSTk legal notice can be found below.
# 
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2003-2010 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Date:    2010/11/01
#
# Description:
# - Configuration file for the CMake build system.

if( VPL_JPEG )

  VPL_MODULE( LoadJPEGDir )

  VPL_MODULE_SOURCE( LoadJPEGDir.cpp )

  VPL_MODULE_LIBRARY_APPEND( ${VPL_JPEG} )
  VPL_MODULE_LIBRARY_APPEND( ${VPL_ZLIB} )

  VPL_MODULE_INCLUDE_DIR( ${VPL_SOURCE_DIR}/src/modules/LoadJPEGDir )

  VPL_MODULE_BUILD()

  VPL_MODULE_INSTALL()

endif()
