

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT +=  widgets

TEMPLATE = app

INCLUDEPATH += $$SRC_DIR


include($$ROOT_DIR/../preferred/compiler.pri)


CONFIG += c++17


DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

include($$ROOT_DIR/../preferred/dhax.pri)

include($$ROOT_DIR/../preferred/opencv.pri)

DEFINES += DHAX_DATA_FOLDER=\\\"$$DHAX_DATA_DIR\\\"
DEFINES += DHAX_IMAGE_FOLDER=\\\"$$DHAX_IMAGE_DIR\\\"

DEFINES += DEFAULT_DEV_FOLDER=\\\"$$ROOT_DIR/../dev\\\"

DEFINES += DEFAULT_DEV_TKRZW_FOLDER=\\\"$$ROOT_DIR/../dev/consoles/dgdb/tkrzw\\\"

DEFINES += DEFAULT_DEV_DGDB_FOLDER=\\\"$$ROOT_DIR/../dev/consoles/dgdb/instances\\\"

DEFINES += SCREENSHOTS_FOLDER=\\\"$$ROOT_DIR/../dev/screenshots\\\"

DEFINES += USE_KANS

INCLUDEPATH += $$DGDB_SRC_GROUP_DIR

INCLUDEPATH += $$DGDB_SRC_GROUP_DIR/tkrzw


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/tkrzw

INCLUDEPATH += $$WHITEDB_SRC_GROUP_DIR



HEADERS += \


SOURCES += \
  $$SRC_DIR/main.cpp \


QtColorWidgets_SRC_DIR = $$SRC_ROOT_DIR/external/Qt-Color-Widgets-master
INCLUDEPATH += $$QtColorWidgets_SRC_DIR/include
FORMS += $$QtColorWidgets_SRC_DIR/src/QtColorWidgets/color_dialog.ui

QFontIcon_SRC_DIR = $$SRC_ROOT_DIR/external/QFontIcon-master/QFontIcon
INCLUDEPATH += $$QFontIcon_SRC_DIR/../
HEADERS += $$QFontIcon_SRC_DIR/qfonticon.h
SOURCES += $$QFontIcon_SRC_DIR/qfonticon.cpp
RESOURCES += $$QFontIcon_SRC_DIR/../resource.qrc


HEADERS += \
  $$QtColorWidgets_SRC_DIR/include/QtColorWidgets/color_dialog.hpp \
  $$QtColorWidgets_SRC_DIR/include/QtColorWidgets/color_wheel.hpp \
  $$QtColorWidgets_SRC_DIR/include/QtColorWidgets/hue_slider.hpp \
  $$QtColorWidgets_SRC_DIR/include/QtColorWidgets/gradient_slider.hpp \
  $$QtColorWidgets_SRC_DIR/include/QtColorWidgets/color_preview.hpp \
  $$QtColorWidgets_SRC_DIR/include/QtColorWidgets/color_line_edit.hpp \
  $$QtColorWidgets_SRC_DIR/include/QtColorWidgets/color_utils.hpp \
  $$QtColorWidgets_SRC_DIR/src/QtColorWidgets/color_names.hpp \


SOURCES += \
  $$QtColorWidgets_SRC_DIR/src/QtColorWidgets/color_dialog.cpp \
  $$QtColorWidgets_SRC_DIR/src/QtColorWidgets/color_wheel.cpp \
  $$QtColorWidgets_SRC_DIR/src/QtColorWidgets/hue_slider.cpp \
  $$QtColorWidgets_SRC_DIR/src/QtColorWidgets/gradient_slider.cpp \
  $$QtColorWidgets_SRC_DIR/src/QtColorWidgets/color_preview.cpp \
  $$QtColorWidgets_SRC_DIR/src/QtColorWidgets/color_line_edit.cpp \
  $$QtColorWidgets_SRC_DIR/src/QtColorWidgets/color_utils.cpp \
  $$QtColorWidgets_SRC_DIR/src/QtColorWidgets/color_names.cpp \

RESOURCES += \
  $$QtColorWidgets_SRC_DIR/resources/QtColorWidgets/color_widgets.qrc



LIBS += -L$$TARGETSDIR  -limage-editor



message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)