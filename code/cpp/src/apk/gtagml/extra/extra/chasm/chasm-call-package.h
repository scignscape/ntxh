
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef CHASM_CALL_PACKAGE__H
#define CHASM_CALL_PACKAGE__H

#include <QString>

#include "accessors.h"
#include "flags.h"

#include "global-types.h"

#include <functional>

#include "kans.h"

#include "chasm-carrier.h"

//KANS_(GTagML)

class Chasm_Channel;

class Chasm_Call_Package
{
 QMap<QString, Chasm_Channel*> channels_;

 Chasm_Channel* current_build_channel_;

 u4 id_;

public:

 Chasm_Call_Package(u4 id);

 void add_new_channel(QString name);

 void add_carrier(const Chasm_Carrier& cc);

//.. ACCESSORS(QString ,text)

// void test_cuo();

// void test_method(QString path, u4 val1, u4 val2);


};

// _KANS(GTagML)

#endif // CHASM_CALL_PACKAGE__H

