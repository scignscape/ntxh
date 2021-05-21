
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

 enum class Known_Type_Strings {
   N_A, QSL, QS, B1, U1, U2, U4, N8, S1, S2, S4, R4, R8
 };

 static Known_Type_Strings parse_known_type_string(QString str)
 {
  static QMap<QString, Known_Type_Strings> static_map{
   {"QSL", Known_Type_Strings::QSL},
   {"&", Known_Type_Strings::QS},
   {"B", Known_Type_Strings::B1},
   {"U1", Known_Type_Strings::U1},
   {"U2", Known_Type_Strings::U2},
   {"U4", Known_Type_Strings::U4},
   {"S1", Known_Type_Strings::S1},
   {"S2", Known_Type_Strings::S2},
   {"S4", Known_Type_Strings::S4},
   {"R4", Known_Type_Strings::R4},
   {"R8", Known_Type_Strings::R8},
   {"N8", Known_Type_Strings::N8},
  };

  return static_map.value(str.toUpper(), Known_Type_Strings::N_A);
 }


// Rep_State rep_state();
// Rep_State rep_state_1();
// Rep_State rep_state_2();

 u1 get_pair_code();
 u1 get_pair_code2();
 u1 get_pair_code3();

 void parse(QString type_string, QString rep);

 void parse_other(QString rep);
 void parse_qsl(QString rep);
 void parse_qs(QString rep);
 void parse_b1(QString rep);
 void parse_u1(QString rep);
 void parse_u2(QString rep);
 void parse_u4(QString rep);
 void parse_s1(QString rep);
 void parse_s2(QString rep);
 void parse_s4(QString rep);
 void parse_n8(QString rep);
 void parse_r8(QString rep);
 void parse_r4(QString rep);


public:

 Chasm_Value_Expression(n8 raw_value = 0);
 Chasm_Value_Expression(QString rep);

 void fix_type_object(Chasm_Type_Object* cto);



};

QVector<Chasm_Value_Expression> operator""_cvx(const char* ss, unsigned long len);


// _KANS(GTagML)

#endif // CHASM_VALUE_EXPRESSION__H
