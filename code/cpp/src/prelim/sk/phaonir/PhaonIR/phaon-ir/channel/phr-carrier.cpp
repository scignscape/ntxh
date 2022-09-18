
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "phr-carrier.h"

#include "types/phr-type-object.h"

USING_KANS(Phaon)


PHR_Carrier::PHR_Carrier()
  :  type_object_(nullptr), raw_value_(nullptr)
{

}

QString PHR_Carrier::get_src_value() const
{
 return raw_value_string_;
}

PHR_Carrier* PHR_Carrier::clone()
{
 PHR_Carrier* result = new PHR_Carrier;
 result->phr_type_ = phr_type_;
 result->raw_value_ = raw_value_;
 result->raw_value_string_ = raw_value_string_;
 result->symbol_name_ = symbol_name_;
 result->type_object_ = type_object_;
 return result;
}

QString* PHR_Carrier::raw_value_string_as_pointer()
{
 return &raw_value_string_;
}

QString* PHR_Carrier::symbol_as_pointer()
{
 return &symbol_name_;
}

PHR_Type_Object* PHR_Carrier::type_object() const
{
 if(!type_object_)
   type_object_ = new PHR_Type_Object(phr_type_);
 return type_object_;
}
