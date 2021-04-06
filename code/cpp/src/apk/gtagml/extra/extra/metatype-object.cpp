
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "metatype-object.h"


#include "kans.h"

//USING_KANS(GTagML)


Metatype_Object::Metatype_Object(QString local_name)
  :  local_name_(local_name)
{

}

QString Metatype_Object::get_full_name()
{
 if(full_name_.isEmpty())
   return local_name_;

 return full_name_;
}
