
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "qh-type-system.h"

#include "qh-runtime.h"


Qh_Runtime::Qh_Runtime()
  :  type_system_(new Qh_Type_System)
{

}

