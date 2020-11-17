
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

include($$ROOT_DIR/../preferred/sysr.pri)


INCLUDEPATH += $$SRC_GROUP_DIR  \

INCLUDEPATH += $$SRC_GROUP_DIR/OpenMesh-Core  \


HEADERS += \


SOURCES += \
  $$SRC_DIR/OpenMesh/Tools/Decimater/BaseDecimaterT.cc \
  $$SRC_DIR/OpenMesh/Tools/Decimater/DecimaterT.cc \
  $$SRC_DIR/OpenMesh/Tools/Decimater/McDecimaterT.cc \
  $$SRC_DIR/OpenMesh/Tools/Decimater/MixedDecimaterT.cc \
  $$SRC_DIR/OpenMesh/Tools/Decimater/ModAspectRatioT.cc \
  $$SRC_DIR/OpenMesh/Tools/Decimater/ModEdgeLengthT.cc \
  $$SRC_DIR/OpenMesh/Tools/Decimater/ModHausdorffT.cc \
  $$SRC_DIR/OpenMesh/Tools/Decimater/ModProgMeshT.cc \
  $$SRC_DIR/OpenMesh/Tools/Decimater/ModQuadricT.cc \
  $$SRC_DIR/OpenMesh/Tools/Decimater/Observer.cc \
  $$SRC_DIR/OpenMesh/Tools/Smoother/JacobiLaplaceSmootherT.cc \
  $$SRC_DIR/OpenMesh/Tools/Smoother/LaplaceSmootherT.cc \
  $$SRC_DIR/OpenMesh/Tools/Smoother/SmootherT.cc \
  $$SRC_DIR/OpenMesh/Tools/Subdivider/Adaptive/Composite/CompositeT.cc \
  $$SRC_DIR/OpenMesh/Tools/Subdivider/Adaptive/Composite/RulesT.cc \
  $$SRC_DIR/OpenMesh/Tools/Subdivider/Uniform/CatmullClarkT.cc \
  $$SRC_DIR/OpenMesh/Tools/Subdivider/Uniform/Composite/CompositeT.cc \
  $$SRC_DIR/OpenMesh/Tools/Utils/getopt.c \
  $$SRC_DIR/OpenMesh/Tools/Utils/conio.cc \
  $$SRC_DIR/OpenMesh/Tools/Utils/Gnuplot.cc \
  $$SRC_DIR/OpenMesh/Tools/Utils/MeshCheckerT.cc \
  $$SRC_DIR/OpenMesh/Tools/Utils/StripifierT.cc \
  $$SRC_DIR/OpenMesh/Tools/Utils/Timer.cc \
  $$SRC_DIR/OpenMesh/Tools/VDPM/VFront.cc \
  $$SRC_DIR/OpenMesh/Tools/VDPM/VHierarchy.cc \
  $$SRC_DIR/OpenMesh/Tools/VDPM/VHierarchyNodeIndex.cc \
  $$SRC_DIR/OpenMesh/Tools/VDPM/VHierarchyWindow.cc \
  $$SRC_DIR/OpenMesh/Tools/VDPM/ViewingParameters.cc \


