#===============================================================================
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2007-2010 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Date:    2007/08/25
#
# $Id: CMakeLists.txt 1863 2010-08-31 20:40:15Z spanel $
#
# Description:
# - Configuration file for the CMake build system.

IF( BUILD_LIBRARIES )

  # Prefix added before name of a library
  SET( MDSTk_LIBRARY_PREFIX mds CACHE INTERNAL "Library name prefix." )

  # Library name declaration
  MACRO( MDSTk_LIBRARY _LIBRARY_NAME )
    SET( MDSTk_LIBRARY_NAME ${MDSTk_LIBRARY_PREFIX}${_LIBRARY_NAME} )
    SET( MDSTk_PROJECT_NAME lib${_LIBRARY_NAME} )
    SET( MDSTk_LIBRARY_SOURCES "" )
    SET( MDSTk_LIBRARY_HEADERS "" )
  ENDMACRO( MDSTk_LIBRARY )

  # Macro for adding source file to library build
  MACRO( MDSTk_LIBRARY_SOURCE )
    SET( MDSTk_LIBRARY_SOURCES ${MDSTk_LIBRARY_SOURCES} ${ARGV} )
  ENDMACRO( MDSTk_LIBRARY_SOURCE )

  # Macro for adding header file to library
  MACRO( MDSTk_LIBRARY_HEADER )
    SET( MDSTk_LIBRARY_HEADERS ${MDSTk_LIBRARY_HEADERS} ${ARGV} )
  ENDMACRO( MDSTk_LIBRARY_HEADER )

  # Macro for adding all header files in a specified directory to library
  MACRO( MDSTk_LIBRARY_INCLUDE_DIR _DIR )
    FILE( GLOB_RECURSE MDSTk_LIBRARY_HEADERS ${_DIR}/*.h ${_DIR}/*.hxx )
  ENDMACRO( MDSTk_LIBRARY_INCLUDE_DIR )

  # Final building macro
  MACRO( MDSTk_LIBRARY_BUILD )
    ADD_LIBRARY( ${MDSTk_LIBRARY_NAME}
                 ${MDSTk_LIBRARY_SOURCES}
                 ${MDSTk_LIBRARY_HEADERS} )
    SET_TARGET_PROPERTIES( ${MDSTk_LIBRARY_NAME} PROPERTIES
                           PROJECT_LABEL ${MDSTk_PROJECT_NAME}
                           DEBUG_POSTFIX d
                           LINK_FLAGS "${MDSTk_LINK_FLAGS}"
                           )
#    TARGET_LINK_LIBRARIES( ${MDSTk_LIBRARY_NAME} ... )
  ENDMACRO( MDSTk_LIBRARY_BUILD )

  # Adding dependencies
  MACRO( MDSTk_LIBRARY_DEP _NAME )
    TARGET_LINK_LIBRARIES( ${MDSTk_LIBRARY_NAME} ${_NAME} )
  ENDMACRO( MDSTk_LIBRARY_DEP )

  # Install macro
  MACRO( MDSTk_LIBRARY_INSTALL )
    INSTALL( TARGETS ${MDSTk_LIBRARY_NAME}
             RUNTIME DESTINATION bin
             LIBRARY DESTINATION lib
             ARCHIVE DESTINATION lib )
    FOREACH( HEADER ${MDSTk_LIBRARY_HEADERS} )
      FILE( RELATIVE_PATH FILE ${MDSTk_SOURCE_DIR}/include ${HEADER} )
      GET_FILENAME_COMPONENT( DIR ${FILE} PATH )
      INSTALL( FILES ${HEADER} DESTINATION include/${DIR} )
    ENDFOREACH( HEADER )
  ENDMACRO( MDSTk_LIBRARY_INSTALL )


  # Build libraries in these directories
  ADD_SUBDIRECTORY( Base )
  ADD_SUBDIRECTORY( Image )
  ADD_SUBDIRECTORY( ImageIO )
  ADD_SUBDIRECTORY( Math )
  ADD_SUBDIRECTORY( Module )
  ADD_SUBDIRECTORY( System )
  ADD_SUBDIRECTORY( VectorEntity )
  ADD_SUBDIRECTORY( TinyXML )
  ADD_SUBDIRECTORY( Eigen )

ENDIF( BUILD_LIBRARIES )

