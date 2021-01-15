
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


QT += core 

QT -= gui

DEFINES += USE_KANS

include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)

TEMPLATE = app

DEFINES += USE_KANS


INCLUDEPATH += $$SRC_GROUP_DIR/BrownGraph

INCLUDEPATH += $$SRC_PROSET_DIR/Brownie/brownie

INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR

INCLUDEPATH += $$SRC_KERNEL_DIR/dgdb/dgdb-white

INCLUDEPATH += $$SRC_KERNEL_DIR/dgdb/dgdb-white/dgdb-white


DEFINES += DEFAULT_DEV_DGDB_FOLDER=\\\"$$ROOT_DIR/dev/consoles/dgdb\\\"


HEADERS += \


SOURCES +=  \
  $$SRC_DIR/main.cpp


LIBS += -L$$TARGETSDIR -lBrownGraph


QMAKE_CXXFLAGS += -fopenmp


LIBS += -fopenmp


LIBS += -L$$TARGETSDIR -lwhitedb -ldgdb-white \
  -lntxh  -lntxh-parser

