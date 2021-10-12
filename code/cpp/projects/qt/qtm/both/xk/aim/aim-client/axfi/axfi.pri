

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += widgets xml

INCLUDEPATH += $$SRC_DIR  $$AIMLIB_SRC_GROUP_DIR/aimlib/AIMLib

QMAKE_CC = gcc-7
QMAKE_CXX = g++-7

CONFIG += c++17

message($$AIMLIB_SRC_GROUP_DIR)

#INCLUDEPATH += $$SRC_GROUP_DIR
DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

INCLUDEPATH += $$DGDB_SRC_GROUP_DIR

INCLUDEPATH += $$DGDB_SRC_GROUP_DIR/tkrzw

HEADERS += \
  $$SRC_DIR/axfi-annotation.h  \
  $$SRC_DIR/axfi-location-2d.h  \
  $$SRC_DIR/axfi-annotation-group.h  \
  $$SRC_DIR/axfi-annotation-environment.h  \
  $$SRC_DIR/axfi-annotation-folder.h  \
  $$SRC_DIR/aim/user-info.h  \
  $$SRC_DIR/aim/imaging-equipment-info.h  \
  $$SRC_DIR/aim/image-annotation-info.h \
  $$SRC_DIR/aim/image-annotation-collection-info.h \
  $$SRC_DIR/al-wrap.h \
  $$SRC_DIR/dh/dhax-annotation-target.h \
  $$SRC_DIR/dh/dhax-annotation-environment.h \
  $$SRC_DIR/dh/dhax-annotation-folder.h \
  $$SRC_DIR/dh/dhax-annotation-group.h \
  $$SRC_DIR/dh/dhax-annotation-instance.h \
  $$SRC_DIR/dh/location/dhax-location-2d.h \
  $$SRC_DIR/dh/location/dhax-signed-location-2d.h \
  $$SRC_DIR/dh/location/dhax-float-location-2d.h \
  $$SRC_DIR/dh/location/dhax-double-location-2d.h \



SOURCES += \
  $$SRC_DIR/axfi-annotation.cpp  \
  $$SRC_DIR/axfi-location-2d.cpp  \
  $$SRC_DIR/axfi-annotation-group.cpp  \
  $$SRC_DIR/axfi-annotation-environment.cpp  \
  $$SRC_DIR/axfi-annotation-folder.cpp  \
  $$SRC_DIR/aim/user-info.cpp  \
  $$SRC_DIR/aim/imaging-equipment-info.cpp  \
  $$SRC_DIR/aim/image-annotation-info.cpp \
  $$SRC_DIR/aim/image-annotation-collection-info.cpp \
  $$SRC_DIR/dh/dhax-annotation-target.cpp \
  $$SRC_DIR/dh/dhax-annotation-environment.cpp \
  $$SRC_DIR/dh/dhax-annotation-folder.cpp \
  $$SRC_DIR/dh/dhax-annotation-group.cpp \
  $$SRC_DIR/dh/dhax-annotation-instance.cpp \
  $$SRC_DIR/dh/location/dhax-location-2d.cpp \
  $$SRC_DIR/dh/location/dhax-signed-location-2d.cpp \
  $$SRC_DIR/dh/location/dhax-float-location-2d.cpp \
  $$SRC_DIR/dh/location/dhax-double-location-2d.cpp \



message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
