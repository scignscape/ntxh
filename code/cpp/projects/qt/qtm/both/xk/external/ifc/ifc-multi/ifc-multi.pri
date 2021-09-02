
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


QT += widgets

include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/occt.pri)

INCLUDEPATH += $$OCCT_INCLUDE_DIR/opencascade

INCLUDEPATH += /usr/include/libxml2/

CONFIG += staticlib


INCLUDEPATH += $$SRC_GROUP_DIR/ifc-2x3/schema-specific/extra
INCLUDEPATH += $$SRC_GROUP_DIR/ifc-4/schema-specific/extra
INCLUDEPATH += $$SRC_GROUP_DIR/ifc-4x1/schema-specific/extra
INCLUDEPATH += $$SRC_GROUP_DIR/ifc-4x2/schema-specific/extra
INCLUDEPATH += $$SRC_GROUP_DIR/ifc-4x3_rc1/schema-specific/extra
INCLUDEPATH += $$SRC_GROUP_DIR/ifc-4x3_rc2/schema-specific/extra
INCLUDEPATH += $$SRC_GROUP_DIR/ifc-4x3_rc3/schema-specific/extra
INCLUDEPATH += $$SRC_GROUP_DIR/ifc-4x3_rc4/schema-specific/extra


DEFINES += DEFAULT_IFC_FOLDER=\\\"$$ROOT_DIR/../dev/ifc\\\"


DEFINES += BOOST_ALL_NO_LIB BOOST_OPTIONAL_USE_OLD_DEFINITION_OF_NONE

DEFINES += BOOST_ALL_NO_LIB BOOST_OPTIONAL_USE_OLD_DEFINITION_OF_NONE 

DEFINES += HAS_SCHEMA_2x3  HAS_SCHEMA_4  HAS_SCHEMA_4x1  HAS_SCHEMA_4x2  \
  HAS_SCHEMA_4x3_rc1  HAS_SCHEMA_4x3_rc2  HAS_SCHEMA_4x3_rc3  HAS_SCHEMA_4x3_rc4

IFC_CORE_DIR = $$SRC_GROUP_DIR/core/src


# QT += opengl

INCLUDEPATH += $$SRC_DIR/schema-specific/extra  $$SRC_DIR/schema-specific/extra/extra
INCLUDEPATH +=  $$IFC_CORE_DIR/extra
INCLUDEPATH += ../hack/extra


HEADERS += \


SOURCES += \
  $$SRC_DIR/ifcconvert/IfcConvert.cpp \


#LIBS += -L$$TARGETSDIR  -lifc-2x3  -lifc-4  -lifc-4x1  -lifc-4x2   \
#  -lifc-4x3_rc1 -lifc-4x3_rc2 -lifc-4x3_rc3 -lifc-4x3_rc4

LIBS += $$TARGETSDIR/libifc-2x3.a \
  $$TARGETSDIR/libifc-4.a \
  $$TARGETSDIR/libifc-4x1.a \
  $$TARGETSDIR/libifc-4x2.a \
  $$TARGETSDIR/libifc-4x3_rc1.a \
  $$TARGETSDIR/libifc-4x3_rc2.a \
  $$TARGETSDIR/libifc-4x3_rc3.a \
  $$TARGETSDIR/libifc-4x3_rc4.a \



LIBS += \
 -lboost_program_options \
 -lboost_system \
 -lboost_regex \
 -lboost_thread \
 -lboost_date_time \
 -lboost_chrono \
 -lboost_atomic \
 -lpthread \
 -lxml2 \

LIBS += -L$$OCCT_LIB_DIR \
 -lTKernel \
 -lTKMath \
 -lTKBRep \
 -lTKGeomBase \
 -lTKGeomAlgo \
 -lTKG3d \
 -lTKG2d \
 -lTKShHealing \
 -lTKTopAlgo \
 -lTKMesh \
 -lTKPrim \
 -lTKBool \
 -lTKBO \
 -lTKFillet \
 -lTKSTEP \
 -lTKSTEPBase \
 -lTKSTEPAttr \
 -lTKXSBase \
 -lTKSTEP209 \
 -lTKIGES \
 -lTKOffset \
 -lTKHLR


