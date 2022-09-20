

//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "axfi-annotation-environment.h"

#include <QDataStream>


#include "axfi-annotation-folder.h"

#include "AIMLib/AIMCommon.h"

#include "AIMLib/external/CD.h"
#include "AIMLib/external/II.h"
#include "AIMLib/AimHeaders.h"

#include "AIMLib/entity/ImageAnnotationCollection.h"
#include "AIMLib/operations/BaseModel.h"
#include "AIMLib/operations/DcmModel.h"
#include "AIMLib/operations/XmlModel.h"

#include "AIMLib/entity/AnnotationCollection.h"

#include "aim/image-annotation-collection-info.h"


AXFI_Annotation_Environment::AXFI_Annotation_Environment()
 // :  axfi_annotation_group_(new AXFI_Annotation_Group)
{

}

AXFI_Annotation_Folder* AXFI_Annotation_Environment::add_folder(QString path)
{
 AXFI_Annotation_Folder* result = new AXFI_Annotation_Folder;
 result->read_path(path);
 folders_[path] = result;
 return result;
}

Image_Annotation_Collection_Info*
  AXFI_Annotation_Environment::load_xml_annotations(QString file_path)
{
 aim_lib::XmlModel xmlm;
 aim_lib::AnnotationCollection* ac = xmlm.ReadAnnotationCollectionFromFile
   (file_path.toStdString());


 aim_lib::AnnotationCollection::AnnotationCollectionType act = ac->GetAnnotationCollectionType();
 if(act == aim_lib::AnnotationCollection::ACT_ImageAnnotationCollection)
 {
  Image_Annotation_Collection_Info* result = new Image_Annotation_Collection_Info;
  aim_lib::ImageAnnotationCollection* iac = static_cast<aim_lib::ImageAnnotationCollection*>(ac);
  result->alinit(iac);
  result->equipment().alinit(const_cast<aim_lib::Equipment*>(iac->GetEquipment()));
  result->user().alinit(const_cast<aim_lib::User*>(iac->GetUser()));
  result->set_description(QString::fromStdString(iac->GetDescription()));
  result->set_datetime(convert_aim_datetime(iac->GetDateTime()));
  return result;
 }
 return nullptr;
}

QDateTime AXFI_Annotation_Environment::convert_aim_datetime(const aim_lib::DateTime& dt)
{
 QDateTime result;
 result.setDate(QDate(dt.GetYear(), dt.GetMonth(), dt.GetDay()));
 result.setTime(QTime(dt.GetHour(), dt.GetMinute(), dt.GetSecond()));
 return result;
}

void AXFI_Annotation_Environment::supply_data(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
// qds << a_string_ << a_number_;


#define TEMP_MACRO(cast, type ,name) << cast name##_
// qds _Demo_Class_fm(TEMP_MACRO);
#undef TEMP_MACRO


}

void AXFI_Annotation_Environment::absorb_data(const QByteArray& qba)
{
 QDataStream qds(qba);
// qds >> a_string_ >> a_number_;


#define TEMP_MACRO(cast, type ,name) >> cast name##_
// qds _Demo_Class_fm(TEMP_MACRO);
#undef TEMP_MACRO
}



