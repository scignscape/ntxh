
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "language-sample-group.h"

//#include "ngml-sdi/ngml-sdi-paragraph.h"

#include "language-sample.h"

#include "qh-package/qh-pack-builder.h"
#include "qh-package/qh-pack-reader.h"

#include <QDebug>

#include <QDataStream>



USING_KANS(DSM)


//Language_Sample_Group::Language_Sample_Group()
//  :  in_database_id_(id), id_(0),
//     page_(0), order_in_page_(0)
//{

//}

//Language_Sample_Group::Language_Sample_Group() //NGML_SDI_Paragraph* ngml)
// :  in_database_id_(0), in_file_id_(0), file_id_(0),
//    page_(0), order_in_page_(0)//, ngml_(ngml)
//{

//}


Language_Sample_Group::Language_Sample_Group(u2 id)
  :  in_database_id_(0), id_(id),
     page_(0), //order_in_page_(0),
     section_(0),
     first_sample_id_(0), last_sample_id_(0)
{

}


QString Language_Sample_Group::get_example_form()
{
 QString result;
 QSet<QString> seen;
 for(Language_Sample* ls : samples_)
 {
  QString ef = ls->example_form();
  if(!ef.isEmpty())
  {
   if(result.isEmpty())
   {
    result = ef;
    seen.insert(ef);
   }
   else if(!seen.contains(ef))
   {
    seen.insert(ef);
    result += "," + ef;
   }
  }
 }
 if(result.isEmpty())
   return "txt";
 return result;
}

QString Language_Sample_Group::get_issue()
{
 QString result; //= issues_.first();
 u4 count = 0;
 for(QString issue : issues_)
 {
  if(issue.startsWith('#'))
   continue;
  if(count == 0)
    result = issue;
  else if(count == 1)
    result += "(" + issue;
  else result += "," + issue;
  ++count;
 }
 if(count > 1)
   result += ")";
 return result;
}

bool Language_Sample_Group::match_issue(const QSet<QString>& iset, const QSet<QString>& fset)
{
 // // is this a reasonable generic default?  Needed at all?
 if(issues_.isEmpty())
   return fset.contains("txt");

 u1 form_count = 0;

 for(QString form : fset)
 {
  form.prepend('#');
  if(issues_.contains(form))
    ++form_count;
 }

 if(form_count == 0)
   return false;

 for(QString issue : issues_)
 {
  if(iset.contains(issue))
    return true;
 }
 return false;
}

void Language_Sample_Group::add_sample(Language_Sample* sample)
{
 if(samples_.isEmpty())
   first_sample_id_ = sample->id();

 last_sample_id_ = sample->id();
 samples_.push_back(sample);

 QString issue = sample->issue();
 if(issue.isEmpty())
   return;

 if(!issues_.contains(issue))
   issues_.push_back(issue);

 QString ef = sample->example_form();
 if(ef.isEmpty())
   ef = "txt";
 ef.prepend('#');

 if(!issues_.contains(ef))
   issues_.push_back(ef);



}


void Language_Sample_Group::supply_pack(Qh_Pack_Builder& qpb)
{
 // // need node data for the string ...
 qpb.init_node_data();

 QByteArray qba; supply_opaque(qba);

 qpb.add_sv((u4) in_database_id_)
   .add_sv((u2) id_)
   .add_sv((u2) page_)
   .add_sv((u2) section_)
   .add_sv(qba);
}

void Language_Sample_Group::absorb_pack(Qh_Pack_Builder& qpb)
{
 Qh_Pack_Reader qpr(qpb.pack_code(), qpb.data(), qpb.node_data());

 in_database_id_ = qpr.read_value().toUInt();
 id_ = qpr.read_value().toUInt();
 page_ = qpr.read_value().toUInt();
 section_ = qpr.read_value().toUInt();
 QByteArray qba = qpr.read_value().toByteArray();
 absorb_opaque(qba);
}

void Language_Sample_Group::supply_opaque(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << issues_;

 s4 size = samples_.size();
 qds << size;

 if(size > 0)
   qds << samples_.first()->id();

 if(size > 1)
   qds << samples_.last()->id();
}

void Language_Sample_Group::absorb_opaque(const QByteArray& qba)
{
 QDataStream qds(qba);
 qds >> issues_;

 s4 size;
 qds >> size;

 if(size > 0)
 {
  qds >> first_sample_id_;
  if(size == 1)
    last_sample_id_ = first_sample_id_;
  else
    qds >> last_sample_id_;
 }
}

void Language_Sample_Group::get_sample_texts(QStringList& qsl)
{
 for(Language_Sample* sample : samples_)
   qsl << sample->archival_or_text();
}


QString Language_Sample_Group::get_main_text()
{
 if(samples_.isEmpty())
   return {};
 Language_Sample* sample = samples_.first();
 return sample->archival_or_text();
}


QString Language_Sample_Group::get_summary()
{
// if(ngml_)
//   return QString("%1 = %2:%3,%4-%5,%6; %7-%8").arg(file_id_)
//     .arg(ngml_->id())
//     .arg(ngml_->start_x())
//     .arg(ngml_->end_x())
//     .arg(ngml_->start_y())
//     .arg(ngml_->end_y())
//     .arg(ngml_->start_index())
//     .arg(ngml_->end_index())
//   ;
// return {};
}
