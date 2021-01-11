
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef PROSODIC_ANNOTATION_ELEMENT__H
#define PROSODIC_ANNOTATION_ELEMENT__H

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

class Prosodic_Annotation_Element
{
 QString layer_range_code_;

 u4 layer_;
 u4 range_start_;
 u4 range_end_;

 QString text_;

 QStringList annotations_;

public:


 Prosodic_Annotation_Element(QString text);

 ACCESSORS(QString ,text)

 ACCESSORS(u4 ,layer)
 ACCESSORS(u4 ,range_start)
 ACCESSORS(u4 ,range_end)

 ACCESSORS__RGET(QStringList ,annotations)

 void parse_layer_range_code(QString lrc);


};


//?
_KANS(GHL)

#endif // PROSODIC_ANNOTATION_ELEMENT__H
