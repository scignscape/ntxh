# CMake generated Testfile for 
# Source directory: /home/nlevisrael/sebi-libs/opencv-4.5.0/modules/flann
# Build directory: /home/nlevisrael/sebi-libs/OpenCV-Build/modules/flann
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_flann "/home/nlevisrael/sebi-libs/OpenCV-Build/bin/opencv_test_flann" "--gtest_output=xml:opencv_test_flann.xml")
set_tests_properties(opencv_test_flann PROPERTIES  LABELS "Main;opencv_flann;Accuracy" WORKING_DIRECTORY "/home/nlevisrael/sebi-libs/OpenCV-Build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVUtils.cmake;1640;add_test;/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVModule.cmake;1310;ocv_add_test_from_target;/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVModule.cmake;1074;ocv_add_accuracy_tests;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/flann/CMakeLists.txt;2;ocv_define_module;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/flann/CMakeLists.txt;0;")
