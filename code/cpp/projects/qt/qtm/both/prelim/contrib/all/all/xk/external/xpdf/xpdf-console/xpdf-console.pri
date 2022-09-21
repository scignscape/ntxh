
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += widgets


TEMPLATE = app


include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

INCLUDEPATH += $$SRC_GROUP_DIR


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords

SOURCES += \
  $$SRC_DIR/main.cpp \




LIBS += -L$$TARGETSDIR -lxpdf  -lquazip


DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

include($$ROOT_DIR/../preferred/xpdf.pri)
# uncomment to use default versions of these libraries,
# then you don't need a preferred/ ...
# LIBS += -lfreetype  -lpng


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

