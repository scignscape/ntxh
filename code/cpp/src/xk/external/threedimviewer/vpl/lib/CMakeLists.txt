#==============================================================================
# This file comes from MDSTk software and was modified for
#
# VPL - Voxel Processing Library
# Changes are Copyright 2014 3Dim Laboratory s.r.o.
# All rights reserved.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
#
# The original MDSTk legal notice can be found below.
# 
# Medical Data Segmentation Toolkit (VPL)
# Copyright (c) 2007-2010 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Date:    2007/08/25
#==============================================================================

IF( BUILD_LIBRARIES )

  # Prefix added before name of a library
  SET( VPL_LIBRARY_PREFIX vpl CACHE INTERNAL "Library name prefix." )

  # Library name declaration
  MACRO( VPL_LIBRARY _LIBRARY_NAME )
    SET( VPL_LIBRARY_NAME ${VPL_LIBRARY_PREFIX}${_LIBRARY_NAME}${VPL_LIBRARY_SUFFIX} )
    SET( VPL_PROJECT_NAME lib${_LIBRARY_NAME} )
    SET( VPL_LIBRARY_SOURCES "" )
    SET( VPL_LIBRARY_HEADERS "" )
  ENDMACRO( VPL_LIBRARY )

  # Macro for adding source file to library build
  MACRO( VPL_LIBRARY_SOURCE )
    SET( VPL_LIBRARY_SOURCES ${VPL_LIBRARY_SOURCES} ${ARGV} )
  ENDMACRO( VPL_LIBRARY_SOURCE )

  # Macro for adding header file to library
  MACRO( VPL_LIBRARY_HEADER )
    SET( VPL_LIBRARY_HEADERS ${VPL_LIBRARY_HEADERS} ${ARGV} )
  ENDMACRO( VPL_LIBRARY_HEADER )

  # Macro for adding all header files in a specified directory to library
  MACRO( VPL_LIBRARY_INCLUDE_DIR _DIR )
    FILE( GLOB_RECURSE VPL_LIBRARY_HEADERS ${_DIR}/*.h ${_DIR}/*.hxx ${_DIR}/*.hpp)
  ENDMACRO( VPL_LIBRARY_INCLUDE_DIR )

  # Macro for adding all header files in a specified directory to library
  MACRO( VPL_LIBRARY_SOURCE_DIR _DIR )
    FILE( GLOB_RECURSE VPL_LIBRARY_SOURCES ${_DIR}/*.cpp ${_DIR}/*.c )
  ENDMACRO( VPL_LIBRARY_SOURCE_DIR )

  # Final building macro
  MACRO( VPL_LIBRARY_BUILD )
    ADD_LIBRARY( ${VPL_LIBRARY_NAME}
                 ${VPL_LIBRARY_SOURCES}
                 ${VPL_LIBRARY_HEADERS} )
    SET_TARGET_PROPERTIES( ${VPL_LIBRARY_NAME} PROPERTIES
                           PROJECT_LABEL ${VPL_PROJECT_NAME}
                           DEBUG_POSTFIX d
                           LINK_FLAGS "${VPL_LINK_FLAGS}"
                           )
#    TARGET_LINK_LIBRARIES( ${VPL_LIBRARY_NAME} ... )
  ENDMACRO( VPL_LIBRARY_BUILD )

  # Adding dependencies
  MACRO( VPL_LIBRARY_DEP _NAME )
    TARGET_LINK_LIBRARIES( ${VPL_LIBRARY_NAME} ${_NAME}${VPL_LIBRARY_SUFFIX} )
  ENDMACRO( VPL_LIBRARY_DEP )

  # Install macro
  MACRO( VPL_LIBRARY_INSTALL )
    INSTALL( TARGETS ${VPL_LIBRARY_NAME}
             RUNTIME DESTINATION bin
             LIBRARY DESTINATION lib
             ARCHIVE DESTINATION lib )
    FOREACH( HEADER ${VPL_LIBRARY_HEADERS} )
      FILE( RELATIVE_PATH FILE ${VPL_SOURCE_DIR}/include ${HEADER} )
      GET_FILENAME_COMPONENT( DIR ${FILE} PATH )
      INSTALL( FILES ${HEADER} DESTINATION include/${DIR} )
    ENDFOREACH( HEADER )
  ENDMACRO( VPL_LIBRARY_INSTALL )


  # Build libraries in these directories
  ADD_SUBDIRECTORY( Base )
  ADD_SUBDIRECTORY( Image )
  ADD_SUBDIRECTORY( ImageIO )
  ADD_SUBDIRECTORY( Math )
  ADD_SUBDIRECTORY( Module )
  ADD_SUBDIRECTORY( System )
  
  IF ( BUILD_LIB_TEST )
    ADD_SUBDIRECTORY(Test)
  ENDIF(BUILD_LIB_TEST)

ENDIF( BUILD_LIBRARIES )

