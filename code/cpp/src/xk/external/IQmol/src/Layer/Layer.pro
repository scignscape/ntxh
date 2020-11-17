LIB = Layer
CONFIG += lib
include(../common.pri)

INCLUDEPATH += ../Data ../Util ../Configurator ../Parser ../Process ../Main ../Viewer ../Old \
               ../OpenMesh/src ../Grid
     

SOURCES = \
   $$PWD/AtomLayer.C \
   $$PWD/AxesLayer.C \
   $$PWD/AxesMeshLayer.C \
   $$PWD/BackgroundLayer.C \
   $$PWD/BondLayer.C \
   $$PWD/CanonicalOrbitalsLayer.C \
   $$PWD/ChargeLayer.C \
   $$PWD/ClippingPlaneLayer.C \
   $$PWD/ConstraintLayer.C \
   $$PWD/ContainerLayer.C \
   $$PWD/CubeDataLayer.C \
   $$PWD/DipoleLayer.C \
   $$PWD/DysonOrbitalsLayer.C \
   $$PWD/GeminalOrbitalsLayer.C \
   $$PWD/GeometryLayer.C \
   $$PWD/GeometryListLayer.C \
   $$PWD/EfpFragmentLayer.C \
   $$PWD/EfpFragmentListLayer.C \
   $$PWD/ExcitedStatesLayer.C \
   $$PWD/FileLayer.C \
   $$PWD/FrequenciesLayer.C \
   $$PWD/GroupLayer.C \
   $$PWD/InfoLayer.C \
   $$PWD/IsotopesLayer.C \
   $$PWD/Layer.C \
   $$PWD/LayerFactory.C \
   $$PWD/MoleculeLayer.C \
   $$PWD/MolecularSurfacesLayer.C \
   $$PWD/NaturalBondOrbitalsLayer.C \
   $$PWD/NaturalTransitionOrbitalsLayer.C \
   $$PWD/NmrLayer.C \
   $$PWD/OrbitalsLayer.C \
   $$PWD/PrimitiveLayer.C \
   $$PWD/RemLayer.C \
   $$PWD/SurfaceLayer.C \
   $$PWD/SymmetryLayer.C \


HEADERS = \
   $$PWD/AtomLayer.h \
   $$PWD/AxesLayer.h \
   $$PWD/AxesMeshLayer.h \
   $$PWD/BackgroundLayer.h \
   $$PWD/BondLayer.h \
   $$PWD/CanonicalOrbitalsLayer.h \
   $$PWD/ChargeLayer.h \
   $$PWD/ClippingPlaneLayer.h \
   $$PWD/ConstraintLayer.h \
   $$PWD/ContainerLayer.h \
   $$PWD/CubeDataLayer.h \
   $$PWD/DipoleLayer.h \
   $$PWD/DysonOrbitalsLayer.h \
   $$PWD/GeminalOrbitalsLayer.h \
   $$PWD/GeometryLayer.h \
   $$PWD/GeometryListLayer.h \
   $$PWD/GlobalLayer.h \
   $$PWD/EfpFragmentLayer.h \
   $$PWD/EfpFragmentListLayer.h \
   $$PWD/ExcitedStatesLayer.h \
   $$PWD/FileLayer.h \
   $$PWD/FrequenciesLayer.h \
   $$PWD/GLObjectLayer.h \
   $$PWD/GroupLayer.h \
   $$PWD/InfoLayer.h \
   $$PWD/IsotopesLayer.h \
   $$PWD/Layer.h \
   $$PWD/LayerFactory.h \
   $$PWD/MoleculeLayer.h \
   $$PWD/MolecularSurfacesLayer.h \
   $$PWD/NaturalBondOrbitalsLayer.h \
   $$PWD/NaturalTransitionOrbitalsLayer.h \
   $$PWD/NmrLayer.h \
   $$PWD/OrbitalsLayer.h \
   $$PWD/PrimitiveLayer.h \
   $$PWD/RemLayer.h \
   $$PWD/SurfaceLayer.h \
   $$PWD/SymmetryLayer.h \
