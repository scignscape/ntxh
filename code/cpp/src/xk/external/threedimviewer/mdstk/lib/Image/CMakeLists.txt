#===============================================================================
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2007 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Date:    2007/08/25
#
# $Id: CMakeLists.txt 1865 2010-09-02 12:43:29Z spanel $
#
# Description:
# - Configuration file for the CMake build system.

MDSTk_LIBRARY( Image )

# Making library...
ADD_DEFINITIONS( -DMDS_MAKING_IMAGE_LIBRARY )

MDSTk_LIBRARY_SOURCE( mdsDensityVolume.cpp )
MDSTk_LIBRARY_SOURCE( mdsKernel.cpp )
MDSTk_LIBRARY_SOURCE( mdsKernels.cpp )
MDSTk_LIBRARY_SOURCE( mdsSlice.cpp )
MDSTk_LIBRARY_SOURCE( mdsInstantiations.cpp )

MDSTk_LIBRARY_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/include/MDSTk/Image )

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

MDSTk_LIBRARY_BUILD()

MDSTk_LIBRARY_DEP( mdsModule mdsSystem mdsBase )

MDSTk_LIBRARY_INSTALL()

