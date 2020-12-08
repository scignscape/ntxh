#===============================================================================
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2008 by PGMed@FIT
#
# Authors: Radek Barton, ibarton@fit.vutbr.cz
# Section: VolumeSubsampling
# Date:    2008/10/27
#
# $Id: CMakeLists.txt 1707 2010-05-05 11:00:46Z spanel $
#
# Description:
# - Configuration file for the CMake build system.

MDSTk_MODULE( VolumeSubsampling )

MDSTk_MODULE_SOURCE( mdsVolumeSubsampling.cpp )

MDSTk_MODULE_LIBRARY_APPEND( ${MDSTk_ZLIB} )

MDSTk_MODULE_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/src/modules/VolumeSubsampling )

MDSTk_MODULE_BUILD()

MDSTk_MODULE_INSTALL()
