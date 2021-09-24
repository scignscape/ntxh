
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dh-subvalue-field.h"


DH_Subvalue_Field::DH_Subvalue_Field(QString field_name)
  :  field_name_(field_name), write_mode_(In_Block), block_offset_start_(0), block_offset_end_(0)
{

}

