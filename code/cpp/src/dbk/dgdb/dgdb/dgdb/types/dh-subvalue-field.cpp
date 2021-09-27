
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dh-subvalue-field.h"


DH_Subvalue_Field::DH_Subvalue_Field(QString field_name)
  :  field_name_(field_name), write_mode_(In_Block), block_offset_start_(0),
     block_offset_end_(0), record_column_index_(0), index_(0)
{

}

void DH_Subvalue_Field::check_write_mode()
{
 if(write_mode_ != Write_Mode::In_Block)
  return;

 if(query_path_.isEmpty())
  return;

 write_mode_ = Write_Mode::Redirect_External;
}


u2 DH_Subvalue_Field::block_offset_record_column_split()
{
 u2 result = (u2) block_offset_start_ << 6;
 result |= ( (u1)record_column_index_ & 0b00111111 );
 return result;
}

