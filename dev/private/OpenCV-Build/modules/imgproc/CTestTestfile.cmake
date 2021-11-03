# CMake generated Testfile for 
# Source directory: /home/nlevisrael/sebi-libs/opencv-4.5.0/modules/imgproc
# Build directory: /home/nlevisrael/sebi-libs/OpenCV-Build/modules/imgproc
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_imgproc "/home/nlevisrael/sebi-libs/OpenCV-Build/bin/opencv_test_imgproc" "--gtest_output=xml:opencv_test_imgproc.xml")
set_tests_properties(opencv_test_imgproc PROPERTIES  LABELS "Main;opencv_imgproc;Accuracy" WORKING_DIRECTORY "/home/nlevisrael/sebi-libs/OpenCV-Build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVUtils.cmake;1640;add_test;/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVModule.cmake;1310;ocv_add_test_from_target;/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVModule.cmake;1074;ocv_add_accuracy_tests;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/imgproc/CMakeLists.txt;13;ocv_define_module;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/imgproc/CMakeLists.txt;0;")
add_test(opencv_perf_imgproc "/home/nlevisrael/sebi-libs/OpenCV-Build/bin/opencv_perf_imgproc" "--gtest_output=xml:opencv_perf_imgproc.xml")
set_tests_properties(opencv_perf_imgproc PROPERTIES  LABELS "Main;opencv_imgproc;Performance" WORKING_DIRECTORY "/home/nlevisrael/sebi-libs/OpenCV-Build/test-reports/performance" _BACKTRACE_TRIPLES "/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVUtils.cmake;1640;add_test;/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVModule.cmake;1212;ocv_add_test_from_target;/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVModule.cmake;1075;ocv_add_perf_tests;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/imgproc/CMakeLists.txt;13;ocv_define_module;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/imgproc/CMakeLists.txt;0;")
add_test(opencv_sanity_imgproc "/home/nlevisrael/sebi-libs/OpenCV-Build/bin/opencv_perf_imgproc" "--gtest_output=xml:opencv_perf_imgproc.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
set_tests_properties(opencv_sanity_imgproc PROPERTIES  LABELS "Main;opencv_imgproc;Sanity" WORKING_DIRECTORY "/home/nlevisrael/sebi-libs/OpenCV-Build/test-reports/sanity" _BACKTRACE_TRIPLES "/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVUtils.cmake;1640;add_test;/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVModule.cmake;1213;ocv_add_test_from_target;/home/nlevisrael/sebi-libs/opencv-4.5.0/cmake/OpenCVModule.cmake;1075;ocv_add_perf_tests;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/imgproc/CMakeLists.txt;13;ocv_define_module;/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/imgproc/CMakeLists.txt;0;")