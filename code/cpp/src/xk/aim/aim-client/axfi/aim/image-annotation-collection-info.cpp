

//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "annotation-collection-info.h"

#include <QDataStream>

#include "AIMLib/stdafx.h"
#include "AIMLib/AimEnum.h"
#include "AIMLib/util/DateTime.h"
#include "AIMLib/entity/Entity.h"
#include "AIMLib/entity/AuditTrail.h"
#include "AIMLib/entity/CharacteristicQuantification.h"
#include "AIMLib/entity/ImagingObservationCharacteristic.h"
#include "AIMLib/entity/ImagingPhysicalEntityCharacteristic.h"
#include "AIMLib/entity/ImagingPhysicalEntity.h"
#include "AIMLib/entity/ImagingObservationEntity.h"
#include "AIMLib/entity/InferenceEntity.h"
#include "AIMLib/entity/Parameter.h"
#include "AIMLib/entity/Algorithm.h"
#include "AIMLib/entity/Dimension.h"
#include "AIMLib/entity/CalculationResult.h"
#include "AIMLib/entity/CalculationEntity.h"
#include "AIMLib/entity/AnnotationRoleEntity.h"
#include "AIMLib/entity/LesionObservationEntity.h"
#include "AIMLib/entity/GeneralLesionObservationEntity.h"
#include "AIMLib/entity/TimePointLesionObservationEntity.h"
#include "AIMLib/entity/TaskContextEntity.h"
#include "AIMLib/entity/AnnotationEntity.h"
//ImageAnnotation includes
#include "AIMLib/entity/ReferencedDicomObject.h"
#include "AIMLib/entity/GeneralImage.h"
#include "AIMLib/entity/ImagePlane.h"
#include "AIMLib/entity/Image.h"
#include "AIMLib/entity/ImageSeries.h"
#include "AIMLib/entity/ImageStudy.h"
#include "AIMLib/entity/ImageReferenceEntity.h"
#include "AIMLib/entity/UriImageReferenceEntity.h"
#include "AIMLib/entity/DicomImageReferenceEntity.h"
#include "AIMLib/entity/MarkupEntity.h"
#include "AIMLib/entity/GeometricShapeEntity.h"
#include "AIMLib/entity/TextAnnotationEntity.h"
#include "AIMLib/entity/SegmentationEntity.h"
#include "AIMLib/entity/DicomSegmentationEntity.h"
#include "AIMLib/entity/TwoDimensionSpatialCoordinate.h"
#include "AIMLib/entity/TwoDimensionGeometricShapeEntity.h"
#include "AIMLib/entity/ThreeDimensionSpatialCoordinate.h"
#include "AIMLib/entity/ThreeDimensionGeometricShapeEntity.h"

#include "AIMLib/statement/AnnotationStatement.h"
#include "AIMLib/statement/AbstractAnnotationStatement.h"
#include "AIMLib/statement/ImageAnnotationStatement.h"

#include "AIMLib/entity/AnnotationCollection.h"
#include "AIMLib/entity/ImageAnnotation.h"
#include "AIMLib/entity/Person.h"
#include "AIMLib/entity/ImageAnnotationCollection.h"


Image_Annotation_Collection_Info::Image_Annotation_Collection_Info()
{

}

AL_INIT(ImageAnnotationCollection)


void Image_Annotation_Collection_Info::supply_data(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
// qds << a_string_ << a_number_;


#define TEMP_MACRO(cast, type ,name) << cast name##_
// qds _Demo_Class_fm(TEMP_MACRO);
#undef TEMP_MACRO


}

void Image_Annotation_Collection_Info::absorb_data(const QByteArray& qba)
{
 QDataStream qds(qba);
// qds >> a_string_ >> a_number_;


#define TEMP_MACRO(cast, type ,name) >> cast name##_
// qds _Demo_Class_fm(TEMP_MACRO);
#undef TEMP_MACRO
}



