
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "prosodic-annotation-element.h"


//?
USING_KANS(GHL)


Prosodic_Annotation_Element::Prosodic_Annotation_Element(QString text)
  :  layer_(0),
     range_start_(0),
     range_end_(0),
     text_(text)
{

}


void Prosodic_Annotation_Element::parse_layer_range_code(QString lrc)
{
 s4 i1 = lrc.indexOf(':');

 if(i1 == -1)
   return;

 s4 i2 = lrc.indexOf('-');
 if(i2 == -1)
   return;

 layer_ = lrc.mid(0, i1).toInt();
 range_start_ = lrc.mid(i1 + 1, i2).toInt();
 range_end_ = lrc.mid(i2 + 1).toInt();


}
