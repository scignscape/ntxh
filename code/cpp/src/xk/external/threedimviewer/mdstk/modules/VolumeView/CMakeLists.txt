#===============================================================================
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2007 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Date:    2007/08/25
#
# $Id: CMakeLists.txt 1707 2010-05-05 11:00:46Z spanel $
#
# Description:
# - Configuration file for the CMake build system.

IF( BUILD_OPENGL_MODULES )
  
  MDSTk_MODULE( VolumeView )

  MDSTk_MODULE_SOURCE( mdsVolumeView.cpp )

  MDSTk_MODULE_LIBRARY_APPEND( ${MDSTk_ZLIB} )
  MDSTk_MODULE_LIBRARY_APPEND( ${MDSTk_GLUT} )
  MDSTk_MODULE_LIBRARY_APPEND( ${MDSTk_OPENGL} )

  MDSTk_MODULE_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/src/modules/VolumeView )

  MDSTk_MODULE_BUILD()

  MDSTk_MODULE_INSTALL()

ENDIF( BUILD_OPENGL_MODULES )
