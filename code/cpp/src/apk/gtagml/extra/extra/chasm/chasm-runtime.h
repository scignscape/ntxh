
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

#include "./dev/consoles/fns/run-s0_3_r0.cpp"
#include "./dev/consoles/fns/run-s0_3_r3.cpp"

class Chasm_Call_Package;

//KANS_(GTagML)

class Chasm_Runtime
{
 //QString text_;

 struct _Result
 {
  QString* _QString;

  _Result() : _QString(new QString) {}
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
 void evaluate(Chasm_Call_Package* ccp, u2 fncode, FN_Type fn)
 {
  u1 rr = (fncode % 10000) / 1000;

  fncode %= 1000;

  switch(rr)
  {
  case 0:
   evaluate_r0(ccp, fncode, (minimal_fn_s0_r0_type) fn);
   break;

  case 3:
   evaluate_r3(ccp, fncode, (minimal_fn_s0_r3_type) fn);
   break;

  }
 }

 void evaluate_r0(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_r0_type fn);
 void evaluate_r3(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_r3_type fn);


//.. ACCESSORS(QString ,text)

// void test_cuo();

// void test_method(QString path, u4 val1, u4 val2);


};

// _KANS(GTagML)

#endif // CHASM_RUNTIME__H

