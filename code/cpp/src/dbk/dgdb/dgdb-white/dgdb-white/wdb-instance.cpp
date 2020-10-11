
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

void* WDB_Instance::new_wg_record(u4 number_of_columns, u4 col1)
{
 qDebug() << "nc: " << number_of_columns << ", col1: " << col1;
 void* result = wg_create_record(white_, number_of_columns);

 wg_int c1val = wg_encode_int(white_, col1);
 wg_set_field(white_, result, 0, c1val);

 return result;
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


