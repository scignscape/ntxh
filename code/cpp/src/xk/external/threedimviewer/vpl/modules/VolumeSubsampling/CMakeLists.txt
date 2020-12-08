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
# Copyright (c) 2008 by PGMed@FIT
#
# Authors: Radek Barton, ibarton@fit.vutbr.cz
# Section: VolumeSubsampling
# Date:    2008/10/27
#
# Description:
# - Configuration file for the CMake build system.

VPL_MODULE( VolumeSubsampling )

VPL_MODULE_SOURCE( VolumeSubsampling.cpp )

VPL_MODULE_LIBRARY_APPEND( ${VPL_ZLIB} )

VPL_MODULE_INCLUDE_DIR( ${VPL_SOURCE_DIR}/src/modules/VolumeSubsampling )

VPL_MODULE_BUILD()

VPL_MODULE_INSTALL()
