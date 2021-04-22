
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = dsmain

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


LIBS += -L$$TARGETSDIR  \
  -lntxh  -lntxh-parser -lngml-sdi  -ldgh-sdi  \
  -ldsmain  -lScignStage-ling -lqring


LIBS += -L$$TARGETSDIR -lqh-package


contains(CHOICE_FEATURES, "ro") \#/
{
 message(DEFINE\'ing USING_RO)
 DEFINES += USING_RO
 LIBS += -L$$TARGETSDIR -lro-info

 DEFINES += TARGETS_DIR=\\\"$$TARGETSDIR\\\"
 DEFINES += AR_ROOT_DIR=\\\"$$ROOT_DIR\\\"

 INCLUDEPATH += $$SRC_PROSET_DIR/ro-info
}


contains(CHOICE_FEATURES, "kph-gen") \#/
{
 message(DEFINE\'ing USING_KPH_GEN)
 DEFINES += USING_KPH_GEN
 LIBS += -L$$TARGETSDIR -lkph-generator
}


contains(CHOICE_FEATURES, "kph") \#/
{
 message(DEFINE\'ing USING_KPH)
 DEFINES += USING_KPH

 LIBS += -L$$TARGETSDIR -lphaon-lib -lphaon-ir -lphr-direct-eval  \
   -lphr-command-runtime

 HEADERS += \
   $$SRC_DIR/test-functions.h \

 SOURCES += \
   $$SRC_DIR/test-functions.cpp \

 INCLUDEPATH += $$PHAONIR_SRC_GROUP_DIR
 INCLUDEPATH += $$PHAONLIB_SRC_GROUP_DIR
 INCLUDEPATH += $$APPLICATION_MODEL_SRC_GROUP_DIR

 LIBS += -L$$TARGETSDIR -lapplication-model

}


contains(CHOICE_FEATURES, "xpdf") \#/
{
 message(DEFINE\'ing USING_XPDF)
 DEFINES += USING_XPDF
 message(LINKING XPDF)
 LIBS += -L$$TARGETSDIR -lxpdf -lquazip

 include($$ROOT_DIR/../preferred/xpdf.pri)
}


contains(CHOICE_FEATURES, "lex-pair") \#/
{
 message(DEFINE\'ing USING_LEXPAIR)
 DEFINES += USING_LEXPAIR

 INCLUDEPATH += $$LEXPAIR_SRC_GROUP_DIR

 LIBS += -L$$TARGETSDIR -llexpair
}


contains(CHOICE_FEATURES, "config") \#/
{
 message(DEFINE\'ing USING_CONFIG_DIALOG)
 DEFINES += USING_CONFIG_DIALOG

 INCLUDEPATH += $$CONFIG_SRC_GROUP_DIR

 DEFINES += DEFINES_SRC_FOLDER=\\\"$$SRC_ROOT_DIR/_defines\\\"
 DEFINES += CHOICES_PRI_FOLDER=\\\"$$CPP_ROOT_DIR/projects/qt/qtm/_choices\\\"
 DEFINES += CUSTOM_LIBS_PRI_FOLDER=\\\"$$CPP_ROOT_DIR/projects/qt/qtm/_custom_libs\\\"
 DEFINES += UNIBUILD_PRI_FOLDER=\\\"$$CPP_ROOT_DIR/projects/qt/qtm/unibuild/dsmain\\\"

 LIBS += -L$$TARGETSDIR -lconfig-dialog
}



message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

