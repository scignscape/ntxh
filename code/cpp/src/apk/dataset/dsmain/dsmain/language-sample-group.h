
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


class Qh_Pack_Builder;

KANS_(DSM)

class Language_Sample;

class Language_Sample_Group
{
 u4 in_database_id_;

 u2 id_;
 u2 page_;
//? u2 order_in_page_;

 u2 section_;


 QVector<Language_Sample*> samples_;

 // //  also includes forms, prepended with '#'
 QStringList issues_;

 u2 first_sample_id_;
 u2 last_sample_id_;

public:

 Language_Sample_Group(u2 id = 0);


 ACCESSORS(u4 ,in_database_id)
 ACCESSORS(u2 ,id)
 ACCESSORS(u2 ,page)

 //? ACCESSORS(u2 ,order_in_page)

 ACCESSORS(u2 ,section)

 QString get_issue();
 bool match_issue(const QSet<QString>& iset, const QSet<QString>& fset);

 ACCESSORS(QVector<Language_Sample*> ,samples)

 QString get_summary();

 QString get_main_text();

 QString get_example_form();

 void add_sample(Language_Sample* sample);

 void supply_pack(Qh_Pack_Builder& qpb);
 void absorb_pack(Qh_Pack_Builder& qpb);

 void supply_opaque(QByteArray& qba);
 void absorb_opaque(const QByteArray& qba);

};


_KANS(DSM)

#endif // LANGUAGE_SAMPLE_GROUP__H
