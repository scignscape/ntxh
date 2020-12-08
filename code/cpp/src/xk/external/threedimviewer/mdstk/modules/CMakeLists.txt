#===============================================================================
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2007-2010 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Date:    2007/08/25
#
# $Id: CMakeLists.txt 1918 2010-11-05 21:46:28Z spanel $
#
# Description:
# - Configuration file for the CMake build system.

# Build modules
IF( BUILD_MODULES )

  # Prefix added before name of a module
  SET( MDSTk_MODULE_PREFIX mds CACHE INTERNAL "Module name prefix." )

  # System libraries necessary for building MDSTk binaries
  IF ( WIN32 )
    SET( MDSTk_SYSTEM_LIBS winmm kernel32 )
  ELSE( WIN32 )
    IF( UNIX )
      SET( MDSTk_SYSTEM_LIBS pthread rt )
    ELSE( UNIX )
      MESSAGE( FATAL_ERROR "Unknown target system!" )
    ENDIF( UNIX )
  ENDIF( WIN32 )

  # MDSTk libraries
  set( MDSTk_LIBS mdsImageIO mdsImage mdsModule mdsSystem mdsMath mdsBase )
  
  # VectorEntity enabled
  if( BUILD_VECTOR_ENTITY )
    list( APPEND MDSTk_LIBS mdsVectorEntity )
  endif( BUILD_VECTOR_ENTITY )
  
  # TinyXML enabled
  if( MDS_XML_ENABLED )
    list( APPEND MDSTk_LIBS mdsTinyXML )
  endif( MDS_XML_ENABLED )


  # Macro used for declaring a module
  MACRO( MDSTk_MODULE _MODULE_NAME )
    SET( MDSTk_MODULE_NAME ${MDSTk_MODULE_PREFIX}${_MODULE_NAME} )
    SET( MDSTk_PROJECT_NAME ${MDSTk_MODULE_PREFIX}${_MODULE_NAME} )
    SET( MDSTk_MODULE_SOURCES "" )
    SET( MDSTk_MODULE_HEADERS "" )
    SET( MDSTk_MODULE_LIBS_PREPEND "" )
    SET( MDSTk_MODULE_LIBS_APPEND "" )
  ENDMACRO( MDSTk_MODULE )

  # Macro for adding source file to module build
  MACRO( MDSTk_MODULE_SOURCE )
    SET( MDSTk_MODULE_SOURCES ${MDSTk_MODULE_SOURCES} ${ARGV} )
  ENDMACRO( MDSTk_MODULE_SOURCE )

  # Macro for adding header file to module
  MACRO( MDSTk_MODULE_HEADER )
    SET( MDSTk_MODULE_HEADERS ${MDSTk_MODULE_HEADERS} ${ARGV} )
  ENDMACRO( MDSTk_MODULE_HEADER )

  # Macro for adding all header files in a specified directory
  MACRO( MDSTk_MODULE_INCLUDE_DIR _DIR )
    FILE( GLOB_RECURSE MDSTk_MODULE_HEADERS ${_DIR}/*.h ${_DIR}/*.hxx )
  ENDMACRO( MDSTk_MODULE_INCLUDE_DIR )

  # Macro for appending additional library to module build
  MACRO( MDSTk_MODULE_LIBRARY_APPEND )
    SET( MDSTk_MODULE_LIBS_APPEND ${MDSTk_MODULE_LIBS_APPEND} ${ARGV} )
  ENDMACRO( MDSTk_MODULE_LIBRARY_APPEND )

  # Macro for prepending additional library to module build
  MACRO( MDSTk_MODULE_LIBRARY_PREPEND )
    SET( MDSTk_MODULE_LIBS_PREPEND ${ARGV} ${MDSTk_MODULE_LIBS_PREPEND} )
  ENDMACRO( MDSTk_MODULE_LIBRARY_PREPEND )

  # Building macro
  MACRO( MDSTk_MODULE_BUILD )
    ADD_EXECUTABLE( ${MDSTk_MODULE_NAME}
                    ${MDSTk_MODULE_SOURCES}
                    ${MDSTk_MODULE_HEADERS} )
    TARGET_LINK_LIBRARIES( ${MDSTk_MODULE_NAME}
                           ${MDSTk_MODULE_LIBS_PREPEND}
                           ${MDSTk_LIBS}
                           ${MDSTk_SYSTEM_LIBS}
                           ${MDSTk_MODULE_LIBS_APPEND} )
    SET_TARGET_PROPERTIES( ${MDSTk_MODULE_NAME}
                           PROPERTIES LINKER_LANGUAGE CXX
                           DEBUG_POSTFIX d
                           LINK_FLAGS "${MDSTk_LINK_FLAGS}"
                           )
  ENDMACRO( MDSTk_MODULE_BUILD )

  # Install macro
  MACRO( MDSTk_MODULE_INSTALL )
    INSTALL( TARGETS ${MDSTk_MODULE_NAME}
             RUNTIME DESTINATION bin )
  ENDMACRO( MDSTk_MODULE_INSTALL )


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

ENDIF( BUILD_MODULES )

