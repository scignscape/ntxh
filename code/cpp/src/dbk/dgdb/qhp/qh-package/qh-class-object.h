
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef QH_CLASS_OBJECT__H
#define QH_CLASS_OBJECT__H

#include <QByteArray>

#include <functional>

#include "global-types.h"

#include "accessors.h"

#include "qh-pack-code.h"

class Qh_Class_Object
{
 QString name_;
 Qh_Pack_Code pack_code_;


public:

 Qh_Class_Object(QString name = {});

 ACCESSORS(QString ,name)
 ACCESSORS__RGET(Qh_Pack_Code ,pack_code)


};


#endif // QH_CLASS_OBJECT__H


