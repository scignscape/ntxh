

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT +=  widgets

QMAKE_CC = gcc-7
QMAKE_CXX = g++-7

CONFIG += c++17


INCLUDEPATH += $$SRC_DIR


DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

include($$ROOT_DIR/../preferred/dhax.pri)

include($$ROOT_DIR/../preferred/opencv.pri)

DEFINES += DHAX_DATA_FOLDER=\\\"$$DHAX_DATA_DIR\\\"
DEFINES += DHAX_IMAGE_FOLDER=\\\"$$DHAX_IMAGE_DIR\\\"


DEFINES += DEFAULT_DEV_TKRZW_FOLDER=\\\"$$ROOT_DIR/../dev/consoles/dgdb/tkrzw\\\"

DEFINES += DEFAULT_DEV_DGDB_FOLDER=\\\"$$ROOT_DIR/../dev/consoles/dgdb/instances\\\"

DEFINES += SCREENSHOTS_FOLDER=\\\"$$ROOT_DIR/../dev/screenshots\\\"

DEFINES += DEFAULT_DEV_FOLDER=\\\"$$ROOT_DIR/../dev\\\"


DEFINES += USE_KANS

INCLUDEPATH += $$DGDB_SRC_GROUP_DIR

INCLUDEPATH += $$DGDB_SRC_GROUP_DIR/tkrzw


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/tkrzw

INCLUDEPATH += $$WHITEDB_SRC_GROUP_DIR


HEADERS += \
  $$SRC_DIR/backend/CommandPattern/CommandManager.h \
  $$SRC_DIR/backend/CommandPattern/Commands.h \
  $$SRC_DIR/backend/CommandPattern/ICommand.h \
  $$SRC_DIR/backend/CommandPattern/blurCommand.h \
  $$SRC_DIR/backend/CommandPattern/brightnessCommand.h \
  $$SRC_DIR/backend/CommandPattern/colorMaskCommand.h \
  $$SRC_DIR/backend/CommandPattern/contrastCommand.h \
  $$SRC_DIR/backend/CommandPattern/edgeDetectCommand.h \
  $$SRC_DIR/backend/CommandPattern/embossCommand.h \
  $$SRC_DIR/backend/CommandPattern/flipXCommand.h \
  $$SRC_DIR/backend/CommandPattern/flipYCommand.h \
  $$SRC_DIR/backend/CommandPattern/grayScaleCommand.h \
  $$SRC_DIR/backend/CommandPattern/rotateAntiClockwiseCommand.h \
  $$SRC_DIR/backend/CommandPattern/rotateClockwiseCommand.h \
  $$SRC_DIR/backend/CommandPattern/scaleCommand.h \
  $$SRC_DIR/backend/CommandPattern/sharpenCommand.h \
  $$SRC_DIR/backend/CommandPattern/utils.h \
  $$SRC_DIR/backend/CommandPattern/dhax/extend-mod-3-command.h \
  $$SRC_DIR/backend/CommandPattern/dhax/quantize-3x3-command.h \
  $$SRC_DIR/backend/Image.h \
  $$SRC_DIR/backend/Pixel.h \
  $$SRC_DIR/backend/utils.h \
  $$SRC_DIR/frontend/InputDialog.h \
  $$SRC_DIR/frontend/MainWindow.h \
  $$SRC_DIR/frontend/main-window-dialog.h \

RESOURCES += \
  $$SRC_DIR/frontend/resources.qrc


SOURCES += \
  $$SRC_DIR/backend/CommandPattern/CommandManager.cpp \
  $$SRC_DIR/backend/CommandPattern/blurCommand.cpp \
  $$SRC_DIR/backend/CommandPattern/brightnessCommand.cpp \
  $$SRC_DIR/backend/CommandPattern/colorMaskCommand.cpp \
  $$SRC_DIR/backend/CommandPattern/contrastCommand.cpp \
  $$SRC_DIR/backend/CommandPattern/edgeDetectCommand.cpp \
  $$SRC_DIR/backend/CommandPattern/embossCommand.cpp \
  $$SRC_DIR/backend/CommandPattern/flipXCommand.cpp \
  $$SRC_DIR/backend/CommandPattern/flipYCommand.cpp \
  $$SRC_DIR/backend/CommandPattern/grayScaleCommand.cpp \
  $$SRC_DIR/backend/CommandPattern/rotateAntiClockwiseCommand.cpp \
  $$SRC_DIR/backend/CommandPattern/rotateClockwiseCommand.cpp \
  $$SRC_DIR/backend/CommandPattern/scaleCommand.cpp \
  $$SRC_DIR/backend/CommandPattern/sharpenCommand.cpp \
  $$SRC_DIR/backend/CommandPattern/utils.cpp \
  $$SRC_DIR/backend/CommandPattern/dhax/extend-mod-3-command.cpp \
  $$SRC_DIR/backend/CommandPattern/dhax/quantize-3x3-command.cpp \
  $$SRC_DIR/backend/Image.cpp \
  $$SRC_DIR/backend/Pixel.cpp \
  $$SRC_DIR/backend/utils.cpp \
  $$SRC_DIR/frontend/InputDialog.cpp \
  $$SRC_DIR/frontend/MainWindow.cpp \
  $$SRC_DIR/frontend/main-window-dialog.cpp \


DEFINES += APP_NAME=\\\"image-editor\\\"
DEFINES += APP_VERSION=\\\"1.0.0\\\"


#   $$SRC_DIR/backend/main.cpp \



LIBS += -L$$TARGETSDIR 



message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
