
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "chasm-value-expression.h"

#include "chasm/chasm-runtime.h"
#include "chasm/chasm-call-package.h"


#include <QString>
#include <QVariant>
#include <QByteArray>

#include <QUrl>

#include <QPoint>

#include <QRegularExpression>

#include <tuple>

Chasm_Value_Expression::Chasm_Value_Expression(n8 raw_value)
  :  raw_value_(raw_value)
{
}

//Chasm_Value_Expression::Rep_State Chasm_Value_Expression::rep_state_1()
//{
// QPair<n8, n8>* pr = (QPair<n8, n8>*) (raw_value_ - 1);
// switch (code)
// {
// case 0: return Type_Object;
// case 1: return Type_Object;

// case 3: return Fixnum;
// }
//}


//Chasm_Value_Expression::Rep_State Chasm_Value_Expression::rep_state()
//{
// if(raw_value_ == 0)
//   return N_A;
// u1 code = raw_value_ & 3;
// switch (code)
// {
// case 0: return Type_Object;
// case 1: return Type_Object;

// case 3: return Fixnum;
// }
//}

u1 Chasm_Value_Expression::get_pair_code2()
{
 std::pair<n8, n8>* pr = (std::pair<n8, n8>*) (raw_value_ - 1);
 u1 c1 = pr->first & 3;
 u1 c2 = pr->second & 3;
 return (c1 << 4) | (c2 << 2) | 2;
}

u1 Chasm_Value_Expression::get_pair_code3()
{
 std::tuple<n8, n8, n8>* triple = (std::tuple<n8, n8, n8>*) (raw_value_ - 1);
 u1 c1 = std::get<0>( *triple ) & 3;
 u1 c2 = std::get<1>( *triple ) & 3;
 u1 c3 = std::get<2>( *triple ) & 3;
 return (c1 << 6) | (c2 << 4) | (c3 << 2) | 3;
}

u1 Chasm_Value_Expression::get_pair_code()
{
 if(raw_value_ == 0)
   return 0;
 u1 code = raw_value_ & 3;
 switch (code)
 {
  case 0: return 1;
  case 1: return get_pair_code2();
  case 2: return get_pair_code3();
  case 3: return 129;
 }
}


