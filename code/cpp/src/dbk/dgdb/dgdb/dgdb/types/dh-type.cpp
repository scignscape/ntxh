
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dh-type.h"

//USING_KANS(DgDb)

DH_Type::DH_Type()
  :  byte_length_(0),
     byte_length_code_(0), stash_id_(0),
     meta_object_(nullptr), shm_block_size_(0)
  //   stage_encoder_(nullptr)
{

}

DH_Type& DH_Type::default_object_layout()
{
 set_byte_length(QT_POINTER_SIZE);
 set_byte_length_code(QT_POINTER_SIZE);
 return *this;
}


void DH_Type::_note_field_block_offset(QString field_name, u4 start, u4 end)
{
 field_block_offsets_[field_name] = {start, end};
}



QPair<u4, u4> DH_Type::get_field_block_offset(QString field_name)
{
 return field_block_offsets_.value(field_name);
}

