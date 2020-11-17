
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += xml widgets opengl


include($$ROOT_DIR/../preferred/sysr.pri)

#
include($$ROOT_DIR/../preferred/boost.pri)
include($$ROOT_DIR/../preferred/openbabel.pri)

include($$ROOT_DIR/../preferred/libssh2.pri)

UI_DIR = $$SRC_DIR/uis-gen/any-build


INCLUDEPATH += $$SRC_GROUP_DIR  \


INCLUDEPATH += $$SRC_DIR/Viewer   $$SRC_DIR/extras


# 
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Util/Util
#
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Data/Data
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Parser/Parser
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Process/Process
#
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Network/Network

INCLUDEPATH += $$SRC_GROUP_DIR/OpenMesh-Core

INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Old/Old \
  $$SRC_GROUP_DIR/IQmol-Old/extras


INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Layer/Layer

INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Configurator/Configurator \
  $$SRC_GROUP_DIR/IQmol-Configurator/extras


INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk/yaml-cpp/include


HEADERS += \
  $$SRC_DIR/Viewer/Animator.h \
  $$SRC_DIR/Viewer/CameraDialog.h \
  $$SRC_DIR/Viewer/ShaderDialog.h \
  $$SRC_DIR/Viewer/Snapshot.h \
  $$SRC_DIR/Viewer/Viewer.h \
  $$SRC_DIR/Viewer/ViewerModel.h \
  $$SRC_DIR/Viewer/ViewerModelView.h \



SOURCES += \
  $$SRC_DIR/Viewer/Animator.C \
  $$SRC_DIR/Viewer/BuildAtomHandler.C \
  $$SRC_DIR/Viewer/BuildEfpFragmentHandler.C \
  $$SRC_DIR/Viewer/BuildFunctionalGroupHandler.C \
  $$SRC_DIR/Viewer/BuildHandler.C \
  $$SRC_DIR/Viewer/BuildMoleculeFragmentHandler.C \
  $$SRC_DIR/Viewer/CameraDialog.C \
  $$SRC_DIR/Viewer/Cursors.C \
  $$SRC_DIR/Viewer/GLSLmath.C \
  $$SRC_DIR/Viewer/ManipulatedFrameSetConstraint.C \
  $$SRC_DIR/Viewer/ManipulateHandler.C \
  $$SRC_DIR/Viewer/ManipulateSelectionHandler.C \
  $$SRC_DIR/Viewer/PovRayGen.C \
  $$SRC_DIR/Viewer/ReindexAtomsHandler.C \
  $$SRC_DIR/Viewer/SelectHandler.C \
  $$SRC_DIR/Viewer/ShaderDialog.C \
  $$SRC_DIR/Viewer/ShaderLibrary.C \
  $$SRC_DIR/Viewer/Snapshot.C \
  $$SRC_DIR/Viewer/Viewer.C \
  $$SRC_DIR/Viewer/ViewerModel.C \
  $$SRC_DIR/Viewer/ViewerModelView.C \


FORMS += \
  $$SRC_DIR/Viewer/CameraDialog.ui \
  $$SRC_DIR/Viewer/ShaderDialog.ui \
  $$SRC_DIR/Viewer/Snapshot.ui \


