
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

TEMPLATE = app

QT -= gui

include($$ROOT_DIR/../preferred/sysr.pri)

#include($$ROOT_DIR/../preferred/sysr-c.pri)

DEFINES += DEFAULT_DEV_DGDB_FOLDER=\\\"$$ROOT_DIR/dev/consoles/dgdb\\\"

DEFINES += USE_KANS


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR $$WHITEDB_SRC_GROUP_DIR


HEADERS += \


SOURCES += \
  $$SRC_DIR/main.cpp \



LIBS += -L$$TARGETSDIR -lwhitedb -ldgdb-white \
  -lntxh  -lntxh-parser

