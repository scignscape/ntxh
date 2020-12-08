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

# Enable TryEnterCriticalSection() and other functions on Windows
IF( WIN32 )
  ADD_DEFINITIONS( -D_WIN32_WINNT=0x0400 )
ENDIF( WIN32 )

VPL_LIBRARY( System )

# Making library...
ADD_DEFINITIONS( -DVPL_MAKING_SYSTEM_LIBRARY )

VPL_LIBRARY_SOURCE( Condition.cpp )
VPL_LIBRARY_SOURCE( ExitHandler.cpp )
VPL_LIBRARY_SOURCE( FileBrowser.cpp )
VPL_LIBRARY_SOURCE( Memory.cpp )
VPL_LIBRARY_SOURCE( Mutex.cpp )
VPL_LIBRARY_SOURCE( NamedPipe.cpp )
VPL_LIBRARY_SOURCE( NamedSemaphore.cpp )
VPL_LIBRARY_SOURCE( SharedMem.cpp )
VPL_LIBRARY_SOURCE( Sleep.cpp )
VPL_LIBRARY_SOURCE( Stopwatch.cpp )
VPL_LIBRARY_SOURCE( String.cpp )
VPL_LIBRARY_SOURCE( Thread.cpp )
VPL_LIBRARY_SOURCE( Timer.cpp )
VPL_LIBRARY_SOURCE( Timestamp.cpp )
VPL_LIBRARY_SOURCE( UserThread.cpp )

VPL_LIBRARY_INCLUDE_DIR( ${VPL_SOURCE_DIR}/include/VPL/System )

VPL_LIBRARY_BUILD()

VPL_LIBRARY_DEP( vplBase )

VPL_LIBRARY_INSTALL()

