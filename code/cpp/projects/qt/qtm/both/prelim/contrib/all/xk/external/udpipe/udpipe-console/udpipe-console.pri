
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = udpipe-console

include(../build-group.pri)

TEMPLATE = app

#DEFINES += DEFAULT_KPH_FOLDER=\\\"$$CPP_ROOT_DIR/kph\\\"

INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR


INCLUDEPATH += $$QRING_SRC_GROUP_DIR

INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR


CONFIG += no_keywords


DEFINES += USE_KANS

DEFINES += CONLLU_DIR=\\\"$$DEV_ROOT_DIR/conllu\\\"

INCLUDEPATH += $$SRC_GROUP_DIR/udpipe $$SRC_GROUP_DIR/

INCLUDEPATH += $$SRC_PROSET_DIR/

INCLUDEPATH += $$SRC_PROSET_DIR/QRing

TEMPLATE = app

SOURCES += \
    $$SRC_DIR/main.cpp \


LIBS += -L$$TARGETSDIR -ludpipe  -lqring \
   -lntxh-udp -lntxh-parser -lntxh

