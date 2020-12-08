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

VPL_LIBRARY( Math )

# Making library...
ADD_DEFINITIONS( -DVPL_MAKING_MATH_LIBRARY )

VPL_LIBRARY_SOURCE( Base.cpp )
VPL_LIBRARY_SOURCE( Instantiations.cpp )

VPL_LIBRARY_INCLUDE_DIR( ${VPL_SOURCE_DIR}/include/VPL/Math )

source_group( Algorithm REGULAR_EXPRESSION ".*/Algorithm/.*h" )
source_group( MatrixFunctions REGULAR_EXPRESSION ".*/MatrixFunctions/.*h" )
source_group( VectorFunctions REGULAR_EXPRESSION ".*/VectorFunctions/.*h" )
source_group( ver1 REGULAR_EXPRESSION ".*/ver1/.*h" )

VPL_LIBRARY_BUILD()

VPL_LIBRARY_DEP( vplBase )

VPL_LIBRARY_INSTALL()

