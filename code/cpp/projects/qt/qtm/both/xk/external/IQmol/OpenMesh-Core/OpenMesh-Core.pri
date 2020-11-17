
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

include($$ROOT_DIR/../preferred/sysr.pri)


INCLUDEPATH += $$SRC_GROUP_DIR  \


HEADERS += \


SOURCES += \
  $$SRC_DIR/OpenMesh/Core/Geometry/NormalConeT.cc \
  $$SRC_DIR/OpenMesh/Core/IO/BinaryHelper.cc \
  $$SRC_DIR/OpenMesh/Core/IO/IOManager.cc \
  $$SRC_DIR/OpenMesh/Core/IO/OMFormat.cc \
  $$SRC_DIR/OpenMesh/Core/IO/OMFormatT.cc \
  $$SRC_DIR/OpenMesh/Core/IO/reader/BaseReader.cc \
  $$SRC_DIR/OpenMesh/Core/IO/reader/OBJReader.cc \
  $$SRC_DIR/OpenMesh/Core/IO/reader/OFFReader.cc \
  $$SRC_DIR/OpenMesh/Core/IO/reader/OMReader.cc \
  $$SRC_DIR/OpenMesh/Core/IO/reader/PLYReader.cc \
  $$SRC_DIR/OpenMesh/Core/IO/reader/STLReader.cc \
  $$SRC_DIR/OpenMesh/Core/IO/writer/BaseWriter.cc \
  $$SRC_DIR/OpenMesh/Core/IO/writer/OBJWriter.cc \
  $$SRC_DIR/OpenMesh/Core/IO/writer/OFFWriter.cc \
  $$SRC_DIR/OpenMesh/Core/IO/writer/OMWriter.cc \
  $$SRC_DIR/OpenMesh/Core/IO/writer/PLYWriter.cc \
  $$SRC_DIR/OpenMesh/Core/IO/writer/STLWriter.cc \
  $$SRC_DIR/OpenMesh/Core/IO/writer/VTKWriter.cc \
  $$SRC_DIR/OpenMesh/Core/Mesh/ArrayKernel.cc \
  $$SRC_DIR/OpenMesh/Core/Mesh/ArrayKernelT.cc \
  $$SRC_DIR/OpenMesh/Core/Mesh/BaseKernel.cc \
  $$SRC_DIR/OpenMesh/Core/Mesh/PolyConnectivity.cc \
  $$SRC_DIR/OpenMesh/Core/Mesh/PolyMeshT.cc \
  $$SRC_DIR/OpenMesh/Core/Mesh/TriConnectivity.cc \
  $$SRC_DIR/OpenMesh/Core/Mesh/TriMeshT.cc \
  $$SRC_DIR/OpenMesh/Core/System/omstream.cc \
  $$SRC_DIR/OpenMesh/Core/Templates/newClass.cc \
  $$SRC_DIR/OpenMesh/Core/Templates/newClassT.cc \
  $$SRC_DIR/OpenMesh/Core/Utils/BaseProperty.cc \
  $$SRC_DIR/OpenMesh/Core/Utils/Endian.cc \
  $$SRC_DIR/OpenMesh/Core/Utils/RandomNumberGenerator.cc \
  $$SRC_DIR/OpenMesh/Core/Utils/SingletonT.cc \


