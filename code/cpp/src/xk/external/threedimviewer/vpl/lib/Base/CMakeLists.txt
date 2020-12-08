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

VPL_LIBRARY( Base )

# Making library...
ADD_DEFINITIONS( -DVPL_MAKING_BASE_LIBRARY )

VPL_LIBRARY_SOURCE( Error.cpp )
VPL_LIBRARY_SOURCE( FullException.cpp )
VPL_LIBRARY_SOURCE( Identifier.cpp )
VPL_LIBRARY_SOURCE( LogAppender.cpp )
VPL_LIBRARY_SOURCE( LogFilters.cpp )
VPL_LIBRARY_SOURCE( Logger.cpp )
VPL_LIBRARY_SOURCE( LogChannel.cpp )
VPL_LIBRARY_SOURCE( LogIDEAppender.cpp )
VPL_LIBRARY_SOURCE( LogLayout.cpp )
VPL_LIBRARY_SOURCE( LogRecord.cpp )
VPL_LIBRARY_SOURCE( Setup.cpp )
VPL_LIBRARY_SOURCE( Singleton.cpp )
VPL_LIBRARY_SOURCE( SmallObject.cpp )
VPL_LIBRARY_SOURCE( Warning.cpp )
VPL_LIBRARY_SOURCE( LogAppender.cpp )
VPL_LIBRARY_SOURCE( LogFilters.cpp )
VPL_LIBRARY_SOURCE( Logger.cpp )

VPL_LIBRARY_INCLUDE_DIR( ${VPL_SOURCE_DIR}/include/VPL/Base )

VPL_LIBRARY_BUILD()

VPL_LIBRARY_INSTALL()

