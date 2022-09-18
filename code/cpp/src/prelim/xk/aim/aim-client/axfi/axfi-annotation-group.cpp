
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "axfi-annotation-group.h"


AXFI_Annotation_Group::AXFI_Annotation_Group(AXFI_Annotation_Group* parent_group)
  :  parent_group_(parent_group)
{

}

void AXFI_Annotation_Group::add_annotation(AXFI_Annotation* axa)
{
 annotations_.push_back(axa);
}
