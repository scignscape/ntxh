
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef METATYPE_OBJECT__H
#define METATYPE_OBJECT__H

#include <QString>
#include <QMap>

#include "accessors.h"
#include "flags.h"

#include "global-types.h"

#include "kans.h"


//KANS_(GTagML)


class Metatype_Object
{
 QString local_name_;
 QString full_name_;

public:

 Metatype_Object(QString local_name);

 ACCESSORS(QString ,local_name)
 ACCESSORS(QString ,full_name)

 QString get_full_name();



};

// _KANS(GTagML)

#endif // METATYPE_OBJECT__H
