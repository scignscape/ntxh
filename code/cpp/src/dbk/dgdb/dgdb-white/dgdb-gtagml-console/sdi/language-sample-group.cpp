
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "language-sample-group.h"

#include "language-sample.h"

#include <QDebug>

#include "textio.h"


USING_KANS(GHL)
//USING_KANS(TextIO)

Language_Sample_Group::Language_Sample_Group(int id, QString text_id)
  :  id_(id), index_(0), text_id_(text_id),
     chapter_(0), page_(0),
     ref_group_(nullptr)
{

}

QString Language_Sample_Group::get_main_text()
{
 if(main_text_.isEmpty())
   return first_sample_text();
 return main_text_;
}

QString Language_Sample_Group::first_sample_text()
{
 if(isEmpty())
   return QString();
 return first()->text();
}

QStringList Language_Sample_Group::all_sample_text()
{
 QStringList result;
 for(Language_Sample* samp : *this)
 {
  result << samp->text();
 }
 return result;
}


QString Language_Sample_Group::get_form()
{
 if(classification_.isEmpty())
   return "Text";
 int index = classification_.indexOf(':');
 if(index == -1)
 {
  return classification_;
 }
 return classification_.left(index);
}

bool Language_Sample_Group::match_classification(const QSet<QString>& qset)
{
 if(classification_.isEmpty())
   return qset.contains("Text");
 int index = classification_.indexOf(':');
 if(index == -1)
 {
  return qset.contains(classification_);
 }
 return qset.contains(classification_.left(index))
   && qset.contains(classification_.mid(index + 1));
}

QString Language_Sample_Group::get_issue()
{
 if(classification_.isEmpty())
   return "(N_A)";
 int index = classification_.indexOf(':');
 if(index == -1)
 {
  return "(N_A)";
 }
 return classification_.mid(index + 1);
}

void Language_Sample_Group::check_set_form(QString f)
{
 if(classification_.isEmpty())
 {
  classification_ = f;
 }
 else if(classification_.startsWith("?:"))
 {
  classification_.replace(0, 1, f);
 }
}

