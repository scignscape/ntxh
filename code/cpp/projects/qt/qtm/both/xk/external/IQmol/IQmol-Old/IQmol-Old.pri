
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += opengl xml


include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)
include($$ROOT_DIR/../preferred/openbabel.pri)

UI_DIR = $$SRC_DIR/uis-gen/any-build


INCLUDEPATH += $$SRC_GROUP_DIR  \

INCLUDEPATH += $$SRC_DIR/Old  $$SRC_DIR/extras  


INCLUDEPATH += $$SRC_GROUP_DIR/OpenMesh-Core  \

INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Util/Util
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Data/Data
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Parser/Parser
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Layer/Layer
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Viewer/Viewer
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Grid/Grid


INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Configurator/Configurator \
  $$SRC_GROUP_DIR/IQmol-Configurator/extras



HEADERS += \
  $$SRC_DIR/Old/LogMessageDialog.h \
  $$SRC_DIR/Old/ParseJobFiles.h \ 
  $$SRC_DIR/Old/ProgressDialog.h \
  $$SRC_DIR/Old/SurfaceAnimatorDialog.h \
  $$SRC_DIR/Old/SymmetryToleranceDialog.h \


SOURCES += \
  $$SRC_DIR/Old/AtomicDensity.C \
  $$SRC_DIR/Old/ColorGrid.C \
  $$SRC_DIR/Old/gl2ps.C \
  $$SRC_DIR/Old/LogMessageDialog.C \
  $$SRC_DIR/Old/ParseJobFiles.C \
  $$SRC_DIR/Old/ProgressDialog.C \
  $$SRC_DIR/Old/SpatialProperty.C \
  $$SRC_DIR/Old/SurfaceAnimatorDialog.C \
  $$SRC_DIR/Old/SymmetryToleranceDialog.C \
  $$SRC_DIR/Old/UndoCommands.C \


FORMS += \
  $$SRC_DIR/Old/GetVaultKeyDialog.ui \
  $$SRC_DIR/Old/LogMessageDialog.ui \
  $$SRC_DIR/Old/ProgressDialog.ui \
  $$SRC_DIR/Old/SurfaceAnimatorDialog.ui \
  $$SRC_DIR/Old/SymmetryToleranceDialog.ui \




