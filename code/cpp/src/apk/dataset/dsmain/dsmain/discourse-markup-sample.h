
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DISCOURSE_MARKUP_SAMPLE__H
#define DISCOURSE_MARKUP_SAMPLE__H

#include "kans.h"
#include "accessors.h"

#include <QVector>
#include <QString>

#include "global-types.h"


KANS_(DSM)

class Discourse_Markup_Sample
{
 QString ref_;

 QStringList words_;

 QString inline_text_;

 QMap<u2, QStringList> notes_;
 QMap<u2, QString> inserts_;

public:

 Discourse_Markup_Sample();

 void parse_inline(QString text);
 void parse(QString text);

};


_KANS(DSM)

#endif // DISCOURSE_MARKUP_SAMPLE__H
