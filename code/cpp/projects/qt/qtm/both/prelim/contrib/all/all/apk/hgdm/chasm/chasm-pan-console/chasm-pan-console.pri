
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

# QT -= gui

QT += webenginewidgets


TEMPLATE = app

include($$ROOT_DIR/../preferred/sysr.pri)


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR $$SRC_ROOT_DIR

#INCLUDEPATH += $$NTXH_SRC_GROUP_DIR
#INCLUDEPATH += $$NTXH_SRC_GROUP_DIR/ntxh
#INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR
#INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR
#INCLUDEPATH += $$HTXN_SRC_GROUP_DIR
#INCLUDEPATH += $$SRC_GROUP_DIR/gtagml

 # Most projects don't use ROOT_DIR as a basis
 # for includes but this one loads some generated
 # source code to experiment with ...
  # INCLUDEPATH += $$ROOT_DIR


DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

DEFINES += SCREENSHOTS_FOLDER=\\\"$$ROOT_DIR/code/assets/screenshots\\\"


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES

CONFIG += no_keywords


DEFINES += USE_KANS


# Most projects don't use ROOT_DIR as a basis
# for includes but this one loads some generated
# source code to experiment with ...
INCLUDEPATH += $$ROOT_DIR


HEADERS += \
  $$SRC_DIR/rpdf/webgl-view-dialog/my-page.h \
  $$SRC_DIR/rpdf/webgl-view-dialog/rpdf-web-engine-page.h \
  $$SRC_DIR/rpdf/webgl-view-dialog/rpdf-web-engine-view.h \
  $$SRC_DIR/rpdf/webgl-view-dialog/webgl-view-dialog.h \
  $$SRC_DIR/rpdf/webgl-view-dialog/context-menu-provider.h \
  $$SRC_DIR/rpdf/webgl-view-dialog/url-or-event-pattern.h \
  $$SRC_DIR/rpdf/webgl-view-dialog/pattern-matcher-runtime.h \
  $$SRC_DIR/rpdf/webgl-view-dialog/signal-generator.h \



SOURCES += \
  $$SRC_DIR/main.cpp \
  $$SRC_DIR/rpdf/webgl-view-dialog/my-page.cpp \
  $$SRC_DIR/rpdf/webgl-view-dialog/rpdf-web-engine-page.cpp \
  $$SRC_DIR/rpdf/webgl-view-dialog/rpdf-web-engine-view.cpp  \
  $$SRC_DIR/rpdf/webgl-view-dialog/webgl-view-dialog.cpp \
  $$SRC_DIR/rpdf/webgl-view-dialog/context-menu-provider.cpp \
  $$SRC_DIR/rpdf/webgl-view-dialog/url-or-event-pattern.cpp \
  $$SRC_DIR/rpdf/webgl-view-dialog/pattern-matcher-runtime.cpp \
  $$SRC_DIR/rpdf/webgl-view-dialog/signal-generator.cpp \



LIBS += -L$$TARGETSDIR -lchasm-lib -lchasm-lib-X1 -lchasm-lib-X2 \
  -lchasm-lib-33 -lchasm-lib-43


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

