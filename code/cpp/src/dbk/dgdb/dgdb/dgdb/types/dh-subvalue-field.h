
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef DH_SUBVALUE_FIELD__H
#define DH_SUBVALUE_FIELD__H

#include <functional>

#include "global-types.h"

//#include "_whitedb/_whitedb.h"

#include "accessors.h"

#include "kans.h"

 //?KANS_(DgDb)

class DH_Type;

class DH_Subvalue_Field
{
 QString field_name_;

public:
 enum Write_Mode{
  In_Block,
  Redirect_In_Block,
  Redirect_In_Record,
  Redirect_External,
 };

 enum Block_Segment_Info_Flags {
   Extension_Flags = 1, Has_Offset_Split = 2, Has_Type_Code = 4,
   Has_Segment_Length = 8, Has_Record_Pointer = 16, Has_Field_Index = 32,
   Has_White_Path = 64, Has_Value = 128
 };

 enum Block_Segment_Extension_Info_Flags {
   Has_Active_Segment_End = 1, Has_Active_Segment_Start = 2,
   Has_Edit_Timestamp = 4, Has_Edit_Info = 8,
   Has_User_Data = 16
 };


private:

 Write_Mode write_mode_;
 u2 index_;
 u2 record_column_index_;

 u4 block_offset_start_;
 u4 block_offset_end_;

public:


 DH_Subvalue_Field(QString field_name = {});

 ACCESSORS(Write_Mode ,write_mode)

 ACCESSORS(QString ,field_name)

 ACCESSORS(u4 ,block_offset_start)
 ACCESSORS(u4 ,block_offset_end)

 ACCESSORS(u2 ,index)
 ACCESSORS(u2 ,record_column_index)

};

struct DH
{
 struct Redirect_In_Record_intermediary
 {
  operator DH_Subvalue_Field::Write_Mode() const
  {
   return DH_Subvalue_Field::Redirect_In_Record;
  }
  QPair<DH_Subvalue_Field::Write_Mode, u2> operator()(u2 column_index) const
  {
   return {DH_Subvalue_Field::Redirect_In_Record, column_index};
  }
 };

 // column_index

 static constexpr Redirect_In_Record_intermediary Redirect_In_Record = {};

};

 //?_KANS(DgDb)

#endif // DH_SUBVALUE_FIELD__H


