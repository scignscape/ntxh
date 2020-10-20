
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dw-type-system.h"

#include "dw-type.h"
#include "dw-type-builder.h"

//#include "graph/dgdb-node.h"

USING_KANS(DGDB)

DW_Type_System::DW_Type_System()
  :  current_type_builder_(nullptr)
{

}

DW_Type& DW_Type_System::register_type(QString tn, QString ctn)
{
 DW_Type* result = get_type_by_name(tn);
 if(!result)
 {
  result = new DW_Type();
  result->set_name(tn);
  result->set_cname(ctn);
  types_by_name_[tn] = result;
 }
 return *result;
}

void DW_Type_System::build_default_types()
{
 current_type_builder_->build(&types_by_name_);
}

DW_Type* DW_Type_System::get_type_by_name(QString tn, QString* res)
{
 // // res being non-null means we may need a resolution ... 
 if(res)
 {
  auto it = type_name_resolutions_.find(tn);
  if(it != type_name_resolutions_.end())
  {
   tn = *it;
   *res = *it;
  }
 }
 return types_by_name_.value(tn);
}


