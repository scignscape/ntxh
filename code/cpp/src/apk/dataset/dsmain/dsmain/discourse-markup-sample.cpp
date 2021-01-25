
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "discourse-markup-sample.h"

#include <QRegularExpression>


USING_KANS(DSM)


Discourse_Markup_Sample::Discourse_Markup_Sample()
{

}

void Discourse_Markup_Sample::parse_inline(QString text)
{
 QString worktext;
 {
  s4 index = text.indexOf(' ');
  ref_ = text.mid(1, index - 1);
  inline_text_ = text.mid(index + 1).simplified();
  worktext = inline_text_;
  worktext.replace('^', "^^");
 }
 s4 index, old_index = 0;

 while((index = worktext.indexOf("^^", old_index)) != -1)
 {
  old_index = index;
  index = worktext.indexOf('-', old_index + 2);
  worktext.replace(old_index, 1, ' ');
  worktext.replace(index, 1, ' ');
  index += 1;
 }

 QStringList maybe_words = worktext.split(' ');
 u2 count = 0;
 for(QString mw: maybe_words)
 {
  if(mw.startsWith('^'))
  {
   mw.replace('p', '%');
   mw.replace('s', '*');
   notes_[count].push_back(mw.mid(1));
   continue;
  }
  if(mw.startsWith('='))
  {
   inserts_[count] = mw.mid(1);
   continue;
  }
  ++count;
  words_.push_back(mw);
 }
}

void Discourse_Markup_Sample::parse(QString text)
{
 if(text.startsWith(':'))
 {
  // inline ...
  parse_inline(text);
  return;
 }

 QStringList lines = text.split('\n');
 u2 count = 0;
 for(QString line: lines)
 {
  if(line.isEmpty())
    continue;
  if(line.startsWith("=="))
  {
   ref_ = line.mid(2).simplified();
   continue;
  }
  if(line.startsWith('='))
  {
   inserts_[count] = line.mid(1).simplified();
   continue;
  }
  ++count;
  QStringList qsl = line.split('=');
  words_.push_back(qsl.takeFirst());
  if(!qsl.isEmpty())
    notes_[count] = qsl;
 }

}
