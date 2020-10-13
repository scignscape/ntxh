
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

#include "accessors.h"

#include "kans.h"

KANS_(DGDB)


class WDB_Instance
{
 void* white_;
 QString name_;

 enum DateTime_Codes {
   Recent_Create = 1, Recent_Load_From_File = 2,
   Created = 3, Last_Load_From_File = 4, Recent_Attach = 5
  };

 QMap<u1, QDateTime> datetimes_; 

public:

 WDB_Instance(void* w, QString n = {}); 

 ACCESSORS(void* ,white)

 void* new_wg_record(QMap<u4, DW_Stage_Value>& svs);
 void decode_wg_record_value(void* rec, u4 index, DW_Stage_Value& dwsv);

 void get_qba_from_record(void* rec, u4 field_number, QByteArray& qba);
 void set_qba_record_field(void* rec, u4 field_number, QByteArray& qba);
 void set_qba_record_field(void* rec, u4 field_number, const QByteArray& qba);

 void set_creation_datetime(QDateTime dtm);
 void set_creation_datetime();

 void* get_record_by_id(u4 id);
// void get_record_field(void* rec, u4 field_number, QByteArray& qba);

 void* new_wg_record(u4 number_of_columns, u4 col1, QString col2);
 void* new_wg_record(u4 number_of_columns);
 void* new_wg_record(u4 number_of_columns, u4 col1);

// void set_record_field(void* rec, u4 field_number, const QByteArray& qba);


 static QString static_to_ntxh(); 
 void to_ntxh(QString& result);

};


_KANS(DGDB)


#endif // WDB_INSTANCE__H


