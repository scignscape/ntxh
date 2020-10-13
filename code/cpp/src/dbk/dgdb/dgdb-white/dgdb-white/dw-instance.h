
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

class DW_Instance
{
 QString db_root_folder_;
 WDB_Instance* wdb_instance_;
 WDB_Manager* wdb_manager_;

 u4 startup_hypernode_record_count_; 
 u4 current_hypernode_record_count_;

 u4 startup_index_record_count_; 
 u4 current_index_record_count_;

 u4 startup_index_label_count_; 
 u4 current_index_label_count_;

 u4 new_hypernode_record_id();
 u4 new_index_record_id();
 u4 new_index_label_id();


public:

 struct _Config
 {
  flags_(1)
   bool scratch_mode:1;
   bool local_scratch_mode:1;
   bool auto_stage:1;
   bool auto_commit:1;
  _flags

  _Config() : Flags(0) {}  
 };

 _Config Config; 

 ACCESSORS(QString ,db_root_folder)
 ACCESSORS(WDB_Instance* ,wdb_instance)

 DW_Instance();

 void init(); 

 void to_ntxh(QString& ty, QString& result);
 void init_from_ntxh(QString fld, u1 code);

 DW_Record new_wg_hypernode_record(const QByteArray& qba);
 DW_Record new_wg_outedges_record(const QByteArray& qba);
 DW_Record new_wg_inedges_record(const QByteArray& qba);
 DW_Record new_wg_findable_field_record(const QByteArray& qba);
 DW_Record new_wg_index_label_record(QString label);

 DW_Record new_wg_index_record(const DW_Record& ref, const DW_Stage_Value& dwsv);

 void get_hypernode_payload(u4 id, QByteArray& qba);
 void get_hypernode_payload(const DW_Record& dwr, QByteArray& qba);

 DW_Record query_by_index_record(DW_Stage_Value& dwsv);
 

};


_KANS(DGDB)

#endif // DGDB_INSTANCE__H
