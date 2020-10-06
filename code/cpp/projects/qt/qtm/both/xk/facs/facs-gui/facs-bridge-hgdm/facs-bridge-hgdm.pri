
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


QT += core 

TEMPLATE = lib

INCLUDEPATH += $$SRC_GROUP_DIR

QT -= gui

DEFINES += USE_KANS


include($$ROOT_DIR/../preferred/sysr.pri)


HEADERS += \
  $$SRC_DIR/mpf-package-hgdm.h \
  $$SRC_DIR/hgdm-angel-runtime-context.h \
  $$SRC_DIR/hQVariant.h \


SOURCES +=  \
  $$SRC_DIR/mpf-package-hgdm.cpp \
  $$SRC_DIR/hgdm-angel-runtime-context.cpp \
  $$SRC_DIR/hQVariant.cpp \
