
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef LANGUAGE_SAMPLE__H
#define LANGUAGE_SAMPLE__H

#include "kans.h"
#include "accessors.h"

#include "global-types.h"

#include <QVector>
#include <QString>


class Qh_Pack_Builder;
class Qh_Pack_Reader;
class Qh_Pack_Code;
class Qh_Hypernode;

//?
KANS_(GHL)

class Language_Sample_Group;

class Language_Sample
{
 QString text_;

 u4 database_id_;
 u2 index_;

 QString sub_index_;

 u2 chapter_;
 u4 page_;

 QString precomment_;
 QString postcomment_;
 QString alternate_;
 QString speaker_;

 Language_Sample_Group* group_;


 int get_group_id();

public:

 Language_Sample(QString text);


 ACCESSORS(QString ,text)

 ACCESSORS(u4 ,database_id)
 ACCESSORS(u2 ,index)

 ACCESSORS(QString ,sub_index)

 ACCESSORS(u2 ,chapter)
 ACCESSORS(u4 ,page)

 ACCESSORS(QString ,precomment)
 ACCESSORS(QString ,postcomment)
 ACCESSORS(QString ,alternate)
 ACCESSORS(QString ,speaker)

 ACCESSORS(Language_Sample_Group* ,group)

 static void init_pack_code(Qh_Pack_Code& qpc);

 void supply_pack(Qh_Pack_Builder& qpb);

 Language_Sample_Group* get_ref_group();

};


//?
_KANS(GHL)

#endif // LANGUAGE_SAMPLE__H
