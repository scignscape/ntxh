
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DGDB_LOCATION_STRUCTURE__H
#define DGDB_LOCATION_STRUCTURE__H

#include <QByteArray>

#include <functional>

#include "global-types.h"

#include "accessors.h"

// //  pattern
//     0b 0000'0000'0000'0000 0000'0000'0000'1000 0000'0000'0000'0000 0000'0000'0000'1000



class DGDB_Location_Structure
{
 n8 raw_code_;

public:

 enum class Field_Id_Options {
  Raw_Array_Position,
  Offset_Array_Position,
  Negative_Raw_Array_Position,
  Negative_Offset_Array_Position,

  Interned_Property_Name,
  Interned_Field_Name,
  Mapped_Field_Name,
  Invalid //Raw_Position,
 };

 enum class Data_Options {
  QVariant, Numeric, QString,
  Raw_Binary, Shm_Pointer,
  Shm_Pointer_With_Path_Code,
  Shm_Pointer_With_Size,
  Shm_Pointer_With_Size_and_Path_Code,
  Signed_Numeric, Typed_Numeric, Typed_QString,
  Typed_Raw_Binary, Typed_Shm_Pointer,
  Typed_Shm_Pointer_With_Path_Code,
  Typed_Shm_Pointer_With_Size,
  Typed_Shm_Pointer_With_Size_and_Path_Code
 };


 DGDB_Location_Structure();

 ACCESSORS(n8 ,raw_code)

 u2 get_raw_primary_field_id();
 u2 get_raw_secondary_field_id();

 QPair<Field_Id_Options, u2> get_primary_field_id();
 QPair<Field_Id_Options, u2> get_secondary_field_id();
 QPair<Data_Options, u4> get_node_id();

 u4 get_raw_node_id();

 void set_node_id(u4 id);

 void set_data_options(Data_Options opts);

 u2 set_primary_field_id(u2 field_number, Field_Id_Options fio);
 u2 set_secondary_field_id(u2 field_number, Field_Id_Options fio);

};


#endif // DGDB_LOCATION_STRUCTURE__H


