
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgdb-type.h"

USING_KANS(DGDB)

DgDb_Type::DgDb_Type()
  :  byte_length_(0), meta_object_(nullptr),
     stage_encoder_(nullptr)
{

}

DgDb_Type& DgDb_Type::default_object_layout()
{
 set_byte_length(QT_POINTER_SIZE);
 set_byte_length_code(QT_POINTER_SIZE);
 return *this;
}


