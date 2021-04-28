
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef CHASM_RUNTIME__H
#define CHASM_RUNTIME__H

#include <QString>

#include <QStack>

#include "accessors.h"
#include "flags.h"

#include "global-types.h"

#include <functional>

#include "kans.h"

#include "chasm-carrier.h"

#include "./dev/consoles/fns/run-s0_3_r0.cpp"

class Chasm_Call_Package;

//KANS_(GTagML)

class Chasm_Runtime
{
 //QString text_;

 u4 gen_trisym_line_index_;
 u4 gen_trisym_file_index_;
 u4 gen_trisym_col_index_;

 u4 call_package_index_;

 QStack<Chasm_Call_Package*> current_call_packages_;

 u4 current_no_file_session_;

public:

 Chasm_Runtime();

 Chasm_Call_Package* new_call_package();

 Chasm_Carrier gen_carrier();

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

  }
 }

 void evaluate_r0(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_r0_type fn);


//.. ACCESSORS(QString ,text)

// void test_cuo();

// void test_method(QString path, u4 val1, u4 val2);


};

// _KANS(GTagML)

#endif // CHASM_RUNTIME__H

