
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef PHR_TYPE_OBJECT__H
#define PHR_TYPE_OBJECT__H

#include <QString>

#include "accessors.h"

#include "kans.h"

KANS_(Phaon)

class PHR_Type;

class PHR_Type_Object
{
 PHR_Type* ty_;

public:

 PHR_Type_Object(PHR_Type* ty);

 ACCESSORS(PHR_Type* ,ty)

 quint8 byte_code();

 bool is_string_like() const;


};

_KANS(Phaon)

#endif // PHR_TYPE_OBJECT__H
