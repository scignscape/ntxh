
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef QH_RUNTIME__H
#define QH_RUNTIME__H

#include <QByteArray>

#include <functional>

#include "global-types.h"

#include "accessors.h"

class Qh_Type_System;

class Qh_Runtime
{
 Qh_Type_System* type_system_;

public:

 Qh_Runtime();


 ACCESSORS(Qh_Type_System* ,type_system)

};


#endif // QH_RUNTIME__H


