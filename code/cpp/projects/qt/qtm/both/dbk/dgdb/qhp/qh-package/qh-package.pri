
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)


QT -= gui

include($$ROOT_DIR/../preferred/sysr.pri)


DEFINES += USE_KANS


HEADERS += \
  $$SRC_DIR/qh-bundle-code.h  \
  $$SRC_DIR/qh-pack-builder.h  \
  $$SRC_DIR/qh-pack-reader.h  \
  $$SRC_DIR/qh-node-data.h  \
  $$SRC_DIR/qh-hypernode.h  \
  $$SRC_DIR/qh-hyperedge.h  \


SOURCES += \
  $$SRC_DIR/qh-bundle-code.cpp  \
  $$SRC_DIR/qh-pack-builder.cpp  \
  $$SRC_DIR/qh-pack-reader.cpp  \
  $$SRC_DIR/qh-node-data.cpp  \
  $$SRC_DIR/qh-hypernode.cpp  \
  $$SRC_DIR/qh-hyperedge.cpp  \


#LIBS += -L$$TARGETSDIR -lwhitedb  \
#  -lntxh  -lntxh-parser


