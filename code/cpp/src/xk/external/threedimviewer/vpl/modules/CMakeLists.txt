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
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2007-2010 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Date:    2007/08/25
#==============================================================================

# Build modules
IF( BUILD_MODULES )

  # Prefix added before name of a module
  SET( VPL_MODULE_PREFIX "vpl" CACHE INTERNAL "Module name prefix." )

  # System libraries necessary for building VPL binaries
  if ( WIN32 )
    set( VPL_SYSTEM_LIBS winmm kernel32 )
  else()
    if( APPLE )
      set( VPL_SYSTEM_LIBS pthread )
    else()
      if( UNIX )
        set( VPL_SYSTEM_LIBS pthread rt )
      else( UNIX )
        message( FATAL_ERROR "Unknown target system!" )
      endif()
    endif()
  endif()
           
  # VPL libraries
  set( VPL_LIBS ${VPL_IMAGEIO_LIB} ${VPL_IMAGE_LIB} ${VPL_MODULE_LIB} ${VPL_SYSTEM_LIB} ${VPL_MATH_LIB} ${VPL_BASE_LIB} )
    
    # TinyXML enabled
  if( VPL_XML_ENABLED AND TINYXML_FOUND )
    INCLUDE_DIRECTORIES(${TINYXML_INCLUDE_DIR})
    LINK_DIRECTORIES(${TINYXML_LIBRARIES_DIR})
  endif( VPL_XML_ENABLED AND TINYXML_FOUND)


  # Macro used for declaring a module
  MACRO( VPL_MODULE _MODULE_NAME )
    SET( VPL_MODULE_NAME ${VPL_MODULE_PREFIX}${_MODULE_NAME} )
    SET( VPL_PROJECT_NAME ${VPL_MODULE_PREFIX}${_MODULE_NAME} )
    SET( VPL_MODULE_SOURCES "" )
    SET( VPL_MODULE_HEADERS "" )
    SET( VPL_MODULE_LIBS_PREPEND "" )
    SET( VPL_MODULE_LIBS_APPEND "" )
  ENDMACRO( VPL_MODULE )

  # Macro for adding source file to module build
  MACRO( VPL_MODULE_SOURCE )
    SET( VPL_MODULE_SOURCES ${VPL_MODULE_SOURCES} ${ARGV} )
  ENDMACRO( VPL_MODULE_SOURCE )

  # Macro for adding header file to module
  MACRO( VPL_MODULE_HEADER )
    SET( VPL_MODULE_HEADERS ${VPL_MODULE_HEADERS} ${ARGV} )
  ENDMACRO( VPL_MODULE_HEADER )

  # Macro for adding all header files in a specified directory
  MACRO( VPL_MODULE_INCLUDE_DIR _DIR )
    FILE( GLOB_RECURSE VPL_MODULE_HEADERS ${_DIR}/*.h ${_DIR}/*.hxx )
  ENDMACRO( VPL_MODULE_INCLUDE_DIR )

  # Macro for appending additional library to module build
  MACRO( VPL_MODULE_LIBRARY_APPEND )
    SET( VPL_MODULE_LIBS_APPEND ${VPL_MODULE_LIBS_APPEND} ${ARGV} )
  ENDMACRO( VPL_MODULE_LIBRARY_APPEND )

  # Macro for prepending additional library to module build
  MACRO( VPL_MODULE_LIBRARY_PREPEND )
    SET( VPL_MODULE_LIBS_PREPEND ${ARGV} ${VPL_MODULE_LIBS_PREPEND} )
  ENDMACRO( VPL_MODULE_LIBRARY_PREPEND )

  # Building macro
  MACRO( VPL_MODULE_BUILD )
    ADD_EXECUTABLE( ${VPL_MODULE_NAME}
                    ${VPL_MODULE_SOURCES}
                    ${VPL_MODULE_HEADERS} )
    TARGET_LINK_LIBRARIES( ${VPL_MODULE_NAME}
                           ${VPL_MODULE_LIBS_PREPEND}
                           ${VPL_LIBS}
                           ${VPL_SYSTEM_LIBS}
                           ${VPL_MODULE_LIBS_APPEND}
                            ${TINYXML_LIBRARIES}                           
                         )
    SET_TARGET_PROPERTIES( ${VPL_MODULE_NAME}
                           PROPERTIES LINKER_LANGUAGE CXX
                           DEBUG_POSTFIX d
                           LINK_FLAGS "${VPL_LINK_FLAGS}"
                           )
  ENDMACRO( VPL_MODULE_BUILD )

  # Install macro
  MACRO( VPL_MODULE_INSTALL )
    INSTALL( TARGETS ${VPL_MODULE_NAME}
             RUNTIME DESTINATION bin )
	if(VPL_PNG_ENABLED)		 
		INSTALL(FILES  ${VPL_3RDPARTY_DIR}/bin/libpng16.dll DESTINATION bin)
		INSTALL(FILES  ${VPL_3RDPARTY_DIR}/bin/zlib.dll DESTINATION bin)
	endif()
  ENDMACRO( VPL_MODULE_INSTALL )


  # Build all modules
  ADD_SUBDIRECTORY( CreateSHM )
  ADD_SUBDIRECTORY( LoadDicom )
  ADD_SUBDIRECTORY( LoadDicomDir )
  ADD_SUBDIRECTORY( LoadJPEG )
  ADD_SUBDIRECTORY( LoadJPEGDir )
  ADD_SUBDIRECTORY( LoadPNG )
  ADD_SUBDIRECTORY( LoadPNGDir )
  ADD_SUBDIRECTORY( MakeVolume )
  ADD_SUBDIRECTORY( RGBImage2Slice )
  ADD_SUBDIRECTORY( RGBImageView )
  ADD_SUBDIRECTORY( SaveJPEG )
  ADD_SUBDIRECTORY( SaveJPEGDir )
  ADD_SUBDIRECTORY( SavePNG )
  ADD_SUBDIRECTORY( SavePNGDir )
  ADD_SUBDIRECTORY( SliceAffineTransform )
  ADD_SUBDIRECTORY( SliceBlending )
  ADD_SUBDIRECTORY( SliceCornerDetector )
  ADD_SUBDIRECTORY( SliceCut )
  ADD_SUBDIRECTORY( SliceEdgeDetector )
  ADD_SUBDIRECTORY( SliceFFT )
  ADD_SUBDIRECTORY( SliceFilter )
  ADD_SUBDIRECTORY( SliceHistEqualization )
  ADD_SUBDIRECTORY( SliceHistogram )
  ADD_SUBDIRECTORY( SliceInfo )
  ADD_SUBDIRECTORY( SliceLBPCompare )
  ADD_SUBDIRECTORY( SliceLBPExtract )
  ADD_SUBDIRECTORY( SliceLBPHistogram )
  ADD_SUBDIRECTORY( SliceOpticalFlow )
  ADD_SUBDIRECTORY( SliceRange )
  ADD_SUBDIRECTORY( SliceSeg )
  ADD_SUBDIRECTORY( SliceSegEM )
  ADD_SUBDIRECTORY( SliceSegFCM )
  ADD_SUBDIRECTORY( SliceSegHT )
  ADD_SUBDIRECTORY( SliceSegRG )
  ADD_SUBDIRECTORY( SliceSegWatersheds )
  ADD_SUBDIRECTORY( SliceSubsampling )
  ADD_SUBDIRECTORY( SliceThresholding )
  ADD_SUBDIRECTORY( SliceView )
  ADD_SUBDIRECTORY( VolumeBlending )
  ADD_SUBDIRECTORY( VolumeCut )
  ADD_SUBDIRECTORY( VolumeEdgeDetector )
  ADD_SUBDIRECTORY( VolumeFilter )
  ADD_SUBDIRECTORY( VolumeHistEqualization )
  ADD_SUBDIRECTORY( VolumeHistogram )
  ADD_SUBDIRECTORY( VolumeInfo )
  ADD_SUBDIRECTORY( VolumeLandmarkDetector )
  ADD_SUBDIRECTORY( VolumeRange )
  ADD_SUBDIRECTORY( VolumeSeg )
  ADD_SUBDIRECTORY( VolumeSegHT )
  ADD_SUBDIRECTORY( VolumeSegRG )
  ADD_SUBDIRECTORY( VolumeSegEM )
  ADD_SUBDIRECTORY( VolumeSegFCM )
  ADD_SUBDIRECTORY( VolumeSplit )
  ADD_SUBDIRECTORY( VolumeSubsampling )
  ADD_SUBDIRECTORY( VolumeThresholding )
  ADD_SUBDIRECTORY( VolumeView )
  
  # Python enabled
  if( VPL_PYTHON_ENABLED )
    ADD_SUBDIRECTORY( PythonImage )
  endif( VPL_PYTHON_ENABLED )

ENDIF( BUILD_MODULES )

