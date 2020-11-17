
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

INCLUDEPATH += $$SRC_GROUP_DIR/OpenMesh-Core 


INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Util/Util  
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Data/Data  
#INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Process/Process  
#INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Parser/Parser  


INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk/yaml-cpp/include


HEADERS += \
  $$SRC_DIR/Parser/ParseFile.h \


SOURCES += \
  $$SRC_DIR/Parser/CartesianCoordinatesParser.C \
  $$SRC_DIR/Parser/CubeParser.C \
  $$SRC_DIR/Parser/EfpFragmentParser.C \
  $$SRC_DIR/Parser/ExternalChargesParser.C \
  $$SRC_DIR/Parser/FormattedCheckpointParser.C \
  $$SRC_DIR/Parser/GdmaParser.C \
  $$SRC_DIR/Parser/IQmolParser.C \
  $$SRC_DIR/Parser/MeshParser.C \
  $$SRC_DIR/Parser/OpenBabelParser.C \
  $$SRC_DIR/Parser/ParseFile.C \
  $$SRC_DIR/Parser/Parser.C \
  $$SRC_DIR/Parser/PovRayParser.C \
  $$SRC_DIR/Parser/QChemInputParser.C \
  $$SRC_DIR/Parser/QChemOutputParser.C \
  $$SRC_DIR/Parser/QChemPlotParser.C \
  $$SRC_DIR/Parser/XyzParser.C \
  $$SRC_DIR/Parser/YamlParser.C \
  $$SRC_DIR/Parser/ZMatrixCoordinatesParser.C \



