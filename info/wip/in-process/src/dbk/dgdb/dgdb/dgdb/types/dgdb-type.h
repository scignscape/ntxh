
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef DGDB_TYPE__H
#define DGDB_TYPE__H

#include <functional>

#include "global-types.h"

#include "wg-stage-value.h"

#include "_whitedb/_whitedb.h"

#include "accessors.h"

#ifndef RTTI_READ
#define RTTI_READ(tn) \
rtti_read<tn>(#tn)
#endif

#ifndef RTTI_READ_2_1
#define RTTI_READ_2_1(ho_tname ,tn) \
rtti_read<ho_tname<tn>>("(" #ho_tname \
  " " #tn ")")
#endif

#include "kans.h"

KANS_(DGDB)

class DgDb_Node;

class DgDb_Type
{
 QString name_;
 QString cname_;
 u4 byte_length_;
 u1 byte_length_code_;
 void* meta_object_;

 std::function<void(void*, QByteArray& qba, 
   WG_Stage_Value::Callback_type cb)> stage_encoder_;

 std::function<void*(DgDb_Node*, 
   std::function<void*(u4)> )> binary_encoder_;

 std::function<void*(DgDb_Node*, 
   std::function<void*(u8)> )> wg_record_encoder_;

public:

 ACCESSORS(MACRO_PASTE(std::function<void*(DgDb_Node*, 
   std::function<void*(u4)> )>) ,binary_encoder)

 ACCESSORS__GET(MACRO_PASTE(std::function<void(void*, QByteArray& qba, 
   WG_Stage_Value::Callback_type cb)>) ,stage_encoder)

 template<typename PROC_Type>
 DgDb_Type& set_stage_encoder(PROC_Type pt)
 {
  stage_encoder_ = (void(*)(void*, QByteArray& qba,
    WG_Stage_Value::Callback_type cb)) pt;
 }  


 ACCESSORS(MACRO_PASTE(std::function<void*(DgDb_Node*, 
   std::function<void*(u8)> )>) ,wg_record_encoder)

 ACCESSORS(u4 ,byte_length)
 ACCESSORS(u1 ,byte_length_code)
 ACCESSORS(QString ,name)
 ACCESSORS(QString ,cname)

 template<typename CType>
 void rtti_read(QString name)
 {
  name_ = name;
  cname_ = QString::fromStdString(typeid(CType).name());
  byte_length_ = sizeof(CType);
  if( (byte_length_ == 1) || (byte_length_ == 2)
    || (byte_length_ == 4) || (byte_length_ == 8) )
    byte_length_code_ = byte_length_; 
 } 


 DgDb_Type();

 DgDb_Type& default_object_layout();
 

};


_KANS(DGDB)

#endif // DGDB_TYPE__H


