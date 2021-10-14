

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += xml widgets

TEMPLATE = app

INCLUDEPATH += $$SRC_DIR

INCLUDEPATH += $$SRC_PROSET_DIR/aimlib/aimlib/AIMLib/

QMAKE_CC = gcc-7
QMAKE_CXX = g++-7

CONFIG += c++17


DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

include($$ROOT_DIR/../preferred/aim.pri)

DEFINES += AIM_DATA_FOLDER=\\\"$$AIM_DATA_DIR\\\"

DEFINES += DEFAULT_DEV_TKRZW_FOLDER=\\\"$$ROOT_DIR/../dev/consoles/dgdb/tkrzw\\\"

DEFINES += DEFAULT_DEV_DGDB_FOLDER=\\\"$$ROOT_DIR/../dev/consoles/dgdb/instances\\\"


DEFINES += USE_KANS

INCLUDEPATH += $$DGDB_SRC_GROUP_DIR

INCLUDEPATH += $$DGDB_SRC_GROUP_DIR/tkrzw


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/tkrzw

INCLUDEPATH += $$WHITEDB_SRC_GROUP_DIR



HEADERS += \


SOURCES += \
  $$SRC_DIR/main.cpp \


# #  for dcmtk OFString = std::string ...
DEFINES += HAVE_STD_STRING
DEFINES += HAVE_STL_STRING


LIBS += -L$$TARGETSDIR  -ldhax-gui

LIBS += -L$$TARGETSDIR  -laimlib -ldcmsr -lofstd -loflog -ldcmdata \
   -ldcmimage -ldcmimgle

LIBS += -L$$TARGETSDIR  -laxfi

LIBS += -lrt


LIBS += -L$$TARGETSDIR -ldgdb

LIBS += -L$$TARGETSDIR -ltkrzw -llz4  -llzma -lz

LIBS += -L$$TARGETSDIR -lwhitedb



#LIBS += -L$$TARGETSDIR -laimlib


# #  assumed xerces is installed ...
LIBS += -lxerces-c


DCMTK_DIR = $$DCMTK_SRC_GROUP_DIR


INCLUDEPATH += $$DCMTK_DIR/ofstd/include
INCLUDEPATH += $$DCMTK_DIR/dcm-config/include
INCLUDEPATH += $$DCMTK_DIR/dcmsr/include
INCLUDEPATH += $$DCMTK_DIR/dcmdata/include
INCLUDEPATH += $$DCMTK_DIR/oflog/include


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
