
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = dsmain-setup

include(../build-group.pri)

TEMPLATE = app

QT += widgets gui

include($$ROOT_DIR/../preferred/sysr.pri)


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR $$SRC_ROOT_DIR

INCLUDEPATH += $$WCM_SRC_GROUP_DIR
INCLUDEPATH += $$NTXH_SRC_GROUP_DIR
INCLUDEPATH += $$NTXH_SRC_GROUP_DIR/ntxh
INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR

INCLUDEPATH += $$SCIGNSTAGE_SRC_GROUP_DIR

INCLUDEPATH += $$QRING_SRC_GROUP_DIR

INCLUDEPATH += $$HTXN_SRC_GROUP_DIR


DEFINES += DEFAULT_ICON_FOLDER=\\\"$$ROOT_DIR/code/assets/icons\\\"

DEFINES += DEFAULT_DATASET_FOLDER=\\\"$$ROOT_DIR/data/dataset\\\"

DEFINES += DEFAULT_NTXH_FOLDER=\\\"$$DEV_ROOT_DIR/ntxh\\\"

DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

DEFINES += DEFAULT_SDI_FOLDER=\\\"$$ROOT_DIR/../dev/documents\\\"

DEFINES += SCREENSHOTS_FOLDER=\\\"$$ROOT_DIR/code/assets/screenshots\\\"


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES

CONFIG += no_keywords

DEFINES += USE_KANS


INCLUDEPATH += $$DGH_SDI_SRC_GROUP_DIR


HEADERS += \


SOURCES += \
  $$SRC_DIR/main.cpp


LIBS += -L$$TARGETSDIR -ldsmain -lntxh -lntxh-parser -lqh-package  -lqring


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

