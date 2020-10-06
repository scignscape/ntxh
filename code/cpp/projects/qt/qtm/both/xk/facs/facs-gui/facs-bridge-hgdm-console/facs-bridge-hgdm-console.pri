
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


QT += core 

TEMPLATE = app

INCLUDEPATH += $$SRC_GROUP_DIR  \
  $$ANGELSCRIPT_SRC_GROUP_DIR/include  \
  $$ANGELSCRIPT_SRC_GROUP_DIR


QT -= gui

DEFINES += USE_KANS


include($$ROOT_DIR/../preferred/sysr.pri)


DEFINES += AS_ROOT_DIR=\\\"$$ROOT_DIR/dev/consoles/angelscript\\\"


HEADERS += \


SOURCES +=  \
  $$SRC_DIR/main.cpp \


LIBS += -L$$TARGETSDIR -lfacs-bridge -lfacs-bridge-hgdm \
   -langelscript  -las-runner


