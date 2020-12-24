
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT  += core gui widgets


include($$ROOT_DIR/../preferred/opencv.pri)

include($$ROOT_DIR/../preferred/sysr.pri)

#include($$ROOT_DIR/../preferred/sysr-c.pri)

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



LIBS += -L$$OPENCV_LIB_DIR/ -lopencv_core -lopencv_imgcodecs
LIBS += -L$$OPENCV_LIB_DIR/ -lopencv_core -lopencv_core
LIBS += -L$$OPENCV_LIB_DIR/ -lopencv_core -lopencv_imgproc

