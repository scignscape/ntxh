
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


QT += widgets gui


QT += location   network



include(../build-group.pri)

CONFIG += c++17


TEMPLATE = app

#MAPGRAPHICS_MASTER = ../../../MapGraphics-master
# http://localhost:6600/qmt-l/rs~png/~tiles/kherson/~osm-14-9674-5784

include($$ROOT_DIR/../preferred/openssl.pri)

#LIBS += /usr/lib/x86_64-linux-gnu/libssl.a



INCLUDEPATH += \
  $$SRC_GROUP_DIR/MapGraphics


HEADERS += \
  $$SRC_DIR/lanternfly/lanternfly-frame.h \
  $$SRC_DIR/main-window.h \
  $$SRC_DIR/lanternfly/lanternfly-sighting-dialog.h \
  $$SRC_DIR/lanternfly/lanternfly-configuration-dialog.h \
  $$SRC_DIR/lanternfly/lanternfly-sighting-filter-dialog.h \
  $$SRC_DIR/qmt-client-layer.h \
  $$SRC_DIR/qmt-client-context-menu-handler.h \
  $$SRC_DIR/qmt-client-location-focus.h \


SOURCES += \
  $$SRC_DIR/lanternfly/lanternfly-frame.cpp \
  $$SRC_DIR/lanternfly/lanternfly-sighting-dialog.cpp \
  $$SRC_DIR/lanternfly/lanternfly-configuration-dialog.cpp \
  $$SRC_DIR/lanternfly/lanternfly-sighting-filter-dialog.cpp \
  $$SRC_DIR/main-window.cpp \
  $$SRC_DIR/main.cpp \
  $$SRC_DIR/qmt-client-layer.cpp \
  $$SRC_DIR/qmt-client-context-menu-handler.cpp \
  $$SRC_DIR/qmt-client-location-focus.cpp \



LIBS += -L$$TARGETSDIR -lMapGraphics

#HEADERS += \

