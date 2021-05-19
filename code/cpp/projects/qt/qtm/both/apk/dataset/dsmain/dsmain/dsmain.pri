
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = dsmain

include(../build-group.pri)

QT -= gui

include($$ROOT_DIR/../preferred/sysr.pri)


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR $$SRC_ROOT_DIR

INCLUDEPATH += $$WCM_SRC_GROUP_DIR
INCLUDEPATH += $$NTXH_SRC_GROUP_DIR
INCLUDEPATH += $$NTXH_SRC_GROUP_DIR/ntxh
INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR

INCLUDEPATH += $$HTXN_SRC_GROUP_DIR

INCLUDEPATH += $$QRING_SRC_GROUP_DIR

INCLUDEPATH += $$QHP_SRC_GROUP_DIR



DEFINES += DEFAULT_WCM_FOLDER=\\\"$$DEV_ROOT_DIR/wcm\\\"

DEFINES += DEFAULT_NTXH_FOLDER=\\\"$$DEV_ROOT_DIR/ntxh\\\"

DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES

CONFIG += no_keywords


DEFINES += USE_KANS


# # currently chasm is only available through the isobuild ...
CHOICE_FEATURES += chasm

contains(CHOICE_FEATURES, "chasm") \#/
{
 message(DEFINE\'ing USE_CHASM)
 DEFINES += USE_CHASM
}


HEADERS +=  \
  $$SRC_DIR/dataset.h  \
  $$SRC_DIR/dataset-info.h  \
  $$SRC_DIR/dataset-environment.h  \
  $$SRC_DIR/dsm-sdi-document.h  \
  $$SRC_DIR/language-sample.h  \
  $$SRC_DIR/language-sample-group.h  \
  $$SRC_DIR/discourse-markup-sample.h  \
  $$SRC_DIR/qh-model.h  \
  $$SRC_DIR/qh/local.h  \
  $$SRC_DIR/qh/known-types.h  \


SOURCES += \
  $$SRC_DIR/dataset.cpp  \
  $$SRC_DIR/dataset-environment.cpp  \
  $$SRC_DIR/dataset-info.cpp  \
  $$SRC_DIR/dsm-sdi-document.cpp  \
  $$SRC_DIR/language-sample.cpp  \
  $$SRC_DIR/language-sample-group.cpp  \
  $$SRC_DIR/discourse-markup-sample.cpp  \
  $$SRC_DIR/qh-model.cpp  \
  $$SRC_DIR/qh/local.cpp  \


LIBS +=  -L$$TARGETSDIR  -lntxh-parser -lntxh  -lqring

LIBS += -L$$TARGETSDIR -lqh-package

contains(CHOICE_FEATURES, "chasm") \#/
{
 LIBS += -L$$TARGETSDIR -lchasm-dsmain -lchasm-lib
}


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

