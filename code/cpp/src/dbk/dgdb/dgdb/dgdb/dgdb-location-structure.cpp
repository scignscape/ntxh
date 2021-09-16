
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgdb-location-structure.h"

DGDB_Location_Structure::DGDB_Location_Structure()
  :  raw_code_(0)
{

}

u2 DGDB_Location_Structure::get_raw_primary_field_id()
{
 return (u2) (raw_code_ & 0xFFFF);
}

u2 DGDB_Location_Structure::get_raw_secondary_field_id()
{
 u2 result = raw_code_ >> 48;
 return result & 0b0111'1111'1111'1111;
}

QPair<DGDB_Location_Structure::Field_Id_Options, u2>
  DGDB_Location_Structure::get_primary_field_id()
{
 u2 result = get_raw_primary_field_id();
 static u2 mask13 = 0b0001'1111'1111'1111;
 return { (Field_Id_Options) (result >> 13), result & mask13};
}


QPair<DGDB_Location_Structure::Field_Id_Options, u2>
  DGDB_Location_Structure::get_secondary_field_id()
{
 u2 result = get_raw_secondary_field_id();
 static u2 mask13 = 0b0001'1111'1111'1111;
 return { (Field_Id_Options) ( (result >> 13) & 3), result & mask13};
}

u4 DGDB_Location_Structure::get_raw_node_id()
{
 n8 result = raw_code_ & 0x0000'FFFF'FFFF'0000;
 return (u4) (result >> 16);
}


void DGDB_Location_Structure::set_data_options(Data_Options opts)
{
 u1 data_options = (u1) opts & 7;

 // //  clear the data_options and typed flag bits ///
 raw_code_ &= 0x7FFF'1FFF'FFFF'FFFF;

 raw_code_ |= (n8)data_options << 45;

 if( (u1)opts & 8 )
   raw_code_ |= ( (n8)1 << 63);
}


QPair<DGDB_Location_Structure::Data_Options, u4> DGDB_Location_Structure::get_node_id()
{
 u4 result = get_raw_node_id();
 u1 data_options = result >> 29;
 result &= 0b0001'1111'1111'1111'1111'1111'1111'1111;
 if(raw_code_ >> 63)
 {
  // //  typed_flag bit set
  return { (DGDB_Location_Structure::Data_Options) (data_options | 8), result };
 }
 // //  typed_flag bit not set
 return { (DGDB_Location_Structure::Data_Options) data_options, result };
}

void DGDB_Location_Structure::set_node_id(u4 id)
{
 // //  id should be < 0x1FFF'FFFF ...

 // //  middle four bytes should be 0b0001'1111 ... all ones ...
 raw_code_ &= 0xFFFF'E000'0000'FFFF;
 raw_code_ |= ((n8)id << 16);
}


u2 DGDB_Location_Structure::set_primary_field_id(u2 field_number, Field_Id_Options fio)
{
 static u2 mask13 = 0b0001'1111'1111'1111;
 u2 result = field_number & mask13;

 // // if(result != field_number)
  //     opportunity to check the field_number is in proper bounds ...

 result |= ((u2) fio) << 13;
 raw_code_ &= 0xFFFF'FFFF'FFFF'0000;
 raw_code_ |= result;//(result << 16);
 return result;
}

u2 DGDB_Location_Structure::set_secondary_field_id(u2 field_number, Field_Id_Options fio)
{
 static u2 mask13 = 0b0001'1111'1111'1111;
 u2 result = field_number & mask13;

 // // if(result != field_number)
  //     opportunity to check the field_number is in proper bounds ...

 // //  fio should be only one of the first four options ...
 result |= (((u2) fio) & 3) << 13;
 raw_code_ &= 0x8000'FFFF'FFFF'FFFF;
 raw_code_ |= ( (n8)result << 48);
 return result;
}


