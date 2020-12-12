
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "gtagml-document-info.h"

#include "dgdb-white/dw-stage-value.h"
#include "dgdb-white/stage/dw-stage-queue.h"


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

  if(line.startsWith("$ "))
  {
   if(line.endsWith(';'))
     line.chop(1);
   QStringList qsl = line.mid(2).trimmed().split(" := ", Qt::KeepEmptyParts);
   QString key = qsl.takeFirst();
   for(QString v : qsl)
     info_params_.insert(key, v);
   return 0;
  }

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

 document_title_ = info_params_.value("document-title");
}

void GTagML_Document_Info::encode_stage_values(QByteArray& qba,
  DW_Stage_Value::Callback_type cb)
{
// QByteArray private_qba;
// supply_data(private_qba);

 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds
   << DW_Stage_Value().set_str_data(document_title_).run[4](cb)
   << DW_Stage_Value().set_n8_data(created_.currentMSecsSinceEpoch()).run[5](cb)
   << DW_Stage_Value().set_n8_data(modified_.currentMSecsSinceEpoch()).run[6](cb)   << DW_Stage_Value().set_n8_data(created_.currentMSecsSinceEpoch()).run[5](cb)
   << DW_Stage_Value().set_date_data(created_.date()).run[7](cb)
   << DW_Stage_Value().set_date_data(created_.date()).run[8](cb)
  ;
}

void GTagML_Document_Info::read_stage_queue(QQueue<void*>& vals)
{
// n8
// created_ = *(QDateTime*) vals.dequeue();
// modified_ = *(QDateTime*) vals.dequeue();
}

void GTagML_Document_Info::init_stage_queue(const QByteArray& qba,
  QMap<u4, DW_Stage_Value>& qm, DW_Stage_Queue& sq)
{
 sq.enqueue(new GTagML_Document_Info);

 QDataStream qds(qba);

 qds
   >> qm[4].queue<QString>(sq)
   >> qm[5].queue<n8>(sq)
   >> qm[6].queue<n8>(sq)
   >> qm[7].queue<QDate>(sq)
   >> qm[8].queue<QDate>(sq)
  ;


}



void GTagML_Document_Info::supply_data(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << document_title_ << created_ << modified_;
}

void GTagML_Document_Info::absorb_data(const QByteArray& qba)
{
 QDataStream qds(qba);
 qds >> document_title_ >> created_ >> modified_;
}



