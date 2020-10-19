//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dw-instance.h"

#include "types/dw-type-system.h"
#include "types/dw-type.h"


#include "wdb-instance.h"
#include "wdb-manager.h"

#include "dw-frame.h"

#include <QDebug>
#include <QFileInfo>



USING_KANS(DGDB)


DW_Instance::DW_Instance()
  :  wdb_instance_(nullptr), wdb_manager_(nullptr),
     type_system_(nullptr),
     startup_hypernode_record_count_(0), 
     current_hypernode_record_count_(0),
     startup_index_record_count_(0), 
     current_index_record_count_(0),
     startup_index_label_count_(0),
     current_index_label_count_(0),
     startup_outedges_record_count_(0), 
     current_outedges_record_count_(0),
     startup_inedges_record_count_(0), 
     current_inedges_record_count_(0),
     startup_multi_index_record_count_(0),
     current_multi_index_record_count_(0),
     startup_double_edges_record_count_(0), 
     current_double_edges_record_count_(0)
{

}

DW_Record DW_Instance::register_typed_value(QString type_name, DW_Stage_Value::Package& pkg)
{
 DW_Record result = new_wg_hypernode_record(pkg.qba);

 if(!pkg.single_indexed.isEmpty())
 {
  QMapIterator<QString, DW_Stage_Value> it (pkg.single_indexed);
  while(it.hasNext())
  {
   it.next();
   DW_Record ir = new_wg_index_record(result, it.value(), it.key()); //const DW_Stage_Value& dwsv);
  }
 }
 
 if(!pkg.multi_indexed.isEmpty())
 {
  u4 miid = new_multi_index_record_id();
  DW_Record mi = wdb_instance_->new_wg_record(miid, type_name, 
    Config.flags.avoid_record_pointers? &result : result.wg_record(), pkg.multi_indexed);
  wdb_instance_->set_wg_record_field_rec(result, 4, mi);
//  QMapIterator<u4, DW_Stage_Value*> it (pkg.multi_indexed);

 }

 return result;
 //DW_Record dr1 = register_ 
}

DW_Record DW_Instance::register_typed_value(QString type_name, void* v, 
  DW_Stage_Value::Callback_type cb, DW_Stage_Value::Package* pkg)
{
 QString tn = test_register_value(type_name, v, cb);
 return register_typed_value(tn, *pkg);
}

DW_Record DW_Instance::register_typed_value(QString type_name, void* v)
{
 DW_Stage_Value::Package pkg;
 QString tn = test_register_value(type_name, v, &pkg);
 return register_typed_value(tn, pkg);
}


QString DW_Instance::test_register_value(QString type_name, void* v, DW_Stage_Value::Package* pkg)
{
 QString result;

 QMap<QString, DW_Stage_Value> single_index_vals;
 QMap<u4, DW_Stage_Value> multi_index_vals;

 DW_Stage_Value::Callback_type cb = [&single_index_vals, &multi_index_vals]
   (u4 u, QString col, DW_Stage_Value* v)
 {
  if(u)
    multi_index_vals[u] = *v;
  else
    single_index_vals[col] = *v;

  qDebug() << "u = " << u << ", col = " << col; 
 };

 if(pkg)
 {
  result = test_register_value(type_name, v, cb, &pkg->qba);
  pkg->single_indexed = single_index_vals;
  pkg->multi_indexed = multi_index_vals;
 }
 else
   result = test_register_value(type_name, v, cb);

 return result;
}

QString DW_Instance::test_register_value(QString type_name, void* v, DW_Stage_Value::Callback_type cb, QByteArray* qba)
{
 QString result;
 DW_Type* dwt = type_system_->get_type_by_name(type_name, &result);
 std::function<void(void*, QByteArray& qba, 
   DW_Stage_Value::Callback_type cb)> fn = dwt->stage_encoder();
 if(qba)
 {
  fn(v, *qba, cb);
 }
 else
 {
  QByteArray qba;
  fn(v, qba, cb);
 }
 return result;
}

void DW_Instance::restore_from_file(QString rf)
{
 wdb_instance_->load_from_file(rf);
}


void DW_Instance::save_changes()
{
 wdb_instance_->save_to_local_file(db_root_folder_, file_name_);
}

DW_Frame* DW_Instance::new_frame()
{
 return new DW_Frame(this);
}

DW_Record DW_Instance::new_wg_index_record(const DW_Record& ref, const DW_Stage_Value& dwsv, 
  QString label)
{  
 u4 id = new_index_record_id();

 DW_Stage_Value col_3;
 col_3.set_u4_data(ref.id());

 QMap<u4, DW_Stage_Value> svs {{3, col_3}, {4, dwsv} };

 if(Config.flags.avoid_record_pointers)
 {
  return wdb_instance_->new_wg_record(id, label, nullptr, svs);
 }
 DW_Stage_Value col_2;
 col_2.set_rec_data(ref.wg_record());
 svs.insert(2, col_2);
 return wdb_instance_->new_wg_record(id, label, nullptr, svs);
}

DW_Record DW_Instance::query_by_index_record(DW_Stage_Value& dwsv, QString label)
{
 u4 param_column = 4;
 void* result = wdb_instance_->query_within_id_range(0, indexes_mask, max_mask, 
   param_column, dwsv, label);

 if(result)
 {
  u4 refid = 0;
  void* ref = wdb_instance_->get_index_record_ref_target(result, &refid);   
  return {refid, ref};
 }

 return {0, nullptr}; 
}


void DW_Instance::get_hypernode_payload(u4 id, QByteArray& qba)
{
 void* rec = wdb_instance_->get_record_by_id(id);
 if(rec)
 {
  wdb_instance_->get_qba_from_record(rec, 1, qba);
 }
}

void DW_Instance::get_hypernode_payload(const DW_Record& dwr, QByteArray& qba)
{
 if(dwr.wg_record())
   wdb_instance_->get_qba_from_record(dwr.wg_record(), 1, qba);
}


void DW_Instance::to_ntxh(QString& ty, QString& result)
{
 ty = R"(&type DW_Instance {2}
  :folder:1 :cc:2 ;
 )";

 result = QString(R"(!/ DW_Instance
$folder: %1
$cc: %2
/!

<+>
)").arg(db_root_folder_).arg(Config.Flags);
}

void DW_Instance::reinit()
{
 Config.flags.temp_reinit = true;
 wdb_instance_ = wdb_manager_->check_reinit();
 Config.flags.temp_reinit = false;
}

void DW_Instance::init()
{
 type_system_ = new DW_Type_System; 
 wdb_manager_ = new WDB_Manager(this);
 wdb_manager_->set_db_root_folder(db_root_folder_);
 wdb_manager_->init_from_ntxh();
 wdb_instance_ = wdb_manager_->get_current_white();
}

QString DW_Instance::get_restore_file()
{
 QString result = wdb_instance_->get_local_file_name(db_root_folder_, file_name_);
 if(!result.isEmpty())
 {
  QFileInfo qfi(result);
  if(qfi.exists())
    return result;
 } 
 return {};
}


void DW_Instance::init_from_ntxh(QString fld, u1 code)
{
 db_root_folder_ = fld;
 Config.Flags = code;
}

u4 DW_Instance::new_index_label_id()
{
 ++current_index_label_count_;
 return current_index_label_count_;
}

u4 DW_Instance::new_index_record_id()
{
 ++current_index_record_count_;
 return current_index_record_count_ | indexes_mask;
}

u4 DW_Instance::new_multi_index_record_id()
{
 ++current_multi_index_record_count_;
 return current_multi_index_record_count_ | multi_indexes_mask;
}

u4 DW_Instance::new_double_edges_record_id()
{
 ++current_double_edges_record_count_;
 return current_double_edges_record_count_ | double_edges_mask;
}

u4 DW_Instance::new_inedges_record_id()
{
 ++current_inedges_record_count_;
 return current_inedges_record_count_ | inedges_mask;
}

u4 DW_Instance::new_outedges_record_id()
{
 ++current_outedges_record_count_;
 return current_outedges_record_count_ | outedges_mask;
}



u4 DW_Instance::new_hypernode_record_id()
{
 ++current_hypernode_record_count_;
 return current_hypernode_record_count_ | hypernodes_id_minimum;
}

DW_Record DW_Instance::new_wg_index_label_record(QString label)
{
 u4 id = new_index_label_id();

  // // 3 columns?
 void* result = wdb_instance_->new_wg_record(3, id, label);
 return {id, result};
}

DW_Record DW_Instance::new_wg_hypernode_record(const QByteArray& qba)
{
 u4 base_id = new_hypernode_record_id();
 //base_id <<= 13;
 void* result = wdb_instance_->new_wg_record(7, base_id);
 
 wdb_instance_->set_qba_record_field(result, 1, qba);

 return {base_id, result};
}

DW_Record DW_Instance::add_hyperedge(DW_Record& source, QString connector, const DW_Record* annotation, 
  DW_Record& target)
{
 QPair<QPair<QString, DW_Record>, DW_Record> edge = annotation? 
   QPair<QPair<QString, DW_Record>, DW_Record>{{connector, *annotation}, target}
   : QPair<QPair<QString, DW_Record>, DW_Record>{{connector, {0, nullptr} }, target};

 QVector<QPair<QPair<QString, DW_Record>, DW_Record>> targets {edge};

 return new_wg_outedges_record(source, targets);
}

DW_Record DW_Instance::add_hyperedge(DW_Record& source, QString connector, const DW_Record& annotation, 
  DW_Record& target)
{
 return add_hyperedge(source, connector, &annotation, target);
}

DW_Record DW_Instance::add_hyperedge(DW_Record& source, QString connector, DW_Record& target)
{
 return add_hyperedge(source, connector, nullptr, target);
}

u4 DW_Instance::commit_new_triples(QVector<String_Label_Triple>& triples)
{
 u4 result = 0;
 for(String_Label_Triple& triple : triples)
 {
  ++result;
  qDebug() << triple.connector_label;
  add_hyperedge(*triple.source, triple.connector_label, *triple.target);
 }
 return result;
}

void DW_Instance::_set_raw_record_fields(void* rec, u4 start_col, QVector<DW_Stage_Value>& svs)
{
 for(u4 u = 0; u < svs.size(); ++u)
 {
  wdb_instance_->set_record_field(rec, u + start_col, svs[u]); 
 }
}

void* DW_Instance::query_leading_rec(u4 col)
{
 return wdb_instance_->query_leading_rec(col);
}

void* DW_Instance::query_leading_str(u4 col)
{
 return wdb_instance_->query_leading_str(col);
}

void* DW_Instance::query_leading_int(u4 col)
{
 return wdb_instance_->query_leading_int(col);
}

void* DW_Instance::_add_raw_record(u4 number_of_columns, QVector<DW_Stage_Value>& svs)
{
 void* result = wdb_instance_->new_wg_record(number_of_columns);
 
 if(number_of_columns > svs.size())
   number_of_columns = svs.size();
 for(u4 u = 0; u < number_of_columns; ++u)
 {
  wdb_instance_->set_record_field(result, u, svs[u]); 
 }
 
 return result;
}

DW_Record DW_Instance::new_wg_outedges_record(DW_Record& ref, 
  QVector<QPair<QPair<QString, DW_Record>, DW_Record>>& targets)
{
 DW_Record result = wdb_instance_->check_reset_ref_field(ref, 3, targets.size() * 3);
  //, 
  //[this]() { return new_outedges_record_id(); });

 if(result.id() == 0)
 {
  u4 new_id = new_outedges_record_id();
  wdb_instance_->set_record_id_field(result.wg_record(), new_id); 
  result.set_id(new_id);
 }
  
 wdb_instance_->populate_edges_record(result, ref, targets); 
}

DW_Record DW_Instance::new_wg_inedges_record(const QByteArray& qba)
{
 u4 base_id = new_hypernode_record_id();

}
 
DW_Record DW_Instance::new_wg_findable_field_record(const QByteArray& qba)
{
 u4 base_id = new_hypernode_record_id();

}








