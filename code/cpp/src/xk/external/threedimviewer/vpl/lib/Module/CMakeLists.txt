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

VPL_LIBRARY( Module )

# Making library...
ADD_DEFINITIONS( -DVPL_MAKING_MODULE_LIBRARY )

VPL_LIBRARY_SOURCE( Argv.cpp )
VPL_LIBRARY_SOURCE( BinarySerializer.cpp )
VPL_LIBRARY_SOURCE( BlockChannel.cpp )
VPL_LIBRARY_SOURCE( Compressor.cpp )
VPL_LIBRARY_SOURCE( Console.cpp )
VPL_LIBRARY_SOURCE( DensityCompressor.cpp )
VPL_LIBRARY_SOURCE( GZipCompressor.cpp )
VPL_LIBRARY_SOURCE( Channel.cpp )
VPL_LIBRARY_SOURCE( MemoryChannel.cpp )
VPL_LIBRARY_SOURCE( Module.cpp )
VPL_LIBRARY_SOURCE( Predictor.cpp )
VPL_LIBRARY_SOURCE( RLECompressor.cpp )
VPL_LIBRARY_SOURCE( SHMSerializer.cpp )
VPL_LIBRARY_SOURCE( StreamChannel.cpp )
VPL_LIBRARY_SOURCE( View.cpp )
VPL_LIBRARY_SOURCE( XMLSerializer.cpp )

VPL_LIBRARY_INCLUDE_DIR( ${VPL_SOURCE_DIR}/include/VPL/Module )

VPL_LIBRARY_BUILD()

VPL_LIBRARY_DEP( vplSystem vplBase )

VPL_LIBRARY_INSTALL()

