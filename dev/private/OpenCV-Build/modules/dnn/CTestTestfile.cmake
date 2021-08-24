# CMake generated Testfile for 
# Source directory: /home/nlevisrael/sebi-libs/opencv-4.5.0/modules/dnn
# Build directory: /home/nlevisrael/sebi-libs/OpenCV-Build/modules/dnn
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_dnn "/home/nlevisrael/sebi-libs/OpenCV-Build/bin/opencv_test_dnn" "--gtest_output=xml:opencv_test_dnn.xml")
set_tests_properties(opencv_test_dnn PROPERTIES  LABELS "Main;opencv_dnn;Accuracy" WORKING_DIRECTORY "/home/nlevisrael/sebi-libs/OpenCV-Build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVUtils.cmake;1640;add_test;/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVModule.cmake;1310;ocv_add_test_from_target;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/dnn/CMakeLists.txt;168;ocv_add_accuracy_tests;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/dnn/CMakeLists.txt;0;")
add_test(opencv_perf_dnn "/home/nlevisrael/sebi-libs/OpenCV-Build/bin/opencv_perf_dnn" "--gtest_output=xml:opencv_perf_dnn.xml")
set_tests_properties(opencv_perf_dnn PROPERTIES  LABELS "Main;opencv_dnn;Performance" WORKING_DIRECTORY "/home/nlevisrael/sebi-libs/OpenCV-Build/test-reports/performance" _BACKTRACE_TRIPLES "/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVUtils.cmake;1640;add_test;/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVModule.cmake;1212;ocv_add_test_from_target;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/dnn/CMakeLists.txt;173;ocv_add_perf_tests;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/dnn/CMakeLists.txt;0;")
add_test(opencv_sanity_dnn "/home/nlevisrael/sebi-libs/OpenCV-Build/bin/opencv_perf_dnn" "--gtest_output=xml:opencv_perf_dnn.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
set_tests_properties(opencv_sanity_dnn PROPERTIES  LABELS "Main;opencv_dnn;Sanity" WORKING_DIRECTORY "/home/nlevisrael/sebi-libs/OpenCV-Build/test-reports/sanity" _BACKTRACE_TRIPLES "/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVUtils.cmake;1640;add_test;/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVModule.cmake;1213;ocv_add_test_from_target;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/dnn/CMakeLists.txt;173;ocv_add_perf_tests;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/dnn/CMakeLists.txt;0;")
