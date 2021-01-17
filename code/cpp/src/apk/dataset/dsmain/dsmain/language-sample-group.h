
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

#include "ntxh-parser/ntxh-document.h"



KANS_CLASS_DECLARE(DGH ,DGH_SDI_Paragraph)
USING_KANS(HGDMCore)


KANS_(DSM)

class Language_Sample;

class Language_Sample_Group
{
 u4 in_database_id_;

 u2 id_;
 u2 page_;
 u2 order_in_page_;

 u2 section_;

// u4 start_;
// u4 end_;
// DGH_SDI_Sentence* first_sentence_;
// DGH_SDI_Sentence* last_sentence_;

 QVector<Language_Sample*> samples_;

 QStringList issues_;


public:

 Language_Sample_Group(u2 id = 0);

// Language_Sample_Group(NGML_SDI_Paragraph* ngml);

// Language_Sample_Group(u4 file_id, u4 in_file_id);


 ACCESSORS(u4 ,in_database_id)
 ACCESSORS(u2 ,id)
 ACCESSORS(u2 ,page)
 ACCESSORS(u2 ,order_in_page)

 ACCESSORS(u2 ,section)

 QString get_issue();

 ACCESSORS(QVector<Language_Sample*> ,samples)

// ACCESSORS(u4 ,start)
// ACCESSORS(u4 ,end)
// ACCESSORS(DGH_SDI_Sentence* ,first_sentence)
// ACCESSORS(DGH_SDI_Sentence* ,last_sentence)

 QString get_summary();

 QString get_main_text();

 QString get_example_form();

 void add_sample(Language_Sample* sample);

};


_KANS(DSM)

#endif // LANGUAGE_SAMPLE_GROUP__H
