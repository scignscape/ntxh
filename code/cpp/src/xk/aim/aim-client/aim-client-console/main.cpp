
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include <QDebug>

#include <QFileInfo>
#include <QDirIterator>

#include <QString>



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



#include <QDebug>

#include <QFileInfo>
#include <QDirIterator>

#include <QString>
#include <QDataStream>

#include "tkrzw_dbm_hash.h"

#include "dgdb/dh-location-structure.h"

using namespace _class_DH_Location_Structure;

#include "dgdb/dgdb-database-instance.h"

#include "dgdb/dtb/sv-wrapper.h"

#include "dgdb/types/stage/dh-stage-code.h"
#include "dgdb/dh-stage-value.h"


#include "dgdb/dgdb-hypernode.h"

#include "dgdb/conversions.h"

#include "dgdb/types/dh-type-system.h"
#include "dgdb/types/dh-type.h"

#include "dgdb/graph/dh-frame.h"
#include "dgdb/graph/dh-dominion.h"
#include "dgdb/dh-instance.h"


#include "demo-class.h"

#include "aim-client/dh-annotation-environment.h"
#include "axfi/axfi-annotation-environment.h"
#include "axfi/axfi-annotation-folder.h"


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

    int status; //? huh? = -4; // some arbitrary value to eliminate the compiler warning

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

int main1(int argc, char *argv[])
{
 QString folder = AIM_DATA_FOLDER;

 QDirIterator qdi(AIM_DATA_FOLDER, {"*.xml"});

 QStringList aim_files;

 while(qdi.hasNext())
 {
  qdi.next();
  aim_files << qdi.fileInfo().absoluteFilePath();
 }

 QString af1 = aim_files.first();
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


int main2(int argc, char *argv[])
{
 AXFI_Annotation_Environment ae;
// ae.set_folder(AIM_DATA_FOLDER);
// qDebug() << ae.folder();

 DH_Annotation_Environment dae(&ae);

 DgDb_Database_Instance& ddi = *dae.dgdb(DEFAULT_DEV_DGDB_FOLDER "/t1");

 ddi.Config.flags.avoid_record_pointers = true;
 ddi.Config.flags.tkrzw_auto_commit = true;
 //ddi.Config.flags.local_scratch_mode = true;
 ddi.Config.flags.scratch_mode = true;
 ddi.Config.flags.reset_tkrzw = true;

 dae.init_database();
}

int main(int argc, char *argv[])
{
 AXFI_Annotation_Environment ae;

 AXFI_Annotation_Folder* af = ae.add_folder(AIM_DATA_FOLDER);
// qDebug() << ae.folder();
// //DH_Annotation_Environment dae(&ae);

 if(af->is_empty())
   return 0;

 QString af1 = af->aim_files().first();


// QString folder = AIM_DATA_FOLDER;
// QString af1 = aim_files.first();
// qDebug() << af1;

 AnnotationCollection* acc = test_load_annotations(DT_XML, af1.toStdString());


}

int main3(int argc, char *argv[])
{
 AXFI_Annotation_Environment ae;
// ae.set_folder(AIM_DATA_FOLDER);
// qDebug() << ae.folder();

 DH_Annotation_Environment dae(&ae);

 DgDb_Database_Instance& ddi = *dae.dgdb(DEFAULT_DEV_DGDB_FOLDER "/t1");

 //ddi.set_private_folder_path(DEFAULT_DEV_DGDB_FOLDER "/t1");

 //DgDb_Database_Instance ddi(DEFAULT_DEV_DGDB_FOLDER "/t1");

 ddi.Config.flags.avoid_record_pointers = true;
 ddi.Config.flags.tkrzw_auto_commit = true;
 //ddi.Config.flags.local_scratch_mode = true;
 ddi.Config.flags.scratch_mode = true;
 ddi.Config.flags.reset_tkrzw = true;

 dae.init_database();


 qDebug() << "blocks ftok key: " << ddi.ftok_key("blocks");

 //ddi.set_get_shm_field_ptr(_get_shm_field_ptr);

//#define _field_list_(cast, type ,name) #name,

#define _field_map_(cast, type ,name) {#name, DH_Stage_Code::get_prelim_for_type<type>() },

 DH_Type_System* dhts = ddi.type_system();

 dhts->REGISTER_TYPE(Demo_Class)
   .set_shm_block_size(106)    //   .sf({_Demo_Class_fm(_field_list_)})
   .sf({_Demo_Class_fm(_field_map_)})
      ("u4_in_block")[1](12,15)
      ("s1_in_block")[2]._signed_(16,16)
      ("datetime_in_block")[3]._datetime_(17,24)
      ("date_in_block")[4]._date_(25,32)
      ("time_in_block")[5]._time_(33,40)
      ("string_in_record")[6](41,48)
         //(DH::Redirect_In_Record <QString>)
         //(DH::Redirect_In_Record <QString> [7])
         //(DH::Redirect_In_Record <QString> (1))
         .record<QString>() //[7]
      ("string_encoded")[7](49,56)
         .encode<QString>()
      ("string_for_query")[8](57,64)
         .query<QString>("&/q/$type") //[5]
      ("s2_for_query")[9]._signed_(65,72)
         .query<int>("&/q/$type")(2) //[6] // [6]
      ("u4_for_query")[10](73,80)
         .query<int>("&/q/$type")(4)["string_for_query"] //[7]
      ("datetime_for_query")[11](81,88)
         .query<QDateTime>("&/q/$type") //[8]
      ("date_for_query")[12](89,96)
         .query<QDate>("&/q/$type") //[9]
      ("time_for_query")[13](97,104)
         .query<QTime>("&/q/$type") //[10]
      ("test_enum")[14](105,105)
      ("test_enum_flags")[15](106,106)
  ->set_default_binary_encoder(&Demo_Class::supply_data)
   .set_default_binary_decoder(&Demo_Class::absorb_data)
   ;



 // (DH::Redirect_In_Record [7]) //(DH_Subvalue_Field::Redirect_In_Record)

 DH_Type* dht = dhts->get_type_by_name("Demo_Class");

 DgDb_Hypernode* dh = ddi.new_hypernode<Demo_Class>();

// ddi.store_indexed_field(dh, _interned_field_name(3), u2_to_qba(524),
//   DH_Location_Structure::Data_Options::Shm_Pointer, "a_string");


// ddi.store(dh, "a_number", u2_to_qba(892));
// ddi.store(dh, "a_string", "a-test");

 Demo_Class* dc = new Demo_Class;
 dc->set_date_for_query(QDate(1794, 2, 4));
 dc->set_date_in_block(QDate(1787, 4, 23));
 dc->set_time_for_query(QTime(12, 13, 14, 15));
 dc->set_time_in_block(QTime(16, 17, 18, 19));
 dc->set_datetime_in_block(QDate(2021, 2, 4).startOfDay());
 dc->set_datetime_for_query(QDateTime(QDate(2021, 2, 4), QTime(20, 21, 22, 23)));
 dc->set_s1_in_block(-123);
 dc->set_s2_for_query(-789);
 dc->set_u4_in_block(12345);
 dc->set_u4_for_query(67890);
 dc->set_string_for_query("test:string-for-query"); //test:string-for-quer
 dc->set_string_in_record("test:string-in-record"); //test:string-in-recor
 dc->set_string_encoded("test:string-encoded"); //test:string-in-recor
 dc->set_test_enum(Demo_Class::Test_Enum::Enum_Val_3);
 dc->set_test_enum_flags(Demo_Class::Test_Enum_Flags::Enum_Flags_4
   | Demo_Class::Test_Enum_Flags::Enum_Flags_2);


 ddi.init_hypernode_from_object(dh, dc);

 ddi.set_property(dh, "test", 78);
 QVariant qv = ddi.get_property(dh, "test");
 qDebug() << "qv = " << qv;

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "test_enum", qba, pv);

  Demo_Class::Test_Enum test_val = (Demo_Class::Test_Enum) qba_to_u1(qba);
  //test = qToBigEndian(test);

  qDebug() << "test_enum = " << (u1) test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "test_enum_flags", qba, pv);

  Demo_Class::Test_Enum_Flags test_val = (Demo_Class::Test_Enum_Flags) qba_to_u1(qba);
  //test = qToBigEndian(test);

  qDebug() << "test_enum_flags = " << (u1) test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "string_in_record", qba, pv);

  qDebug() << "string_in_record = " << qba;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "string_encoded", qba, pv);

  qDebug() << "string_encoded = " << qba;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "string_for_query", qba, pv);

  qDebug() << "string_for_query = " << qba;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "s2_for_query", qba, pv);

  s2 test_val = qba_to_s2(qba);
  //test = qToBigEndian(test);

  qDebug() << "s2_for_query = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "u4_for_query", qba, pv);

  u4 test_val = qba_to_u4(qba);
  //test = qToBigEndian(test);

  qDebug() << "u4_for_query = " << test_val;
 }


 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "date_for_query", qba, pv);

  QDate test_val = qba_to_qdate(qba);
  //test = qToBigEndian(test);

  qDebug() << "date_for_query = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "datetime_for_query", qba, pv);

  QDateTime test_val = qba_to_qdatetime(qba);
  //test = qToBigEndian(test);

  qDebug() << "datetime_for_query = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "time_for_query", qba, pv);

  QTime test_val = qba_to_qtime(qba);
  //test = qToBigEndian(test);

  qDebug() << "time_for_query = " << test_val;
 }


 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "date_in_block", qba, pv);

  QDate test_val = qba_to_qdate(qba);
  //test = qToBigEndian(test);

  qDebug() << "date_in_block = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "datetime_in_block", qba, pv);

  QDateTime test_val = qba_to_qdatetime(qba);
  //test = qToBigEndian(test);

  qDebug() << "datetime_in_block = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "time_in_block", qba, pv);

  QTime test_val = qba_to_qtime(qba);
  //test = qToBigEndian(test);

  qDebug() << "time_in_block = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "u4_in_block", qba, pv);

  u4 test_val = qba_to_u4(qba);
  //test = qToBigEndian(test);

  qDebug() << "u4_in_block = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "s1_in_block", qba, pv);

  s2 test_val = qba_to_s1(qba);
  //test = qToBigEndian(test);

  qDebug() << "s1_in_block = " << test_val;
 }

 DgDb_Hypernode* dh1 = ddi.find_hypernode(dht, "string_for_query",
   dc->string_for_query());

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh1, "string_encoded", qba, pv);

  qDebug() << "string_encoded = " << qba;
 }

 Demo_Class* dc1;
 ddi.init_object_from_hypernode(dh1, dc1);
 qDebug() << "string_encoded = " << dc1->string_encoded();

 dc1->set_string_in_record("modified string ...");

 DgDb_Hypernode* dh2 = ddi.new_hypernode<Demo_Class>(dc1);

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh2, "string_in_record", qba, pv);

  qDebug() << "string_in_record = " << qba;
 }

 DH_Instance* dhi = ddi.dh_instance();

 DH_Frame& fr = *dhi->new_frame();
 DH_Dominion* dom = new DH_Dominion();
 DH_Context* ctxt = fr.new_context();

 dh << (fr/dom/ctxt)["Demo.SomeRelation"] >> dh2;

// DW_Frame& fr = *dw->new_frame(); // new DW_Frame(dw);
// DW_Dominion* dom = new DW_Dominion();
// DW_Context* ctxt = fr.new_context();

 fr.commit();

 DH_Record dhr = dhi->find_outedge(dh, "Demo.SomeRelation");

 DgDb_Hypernode* dh3 = dhr.node();
 if(dh2 == dh3)
 {
  qDebug() << "OK";
 }

// test_process_cb(ddi);
// test_process_cb(ddi);
// test_process_cb(ddi);
// test_process_cb(ddi);
// test_process_cb(ddi);

// test1_process_cb(ddi);
// test1_process_cb(ddi);
// test1_process_cb(ddi);
// test1_process_cb(ddi);
// test1_process_cb(ddi);

}
