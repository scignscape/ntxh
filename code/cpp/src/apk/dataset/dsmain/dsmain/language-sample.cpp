
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "language-sample.h"

//? #include "ngml-sdi/ngml-sdi-sentence.h"



#include <QRegularExpression>



USING_KANS(DSM)


Language_Sample::Language_Sample(u2 id)
  :  id_(id)
{

}


void Language_Sample::check_alternate_text(QString text)
{
 if(text == "(!)")
 {
  QString txt = text_;
  txt.replace(QRegularExpression(QStringLiteral("\\(.*\\)")),{});
  text = txt.simplified();
 }

 alternate_text_ = text;
}


QString Language_Sample::archival_or_text()
{
 return alternate_text_.isEmpty()? text_ : alternate_text_;
}

void Language_Sample::parse_classification(QString text)
{
 s4 index = text.indexOf(';');
 if(index == -1)
   set_issue(text);
 else
 {
  QString q1 = text.mid(0, index);
  QString q2 = text.mid(index + 1);
  set_issue(q1);
  set_example_form(q2);
 }
}


//SDI_Sentence::SDI_Sentence(//NGML_SDI_Sentence* ngml,
//    u4 in_file_id, u4 file_id, u4 page)
//  :  in_file_id_(in_file_id), file_id_(file_id), page_(page)//, ngml_(ngml)
//{

//}

//QString SDI_Sentence::get_summary()
//{
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
//}

