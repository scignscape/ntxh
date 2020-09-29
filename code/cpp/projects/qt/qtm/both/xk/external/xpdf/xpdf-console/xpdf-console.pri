
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

TEMPLATE = app


include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

INCLUDEPATH += $$SRC_GROUP_DIR


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords

SOURCES += \
  $$SRC_DIR/main.cpp \



LIBS += -L$$TARGETSDIR -lxpdf # -lfreetype #-lpdf-pull -ldsmain

LIBS += /home/nlevisrael/mtr/extras/gl/xcb/lib/x86_64-linux-gnu/libfreetype.so.6.12.1

LIBS += /home/nlevisrael/mtr/extras/gl/xcb/lib/x86_64-linux-gnu/libpng12.so.0



#?contains(CHOICE_FEATURES, "pdf-pull") \#/
#?{
#? message(DEFINE\'ing USING_PDF_PULL)
#? DEFINES += USING_PDF_PULL
#? LIBS +=-L$$TARGETSDIR -lpdf-pull  \
#?   -ldsmain -lntxh -lntxh-builder -lntxh-parser
#?}


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

