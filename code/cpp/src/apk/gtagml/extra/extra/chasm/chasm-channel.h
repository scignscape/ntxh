
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef CHASM_CHANNEL__H
#define CHASM_CHANNEL__H

#include <QString>

#include "accessors.h"
#include "flags.h"

#include "global-types.h"

#include <functional>

#include "kans.h"

#include "chasm-carrier.h"


//KANS_(GTagML)

class Chasm_Channel
{
 QString name_;

 QVector<Chasm_Carrier> carriers_;


public:

 Chasm_Channel(QString name);

 ACCESSORS(QString ,name)

 void add_carrier(const Chasm_Carrier& cc)
 {
  carriers_.push_back(cc);
 }

};

// _KANS(GTagML)

#endif // CHASM_CHANNEL__H

