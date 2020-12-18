
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef SDI_PARAGRAPH__H
#define SDI_PARAGRAPH__H

#include "kans.h"
#include "accessors.h"

#include <QVector>
#include <QString>

#include "global-types.h"

KANS_(GHL)


class SDI_Sentence;


class SDI_Paragraph
{
 u4 id_;
 u4 start_;
 u4 end_;

 SDI_Sentence* first_sentence_;
 SDI_Sentence* last_sentence_;


public:

 SDI_Paragraph(u4 id, u4 start, u4 end);


 ACCESSORS(u4 ,id)
 ACCESSORS(u4 ,start)
 ACCESSORS(u4 ,end)

 ACCESSORS(SDI_Sentence* ,first_sentence)
 ACCESSORS(SDI_Sentence* ,last_sentence)


};


_KANS(GHL)

#endif // LANGUAGE_SAMPLE_GROUP__H
