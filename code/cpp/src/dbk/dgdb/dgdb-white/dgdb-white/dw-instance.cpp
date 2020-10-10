//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dw-instance.h"

#include "wdb-instance.h"



USING_KANS(DGDB)


DW_Instance::DW_Instance()
  :  wdb_instance_(nullptr), 
     startup_record_count_(0), 
     current_record_count_(0),
     startup_index_label_count_(0),
     current_index_label_count_(0)
{

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

void* DW_Instance::new_wg_index_label_record(QString label)
{
 u4 id = new_index_label_id();

  // // 3 columns?
 void* result = wdb_instance_->new_wg_record(3, id, label);
 return result;
}

void* DW_Instance::new_wg_hypernode_record(QByteArray& qba)
{
 u4 base_id = new_base_record_id();
 base_id <<= 13;
 void* result = wdb_instance_->new_wg_record(5, base_id);
 return result;
}

void* DW_Instance::new_wg_outedges_record(QByteArray& qba)
{
 u4 base_id = new_base_record_id();

}

void* DW_Instance::new_wg_inedges_record(QByteArray& qba)
{
 u4 base_id = new_base_record_id();

}
 
void* DW_Instance::new_wg_findable_field_record(QByteArray& qba)
{
 u4 base_id = new_base_record_id();

}








