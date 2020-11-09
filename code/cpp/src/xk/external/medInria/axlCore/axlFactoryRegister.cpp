/* axlFactoryRegister.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlFactoryRegister.h"


#include <axlCore/axlAbstractView.h>
#include <dtkCoreSupport/dtkGlobal.h>
#include <dtkCoreSupport/dtkPluginManager.h>



////Converters
#include <axlCore/axlPointConverter.h>
#include <axlCore/axlLineConverter.h>
#include <axlCore/axlSphereConverter.h>
#include <axlCore/axlCircleArcConverter.h>
#include <axlCore/axlSurfaceParametricOffsetConverter.h>
#include <axlCore/axlShapeConverter.h>
#include <axlCore/axlSurfaceRevolutionConverter.h>

#include <axlCore/axlSurfaceRevolutionParametricConverter.h>
#include <axlCore/axlCompositeCurveConverter.h>
#include <axlCore/axlTabulatedCylinderConverter.h>
//#include <axlCore/axlAbstractDataCompositeConverter.h>
#include <axlCore/axlShapeBSplineConverter.h>


////Process Creator
#include <axlCore/axlConeCreator.h>
#include <axlCore/axlCylinderCreator.h>
#include <axlCore/axlEllipsoidCreator.h>
#include <axlCore/axlPlaneCreator.h>
#include <axlCore/axlLineCreator.h>
#include <axlCore/axlSphereCreator.h>
#include <axlCore/axlTorusCreator.h>
#include <axlCore/axlCircleArcCreator.h>


////Other kind of process
#include <axlCore/axlBarycenterProcess.h>
#include <axlCore/axlIntersection.h>
#include <axlCore/axlToMesh.h>
#include <axlCore/axlProcessProjection.h>

////fields types
#include <axlCore/axlFieldSpatialPointDistance.h>
#include <axlCore/axlFieldParametricSurface.h>
//#include <axlCore/axlFieldSpatialDirection.h>
#include <axlCore/axlFieldSpatialCoordinates.h>
#include <axlCore/axlFieldParametricVolume.h>
#include <axlCore/axlFieldParametricNormalVector.h>
#include <axlCore/axlFieldParametricCurveTangentVector.h>
#include <axlCore/axlFieldParametricSurfaceTangentVector.h>
#include <axlCore/axlFieldParametricVolumeTangentVector.h>
#include <axlCore/axlFieldDiscrete.h>

////process fields Creator
//#include <axlCore/axlProcessZScalarField.h>
#include <axlCore/axlFieldSpatialCoordinatesCreator.h>
//#include <axlCore/axlProcessTangentVectorField.h>
//#include <axlCore/axlProcessSpatialDistanceField.h>
#include <axlCore/axlFieldSpatialPointDistanceCreator.h>
#include <axlCore/axlFieldParametricNormalVectorCreator.h>
#include <axlCore/axlFieldParametricCurveTangentVectorCreator.h>
#include <axlCore/axlFieldParametricSurfaceTangentVectorCreator.h>
#include <axlCore/axlFieldParametricVolumeTangentVectorCreator.h>

////factories
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractDataReader.h>


////writer
//#include <axlCore/axlFieldSpatialWriter.h>
#include <axlCore/axlOFFWriter.h>
#include "axlConeWriter.h"
#include "axlCylinderWriter.h"
#include "axlCylinderParametricWriter.h"
#include "axlCircleArcWriter.h"
#include "axlEllipsoidWriter.h"
#include "axlLineWriter.h"
#include "axlPlaneWriter.h"
#include "axlPlaneParametricWriter.h"
#include "axlTorusWriter.h"
#include "axlTorusParametricWriter.h"
#include "axlShapeWriter.h"
#include "axlPointWriter.h"
#include "axlSphereWriter.h"
#include "axlMeshWriter.h"
#include "axlDataDynamicWriter.h"
#include "axlAbstractDataCompositeWriter.h"
#include "axlSurfaceRevolutionWriter.h"

#include "axlSurfaceRevolutionParametricWriter.h"
#include <axlCore/axlFieldDiscreteWriter.h>
#include "axlCompositeCurveWriter.h"
#include "axlTabulatedCylinderWriter.h"
#include <axlCore/axlShapeBSplineWriter.h>


////reader
//#include <axlCore/axlFieldReader.h>
#include <axlCore/axlOFFReader.h>
#include <axlCore/axlAbstractDataCompositeReader.h>
#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlConeReader.h>
#include <axlCore/axlCylinderReader.h>
#include <axlCore/axlCylinderParametricReader.h>
#include <axlCore/axlEllipsoidReader.h>
#include <axlCore/axlLineReader.h>
#include <axlCore/axlPlaneReader.h>
#include <axlCore/axlPlaneParametricReader.h>
#include <axlCore/axlMeshReader.h>
#include <axlCore/axlSphereReader.h>
#include <axlCore/axlPointReader.h>
#include <axlCore/axlTorusReader.h>
#include <axlCore/axlTorusParametricReader.h>
#include <axlCore/axlCircleArcReader.h>
#include <axlCore/axlShapeReader.h>
#include <axlCore/axlFieldDiscreteReader.h>
#include <axlCore/axlProcessProjection.h>
#include <axlCore/axlSurfaceRevolutionReader.h>

#include <axlCore/axlSurfaceRevolutionParametricReader.h>
#include <axlCore/axlCompositeCurveReader.h>
#include <axlCore/axlTabulatedCylinderReader.h>

#include <axlCore/axlShapeBSplineReader.h>


//basic data
#include "axlPoint.h"
#include "axlCone.h"
#include "axlCylinder.h"
#include "axlEllipsoid.h"
#include "axlCircleArc.h"
#include "axlPlane.h"
#include "axlTorus.h"
#include "axlSphere.h"
#include "axlLine.h"
#include "axlDataDynamic.h"
#include "axlMesh.h"
#include "axlShape.h"
#include "axlSurfaceRevolution.h"

#include "axlSurfaceRevolutionParametric.h"
#include "axlCompositeCurve.h"
#include "axlTabulatedCylinder.h"
#include "axlCurveOnParamSurface.h"
#include "axlTrimmedParametricSurface.h"
#include "axlShapeBSpline.h"


//for parameters
#include "axlInteger.h"
#include "axlDouble.h"


// /////////////////////////////////////////////////////////////////
// axlFactoryRegister implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 *
 *
 */
axlFactoryRegister::axlFactoryRegister(void)
{
}



//! Destroys the axlFactoryRegister
/*!
 *
 */
axlFactoryRegister::~axlFactoryRegister(void)
{
}

void axlFactoryRegister::initialized()
{

    //basic object
    dtkAbstractDataFactory::instance()->registerDataType("axlPoint", createaxlPoint);
    dtkAbstractDataFactory::instance()->registerDataType("axlCylinder", createaxlCylinder);
    dtkAbstractDataFactory::instance()->registerDataType("axlCone", createaxlCone);
    dtkAbstractDataFactory::instance()->registerDataType("axlEllipsoid", createaxlEllipsoid);
    dtkAbstractDataFactory::instance()->registerDataType("axlCircleArc", createaxlCircleArc);
    dtkAbstractDataFactory::instance()->registerDataType("axlPlane", createaxlPlane);
    dtkAbstractDataFactory::instance()->registerDataType("axlTorus", createaxlTorus);
    dtkAbstractDataFactory::instance()->registerDataType("axlSphere", createaxlSphere);
    dtkAbstractDataFactory::instance()->registerDataType("axlLine", createaxlLine);
    dtkAbstractDataFactory::instance()->registerDataType("axlMesh", createaxlMesh);
    dtkAbstractDataFactory::instance()->registerDataType("axlDataDynamic", createAxlDataDynamic);
    dtkAbstractDataFactory::instance()->registerDataType("axlInteger", createaxlInteger);
    dtkAbstractDataFactory::instance()->registerDataType("axlDouble", createaxlDouble);
    dtkAbstractDataFactory::instance()->registerDataType("axlSurfaceRevolution", createaxlSurfaceRevolution);
    axlShapeBSpline::registered();

    //Intialisation of Converters of atomic Data
    axlSurfaceParametricOffsetConverter::registered();
    axlCircleArcConverter::registered();
    axlLineConverter::registered();
    axlPointConverter::registered();
    axlSphereConverter::registered();
    axlShapeConverter::registered();
	axlSurfaceRevolutionConverter::registered();
	axlSurfaceRevolutionParametricConverter::registered();
	axlCompositeCurveConverter::registered();
	axlTabulatedCylinderConverter::registered();
	//axlAbstractDataCompositeConverter::registered();
    axlShapeBSplineConverter::registered();

    //register axlCore processes
    axlConeCreator::registered();
    axlCylinderCreator::registered();
    axlEllipsoidCreator::registered();
    axlPlaneCreator::registered();
    dtkAbstractProcessFactory::instance()->registerProcessType("axlLineCreator", createaxlLineCreator);
    dtkAbstractProcessFactory::instance()->registerProcessType("axlSphereCreator", createaxlSphereCreator);
    dtkAbstractProcessFactory::instance()->registerProcessType("axlTorusCreator", createaxlTorusCreator);
    dtkAbstractProcessFactory::instance()->registerProcessType("axlCircleArcCreator", createaxlCircleArcCreator);
    dtkAbstractProcessFactory::instance()->registerProcessType("axlBarycenterProcess", createaxlBarycenterProcess, "axlAbstractProcess");
    dtkAbstractProcessFactory::instance()->registerProcessType("axlIntersection", createaxlIntersectionProcess, "axlAbstractProcess");
    dtkAbstractProcessFactory::instance()->registerProcessType("axlToMesh", createaxlToMeshProcess, "MeshProcess");
    //axlProcessProjection::registered();


    //register some fields type
    dtkAbstractDataFactory::instance()->registerDataType("axlFieldParametricSurface", createaxlFieldParametricSurface);
    dtkAbstractDataFactory::instance()->registerDataType("axlFieldSpatialPointDistance", createAxlFieldSpatialPointDistance);
    dtkAbstractDataFactory::instance()->registerDataType("axlFieldSpatialCoordinates", createaxlFieldSpatialCoordinates);
    dtkAbstractDataFactory::instance()->registerDataType("axlFieldParametricVolume", createaxlFieldParametricVolume);
    dtkAbstractDataFactory::instance()->registerDataType("axlFieldParametricNormalVector", createaxlFieldParametricNormalVector);
    dtkAbstractDataFactory::instance()->registerDataType("axlFieldParametricCurveTangentVector", createaxlFieldParametricCurveTangentVector);
    dtkAbstractDataFactory::instance()->registerDataType("axlFieldParametricSurfaceTangentVector", createaxlFieldParametricSurfaceTangentVector);
    dtkAbstractDataFactory::instance()->registerDataType("axlFieldParametricVolumeTangentVector", createaxlFieldParametricVolumeTangentVector);
    dtkAbstractDataFactory::instance()->registerDataType("axlFieldDiscrete",createaxlFieldDiscrete);
    //register some field process creator
    dtkAbstractProcessFactory::instance()->registerProcessType("axlFieldSpatialCoordinatesCreator", createaxlFieldSpatialCoordinatesCreator, "axlAbstractProcess");
    dtkAbstractProcessFactory::instance()->registerProcessType("axlFieldSpatialPointDistanceCreator", createaxlFieldSpatialPointDistanceCreator,"axlAbstractProcess");
    dtkAbstractProcessFactory::instance()->registerProcessType("axlFieldParametricNormalVectorCreator", createaxlFieldParametricNormalVectorCreator,"axlAbstractProcess");
    dtkAbstractProcessFactory::instance()->registerProcessType("axlFieldParametricCurveTangentVectorCreator", createaxlFieldParametricCurveTangentVectorCreator,"axlAbstractProcess");
    dtkAbstractProcessFactory::instance()->registerProcessType("axlFieldParametricSurfaceTangentVectorCreator", createaxlFieldParametricSurfaceTangentVectorCreator,"axlAbstractProcess");
    dtkAbstractProcessFactory::instance()->registerProcessType("axlFieldParametricVolumeTangentVectorCreator", createaxlFieldParametricVolumeTangentVectorCreator,"axlAbstractProcess");

    //register some readers
    axlOFFReader::registered();
    axlConeReader::registered();
    //dtkAbstractDataFactory::instance()->registerDataReaderType("axlConeReader",QStringList(), createaxlConeReader);
    axlCylinderReader::registered();
    //dtkAbstractDataFactory::instance()->registerDataReaderType("axlCylinderReader",QStringList(), createaxlCylinderReader);
    axlCylinderParametricReader::registered();
    //dtkAbstractDataFactory::instance()->registerDataReaderType("axlCylinderParametricReader",QStringList(), createaxlCylinderParametricReader);
    dtkAbstractDataFactory::instance()->registerDataReaderType("axlEllipsoidReader",QStringList(), createaxlEllipsoidReader);
    dtkAbstractDataFactory::instance()->registerDataReaderType("axlLineReader",QStringList(), createaxlLineReader);
    dtkAbstractDataFactory::instance()->registerDataReaderType("axlPlaneReader",QStringList(), createaxlPlaneReader);
    dtkAbstractDataFactory::instance()->registerDataReaderType("axlPlaneParametricReader",QStringList(), createaxlPlaneParametricReader);
    dtkAbstractDataFactory::instance()->registerDataReaderType("axlPointReader",QStringList(), createaxlPointReader);
    dtkAbstractDataFactory::instance()->registerDataReaderType("axlSphereReader",QStringList(), createaxlSphereReader);
    dtkAbstractDataFactory::instance()->registerDataReaderType("axlTorusReader",QStringList(), createaxlTorusReader);
    dtkAbstractDataFactory::instance()->registerDataReaderType("axlTorusParametricReader",QStringList(), createaxlTorusParametricReader);
    dtkAbstractDataFactory::instance()->registerDataReaderType("axlCircleArcReader",QStringList(), createaxlCircleArcReader);
    dtkAbstractDataFactory::instance()->registerDataReaderType("axlShapeReader",QStringList(), createaxlShapeReader);
    dtkAbstractDataFactory::instance()->registerDataReaderType("axlMeshReader",QStringList(), createaxlMeshReader);
	dtkAbstractDataFactory::instance()->registerDataReaderType("axlSurfaceRevolutionReader",QStringList(), createaxlSurfaceRevolutionReader);
	dtkAbstractDataFactory::instance()->registerDataReaderType("axlSurfaceRevolutionParametricReader",QStringList(), createaxlSurfaceRevolutionParametricReader);
	dtkAbstractDataFactory::instance()->registerDataReaderType("axlCompositeCurveReader",QStringList(),createaxlCompositeCurveReader);
	dtkAbstractDataFactory::instance()->registerDataReaderType("axlTabulatedCylinderReader",QStringList(),createaxlTabulatedCylinderReader);
    axlFieldDiscreteReader::registered();
    axlShapeBSplineReader::registered();

    //register some writers
    axlOFFWriter::registered();
    dtkAbstractDataFactory::instance()->registerDataWriterType("axlConeWriter", QStringList(), createaxlConeWriter);
    dtkAbstractDataFactory::instance()->registerDataWriterType("axlCylinderWriter", QStringList(), createaxlCylinderWriter);
    dtkAbstractDataFactory::instance()->registerDataWriterType("axlCylinderParametricWriter", QStringList(), createaxlCylinderParametricWriter);
    dtkAbstractDataFactory::instance()->registerDataWriterType("axlEllipsoidWriter", QStringList(), createaxlEllipsoidWriter);
    dtkAbstractDataFactory::instance()->registerDataWriterType("axlLineWriter", QStringList(), createaxlLineWriter);
    dtkAbstractDataFactory::instance()->registerDataWriterType("axlPlaneWriter", QStringList(), createaxlPlaneWriter);
    dtkAbstractDataFactory::instance()->registerDataWriterType("axlPlaneParametricWriter", QStringList(), createaxlPlaneParametricWriter);
    dtkAbstractDataFactory::instance()->registerDataWriterType("axlPointWriter", QStringList(), createaxlPointWriter);
    dtkAbstractDataFactory::instance()->registerDataWriterType("axlSphereWriter", QStringList(), createaxlSphereWriter);
    dtkAbstractDataFactory::instance()->registerDataWriterType("axlTorusWriter", QStringList(), createaxlTorusWriter);
    dtkAbstractDataFactory::instance()->registerDataWriterType("axlTorusParametricWriter", QStringList(), createaxlTorusParametricWriter);
    dtkAbstractDataFactory::instance()->registerDataWriterType("axlCircleArcWriter", QStringList(), createaxlCircleArcWriter);
    dtkAbstractDataFactory::instance()->registerDataWriterType("axlShapeWriter", QStringList(), createaxlShapeWriter);
	dtkAbstractDataFactory::instance()->registerDataWriterType("axlSurfaceRevolutionWriter", QStringList(), createaxlSurfaceRevolutionWriter);
	dtkAbstractDataFactory::instance()->registerDataWriterType("axlSurfaceRevolutionParametricWriter", QStringList(), createaxlSurfaceRevolutionParametricWriter);
	dtkAbstractDataFactory::instance()->registerDataWriterType("axlCompositeCurveWriter", QStringList(), createaxlCompositeCurveWriter);
	dtkAbstractDataFactory::instance()->registerDataWriterType("axlTabulatedCylinderWriter", QStringList(), createaxlTabulatedCylinderWriter);
    axlFieldDiscreteWriter::registered();


    //basic object
    dtkAbstractDataFactory::instance()->registerDataType("axlPoint", createaxlPoint);
    dtkAbstractDataFactory::instance()->registerDataType("axlCylinder", createaxlCylinder);
    dtkAbstractDataFactory::instance()->registerDataType("axlCone", createaxlCone);
    dtkAbstractDataFactory::instance()->registerDataType("axlEllipsoid", createaxlEllipsoid);
    dtkAbstractDataFactory::instance()->registerDataType("axlCircleArc", createaxlCircleArc);
    dtkAbstractDataFactory::instance()->registerDataType("axlPlane", createaxlPlane);
    dtkAbstractDataFactory::instance()->registerDataType("axlTorus", createaxlTorus);
    dtkAbstractDataFactory::instance()->registerDataType("axlSphere", createaxlSphere);
    dtkAbstractDataFactory::instance()->registerDataType("axlLine", createaxlLine);
    dtkAbstractDataFactory::instance()->registerDataType("axlMesh", createaxlMesh);
    dtkAbstractDataFactory::instance()->registerDataType("axlDataDynamic", createAxlDataDynamic);
    dtkAbstractDataFactory::instance()->registerDataType("axlInteger", createaxlInteger);
    dtkAbstractDataFactory::instance()->registerDataType("axlDouble", createaxlDouble);
	dtkAbstractDataFactory::instance()->registerDataType("axlSurfaceRevolution", createaxlSurfaceRevolution);
	dtkAbstractDataFactory::instance()->registerDataType("axlSurfaceRevolutionParametric", createaxlSurfaceRevolutionParametric);
	dtkAbstractDataFactory::instance()->registerDataType("axlCompositeCurve",createaxlCompositeCurve);
	dtkAbstractDataFactory::instance()->registerDataType("axlTabulatedCylinder",createaxlTabulatedCylinder);
	dtkAbstractDataFactory::instance()->registerDataType("axlCurveOnParamSurface",createaxlCurveOnParamSurface);
	dtkAbstractDataFactory::instance()->registerDataType("axlTrimmedParametricSurface",createaxlTrimmedParametricSurface);
    axlShapeBSplineWriter::registered();

}


void axlFactoryRegister::uninitialized()
{

}


// /////////////////////////////////////////////////////////////////
// axlFactoryRegister documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlFactoryRegister
 *
 *  \brief Register some readers, writers and other data and processes of axlCore in factories.
 *
 *
 */

