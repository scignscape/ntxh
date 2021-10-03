
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include <QDebug>

#include <QFileInfo>
#include <QDirIterator>

#include <QString>
#include <QDataStream>

#include "tkrzw_dbm_hash.h"

#include "dgdb/dgdb-location-structure.h"

using namespace _class_DgDb_Location_Structure;

#include "dgdb/dgdb-database-instance.h"

#include "dgdb/types/stage/dh-stage-code.h"
#include "dgdb/dh-stage-value.h"


#include "dgdb/dgdb-hypernode.h"

#include "dgdb/conversions.h"

#include "dgdb/types/dh-type-system.h"
#include "dgdb/types/dh-type.h"


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


//extern "C" {
//#include "whitedb/_whitedb.h"
//}

#include "test-class.h"
#include "demo-class.h"

using namespace tkrzw;


//dhts->REGISTER_TYPE(Test_Class)
//  .set_shm_block_size(100)
//  .sf({_Demo_Class_fm(_field_list_)})
//     ("a_sign")[1]._signed_(10,11)
//     ("a_string")[2](12,19)
//        .query<QString>("&/q/$type")[5]
//     ("a_number")[3](20,27)
//        .query<int>("&/q/$type")(4)[6]
// ->set_default_binary_encoder(&Test_Class::supply_data)
//  .set_default_binary_decoder(&Test_Class::absorb_data)
//  ;


int main2(int argc, char *argv[])
{
 DgDb_Database_Instance ddi(DEFAULT_DEV_DGDB_FOLDER "/t1");

 ddi.init_dtb_package();
 ddi.init_type_system();
 ddi.check_construct_files();
 ddi.check_interns_dbm();
 ddi.check_nodes_dbm();
 ddi.read_hypernode_count_status();
 ddi.read_interns_count_status();
 ddi.init_dwb_blocks();

 qDebug() << "blocks ftok key: " << ddi.ftok_key("blocks");

 //ddi.set_get_shm_field_ptr(_get_shm_field_ptr);

#define _field_list_(x) #x,

 DH_Type_System* dhts = ddi.type_system();
 dhts->REGISTER_TYPE(Test_Class)
   .set_shm_block_size(100)
   .sf({_Test_Class_FM(_field_list_)})
      ("a_sign")[1]._signed_(11,11)
      ("a_string")[2](12,19)
         .query<QString>("&/q/$type")[5]
      ("a_number")[3](20,27)
         .query<int>("&/q/$type")(4)[6]
  ->set_default_binary_encoder(&Test_Class::supply_data)
   .set_default_binary_decoder(&Test_Class::absorb_data)
   ;

 // (DH::Redirect_In_Record [7]) //(DH_Subvalue_Field::Redirect_In_Record)

 DH_Type* dht = dhts->get_type_by_name("Test_Class");

 DgDb_Hypernode* dh = ddi.new_hypernode<Test_Class>();

// ddi.store_indexed_field(dh, _interned_field_name(3), u2_to_qba(524),
//   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_string");


// ddi.store(dh, "a_number", u2_to_qba(892));
// ddi.store(dh, "a_string", "a-test");

 Test_Class* tc = new Test_Class;
 tc->set_a_number(1);
 tc->set_a_string("a str");
 tc->set_a_sign(-25);

 ddi.init_hypernode_from_object(dh, tc);
 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "a_number", qba, pv);

  u4 test_val = qba_to_u4(qba);
  //test = qToBigEndian(test);

  qDebug() << "test_val = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "a_sign", qba, pv);

  s1 test_val = qba_to_s1(qba);
  //test = qToBigEndian(test);

  qDebug() << "test_val = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "a_string", qba, pv);

  qDebug() << "test_val = " << qba;
 }

// {
//  QByteArray qba;
//  void* pv;

//  Test_Class* tc;
//  DgDb_Hypernode* dh1 = ddi.find_hypernode("a_string", "a-test", &tc);

//  qDebug() << "dh id = " << dh->id();
//  qDebug() << "dh1 id = " << dh1->id();
// }




// ddi.store(dh, "a_number", u2_to_qba(892));
// {
//  QByteArray qba;
//  void* pv;

//  ddi.fetch_subvalue(dh, "a_number", qba, pv);

//  u2 test_val = qba_to_u2(qba);
//  //test = qToBigEndian(test);

//  qDebug() << "test_val = " << test_val;
// }


// ddi.store_indexed_field(dh, _interned_field_name(3), u2_to_qba(524),
//   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_number");

// ddi.store_indexed_field(dh, _interned_field_name(4), "test",
//   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_string");

// {
//  QByteArray qba;
//  void* pv;
//  ddi.fetch_indexed_field(dh, 3, DgDb_Location_Structure::Field_Id_Options::Interned_Field_Name,
//    qba, pv, DgDb_Location_Structure::Data_Options::Shm_Pointer);

//  u2 test = qba_to_u2(qba);

//  qDebug() << "test = " << test;
// }

 //ddi.set_get_shm_field_ptr(_get_shm_field_ptr);

}



int main(int argc, char *argv[])
{
 DgDb_Database_Instance ddi(DEFAULT_DEV_DGDB_FOLDER "/t1");

 ddi.init_dtb_package();
 ddi.init_type_system();
 ddi.check_construct_files();
 ddi.check_interns_dbm();
 ddi.check_nodes_dbm();
 ddi.read_hypernode_count_status();
 ddi.read_interns_count_status();
 ddi.init_dwb_blocks();

 qDebug() << "blocks ftok key: " << ddi.ftok_key("blocks");

 //ddi.set_get_shm_field_ptr(_get_shm_field_ptr);

#define _field_list_(cast, type ,name) #name,

 DH_Type_System* dhts = ddi.type_system();

 dhts->REGISTER_TYPE(Demo_Class)
   .set_shm_block_size(100)
   .sf({_Demo_Class_fm(_field_list_)})
      ("u4_in_block")[1](12,15)
      ("s1_in_block")[2]._signed_(16,16)
      ("datetime_in_block")[3]._datetime_(17,24)
      ("date_in_block")[4]._date_(25,32)
      ("time_in_block")[5]._time_(33,40)
      ("string_in_record")[6](41,48)
         (DH::Redirect_In_Record <QString> [7])
         //.column<QString>(7)
      ("test_enum")[7](49,49)
      ("test_enum_flags")[8](50,50)
      ("string_for_query")[9](51,58)
         .query<QString>("&/q/$type")[5]
      ("s2_for_query")[10](59,66)
         .query<int>("&/q/$type")(-2)[6]
      ("u4_for_query")[11](67,74)
         .query<int>("&/q/$type")(4)[7]
      ("datetime_for_query")[12](75,82)
         .query<QDateTime>("&/q/$type")[8]
      ("date_for_query")[13](83,90)
         .query<QDate>("&/q/$type")[9]
      ("time_for_query")[14](91,98)
         .query<QTime>("&/q/$type")[10]
  ->set_default_binary_encoder(&Demo_Class::supply_data)
   .set_default_binary_decoder(&Demo_Class::absorb_data)
   ;


// QString ,string_in_record      )field(,\
// QString ,string_for_query      )field(,\
// u4 ,u4_in_block                )field(,\
// u4 ,u4_for_query               )field(,\
// s1 ,s1_in_block                )field(,\
// s2 ,s2_for_query               )field(,\
// QDateTime ,datetime_in_block   )field(,\
// QDateTime ,datetime_for_query  )field(,\
// QDate ,date_in_block           )field(,\
// QDate ,date_for_query          )\
//\
//field((u1&), Test_Enum ,test_enum)\
//field((u1&), Test_Enum_Flags ,test_enum_flags)


 // (DH::Redirect_In_Record [7]) //(DH_Subvalue_Field::Redirect_In_Record)

 DH_Type* dht = dhts->get_type_by_name("Demo_Class");

 DgDb_Hypernode* dh = ddi.new_hypernode<Demo_Class>();

// ddi.store_indexed_field(dh, _interned_field_name(3), u2_to_qba(524),
//   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_string");


// ddi.store(dh, "a_number", u2_to_qba(892));
// ddi.store(dh, "a_string", "a-test");

 Demo_Class* dc = new Demo_Class;
 dc->set_date_for_query(QDate(1794, 2, 4));
 dc->set_date_in_block(QDate(1787, 4, 23));
 dc->set_time_for_query(QTime(12, 13, 14, 15));
 dc->set_time_in_block(QTime(16, 17, 18, 19));
 dc->set_datetime_in_block(QDate(2021, 2, 4).startOfDay());
 dc->set_datetime_for_query(QDateTime(QDate(2021, 2, 4), QTime(20, 21, 22, 23)));
 dc->set_s1_in_block(-25);
 dc->set_s2_for_query(-789);
 dc->set_u4_in_block(12345);
 dc->set_u4_for_query(67890);
 dc->set_string_for_query("y"); //test:string-for-quer
 dc->set_string_in_record("d"); //test:string-in-recor
 dc->set_test_enum(Demo_Class::Test_Enum::Enum_Val_3);
 dc->set_test_enum_flags(Demo_Class::Test_Enum_Flags::Enum_Flags_4
   | Demo_Class::Test_Enum_Flags::Enum_Flags_2);


 ddi.init_hypernode_from_object(dh, dc);
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

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "string_for_query", qba, pv);

  qDebug() << "string_for_query = " << qba;
 }
}

#ifdef HIDE



//void* _get_shm_field_ptr(DgDb_Database_Instance& ddi,
//  DgDb_Hypernode& dh,
//  u2 index_code, QString field_name,
//  size_t* size, n8* shm_path_code)
//{
// qDebug() << "field name = " << field_name;
// auto [fio, index] = _split_index_code(index_code);

// DH_Type* dht = dh.dh_type();
// char* block = dh.shm_block();
// auto [offset, end] = dht->get_field_block_offset(field_name);
// u4 sz = end - offset;
// if(!block)
// {
////  size_t sbs = dht->shm_block_size();
////  u2 block_column = dht->shm_block_column();
//  block = ddi.allocate_shm_block(dht, dh.id(), "testOk");
//  dh.set_shm_block(block);
////  void* rec = ddi.get_wdb_record_from_block(block);
////  QString msg = ddi.get_string_from_wdb_record(rec);
////  qDebug() << "msg = " << msg;
// }

// return block + offset;
//}



int main7(int argc, char *argv[])
{
 DgDb_Database_Instance ddi(DEFAULT_DEV_DGDB_FOLDER "/t1");

 ddi.init_dtb_package();
 ddi.init_type_system();
 ddi.check_construct_files();
 ddi.check_interns_dbm();
 ddi.check_nodes_dbm();
 ddi.read_hypernode_count_status();
 ddi.read_interns_count_status();
 ddi.init_dwb_blocks();

 qDebug() << "blocks ftok key: " << ddi.ftok_key("blocks");

 //ddi.set_get_shm_field_ptr(_get_shm_field_ptr);

 DH_Type_System* dhts = ddi.type_system();
 dhts->REGISTER_TYPE(Test_Class)
   .set_shm_block_size(100)
   .sf("a_sign")[1]._signed_(10,11)
      ("a_string")[2](12,19)
         .query<QString>("&/q/$type")[5]
      ("a_number")[3](20,27)  //(20,21)
         .query<int>("&/q/$type")(4)[6]
  ->set_default_binary_encoder(&Test_Class::supply_data)
   .set_default_binary_decoder(&Test_Class::absorb_data)
   ;

 DH_Type* dht = dhts->get_type_by_name("Test_Class");
 DH_Stage_Code sc = ddi.get_stage_code(dht, "a_string");

 DgDb_Hypernode* dh = ddi.new_hypernode<Test_Class>();

// ddi.store_indexed_field(dh, _interned_field_name(3), u2_to_qba(524),
//   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_string");

// Test_Class* tc = new Test_Class;
// tc->set_a_number(991);
// tc->set_a_string("a str");
// tc->set_a_sign(-265);

 ddi.store(dh, "a_number", u4_to_sv(991));

 ddi.store(dh, "a_string", "a-test");

// ddi.store_indexed_field(dh, _structure_field_index(2), "a-test",
//   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_string");

 ddi.store(dh, "a_sign", s2_to_sv(-256));
// DgDb_Hypernode* dh1 = ddi.find_hypernode(dht, "a_string", "a-test");

// Test_Class* tc;

 DH_Stage_Value sv;
// sv.set_str_data("a-test");
// DgDb_Hypernode* dh1 = ddi.find_hypernode(dht, "a_string", sv);

 sv.set_u4_data(991);
 DgDb_Hypernode* dh1 = ddi.find_hypernode(dht, "a_number", sv);


 qDebug() << "dh id = " << dh->id();
 qDebug() << "dh1 id = " << dh1->id();



 // ddi.init_hypernode_from_object(dh, tc);
 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh1, "a_number", qba, pv);

  u4 test_val = qba_to_u4(qba);
  //test = qToBigEndian(test);

  qDebug() << "test_val = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh1, "a_sign", qba, pv);

  s2 test_val = qba_to_s2(qba);
  //test = qToBigEndian(test);

  qDebug() << "test_val = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh1, "a_string", qba, pv);

  qDebug() << "test_val = " << qba;
 }
}

int main6(int argc, char *argv[])
{
 DgDb_Database_Instance ddi(DEFAULT_DEV_DGDB_FOLDER "/t1");

 ddi.init_dtb_package();
 ddi.init_type_system();
 ddi.check_construct_files();
 ddi.check_interns_dbm();
 ddi.check_nodes_dbm();
 ddi.read_hypernode_count_status();
 ddi.read_interns_count_status();
 ddi.init_dwb_blocks();

 qDebug() << "blocks ftok key: " << ddi.ftok_key("blocks");

 //ddi.set_get_shm_field_ptr(_get_shm_field_ptr);

 DH_Type_System* dhts = ddi.type_system();
 dhts->REGISTER_TYPE(Test_Class)
   .set_shm_block_size(100)
   .sf("a_sign")[1]._signed_(10,11)
      ("a_string")[2](12,19)
         .query<QString>("&/q/$type")[5]
      ("a_number")[3](20,23)
  ->set_default_binary_encoder(&Test_Class::supply_data)
   .set_default_binary_decoder(&Test_Class::absorb_data)
   ;

 // (DH::Redirect_In_Record [7]) //(DH_Subvalue_Field::Redirect_In_Record)

// DH_Type* dht = dhts->get_type_by_name("Test_Class");
// DH_Stage_Code sc1 = ddi.get_stage_code(dht, "a_number");

 DgDb_Hypernode* dh = ddi.new_hypernode<Test_Class>();

 ddi.store_indexed_field(dh, _structure_field_index(1), s2_to_sv(-324),
   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_number");

 ddi.store_indexed_field(dh, _structure_field_index(2), qstring_to_sv("test"),
   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_string");

 ddi.store_indexed_field(dh, _structure_field_index(3), u4_to_sv(11324),
   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_string");

 DgDb_Hypernode* dh1 = dh;

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh1, "a_number", qba, pv);

  u4 test_val = qba_to_u4(qba);
  //test = qToBigEndian(test);

  qDebug() << "test_val = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh1, "a_sign", qba, pv);

  s2 test_val = qba_to_s2(qba);
  //test = qToBigEndian(test);

  qDebug() << "test_val = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh1, "a_string", qba, pv);

  qDebug() << "test_val = " << qba;
 }


#ifdef HIDE

 DgDb_Hypernode* dh = ddi.new_hypernode<Test_Class>();

 ddi.store_indexed_field(dh, _interned_field_name(3), u2_to_qba(524),
   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_string");


// ddi.store(dh, "a_number", u2_to_qba(892));
// ddi.store(dh, "a_string", "a-test");

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "a_number", qba, pv);

  u2 test_val = qba_to_u2(qba);
  //test = qToBigEndian(test);

  qDebug() << "test_val = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "a_string", qba, pv);

  qDebug() << "test_val = " << qba;
 }
#endif
}


int main8(int argc, char *argv[])
{
 DgDb_Database_Instance ddi(DEFAULT_DEV_DGDB_FOLDER "/t1");

 ddi.init_dtb_package();
 ddi.init_type_system();
 ddi.check_construct_files();
 ddi.check_interns_dbm();
 ddi.check_nodes_dbm();
 ddi.read_hypernode_count_status();
 ddi.read_interns_count_status();
 ddi.init_dwb_blocks();

 qDebug() << "blocks ftok key: " << ddi.ftok_key("blocks");

 //ddi.set_get_shm_field_ptr(_get_shm_field_ptr);

#define _field_list_(x) #x,

 DH_Type_System* dhts = ddi.type_system();
 dhts->REGISTER_TYPE(Test_Class)
   .set_shm_block_size(100)
   .sf({_Test_Class_FM(_field_list_)})
      ("a_sign")[1]._signed_(10,11)
      ("a_string")[2](12,19)
         .query<QString>("&/q/$type")[5]
      ("a_number")[3](20,27)
         .query<int>("&/q/$type")(4)[6]
  ->set_default_binary_encoder(&Test_Class::supply_data)
   .set_default_binary_decoder(&Test_Class::absorb_data)
   ;

 // (DH::Redirect_In_Record [7]) //(DH_Subvalue_Field::Redirect_In_Record)

 DH_Type* dht = dhts->get_type_by_name("Test_Class");

 DgDb_Hypernode* dh = ddi.new_hypernode<Test_Class>();

// ddi.store_indexed_field(dh, _interned_field_name(3), u2_to_qba(524),
//   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_string");


// ddi.store(dh, "a_number", u2_to_qba(892));
// ddi.store(dh, "a_string", "a-test");

 Test_Class* tc = new Test_Class;
 tc->set_a_number(1);
 tc->set_a_string("a str");
 tc->set_a_sign(-265);

 ddi.init_hypernode_from_object(dh, tc);
 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "a_number", qba, pv);

  u4 test_val = qba_to_u4(qba);
  //test = qToBigEndian(test);

  qDebug() << "test_val = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "a_sign", qba, pv);

  s2 test_val = qba_to_s2(qba);
  //test = qToBigEndian(test);

  qDebug() << "test_val = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "a_string", qba, pv);

  qDebug() << "test_val = " << qba;
 }

// {
//  QByteArray qba;
//  void* pv;

//  Test_Class* tc;
//  DgDb_Hypernode* dh1 = ddi.find_hypernode("a_string", "a-test", &tc);

//  qDebug() << "dh id = " << dh->id();
//  qDebug() << "dh1 id = " << dh1->id();
// }




// ddi.store(dh, "a_number", u2_to_qba(892));
// {
//  QByteArray qba;
//  void* pv;

//  ddi.fetch_subvalue(dh, "a_number", qba, pv);

//  u2 test_val = qba_to_u2(qba);
//  //test = qToBigEndian(test);

//  qDebug() << "test_val = " << test_val;
// }


// ddi.store_indexed_field(dh, _interned_field_name(3), u2_to_qba(524),
//   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_number");

// ddi.store_indexed_field(dh, _interned_field_name(4), "test",
//   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_string");

// {
//  QByteArray qba;
//  void* pv;
//  ddi.fetch_indexed_field(dh, 3, DgDb_Location_Structure::Field_Id_Options::Interned_Field_Name,
//    qba, pv, DgDb_Location_Structure::Data_Options::Shm_Pointer);

//  u2 test = qba_to_u2(qba);

//  qDebug() << "test = " << test;
// }

 //ddi.set_get_shm_field_ptr(_get_shm_field_ptr);

}



int main3(int argc, char *argv[])
{
 DgDb_Database_Instance ddi(DEFAULT_DEV_DGDB_FOLDER "/t1");

 ddi.init_dtb_package();
 ddi.init_type_system();
 ddi.check_construct_files();
 ddi.check_interns_dbm();
 ddi.check_nodes_dbm();
 ddi.read_hypernode_count_status();
 ddi.read_interns_count_status();
 ddi.init_dwb_blocks();

 qDebug() << "blocks ftok key: " << ddi.ftok_key("blocks");

 //ddi.set_get_shm_field_ptr(_get_shm_field_ptr);

 DH_Type_System* dht = ddi.type_system();
 dht->REGISTER_TYPE(Test_Class)
   .set_shm_block_size(100)
   .sf("a_number")[1](10,11)
      ("a_string")[2](12,19)(DH_Subvalue_Field::Redirect_In_Record)
  ->set_default_binary_encoder(&Test_Class::supply_data)
   .set_default_binary_decoder(&Test_Class::absorb_data)
   ;

 // (DH::Redirect_In_Record [7]) //(DH_Subvalue_Field::Redirect_In_Record)

 DgDb_Hypernode* dh = ddi.new_hypernode<Test_Class>();

// ddi.store_indexed_field(dh, _interned_field_name(3), u2_to_qba(524),
//   DgDb_Location_Structure::Data_Options::Shm_Pointer, "a_string");


// ddi.store(dh, "a_number", u2_to_qba(892));
// ddi.store(dh, "a_string", "a-test");

 Test_Class* tc = new Test_Class;
 tc->set_a_number(4451);
 tc->set_a_string("a-str");

 ddi.init_hypernode_from_object(dh, tc);
 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "a_number", qba, pv);

  u2 test_val = qba_to_u2(qba);
  //test = qToBigEndian(test);

  qDebug() << "test_val = " << test_val;
 }

 {
  QByteArray qba;
  void* pv;

  ddi.fetch_subvalue(dh, "a_string", qba, pv);

  qDebug() << "test_val = " << qba;
 }
}

//int main5(int argc, char *argv[])
//{
// db = wg_attach_database("300", 0);

// DgDb_Database_Instance ddi(DEFAULT_DEV_DgDb_FOLDER "/t1");

// ddi.check_construct_files();
// ddi.check_interns_dbm();
// ddi.check_nodes_dbm();
// ddi.read_hypernode_count_status();
// ddi.read_interns_count_status();

// ddi.set_get_shm_field_ptr(_get_shm_field_ptr2);

//// ddi.set_get_shm_field_ptr([](u2 index_code, QString field_name,
////   size_t* size, n8* shm_path_code) -> void*
//// {
////  qDebug() << "field name = " << field_name;
////  auto [fio, index] = _split_index_code(index_code);
////  return nullptr;
//// });

// DgDb_Hypernode* dh = ddi.new_hypernode();

// ddi.store_indexed_field(dh, _negative_raw_array_position(3), u2_to_qba(514),
//   DgDb_Location_Structure::Data_Options::Shm_Pointer, "xtest");

// void* v = wg_get_first_record(db);

// if(v)
// {
//  wg_int wi = wg_get_field(db, v, 0);

//  //wg_int wi1 = wg_decode_blob_len(db, wi);

//  //char data[wi1];
//  char* cc = wg_decode_blob(db, wi);

//  qDebug() << "cc = " << (n8) cc;

//  u2 uu;
//  memcpy(&uu, cc + 20, 2);
//  uu = qToBigEndian(uu);

//  qDebug() << "uu = " << uu;

//  wg_int nn;
//  memcpy(&nn, cc, sizeof (wg_int));

//  qDebug() << "nn = " << nn;

//  void* rec = wg_decode_record(db, nn);

//  qDebug() << "rec = " << rec;

//  wg_int wi2 = wg_get_field(db, rec, 1);

//  qDebug() << "wi2 = " << wi2;

//  char* str = wg_decode_str(db, wi2);
//  qDebug() << "str = " << str;


// }
//// nn = qToBigEndian(nn);

//// char* data = _make_shm();
//// QByteArray qba(2, 0);
//// memcpy(qba.data(), data + 100, 2);
//// u2 uu = qba_to_u2(qba);
//// qDebug() << "uu = " << uu;


// QByteArray qba;
// void* pv;
// ddi.fetch_indexed_field(dh, 3, DgDb_Location_Structure::Field_Id_Options::Negative_Raw_Array_Position, qba,
//   pv, DgDb_Location_Structure::Data_Options::Shm_Pointer);

//// u2 test;// = qba_to_u2(qba);
//// qba_to_<u2>(qba, test);

//// u1 test = qba_to_u1(qba);
// u2 test = qba_to_u2(qba);

// qDebug() << "test = " << test;

// return 0;
//}


int main4(int argc, char *argv[])
{
 DgDb_Database_Instance ddi(DEFAULT_DEV_DGDB_FOLDER "/t1");

 ddi.check_construct_files();
 ddi.check_interns_dbm();
 ddi.check_nodes_dbm();
 ddi.read_hypernode_count_status();
 ddi.read_interns_count_status();

 DgDb_Hypernode* dh = ddi.new_hypernode();

 ddi.store_indexed_field(dh, 3, u1_to_sv(78),
   DgDb_Location_Structure::Data_Options::Numeric, {});


 QByteArray qba;
 ddi.fetch_indexed_field(dh, 3, qba,
   DgDb_Location_Structure::Data_Options::Numeric);

 u1 test = qba_to_u1(qba);

 qDebug() << "test = " << test;

}

int main2(int argc, char *argv[])
{
 DgDb_Database_Instance ddi(DEFAULT_DEV_DGDB_FOLDER "/t1");

 ddi.check_construct_files();
 ddi.check_interns_dbm();
 ddi.check_nodes_dbm();
 ddi.read_hypernode_count_status();
 ddi.read_interns_count_status();

 DgDb_Hypernode* dh = ddi.new_hypernode();

 ddi.set_property(dh, "test", 78);

 QVariant qv = ddi.get_property(dh, "test");

 qDebug() << "qv = " << qv;

// s4 st = ddi.read_hypernode_count_status();
// qDebug() << "st = " << st;re   thie

// ddi.store_hypernode_count_status(55);
// s4 st1 = ddi.read_hypernode_count_status();
// qDebug() << "st1 = " << st1;


// DgDb_Location_Structure dls;

// //dls.set_raw_code();

// dls.set_primary_field_id(33, DgDb_Location_Structure::Field_Id_Options::Interned_Field_Name);
// dls.set_secondary_field_id(44, DgDb_Location_Structure::Field_Id_Options::Offset_Array_Position);

// QPair<DgDb_Location_Structure::Field_Id_Options, u2> pr1 = dls.get_primary_field_id();
// QPair<DgDb_Location_Structure::Field_Id_Options, u2> pr2 = dls.get_secondary_field_id();

// qDebug() << dls.raw_code();
// qDebug() << (u1) pr1.first << pr1.second;
// qDebug() << (u1) pr2.first << pr2.second;

 return 0;

}

int main1(int argc, char *argv[])
{
 DgDb_Location_Structure dls;

 //dls.set_raw_code();

 dls.set_primary_field_id(33, DgDb_Location_Structure::Field_Id_Options::Structure_Field_Index);
 dls.set_secondary_field_id(44, DgDb_Location_Structure::Field_Id_Options::Negative_Raw_Array_Position);

// QPair<DgDb_Location_Structure::Field_Id_Options, u2> pr1 = dls.get_primary_field_id();
// QPair<DgDb_Location_Structure::Field_Id_Options, u2> pr2 = dls.get_secondary_field_id();

// qDebug() << dls.raw_code();
//// qDebug() << (u1) pr1.first << pr1.second;
// // qDebug() << (u1) pr2.first << pr2.second;

 dls.set_node_id(1001);

 // qDebug() << dls.raw_code();

 dls.set_data_options(DgDb_Location_Structure::Data_Options::Shm_Pointer_With_Size);

 // // qDebug() << dls.raw_code();
 QPair<DgDb_Location_Structure::Data_Options, u4> pr3 = dls.get_node_id();


 QPair<DgDb_Location_Structure::Field_Id_Options, u2> pr1 = dls.get_primary_field_id();
 QPair<DgDb_Location_Structure::Field_Id_Options, u2> pr2 = dls.get_secondary_field_id();

 qDebug() << (u1) pr1.first << pr1.second;
 qDebug() << (u1) pr2.first << pr2.second;
 qDebug() << (u1) pr3.first << pr3.second;




 return 0;
}




//void* db; // = wg_attach_database("300", 0);

//// void* rec = wg_create_record(db, 10);
////void* rec1 = wg_create_record(db, 3);

//// wg_int enc = wg_encode_int(db, 443);
//// wg_int enc1 = wg_encode_str(db, "this is my string", NULL);


//char* _make_shm()
//{
// static char* result = nullptr;
// if(!result)
// {
//  QString path = DEFAULT_DEV_DgDb_FOLDER "/t1/white-data";
//  key_t key = ftok(path.toLatin1().data(), '~');
//  qDebug() << "key = " << key;

//  int shmid = shmget(key, 1024, 0644 | IPC_CREAT);
//  result = (char*) shmat(shmid, NULL, 0);
// }
// return result;
//}


//void* _get_shm_field_ptr2(u2 index_code, QString field_name,
//  size_t* size, n8* shm_path_code)
//{
// qDebug() << "field name = " << field_name;
// auto [fio, index] = _split_index_code(index_code);

//// char* data = _make_shm();
//// return data + 100;

// char array[100] = {0};

// wg_int wi = wg_encode_blob(db, array, nullptr, 100);
// char* result = wg_decode_blob(db, wi);

// qDebug() << "cc result = " << (n8) result;

//// void* rec = wg_create_record(db, 3);
//// wg_set_field(db, rec, 0, wi);
//// wg_set_str_field(db, rec, 1, "x");

//// wg_int rr = wg_encode_record(db, rec);

//// rr = qToBigEndian(rr);
//// memcpy(result, &rr, sizeof (wg_int));

// return result + 20;
//}

//void* _get_shm_field_ptr1(u2 index_code, QString field_name,
//  size_t* size, n8* shm_path_code)
//{
// qDebug() << "field name = " << field_name;
// auto [fio, index] = _split_index_code(index_code);

//// char* data = _make_shm();
//// return data + 100;

// char array[100] = {0};

// wg_int wi = wg_encode_blob(db, array, nullptr, 100);
// char* result = wg_decode_blob(db, wi);

// qDebug() << "cc result = " << (n8) result;


// void* rec = wg_create_record(db, 3);
// wg_set_field(db, rec, 0, wi);
// wg_set_str_field(db, rec, 1, "x");

// wg_int rr = wg_encode_record(db, rec);

//// rr = qToBigEndian(rr);
// memcpy(result, &rr, sizeof (wg_int));

// return result + 20;
//}


//void* _get_shm_field_ptr(u2 index_code, QString field_name,
//  size_t* size, n8* shm_path_code)
//{
// qDebug() << "field name = " << field_name;
// auto [fio, index] = _split_index_code(index_code);

//// char* data = _make_shm();
//// return data + 100;

//   void* v = wg_get_first_record(db);

//   wg_int wi = wg_get_field(db, v, 0);

//   //wg_int wi1 = wg_decode_blob_len(db, wi);

//   //char data[wi1];
//   char* cc = wg_decode_blob(db, wi);

//   return cc + 20;

//}


#endif // HIDE
