#===============================================================================
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2007 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Date:    2007/08/25
#
# $Id: CMakeLists.txt 1863 2010-08-31 20:40:15Z spanel $
#
# Description:
# - Configuration file for the CMake build system.

MDSTk_LIBRARY( Math )

# Making library...
ADD_DEFINITIONS( -DMDS_MAKING_MATH_LIBRARY )

MDSTk_LIBRARY_SOURCE( mdsBase.cpp )
MDSTk_LIBRARY_SOURCE( mdsInstantiations.cpp )

MDSTk_LIBRARY_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/include/MDSTk/Math )

source_group( Algorithm REGULAR_EXPRESSION ".*/Algorithm/.*h" )
source_group( MatrixFunctions REGULAR_EXPRESSION ".*/MatrixFunctions/.*h" )
source_group( VectorFunctions REGULAR_EXPRESSION ".*/VectorFunctions/.*h" )
source_group( ver1 REGULAR_EXPRESSION ".*/ver1/.*h" )

MDSTk_LIBRARY_BUILD()

MDSTk_LIBRARY_DEP( mdsBase )

MDSTk_LIBRARY_INSTALL()

