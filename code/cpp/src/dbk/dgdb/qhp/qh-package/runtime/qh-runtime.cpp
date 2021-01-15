
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "qh-type-system.h"

#include "qh-runtime.h"

#include "qh-pack-builder.h"
#include "qh-pack-code.h"
#include "qh-class-object.h"


Qh_Runtime::Qh_Runtime()
  :  type_system_(new Qh_Type_System)
{

}


Qh_Pack_Builder* Qh_Runtime::serialize(Qh_Type* qht, void* obj)
{
 return qht->serialize(obj);
}

Qh_Hypernode* Qh_Runtime::new_hypernode(void* pv, Qh_Type* qht)
{
 if(Qh_Class_Object* qco = qht->qh_class_object())
 {
  Qh_Pack_Builder qpb(qco->pack_code());
  qht->serialize(qpb, pv); //static_pack_encoder()(pv, qpb);
  return qpb.as_hypernode();
 }
 return nullptr;
}



