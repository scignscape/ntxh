#==============================================================================
# This file is part of
#
# VPL - Voxel Processing Library
# Copyright 2017 3Dim Laboratory s.r.o.
# All rights reserved.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
#
#==============================================================================

  
VPL_MODULE( PythonImage )

VPL_MODULE_SOURCE( PythonImage.cpp )

VPL_MODULE_LIBRARY_APPEND( ${VPL_PNG} )
VPL_MODULE_LIBRARY_APPEND( ${VPL_ZLIB} )
VPL_MODULE_LIBRARY_APPEND( ${VPL_PYTHON} )
VPL_MODULE_LIBRARY_APPEND( ${PYTHONCPP_INTEROP_LINKED_LIBS} )




VPL_MODULE_INCLUDE_DIR( ${VPL_SOURCE_DIR}/src/modules/PythonImage )

VPL_MODULE_BUILD()

VPL_MODULE_INSTALL()
target_compile_options(${VPL_PROJECT_NAME}  PRIVATE -DSWIG_TYPE_TABLE=TRIDIM)
