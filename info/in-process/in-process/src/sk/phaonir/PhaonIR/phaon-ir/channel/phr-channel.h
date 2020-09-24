
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef PHR_CHANNEL__H
#define PHR_CHANNEL__H


#include <QStack>

#include "kans.h"

KANS_(Phaon)

class PHR_Carrier;

class PHR_Channel : public QVector<PHR_Carrier*>
{

public:

 PHR_Channel();

 QString get_first_raw_value_string();
 void* get_first_raw_value();
 QString get_first_symbol_name();

 friend bool operator <(const PHR_Channel& lhs, const PHR_Channel& rhs)
 {
  return lhs.value(0) < rhs.value(0);
 }

 PHR_Channel* clone();

};

_KANS(Phaon)

#endif // PHR_CHANNEL__H
