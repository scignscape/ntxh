
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "gtagml-document-mark.h"

#include <QDataStream>

#include "dgdb-white/dw-stage-value.h"
#include "dgdb-white/stage/dw-stage-queue.h"


GTagML_Document_Mark::GTagML_Document_Mark(u4 document_id, QString text)
 : document_id_(document_id), text_(text), start_(0), end_(0), layer_(0)
{

}

GTagML_Document_Mark::GTagML_Document_Mark()
 : document_id_(0), start_(0), end_(0), layer_(0)
{

}

void GTagML_Document_Mark::encode_stage_values(QByteArray& qba,
   DW_Stage_Value::Callback_type cb)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds
   << DW_Stage_Value().set_u4_data(document_id_).run["Doc.Id"](cb)
   << DW_Stage_Value().set_str_data(text_).run[4](cb)
   << DW_Stage_Value().set_str_data(annotation_).run[5](cb)
   << start_
   << end_
   << layer_
 ;
}

void GTagML_Document_Mark::init_stage_queue(const QByteArray& qba,
  QMap<u4, DW_Stage_Value>& qm, DW_Stage_Queue& sq)
{ 
 sq.enqueue(new GTagML_Document_Mark);

 QDataStream qds(qba);

 qds
   >> sq.skip()
   >> qm[4].queue<QString>(sq)
   >> qm[5].queue<u2>(sq)
   >> qm[6].queue<QDate>(sq)
   >> qm[7].queue<QTime>(sq)
  ;

 sq.reverse();
 //sq << default_stage_queue_reader<GTagML_Document_Mark>(&GTagML_Document_Mark::read_stage_queue);
}


void GTagML_Document_Mark::read_stage_queue(QQueue<void*>& vals)
{
 text_ = *(QString*) vals.dequeue();
 annotation_ = *(QString*) vals.dequeue();
 start_ = *(u4*) vals.dequeue();
 end_ = *(u4*) vals.dequeue();
 layer_ = *(u4*) vals.dequeue();
}


