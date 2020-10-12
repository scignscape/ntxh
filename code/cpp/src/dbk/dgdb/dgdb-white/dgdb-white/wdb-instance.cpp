
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "wdb-instance.h"

extern "C" {
#include "whitedb/_whitedb.h"
}

#include <QDebug>


USING_KANS(DGDB)


WDB_Instance::WDB_Instance(void* w, QString n)
  :  white_(w), name_(n)
{


}

void* WDB_Instance::new_wg_record(u4 number_of_columns)
{
 void* result = wg_create_record(white_, number_of_columns);
 return result;
}

void* WDB_Instance::get_record_by_id(u4 id)
{
 return wg_find_record_int(white_, 0, WG_COND_EQUAL, id, NULL);
}

void WDB_Instance::get_record_field(void* rec, u4 field_number, QByteArray& qba)
{
 wg_int data = wg_get_field(white_, rec, field_number);
 wg_int len = wg_decode_blob_len(white_, data);
 qba.resize(len);
 wg_int ok = wg_decode_blob_copy(white_, data, qba.data(), len);
}

void* WDB_Instance::new_wg_record(u4 number_of_columns, u4 col1)
{
 void* result = wg_create_record(white_, number_of_columns);
 wg_int c1val = wg_encode_int(white_, col1);
 wg_set_field(white_, result, 0, c1val);

 return result;
}

void WDB_Instance::set_record_field(void* rec, u4 field_number, const QByteArray& qba)
{
 wg_int enc = wg_encode_blob(white_, const_cast<char*>(qba.data()), NULL, qba.length());
 wg_set_field(white_, rec, field_number, enc);
}

void* WDB_Instance::new_wg_record(u4 number_of_columns, u4 col1, QString col2)
{
 void* result = wg_create_record(white_, number_of_columns);
 wg_int c1val = wg_encode_int(white_, col1);
 wg_int c2val = wg_encode_str(white_, col2.toLatin1().data(), NULL);

 wg_set_field(white_, result, 0, c1val);
 wg_set_field(white_, result, 1, c2val);
 return result;
}



QString WDB_Instance::static_to_ntxh()
{
 return R"(&type WDB_Instance {4}
  :name:1 :created:2 :attached:3 :llff:4 ;
 )";
}

void WDB_Instance::to_ntxh(QString& result)
{
 QString cr = datetimes_.value(Created).toString();
 QString ra = datetimes_.value(Recent_Attach).toString();
 QString llff = datetimes_.value(Last_Load_From_File).toString();

 result = QString(R"(!/ WDB_Instance
$name: %1
$created: %2
$attached: %3
$llff: %4
/!

<+>
)").arg(name_).arg(cr).arg(ra).arg(llff);

}


void WDB_Instance::set_creation_datetime()
{
 datetimes_.insert(Created, QDateTime::currentDateTime());
}

void WDB_Instance::set_creation_datetime(QDateTime dtm)
{
 datetimes_.insert(Created, dtm);
}


