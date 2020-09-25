
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef WDB_MANAGER__H
#define WDB_MANAGER__H

#include <QMap>
#include <QString>

#include "global-types.h"

#include "accessors.h"


#include "kans.h"

KANS_(DGDB)

class WDB_Instance;
class DgDb_Instance;
class WG_Stage_Value;

class WDB_Manager
{
 DgDb_Instance* dgdb_instance_;

 u2 max_num_code_;
 u8 default_mem_size_;

 QMap<u2, WDB_Instance*> whites_;
 QMap<QString, WDB_Instance*> whites_by_name_;

 WDB_Instance* current_white_;  

 QString db_root_folder_;

 void to_ntxh(QString& result);
 void update_ntxh();


public:

 WDB_Manager(DgDb_Instance* dgdb_instance);

 ACCESSORS(u8 ,default_mem_size)

 ACCESSORS(WDB_Instance* ,current_white)
 ACCESSORS(QString ,db_root_folder)

 void init_from_ntxh();

 void decode_value(void* rec, u4 index, 
   WG_Stage_Value& wgsv, WDB_Instance* wdbi = nullptr);

 void set_qba_data_field(void* rec, QByteArray& qba, 
   u4 qba_index = 0, WDB_Instance* wdbi = nullptr);

 void* new_wg_record(QMap<u4, WG_Stage_Value>& wsvs,
   WDB_Instance* wdbi = nullptr);

 void get_qba_from_record(void* rec, QByteArray& qba, 
   u4 qba_index = 0, WDB_Instance* wdbi = nullptr);

 WDB_Instance* get_current_white();
 WDB_Instance* get_white(QString name);

 WDB_Instance* new_white(u2 num_code = 0, u8 mem = 0, QString name = {});
 WDB_Instance* new_white(QString name)
 {
  return new_white(0, 0, name);
 }
 WDB_Instance* new_white(u2 num_code, QString name)
 {
  return new_white(num_code, 0, name);
 }

};


_KANS(DGDB)


#endif // WDB_MANAGER__H


