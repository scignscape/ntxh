
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "language-sample.h"

#include "language-sample-group.h"

#include <QDebug>

#include "textio.h"

#include "qh-package/qh-pack-code.h"
#include "qh-package/qh-pack-builder.h"


//?
USING_KANS(GHL)


Language_Sample::Language_Sample(QString text)
  :  text_(text), database_id_(0),
     index_(0),
     chapter_(0), page_(0), group_(nullptr)
{

}


void Language_Sample::init_pack_code(Qh_Pack_Code& qpc)
{
 qpc.add_str() // text
   .add_u4() // database_id
   .add_u2() // index
   .add_str() // full index string
   .add_u2() // chapter
   .add_u4() // page
   .add_opaque() // everything else
   ;
}


int Language_Sample::get_group_id()
{
 if(group_)
 {
  return group_->id();
 }
 return 0;
}

Language_Sample_Group* Language_Sample::get_ref_group()
{
 if(group_)
 {
  if(group_->ref_group())
    return group_->ref_group();
  return group_;
 }
 return nullptr;
}

void Language_Sample::supply_pack(Qh_Pack_Builder& qpb)
{

}
