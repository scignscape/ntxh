//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dw-instance.h"

#include "types/dw-type-system.h"
#include "types/dw-type.h"

#include "stage/dw-stage-queue.h"

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
     startup_subvalues_record_count_(0),
     current_subvalues_record_count_(0),
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
     startup_properties_record_count_(0), 
     current_properties_record_count_(0)
{

}

DW_Record DW_Instance::register_typed_value(QString type_name, DW_Stage_Value::Package& pkg)
{
 DW_Record result = new_binary_hypernode_record(pkg.qba);

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

DW_Record DW_Instance::get_multi_index_record(DW_Record dr)
{
  //   column 4 is ref to multi_index_record ...
 return wdb_instance_->get_multi_index_record(dr, 4);
}

DW_Record DW_Instance::add_subvalues_record(DW_Record dr, u4 len)
{
 u4 new_id = new_subvalues_record_id();
  // //  column 3 is ref to subvalues record ...
   //    len + 3 leaves room for the two id's and the base record ...
 void* result = wdb_instance_->init_subvalues_record(dr, len + 3, 3, new_id);
 return {new_id, result};
}

DW_Record DW_Instance::add_subvalues_record(DW_Record dr, QStringList qsl)
{
 DW_Record result = add_subvalues_record(dr, qsl.size());
 u4 col = 3;
 for(QString qs : qsl)
 {
  wdb_instance_->set_wg_record_field_str(result, col, qs);
  ++col; 
 }
 return result;
}

DW_Record DW_Instance::get_subvalues_record(DW_Record dr, QStringList& qsl)
{
  // // col 3 is subvalues ...
 DW_Record result = wdb_instance_->get_subvalues_record(dr, 3);

 if(result.wg_record() == nullptr)
   return {0, nullptr};

  // // col 3 is start of actual values ...
 wdb_instance_->read_subvalues(result, qsl, 3);
 return result;
}

void DW_Instance::parse_binary_record(DW_Record dr, 
  void* v, std::function<void(void*, const QByteArray&)> cb, u4 qba_index)
{
 QByteArray qba;
 get_hypernode_payload(dr, qba, qba_index);
 cb(v, qba); 
}

void* DW_Instance::parse_dw_record(DW_Record dr, std::function<void(const QByteArray&, 
  QMap<u4, DW_Stage_Value>&, DW_Stage_Queue& sq)> cb, u4 qba_index, 
  std::function<void(QQueue<void*>&)> qcb)
{
 QByteArray qba;

 get_hypernode_payload(dr, qba, qba_index);

 if(qba.isEmpty())
   // // somehow the payload wasn't found
   return nullptr;

 // // get the multi_index_record ...
 DW_Record mir = get_multi_index_record(dr);

 void* mirv = mir.wg_record();

 if(!mirv)
   return nullptr;

 QMap<u4, DW_Stage_Value> qm;

 DW_Stage_Queue sq;
 cb(qba, qm, sq); //, qv);

 QMutableMapIterator<u4, DW_Stage_Value> it(qm);
 while(it.hasNext())
 {
  it.next();
  u4 index = it.key();
  DW_Stage_Value dwsv = it.value();
  wdb_instance_->decode_wg_record_value(mirv, index, dwsv);
 }

 if(!sq.values.isEmpty())
 {
  void* result = sq.head();
  if(sq.callback)
    sq.callback(sq.values);
  else if(qcb)
  {   
   qcb(sq.values);
  }
  return result;
 }

 return nullptr;
 
}

//std::function<void(QQueue<void*>&)> DW_Instance::get_stage_queue_reader(DW_Type* dt)

std::function<void(QQueue<void*>&)> DW_Instance::get_stage_queue_reader(DW_Type* dt)
{
 return dt->stage_queue_reader();
}

std::function<void(void*, QByteArray&)> DW_Instance::get_binary_encoder(DW_Type* dt)
{
 return dt->binary_encoder();
}

std::function<void(void*, const QByteArray&)> DW_Instance::get_binary_decoder(DW_Type* dt)
{
 return dt->binary_decoder();
}

void* DW_Instance::parse_dw_record(DW_Record dr, QString ctn, u4 qba_index, 
  std::function<void(QQueue<void*>&)> qcb)
{
 DW_Type* dt = get_type_by_name(ctn);
 return parse_dw_record(dr, dt->stage_queue_initializer(), qba_index, qcb);
}


DW_Type* DW_Instance::get_type_by_name(QString ctn)
{
 QString tn;
 DW_Type* result = type_system_->get_type_by_name(ctn, &tn);
 return result;
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

DW_Record DW_Instance::new_wg_index_record(DW_Record ref, const DW_Stage_Value& dwsv, 
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


DW_Record DW_Instance::query_by_multi_index_record(DW_Stage_Value& dwsv, QString type_name, u4 col)
{
 return query_by_index_record(dwsv, type_name, col, multi_indexes_mask, properties_mask, 
   Config.flags.avoid_record_pointers? 2 : 0);
}


DW_Record DW_Instance::query_by_index_record(DW_Stage_Value& dwsv, QString label)
{
 return query_by_index_record(dwsv, label, 4, indexes_mask, max_mask, 3);
}

DW_Record DW_Instance::query_by_index_record(DW_Stage_Value& dwsv, QString label, 
  u4 param_column, u4 id_min, u4 id_max, u4 ref_id_column)
{
 void* result = wdb_instance_->query_within_id_range(0, id_min, id_max,  
   param_column, dwsv, label);

 if(result)
 {
  u4 refid = 0;
  void* ref = wdb_instance_->get_index_record_ref_target(result, ref_id_column, &refid);   
  return {refid, ref};
 }

 return {0, nullptr}; 
}


void DW_Instance::get_hypernode_payload(u4 id, QByteArray& qba, u4 qba_index)
{
 void* rec = wdb_instance_->get_record_by_id(id);
 if(rec)
 {
  wdb_instance_->get_qba_from_record(rec, qba_index, qba);
 }
}

void DW_Instance::get_hypernode_payload(DW_Record dwr, QByteArray& qba, u4 qba_index)
{
 if(dwr.wg_record())
   wdb_instance_->get_qba_from_record(dwr.wg_record(), qba_index, qba);
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

u4 DW_Instance::new_properties_record_id()
{
 ++current_properties_record_count_;
 return current_properties_record_count_ | properties_mask;
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

u4 DW_Instance::new_subvalues_record_id()
{
 ++current_subvalues_record_count_;
 return current_subvalues_record_count_ | subvalues_mask;
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

DW_Record DW_Instance::new_binary_hypernode_record(const QByteArray& qba)
{
 u4 base_id = new_hypernode_record_id();
 //base_id <<= 13;
 void* result = wdb_instance_->new_wg_record(7, base_id);
 
 wdb_instance_->set_qba_record_field(result, 1, qba);

 return {base_id, result};
}

DW_Record DW_Instance::add_hyperedge_or_property(DW_Record& source, QString connector, 
  const DW_Record* annotation, DW_Record& target, u4 property_code)
{
 QPair<QPair<QString, DW_Record>, DW_Record> edge = annotation? 
   QPair<QPair<QString, DW_Record>, DW_Record>{{connector, *annotation}, target}
   : QPair<QPair<QString, DW_Record>, DW_Record>{{connector, {0, nullptr} }, target};

 QVector<QPair<QPair<QString, DW_Record>, DW_Record>> targets {edge};

 if(property_code == 0)
   return new_outedges_record(source, targets);
 else
   return new_properties_record(source, targets);
}

DW_Record DW_Instance::add_hyperedge(DW_Record& source, QString connector, const DW_Record& annotation, 
  DW_Record& target)
{
 return add_hyperedge_or_property(source, connector, &annotation, target);
}

DW_Record DW_Instance::add_hyperedge(DW_Record& source, QString connector, DW_Record& target)
{
 return add_hyperedge_or_property(source, connector, nullptr, target);
}


DW_Record DW_Instance::add_property(DW_Record& source, QString connector, const DW_Record& annotation, 
  DW_Record& target, u4 property_code)
{
 return add_hyperedge_or_property(source, connector, &annotation, target, property_code);
}

DW_Record DW_Instance::add_property(DW_Record& source, QString connector, 
  DW_Record& target, u4 property_code)
{
 return add_hyperedge_or_property(source, connector, nullptr, target, property_code);
}


QPair<u4, u4> DW_Instance::commit_new_triples(QVector<String_Label_Triple>& triples)
{
 QPair<u4, u4> result = {0, 0};
 for(String_Label_Triple& triple : triples)
 {
  if(triple.property_kind > 0)
  {
   ++result.first;
   qDebug() << "adding property ..." << triple.connector_label;
   add_property(*triple.source, triple.connector_label, *triple.target, triple.property_kind);
  }
  else
  {
   ++result.second; 
   qDebug() << "adding hyperedge ..." << triple.connector_label;
   add_hyperedge(*triple.source, triple.connector_label, *triple.target);
  }
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

DW_Record DW_Instance::new_outedges_record(DW_Record base, 
  QVector<QPair<QPair<QString, DW_Record>, DW_Record>>& targets)
{
  // // col 5 is outedges ...
 return new_outedges_or_property_record(base, 5, &DW_Instance::new_outedges_record_id, targets);
}

DW_Record DW_Instance::new_properties_record(DW_Record base, 
  QVector<QPair<QPair<QString, DW_Record>, DW_Record>>& targets)
{
  // // col 6 is properties ...
 return new_outedges_or_property_record(base, 6, &DW_Instance::new_properties_record_id, targets);
}

DW_Record DW_Instance::new_outedges_or_property_record(DW_Record base, 
  u4 col, u4 (DW_Instance::*cb)(),
  QVector<QPair<QPair<QString, DW_Record>, DW_Record>>& targets)
{
 DW_Record result = wdb_instance_->check_reset_ref_field(base, col, targets.size() * 3);
  //, 
  //[this]() { return new_outedges_record_id(); });

 if(result.id() == 0)
 {
  u4 new_id = (this->*cb)();
  wdb_instance_->set_record_id_field(result.wg_record(), new_id); 
  result.set_id(new_id);

  if(Config.flags.avoid_record_pointers)
    // //  need to swap 1024 with the valid id ...
    wdb_instance_->set_wg_record_field_int(base, col, new_id);

 }
  
 wdb_instance_->populate_edges_or_property_record(result, base, targets); 
}

DW_Record DW_Instance::get_outedges_record(DW_Record base)
{
 DW_Record result = wdb_instance_->get_outedges_record(base, 5);
 return result;
}

DW_Record DW_Instance::find_hyperedge(DW_Record base, QString label)
{
 DW_Record outs = get_outedges_record(base);
 DW_Record ann;
 DW_Record result = wdb_instance_->match_edges_label(outs, label, ann, 3, 3);
 return result;
}

DW_Record DW_Instance::new_wg_inedges_record(const QByteArray& qba)
{
 u4 base_id = new_hypernode_record_id();

}
 
DW_Record DW_Instance::new_wg_findable_field_record(const QByteArray& qba)
{
 u4 base_id = new_hypernode_record_id();

}








