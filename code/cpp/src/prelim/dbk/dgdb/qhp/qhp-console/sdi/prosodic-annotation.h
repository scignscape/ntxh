
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef PROSODIC_ANNOTATION__H
#define PROSODIC_ANNOTATION__H

#include "kans.h"
#include "accessors.h"

#include "global-types.h"

#include "prosodic-annotation-element.h"


#include <QVector>
#include <QString>


class Qh_Pack_Builder;
class Qh_Pack_Reader;
class Qh_Pack_Code;
class Qh_Hypernode;

//?
KANS_(GHL)

class Language_Sample_Group;

class Prosodic_Annotation
{
 QVector<Prosodic_Annotation_Element> elements_;

public:

 Prosodic_Annotation();

 ACCESSORS__RGET(QVector<Prosodic_Annotation_Element> ,elements)

 void parse_elements(QString text);

};


//?
_KANS(GHL)

#endif // PROSODIC_ANNOTATION__H
