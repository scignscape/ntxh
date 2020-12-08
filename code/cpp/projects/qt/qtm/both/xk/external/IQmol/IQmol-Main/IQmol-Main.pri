
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

TEMPLATE = app

QT += xml widgets opengl printsupport


INCLUDEPATH += $$SRC_ROOT_DIR/xk/external/IQmol/openbabel/include/
INCLUDEPATH += $$SRC_ROOT_DIR/xk/external/IQmol/openbabel/include-config/

include($$ROOT_DIR/../preferred/sysr.pri)

#
include($$ROOT_DIR/../preferred/boost.pri)
include($$ROOT_DIR/../preferred/openbabel.pri)

#include($$ROOT_DIR/../preferred/libssh2.pri)


INCLUDEPATH += $$SRC_GROUP_DIR  \


INCLUDEPATH += $$SRC_DIR/Main  $$SRC_DIR/extras 

UI_DIR = $$SRC_DIR/uis-gen/any-build


INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Viewer/Viewer
#
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Util/Util
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Network/Network
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Data/Data
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Parser/Parser
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Process/Process

INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Qui/

#

INCLUDEPATH += $$SRC_GROUP_DIR/OpenMesh-Core

INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Old/Old \
  $$SRC_GROUP_DIR/IQmol-Old/extras


INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Layer/Layer

INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Configurator/Configurator \
  $$SRC_GROUP_DIR/IQmol-Configurator/extras


HEADERS += \
  $$SRC_DIR/Main/AboutDialog.h \
  $$SRC_DIR/Main/FragmentTable.h \
  $$SRC_DIR/Main/HelpBrowser.h \
  $$SRC_DIR/Main/InsertMoleculeDialog.h \
  $$SRC_DIR/Main/IQmolApplication.h \
  $$SRC_DIR/Main/MainWindow.h \
  $$SRC_DIR/Main/PeriodicTable.h \
  $$SRC_DIR/Main/PreferencesBrowser.h \
  $$SRC_DIR/Main/ToolBar.h \
  $$SRC_DIR/Main/version.h \


SOURCES += \
  $$SRC_DIR/Main/AboutDialog.C \
  $$SRC_DIR/Main/FragmentTable.C \
  $$SRC_DIR/Main/HelpBrowser.C \
  $$SRC_DIR/Main/InsertMoleculeDialog.C \
  $$SRC_DIR/Main/IQmolApplication.C \
  $$SRC_DIR/Main/main.C \
  $$SRC_DIR/Main/MainWindow.C \
  $$SRC_DIR/Main/PeriodicTable.C \
  $$SRC_DIR/Main/PreferencesBrowser.C \
  $$SRC_DIR/Main/ToolBar.C \


FORMS += \
  $$SRC_DIR/Main/AboutDialog.ui \
  $$SRC_DIR/Main/FragmentTable.ui \
  $$SRC_DIR/Main/HelpBrowser.ui \
  $$SRC_DIR/Main/InsertMoleculeDialog.ui \
  $$SRC_DIR/Main/PeriodicTable.ui \
  $$SRC_DIR/Main/PeriodicTableMac.ui \
  $$SRC_DIR/Main/PreferencesBrowser.ui \
  $$SRC_DIR/Main/ToolBar.ui \


RESOURCES += \
  $$SRC_DIR/Main/IQmol.qrc


DEFINES += DEFAULT_SCREENSHOT_FOLDER=\\\"$$ROOT_DIR/code/screenshots\\\"


MPF_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/htxn/mosaic

DEFINES += DEFAULT_ICONS_FOLDER=\\\"$$ROOT_DIR/code/icons\\\"

INCLUDEPATH += $$MPF_SRC_GROUP_DIR

HEADERS += \
  $$MPF_SRC_GROUP_DIR/mpf/mpf-plugin-info.h \
  $$MPF_SRC_GROUP_DIR/mpf/mpf-plugin-info-dialog.h \
  $$MPF_SRC_GROUP_DIR/mpf/mpf-test-dialog.h \

SOURCES += \
  $$MPF_SRC_GROUP_DIR/mpf/mpf-plugin-info.cpp \
  $$MPF_SRC_GROUP_DIR/mpf/mpf-plugin-info-dialog.cpp \
  $$MPF_SRC_GROUP_DIR/mpf/mpf-test-dialog.cpp \

SOURCES += \
  $$SRC_ROOT_DIR/add-minimize-frame.cpp \



LIBS += -L$$TARGETSDIR -lIQmol-Viewer  -lQGLViewer  \
  -lIQmol-Layer -lIQmol-Configurator -lIQmol-Data  \
  -lIQmol-Grid -lIQmol-Network -lIQmol-Old -lIQmol-Parser  \
  -lIQmol-Plot -lIQmol-Process -lIQmol-Qui -lIQmol-Util  \
  -lOpenMesh-Core -lOpenMesh-Tools

#LIBS += $$LIBSSH2_STATIC_LIB

LIBS += -L$$TARGETSDIR -lopenbabel -lyaml-cpp

#LIBS += $$SRC_DIR/Main/symmol.o

QMAKE_LFLAGS += $$SRC_DIR/Main/symmol.o

LIBS += -lgfortran


LIBS += -lssh2

LIBS += -lGLU


defined(BOOST_LIB_DIR, var) {
 LIBS += -L$$BOOST_LIB_DIR -lboost_serialization -lboost_system
} else {
 LIBS += -lboost_serialization -lboost_system
}


LIBS += -lGL

LIBS += -lssl -lcrypto



