
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include <QDebug>

#include <QFileInfo>
#include <QDirIterator>

#include "AIMLib/AIMCommon.h"

#include "AIMLib/external/CD.h"
#include "AIMLib/external/II.h"
#include "AIMLib/AimHeaders.h"

#include "AIMLib/entity/ImageAnnotationCollection.h"

#include "AIMLib/operations/BaseModel.h"
#include "AIMLib/operations/DcmModel.h"
#include "AIMLib/operations/XmlModel.h"

#include "AIMLib/entity/SegmentationEntity.h"

#include <typeinfo>
//entity/TimePointLesionObservationEntity.h

enum TestDocumentType{
 DT_DICOM,
 DT_XML,
 DT_ALL
};

using namespace aim_lib;
using namespace iso_21090;


#define DICOM_DOC_NAME "outdoc.dcm"
#define DICOM_DOC_NAME2 "outdoc2.dcm"
#define XML_DOC_NAME "outdoc.xml"
#define XML_DOC_NAME2 "outdoc2.xml"


#ifdef __GNUG__
#include <cstdlib>
#include <memory>
#include <cxxabi.h>

std::string demangle(const char* name) {

    int status = -4; // some arbitrary value to eliminate the compiler warning

    // enable c++11 by passing the flag -std=c++11 to g++
    std::unique_ptr<char, void(*)(void*)> res {
        abi::__cxa_demangle(name, NULL, NULL, &status),
        std::free
    };

    return (status==0) ? res.get() : name ;
}

#else

// does nothing if not g++
std::string demangle(const char* name) {
    return name;
}

#endif


AnnotationCollection* test_load_annotations(TestDocumentType dtType, const std::string& fileName)
{
 AnnotationCollection* pAnnotationColl;
 if (dtType == DT_DICOM)
 {
  DcmModel dcmModel;
  pAnnotationColl = dcmModel.ReadAnnotationCollectionFromFile(fileName.empty() ? DICOM_DOC_NAME : fileName);
 }
 else if (dtType == DT_XML)
 {
  XmlModel xmlModel;
  pAnnotationColl = xmlModel.ReadAnnotationCollectionFromFile(fileName.empty() ? XML_DOC_NAME : fileName);
 }

 //delete pAnnotationColl;
 //pAnnotationColl = NULL;

 return pAnnotationColl;
}

int process_image_annotation(ImageAnnotation& ia)
{
 ImageAnnotation::AnnotationType ty = ia.GetAnnotationType();
 QString qstr = QString::fromStdString( ia.GetComment() );
 qDebug() << "Comment: " << qstr;

 MarkupEntityPtrVector mes = ia.GetMarkupEntityCollection();
 qDebug() << "ses size: " << mes.size();

 for(MarkupEntity* me : mes)
 {
  const std::type_info& tyid = typeid(*me);
  QString tnns = QString::fromStdString( demangle(tyid.name()) );
  QStringList qsl = tnns.split("::");
  QString ns = qsl.first();
  QString tn = qsl.last();

  TwoDimensionGeometricShapeEntity* ent =
    static_cast<TwoDimensionGeometricShapeEntity*>(me);

  TwoDimensionGeometricShapeEntity::TwoDimensionShapeType st = ent->GetShapeType();
  qDebug() << st;


  qDebug() << tn;
//  me->
 }
}

int process_annotation_collection(AnnotationCollection* acc)
{
 int result;

 AnnotationCollection::AnnotationCollectionType acct = acc->GetAnnotationCollectionType();

 if(acct == AnnotationCollection::AnnotationCollectionType::ACT_ImageAnnotationCollection)
 {
  ImageAnnotationCollection* iac = static_cast<ImageAnnotationCollection*>(acc);
  ImageAnnotationVector iav = iac->GetImageAnnotations();
  result = iav.size();
  ImageAnnotation ia0 = iav.at(0);
  process_image_annotation(ia0);
 }

 return result;
}

int main(int argc, char *argv[])
{
 QString folder = AIM_DATA_FOLDER;

 QDirIterator qdi(AIM_DATA_FOLDER, {"*.xml"});

 QStringList aim_files;

 while(qdi.hasNext())
 {
  qdi.next();
  aim_files << qdi.fileInfo().absoluteFilePath();
 }

 QString af1 = aim_files.value(0);
 qDebug() << af1;

 AnnotationCollection* acc = test_load_annotations(DT_XML, af1.toStdString());

 int size = process_annotation_collection(acc);

// for(QString af : aim_files)
// {
//  AnnotationCollection* acc = test_load_annotations(DT_XML, af.toStdString());
//  int size = process_annotation_collection(acc);
//  qDebug() << af << ": " << size;
// }

 return 0;
}

