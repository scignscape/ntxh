
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "gtagml-document-citation.h"

#include <QDataStream>

#include "dgdb-white/dw-stage-value.h"
#include "dgdb-white/stage/dw-stage-queue.h"


GTagML_Document_Citation::GTagML_Document_Citation(u4 document_id, QString text)
 : document_id_(document_id), text_(text), cited_page_number_(0), start_(0), end_(0), layer_(0)
{

}

GTagML_Document_Citation::GTagML_Document_Citation()
 : document_id_(0), start_(0), end_(0), layer_(0)
{

}

void GTagML_Document_Citation::encode_stage_values(QByteArray& qba,
   DW_Stage_Value::Callback_type cb)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);

 QString docid = QString::number(document_id_);

 qds
   << DW_Stage_Value().set_u4_data(document_id_).run["Doc.Id"](cb)
   << DW_Stage_Value().set_u4_data(document_id_).run[4](cb)
   << DW_Stage_Value().set_str_data(text_).run[5](cb)
   << DW_Stage_Value().set_str_data(extra_).run[6](cb)
   << DW_Stage_Value().set_str_data(ref_url_).run["CiteUrl"](cb)
   << DW_Stage_Value().set_str_data(ref_url_).run[7](cb)
   << start_
   << end_
   << layer_
   << cited_page_number_
   << cited_page_nonnumeric_
 ;
}

void GTagML_Document_Citation::init_stage_queue(const QByteArray& qba,
  QMap<u4, DW_Stage_Value>& qm, DW_Stage_Queue& sq)
{
 GTagML_Document_Citation* result = new GTagML_Document_Citation;
 sq.enqueue(result);


 QDataStream qds(qba);
 qds
   >> sq.skip()
   >> qm[4].queue<u4>(sq)
   >> qm[5].queue<QString>(sq)
   >> qm[6].queue<QString>(sq)
   >> sq.skip()
   >> qm[7].queue<QString>(sq)
   >> sq.enqueue_new<u4>()
   >> sq.enqueue_new<u4>()
   >> sq.enqueue_new<u4>()
   >> sq.enqueue_new<u4>()
   >> sq.enqueue_new<QString>()
  ;

 sq.reverse();
}


void GTagML_Document_Citation::read_stage_queue(QQueue<void*>& vals)
{
 document_id_ = *(u4*) vals.dequeue();
 text_ = *(QString*) vals.dequeue();
 extra_ = *(QString*) vals.dequeue();
 start_ = *(u4*) vals.dequeue();
 ref_url_ = *(u4*) vals.dequeue();
 end_ = *(u4*) vals.dequeue();
 layer_ = *(u4*) vals.dequeue();
 cited_page_number_ = *(u4*) vals.dequeue();
 cited_page_nonnumeric_ = *(QString*) vals.dequeue();
}


