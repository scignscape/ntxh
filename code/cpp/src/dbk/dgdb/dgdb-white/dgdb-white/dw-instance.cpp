//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dw-instance.h"

#include "wdb-instance.h"
#include "wdb-manager.h"

#include <QDebug>



USING_KANS(DGDB)


DW_Instance::DW_Instance()
  :  wdb_instance_(nullptr), wdb_manager_(nullptr),
     startup_record_count_(0), 
     current_record_count_(0),
     startup_index_label_count_(0),
     current_index_label_count_(0)
{

}

void DW_Instance::get_hypernode_payload(u4 id, QByteArray& qba)
{
 void* rec = wdb_instance_->get_record_by_id(id);
 if(rec)
 {
  wdb_instance_->get_record_field(rec, 1, qba);
 }
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

void DW_Instance::init()
{ 

 // // temporary for testing ...
 // Config.flags.local_scratch_mode = true;
  

 wdb_manager_ = new WDB_Manager(this);
 wdb_manager_->set_db_root_folder(db_root_folder_);
 wdb_manager_->init_from_ntxh();
 wdb_instance_ = wdb_manager_->get_current_white();
}

void DW_Instance::init_from_ntxh(QString fld, u1 code)
{
 db_root_folder_ = fld;
 Config.Flags = code;
}

u4 DW_Instance::new_index_label_id()
{
 ++current_index_label_count_;
 return current_record_count_;
}

u4 DW_Instance::new_base_record_id()
{
 ++current_record_count_;
 return current_record_count_;
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
 u4 base_id = new_base_record_id();
 base_id <<= 13;
 void* result = wdb_instance_->new_wg_record(5, base_id);
 
 wdb_instance_->set_record_field(result, 1, qba);

 return {base_id, result};
}

DW_Record DW_Instance::new_wg_outedges_record(const QByteArray& qba)
{
 u4 base_id = new_base_record_id();

}

DW_Record DW_Instance::new_wg_inedges_record(const QByteArray& qba)
{
 u4 base_id = new_base_record_id();

}
 
DW_Record DW_Instance::new_wg_findable_field_record(const QByteArray& qba)
{
 u4 base_id = new_base_record_id();

}








