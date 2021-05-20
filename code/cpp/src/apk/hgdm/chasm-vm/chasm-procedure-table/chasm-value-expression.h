
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef CHASM_VALUE_EXPRESSION__H
#define CHASM_VALUE_EXPRESSION__H

#include <QString>

#include <QStack>
#include <QVariant>
#include <QQueue>
#include <deque>

#include <QDebug>

#include "chasm/chasm-carrier.h"

#include "accessors.h"
#include "flags.h"

#include "global-types.h"
#include "kans.h"

#include "chasm/chasm-runtime.h"

class Chasm_Type_Object;


class Chasm_Value_Expression
{
 n8 raw_value_;

 enum Rep_State
 {
  N_A, Type_Object, Type_Object_QString, Type_Object_Value,
  Triple, Fixnum
 };

// Rep_State rep_state();
// Rep_State rep_state_1();
// Rep_State rep_state_2();

 u1 get_pair_code();
 u1 get_pair_code2();
 u1 get_pair_code3();

public:

 Chasm_Value_Expression(n8 raw_value = 0);

 void fix_type_object(Chasm_Type_Object* cto);


};

// _KANS(GTagML)

#endif // CHASM_VALUE_EXPRESSION__H
