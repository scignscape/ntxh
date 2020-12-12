
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "gtagml-document-info.h"

#include <QDataStream>

#include "textio.h"
USING_KANS(TextIO)

GTagML_Document_Info::GTagML_Document_Info()
{

}

void GTagML_Document_Info::load_marks(QString path)
{
 mark_map_type* marks_by_mode [5] = {&auxiliary_mark_map_,
   &main_mark_map_, &optional_argument_mark_map_,
   &main_mark_map_, &mandatory_argument_mark_map_};

 u4 current_index = 0;
 u1 current_mode = 0;
 u4 last_index = 0;
 u1 last_mode = 0;

 load_file(path, [this, marks_by_mode, &current_index,
   &current_mode, &last_index, &last_mode](QString& line) -> int
 {
  if(line.isEmpty())
    return 0;
  if(line.startsWith("= "))
  {
   line = line.mid(2).trimmed();
   if(line.endsWith(':'))
   {
    line.chop(1);
    last_index = current_index;
    current_index = line.toUInt();
   }
   else
   {
    last_mode = current_mode;
    current_mode = line.toUInt();
    if(current_mode == 9)
    {
     (*marks_by_mode[last_mode])[last_index].second = current_index;
    }
   }
  }
  else
  {
   (*marks_by_mode[current_mode])[current_index] = {line, 0};
  }
  return 0;
 });
}

void GTagML_Document_Info::encode_stage_values(QByteArray& qba,
  DW_Stage_Value::Callback_type cb)
{

}

void GTagML_Document_Info::read_stage_queue(QQueue<void*>& vals)
{
 created_ = *(QDateTime*) vals.dequeue();
 modified_ = *(QDateTime*) vals.dequeue();
}

void GTagML_Document_Info::init_stage_queue(const QByteArray& qba,
  QMap<u4, DW_Stage_Value>& qm, DW_Stage_Queue& sq)
{
}



//void GTagML_Document_Info::supply_data(QByteArray& qba)
//{
// QDataStream qds(&qba, QIODevice::WriteOnly);
// qds << a_string_ << a_number_;
//}

//void GTagML_Document_Info::absorb_data(const QByteArray& qba)
//{
// QDataStream qds(qba);
// qds >> a_string_ >> a_number_;
//}



