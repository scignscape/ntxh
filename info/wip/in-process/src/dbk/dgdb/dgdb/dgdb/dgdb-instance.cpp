
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgdb-instance.h"

#include "graph/dgdb-node.h"
#include "graph/dgdb-frame.h"

#include "types/dgdb-type-builder.h"
#include "types/dgdb-type.h"

#include "wdb-manager.h"

#include <typeinfo>
#include <QDebug> 

USING_KANS(DGDB)

DgDb_Instance::DgDb_Instance()
{
 default_frame_ = new DgDb_Frame();
 current_frame_ = default_frame_;
 current_type_builder_ = new DgDb_Type_Builder;
 wdb_manager_ = new WDB_Manager(this);
}

void DgDb_Instance::to_ntxh(QString& ty, QString& result)
{
 ty = R"(&type DgDb_Instance {2}
  :folder:1 :cc:2 ;
 )";

 result = QString(R"(!/ DgDb_Instance
$folder: %1
$cc: %2
/!

<+>
)").arg(db_root_folder_).arg(Config.Flags);

}

void* DgDb_Instance::new_wg_record(QByteArray& qba, QMap<u4, WG_Stage_Value>& wsvs,
  u4 qba_index, WDB_Instance* wdbi)
{
 void* pv = wdb_manager_->new_wg_record(wsvs, wdbi);
 wdb_manager_->set_qba_data_field(pv, qba, qba_index);
 return pv;
}

void DgDb_Instance::parse_wg_record(void* rec, 
  std::function<void(const QByteArray& qba, QMap<u4, WG_Stage_Value>&, 
  WG_Stage_Queue&)> cb, u4 qba_index, WDB_Instance* wdbi)
{
 QByteArray qba;
 wdb_manager_->get_qba_from_record(rec, qba, qba_index, wdbi);
 QMap<u4, WG_Stage_Value> qm;
 //QQueue<void*> qv;

 WG_Stage_Queue sq;
 cb(qba, qm, sq); //, qv);

 QMutableMapIterator<u4, WG_Stage_Value> it(qm);
 while(it.hasNext())
 {
  it.next();
  u4 index = it.key();
  //u1 info = it.value().get_encoding_type();
  
  wdb_manager_->decode_value(rec, index, it.value(), wdbi);

//  qDebug() << "inx: " << index;
//  qDebug() << "inf: " << info;
 }

 if(sq.values.isEmpty())
 {
  if(sq.callback)
    sq.callback(sq.values);
 }
 else if(sq.callback)
   sq.callback(sq.values);
 else
 {
  // // some sort of type default ...
 }
}

void DgDb_Instance::init_from_ntxh(QString fld, u1 code)
{
 Config.Flags = code;
}

void DgDb_Instance::init()
{
 wdb_manager_->set_db_root_folder(db_root_folder_);
 wdb_manager_->init_from_ntxh();
 wdb_manager_->get_current_white();
}

DgDb_Type& DgDb_Instance::register_type(QString tn, QString ctn)
{
 DgDb_Type* result = get_type_by_name(tn);
 if(!result)
 {
  result = new DgDb_Type();
  result->set_name(tn);
  result->set_cname(ctn);
  types_by_name_[tn] = result;
 }
 return *result;
}

void DgDb_Instance::build_default_types()
{
 current_type_builder_->build(&types_by_name_);
}

DgDb_Type* DgDb_Instance::get_type_by_name(QString tn)
{
 return types_by_name_.value(tn);
}

DgDb_Node* DgDb_Instance::_add(void* v, QString tn)
{
 DgDb_Node* result = new DgDb_Node(v);
 current_frame_->add(result);
 return result;
}


