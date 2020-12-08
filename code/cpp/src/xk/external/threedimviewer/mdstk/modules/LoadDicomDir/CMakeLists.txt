#===============================================================================
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2007-2010 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Date:    2010/11/01
#
# $Id: CMakeLists.txt 1928 2010-11-07 13:11:14Z spanel $
#
# Description:
# - Configuration file for the CMake build system.

MDSTk_MODULE( LoadDicomDir )

MDSTk_MODULE_SOURCE( mdsLoadDicomDir.cpp )

MDSTk_MODULE_LIBRARY_APPEND( ${MDSTk_ZLIB} )

MDSTk_MODULE_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/src/modules/LoadDicomDir )

MDSTk_MODULE_BUILD()

MDSTk_MODULE_INSTALL()

