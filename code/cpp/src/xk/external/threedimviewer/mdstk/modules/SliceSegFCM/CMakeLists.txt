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

MDSTk_MODULE( SliceSegFCM )

MDSTk_MODULE_SOURCE( mdsSliceSegFCM.cpp )

MDSTk_MODULE_LIBRARY_APPEND( ${MDSTk_ZLIB} )

MDSTk_MODULE_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/src/modules/SliceSegFCM )

MDSTk_MODULE_BUILD()

MDSTk_MODULE_INSTALL()

