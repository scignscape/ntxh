
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)


QT -= gui

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/sysr-c.pri)



INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR


HEADERS += \
  $$SRC_DIR/dw-instance.h


SOURCES += \
  $$SRC_DIR/dw-instance.cpp


