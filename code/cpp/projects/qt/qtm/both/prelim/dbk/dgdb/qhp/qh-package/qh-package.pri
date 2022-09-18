
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)


QT -= gui

include($$ROOT_DIR/../preferred/sysr.pri)


DEFINES += USE_KANS


HEADERS += \
  $$SRC_DIR/qh-pack-code.h  \
  $$SRC_DIR/qh-pack-builder.h  \
  $$SRC_DIR/qh-pack-reader.h  \
  $$SRC_DIR/qh-node-data.h  \
  $$SRC_DIR/qh-class-object.h  \
  $$SRC_DIR/qh-field-info.h  \
  $$SRC_DIR/qh-node-frame.h  \
  $$SRC_DIR/qh-hypernode.h  \
  $$SRC_DIR/qh-hyperedge.h  \
  $$SRC_DIR/qh-hyperedge-dominion.h  \
  $$SRC_DIR/runtime/qh-runtime.h  \
  $$SRC_DIR/runtime/qh-type-system.h  \
  $$SRC_DIR/runtime/qh-type.h  \


SOURCES += \
  $$SRC_DIR/qh-pack-code.cpp  \
  $$SRC_DIR/qh-pack-builder.cpp  \
  $$SRC_DIR/qh-pack-reader.cpp  \
  $$SRC_DIR/qh-node-data.cpp  \
  $$SRC_DIR/qh-class-object.cpp  \
  $$SRC_DIR/qh-field-info.cpp  \
  $$SRC_DIR/qh-node-frame.cpp  \
  $$SRC_DIR/qh-hypernode.cpp  \
  $$SRC_DIR/qh-hyperedge.cpp  \
  $$SRC_DIR/qh-hyperedge-dominion.cpp  \
  $$SRC_DIR/runtime/qh-runtime.cpp  \
  $$SRC_DIR/runtime/qh-type-system.cpp  \
  $$SRC_DIR/runtime/qh-type.cpp  \



#LIBS += -L$$TARGETSDIR -lwhitedb  \
#  -lntxh  -lntxh-parser


