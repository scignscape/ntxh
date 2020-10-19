
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef WDB_INSTANCE__H
#define WDB_INSTANCE__H

#include <QString>
#include <QMap>
#include <QDateTime>

#include "global-types.h"

#include "dw-stage-value.h"
#include "dw-record.h"

#include "accessors.h"

#include "kans.h"

KANS_(DGDB)

class DW_Instance;

class WDB_Instance
{
 DW_Instance* dw_instance_;

 void* white_;
 QString name_;
 u2 num_code_;

 enum DateTime_Codes {
   Recent_Create = 1, Recent_Load_From_File = 2,
   Created = 3, Last_Load_From_File = 4, Recent_Attach = 5
  };

 QMap<u1, QDateTime> datetimes_; 

 void* _new_wg_record(u4 id, QString col1, void* col2, QMap<u4, DW_Stage_Value>& svs);

public:

 WDB_Instance(DW_Instance* dw_instance, void* w, QString n = {}); 

 ACCESSORS(void* ,white)
 ACCESSORS(u2 ,num_code)

 void save_to_local_file(QString folder, QString file_name);
 QString get_local_file_name(QString folder, QString file_name);

 void* query_within_id_range(u4 range_col, u4 low, u4 high, 
   u4 param_column, DW_Stage_Value dwsv, QString label = {}, u4 label_column = 1);

 void* new_wg_record(QMap<u4, DW_Stage_Value>& svs);
 DW_Record new_wg_record(u4 id, QString col1, void* col2, QMap<u4, DW_Stage_Value>& svs);

//? void* new_wg_record(u4 id, const QVector<DW_Stage_Value>& svs);

 void decode_wg_record_value(void* rec, u4 index, DW_Stage_Value& dwsv);

 void load_from_file(QString rf);

 void set_wg_record_field_rec(DW_Record& dr, u4 col, DW_Record& rec);
 n8 wg_encode_dw_record(DW_Record& rec);
 n8 check_wg_encode_dw_record(void* v);

 //void avoid_record_pointers


 void get_qba_from_record(void* rec, u4 field_number, QByteArray& qba);
 void set_qba_record_field(void* rec, u4 field_number, QByteArray& qba);
 void set_qba_record_field(void* rec, u4 field_number, const QByteArray& qba);

 void set_creation_datetime(QDateTime dtm);
 void set_creation_datetime();

 void* query_leading_rec(u4 col);
 void* query_leading_str(u4 col);
 void* query_leading_int(u4 col);

 void* get_record_by_id(u4 id);
 u4 get_record_id(void* rec);
 void* get_index_record_ref_target(void* rec, u4* and_ref_id = nullptr);

 void set_record_id_field(void* rec, u4 id);
 n8 set_record_field(void* rec, u4 col, DW_Stage_Value& dwsv);


 void* new_wg_record(u4 number_of_columns, u4 col1, QString col2);
 void* new_wg_record(u4 number_of_columns);
 void* new_wg_record(u4 number_of_columns, u4 col1);

 DW_Record check_reset_ref_field(DW_Record& ref, u4 col, u4 new_size); //, u4 (*fn)() );

 void populate_edges_record(DW_Record& new_rec, DW_Record& ref, 
   QVector<QPair<QPair<QString, DW_Record>, DW_Record>>& targets);

// void set_record_field(void* rec, u4 field_number, const QByteAfrray& qba);


 static QString static_to_ntxh(); 
 void to_ntxh(QString& result);

};


_KANS(DGDB)


#endif // WDB_INSTANCE__H


