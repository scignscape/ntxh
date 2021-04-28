
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

 trisym() : code(0) {}

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
  // // clear lowest 2 bytes
  code ^= 0xFFFF;

  code |= val;
 }

 u4 fcode() { return (code & 0xFFFFFF0000000000) >> 40; }
 s4 scode() { return (code & 0x000000FFFFFF0000) >> 24; }
 u4 ccode() { return (code & 0xFFFF); }
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

// void test_cuo();

// void test_method(QString path, u4 val1, u4 val2);


};

// _KANS(GTagML)

#endif // CHASM_CARRIER__H

