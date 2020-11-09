
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui widgets xml #opengl sql network xml testlib svg

#INCLUDEPATH += $$SRC_GROUP_DIR

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

#include($$ROOT_DIR/../preferred/medInria-external.pri)

#DEFINES += DTKLOGEXPORT


#DTK_META_SRC_DIR =   $$SRC_DIR/devdtk/dtk/src

#
DTK_META_EXPORT_INCLUDES_DIR =   $$SRC_GROUP_DIR/dtk-meta-export-includes

#DTK_META_APP_DIR =   $$SRC_DIR/devdtk/dtk/app

#
INCLUDEPATH += $$SRC_DIR/inc
INCLUDEPATH += $$SRC_DIR/inc/axlCore


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

#
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCoreSupport/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc/dtkLog
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkMathSupport/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc


#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkLog
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkComposer
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkCore
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkMeta
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkGuiSupport
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkWidgets
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkDistributed
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkMath



HEADERS +=  \
  $$SRC_DIR/inc/axlCore/axlAbstractActor.h \
  $$SRC_DIR/inc/axlCore/axlAbstractActorField.h \
  $$SRC_DIR/inc/axlCore/axlAbstractCreatorProcess.h \
  $$SRC_DIR/inc/axlCore/axlAbstractCurve.h \
  $$SRC_DIR/inc/axlCore/axlAbstractCurveAlgebraic.h \
  $$SRC_DIR/inc/axlCore/axlAbstractCurveBSpline.h \
  $$SRC_DIR/inc/axlCore/axlAbstractCurveImplicit.h \
  $$SRC_DIR/inc/axlCore/axlAbstractCurveNurbs.h \
  $$SRC_DIR/inc/axlCore/axlAbstractCurveParametric.h \
  $$SRC_DIR/inc/axlCore/axlAbstractCurveRational.h \
  $$SRC_DIR/inc/axlCore/axlAbstractData.h \
  $$SRC_DIR/inc/axlCore/axlAbstractDataComposite.h \
  $$SRC_DIR/inc/axlCore/axlAbstractDataCompositeReader.h \
  $$SRC_DIR/inc/axlCore/axlAbstractDataCompositeWriter.h \
  $$SRC_DIR/inc/axlCore/axlAbstractDataConverter.h \
  $$SRC_DIR/inc/axlCore/axlAbstractDataReader.h \
  $$SRC_DIR/inc/axlCore/axlAbstractDataWriter.h \
  $$SRC_DIR/inc/axlCore/axlAbstractField.h \
  $$SRC_DIR/inc/axlCore/axlAbstractFieldDiscrete.h \
  $$SRC_DIR/inc/axlCore/axlAbstractFieldGenerator.h \
  $$SRC_DIR/inc/axlCore/axlAbstractFieldParametric.h \
  $$SRC_DIR/inc/axlCore/axlAbstractFieldParametricCurve.h \
  $$SRC_DIR/inc/axlCore/axlAbstractFieldParametricSurface.h \
  $$SRC_DIR/inc/axlCore/axlAbstractFieldParametricVolume.h \
  $$SRC_DIR/inc/axlCore/axlAbstractFieldSpatial.h \
  $$SRC_DIR/inc/axlCore/axlAbstractNumberType.h \
  $$SRC_DIR/inc/axlCore/axlAbstractProcess.h \
  $$SRC_DIR/inc/axlCore/axlAbstractSurface.h \
  $$SRC_DIR/inc/axlCore/axlAbstractSurfaceBSpline.h \
  $$SRC_DIR/inc/axlCore/axlAbstractSurfaceImplicit.h \
  $$SRC_DIR/inc/axlCore/axlAbstractSurfaceNurbs.h \
  $$SRC_DIR/inc/axlCore/axlAbstractSurfaceParametric.h \
  $$SRC_DIR/inc/axlCore/axlAbstractSurfaceRational.h \
  $$SRC_DIR/inc/axlCore/axlAbstractSurfaceTrimmed.h \
  $$SRC_DIR/inc/axlCore/axlAbstractView.h \
  $$SRC_DIR/inc/axlCore/axlAbstractVisitor.h \
  $$SRC_DIR/inc/axlCore/axlAbstractVisitorParametric.h \
  $$SRC_DIR/inc/axlCore/axlAbstractVolume.h \
  $$SRC_DIR/inc/axlCore/axlAbstractVolumeBSpline.h \
  $$SRC_DIR/inc/axlCore/axlAbstractVolumeDiscrete.h \
  $$SRC_DIR/inc/axlCore/axlAbstractVolumeImplicit.h \
  $$SRC_DIR/inc/axlCore/axlAbstractVolumeNurbs.h \
  $$SRC_DIR/inc/axlCore/axlAbstractVolumeParametric.h \
  $$SRC_DIR/inc/axlCore/axlAbstractVolumeRational.h \
  $$SRC_DIR/inc/axlCore/axlBarycenterProcess.h \
  $$SRC_DIR/inc/axlCore/axlCircleArc.h \
  $$SRC_DIR/inc/axlCore/axlCircleArcConverter.h \
  $$SRC_DIR/inc/axlCore/axlCircleArcCreator.h \
  $$SRC_DIR/inc/axlCore/axlCircleArcReader.h \
  $$SRC_DIR/inc/axlCore/axlCircleArcWriter.h \
  $$SRC_DIR/inc/axlCore/axlCompositeCurve.h \
  $$SRC_DIR/inc/axlCore/axlCompositeCurveConverter.h \
  $$SRC_DIR/inc/axlCore/axlCompositeCurveReader.h \
  $$SRC_DIR/inc/axlCore/axlCompositeCurveWriter.h \
  $$SRC_DIR/inc/axlCore/axlCone.h \
  $$SRC_DIR/inc/axlCore/axlConeCreator.h \
  $$SRC_DIR/inc/axlCore/axlConeParametric.h \
  $$SRC_DIR/inc/axlCore/axlConeReader.h \
  $$SRC_DIR/inc/axlCore/axlConeWriter.h \
  $$SRC_DIR/inc/axlCore/axlCoreExport2.h \
  $$SRC_DIR/inc/axlCore/axlCurveOnParamSurface.h \
  $$SRC_DIR/inc/axlCore/axlCurveOnParamSurfaceConverter.h \
  $$SRC_DIR/inc/axlCore/axlCylinder.h \
  $$SRC_DIR/inc/axlCore/axlCylinderCreator.h \
  $$SRC_DIR/inc/axlCore/axlCylinderParametric.h \
  $$SRC_DIR/inc/axlCore/axlCylinderParametricReader.h \
  $$SRC_DIR/inc/axlCore/axlCylinderParametricWriter.h \
  $$SRC_DIR/inc/axlCore/axlCylinderReader.h \
  $$SRC_DIR/inc/axlCore/axlCylinderWriter.h \
  $$SRC_DIR/inc/axlCore/axlDataDynamic.h \
  $$SRC_DIR/inc/axlCore/axlDataDynamicReader.h \
  $$SRC_DIR/inc/axlCore/axlDataDynamicWriter.h \
  $$SRC_DIR/inc/axlCore/axlDouble.h \
  $$SRC_DIR/inc/axlCore/axlEllipsoid.h \
  $$SRC_DIR/inc/axlCore/axlEllipsoidCreator.h \
  $$SRC_DIR/inc/axlCore/axlEllipsoidReader.h \
  $$SRC_DIR/inc/axlCore/axlEllipsoidWriter.h \
  $$SRC_DIR/inc/axlCore/axlFactoryRegister.h \
  $$SRC_DIR/inc/axlCore/axlFieldDiscrete.h \
  $$SRC_DIR/inc/axlCore/axlFieldDiscreteReader.h \
  $$SRC_DIR/inc/axlCore/axlFieldDiscreteWriter.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricCurve.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricCurveReader.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricCurveTangentVector.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricCurveTangentVectorCreator.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricCurveTangentVectorReader.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricCurveTangentVectorWriter.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricCurveWriter.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricNormalVector.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricNormalVectorCreator.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricSurface.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricSurfaceNormalVectorReader.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricSurfaceNormalVectorWriter.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricSurfaceReader.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricSurfaceTangentVector.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricSurfaceTangentVectorCreator.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricSurfaceTangentVectorReader.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricSurfaceTangentVectorWriter.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricSurfaceWriter.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricVolume.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricVolumeReader.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricVolumeTangentVector.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricVolumeTangentVectorCreator.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricVolumeTangentVectorReader.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricVolumeTangentVectorWriter.h \
  $$SRC_DIR/inc/axlCore/axlFieldParametricVolumeWriter.h \
  $$SRC_DIR/inc/axlCore/axlFieldReader.h \
  $$SRC_DIR/inc/axlCore/axlFieldReadersFactory.h \
  $$SRC_DIR/inc/axlCore/axlFieldSpatialCoordinates.h \
  $$SRC_DIR/inc/axlCore/axlFieldSpatialCoordinatesCreator.h \
  $$SRC_DIR/inc/axlCore/axlFieldSpatialCoordinatesReader.h \
  $$SRC_DIR/inc/axlCore/axlFieldSpatialCoordinatesWriter.h \
  $$SRC_DIR/inc/axlCore/axlFieldSpatialPointDistance.h \
  $$SRC_DIR/inc/axlCore/axlFieldSpatialPointDistanceCreator.h \
  $$SRC_DIR/inc/axlCore/axlFieldSpatialPointDistanceReader.h \
  $$SRC_DIR/inc/axlCore/axlFieldSpatialPointDistanceWriter.h \
  $$SRC_DIR/inc/axlCore/axlFieldSpatialWriter.h \
  $$SRC_DIR/inc/axlCore/axlFieldWritersFactory.h \
  $$SRC_DIR/inc/axlCore/axlFormat.h \
  $$SRC_DIR/inc/axlCore/axlInteger.h \
  $$SRC_DIR/inc/axlCore/axlIntersection.h \
  $$SRC_DIR/inc/axlCore/axlLight.h \
  $$SRC_DIR/inc/axlCore/axlLine.h \
  $$SRC_DIR/inc/axlCore/axlLineConverter.h \
  $$SRC_DIR/inc/axlCore/axlLineCreator.h \
  $$SRC_DIR/inc/axlCore/axlLineReader.h \
  $$SRC_DIR/inc/axlCore/axlLineWriter.h \
  $$SRC_DIR/inc/axlCore/axlMenuFactory.h \
  $$SRC_DIR/inc/axlCore/axlMesh.h \
  $$SRC_DIR/inc/axlCore/axlMeshReader.h \
  $$SRC_DIR/inc/axlCore/axlMeshWriter.h \
  $$SRC_DIR/inc/axlCore/axlOFFReader.h \
  $$SRC_DIR/inc/axlCore/axlOFFWriter.h \
  $$SRC_DIR/inc/axlCore/axlPlane.h \
  $$SRC_DIR/inc/axlCore/axlPlaneCreator.h \
  $$SRC_DIR/inc/axlCore/axlPlaneParametric.h \
  $$SRC_DIR/inc/axlCore/axlPlaneParametricReader.h \
  $$SRC_DIR/inc/axlCore/axlPlaneParametricWriter.h \
  $$SRC_DIR/inc/axlCore/axlPlaneReader.h \
  $$SRC_DIR/inc/axlCore/axlPlaneWriter.h \
  $$SRC_DIR/inc/axlCore/axlPoint.h \
  $$SRC_DIR/inc/axlCore/axlPointConverter.h \
  \#?  $$SRC_DIR/inc/axlCore/axlPointReader.h \
  $$SRC_DIR/inc/axlCore/axlPointSet.h \
  $$SRC_DIR/inc/axlCore/axlPointSetConverter.h \
  \#?  $$SRC_DIR/inc/axlCore/axlPointSetReader.h \
  $$SRC_DIR/inc/axlCore/axlPointSetWriter.h \
  $$SRC_DIR/inc/axlCore/axlPointWriter.h \
  $$SRC_DIR/inc/axlCore/axlProcessProjection.h \
  $$SRC_DIR/inc/axlCore/axlReader.h \
  $$SRC_DIR/inc/axlCore/axlSamplingCurve.h \
  $$SRC_DIR/inc/axlCore/axlShape.h \
  $$SRC_DIR/inc/axlCore/axlShapeBSpline.h \
  $$SRC_DIR/inc/axlCore/axlShapeBSplineConverter.h \
  $$SRC_DIR/inc/axlCore/axlShapeBSplineReader.h \
  $$SRC_DIR/inc/axlCore/axlShapeBSplineWriter.h \
  $$SRC_DIR/inc/axlCore/axlShapeConverter.h \
  $$SRC_DIR/inc/axlCore/axlShapeReader.h \
  $$SRC_DIR/inc/axlCore/axlShapeWriter.h \
  $$SRC_DIR/inc/axlCore/axlSphere.h \
  $$SRC_DIR/inc/axlCore/axlSphereConverter.h \
  $$SRC_DIR/inc/axlCore/axlSphereCreator.h \
  $$SRC_DIR/inc/axlCore/axlSphereReader.h \
  $$SRC_DIR/inc/axlCore/axlSphereWriter.h \
  $$SRC_DIR/inc/axlCore/axlSurfaceParametricOffset.h \
  $$SRC_DIR/inc/axlCore/axlSurfaceParametricOffsetConverter.h \
  $$SRC_DIR/inc/axlCore/axlSurfaceRevolution.h \
  $$SRC_DIR/inc/axlCore/axlSurfaceRevolutionConverter.h \
  $$SRC_DIR/inc/axlCore/axlSurfaceRevolutionParametric.h \
  $$SRC_DIR/inc/axlCore/axlSurfaceRevolutionParametricConverter.h \
  $$SRC_DIR/inc/axlCore/axlSurfaceRevolutionParametricReader.h \
  $$SRC_DIR/inc/axlCore/axlSurfaceRevolutionParametricWriter.h \
  $$SRC_DIR/inc/axlCore/axlSurfaceRevolutionReader.h \
  $$SRC_DIR/inc/axlCore/axlSurfaceRevolutionWriter.h \
  $$SRC_DIR/inc/axlCore/axlTabulatedCylinder.h \
  $$SRC_DIR/inc/axlCore/axlTabulatedCylinderConverter.h \
  $$SRC_DIR/inc/axlCore/axlTabulatedCylinderReader.h \
  $$SRC_DIR/inc/axlCore/axlTabulatedCylinderWriter.h \
  $$SRC_DIR/inc/axlCore/axlToMesh.h \
  $$SRC_DIR/inc/axlCore/axlTorus.h \
  $$SRC_DIR/inc/axlCore/axlTorusCreator.h \
  $$SRC_DIR/inc/axlCore/axlTorusParametric.h \
  $$SRC_DIR/inc/axlCore/axlTorusParametricReader.h \
  $$SRC_DIR/inc/axlCore/axlTorusParametricWriter.h \
  $$SRC_DIR/inc/axlCore/axlTorusReader.h \
  $$SRC_DIR/inc/axlCore/axlTorusWriter.h \
  $$SRC_DIR/inc/axlCore/axlTrimmedParametricSurface.h \
  $$SRC_DIR/inc/axlCore/axlViewController.h \
  $$SRC_DIR/inc/axlCore/axlViewDefault.h \
  $$SRC_DIR/inc/axlCore/axlWriter.h \


SOURCES +=  \
  $$SRC_DIR/axlAbstractActor.cpp \
  $$SRC_DIR/axlAbstractActorField.cpp \
  $$SRC_DIR/axlAbstractCreatorProcess.cpp \
  $$SRC_DIR/axlAbstractCurve.cpp \
  $$SRC_DIR/axlAbstractCurveAlgebraic.cpp \
  $$SRC_DIR/axlAbstractCurveBSpline.cpp \
  $$SRC_DIR/axlAbstractCurveImplicit.cpp \
  $$SRC_DIR/axlAbstractCurveNurbs.cpp \
  $$SRC_DIR/axlAbstractCurveParametric.cpp \
  $$SRC_DIR/axlAbstractCurveRational.cpp \
  $$SRC_DIR/axlAbstractData.cpp \
  $$SRC_DIR/axlAbstractDataComposite.cpp \
  $$SRC_DIR/axlAbstractDataCompositeReader.cpp \
  $$SRC_DIR/axlAbstractDataCompositeWriter.cpp \
  $$SRC_DIR/axlAbstractDataConverter.cpp \
  $$SRC_DIR/axlAbstractDataReader.cpp \
  $$SRC_DIR/axlAbstractDataWriter.cpp \
  $$SRC_DIR/axlAbstractField.cpp \
  $$SRC_DIR/axlAbstractFieldDiscrete.cpp \
  $$SRC_DIR/axlAbstractFieldGenerator.cpp \
  $$SRC_DIR/axlAbstractFieldParametric.cpp \
  $$SRC_DIR/axlAbstractFieldParametricCurve.cpp \
  $$SRC_DIR/axlAbstractFieldParametricSurface.cpp \
  $$SRC_DIR/axlAbstractFieldParametricVolume.cpp \
  $$SRC_DIR/axlAbstractFieldSpatial.cpp \
  $$SRC_DIR/axlAbstractProcess.cpp \
  $$SRC_DIR/axlAbstractSurface.cpp \
  $$SRC_DIR/axlAbstractSurfaceBSpline.cpp \
  $$SRC_DIR/axlAbstractSurfaceImplicit.cpp \
  $$SRC_DIR/axlAbstractSurfaceNurbs.cpp \
  $$SRC_DIR/axlAbstractSurfaceParametric.cpp \
  $$SRC_DIR/axlAbstractSurfaceRational.cpp \
  $$SRC_DIR/axlAbstractSurfaceTrimmed.cpp \
  $$SRC_DIR/axlAbstractView.cpp \
  $$SRC_DIR/axlAbstractVisitor.cpp \
  $$SRC_DIR/axlAbstractVisitorParametric.cpp \
  $$SRC_DIR/axlAbstractVolume.cpp \
  $$SRC_DIR/axlAbstractVolumeBSpline.cpp \
  $$SRC_DIR/axlAbstractVolumeDiscrete.cpp \
  $$SRC_DIR/axlAbstractVolumeImplicit.cpp \
  $$SRC_DIR/axlAbstractVolumeNurbs.cpp \
  $$SRC_DIR/axlAbstractVolumeParametric.cpp \
  $$SRC_DIR/axlAbstractVolumeRational.cpp \
  $$SRC_DIR/axlBarycenterProcess.cpp \
  $$SRC_DIR/axlCircleArc.cpp \
  $$SRC_DIR/axlCircleArcConverter.cpp \
  $$SRC_DIR/axlCircleArcCreator.cpp \
  $$SRC_DIR/axlCircleArcReader.cpp \
  $$SRC_DIR/axlCircleArcWriter.cpp \
  $$SRC_DIR/axlCompositeCurve.cpp \
  $$SRC_DIR/axlCompositeCurveConverter.cpp \
  $$SRC_DIR/axlCompositeCurveReader.cpp \
  $$SRC_DIR/axlCompositeCurveWriter.cpp \
  $$SRC_DIR/axlCone.cpp \
  $$SRC_DIR/axlConeCreator.cpp \
  $$SRC_DIR/axlConeParametric.cpp \
  $$SRC_DIR/axlConeReader.cpp \
  $$SRC_DIR/axlConeWriter.cpp \
  $$SRC_DIR/axlCurveOnParamSurface.cpp \
  $$SRC_DIR/axlCurveOnParamSurfaceConverter.cpp \
  $$SRC_DIR/axlCylinder.cpp \
  $$SRC_DIR/axlCylinderCreator.cpp \
  $$SRC_DIR/axlCylinderParametric.cpp \
  $$SRC_DIR/axlCylinderParametricReader.cpp \
  $$SRC_DIR/axlCylinderParametricWriter.cpp \
  $$SRC_DIR/axlCylinderReader.cpp \
  $$SRC_DIR/axlCylinderWriter.cpp \
  $$SRC_DIR/axlDataDynamic.cpp \
  $$SRC_DIR/axlDataDynamicReader.cpp \
  $$SRC_DIR/axlDataDynamicWriter.cpp \
  $$SRC_DIR/axlDouble.cpp \
  $$SRC_DIR/axlEllipsoid.cpp \
  $$SRC_DIR/axlEllipsoidCreator.cpp \
  $$SRC_DIR/axlEllipsoidReader.cpp \
  $$SRC_DIR/axlEllipsoidWriter.cpp \
  $$SRC_DIR/axlFactoryRegister.cpp \
  $$SRC_DIR/axlFieldDiscrete.cpp \
  $$SRC_DIR/axlFieldDiscreteReader.cpp \
  $$SRC_DIR/axlFieldDiscreteWriter.cpp \
  $$SRC_DIR/axlFieldParametricCurve.cpp \
  $$SRC_DIR/axlFieldParametricCurveReader.cpp \
  $$SRC_DIR/axlFieldParametricCurveTangentVector.cpp \
  $$SRC_DIR/axlFieldParametricCurveTangentVectorCreator.cpp \
  $$SRC_DIR/axlFieldParametricCurveTangentVectorReader.cpp \
  $$SRC_DIR/axlFieldParametricCurveTangentVectorWriter.cpp \
  $$SRC_DIR/axlFieldParametricCurveWriter.cpp \
  $$SRC_DIR/axlFieldParametricNormalVector.cpp \
  $$SRC_DIR/axlFieldParametricNormalVectorCreator.cpp \
  $$SRC_DIR/axlFieldParametricSurface.cpp \
  $$SRC_DIR/axlFieldParametricSurfaceNormalVectorReader.cpp \
  $$SRC_DIR/axlFieldParametricSurfaceNormalVectorWriter.cpp \
  $$SRC_DIR/axlFieldParametricSurfaceReader.cpp \
  $$SRC_DIR/axlFieldParametricSurfaceTangentVector.cpp \
  $$SRC_DIR/axlFieldParametricSurfaceTangentVectorCreator.cpp \
  $$SRC_DIR/axlFieldParametricSurfaceTangentVectorReader.cpp \
  $$SRC_DIR/axlFieldParametricSurfaceTangentVectorWriter.cpp \
  $$SRC_DIR/axlFieldParametricSurfaceWriter.cpp \
  $$SRC_DIR/axlFieldParametricVolume.cpp \
  $$SRC_DIR/axlFieldParametricVolumeReader.cpp \
  $$SRC_DIR/axlFieldParametricVolumeTangentVector.cpp \
  $$SRC_DIR/axlFieldParametricVolumeTangentVectorCreator.cpp \
  $$SRC_DIR/axlFieldParametricVolumeTangentVectorReader.cpp \
  $$SRC_DIR/axlFieldParametricVolumeTangentVectorWriter.cpp \
  $$SRC_DIR/axlFieldParametricVolumeWriter.cpp \
  $$SRC_DIR/axlFieldReader.cpp \
  $$SRC_DIR/axlFieldReadersFactory.cpp \
  $$SRC_DIR/axlFieldSpatialCoordinates.cpp \
  $$SRC_DIR/axlFieldSpatialCoordinatesCreator.cpp \
  $$SRC_DIR/axlFieldSpatialCoordinatesReader.cpp \
  $$SRC_DIR/axlFieldSpatialCoordinatesWriter.cpp \
  $$SRC_DIR/axlFieldSpatialPointDistance.cpp \
  $$SRC_DIR/axlFieldSpatialPointDistanceCreator.cpp \
  $$SRC_DIR/axlFieldSpatialPointDistanceReader.cpp \
  $$SRC_DIR/axlFieldSpatialPointDistanceWriter.cpp \
  $$SRC_DIR/axlFieldSpatialWriter.cpp \
  $$SRC_DIR/axlFieldWritersFactory.cpp \
  $$SRC_DIR/axlInteger.cpp \
  $$SRC_DIR/axlIntersection.cpp \
  $$SRC_DIR/axlLight.cpp \
  $$SRC_DIR/axlLine.cpp \
  $$SRC_DIR/axlLineConverter.cpp \
  $$SRC_DIR/axlLineCreator.cpp \
  $$SRC_DIR/axlLineReader.cpp \
  $$SRC_DIR/axlLineWriter.cpp \
  $$SRC_DIR/axlMenuFactory.cpp \
  $$SRC_DIR/axlMesh.cpp \
  $$SRC_DIR/axlMeshReader.cpp \
  $$SRC_DIR/axlMeshWriter.cpp \
  $$SRC_DIR/axlOFFReader.cpp \
  $$SRC_DIR/axlOFFWriter.cpp \
  $$SRC_DIR/axlPlane.cpp \
  $$SRC_DIR/axlPlaneCreator.cpp \
  $$SRC_DIR/axlPlaneParametric.cpp \
  $$SRC_DIR/axlPlaneParametricReader.cpp \
  $$SRC_DIR/axlPlaneParametricWriter.cpp \
  $$SRC_DIR/axlPlaneReader.cpp \
  $$SRC_DIR/axlPlaneWriter.cpp \
  $$SRC_DIR/axlPoint.cpp \
  $$SRC_DIR/axlPointConverter.cpp \
  $$SRC_DIR/axlPointReader.cpp \
  $$SRC_DIR/axlPointSet.cpp \
  $$SRC_DIR/axlPointSetConverter.cpp \
  \#? $$SRC_DIR/axlPointSetReader.cpp \
  $$SRC_DIR/axlPointSetWriter.cpp \
  $$SRC_DIR/axlPointWriter.cpp \
  $$SRC_DIR/axlProcessProjection.cpp \
  $$SRC_DIR/axlReader.cpp \
  \#? $$SRC_DIR/axlSamplingCurve.cpp \
  $$SRC_DIR/axlShape.cpp \
  $$SRC_DIR/axlShapeBSpline.cpp \
  $$SRC_DIR/axlShapeBSplineConverter.cpp \
  $$SRC_DIR/axlShapeBSplineReader.cpp \
  $$SRC_DIR/axlShapeBSplineWriter.cpp \
  $$SRC_DIR/axlShapeConverter.cpp \
  $$SRC_DIR/axlShapeReader.cpp \
  $$SRC_DIR/axlShapeWriter.cpp \
  $$SRC_DIR/axlSphere.cpp \
  $$SRC_DIR/axlSphereConverter.cpp \
  $$SRC_DIR/axlSphereCreator.cpp \
  $$SRC_DIR/axlSphereReader.cpp \
  $$SRC_DIR/axlSphereWriter.cpp \
  $$SRC_DIR/axlSurfaceParametricOffset.cpp \
  $$SRC_DIR/axlSurfaceParametricOffsetConverter.cpp \
  $$SRC_DIR/axlSurfaceRevolution.cpp \
  $$SRC_DIR/axlSurfaceRevolutionConverter.cpp \
  $$SRC_DIR/axlSurfaceRevolutionParametric.cpp \
  $$SRC_DIR/axlSurfaceRevolutionParametricConverter.cpp \
  $$SRC_DIR/axlSurfaceRevolutionParametricReader.cpp \
  $$SRC_DIR/axlSurfaceRevolutionParametricWriter.cpp \
  $$SRC_DIR/axlSurfaceRevolutionReader.cpp \
  $$SRC_DIR/axlSurfaceRevolutionWriter.cpp \
  $$SRC_DIR/axlTabulatedCylinder.cpp \
  $$SRC_DIR/axlTabulatedCylinderConverter.cpp \
  $$SRC_DIR/axlTabulatedCylinderReader.cpp \
  $$SRC_DIR/axlTabulatedCylinderWriter.cpp \
  $$SRC_DIR/axlToMesh.cpp \
  $$SRC_DIR/axlTorus.cpp \
  $$SRC_DIR/axlTorusCreator.cpp \
  $$SRC_DIR/axlTorusParametric.cpp \
  $$SRC_DIR/axlTorusParametricReader.cpp \
  $$SRC_DIR/axlTorusParametricWriter.cpp \
  $$SRC_DIR/axlTorusReader.cpp \
  $$SRC_DIR/axlTorusWriter.cpp \
  $$SRC_DIR/axlTrimmedParametricSurface.cpp \
  $$SRC_DIR/axlViewController.cpp \
  $$SRC_DIR/axlViewDefault.cpp \
  $$SRC_DIR/axlWriter.cpp \




