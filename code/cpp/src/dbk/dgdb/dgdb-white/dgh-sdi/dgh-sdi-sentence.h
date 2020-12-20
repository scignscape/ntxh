
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DGH_SDI_SENTENCE__H
#define DGH_SDI_SENTENCE__H

#include "kans.h"
#include "accessors.h"

#include <QVector>
#include <QString>

#include "global-types.h"

KANS_(DGH)

class DGH_SDI_Paragraph;


class DGH_SDI_Sentence
{
 u4 id_;

 u4 page_;

 u4 start_;
 u4 end_;


public:

 DGH_SDI_Sentence(u4 id, u4 page, u4 start, u4 end);


 ACCESSORS(u4 ,id)
 ACCESSORS(u4 ,page)
 ACCESSORS(u4 ,start)
 ACCESSORS(u4 ,end)

};


_KANS(GHL)

#endif // LANGUAGE_SAMPLE_GROUP__H
