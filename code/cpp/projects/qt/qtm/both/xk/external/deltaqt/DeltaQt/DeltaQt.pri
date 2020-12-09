
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT -= gui

include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR  


HEADERS += \
   $$SRC_DIR/annotatedvalue.h \
   $$SRC_DIR/datavalidation.h \
   $$SRC_DIR/delimitedbuffer.h \
   $$SRC_DIR/deltaattribute.h \
   $$SRC_DIR/deltacharacter.h \
   $$SRC_DIR/deltacharactertype.h \
   $$SRC_DIR/deltadataset.h \
   $$SRC_DIR/deltadependentchars.h \
   $$SRC_DIR/deltadirectives.h \
   $$SRC_DIR/deltaimplicitvalue.h \
   $$SRC_DIR/deltaitem.h \
   $$SRC_DIR/deltaparser.h \
   $$SRC_DIR/deltaparserphase2.h \
   $$SRC_DIR/deltaparserprivate.h \
   $$SRC_DIR/deltaqt.h \
   $$SRC_DIR/DeltaQt_global.h \
   $$SRC_DIR/deltasymbols.h \
   $$SRC_DIR/deltavaluerange.h \
   $$SRC_DIR/filenameandmeta.h \
   $$SRC_DIR/functions.h \
   $$SRC_DIR/globals.h \
   $$SRC_DIR/logmsgid.h \
   $$SRC_DIR/parselog.h \
   $$SRC_DIR/rtfprocessing.h \


SOURCES += \
   $$SRC_DIR/annotatedvalue.cpp \
   $$SRC_DIR/datavalidation.cpp \
   $$SRC_DIR/delimitedbuffer.cpp \
   $$SRC_DIR/deltaattribute.cpp \
   $$SRC_DIR/deltacharacter.cpp \
   $$SRC_DIR/deltacharactertype.cpp \
   $$SRC_DIR/deltadataset.cpp \
   $$SRC_DIR/deltadependentchars.cpp \
   $$SRC_DIR/deltadirectives.cpp \
   $$SRC_DIR/deltaimplicitvalue.cpp \
   $$SRC_DIR/deltaitem.cpp \
   $$SRC_DIR/deltaparser.cpp \
   $$SRC_DIR/deltaparserphase2.cpp \
   $$SRC_DIR/deltaparserprivate.cpp \
   $$SRC_DIR/deltaqt.cpp \
   $$SRC_DIR/deltavaluerange.cpp \
   $$SRC_DIR/functions.cpp \
   $$SRC_DIR/parselog.cpp \
   $$SRC_DIR/rtfprocessing.cpp \


