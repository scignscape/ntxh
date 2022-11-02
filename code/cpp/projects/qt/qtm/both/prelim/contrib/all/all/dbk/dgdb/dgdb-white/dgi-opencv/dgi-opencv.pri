
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT  += core gui widgets


#QMAKE_CC = gcc-7
#QMAKE_CXX = g++-7
#CONFIG += c++17



include($$ROOT_DIR/../preferred/opencv.pri)

include($$ROOT_DIR/../preferred/sysr.pri)


DEFINES += DEFAULT_GTAGML_GEN_FOLDER=\\\"$$ROOT_DIR/../gtagml\\\"

DEFINES += DEFAULT_DEV_DGDB_NGML_FOLDER=\\\"$$ROOT_DIR/../gtagml/dgdb\\\"

DEFINES += DEFAULT_SDI_FOLDER=\\\"$$ROOT_DIR/dev/consoles/gtagml/sdi\\\"

DEFINES += USE_KANS


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR $$WHITEDB_SRC_GROUP_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/dgdb-white

INCLUDEPATH += $$SRC_GROUP_DIR/

INCLUDEPATH += $$SRC_ROOT_DIR/apk/gtagml/gtagml
INCLUDEPATH += $$SRC_ROOT_DIR/apk/hgdm/ntxh
INCLUDEPATH += $$SRC_ROOT_DIR/apk/hgdm/ntxh/ntxh



INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR



INCLUDEPATH += $$OPENCV_SRC_DIR/modules/core/include
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/imgproc/include
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/imgcodecs/include

INCLUDEPATH += $$OPENCV_SRC_DIR/include
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/calib3d/include/
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/features2d/include/
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/flann/include/
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/dnn/include/
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/highgui/include/
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/videoio/include/
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/ml/include/
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/objdetect/include/
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/photo/include/
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/stitching/include/
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/video/include/



INCLUDEPATH += $$OPENCV_BUILD_DIR



#INCLUDEPATH += /home/nlevisrael/sebi-libs/opencv-4.5.0/modules/core/include
#INCLUDEPATH += /home/nlevisrael/sebi-libs/opencv-4.5.0/modules/imgproc/include
#INCLUDEPATH += /home/nlevisrael/sebi-libs/opencv-4.5.0/modules/imgcodecs/include
#INCLUDEPATH += /home/nlevisrael/sebi-libs/opencv-4.5.0/modules/videoio/include



HEADERS += \
  $$SRC_DIR/dgi-image.h \
  $$SRC_DIR/dgi-contour.h \
  $$SRC_DIR/dgi-demo-frame.h \



SOURCES += \
  $$SRC_DIR/dgi-image.cpp \
  $$SRC_DIR/dgi-contour.cpp \
  $$SRC_DIR/dgi-demo-frame.cpp \



LIBS += -L$$OPENCV_LIB_DIR -lopencv_core -lopencv_imgcodecs -lopencv_imgproc

#LIBS += -L$$OPENCV_LIB_DIR/ -lopencv_core -lopencv_core
#LIBS += -L$$OPENCV_LIB_DIR/ -lopencv_core -lopencv_imgproc

