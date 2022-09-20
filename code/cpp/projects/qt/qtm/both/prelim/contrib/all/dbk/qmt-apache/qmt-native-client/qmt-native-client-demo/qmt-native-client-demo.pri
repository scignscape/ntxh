
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


QT += widgets gui

include(../build-group.pri)


TEMPLATE = app

#MAPGRAPHICS_MASTER = ../../../MapGraphics-master

INCLUDEPATH += \
  $$SRC_GROUP_DIR/MapGraphics


HEADERS += \
  $$SRC_DIR/lanternfly/lanternfly-frame.h \
  $$SRC_DIR/main-window.h \
  $$SRC_DIR/lanternfly/lanternfly-sighting-dialog.h \
  $$SRC_DIR/lanternfly/lanternfly-configuration-dialog.h \
  $$SRC_DIR/lanternfly/lanternfly-sighting-filter-dialog.h \



SOURCES += \
  $$SRC_DIR/lanternfly/lanternfly-frame.cpp \
  $$SRC_DIR/lanternfly/lanternfly-sighting-dialog.cpp \
  $$SRC_DIR/lanternfly/lanternfly-configuration-dialog.cpp \
  $$SRC_DIR/lanternfly/lanternfly-sighting-filter-dialog.cpp \
  $$SRC_DIR/main-window.cpp \
  $$SRC_DIR/main.cpp \


LIBS += -L$$TARGETSDIR -lMapGraphics

#HEADERS += \

