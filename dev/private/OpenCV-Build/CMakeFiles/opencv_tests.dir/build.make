# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/nlevisrael/sebi-libs/cmake-3.19.1-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/nlevisrael/sebi-libs/cmake-3.19.1-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nlevisrael/sebi-libs/opencv-4.5.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nlevisrael/sebi-libs/OpenCV-Build

# Utility rule file for opencv_tests.

# Include the progress variables for this target.
include CMakeFiles/opencv_tests.dir/progress.make

opencv_tests: CMakeFiles/opencv_tests.dir/build.make

.PHONY : opencv_tests

# Rule to build all files generated by this target.
CMakeFiles/opencv_tests.dir/build: opencv_tests

.PHONY : CMakeFiles/opencv_tests.dir/build

CMakeFiles/opencv_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opencv_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opencv_tests.dir/clean

CMakeFiles/opencv_tests.dir/depend:
	cd /home/nlevisrael/sebi-libs/OpenCV-Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nlevisrael/sebi-libs/opencv-4.5.0 /home/nlevisrael/sebi-libs/opencv-4.5.0 /home/nlevisrael/sebi-libs/OpenCV-Build /home/nlevisrael/sebi-libs/OpenCV-Build /home/nlevisrael/sebi-libs/OpenCV-Build/CMakeFiles/opencv_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opencv_tests.dir/depend

