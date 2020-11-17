
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += opengl xml


include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)
include($$ROOT_DIR/../preferred/openbabel.pri)


INCLUDEPATH += $$SRC_GROUP_DIR  \


INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Util/Util

INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Data/Data

INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Parser/Parser



INCLUDEPATH += $$SRC_GROUP_DIR/OpenMesh-Core

INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk/yaml-cpp/include



HEADERS += \


SOURCES += \
  $$SRC_DIR/Data/Atom.C \
  $$SRC_DIR/Data/AtomicProperty.C \
  $$SRC_DIR/Data/Bank.C \
  $$SRC_DIR/Data/CanonicalOrbitals.C \
  $$SRC_DIR/Data/ChargeMultiplicity.C \
  $$SRC_DIR/Data/Constraint.C \
  $$SRC_DIR/Data/Data.C \
  $$SRC_DIR/Data/DataFactory.C \
  $$SRC_DIR/Data/Density.C \
  $$SRC_DIR/Data/EfpFragment.C \
  $$SRC_DIR/Data/EfpFragmentLibrary.C \
  $$SRC_DIR/Data/ElectronicTransition.C \
  $$SRC_DIR/Data/Energy.C \
  $$SRC_DIR/Data/ExcitedStates.C \
  $$SRC_DIR/Data/File.C \
  $$SRC_DIR/Data/Frequencies.C \
  $$SRC_DIR/Data/GeminalOrbitals.C \
  $$SRC_DIR/Data/Geometry.C \
  $$SRC_DIR/Data/GeometryList.C \
  $$SRC_DIR/Data/GridData.C \
  $$SRC_DIR/Data/GridSize.C \
  $$SRC_DIR/Data/Hessian.C \
  $$SRC_DIR/Data/Mesh.C \
  $$SRC_DIR/Data/MultipoleExpansion.C \
  $$SRC_DIR/Data/NaturalBondOrbitals.C \
  $$SRC_DIR/Data/NaturalTransitionOrbitals.C \
  $$SRC_DIR/Data/NmrData.C \
  $$SRC_DIR/Data/NmrReference.C \
  $$SRC_DIR/Data/NmrReferenceLibrary.C \
  $$SRC_DIR/Data/Orbitals.C \
  $$SRC_DIR/Data/OrbitalsList.C \
  $$SRC_DIR/Data/OrbitalSymmetries.C \
  $$SRC_DIR/Data/PointCharge.C \
  $$SRC_DIR/Data/PointGroup.C \
  $$SRC_DIR/Data/PovRay.C \
  $$SRC_DIR/Data/RemSectionData.C \
  $$SRC_DIR/Data/Shell.C \
  $$SRC_DIR/Data/ShellList.C \
  $$SRC_DIR/Data/Surface.C \
  $$SRC_DIR/Data/SurfaceInfo.C \
  $$SRC_DIR/Data/SurfaceType.C \
  $$SRC_DIR/Data/VibrationalMode.C \
  $$SRC_DIR/Data/YamlNode.C \



