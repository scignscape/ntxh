
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "chasm-runtime.h"

#include <QString>
#include <QVariant>
#include <QByteArray>

#define FULL_INCLUDE
#include "./dev/consoles/fns/run-s0_3_r0.cpp"
#include "./dev/consoles/fns/run-s0_3_r1.cpp"
#include "./dev/consoles/fns/run-s0_3_r2.cpp"
#include "./dev/consoles/fns/run-s0_3_r3.cpp"


//#include "kans.h"
//USING_KANS(GTagML)

#include <QDebug>

//#include "compilation-unit-object.h"
//#include "unified-runtime-object.h"
//#include "metatype-object.h"

#include "chasm-call-package.h"
#include "chasm-channel.h"


Chasm_Runtime::Chasm_Runtime()
 :  gen_trisym_line_index_(0), gen_trisym_file_index_(0),
    gen_trisym_col_index_(0), call_package_index_(0),
    current_no_file_session_(0)
{

}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<n8&>()
{
 return gen_carrier(0);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<u1>()
{
 return gen_carrier(1);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<u2>()
{
 return gen_carrier(2);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<QString>()
{
 return gen_carrier(3);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<u4>()
{
 return gen_carrier(4);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<QByteArray>()
{
 return gen_carrier(5);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<r8>()
{
 return gen_carrier(6);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<QVariant>()
{
 return gen_carrier(7);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<n8>()
{
 return gen_carrier(8);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<void*>()
{
 return gen_carrier(9);
}


template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<n8&>(void* pv)
{
 return gen_carrier(0).take_value(pv);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<u1>(void* pv)
{
 return gen_carrier(1).take_value(pv);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<u2>(void* pv)
{
 return gen_carrier(2).take_value(pv);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<QString>(void* pv)
{
 return gen_carrier(3).take_value(pv);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<u4>(void* pv)
{
 return gen_carrier(4).take_value(pv);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<QByteArray>(void* pv)
{
 return gen_carrier(5).take_value(pv);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<r8>(void* pv)
{
 return gen_carrier(6).take_value(pv);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<QVariant>(void* pv)
{
 return gen_carrier(7).take_value(pv);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<n8>(void* pv)
{
 return gen_carrier(8).take_value(pv);
}

template<>
Chasm_Carrier Chasm_Runtime::gen_carrier<void*>(void* pv)
{
 return gen_carrier(9).take_value(pv);
}



void Chasm_Runtime::evaluate_r0(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_r0_type fn)
{
 Chasm_Channel* lambda = ccp->channel("lambda");
 if(!lambda)
   return;
 run_s0_3_r0(fncode, (minimal_fn_s0_r0_type) fn,
   lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3));
}

void Chasm_Runtime::evaluate_r1(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_r1_type fn, Chasm_Carrier* rcar)
{
 Chasm_Channel* lambda = ccp->channel("lambda");
 if(!lambda)
   return;

 Chasm_Channel* resultch = ccp->channel("result");
 if(!resultch)
   return;

 Chasm_Carrier cc = resultch->first_carrier();

 u1 rr = cc.value();

 run_s0_3_r1(fncode, (minimal_fn_s0_r1_type) fn,
   rr, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3));

 if(rcar)
   rcar->set_value(rr);
}


void Chasm_Runtime::evaluate_r2(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_r2_type fn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/ch-eval-s0_3_r2.cpp"
}


void Chasm_Runtime::evaluate_r3(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_r3_type fn, Chasm_Carrier* rcar)
{
 Chasm_Channel* lambda = ccp->channel("lambda");
 if(!lambda)
   return;

 Chasm_Channel* resultch = ccp->channel("result");
 if(!resultch)
   return;

 Chasm_Carrier cc = resultch->first_carrier();

 QString& rr = *(QString*)cc.value();

 run_s0_3_r3(fncode, (minimal_fn_s0_r3_type) fn,
   rr, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3));

 if(rcar)
   rcar->set_value_as<QString>(rr);

}



Chasm_Carrier Chasm_Runtime::gen_carrier(QString type_name)
{
 trisym tri;
 tri.set_fcode(current_no_file_session_);
 tri.set_lcode(-(++gen_trisym_line_index_));
 tri.set_ccode(1);
 Chasm_Carrier result;
 result.set_key(tri);
 return result;
}

Chasm_Carrier Chasm_Runtime::gen_carrier(u1 type_flag)
{
 Chasm_Carrier result = gen_carrier();
 result.set_type_flag(type_flag);
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


