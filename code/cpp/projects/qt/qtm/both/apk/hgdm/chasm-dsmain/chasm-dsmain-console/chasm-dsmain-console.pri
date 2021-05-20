
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT -= gui


TEMPLATE = app

include($$ROOT_DIR/../preferred/sysr.pri)


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR $$SRC_ROOT_DIR

INCLUDEPATH += $$NTXH_SRC_GROUP_DIR
INCLUDEPATH += $$NTXH_SRC_GROUP_DIR/ntxh
INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$QRING_SRC_GROUP_DIR
#INCLUDEPATH += $$SRC_GROUP_DIR/gtagml

INCLUDEPATH += $$SRC_PROSET_DIR/chasm/chasm-lib
INCLUDEPATH += $$SRC_PROSET_DIR/chasm-vm

INCLUDEPATH += $$DSMAIN_SRC_GROUP_DIR


 # Most projects don't use ROOT_DIR as a basis
 # for includes but this one loads some generated
 # source code to experiment with ...
  # INCLUDEPATH += $$ROOT_DIR


DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

DEFINES += DEMO_CSM_FOLDER=\\\"$$ROOT_DIR/dev/consoles/chasm-vm\\\"


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES

CONFIG += no_keywords


DEFINES += USE_KANS


# Most projects don't use ROOT_DIR as a basis
# for includes but this one loads some generated
# source code to experiment with ...
INCLUDEPATH += $$ROOT_DIR


HEADERS += \



SOURCES += \
  $$SRC_DIR/main.cpp \



LIBS += -L$$TARGETSDIR -lchasm-runtime-bridge -lchasm-vm -lchasm-procedure-table \
  -lchasm-lib -lchasm-lib-X1 -lchasm-lib-X2 \
  -lchasm-lib-33 -lchasm-lib-43

LIBS += -L$$TARGETSDIR -lchasm-dsmain-model  -ldsmain


# #  load all the libraries of dsmain-console ...

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


