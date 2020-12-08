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
# Copyright (c) 2007 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Date:    2007/08/25
#
# Description:
# - Configuration file for the CMake build system.

VPL_MODULE( LoadDicom )

VPL_MODULE_SOURCE( LoadDicom.cpp )

VPL_MODULE_LIBRARY_APPEND( ${VPL_ZLIB} )

# If VPL should use GDCM, then link necessary GDCM libraries 
if( VPL_BUILD_WITH_GDCM )
	VPL_MODULE_LIBRARY_APPEND( ${VPL_GDCM_LIBS} )
endif( VPL_BUILD_WITH_GDCM )

VPL_MODULE_INCLUDE_DIR( ${VPL_SOURCE_DIR}/src/modules/LoadDicom )

VPL_MODULE_BUILD()

VPL_MODULE_INSTALL()

