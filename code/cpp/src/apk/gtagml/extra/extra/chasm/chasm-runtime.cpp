
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "chasm-runtime.h"

#include <QVariant>

#define FULL_INCLUDE
#include "./dev/consoles/fns/run-s0_3_r0.cpp"

//#include "./dev/consoles/fns/run-s0_3_r3.cpp"


//#include "kans.h"
//USING_KANS(GTagML)

#include <QDebug>

//#include "compilation-unit-object.h"
//#include "unified-runtime-object.h"
//#include "metatype-object.h"

#include "chasm-call-package.h"


Chasm_Runtime::Chasm_Runtime()
 :  gen_trisym_line_index_(0), gen_trisym_file_index_(0),
    gen_trisym_col_index_(0), call_package_index_(0),
    current_no_file_session_(0)
{

}


void Chasm_Runtime::evaluate_r0(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_r0_type fn)
{

}


Chasm_Carrier Chasm_Runtime::gen_carrier()
{
 trisym tri;
 tri.set_fcode(current_no_file_session_);
 tri.set_lcode(-(++gen_trisym_line_index_));
 tri.set_ccode(1);
 Chasm_Carrier result;
 result.set_key(tri);
 return result;
}

void Chasm_Runtime::init_no_file_session()
{
 current_no_file_session_ = ++gen_trisym_file_index_;
}


Chasm_Call_Package* Chasm_Runtime::new_call_package()
{
 ++call_package_index_;

 Chasm_Call_Package* result = new Chasm_Call_Package(call_package_index_);
 current_call_packages_.push(result);
 return result;
}


