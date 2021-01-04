
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "qh-type.h"

#include "qh-pack-code.h"
#include "qh-class-object.h"


Qh_Type::Qh_Type()
  :  byte_length_code_(0),
     meta_object_(nullptr),
     qh_class_object_(nullptr)
{

}


Qh_Type& Qh_Type::defpack(void(*fn)(Qh_Pack_Code&))
{
 Qh_Pack_Code qpc;
 fn(qpc);
 qh_class_object_ = new Qh_Class_Object(name_);
 qh_class_object_->pack_code() = qpc;
 return *this;
}
