### CMakeLists.txt ---
##
## Author: Julien Wintz
## Copyright (C) 2008 - Julien Wintz, Inria.
## Created: Mon Mar 14 18:26:38 2011 (+0100)
## Version: $Id$
## Last-Updated: Mon Dec 17 18:09:23 2012 (+0100)
##           By: Julien Wintz
##     Update #: 49
######################################################################
##
### Commentary:
##
######################################################################
##
### Change log:
##
######################################################################

project(axlRpc)

cmake_minimum_required(VERSION 2.6)
include(GenerateExportHeader)

######################################################################
# Check libraries dependencies
######################################################################

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR}/CMakeModules/)

IF (NOT DTK_USED)
  find_package(dtk REQUIRED)
  include(${dtk_USE_FILE})
ENDIF (NOT DTK_USED)

set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

####################################################################
## Sources
####################################################################

set(${PROJECT_NAME}_HEADERS
  #axlRpcExport.h
  axlClient.h
  axlService.h
  axlServer.h
)

set(${PROJECT_NAME}_HEADERS_MOC
  axlClient.h
  axlService.h
  axlServer.h
)

set(${PROJECT_NAME}_SOURCES
  axlClient.cpp
  axlService.cpp
  axlServer.cpp
)

## #################################################################
## Wrapping python
## #################################################################

set(${PROJECT_NAME}_SOURCES_WRAP)

if(DTK_BUILD_WRAPPERS AND SWIG_FOUND)

    set(${PROJECT_NAME}_WRAP_DEPENDS ${${PROJECT_NAME}_HEADERS})
    SET(CMAKE_SWIG_FLAGS "")
    include(${SWIG_USE_FILE})

    if(PYTHONLIBS_FOUND AND AXL_WRAP_PYTHON)

    set(wrap_output ${PROJECT_NAME}_wrap_python.cpp)

    add_custom_command(
      OUTPUT ${wrap_output}
      COMMAND ${SWIG_EXECUTABLE}
      ARGS
      "-python"
      "-c++"
      "-module" axlrpc
      "-I${PROJECT_SOURCE_DIR}/.."
      "-I${PROJECT_SOURCE_DIR}/"
      "-I${dtk_SOURCE_DIR}/"
      "-I${dtk_SOURCE_DIR}/src"
      "-I${dtk_SOURCE_DIR}/src/dtkCore"
      "-outdir" ${CMAKE_BINARY_DIR}/modules/
      "-o" ${wrap_output}
      ${PROJECT_SOURCE_DIR}/axlRpc.i
      MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/axlRpc.i
      COMMENT "Wrapping axlRpc.i to python")

    set(${PROJECT_NAME}_SOURCES_WRAP ${${PROJECT_NAME}_SOURCES_WRAP} ${wrap_output})
    add_custom_target(runWrapRpc ALL DEPENDS ${wrap_output})
    #dtk_wrap(${PROJECT_NAME} ${PROJECT_NAME}_SOURCES_WRAP axlrpc python ${PROJECT_SOURCE_DIR}/axlRpc.i ${${PROJECT_NAME}_WRAP_DEPENDS})
  endif(PYTHONLIBS_FOUND AND AXL_WRAP_PYTHON)

endif(DTK_BUILD_WRAPPERS AND SWIG_FOUND)

## #################################################################
## Configure file
## #################################################################

if(DTK_BUILD_WRAPPERS AND SWIG_FOUND)
    if(APPLE)
      add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/modules/_axlrpc.so
        COMMAND ln -s ${CMAKE_BINARY_DIR}/lib/libaxlRpc.dylib ${CMAKE_BINARY_DIR}/modules/_axlrpc.so
        COMMENT "-- Symlinking axlrpc library")

      add_custom_target(runRpc ALL DEPENDS ${CMAKE_BINARY_DIR}/modules/_axlrpc.so)
    endif(APPLE)

    if(UNIX AND NOT APPLE)
      add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/modules/_axlrpc.so
        COMMAND ln -s ${CMAKE_BINARY_DIR}/lib/libaxlRpc.so ${CMAKE_BINARY_DIR}/modules/_axlrpc.so
        COMMENT "-- Symlinking axlrpc library")

      add_custom_target(runRpc ALL DEPENDS ${CMAKE_BINARY_DIR}/modules/_axlrpc.so)
    endif(UNIX AND NOT APPLE)
endif(DTK_BUILD_WRAPPERS AND SWIG_FOUND)


####################################################################
## Build rules
####################################################################


if(NOT MSVC)
  add_definitions(-Wno-write-strings)
  add_definitions(-Wformat=0)
endif(NOT MSVC)

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_SHARED)
add_definitions(-DQT_NO_DEBUG)

if (STATIC)
add_library(${PROJECT_NAME} STATIC
   ${${PROJECT_NAME}_HEADERS}
   ${${PROJECT_NAME}_SOURCES}
   ${${PROJECT_NAME}_SOURCES_MOC}
   ${${PROJECT_NAME}_SOURCES_WRAP})
endif(STATIC)

if (SHARED)
add_library(${PROJECT_NAME} SHARED
   ${${PROJECT_NAME}_HEADERS}
   ${${PROJECT_NAME}_SOURCES}
   ${${PROJECT_NAME}_SOURCES_MOC}
   ${${PROJECT_NAME}_SOURCES_WRAP})
endif(SHARED)

if(DTK_BUILD_VR)
target_link_libraries(${PROJECT_NAME}
  ${QT_LIBRARIES}
  dtkCoreSupport
  dtkGuiSupport
  dtkVrSupport
  axlCore
  axlGui
  ${QT_QTXML_LIBRARY}
  ${QT_QTNETWORK_LIBRARY}
  ${QJSONRPC_LIBRARIES}
)
else(DTK_BUILD_VR)
target_link_libraries(${PROJECT_NAME}
  ${QT_LIBRARIES}
  dtkCoreSupport
  dtkGuiSupport
  axlCore
  axlGui
  ${QT_QTXML_LIBRARY}
  ${QT_QTNETWORK_LIBRARY}
  ${QJSONRPC_LIBRARIES}
)
endif(DTK_BUILD_VR)

if(PYTHONLIBS_FOUND AND AXL_WRAP_PYTHON)
  target_link_libraries(${PROJECT_NAME} ${PYTHON_LIBRARIES})
endif(PYTHONLIBS_FOUND AND AXL_WRAP_PYTHON)

## #################################################################
## Export header file
## #################################################################
add_compiler_export_flags()

generate_export_header(${PROJECT_NAME} EXPORT_FILE_NAME "${PROJECT_NAME}Export.h")

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different "${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Export.h" "${CMAKE_BINARY_DIR}"
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different "${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Export.h" "${CMAKE_BINARY_DIR}/${PROJECT_NAME}Export")

#add_custom_command (OUTPUT ${CMAKE_BINARY_DIR}/${PROJECT_NAME}Export
#      COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different "${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Export.h" "${CMAKE_BINARY_DIR}/${PROJECT_NAME}Export"
#      DEPENDS ${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Export.h
#      WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

#add_custom_command (OUTPUT ${CMAKE_BINARY_DIR}/${PROJECT_NAME}Export.h
#      COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different "${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Export.h" "${CMAKE_BINARY_DIR}/${PROJECT_NAME}Export.h"
#      DEPENDS ${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Export.h
#      WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

#add_custom_target (${PROJECT_NAME}_Export ALL
#                   DEPENDS
#                     ${CMAKE_BINARY_DIR}/${PROJECT_NAME}Export
#                     ${CMAKE_BINARY_DIR}/${PROJECT_NAME}Export.h
#                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#                   COMMENT  "Export headers for ${PROJECT_NAME}")

include_directories("${${PROJECT_NAME}_BINARY_DIR}")

set(${PROJECT_NAME}_HEADERS
  ${${PROJECT_NAME}_HEADERS}
 "${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Export.h")

## #################################################################
## Handling of generated script modules
## #################################################################

set(${PROJECT_NAME}_MODULES)

if(DTK_BUILD_WRAPPERS AND SWIG_FOUND)

    if(PYTHONLIBS_FOUND AND AXL_WRAP_PYTHON)

    if(WIN32)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        DEPENDS ${PROJECT_SOURCE_DIR}/axlRpc.i
        COMMAND ${CMAKE_COMMAND} ARGS -E make_directory ${CMAKE_BINARY_DIR}/modules
        COMMAND ${CMAKE_COMMAND} ARGS -E copy  ${CMAKE_BINARY_DIR}/bin/libaxlRpc.dll ${CMAKE_BINARY_DIR}/modules//_axlrpc.pyd
        COMMENT "-- Windows: Moving python modules to ${CMAKE_BINARY_DIR}/modules")
        set(${PROJECT_NAME}_MODULES ${CMAKE_BINARY_DIR}/modules/axlrpc.py ${CMAKE_BINARY_DIR}/modules/_axlrpc.pyd)
    endif(WIN32)

    if(UNIX OR APPLE)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        DEPENDS ${PROJECT_SOURCE_DIR}/axlRpc.i
        COMMAND ${CMAKE_COMMAND} ARGS -E make_directory ${CMAKE_BINARY_DIR}/modules
        #COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different ${${PROJECT_NAME}_BINARY_DIR}/axlrpc.py ${CMAKE_BINARY_DIR}/modules
        COMMENT "-- Linux or Apple: Moving python modules to ${CMAKE_BINARY_DIR}/modules")
        set(${PROJECT_NAME}_MODULES ${CMAKE_BINARY_DIR}/modules/axlrpc.py)
        endif(UNIX OR APPLE)
    endif(PYTHONLIBS_FOUND AND AXL_WRAP_PYTHON)

endif(DTK_BUILD_WRAPPERS AND SWIG_FOUND)

####################################################################
## Installation
####################################################################

if(AXL_INSTALL_SDK)
install(FILES ${${PROJECT_NAME}_HEADERS} DESTINATION include/${PROJECT_NAME})
install(FILES ${${PROJECT_NAME}_MODULES} DESTINATION modules)
install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
endif(AXL_INSTALL_SDK)
