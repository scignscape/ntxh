#===============================================================================
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2007 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Date:    2007/08/25
#
# $Id: CMakeLists.txt 2122 2012-02-21 17:45:36Z spanel $
#
# Description:
# - Configuration file for the CMake build system.

# Enable TryEnterCriticalSection() and other functions on Windows
IF( WIN32 )
  ADD_DEFINITIONS( -D_WIN32_WINNT=0x0400 )
ENDIF( WIN32 )

MDSTk_LIBRARY( System )

# Making library...
ADD_DEFINITIONS( -DMDS_MAKING_SYSTEM_LIBRARY )

MDSTk_LIBRARY_SOURCE( mdsCondition.cpp )
MDSTk_LIBRARY_SOURCE( mdsCriticalSection.cpp )
MDSTk_LIBRARY_SOURCE( mdsEvent.cpp )
MDSTk_LIBRARY_SOURCE( mdsExitHandler.cpp )
MDSTk_LIBRARY_SOURCE( mdsFileBrowser.cpp )
MDSTk_LIBRARY_SOURCE( mdsMutex.cpp )
MDSTk_LIBRARY_SOURCE( mdsNamedPipe.cpp )
MDSTk_LIBRARY_SOURCE( mdsSemaphore.cpp )
MDSTk_LIBRARY_SOURCE( mdsSharedMem.cpp )
MDSTk_LIBRARY_SOURCE( mdsSleep.cpp )
MDSTk_LIBRARY_SOURCE( mdsStopwatch.cpp )
MDSTk_LIBRARY_SOURCE( mdsString.cpp )
MDSTk_LIBRARY_SOURCE( mdsThread.cpp )
MDSTk_LIBRARY_SOURCE( mdsTimer.cpp )
MDSTk_LIBRARY_SOURCE( mdsTimestamp.cpp )
MDSTk_LIBRARY_SOURCE( mdsUserThread.cpp )

MDSTk_LIBRARY_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/include/MDSTk/System )

MDSTk_LIBRARY_BUILD()

MDSTk_LIBRARY_DEP( mdsBase )

MDSTk_LIBRARY_INSTALL()

