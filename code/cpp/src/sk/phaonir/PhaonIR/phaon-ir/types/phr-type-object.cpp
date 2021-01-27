
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "phr-type-object.h"

#include "phr-type.h"

USING_KANS(Phaon)

PHR_Type_Object::PHR_Type_Object(PHR_Type* ty)
  :  ty_(ty)
{

}

quint8 PHR_Type_Object::byte_code()
{
 return ty_->byte_code();
}

bool PHR_Type_Object::is_string_like() const
{
 return false;
}


