
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef CHASM_CARRIER__H
#define CHASM_CARRIER__H

#include <QString>

#include "accessors.h"
#include "flags.h"

#include "global-types.h"

#include <functional>

#include "kans.h"


//KANS_(GTagML)

struct trisym
{
 n8 code;

 // //  15 type flag = unknown
 trisym() : code(15) {}

 void set_fcode(u4 val)
 {
  // // only lowest three bytes
  val &= 0xFFFFFF;

  // // clear highest three bytes
  code &= 0x000000FFFFFFFFFF;

  code |= (((n8) val) << 40);
 }

 void set_lcode(s4 val)
 {
  // // only lowest three bytes
  val &= 0xFFFFFF;

  // // clear bytes 4-6
  code &= 0xFFFFFF000000FFFF;

  code |= (((n8) val) << 24);
 }

 void set_ccode(u2 val)
 {
  // // reserve lowest 4 val bits
  val <<= 4;

  // // clear lowest 2 bytes except lowest 4 bits
  code &= ~((n8)0xFFF0);

  code |= val;
 }

 void set_type_flag(u1 tf)
 {
  // // only lowest 4 bits
  tf &= 0x0F;

  // // clear lowest 4 bits
  code &= ~((n8)0x0F);

  code |= tf;
 }


 u4 fcode() { return (code & 0xFFFFFF0000000000) >> 40; }
 s4 scode() { return (code & 0x000000FFFFFF0000) >> 24; }
 u4 ccode() { return (code & 0xFFF0) >> 4; }

 u1 type_flag() { return (code & 0x0F); }

};


class Chasm_Carrier
{
 //QString text_;

 trisym key_;
 n8 value_;

public:

 Chasm_Carrier();

 ACCESSORS(trisym ,key)
 ACCESSORS(n8 ,value)

 void set_type_flag(u1 tf)
 {
  key_.set_type_flag(tf);
 }

 Chasm_Carrier& take_value(void* pv);

 n8 pasn8()
 {
  u1 tf = key_.type_flag();
  if(tf == 3)
  {
   QString* qs = (QString*) value_;
   return value_;
  }
  return (n8) &value_;
 }

 template<typename VALUE_Type>
 VALUE_Type& value_as()
 {
  return *(VALUE_Type*)value_;
 }
 // void test_cuo();

// void test_method(QString path, u4 val1, u4 val2);


};

// _KANS(GTagML)

#endif // CHASM_CARRIER__H

