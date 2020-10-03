
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


QT += core 

TEMPLATE = lib

#INCLUDEPATH += \
# .. \

QT -= gui

DEFINES += USE_KANS


include($$ROOT_DIR/../preferred/sysr.pri)


HEADERS += \
  $$SRC_DIR/qvector-matrix-r8.h  \
  $$SRC_DIR/mpf-package.h \


SOURCES +=  \
  $$SRC_DIR/qvector-matrix-r8.cpp \
  $$SRC_DIR/mpf-package.cpp \


