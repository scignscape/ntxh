
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

TEMPLATE = app

QT -= gui

include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR


DEFINES += USE_KANS


HEADERS += \
  $$SRC_DIR/test-class.h  \
  $$SRC_DIR/sdi/language-sample.h  \
  $$SRC_DIR/sdi/language-sample-group.h  \
  $$SRC_DIR/sdi/prosodic-annotation.h  \
  $$SRC_DIR/sdi/prosodic-annotation-element.h  \
  $$SRC_DIR/qh/local.h  \


SOURCES += \
  $$SRC_DIR/main.cpp  \
  $$SRC_DIR/test-class.cpp  \
  $$SRC_DIR/sdi/language-sample.cpp  \
  $$SRC_DIR/sdi/language-sample-group.cpp  \
  $$SRC_DIR/sdi/prosodic-annotation.cpp  \
  $$SRC_DIR/sdi/prosodic-annotation-element.cpp  \
  $$SRC_DIR/qh/local.cpp  \


LIBS += -L$$TARGETSDIR -lqh-package

#LIBS += -L$$TARGETSDIR -lwhitedb  \
#  -lntxh  -lntxh-parser


