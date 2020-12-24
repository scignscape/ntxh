
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT  += core gui widgets

TEMPLATE = app

include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/opencv.pri)

#include($$ROOT_DIR/../preferred/sysr-c.pri)


DEFINES += DEFAULT_GTAGML_GEN_FOLDER=\\\"$$ROOT_DIR/../gtagml\\\"

DEFINES += DEFAULT_DEV_DGDB_NGML_FOLDER=\\\"$$ROOT_DIR/../gtagml/dgdb\\\"

DEFINES += DEFAULT_SDI_FOLDER=\\\"$$ROOT_DIR/dev/consoles/gtagml/sdi\\\"

DEFINES += DEFAULT_DGI_FOLDER=\\\"$$ROOT_DIR/dev/consoles/dgi/images\\\"



DEFINES += USE_KANS


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR $$WHITEDB_SRC_GROUP_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/dgdb-white

INCLUDEPATH += $$SRC_GROUP_DIR/


INCLUDEPATH += $$OPENCV_SRC_DIR/modules/core/include
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/imgproc/include
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/imgcodecs/include
INCLUDEPATH += $$OPENCV_BUILD_DIR



HEADERS += \


SOURCES += \
  $$SRC_DIR/main.cpp \


LIBS += -L$$TARGETSDIR  -ldgi-opencv



LIBS += -L$$OPENCV_LIB_DIR/ -lopencv_core -lopencv_imgcodecs
LIBS += -L$$OPENCV_LIB_DIR/ -lopencv_core -lopencv_core
LIBS += -L$$OPENCV_LIB_DIR/ -lopencv_core -lopencv_imgproc

