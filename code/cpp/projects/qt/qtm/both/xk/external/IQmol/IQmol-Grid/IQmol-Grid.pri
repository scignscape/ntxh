
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += opengl xml


include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)

UI_DIR = $$SRC_DIR/uis-gen/any-build


INCLUDEPATH += $$SRC_GROUP_DIR  \


INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Util/Util
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Data/Data

INCLUDEPATH += $$SRC_GROUP_DIR/OpenMesh-Core
INCLUDEPATH += $$SRC_GROUP_DIR/OpenMesh-Tools


HEADERS += \
  $$SRC_DIR/Grid/BasisEvaluator.h \
  $$SRC_DIR/Grid/BoundingBoxDialog.h \
  $$SRC_DIR/Grid/DensityEvaluator.h \
  $$SRC_DIR/Grid/GridEvaluator.h \
  $$SRC_DIR/Grid/GridInfoDialog.h \
  $$SRC_DIR/Grid/GridProduct.h \
  $$SRC_DIR/Grid/MarchingCubes.h \
  $$SRC_DIR/Grid/MeshDecimator.h \
  $$SRC_DIR/Grid/MolecularGridEvaluator.h \
  $$SRC_DIR/Grid/OrbitalEvaluator.h \
  $$SRC_DIR/Grid/SurfaceGenerator.h \



SOURCES += \
  $$SRC_DIR/Grid/BasisEvaluator.C \
  $$SRC_DIR/Grid/BoundingBoxDialog.C \
  $$SRC_DIR/Grid/DensityEvaluator.C \
  $$SRC_DIR/Grid/GridEvaluator.C \
  $$SRC_DIR/Grid/GridInfoDialog.C \
  $$SRC_DIR/Grid/GridProduct.C \
  $$SRC_DIR/Grid/Lebedev.C \
  $$SRC_DIR/Grid/MarchingCubes.C \
  $$SRC_DIR/Grid/MeshDecimator.C \
  $$SRC_DIR/Grid/MolecularGridEvaluator.C \
  $$SRC_DIR/Grid/OrbitalEvaluator.C \
  $$SRC_DIR/Grid/Spline.C \
  $$SRC_DIR/Grid/SurfaceGenerator.C \


FORMS += \
  $$SRC_DIR/Grid/BoundingBoxDialog.ui \
  $$SRC_DIR/Grid/GridInfoDialog.ui \





