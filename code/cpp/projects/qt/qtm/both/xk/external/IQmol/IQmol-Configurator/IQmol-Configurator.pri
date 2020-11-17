
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += opengl xml sql


include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)

include($$ROOT_DIR/../preferred/openbabel.pri)


INCLUDEPATH += $$SRC_GROUP_DIR  \


INCLUDEPATH += $$SRC_DIR/Configurator   $$SRC_DIR/extras


INCLUDEPATH += $$SRC_GROUP_DIR/OpenMesh-Core 


INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Layer/Layer  
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Old/Old  
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Util/Util
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Data/Data
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Plot/Plot  
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Viewer/Viewer  




HEADERS += \


SOURCES += \
  $$SRC_DIR/Configurator/AxesConfigurator.C \
  $$SRC_DIR/Configurator/AxesMeshConfigurator.C \
  $$SRC_DIR/Configurator/BackgroundConfigurator.C \
  $$SRC_DIR/Configurator/ClippingPlaneConfigurator.C \
  $$SRC_DIR/Configurator/ConstraintConfigurator.C \
  $$SRC_DIR/Configurator/CubeDataConfigurator.C \
  $$SRC_DIR/Configurator/DipoleConfigurator.C \
  $$SRC_DIR/Configurator/EfpFragmentListConfigurator.C \
  $$SRC_DIR/Configurator/ExcitedStatesConfigurator.C \
  $$SRC_DIR/Configurator/FileConfigurator.C \
  $$SRC_DIR/Configurator/FrequenciesConfigurator.C \
  $$SRC_DIR/Configurator/GeminalOrbitalsConfigurator.C \
  $$SRC_DIR/Configurator/GeometryListConfigurator.C \
  $$SRC_DIR/Configurator/InfoConfigurator.C \
  $$SRC_DIR/Configurator/IsotopesConfigurator.C \
  $$SRC_DIR/Configurator/MolecularSurfacesConfigurator.C \
  $$SRC_DIR/Configurator/MoleculeConfigurator.C \
  $$SRC_DIR/Configurator/MullikenDecompositionsDialog.C \
  $$SRC_DIR/Configurator/NmrConfigurator.C \
  $$SRC_DIR/Configurator/OrbitalsConfigurator.C \
  $$SRC_DIR/Configurator/SurfaceConfigurator.C \
  $$SRC_DIR/Configurator/SymmetryConfigurator.C \


FORMS += \
  $$SRC_DIR/Configurator/AxesConfigurator.ui \
  $$SRC_DIR/Configurator/AxesMeshConfigurator.ui \
  $$SRC_DIR/Configurator/BackgroundConfigurator.ui \
  $$SRC_DIR/Configurator/ClippingPlaneConfigurator.ui \
  $$SRC_DIR/Configurator/CubeDataConfigurator.ui \
  $$SRC_DIR/Configurator/DipoleConfigurator.ui \
  $$SRC_DIR/Configurator/EfpFragmentListConfigurator.ui \
  $$SRC_DIR/Configurator/ExcitedStatesConfigurator.ui \
  $$SRC_DIR/Configurator/FileConfigurator.ui \
  $$SRC_DIR/Configurator/FrequenciesConfigurator.ui \
  $$SRC_DIR/Configurator/GeminalOrbitalsConfigurator.ui \
  $$SRC_DIR/Configurator/GeometryListConfigurator.ui \
  $$SRC_DIR/Configurator/InfoConfigurator.ui \
  $$SRC_DIR/Configurator/IsotopesConfigurator.ui \
  $$SRC_DIR/Configurator/MolecularSurfacesConfigurator.ui \
  $$SRC_DIR/Configurator/MoleculeConfigurator.ui \
  $$SRC_DIR/Configurator/MullikenDecompositionsDialog.ui \
  $$SRC_DIR/Configurator/NmrConfigurator.ui \
  $$SRC_DIR/Configurator/OrbitalsConfigurator.ui \
  $$SRC_DIR/Configurator/ScalarConstraintConfigurator.ui \
  $$SRC_DIR/Configurator/SurfaceConfigurator.ui \
  $$SRC_DIR/Configurator/SymmetryConfigurator.ui \
  $$SRC_DIR/Configurator/VectorConstraintConfigurator.ui \



