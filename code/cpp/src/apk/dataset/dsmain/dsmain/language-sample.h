
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef LANGUAGE_SAMPLE__H
#define LANGUAGE_SAMPLE__H

#include "kans.h"
#include "accessors.h"

#include <QVector>
#include <QString>

#include "global-types.h"


class Qh_Pack_Builder;
class Qh_Pack_Reader;
class Qh_Pack_Code;
class Qh_Hypernode;

KANS_(DSM)



class Language_Sample
{
 u4 id_;

 u2 page_;

 QString page_string_;

 QString latex_label_;

 QString external_label_;
 QString external_source_;

 QString text_;
 QString issue_;

 QString alternate_text_;

 QString example_form_;

 QString pre_;
 QString post_;

 //? NGML_Language_Sample* ngml_;

public:

 Language_Sample(u2 id = 0);

// DSM_Language_Sample(DSM_SDI_Sentence* ngml, u4 in_file_id = 0, u4 file_id = 0, u4 page = 0);

 ACCESSORS(u4 ,id)

 ACCESSORS(u2 ,page)

 ACCESSORS(QString ,latex_label)

 ACCESSORS(QString ,external_label)
 ACCESSORS(QString ,external_source)

 ACCESSORS(QString ,page_string)
 ACCESSORS(QString ,text)
 ACCESSORS(QString ,issue)

// ACCESSORS(QString ,alternate_text)

 ACCESSORS(QString ,example_form)

 ACCESSORS(QString ,pre)
 ACCESSORS(QString ,post)

 void check_alternate_text(QString text);

 QString archival_or_text();

 void parse_classification(QString text);

 void supply_pack(Qh_Pack_Builder& qpb);
 void absorb_pack(Qh_Pack_Builder& qpb);

 void supply_opaque(QByteArray& qba);
 void absorb_opaque(const QByteArray& qba);

//? ACCESSORS(NGML_SDI_Sentence* ,ngml)

// QString get_summary();

};


_KANS(DSM)

#endif // LANGUAGE_SAMPLE__H
