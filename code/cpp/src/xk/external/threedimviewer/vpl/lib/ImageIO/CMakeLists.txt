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
#==============================================================================

VPL_LIBRARY( ImageIO )

# Making library...
ADD_DEFINITIONS( -DVPL_MAKING_IMAGEIO_LIBRARY )

VPL_LIBRARY_SOURCE( DicomSlice.cpp )
VPL_LIBRARY_SOURCE( DicomSliceLoaderVPL.cpp )
VPL_LIBRARY_SOURCE( DicomSliceLoaderGDCM.cpp ) 
VPL_LIBRARY_SOURCE( DicomDirLoader.cpp )


if( VPL_JPEG )
  VPL_LIBRARY_SOURCE( JPEGBaseFunctions.cpp )
endif()

if( VPL_PNG )
  VPL_LIBRARY_SOURCE( PNGBaseFunctions.cpp )
endif()

VPL_LIBRARY_INCLUDE_DIR( ${VPL_SOURCE_DIR}/include/VPL/ImageIO )

VPL_LIBRARY_BUILD()

VPL_LIBRARY_DEP( vplImage vplModule vplSystem vplBase )

VPL_LIBRARY_INSTALL()

