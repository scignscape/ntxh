
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef DH_SUBVALUE_FIELD__H
#define DH_SUBVALUE_FIELD__H

#include <functional>

#include <QDomElement>
#include <QVariant>

#include "global-types.h"

//#include "_whitedb/_whitedb.h"

#include "accessors.h"

#include "kans.h"


 //?KANS_(DgDb)

class DH_Type;

#define _TYPECODE_QUERY_MACROS(x) \
 x(N_A ,void*) \
 x(qstr ,QString) \
 x(qvar ,QVariant) \
 x(WG_INTTYPE ,int) \
 x(WG_DOUBLETYPE ,double) \
 x(WG_STRTYPE ,std::string) \
 x(WG_XMLLITERALTYPE ,QDomEntity) \
 x(WG_URITYPE ,QUrl) \
 x(WG_BLOBTYPE ,QByteArray) \
 x(WG_CHARTYPE ,char) \
 x(WG_FIXPOINTTYPE ,float) \
 x(WG_DATETYPE ,QDate) \
 x(WG_TIMETYPE ,QDateTime) \
 x(Generic ,n8) \




class DH_Subvalue_Field
{
 QString field_name_;

public:

 enum class Query_Typecode {
#define TEMP_MACRO(x ,y) \
  qtc_##x,
  _TYPECODE_QUERY_MACROS(TEMP_MACRO)
#undef TEMP_MACRO
 };

 template<typename T>
 static inline Query_Typecode get_qtc_code()
 {
  return Query_Typecode::qtc_N_A;
 }


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

 QString query_path_;
 QString checked_query_path_;

 Query_Typecode query_typecode_;
 u2 query_column_;

public:


 DH_Subvalue_Field(QString field_name = {});

 ACCESSORS(Write_Mode ,write_mode)

 ACCESSORS(QString ,field_name)

 ACCESSORS(u4 ,block_offset_start)
 ACCESSORS(u4 ,block_offset_end)

 ACCESSORS(u2 ,index)
 ACCESSORS(u2 ,record_column_index)

 ACCESSORS(QString ,query_path)
 ACCESSORS(Query_Typecode ,query_typecode)
 ACCESSORS(u2 ,query_column)
 ACCESSORS(QString ,checked_query_path)

 u2 block_offset_record_column_split();
 void check_write_mode();

 void note_query_info(QString path, Query_Typecode qtc)
 {
  set_query_path(path);
  check_write_mode();
  set_query_typecode(qtc);
 }

};

struct DH
{
 static QPair<u2, u1> block_offset_record_column_unsplit(u2 combined)
 {
  return {combined >> 6, (u1) combined & 0b00111111};
 }


 struct Redirect_In_Record_intermediary
 {
  operator DH_Subvalue_Field::Write_Mode() const
  {
   return DH_Subvalue_Field::Redirect_In_Record;
  }
  QPair<DH_Subvalue_Field::Write_Mode, u2> operator()(u1 column_index) const
  {
   return {DH_Subvalue_Field::Redirect_In_Record, column_index};
  }
  QPair<DH_Subvalue_Field::Write_Mode, u2> operator[](u1 column_index) const
  {
   return {DH_Subvalue_Field::Redirect_In_Record, column_index | 0b0010'0000};
  }

 };

 // column_index

 static constexpr Redirect_In_Record_intermediary Redirect_In_Record = {};

};


#define TEMP_MACRO(x ,y) \
template<> \
inline DH_Subvalue_Field::Query_Typecode DH_Subvalue_Field::get_qtc_code<y>() \
{ \
 return Query_Typecode::qtc_##x; \
} \

_TYPECODE_QUERY_MACROS(TEMP_MACRO)
#undef TEMP_MACRO

 //?_KANS(DgDb)

#endif // DH_SUBVALUE_FIELD__H


