
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "wdb-instance.h"


USING_KANS(DGDB)


WDB_Instance::WDB_Instance(void* w, QString n)
  :  white_(w), name_(n)
{


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


