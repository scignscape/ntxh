#===============================================================================
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2007 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Section: libSystem
# Date:    2007/08/25
#
# $Id: CMakeLists.txt 1863 2010-08-31 20:40:15Z spanel $
#
# Description:
# - Configuration file for the CMake build system.

IF( BUILD_VECTOR_ENTITY )

  MDSTk_LIBRARY( VectorEntity )

  # Making library...
  ADD_DEFINITIONS( -DMDS_MAKING_VCTL_LIBRARY )

  MDSTk_LIBRARY_SOURCE( mcedge.cpp )
  MDSTk_LIBRARY_SOURCE( mcedges.cpp )
  MDSTk_LIBRARY_SOURCE( mcentity.cpp )
  MDSTk_LIBRARY_SOURCE( mcplane.cpp )
  MDSTk_LIBRARY_SOURCE( mcsphere.cpp )
  MDSTk_LIBRARY_SOURCE( mctetra.cpp )
  MDSTk_LIBRARY_SOURCE( mctetras.cpp )
  MDSTk_LIBRARY_SOURCE( mctri.cpp )
  MDSTk_LIBRARY_SOURCE( mctris.cpp )
  MDSTk_LIBRARY_SOURCE( mcvertex.cpp )
  MDSTk_LIBRARY_SOURCE( mcvertices.cpp )
  MDSTk_LIBRARY_SOURCE( mctransformmatrix.cpp )

  MDSTk_LIBRARY_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/include/VectorEntity )

  MDSTk_LIBRARY_BUILD()

  MDSTk_LIBRARY_DEP( mdsSystem mdsBase )

  MDSTk_LIBRARY_INSTALL()

ENDIF( BUILD_VECTOR_ENTITY )

