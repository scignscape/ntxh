
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef COMPILATION_UNIT_OBJECT__H
#define COMPILATION_UNIT_OBJECT__H

#include <QString>

#include "accessors.h"
#include "flags.h"

#include "global-types.h"

#include "kans.h"


//KANS_(GTagML)

class Unified_Runtime_Object;

class Compilation_Unit_Object
{
 QString file_path_;

 static Unified_Runtime_Object* unified_runtime_object_;

public:


 Compilation_Unit_Object(QString file_path);

 ACCESSORS(QString ,file_path)




};

// _KANS(GTagML)

#endif
