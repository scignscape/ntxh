
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)


QT += network


QMAKE_CC = gcc-7
QMAKE_CXX = g++-7

CONFIG += c++17


INCLUDEPATH += $$SRC_GROUP_DIR


HEADERS += \
  $$SRC_GROUP_DIR/qmt-utils/qmt-utils.h \
  $$SRC_GROUP_DIR/qmt-utils/qmt-utils.hpp \


HEADERS += \
  $$SRC_GROUP_DIR/qmt-server/qmt-server-response.h \
  $$SRC_GROUP_DIR/qmt-accessors.h \
  $$SRC_GROUP_DIR/qmt-global-types.h \


SOURCES += \
  $$SRC_GROUP_DIR/qmt-utils/qmt-utils.cpp \

SOURCES += \
  $$SRC_GROUP_DIR/qmt-server/qmt-server-response.cpp \
  $$SRC_DIR/main.cpp \


