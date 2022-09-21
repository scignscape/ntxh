
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "gtagml-document-info.h"

#include "gtagml-document-mark.h"
#include "gtagml-document-citation.h"

#include "dgdb-white/dw-stage-value.h"
#include "dgdb-white/stage/dw-stage-queue.h"


#include <QDataStream>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include "textio.h"
USING_KANS(TextIO)


GTagML_Document_Info::GTagML_Document_Info()
 : in_database_id_(0), mark_register_fn_(nullptr),
   citation_page_indicator_("page"),
   FN_VIA_OP(GTagML_Document_Info ,mark_register_fn),
   FN_VIA_OP(GTagML_Document_Info ,citation_register_fn)
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
  if(line.trimmed().isEmpty())
    return 0;

  if(line.startsWith("$$ "))
  {
   if(line.endsWith(';'))
     line.chop(1);
   QStringList qsl = line.mid(3).trimmed().split(" := ", Qt::KeepEmptyParts);
   QString key = qsl.takeFirst();
   for(QString v : qsl)
     info_params_.insert(key, v);
   return 0;
  }

  if(line.startsWith("$& "))
  {
   QStringList qsl = line.mid(3).trimmed().split(' ', Qt::SkipEmptyParts);
   QString citation_text = qsl.takeFirst();
   citation_text.replace("%%", " ");
   QString optarg = qsl.takeFirst();
   if(optarg == "%%")
     optarg.clear();
   optarg.prepend('[');
   optarg.append(']');
   if(qsl.size() >= 3)
   {
    QString layer_code = qsl.takeFirst();
    int index = layer_code.startsWith('(')? 1 : 0;
    QString summary = QString("%1=%2:%4-%3").arg(optarg)
      .arg(layer_code.mid(index, 1)).arg(qsl.takeFirst()).arg(qsl.takeFirst());
    citations_[citation_text].push_back(summary);
   }
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

void GTagML_Document_Info::register_marks()
{
 QVector<GTagML_Document_Mark*> ms;
 if(!main_mark_map_.isEmpty())
   register_marks(ms, 1, main_mark_map_);

 if(!optional_argument_mark_map_.isEmpty())
   register_marks(ms, 2, optional_argument_mark_map_);

 if(!mandatory_argument_mark_map_.isEmpty())
   register_marks(ms, 3, mandatory_argument_mark_map_);

 if(!auxiliary_mark_map_.isEmpty())
   register_marks(ms, 4, auxiliary_mark_map_);

 if(!ms.isEmpty())
 {
  if(mark_register_fn_)
  {
   for(GTagML_Document_Mark* gdm : ms)
   {
    u4 gdm_id = mark_register_fn_(*gdm);
    //?
    delete gdm;
    if(gdm_id != 0)
      break;
   }
  }
 }

 if(citation_register_fn_)
 {
  QMapIterator<QString, QStringList> it(citations_);
  while(it.hasNext())
  {
   it.next();
   for(QString line : it.value())
   {
    GTagML_Document_Citation gdc(in_database_id_, it.key());
    static QRegularExpression rx{"\\[([^\\]]*)\\]=(\\d+):(\\d+)-(\\d+)"};
    QRegularExpressionMatch rxm = rx.match(line);
    if(rxm.hasMatch())
    {
     u4 pg;
     QString pg_non;
     QString extra = rxm.captured(1);
     if(extra.endsWith(')'))
     {
      int li = extra.lastIndexOf('(');
      pg_non = extra.mid(li + 1, extra.length() - li - 2);
      pg = pg_non.toInt();
      if(pg)
        pg_non.clear();
      extra = extra.left(li);
     }
     if(extra.isEmpty())
     {
      extra = citation_page_indicator_;
      if(extra.endsWith('%'))
        extra.chop(1);
      else
        extra.append(' ');
      if(pg)
        extra.append(QString::number(pg));
      else
        extra.append(pg_non);
     }
     gdc.set_extra(extra);
     if(pg)
       gdc.set_cited_page_number(pg);
     else
       gdc.set_cited_page_nonnumeric(pg_non);
     gdc.set_layer(rxm.captured(2).toInt());
     gdc.set_start(rxm.captured(3).toInt());
     gdc.set_end(rxm.captured(4).toInt());
     citation_register_fn_(gdc);
    }
   }
  }
 }


}

void GTagML_Document_Info::register_marks(QVector<GTagML_Document_Mark*>& ms,
  u4 layer, mark_map_type& mark_map)
{
 QMapIterator<u4, QPair<QString, u4>> it(mark_map);
 while(it.hasNext())
 {
  it.next();
  GTagML_Document_Mark* gdm = new GTagML_Document_Mark(in_database_id_, it.value().first);
  gdm->set_start(it.key());
  gdm->set_end(it.value().second);
  gdm->set_layer(layer);
  ms.push_back(gdm);
 }
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

   << info_params_
  ;
}

void GTagML_Document_Info::read_stage_queue(QQueue<void*>& vals)
{
// n8
// created_ = *(QDateTime*) vals.dequeue();
// modified_ = *(QDateTime*) vals.dequeue();

 document_title_ = *(QString*) vals.dequeue();

 n8 cre = *(n8*) vals.dequeue();
 created_ = QDateTime::fromMSecsSinceEpoch(cre);
 n8 mod = *(n8*) vals.dequeue();
 modified_ = QDateTime::fromMSecsSinceEpoch(mod);

 info_params_ = *(QMap<QString, QString>*) vals.dequeue();
// annotation_ = *(QString*) vals.dequeue();
// start_ = *(u4*) vals.dequeue();
// end_ = *(u4*) vals.dequeue();
// layer_ = *(u4*) vals.dequeue();
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

   >> sq.enqueue_new<QMap<QString, QString>>()
   >> sq.skip()

//   >> qm[7].queue<QDate>(sq)
//   >> qm[8].queue<QDate>(sq)
  ;

 sq.reverse();
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



