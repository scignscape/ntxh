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

MDSTk_LIBRARY( Module )

# Making library...
ADD_DEFINITIONS( -DMDS_MAKING_MODULE_LIBRARY )

MDSTk_LIBRARY_SOURCE( mdsArgv.cpp )
MDSTk_LIBRARY_SOURCE( mdsBinarySerializer.cpp )
MDSTk_LIBRARY_SOURCE( mdsBlockChannel.cpp )
MDSTk_LIBRARY_SOURCE( mdsCompressor.cpp )
MDSTk_LIBRARY_SOURCE( mdsConsole.cpp )
MDSTk_LIBRARY_SOURCE( mdsDensityCompressor.cpp )
MDSTk_LIBRARY_SOURCE( mdsGZipCompressor.cpp )
MDSTk_LIBRARY_SOURCE( mdsChannel.cpp )
MDSTk_LIBRARY_SOURCE( mdsMemoryChannel.cpp )
MDSTk_LIBRARY_SOURCE( mdsModule.cpp )
MDSTk_LIBRARY_SOURCE( mdsPredictor.cpp )
MDSTk_LIBRARY_SOURCE( mdsRLECompressor.cpp )
MDSTk_LIBRARY_SOURCE( mdsSHMSerializer.cpp )
MDSTk_LIBRARY_SOURCE( mdsStreamChannel.cpp )
MDSTk_LIBRARY_SOURCE( mdsView.cpp )
MDSTk_LIBRARY_SOURCE( mdsXMLSerializer.cpp )

MDSTk_LIBRARY_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/include/MDSTk/Module )

MDSTk_LIBRARY_BUILD()

MDSTk_LIBRARY_DEP( mdsSystem mdsBase )

MDSTk_LIBRARY_INSTALL()

