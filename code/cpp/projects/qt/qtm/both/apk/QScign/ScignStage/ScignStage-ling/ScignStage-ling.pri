
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


QT += widgets network


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR

INCLUDEPATH += $$DSMAIN_SRC_GROUP_DIR

INCLUDEPATH += $$XPDF_SRC_GROUP_DIR
INCLUDEPATH += $$PHAON_SRC_GROUP_DIR

INCLUDEPATH += $$PHAONLIB_SRC_GROUP_DIR


INCLUDEPATH += $$NTXH_SRC_GROUP_DIR
INCLUDEPATH += $$NTXH_SRC_GROUP_DIR/ntxh


INCLUDEPATH += $$PHAONIR_SRC_GROUP_DIR

DEFINES += DEFAULT_PTR_BYTE_CODE=QT_POINTER_SIZE

INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$QRING_SRC_GROUP_DIR
INCLUDEPATH += $$LEXPAIR_SRC_GROUP_DIR

INCLUDEPATH += $$XPDF_SRC_GROUP_DIR/xpdf/aconf
INCLUDEPATH += $$XPDF_SRC_GROUP_DIR/xpdf/goo

DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES

DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

DEFINES += DEFAULT_FOLDER=\\\"$$ROOT_DIR/code/assets\\\"
DEFINES += DEFAULT_ICON_FOLDER=\\\"$$ROOT_DIR/code/assets/icons\\\"

DEFINES += ABOUT_FILE_FOLDER=\\\"$$CPP_ROOT_DIR/about/about-files\\\"

DEFINES += SAMPLES_FOLDER=\\\"$$DATA_ROOT_DIR/samples\\\"

DEFINES += DATA_ROOT_DIR=\\\"$$DATA_ROOT_DIR\\\"


CONFIG += no_keywords

DEFINES += USE_KANS
DEFINES += USE_RZNS

INCLUDEPATH += $$XPDF_SRC_GROUP_DIR


HEADERS += \
  $$SRC_DIR/ScignStage-ling-dialog.h \
  $$SRC_DIR/nav-protocols/nav-ling-1d-panel.h \
  $$SRC_DIR/subwindows/scignstage-clickable-label.h \
  $$SRC_DIR/xpdf-bridge.h \


SOURCES += \
  $$SRC_DIR/ScignStage-ling-dialog.cpp \
  $$SRC_DIR/nav-protocols/nav-ling-1d-panel.cpp \
  $$SRC_DIR/subwindows/scignstage-clickable-label.cpp \
  $$SRC_DIR/xpdf-bridge.cpp \
  $$SRC_ROOT_DIR/add-minimize-frame.cpp \

#?  $$SRC_ROOT_DIR/default-phr-startup.cpp \


LIBS += -L$$TARGETSDIR -ldsmain


contains(CHOICE_FEATURES, "xpdf") \#/
{
 message(DEFINE\'ing USING_XPDF)
 DEFINES += USING_XPDF
 message(LINKING XPDF)
 LIBS += -L$$TARGETSDIR -lxpdf
}

contains(CHOICE_FEATURES, "config") \#/
{
 message(DEFINE\'ing USING_CONFIG_DIALOG)
 DEFINES += USING_CONFIG_DIALOG
}

contains(CHOICE_FEATURES, "lex-pair") \#/
{
 message(DEFINE\'ing USING_LEXPAIR)
 DEFINES += USING_LEXPAIR
}

contains(CHOICE_FEATURES, "kph") \#/
{
 message(DEFINE\'ing USING_KPH)
 DEFINES += USING_KPH

 INCLUDEPATH += $$PHAONIR_SRC_GROUP_DIR
 INCLUDEPATH += $$PHAONLIB_SRC_GROUP_DIR

INCLUDEPATH += $$APPLICATION_MODEL_SRC_GROUP_DIR


 LIBS += -L$$TARGETSDIR -lphaon-lib -lphaon-ir
}


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
