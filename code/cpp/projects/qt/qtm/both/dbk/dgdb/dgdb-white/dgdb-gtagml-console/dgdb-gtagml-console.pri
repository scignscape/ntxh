
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

TEMPLATE = app

QT -= gui

include($$ROOT_DIR/../preferred/sysr.pri)

#include($$ROOT_DIR/../preferred/sysr-c.pri)

DEFINES += DEFAULT_GTAGML_GEN_FOLDER=\\\"$$ROOT_DIR/../gtagml\\\"

DEFINES += DEFAULT_DEV_DGDB_NGML_FOLDER=\\\"$$ROOT_DIR/../gtagml/dgdb\\\"

DEFINES += DEFAULT_SDI_FOLDER=\\\"$$ROOT_DIR/dev/consoles/gtagml/sdi\\\"

DEFINES += USE_KANS


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR $$WHITEDB_SRC_GROUP_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/dgdb-white

INCLUDEPATH += $$SRC_GROUP_DIR/

INCLUDEPATH += $$SRC_ROOT_DIR/apk/gtagml/gtagml
INCLUDEPATH += $$SRC_ROOT_DIR/apk/hgdm/ntxh
INCLUDEPATH += $$SRC_ROOT_DIR/apk/hgdm/ntxh/ntxh


INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR


HEADERS += \
  $$SRC_DIR/gtagml-document-info.h \
  $$SRC_DIR/gtagml-document-mark.h \
  $$SRC_DIR/gtagml-document-citation.h \
  $$SRC_DIR/sdi/language-sample.h \
  $$SRC_DIR/sdi/language-sample-group.h \
  $$SRC_DIR/sdi/sdi-sentence.h \
  $$SRC_DIR/sdi/sdi-paragraph.h \



SOURCES += \
  $$SRC_DIR/main.cpp \
  $$SRC_DIR/gtagml-document-info.cpp \
  $$SRC_DIR/gtagml-document-mark.cpp \
  $$SRC_DIR/gtagml-document-citation.cpp \
  $$SRC_DIR/sdi/language-sample.cpp \
  $$SRC_DIR/sdi/language-sample-group.cpp \
  $$SRC_DIR/sdi/sdi-sentence.cpp \
  $$SRC_DIR/sdi/sdi-paragraph.cpp \



LIBS += -L$$TARGETSDIR -lwhitedb -ldgdb-white \
  -lntxh  -lntxh-parser -lngml-sdi

