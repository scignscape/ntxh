#===============================================================================
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2007 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Section: libSystem
# Date:    2008/09/26
#
# $Id: CMakeLists.txt 1863 2010-08-31 20:40:15Z spanel $
#
# Description:
# - Configuration file for the CMake build system.

IF( MDS_XML_ENABLED )

  # Build options
  OPTION( TIXML_USE_STL "Should the TinyXML use the STL library?" ON )

  MDSTk_LIBRARY( TinyXML )

  # Making library...
  ADD_DEFINITIONS( -DMDS_MAKING_TINYXML_LIBRARY )

  MDSTk_LIBRARY_SOURCE( tinystr.cpp )
  MDSTk_LIBRARY_SOURCE( tinyxml.cpp )
  MDSTk_LIBRARY_SOURCE( tinyxmlerror.cpp )
  MDSTk_LIBRARY_SOURCE( tinyxmlparser.cpp )

  MDSTk_LIBRARY_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/include/TinyXML )

  MDSTk_LIBRARY_BUILD()

  MDSTk_LIBRARY_INSTALL()

ENDIF( MDS_XML_ENABLED )

