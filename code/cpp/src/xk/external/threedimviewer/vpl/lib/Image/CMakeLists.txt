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

VPL_LIBRARY( Image )

# Making library...
ADD_DEFINITIONS( -DVPL_MAKING_IMAGE_LIBRARY )

VPL_LIBRARY_SOURCE( DensityVolume.cpp )
VPL_LIBRARY_SOURCE( Kernel.cpp )
VPL_LIBRARY_SOURCE( Kernels.cpp )
VPL_LIBRARY_SOURCE( Slice.cpp )
VPL_LIBRARY_SOURCE( Instantiations.cpp )

VPL_LIBRARY_INCLUDE_DIR( ${VPL_SOURCE_DIR}/include/VPL/Image )

source_group( Algorithm REGULAR_EXPRESSION ".*/Algorithm/.*h" )
source_group( CornerDetection REGULAR_EXPRESSION ".*/CornerDetection/.*h" )
source_group( EdgeDetection REGULAR_EXPRESSION ".*/EdgeDetection/.*h" )
source_group( FeatureExtraction REGULAR_EXPRESSION ".*/FeatureExtraction/.*h" )
source_group( Filters REGULAR_EXPRESSION ".*/Filters/.*h" )
source_group( GeometricTransform REGULAR_EXPRESSION ".*/GeometricTransform/.*h" )
source_group( HistogramThresholding REGULAR_EXPRESSION ".*/HistogramThresholding/.*h" )
source_group( ImageFunctions REGULAR_EXPRESSION ".*/ImageFunctions/.*h" )
source_group( LandmarkDetection REGULAR_EXPRESSION ".*/LandmarkDetection/.*h" )
source_group( LBP REGULAR_EXPRESSION ".*/LBP/.*h" )
source_group( OpticalFlow REGULAR_EXPRESSION ".*/OpticalFlow/.*h" )
source_group( Utilities REGULAR_EXPRESSION ".*/Utilities/.*h" )
source_group( VolumeEdgeDetection REGULAR_EXPRESSION ".*/VolumeEdgeDetection/.*h" )
source_group( VolumeFilters REGULAR_EXPRESSION ".*/VolumeFilters/.*h" )
source_group( VolumeFunctions REGULAR_EXPRESSION ".*/VolumeFunctions/.*h" )
source_group( Watersheds REGULAR_EXPRESSION ".*/Watersheds/.*h" )

VPL_LIBRARY_BUILD()

VPL_LIBRARY_DEP( vplModule vplSystem vplBase )

VPL_LIBRARY_INSTALL()

