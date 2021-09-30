
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DWB_INSTANCE__H
#define DWB_INSTANCE__H

#include <QByteArray>

#include <functional>

#include "global-types.h"

#include "accessors.h"

#include <sys/types.h>


class DH_Stage_Value;

class DWB_Instance
{
 QString config_path_;
 QString restore_path_;

 void* wdb_instance_;

 key_t ftok_key_;

public:

 DWB_Instance(QString config_path, QString restore_path);


 ACCESSORS(QString ,config_path)

 ACCESSORS__GET(key_t ,ftok_key)

 enum class _DB_Create_Status
 {
  N_A = 0, Attached = 1,
  Created_Via_Restore = 2, Created_New = 4,
  FTOK_Failed = 8, Created_Restore_Failed = 16,
  Create_And_Restore_Failed = 32, Attach_Failed = 64
 };

 _DB_Create_Status check_init();

 QPair<void*, char*> new_block_record(u2 field_count, size_t block_size, u2 block_column);
 size_t write_record_pointer_bytes(void* rec, char* destination);
 void write_str_field(void* rec, u2 field_number, QString str);
 void write_u4_field(void* rec, u2 field_number, u4 value);
 void* get_record_from_block(char* block);
 QString get_string_from_record(void* rec, u2 field_number);
 void get_qba_from_record(void* rec, u2 field_number, QByteArray& result);

 u2 write_rec_field_via_split(char* ptr, u2 spl, DH_Stage_Value& sv); //const QByteArray& text);
 //void* get_record_via_split(char* ptr, u2 spl);

 void* get_record_from_qba(const QByteArray& qba);
 void* get_target_record_from_query_record(DWB_Instance* origin_dwb, void* qrec, u2 rec_column);

 void* find_query_record(u2 query_column, QString test); // u2 rec_column,
 void* find_query_record(u2 query_column, DH_Stage_Value& sv); // u2 rec_column,


 QPair<void*, QPair<u2, u2>> get_record_via_split(char* ptr, u2 spl);
 QPair<void*, u2> get_record_via_known_split(char* ptr, u2 spl);

 size_t write_max_fixed(u1 max_fixed, char* destination);
 u1 get_max_fixed_from_block(char* block);
 u1 get_max_used_from_block(char* block);
 u1 inc_max_used_from_block(char* block);

 QByteArray encode_record(void* rec);

 void* new_query_record(DWB_Instance* origin_dwb, void* target_record,
   u2 target_column, u2 value_column, DH_Stage_Value& sv, u2 field_count);

 u4 fetch_u4_field(void* rec, u2 dh_id_column);
 QPair<char*, size_t> fetch_blob_field(void* rec, u2 column);

};


#endif // DWB_INSTANCE__H


