
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


TEMPLATE = app

QT += widgets


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR

DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES

DEFINES += DEFAULT_KPH_FOLDER=\\\"$$ROOT_DIR/dev/kph\\\"
DEFINES += DEFAULT_ICON_FOLDER=\\\"$$CPP_ROOT_DIR/assets/icons\\\"

CONFIG += no_keywords

DEFINES += USE_KANS
DEFINES += USE_RZNS

DEFINES += USING_KPH


HEADERS += \


SOURCES += \
  $$SRC_DIR/main.cpp \


LIBS += -L$$TARGETSDIR -lapplication-model-test-dialog  -lapplication-model  \
   -lScignStage-ling  -ldsmain  -lntxh  -lntxh-parser  -lntxh-builder  \
   -lphaon-ir -lqring


LIBS +=  -L$$TARGETSDIR  -lntxh-parser -lntxh

LIBS += -L$$TARGETSDIR -lqh-package


contains(CHOICE_FEATURES, "xpdf") \#/
{
 LIBS += -L$$TARGETSDIR -lxpdf
}

contains(CHOICE_FEATURES, "pdf-pull") \#/
{
 LIBS +=  -L$$TARGETSDIR -lpdf-pull
}

contains(CHOICE_FEATURES, "kph") \#/
{
 LIBS += -L$$TARGETSDIR -lphaon-lib
}

contains(CHOICE_FEATURES, "lex-pair") \#/
{
 message(DEFINE\'ing USING_LEXPAIR)
 DEFINES += USING_LEXPAIR
}

message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
