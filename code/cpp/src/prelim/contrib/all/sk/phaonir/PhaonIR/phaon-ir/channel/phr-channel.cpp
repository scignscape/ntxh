
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "phr-channel.h"
#include "phr-carrier.h"

USING_KANS(Phaon)

PHR_Channel::PHR_Channel()
{

}

PHR_Channel* PHR_Channel::clone()
{
 PHR_Channel* result = new PHR_Channel;
 for(PHR_Carrier* phc : *this)
 {
  result->push_back(phc->clone());
 }
 return result;
}

void* PHR_Channel::get_first_raw_value()
{
 if(isEmpty())
   return nullptr;
 return first()->raw_value();
}

QString PHR_Channel::get_first_symbol_name()
{
 if(isEmpty())
   return QString();
 return first()->symbol_name();
}

QString PHR_Channel::get_first_raw_value_string()
{
 if(isEmpty())
   return QString();
 return first()->raw_value_string();
}
