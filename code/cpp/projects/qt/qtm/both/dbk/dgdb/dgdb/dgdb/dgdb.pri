
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)


QT -= gui

QT += xml


exists($$ROOT_DIR/../preferred/sysr.pri): include($$ROOT_DIR/../preferred/sysr.pri)

exists($$ROOT_DIR/../preferred/sysr-c.pri): include($$ROOT_DIR/../preferred/sysr-c.pri)

QMAKE_CC = gcc-7
QMAKE_CXX = g++-7

CONFIG += c++17


DEFINES += USE_KANS



INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR

DEFINES += _FTOK_CHAR=\\\'~\\\'


#INCLUDEPATH += $$SRC_GROUP_DIR/tkrzw

#? INCLUDEPATH += $$SRC_KERNEL_DIR/whitedb/whitedb 

INCLUDEPATH += $$NTXH_SRC_GROUP_DIR  $$NTXH_SRC_GROUP_DIR/ntxh 
INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$WHITEDB_SRC_GROUP_DIR
INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR


HEADERS += \
  $$SRC_DIR/dgdb-location-structure.h  \
  $$SRC_DIR/dgdb-database-instance.h  \
  $$SRC_DIR/dgdb-record-processors.h  \
  $$SRC_DIR/conversions.h  \
  $$SRC_DIR/dgdb-hypernode.h  \
  $$SRC_DIR/dwb/dwb-instance.h  \
  $$SRC_DIR/dtb/dtb-package.h  \
  $$SRC_DIR/types/dh-type.h  \
  $$SRC_DIR/types/dh-type-system.h  \
  $$SRC_DIR/types/dh-type-builder.h  \
  $$SRC_DIR/types/dh-subvalue-field.h  \



SOURCES += \
  $$SRC_DIR/dgdb-location-structure.cpp  \
  $$SRC_DIR/dgdb-database-instance.cpp  \
  $$SRC_DIR/dgdb-hypernode.cpp  \
  $$SRC_DIR/dgdb-database-instance.data-options.cpp  \
  $$SRC_DIR/dgdb-database-instance.store-subvalue.cpp  \
  $$SRC_DIR/dwb/dwb-instance.cpp  \
  $$SRC_DIR/dtb/dtb-package.cpp  \
  $$SRC_DIR/types/dh-type.cpp  \
  $$SRC_DIR/types/dh-type-system.cpp  \
  $$SRC_DIR/types/dh-type-builder.cpp  \
  $$SRC_DIR/types/dh-subvalue-field.cpp  \



#LIBS += -L$$TARGETSDIR -lwhitedb  \
#  -lntxh  -lntxh-parser


