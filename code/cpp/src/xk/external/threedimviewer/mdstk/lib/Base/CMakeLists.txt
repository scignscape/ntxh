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

MDSTk_LIBRARY( Base )

# Making library...
ADD_DEFINITIONS( -DMDS_MAKING_BASE_LIBRARY )

MDSTk_LIBRARY_SOURCE( mdsError.cpp )
MDSTk_LIBRARY_SOURCE( mdsFullException.cpp )
MDSTk_LIBRARY_SOURCE( mdsIdentifier.cpp )
MDSTk_LIBRARY_SOURCE( mdsLog.cpp )
MDSTk_LIBRARY_SOURCE( mdsLogChannel.cpp )
MDSTk_LIBRARY_SOURCE( mdsSingleton.cpp )
MDSTk_LIBRARY_SOURCE( mdsSmallObject.cpp )
MDSTk_LIBRARY_SOURCE( mdsWarning.cpp )

MDSTk_LIBRARY_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/include/MDSTk/Base )

MDSTk_LIBRARY_BUILD()

MDSTk_LIBRARY_INSTALL()

