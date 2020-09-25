
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "gtagml-whitespace-holder.h"

#include "kans.h"

USING_KANS(GTagML)

GTagML_Whitespace_Holder::GTagML_Whitespace_Holder()
  : inherited_(nullptr)
{

}

void GTagML_Whitespace_Holder::get_whitespace_counts_as_inherited(u1* result)
{
 if(inherited_)
   inherited_->ws().get_counts_as_inherited(result);
 else
 {
  result[2] = 0;
  result[3] = 0;
 }
}

void GTagML_Whitespace_Holder::inherit_whitespace(GTagML_Whitespace_Holder* wsh)
{
 inherited_ = wsh;
}


void GTagML_Whitespace_Holder::attach_whitespace(QString whitespace)
{
 ws_ = GTagML_Whitespace(whitespace);
}

