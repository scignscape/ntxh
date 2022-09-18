
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

TEMPLATE = app

QT += xml opengl network 


include($$ROOT_DIR/../preferred/sysr.pri)

CONFIG += meshlab_mini


DEFINES += MESHLAB_SCALAR=float


INCLUDEPATH += $$SRC_GROUP_DIR


INCLUDEPATH += $$SRC_GROUP_DIR/meshlab-core   #external/easyexif  


INCLUDEPATH += $$SRC_GROUP_DIR/vcglib \


INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk \


HEADERS += \
  $$SRC_GROUP_DIR/external/easyexif/exif.h \


SOURCES = \
  $$SRC_GROUP_DIR/external/easyexif/exif.cpp \
  $$SRC_DIR/main.cpp \

#  $$SRC_GROUP_DIR/external/easyexif/demo.cpp \



LIBS += -L$$TARGETSDIR -lmeshlab-core  \
  -lmeshlab-common  


LIBS += -lGL -lGLU -lGLEW 






