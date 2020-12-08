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

IF( MDS_FFTW_ENABLED )

  MDSTk_MODULE( SliceFFT )

  MDSTk_MODULE_SOURCE( mdsSliceFFT.cpp )

  MDSTk_MODULE_LIBRARY_APPEND( ${MDSTk_FFTW} )
  MDSTk_MODULE_LIBRARY_APPEND( ${MDSTk_ZLIB} )

  MDSTk_MODULE_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/src/modules/SliceFFT )

  MDSTk_MODULE_BUILD()

  MDSTk_MODULE_INSTALL()

ENDIF( MDS_FFTW_ENABLED )
