
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "unified-runtime-object.h"

#include "compilation-unit-object.h"
#include "metatype-object.h"


#include "kans.h"

//USING_KANS(GTagML)


Unified_Runtime_Object::Unified_Runtime_Object(QString file_path)
  :  file_path_(file_path)
{

}

Unified_Runtime_Object* Unified_Runtime_Object::instance()
{
 static Unified_Runtime_Object* result = new Unified_Runtime_Object(__FILE__);
 return result;
}

void Unified_Runtime_Object::register_compilation_unit_object(Compilation_Unit_Object* cuo)
{
 registered_compilation_unit_objects_[cuo->file_path()] = cuo;
}

void Unified_Runtime_Object::register_metatype_object(Metatype_Object* mto)
{
 registered_metatype_objects_[mto->get_full_name()] = mto;
}
