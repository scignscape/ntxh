
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef CHASM_RUNTIME__H
#define CHASM_RUNTIME__H

#include <QString>

#include <QStack>
#include <QVariant>

#include "accessors.h"
#include "flags.h"

#include "global-types.h"

#include <functional>

#include <QString>
#include <QVariant>
#include <QByteArray>

#include "kans.h"

#include "chasm-carrier.h"

#include "./dev/consoles/fns/s0/a3/run-s0_3_re0.cpp"
#include "./dev/consoles/fns/s0/a3/run-s0_3_re1.cpp"
#include "./dev/consoles/fns/s0/a3/run-s0_3_re2.cpp"
#include "./dev/consoles/fns/s0/a3/run-s0_3_re3.cpp"
#include "./dev/consoles/fns/s0/a3/run-s0_3_re4.cpp"
#include "./dev/consoles/fns/s0/a3/run-s0_3_re5.cpp"
#include "./dev/consoles/fns/s0/a3/run-s0_3_re6.cpp"
#include "./dev/consoles/fns/s0/a3/run-s0_3_re7.cpp"
#include "./dev/consoles/fns/s0/a3/run-s0_3_re8.cpp"
#include "./dev/consoles/fns/s0/a3/run-s0_3_re9.cpp"


class Chasm_Call_Package;

//KANS_(GTagML)

class Chasm_Runtime
{
 //QString text_;

 struct _Result
 {
  n8* _ref;
  u1* _u1;
  u2* _u2;
  QString* _QString;
  u4* _u4;
  QByteArray* _QByteArray;
  r8* _r8;
  QVariant* _QVariant;
  n8* _n8;
  void** _ptr;

  _Result() : _ref(new n8(0)), _u1(new u1(0)), _u2(new u2(0)),
    _QString(new QString), _u4(new u4(0)), _QByteArray(new QByteArray),
    _r8(new r8(0)), _QVariant(new QVariant),
    _n8(new n8(0)),  _ptr(new void*(nullptr))
    {}
 };

 u4 gen_trisym_line_index_;
 u4 gen_trisym_file_index_;
 u4 gen_trisym_col_index_;

 u4 call_package_index_;

 QStack<Chasm_Call_Package*> current_call_packages_;

 u4 current_no_file_session_;

public:

 Chasm_Runtime();

 _Result Result;

 Chasm_Call_Package* new_call_package();

 Chasm_Carrier gen_carrier(QString type_name = {});
 Chasm_Carrier gen_carrier(u1 type_flag);

 template<typename CARRIER_Type>
 inline Chasm_Carrier gen_carrier();

 template<typename CARRIER_Type>
 inline Chasm_Carrier gen_carrier(void* value);

 void init_no_file_session();

 template<typename FN_Type>
 void evaluate(Chasm_Call_Package* ccp, u4 fncode, FN_Type fn, Chasm_Carrier* rcar = nullptr)
 {
  u1 sl = fncode / 10000;

  u1 rr = (fncode % 10000) / 1000;

  fncode %= 1000;

  switch(rr)
  {
  case 0:
   evaluate_re0(ccp, fncode, (minimal_fn_s0_re0_type) fn);
   break;

  case 1:
   evaluate_re1(ccp, fncode, (minimal_fn_s0_re1_type) fn, rcar);
   break;

  case 2:
   evaluate_re2(ccp, fncode, (minimal_fn_s0_re2_type) fn, rcar);
   break;

  case 3:
   evaluate_re3(ccp, fncode, (minimal_fn_s0_re3_type) fn, rcar);
   break;

  case 4:
   evaluate_re4(ccp, fncode, (minimal_fn_s0_re4_type) fn, rcar);
   break;

  case 5:
   evaluate_re5(ccp, fncode, (minimal_fn_s0_re5_type) fn, rcar);
   break;

  case 6:
   evaluate_re6(ccp, fncode, (minimal_fn_s0_re6_type) fn, rcar);
   break;

  case 7:
   evaluate_re7(ccp, fncode, (minimal_fn_s0_re7_type) fn, rcar);
   break;

  case 8:
   evaluate_re8(ccp, fncode, (minimal_fn_s0_re8_type) fn, rcar);
   break;

  case 9:
   evaluate_re9(ccp, fncode, (minimal_fn_s0_re9_type) fn, rcar);
   break;
  }
 }

 void evaluate_re0(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_re0_type fn);
 void evaluate_re1(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_re1_type fn, Chasm_Carrier* rcar = nullptr);
 void evaluate_re2(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_re2_type fn, Chasm_Carrier* rcar = nullptr);
 void evaluate_re3(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_re3_type fn, Chasm_Carrier* rcar = nullptr);
 void evaluate_re4(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_re4_type fn, Chasm_Carrier* rcar = nullptr);
 void evaluate_re5(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_re5_type fn, Chasm_Carrier* rcar = nullptr);
 void evaluate_re6(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_re6_type fn, Chasm_Carrier* rcar = nullptr);
 void evaluate_re7(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_re7_type fn, Chasm_Carrier* rcar = nullptr);
 void evaluate_re8(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_re8_type fn, Chasm_Carrier* rcar = nullptr);
 void evaluate_re9(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_re9_type fn, Chasm_Carrier* rcar = nullptr);


//.. ACCESSORS(QString ,text)

// void test_cuo();

// void test_method(QString path, u4 val1, u4 val2);


};

// _KANS(GTagML)

#endif // CHASM_RUNTIME__H

