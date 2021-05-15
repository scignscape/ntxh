
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "chasm-runtime.h"

#include <QString>
#include <QVariant>
#include <QByteArray>

#include <QUrl>

#include <QPoint>

#define FULL_INCLUDE
#ifdef HIDE
#include "./dev/consoles/fns/s01/a3/run-s01_3_re0.cpp"
#include "./dev/consoles/fns/s01/a3/run-s01_3_re1.cpp"
#include "./dev/consoles/fns/s01/a3/run-s01_3_re2.cpp"
#include "./dev/consoles/fns/s01/a3/run-s01_3_re3.cpp"
#include "./dev/consoles/fns/s01/a3/run-s01_3_re4.cpp"
#include "./dev/consoles/fns/s01/a3/run-s01_3_re5.cpp"
#include "./dev/consoles/fns/s01/a3/run-s01_3_re6.cpp"
#include "./dev/consoles/fns/s01/a3/run-s01_3_re7.cpp"
#include "./dev/consoles/fns/s01/a3/run-s01_3_re8.cpp"
#include "./dev/consoles/fns/s01/a3/run-s01_3_re9.cpp"

#include "./dev/consoles/fns/s01/a2/run-s01_2_re0.cpp"
#include "./dev/consoles/fns/s01/a2/run-s01_2_re1.cpp"
#include "./dev/consoles/fns/s01/a2/run-s01_2_re2.cpp"
#include "./dev/consoles/fns/s01/a2/run-s01_2_re3.cpp"
#include "./dev/consoles/fns/s01/a2/run-s01_2_re4.cpp"
#include "./dev/consoles/fns/s01/a2/run-s01_2_re5.cpp"
#include "./dev/consoles/fns/s01/a2/run-s01_2_re6.cpp"
#include "./dev/consoles/fns/s01/a2/run-s01_2_re7.cpp"
#include "./dev/consoles/fns/s01/a2/run-s01_2_re8.cpp"
#include "./dev/consoles/fns/s01/a2/run-s01_2_re9.cpp"

#include "./dev/consoles/fns/s01/a1/run-s01_1_re0.cpp"
#include "./dev/consoles/fns/s01/a1/run-s01_1_re1.cpp"
#include "./dev/consoles/fns/s01/a1/run-s01_1_re2.cpp"
#include "./dev/consoles/fns/s01/a1/run-s01_1_re3.cpp"
#include "./dev/consoles/fns/s01/a1/run-s01_1_re4.cpp"
#include "./dev/consoles/fns/s01/a1/run-s01_1_re5.cpp"
#include "./dev/consoles/fns/s01/a1/run-s01_1_re6.cpp"
#include "./dev/consoles/fns/s01/a1/run-s01_1_re7.cpp"
#include "./dev/consoles/fns/s01/a1/run-s01_1_re8.cpp"
#include "./dev/consoles/fns/s01/a1/run-s01_1_re9.cpp"

#include "./dev/consoles/fns/s01/a0/run-s01_0_re0.cpp"
#include "./dev/consoles/fns/s01/a0/run-s01_0_re1.cpp"
#include "./dev/consoles/fns/s01/a0/run-s01_0_re2.cpp"
#include "./dev/consoles/fns/s01/a0/run-s01_0_re3.cpp"
#include "./dev/consoles/fns/s01/a0/run-s01_0_re4.cpp"
#include "./dev/consoles/fns/s01/a0/run-s01_0_re5.cpp"
#include "./dev/consoles/fns/s01/a0/run-s01_0_re6.cpp"
#include "./dev/consoles/fns/s01/a0/run-s01_0_re7.cpp"
#include "./dev/consoles/fns/s01/a0/run-s01_0_re8.cpp"
#include "./dev/consoles/fns/s01/a0/run-s01_0_re9.cpp"
#endif //def HIDE

//#include "kans.h"
//USING_KANS(GTagML)

#include <QDebug>

//#include "compilation-unit-object.h"
//#include "unified-runtime-object.h"
//#include "metatype-object.h"

#include "chasm-call-package.h"
#include "chasm-channel.h"
#include "chasm-type-object.h"


//#include "chasm-runtime.op-cfc.cpp"
//#include "chasm-runtime.eval-4of3.cpp"
//#include "chasm-runtime.eval-3of3.cpp"
//#include "chasm-runtime.eval-Xof2.cpp"
//#include "chasm-runtime.eval-Xof1.cpp"




// Chasm_Channel* lambda = ccp->channel("lambda");
// if(!lambda)
//   return;

// Chasm_Channel* retvalue = ccp->channel("retvalue");
// if(!retvalue)
//   return;

// Chasm_Carrier cc = retvalue->first_carrier();

// void* rr = cc.value<void*>();

// Chasm_Channel* sigma = ccp->channel("sigma");
// void* _this;
// if(sigma)
//   _this = sigma->first_carrier().value<void*>();
// else
//   _this = nullptr;

// u2 index = type_patterns_4of3_map.value(fncode.distinct_pretype_pattern);

// run_s01_4of3_re9(fncode.type_pattern, index, (minimal_fn_s0_re9_type) fn,
//   (minimal_fn_s1_re9_type) sfn, lambda->pasn8(1), lambda->pasn8(2),
//   lambda->pasn8(3), lambda->pasn8(4), rr, _this);

// if(rcar)
//   rcar->set_value(rr);

// run_s01_4of3_re9(u4 pattern, u4 index, minimal_fn_s0_re9_type fn,
//   minimal_fn_s1_re9_type sfn, n8 arg1, n8 arg2, n8 arg3, n8 arg4, void*& retv,  void* _this)
//
//}


//void Chasm_Runtime::evaluate_4of1_re9(Chasm_Call_Package* ccp, Chasm_Function_Code fncode,
//  minimal_fn_s0_re9_type fn, minimal_fn_s1_re9_type sfn, Chasm_Carrier* rcar)
//{
// Chasm_Channel* lambda = ccp->channel("lambda");
// if(!lambda)
//  return;

// Chasm_Channel* retvalue = ccp->channel("retvalue");
// if(!retvalue)
//  return;

// Chasm_Channel* sigma = ccp->channel("sigma");
// void* _this;
// if(sigma)
//  _this = sigma->first_carrier().value<void*>();
// else
//  _this = nullptr;

// Chasm_Carrier cc = retvalue->first_carrier();

// void* rr = cc.value<void*>();

//// u2 index = type_patterns_4of3_map.value(fncode.distinct_pretype_pattern);
////
// run_s01_4of1_re9(fncode.type_pattern, index, (minimal_fn_s0_re9_type) fn,
//  (minimal_fn_s1_re9_type) sfn, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3), lambda->pasn8(4), rr, _this);

// if(rcar)
//  rcar->set_value(rr);

// //#include "./dev/consoles/fns/eval/a4of3/ch-eval-s01_4of3_re9.cpp"
//}



Chasm_Runtime::Chasm_Runtime()
 :  gen_trisym_line_index_(0), gen_trisym_file_index_(0),
    gen_trisym_col_index_(0), call_package_index_(0),
    current_no_file_session_(0)
{
 register_type_object("n8&", 0, 0, 0, -1);
 register_type_object("n8&!", 0, 0, 0, -1);
 //register_type_object("n8&!!", 0, 0, 0, -1);

 register_type_object("u1", 1, 10, 100, 1000);
 register_type_object("u2", 2, 20, 200, 2000);
 register_type_object("QString", 3, 30, 300, 3000);
 register_type_object("u4", 4, 40, 400, 4000);
 register_type_object("QByteArray", 5, 50, 500, 5000);
 register_type_object("r8", 6, 60, 600, 6000);
 register_type_object("QVariant", 7, 70, 700, 7000);
 register_type_object("n8", 8, 80, 800, 8000);
 register_type_object("void*", 9, 90, 900, 9000);
}

Chasm_Type_Object* Chasm_Runtime::get_type_object_by_name(QString name)
{
 return type_objects_.value(name);
}

Chasm_Type_Object* Chasm_Runtime::register_type_object(QString name, u2 pos1code, u2 pos2code,
  u2 pos3code, u2 pos4code)
{
 Chasm_Type_Object* result = new Chasm_Type_Object(name, pos1code, pos2code,
   pos3code, pos4code);

 type_objects_.insert(name, result);

 return result;
}


Chasm_Carrier Chasm_Runtime::gen_shared_ref_carrier(std::shared_ptr<n8>* ss)
{
 return gen_carrier(0).take_shared_ref_value(ss);
}

//Chasm_Carrier Chasm_Runtime::gen_shared_ref_carrier(n8 val)
//{
// std::shared_ptr<n8>* ss = new std::shared_ptr<n8>((n8*) val);
// return gen_carrier(0).take_twice_shared_ref_value(ss);
//}


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

Chasm_Carrier Chasm_Runtime::gen_carrier(Chasm_Typed_Value_Representation& tvr)
{
 Chasm_Type_Object* cto = tvr.type_object;

 // just until the full reg is set up ...

 if(cto->name() == "QString")
 {
  return gen_carrier<QString>(&tvr.rep);
 }

 if(cto->name() == "QVariant")
 {
  QString typ = tvr.rep.left(4);
  QString rep = tvr.rep.mid(4);
  QVariant r;
  if(typ == "url:")
    r = QUrl(tvr.rep);
  else if(typ == "int:")
    r = tvr.rep.toInt();
  else
    r = tvr.rep;
  return gen_carrier<QVariant>(&r);
 }

 if(cto->name() == "u1")
 {
  u1 arg = tvr.rep.toUInt();
  return gen_carrier<u1>(&arg);
 }

 if(cto->name() == "n8")
 {
  n8 arg = tvr.rep.toULongLong();
  return gen_carrier<n8>(&arg);
 }

 if(cto->name() == "void*")
 {
  void* arg = (void*) tvr.raw_value;
  return gen_carrier<void*>(&arg);
 }

// if(cto->name() == "n8&!")
// {
//  return gen_shared_ref_carrier(tvr.raw_value);
//  //return gen_shared_ref_carrier(*(std::shared_ptr<n8>*) tvr.raw_value);
// }

 if(cto->name() == "n8&!")
 {
  return gen_shared_ref_carrier((std::shared_ptr<n8>*) tvr.raw_value);
  //return gen_shared_ref_carrier(*(std::shared_ptr<n8>*) tvr.raw_value);
 }

 if(cto->name() == "n8&")
 {
  return gen_carrier<n8&>((n8*) tvr.raw_value);
 }

 return gen_carrier<void*>(&tvr.raw_value);
}


void Chasm_Runtime::release(Chasm_Call_Package* ccp)
{
 QMapIterator<QString, Chasm_Channel*> it(ccp->channels());
 while(it.hasNext())
 {
  it.next();
  Chasm_Channel* ch = it.value();

  for(Chasm_Carrier cc : ch->carriers())
  {
   if(cc.key().type_flag() == 14)
   {
    std::shared_ptr<n8>* ss = cc.raw_value_as<std::shared_ptr<n8>*>();
    delete ss;
   }
  }
 }

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

void _evaluate_s01_0_rX(Chasm_Call_Package* ccp, Chasm_Function_Code fncode,
  void(*fn)(), void(_min_::*sfn)(), Chasm_Carrier* rcar)
{
 Chasm_Channel* sigma = ccp->channel("sigma");
 void** _this; void* _this_;
 if(sigma)
 {
  _this_ = sigma->first_carrier().value<void*>();
  _this = &_this_;
 }
 else { _this = nullptr; _this_ = nullptr; }

 if(fncode.return_code == 0)
 {
  if(_this)
    ((_min_*)*_this->*sfn)();
  else
    fn();
  return;
 }

 Chasm_Channel* retvalue = ccp->channel("retvalue");
 if(!retvalue)
   return;

 Chasm_Carrier cc = retvalue->first_carrier();

 switch (fncode.return_code)
 {
 case 1:
  {
   u1 rr = cc.value<u1>();
   if(_this)
   {
    auto _sfn = (u1(_min_::*)())(sfn);
    rr=((_min_*)*_this->*_sfn)();
   }
   else
     rr=((u1(*)())fn)();
   if(rcar)
     rcar->set_value(rr);
   break;
  }
 case 2:
  {
   u2 rr = cc.value<u2>();
   if(_this)
   {
    auto _sfn = (u1(_min_::*)())(sfn);
    rr=((_min_*)*_this->*_sfn)();
   }
   else
     rr=((u2(*)())fn)();
   if(rcar)
     rcar->set_value(rr);
   break;
  }
 case 3:
  {
   QString& rr = cc.value_as<QString>();
   if(_this)
   {
    auto _sfn = (QString(_min_::*)())(sfn);
    rr=((_min_*)*_this->*_sfn)();
   }
   else
     rr=((QString(*)())fn)();
   if(rcar)
     rcar->set_value_as<QString>(rr);
   break;
  }
 case 4:
  {
   u4 rr = cc.value<u4>();
   if(_this)
   {
    auto _sfn = (u4(_min_::*)())(sfn);
    rr=((_min_*)*_this->*_sfn)();
   }
   else
     rr=((u4(*)())fn)();
   if(rcar)
     rcar->set_value(rr);
   break;
  }
 case 5:
  {
   QByteArray& rr = cc.value_as<QByteArray>();
   if(_this)
   {
    auto _sfn = (QByteArray(_min_::*)())(sfn);
    rr=((_min_*)*_this->*_sfn)();
   }
   else
     rr=((QByteArray(*)())fn)();
   if(rcar)
     rcar->set_value_as<QByteArray>(rr);
   break;
  }
 case 6:
  {
   r8 rr = cc.value<r8>();
   if(_this)
   {
    auto _sfn = (r8(_min_::*)())(sfn);
    rr=((_min_*)*_this->*_sfn)();
   }
   else
     rr=((r8(*)())fn)();
   if(rcar)
     rcar->set_value(rr);
   break;
  }
 case 7:
  {
   QVariant& rr = cc.value_as<QVariant>();
   if(_this)
   {
    auto _sfn = (QVariant(_min_::*)())(sfn);
    rr=((_min_*)*_this->*_sfn)();
   }
   else
     rr=((QVariant(*)())fn)();
   if(rcar)
     rcar->set_value_as<QVariant>(rr);
   break;
  }
 case 8:
  {
   n8 rr = cc.value<n8>();
   if(_this)
   {
    auto _sfn = (n8(_min_::*)())(sfn);
    rr=((_min_*)*_this->*_sfn)();
   }
   else
     rr=((n8(*)())fn)();
   if(rcar)
     rcar->set_value(rr);
   break;
  }
 case 9:
  {
   void* rr = cc.value<void*>();
   if(_this)
   {
    auto _sfn = (void*(_min_::*)())(sfn);
    rr=((_min_*)*_this->*_sfn)();
   }
   else
     rr=((void*(*)())fn)();
   if(rcar)
     rcar->set_value(rr);
   break;
  }
 }
}


#ifdef HIDE

void Chasm_Runtime::evaluate_3_re0(Chasm_Call_Package* ccp, u2 fncode,
  minimal_fn_s0_re0_type fn, minimal_fn_s1_re0_type sfn)
{
#include "./dev/consoles/fns/s01/a3/ch-eval-s01_3_re0.cpp"
}

void Chasm_Runtime::evaluate_3_re1(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re1_type fn, minimal_fn_s1_re1_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a3/ch-eval-s01_3_re1.cpp"
}


void Chasm_Runtime::evaluate_3_re2(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re2_type fn, minimal_fn_s1_re2_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a3/ch-eval-s01_3_re2.cpp"
}

void Chasm_Runtime::evaluate_3_re3(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re3_type fn, minimal_fn_s1_re3_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a3/ch-eval-s01_3_re3.cpp"
}

void Chasm_Runtime::evaluate_3_re4(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re4_type fn, minimal_fn_s1_re4_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a3/ch-eval-s01_3_re4.cpp"
}

void Chasm_Runtime::evaluate_3_re5(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re5_type fn, minimal_fn_s1_re5_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a3/ch-eval-s01_3_re5.cpp"
}

void Chasm_Runtime::evaluate_3_re6(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re6_type fn, minimal_fn_s1_re6_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a3/ch-eval-s01_3_re6.cpp"
}

void Chasm_Runtime::evaluate_3_re7(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re7_type fn, minimal_fn_s1_re7_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a3/ch-eval-s01_3_re7.cpp"
}

void Chasm_Runtime::evaluate_3_re8(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re8_type fn, minimal_fn_s1_re8_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a3/ch-eval-s01_3_re8.cpp"
}

void Chasm_Runtime::evaluate_3_re9(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re9_type fn, minimal_fn_s1_re9_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a3/ch-eval-s01_3_re9.cpp"
}



void Chasm_Runtime::evaluate_2_re0(Chasm_Call_Package* ccp, u2 fncode,
  minimal_fn_s0_re0_type fn, minimal_fn_s1_re0_type sfn)
{
#include "./dev/consoles/fns/s01/a2/ch-eval-s01_2_re0.cpp"
}

void Chasm_Runtime::evaluate_2_re1(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re1_type fn, minimal_fn_s1_re1_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a2/ch-eval-s01_2_re1.cpp"
}

void Chasm_Runtime::evaluate_2_re2(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re2_type fn, minimal_fn_s1_re2_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a2/ch-eval-s01_2_re2.cpp"
}

void Chasm_Runtime::evaluate_2_re3(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re3_type fn, minimal_fn_s1_re3_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a2/ch-eval-s01_2_re3.cpp"
}

void Chasm_Runtime::evaluate_2_re4(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re4_type fn, minimal_fn_s1_re4_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a2/ch-eval-s01_2_re4.cpp"
}

void Chasm_Runtime::evaluate_2_re5(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re5_type fn, minimal_fn_s1_re5_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a2/ch-eval-s01_2_re5.cpp"
}

void Chasm_Runtime::evaluate_2_re6(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re6_type fn, minimal_fn_s1_re6_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a2/ch-eval-s01_2_re6.cpp"
}

void Chasm_Runtime::evaluate_2_re7(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re7_type fn, minimal_fn_s1_re7_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a2/ch-eval-s01_2_re7.cpp"
}

void Chasm_Runtime::evaluate_2_re8(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re8_type fn, minimal_fn_s1_re8_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a2/ch-eval-s01_2_re8.cpp"
}

void Chasm_Runtime::evaluate_2_re9(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re9_type fn, minimal_fn_s1_re9_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a2/ch-eval-s01_2_re9.cpp"
}


void Chasm_Runtime::evaluate_1_re0(Chasm_Call_Package* ccp, u2 fncode, minimal_fn_s0_re0_type fn,
  minimal_fn_s1_re0_type sfn)
{
#include "./dev/consoles/fns/s01/a1/ch-eval-s01_1_re0.cpp"
}

void Chasm_Runtime::evaluate_1_re1(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re1_type fn, minimal_fn_s1_re1_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a1/ch-eval-s01_1_re1.cpp"
}

void Chasm_Runtime::evaluate_1_re2(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re2_type fn, minimal_fn_s1_re2_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a1/ch-eval-s01_1_re2.cpp"
}

void Chasm_Runtime::evaluate_1_re3(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re3_type fn, minimal_fn_s1_re3_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a1/ch-eval-s01_1_re3.cpp"
}

void Chasm_Runtime::evaluate_1_re4(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re4_type fn, minimal_fn_s1_re4_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a1/ch-eval-s01_1_re4.cpp"
}

void Chasm_Runtime::evaluate_1_re5(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re5_type fn, minimal_fn_s1_re5_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a1/ch-eval-s01_1_re5.cpp"
}

void Chasm_Runtime::evaluate_1_re6(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re6_type fn, minimal_fn_s1_re6_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a1/ch-eval-s01_1_re6.cpp"
}

void Chasm_Runtime::evaluate_1_re7(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re7_type fn, minimal_fn_s1_re7_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a1/ch-eval-s01_1_re7.cpp"
}

void Chasm_Runtime::evaluate_1_re8(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re8_type fn, minimal_fn_s1_re8_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a1/ch-eval-s01_1_re8.cpp"
}

void Chasm_Runtime::evaluate_1_re9(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re9_type fn, minimal_fn_s1_re9_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a1/ch-eval-s01_1_re9.cpp"
}



void Chasm_Runtime::evaluate_0_re0(Chasm_Call_Package* ccp,
  u2 fncode, minimal_fn_s0_re0_type fn, minimal_fn_s1_re0_type sfn)
{
#include "./dev/consoles/fns/s01/a0/ch-eval-s01_0_re0.cpp"
}

void Chasm_Runtime::evaluate_0_re1(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re1_type fn, minimal_fn_s1_re1_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a0/ch-eval-s01_0_re1.cpp"
}

void Chasm_Runtime::evaluate_0_re2(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re2_type fn, minimal_fn_s1_re2_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a0/ch-eval-s01_0_re2.cpp"
}

void Chasm_Runtime::evaluate_0_re3(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re3_type fn, minimal_fn_s1_re3_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a0/ch-eval-s01_0_re3.cpp"
}

void Chasm_Runtime::evaluate_0_re4(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re4_type fn, minimal_fn_s1_re4_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a0/ch-eval-s01_0_re4.cpp"
}

void Chasm_Runtime::evaluate_0_re5(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re5_type fn, minimal_fn_s1_re5_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a0/ch-eval-s01_0_re5.cpp"
}

void Chasm_Runtime::evaluate_0_re6(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re6_type fn, minimal_fn_s1_re6_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a0/ch-eval-s01_0_re6.cpp"
}

void Chasm_Runtime::evaluate_0_re7(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re7_type fn, minimal_fn_s1_re7_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a0/ch-eval-s01_0_re7.cpp"
}

void Chasm_Runtime::evaluate_0_re8(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re8_type fn, minimal_fn_s1_re8_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a0/ch-eval-s01_0_re8.cpp"
}

void Chasm_Runtime::evaluate_0_re9(Chasm_Call_Package* ccp,
 u2 fncode, minimal_fn_s0_re9_type fn,
 minimal_fn_s1_re9_type sfn, Chasm_Carrier* rcar)
{
#include "./dev/consoles/fns/s01/a0/ch-eval-s01_0_re9.cpp"
}

#endif // HIDE
