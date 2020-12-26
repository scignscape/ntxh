
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


SOURCES += \
  $$SRC_DIR/main.cpp  \


LIBS += -L$$TARGETSDIR -lqh-package

#LIBS += -L$$TARGETSDIR -lwhitedb  \
#  -lntxh  -lntxh-parser


