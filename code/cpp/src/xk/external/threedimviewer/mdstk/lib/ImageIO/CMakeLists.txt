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

MDSTk_LIBRARY( ImageIO )

# Making library...
ADD_DEFINITIONS( -DMDS_MAKING_IMAGEIO_LIBRARY )

MDSTk_LIBRARY_SOURCE( mdsDicomSlice.cpp )
MDSTk_LIBRARY_SOURCE( mdsJPEGBaseFunctions.cpp )
MDSTk_LIBRARY_SOURCE( mdsPNGBaseFunctions.cpp )

MDSTk_LIBRARY_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/include/MDSTk/ImageIO )

MDSTk_LIBRARY_BUILD()

MDSTk_LIBRARY_DEP( mdsImage mdsModule mdsSystem mdsBase )

MDSTk_LIBRARY_INSTALL()

