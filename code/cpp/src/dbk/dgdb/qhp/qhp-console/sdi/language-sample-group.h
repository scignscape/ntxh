
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef LANGUAGE_SAMPLE_GROUP__H
#define LANGUAGE_SAMPLE_GROUP__H

#include "kans.h"
#include "accessors.h"

#include <QVector>
#include <QString>

#include "global-types.h"

//?
KANS_(GHL)

class Language_Sample;


class Language_Sample_Group : public QVector<Language_Sample*>
{
 u4 id_;

 u2 chapter_;
 u4 page_;

// u4 in_database_index_;
 u2 index_;

 QString classification_;
 QString text_id_;

 Language_Sample_Group* ref_group_;

 QString main_text_;

public:

 Language_Sample_Group(int id, QString text_id);


 ACCESSORS(u4 ,id)
 ACCESSORS(u2 ,chapter)
 ACCESSORS(u4 ,page)

 ACCESSORS(u2 ,index)
 ACCESSORS(QString ,text_id)
 ACCESSORS(QString ,classification)
 ACCESSORS(Language_Sample_Group* ,ref_group)
 ACCESSORS(QString ,main_text)


 QString get_form();
 QString get_issue();

 bool match_classification(const QSet<QString>& qset);

 void check_set_form(QString f);

 static void read_groups_from_file(QString path,
  QVector<Language_Sample_Group*>& result);

 QStringList all_sample_text();
 QString first_sample_text();

 QString get_main_text();

};


//?
_KANS(GHL)

#endif // LANGUAGE_SAMPLE_GROUP__H
