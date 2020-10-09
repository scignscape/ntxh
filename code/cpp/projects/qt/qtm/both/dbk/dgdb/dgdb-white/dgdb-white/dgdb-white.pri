
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)


QT -= gui

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/sysr-c.pri)


DEFINES += USE_KANS


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR

#? INCLUDEPATH += $$SRC_KERNEL_DIR/whitedb/whitedb 

INCLUDEPATH += $$NTXH_SRC_GROUP_DIR  $$NTXH_SRC_GROUP_DIR/ntxh 
INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$WHITEDB_SRC_GROUP_DIR
INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR


HEADERS += \
  $$SRC_DIR/wdb-manager.h  \
  $$SRC_DIR/wdb-instance.h  \
  $$SRC_DIR/dw-instance.h  \
  $$SRC_DIR/dgenvironment.h  \



SOURCES += \
  $$SRC_DIR/wdb-manager.cpp  \
  $$SRC_DIR/wdb-instance.cpp  \
  $$SRC_DIR/dw-instance.cpp  \
  $$SRC_DIR/dgenvironment.cpp  \



LIBS += -L$$TARGETSDIR -lwhitedb  \
  -lntxh  -lntxh-parser


