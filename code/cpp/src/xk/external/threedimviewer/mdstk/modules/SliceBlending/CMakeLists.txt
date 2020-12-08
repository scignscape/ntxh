#===============================================================================
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2007 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Date:    2010/09/03
#
# $Id: CMakeLists.txt 1869 2010-09-02 22:54:56Z spanel $
#
# Description:
# - Configuration file for the CMake build system.

MDSTk_MODULE( SliceBlending )

MDSTk_MODULE_SOURCE( mdsSliceBlending.cpp )

MDSTk_MODULE_LIBRARY_APPEND( ${MDSTk_ZLIB} )

MDSTk_MODULE_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/src/modules/SliceBlending )

MDSTk_MODULE_BUILD()

MDSTk_MODULE_INSTALL()

