#################################################################################
# This file is part of
#
# VPL - Voxel Processing Library
# Copyright 2014 3Dim Laboratory s.r.o.
# All rights reserved.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
################################################################################


if(GTEST_FOUND OR AddGTest_FOUND)
    VPL_LIBRARY( Test )

    # Making library...
    ADD_DEFINITIONS( -DVPL_MAKING_GTEST_LIBRARY )

    VPL_LIBRARY_SOURCE_DIR( ${CMAKE_CURRENT_SOURCE_DIR} )
    VPL_LIBRARY_INCLUDE_DIR( ${VPL_SOURCE_DIR}/include/VPL/Test )
    INCLUDE_DIRECTORIES(${RAPIDJSON_INCLUDE_DIR})

    if(VPL_GTESTS_PREBUILTS)
        include_directories(${GTEST_INCLUDE_DIRS})
    endif()


    #source_group( Algorithm REGULAR_EXPRESSION ".*/Algorithm/.*h" )

    VPL_LIBRARY_BUILD()
    
    
    

    if(VPL_GTESTS_PREBUILTS)
        target_link_libraries(${VPL_LIBRARY_NAME} ${GTEST_BOTH_LIBRARIES})
    else()
        link_directories(${GTEST_DIRECTORY_LIBS})
        target_link_libraries( ${VPL_LIBRARY_NAME} 
        debug ${GTEST_DEBUG_LIBRARIES}
        optimized ${GTEST_RELEASE_LIBRARIES}
    )
    add_dependencies( ${VPL_LIBRARY_NAME}   gtest )
    endif()
	
	source_group( Compare REGULAR_EXPRESSION ".*/Compare/.*h" )
	source_group( Accessor REGULAR_EXPRESSION ".*/Accessor/.*h" )
	source_group( Utillities REGULAR_EXPRESSION ".*/Utillities/.*h" )

    VPL_LIBRARY_INSTALL()
endif()

