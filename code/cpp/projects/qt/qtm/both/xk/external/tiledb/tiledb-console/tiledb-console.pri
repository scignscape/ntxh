

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += widgets
QT += network


TEMPLATE = app


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR  $$SRC_GROUP_DIR/tiledb


DEFINES += TILEDB_EXPORT


include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)


HEADERS += \

SOURCES += \
    $$SRC_DIR/main.cpp \


LIBS += -L$$TARGETSDIR  -ltiledb

 #  maybe should go in a preferred ...
LIBS += -lcrypto
LIBS += -llz4
LIBS += -lzstd
LIBS += -lbz2








