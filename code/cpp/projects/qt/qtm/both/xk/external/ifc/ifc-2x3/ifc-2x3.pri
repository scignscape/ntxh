
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

#TEMPLATE = app

QT += widgets

include($$ROOT_DIR/../preferred/sysr.pri)


INCLUDEPATH += /usr/include/oce/
INCLUDEPATH += /usr/include/libxml2/


DEFINES = BOOST_ALL_NO_LIB BOOST_OPTIONAL_USE_OLD_DEFINITION_OF_NONE

DEFINES += BOOST_ALL_NO_LIB BOOST_OPTIONAL_USE_OLD_DEFINITION_OF_NONE 

DEFINES += HAS_SCHEMA_2x3 

DEFINES += IfcSchema=Ifc2x3

IFC_CORE_DIR = $$SRC_GROUP_DIR/core/src


# QT += opengl

INCLUDEPATH += $$SRC_DIR/schema-specific/extra  $$SRC_DIR/schema-specific/extra/extra
INCLUDEPATH +=  $$IFC_CORE_DIR/extra
INCLUDEPATH += ../hack/extra


HEADERS += \
  $$IFC_CORE_DIR/ifcgeom/IfcGeom.h \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomElement.h \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomIteratorImplementation.h \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomIteratorSettings.h \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomRepresentation.h \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomShapeType.h \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomTree.h \
  $$IFC_CORE_DIR/ifcgeom/IfcRegister.h \
  $$IFC_CORE_DIR/ifcgeom/IfcRegisterConvertCurve.h \
  $$IFC_CORE_DIR/ifcgeom/IfcRegisterConvertFace.h \
  $$IFC_CORE_DIR/ifcgeom/IfcRegisterConvertShape.h \
  $$IFC_CORE_DIR/ifcgeom/IfcRegisterConvertShapes.h \
  $$IFC_CORE_DIR/ifcgeom/IfcRegisterConvertWire.h \
  $$IFC_CORE_DIR/ifcgeom/IfcRegisterCreateCache.h \
  $$IFC_CORE_DIR/ifcgeom/IfcRegisterDef.h \
  $$IFC_CORE_DIR/ifcgeom/IfcRegisterGeomHeader.h \
  $$IFC_CORE_DIR/ifcgeom/IfcRegisterPurgeCache.h \
  $$IFC_CORE_DIR/ifcgeom/IfcRegisterShapeType.h \
  $$IFC_CORE_DIR/ifcgeom/IfcRegisterUndef.h \
  $$IFC_CORE_DIR/ifcgeom/IfcRepresentationShapeItem.h \
  $$IFC_CORE_DIR/ifcgeom/ifc_geom_api.h \
  $$IFC_CORE_DIR/ifcgeom_schema_agnostic/IfcGeomFilter.h \
  $$IFC_CORE_DIR/ifcgeom_schema_agnostic/IfcGeomIterator.h \
  $$IFC_CORE_DIR/ifcgeom_schema_agnostic/IfcGeomMaterial.h \
  $$IFC_CORE_DIR/ifcgeom_schema_agnostic/IfcGeomRenderStyles.h \
  $$IFC_CORE_DIR/ifcgeom_schema_agnostic/IteratorImplementation.h \
  $$IFC_CORE_DIR/ifcgeom_schema_agnostic/Kernel.h \
  $$IFC_CORE_DIR/ifcgeom_schema_agnostic/Serialization.h \
  $$IFC_CORE_DIR/ifcparse/Argument.h \
  $$IFC_CORE_DIR/ifcparse/ArgumentType.h \
  $$IFC_CORE_DIR/ifcparse/IfcBaseClass.h \
  $$IFC_CORE_DIR/ifcparse/IfcCharacterDecoder.h \
  $$IFC_CORE_DIR/ifcparse/IfcEntityInstanceData.h \
  $$IFC_CORE_DIR/ifcparse/IfcEntityList.h \
  $$IFC_CORE_DIR/ifcparse/IfcException.h \
  $$IFC_CORE_DIR/ifcparse/IfcFile.h \
  $$IFC_CORE_DIR/ifcparse/IfcGlobalId.h \
  $$IFC_CORE_DIR/ifcparse/IfcHierarchyHelper.h \
  $$IFC_CORE_DIR/ifcparse/IfcLogger.h \
  $$IFC_CORE_DIR/ifcparse/IfcParse.h \
  $$IFC_CORE_DIR/ifcparse/IfcSIPrefix.h \
  $$IFC_CORE_DIR/ifcparse/IfcSchema.h \
  $$IFC_CORE_DIR/ifcparse/IfcSpfHeader.h \
  $$IFC_CORE_DIR/ifcparse/IfcSpfStream.h \
  $$IFC_CORE_DIR/ifcparse/IfcWrite.h \
  $$IFC_CORE_DIR/ifcparse/ifc_parse_api.h \
  $$IFC_CORE_DIR/ifcparse/macros.h \
  $$IFC_CORE_DIR/ifcparse/utils.h \
  $$IFC_CORE_DIR/serializers/ColladaSerializer.h \
  $$IFC_CORE_DIR/serializers/GeometrySerializer.h \
  $$IFC_CORE_DIR/serializers/GltfSerializer.h \
  $$IFC_CORE_DIR/serializers/IgesSerializer.h \
  $$IFC_CORE_DIR/serializers/OpenCascadeBasedSerializer.h \
  $$IFC_CORE_DIR/serializers/Serializer.h \
  $$IFC_CORE_DIR/serializers/StepSerializer.h \
  $$IFC_CORE_DIR/serializers/SvgSerializer.h \
  $$IFC_CORE_DIR/serializers/WavefrontObjSerializer.h \
  $$IFC_CORE_DIR/serializers/XmlSerializer.h \
  $$IFC_CORE_DIR/serializers/schema_dependent/_XmlSerializer.h \
  $$IFC_CORE_DIR/serializers/util.h


SOURCES += \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomCurves.cpp \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomFaces.cpp \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomFunctions.cpp \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomHelpers.cpp \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomIteratorImplementation.cpp \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomRenderStyles.cpp \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomRepresentation.cpp \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomSerialisation.cpp \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomShapes.cpp \
  $$IFC_CORE_DIR/ifcgeom/IfcGeomWires.cpp \
  $$IFC_CORE_DIR/ifcgeom/IfcRegister.cpp \



SOURCES += \
  \# $$IFC_CORE_DIR/ifcconvert/IfcConvert.cpp \
  $$IFC_CORE_DIR/ifcgeom_schema_agnostic/IfcGeomMaterial.cpp \
  $$IFC_CORE_DIR/ifcgeom_schema_agnostic/IteratorImplementation.cpp \
  $$IFC_CORE_DIR/ifcgeom_schema_agnostic/Kernel.cpp \
  $$IFC_CORE_DIR/ifcgeom_schema_agnostic/Serialization.cpp \
  $$IFC_CORE_DIR/ifcgeom_schema_agnostic/SurfaceStyle.cpp \
  $$IFC_CORE_DIR/ifcparse/IfcCharacterDecoder.cpp \
  $$IFC_CORE_DIR/ifcparse/IfcGlobalId.cpp \
  $$IFC_CORE_DIR/ifcparse/IfcHierarchyHelper.cpp \
  $$IFC_CORE_DIR/ifcparse/IfcLogger.cpp \
  $$IFC_CORE_DIR/ifcparse/IfcParse.cpp \
  $$IFC_CORE_DIR/ifcparse/IfcSIPrefix.cpp \
  $$IFC_CORE_DIR/ifcparse/IfcSchema.cpp \
  $$IFC_CORE_DIR/ifcparse/IfcSpfHeader.cpp \
  $$IFC_CORE_DIR/ifcparse/IfcUtil.cpp \
  $$IFC_CORE_DIR/ifcparse/IfcWrite.cpp \
  $$IFC_CORE_DIR/ifcparse/parse_ifcxml.cpp \
  $$IFC_CORE_DIR/serializers/ColladaSerializer.cpp \
  $$IFC_CORE_DIR/serializers/GltfSerializer.cpp \
  $$IFC_CORE_DIR/serializers/OpenCascadeBasedSerializer.cpp \
  $$IFC_CORE_DIR/serializers/SvgSerializer.cpp \
  $$IFC_CORE_DIR/serializers/WavefrontObjSerializer.cpp \
  $$IFC_CORE_DIR/serializers/XmlSerializer.cpp \
  $$IFC_CORE_DIR/serializers/util.cpp \
  $$IFC_CORE_DIR/serializers/schema_dependent/_XmlSerializer.cpp \


HEADERS += \
  $$SRC_DIR/schema-specific/ifcparse/Ifc2x3.h \


SOURCES += \
  $$SRC_DIR/schema-specific/ifcparse/Ifc2x3.cpp \
  $$SRC_DIR/schema-specific/ifcparse/Ifc2x3-schema.cpp \


LIBS += \
 -lboost_program_options \
 -lboost_system\
 -lboost_program_options\
 -lboost_regex\
 -lboost_thread\
 -lboost_date_time\
 -lboost_chrono\
 -lboost_atomic\
 -lpthread\
 -lxml2\
 -lTKernel\
 -lTKMath\
 -lTKBRep\
 -lTKGeomBase\
 -lTKGeomAlgo\
 -lTKG3d\
 -lTKG2d\
 -lTKShHealing\
 -lTKTopAlgo\
 -lTKMesh\
 -lTKPrim\
 -lTKBool\
 -lTKBO\
 -lTKFillet\
 -lTKSTEP\
 -lTKSTEPBase\
 -lTKSTEPAttr\
 -lTKXSBase\
 -lTKSTEP209\
 -lTKIGES\
 -lTKOffset\
 -lTKHLR


