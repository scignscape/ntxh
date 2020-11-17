
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += opengl xml


include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)
include($$ROOT_DIR/../preferred/openbabel.pri)


INCLUDEPATH += $$SRC_DIR/Layer  $$SRC_DIR/extras

INCLUDEPATH += $$SRC_GROUP_DIR  \

INCLUDEPATH += $$SRC_GROUP_DIR/OpenMesh-Core  \

INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Configurator/Configurator \
  $$SRC_GROUP_DIR/IQmol-Old/extras \
  $$SRC_GROUP_DIR/IQmol-Configurator/extras


INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Data/Data
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Util/Util
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Viewer/Viewer
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Grid/Grid
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Old/Old
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Parser/Parser
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Process/Process



HEADERS += \


SOURCES += \
  $$SRC_DIR/Layer/AtomLayer.C \
  $$SRC_DIR/Layer/AxesLayer.C \
  $$SRC_DIR/Layer/AxesMeshLayer.C \
  $$SRC_DIR/Layer/BackgroundLayer.C \
  $$SRC_DIR/Layer/BondLayer.C \
  $$SRC_DIR/Layer/CanonicalOrbitalsLayer.C \
  $$SRC_DIR/Layer/ChargeLayer.C \
  $$SRC_DIR/Layer/ClippingPlaneLayer.C \
  $$SRC_DIR/Layer/ConstraintLayer.C \
  $$SRC_DIR/Layer/ContainerLayer.C \
  $$SRC_DIR/Layer/CubeDataLayer.C \
  $$SRC_DIR/Layer/DipoleLayer.C \
  $$SRC_DIR/Layer/DysonOrbitalsLayer.C \
  $$SRC_DIR/Layer/EfpFragmentLayer.C \
  $$SRC_DIR/Layer/EfpFragmentListLayer.C \
  $$SRC_DIR/Layer/ExcitedStatesLayer.C \
  $$SRC_DIR/Layer/FileLayer.C \
  $$SRC_DIR/Layer/FrequenciesLayer.C \
  $$SRC_DIR/Layer/GeminalOrbitalsLayer.C \
  $$SRC_DIR/Layer/GeometryLayer.C \
  $$SRC_DIR/Layer/GeometryListLayer.C \
  $$SRC_DIR/Layer/GroupLayer.C \
  $$SRC_DIR/Layer/InfoLayer.C \
  $$SRC_DIR/Layer/IsotopesLayer.C \
  $$SRC_DIR/Layer/Layer.C \
  $$SRC_DIR/Layer/LayerFactory.C \
  $$SRC_DIR/Layer/MolecularSurfacesLayer.C \
  $$SRC_DIR/Layer/MoleculeLayer.C \
  $$SRC_DIR/Layer/NaturalBondOrbitalsLayer.C \
  $$SRC_DIR/Layer/NaturalTransitionOrbitalsLayer.C \
  $$SRC_DIR/Layer/NmrLayer.C \
  $$SRC_DIR/Layer/OrbitalsLayer.C \
  $$SRC_DIR/Layer/PrimitiveLayer.C \
  $$SRC_DIR/Layer/RemLayer.C \
  $$SRC_DIR/Layer/SurfaceLayer.C \
  $$SRC_DIR/Layer/SymmetryLayer.C \


