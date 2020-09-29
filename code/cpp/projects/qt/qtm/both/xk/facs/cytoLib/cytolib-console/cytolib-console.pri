
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = cytolib-console

include(../build-group.pri)

QT -= gui

TEMPLATE = app

include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR $$SRC_ROOT_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/cytolib/include
INCLUDEPATH += $$SRC_GROUP_DIR/cytolib/hdf5
INCLUDEPATH += $$SRC_GROUP_DIR/cytolib/hdf5/c

INCLUDEPATH += $$SRC_PROSET_DIR/facs-gui


INCLUDEPATH += $$NTXH_SRC_GROUP_DIR
INCLUDEPATH += $$NTXH_SRC_GROUP_DIR/ntxh
INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR

INCLUDEPATH += $$HTXN_SRC_GROUP_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/gtagml

#DEFINES += DEFAULT_NTXH_FOLDER=\\\"$$DATA_ROOT_DIR/ntxh\\\"

DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

#DEFINES += DEFAULT_GTAGML_FOLDER=\\\"$$ROOT_DIR/dev/consoles/gtagml/gt\\\"
#DEFINES += DEFAULT_SDI_FOLDER=\\\"$$ROOT_DIR/dev/consoles/gtagml/sdi\\\"

DEFINES += DEMO_FCS_FOLDER=\\\"$$ROOT_DIR/extra/facs/fcs\\\"


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES

CONFIG += no_keywords


DEFINES += USE_KANS

HEADERS += \


SOURCES += \
  $$SRC_DIR/main.cpp \

LIBS += -L$$TARGETSDIR -lcytolib -lfacs-bridge

LIBS +=  -lstdc++fs


include($$ROOT_DIR/../preferred/facs.pri)

include($$ROOT_DIR/../preferred/proto.pri)



## uncomment if these will be found.
#  I have them in a non-standard location
#  so I set the linker flag in facs.pri ...
# LIBS += -llapack -lblas


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)


