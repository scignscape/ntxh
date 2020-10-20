
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "queue-demo-class.h"

#include <QDataStream>


Queue_Demo_Class::Queue_Demo_Class()
 : num_(0)
{

}

void Queue_Demo_Class::encode_stage_values(QByteArray& qba,
   DW_Stage_Value::Callback_type cb)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << DW_Stage_Value().set_str_data(title_).run[3](cb)
   // DW_Stage_Value().new_qstring("title_").run[3](cb)
   << author_
   << DW_Stage_Value().set_u2_data(num_).run["Book.Pages"](cb)
   << DW_Stage_Value().set_date_data(publication_date_).run[4](cb)
   << DW_Stage_Value().set_time_data(test_time_).run[5](cb)
//?   << DW_Stage_Value().set_xml_data(QString::number(num), "xs:integer")
//?     .run[5](cb)[XSD_TYPE_DECODING_Flag];
 ;
}

void Queue_Demo_Class::read_stage_queue(QQueue<void*>& vals)
{
 title_ = *(QString*) vals.dequeue();
 author_ = *(QString*) vals.dequeue();
 num_ = *(u2*) vals.dequeue();
 publication_date_ = *(QDate*) vals.dequeue();
 test_time_ = *(QTime*) vals.dequeue();
  //?QStringList qsl = *(QStringList*) vals.dequeue();
}


