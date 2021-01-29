
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += widgets network

INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR

INCLUDEPATH += $$PHAONIR_SRC_GROUP_DIR
INCLUDEPATH += $$PHAONLIB_SRC_GROUP_DIR
INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR

INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$QRING_SRC_GROUP_DIR
INCLUDEPATH += $$NTXH_SRC_GROUP_DIR

INCLUDEPATH += $$NTXH_SRC_GROUP_DIR/ntxh

INCLUDEPATH += $$DSMAIN_SRC_GROUP_DIR

INCLUDEPATH += $$QHP_SRC_GROUP_DIR


DEFINES += DEFAULT_PTR_BYTE_CODE=QT_POINTER_SIZE

INCLUDEPATH += $$SCIGNSTAGE_SRC_GROUP_DIR

DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords

DEFINES += USE_KANS
DEFINES += USE_RZNS

DEFINES += USE_SOCKET_WITHOUT_QNAM


HEADERS += \
  $$SRC_DIR/application-config-model.h \
  $$SRC_DIR/application-model.h \
  $$SRC_DIR/application-test-model.h \


SOURCES += \
  $$SRC_DIR/application-config-model.cpp \
  $$SRC_DIR/application-model.cpp \
  $$SRC_DIR/application-test-model.cpp \


SOURCES += \
  $$SRC_ROOT_DIR/default-phr-startup.cpp \




LIBS += -L$$TARGETSDIR -lScignStage-ling

LIBS += -L$$TARGETSDIR -lphaon-ir



CHOICE_FEATURES += kph

contains(CHOICE_FEATURES, "kph") \#/
{
 message(DEFINE\'ing USING_KPH)
 DEFINES += USING_KPH
}


CHOICE_FEATURES += lex-pair

contains(CHOICE_FEATURES, "lex-pair") \#/
{
 message(DEFINE\'ing USING_LEXPAIR)
 DEFINES += USING_LEXPAIR
}

message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
