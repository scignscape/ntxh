
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dh-type.h"

//USING_KANS(DgDb)

DH_Type::DH_Type()
  :  byte_length_(0),
     byte_length_code_(0), stash_id_(0),
     meta_object_(nullptr), shm_block_size_(0),
     shm_block_column_(1), shm_message_column_(-2)
  //   stage_encoder_(nullptr)
{

}


DH_Subvalue_Field* DH_Type::get_subvalue_field_by_field_name(QString field_name)
{
 u2 ix = subvalue_fields_index_map_.value(field_name);
 if(ix == 0)
  return nullptr;
 return subvalue_fields_.value(ix);
}

u2 DH_Type::get_internal_field_column_requirements()
{
 return std::count_if(subvalue_fields_.cbegin(), subvalue_fields_.cend(), [](DH_Subvalue_Field* sf)
 {
  return sf->write_mode() == DH_Subvalue_Field::Redirect_In_Record;
 });
}


void DH_Type::note_write_mode(DH_Subvalue_Field* sf, DH_Subvalue_Field::Write_Mode wm)
{
 sf->set_write_mode(wm);
}

void DH_Type::note_record_column_index(DH_Subvalue_Field* sf, u2 rci)
{
 sf->set_record_column_index(rci);
}

DH_Subvalue_Field* DH_Type::note_write_mode(QString field_name, DH_Subvalue_Field::Write_Mode wm)
{
 if(DH_Subvalue_Field* sf = get_subvalue_field_by_field_name(field_name))
 {
  note_write_mode(sf, wm);
  return sf;
 }
 return nullptr;
}

DH_Subvalue_Field::Write_Mode DH_Type::get_write_mode(QString field_name)
{
 if(DH_Subvalue_Field* sf = get_subvalue_field_by_field_name(field_name))
   return sf->write_mode();
 return DH_Subvalue_Field::In_Block;
}


DH_Type& DH_Type::default_object_layout()
{
 set_byte_length(QT_POINTER_SIZE);
 set_byte_length_code(QT_POINTER_SIZE);
 return *this;
}

void DH_Type::note_field_block_offset(DH_Subvalue_Field* sf, u4 start, u4 end)
{
 sf->set_block_offset_start(start);
 sf->set_block_offset_end(end);
}

void DH_Type::note_field_index(DH_Subvalue_Field* sf, u2 index)
{
 sf->set_index(index);
}


DH_Subvalue_Field* DH_Type::note_field_block_offset(QString field_name, u4 start, u4 end)
{
 if(DH_Subvalue_Field* sf = get_subvalue_field_by_field_name(field_name))
 {
  note_field_block_offset(sf, start, end);
  return sf;
 }
 return nullptr;
}


//DH_Subvalue_Field* DH_Type::check_note_field_name(QString field_name)
//{

//}


DH_Subvalue_Field* DH_Type::note_field_index(QString field_name, u2 index)
{
 if(DH_Subvalue_Field* sf = get_subvalue_field_by_field_name(field_name))
 {
  note_field_index(sf, index);
  return sf;
 }

 DH_Subvalue_Field* result = new DH_Subvalue_Field(field_name);
 note_field_index(result, index);
 subvalue_fields_index_map_[field_name] = index;
 subvalue_fields_[index] = result;
 return result;
}


QPair<u4, u4> DH_Type::get_field_block_offset(QString field_name)
{
 if(DH_Subvalue_Field* sf = get_subvalue_field_by_field_name(field_name))
 {
  return {sf->block_offset_start(), sf->block_offset_end()};
 }
 return {0,0};
 //return field_block_offsets_.value(field_name);
}

