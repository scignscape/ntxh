#===============================================================================
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2008 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Date:    2008/12/19
#
# $Id: CMakeLists.txt 1707 2010-05-05 11:00:46Z spanel $
#
# Description:
# - Configuration file for the CMake build system.

MDSTk_MODULE( SliceAffineTransform )

MDSTk_MODULE_SOURCE( mdsSliceAffineTransform.cpp )

MDSTk_MODULE_LIBRARY_APPEND( ${MDSTk_ZLIB} )

MDSTk_MODULE_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/src/modules/SliceAffineTransform )

MDSTk_MODULE_BUILD()

MDSTk_MODULE_INSTALL()
