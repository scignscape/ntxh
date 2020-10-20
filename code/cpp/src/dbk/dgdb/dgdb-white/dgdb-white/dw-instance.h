
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DW_INSTANCE__H
#define DW_INSTANCE__H

#include <QString>

#include <QMap>

#include "accessors.h"

#include "dw-record.h"
#include "dw-stage-value.h"

#include "global-types.h"

#include "kans.h"

#include "flags.h"


KANS_(DGDB)


class WDB_Instance;
class WDB_Manager;
class DW_Frame;

class String_Label_Triple;
class DW_Type_System;

//  
//   
//   11**   indexes      C0.00.00.00
//   10**   inedges      80.00.00.00
//   01**   outedges     40.00.00.00
//   001    subvalues    20.00.00.00
//   000    hypernodes   
//
//



class DW_Instance
{
 QString db_root_folder_;
 WDB_Instance* wdb_instance_;
 WDB_Manager* wdb_manager_;

 QString file_name_;

 DW_Type_System* type_system_;

 u4 startup_hypernode_record_count_; 
 u4 current_hypernode_record_count_;

 u4 startup_outedges_record_count_; 
 u4 current_outedges_record_count_;

 u4 startup_double_edges_record_count_; 
 u4 current_double_edges_record_count_;

 u4 startup_inedges_record_count_; 
 u4 current_inedges_record_count_;

 u4 startup_index_record_count_; 
 u4 current_index_record_count_;

 u4 startup_multi_index_record_count_; 
 u4 current_multi_index_record_count_;

 u4 startup_index_label_count_; 
 u4 current_index_label_count_;

 u4 new_hypernode_record_id();
 u4 new_multi_index_record_id();
 u4 new_index_record_id();
 u4 new_index_label_id();
 u4 new_inedges_record_id();
 u4 new_outedges_record_id();
 u4 new_double_edges_record_id();

 static constexpr u4 max_mask = 0x7FFFFFFF;

 static constexpr u4 indexes_mask = 0x60000000;
 static constexpr u4 double_edges_mask = 0x50000000;
 static constexpr u4 inedges_mask = 0x40000000;
 static constexpr u4 multi_indexes_mask = 0x30000000;
 static constexpr u4 outedges_mask = 0x20000000;
 static constexpr u4 subvalues_mask = 0x10000000;

 static constexpr u4 hypernodes_id_minimum = 1024;

//   011*   indexes       60.00.00.00
//   0101   double_edges  50.00.00.00
//   0100   inedges       40.00.00.00
//   0011   outedges      30.00.00.00
//   0010   multi_indexes 20.00.00.00
//   0001   subvalues     10.00.00.00
//   0000   hypernodes   

 void _set_raw_record_fields(void* rec, u4 start_col, QVector<DW_Stage_Value>& svs);
 void* _add_raw_record(u4 number_of_columns, QVector<DW_Stage_Value>& svs);


public:

 struct _Config
 {
  flags_(1)
   bool scratch_mode:1;
   bool local_scratch_mode:1;
   bool auto_stage:1;
   bool auto_commit:1;

   bool avoid_record_pointers:1;

   bool temp_reinit:1;
  _flags

  _Config() : Flags(0) {}  
 };

 _Config Config; 

 ACCESSORS(QString ,db_root_folder)
 ACCESSORS(WDB_Instance* ,wdb_instance)
 ACCESSORS(DW_Type_System* ,type_system)

 DW_Instance();

 DW_Frame* new_frame();

 void init(); 
 void reinit();


 void to_ntxh(QString& ty, QString& result);
 void init_from_ntxh(QString fld, u1 code);

 void* query_leading_rec(u4 col);
 void* query_leading_str(u4 col);
 void* query_leading_int(u4 col);

 QString get_restore_file();
 void restore_from_file(QString rf);



 DW_Record new_wg_hypernode_record(const QByteArray& qba);

 DW_Record new_wg_outedges_record(DW_Record& ref, QVector<QPair<QPair<QString, DW_Record>, 
   DW_Record>>& targets);
// populate_edges_record(new_rec, ref, targets); 

 void* add_raw_record(u4 number_of_columns, QVector<DW_Stage_Value>& svs)
 {
  return _add_raw_record(number_of_columns, svs);
 }

 void* add_raw_record(u4 number_of_columns, QVector<DW_Stage_Value> svs)
 {
  return _add_raw_record(number_of_columns, svs);
 }

 void set_raw_record_fields(void* rec, u4 start_col, QVector<DW_Stage_Value>& svs)
 {
  _set_raw_record_fields(rec, start_col, svs);
 }
 void set_raw_record_fields(void* rec, u4 start_col, QVector<DW_Stage_Value> svs)
 {
  _set_raw_record_fields(rec, start_col, svs);
 }


 DW_Record add_hyperedge(DW_Record& source, QString connector, const DW_Record* annotation, 
   DW_Record& target);

 DW_Record add_hyperedge(DW_Record& source, QString connector, const DW_Record& annotation, 
   DW_Record& target);

 DW_Record add_hyperedge(DW_Record& source, QString connector, DW_Record& target);

 u4 commit_new_triples(QVector<String_Label_Triple>& triples);

 DW_Record new_wg_inedges_record(const QByteArray& qba);

 DW_Record new_wg_findable_field_record(const QByteArray& qba);
 DW_Record new_wg_index_label_record(QString label);

 DW_Record new_wg_index_record(const DW_Record& ref, 
   const DW_Stage_Value& dwsv, QString label = {});

 void get_hypernode_payload(u4 id, QByteArray& qba);
 void get_hypernode_payload(const DW_Record& dwr, QByteArray& qba);

 DW_Record query_by_index_record(DW_Stage_Value& dwsv, QString label = {});
 DW_Record query_by_multi_index_record(DW_Stage_Value& dwsv, QString type_name, u4 col);
 DW_Record query_by_index_record(DW_Stage_Value& dwsv, QString type_name, u4 param_col, 
   u4 id_min, u4 id_max);



 void save_changes();

 QString test_register_value(QString type_name, void* v, 
   DW_Stage_Value::Callback_type cb, QByteArray* qba = nullptr);
 QString test_register_value(QString type_name, void* v, DW_Stage_Value::Package* pkg = nullptr);

 template<typename VALUE_Type>
 void test_register_value(VALUE_Type* v, DW_Stage_Value::Callback_type cb, 
   QByteArray* qba = nullptr)
 {
  QString tn = QString::fromStdString(typeid(VALUE_Type).name());
  test_register_value(tn, (void*) v, cb, qba);
 }

 template<typename VALUE_Type>
 void test_register_value(VALUE_Type* v, DW_Stage_Value::Package* pkg = nullptr)
 {
  QString tn = QString::fromStdString(typeid(VALUE_Type).name());
  test_register_value(tn, (void*) v, pkg);
 }

 DW_Record register_typed_value(QString type_name, void* v, 
   DW_Stage_Value::Callback_type cb, DW_Stage_Value::Package* pkg);

 DW_Record register_typed_value(QString type_name, void* v);

 DW_Record register_typed_value(QString type_name, DW_Stage_Value::Package& pkg);

 template<typename VALUE_Type>
 DW_Record register_typed_value(VALUE_Type* v)
 {
  QString tn = QString::fromStdString(typeid(VALUE_Type).name());
  return register_typed_value(tn, (void*) v);
 }

 template<typename VALUE_Type>
 DW_Record register_typed_value(VALUE_Type* v, 
   DW_Stage_Value::Callback_type cb, DW_Stage_Value::Package* pkg)
 {
  QString tn = QString::fromStdString(typeid(VALUE_Type).name());
  return register_typed_value(tn, (void*) v, cb, pkg);
 }

};


_KANS(DGDB)

#endif // DGDB_INSTANCE__H
