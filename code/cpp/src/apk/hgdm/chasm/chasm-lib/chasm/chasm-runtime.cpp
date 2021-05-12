
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

#define FULL_INCLUDE
#include "./dev/consoles/fns/run-a4of3/run-s01-4of3-re9.cpp"

u1 _early_parse(Chasm_Function_Code& cfc, n8& cue)
{
 if(cue >= 10000000000) // 10 digits
 {
  cfc.arg_count = cue / 10000000000;
  cue %= 10000000000;
  cfc.convention = cue / 1000000000;
  cue %= 1000000000;
  cfc.return_code = cue / 100000000;
  cue %= 100000000; // 8 digits left
  return 8;
 }
 else if(cue >= 1000000000) // 10 digits
 {
  cfc.arg_count = cue / 1000000000;
  cue %= 1000000000;
  cfc.convention = cue / 100000000;
  cue %= 100000000;
  cfc.return_code = cue / 10000000;
  cue %= 10000000; // 7 digits left
  return 7;
 }
 else if(cue >= 100000000) // 9 digits
 {
  cfc.arg_count = cue / 100000000;
  cue %= 100000000;
  cfc.convention = cue / 10000000;
  cue %= 10000000;
  cfc.return_code = cue / 1000000;
  cue %= 1000000; // 6 digits left
  return 6;
 }
 else if(cue >= 10000000) // 8 digits
 {
  cfc.arg_count = cue / 10000000;
  cue %= 10000000;
  cfc.convention = cue / 1000000;
  cue %= 1000000;
  cfc.return_code = cue / 100000;
  cue %= 100000; // 5 digits left
  return 5;
 }
 else if(cue >= 1000000) // 7 digits
 {
  cfc.arg_count = cue / 1000000;
  cue %= 1000000;
  cfc.convention = cue / 100000;
  cue %= 100000;
  cfc.return_code = cue / 10000;
  cue %= 10000; // 4 digits left
  return 4;
 }
 else if(cue >= 10000) // 6 digits
 {
  cfc.arg_count = cue / 100000;
  cue %= 100000;
  cfc.convention = cue / 10000;
  cue %= 10000;
  cfc.return_code = cue / 1000;
  cue %= 1000; // 3 digits left
  return 3;
 }
 else if(cue >= 10000) // 5 digits
 {
  cfc.arg_count = cue / 10000;
  cue %= 10000;
  cfc.convention = cue / 1000;
  cue %= 1000;
  cfc.return_code = cue / 100;
  cue %= 100; // 2 digits left
  return 2;
 }
 else if(cue >= 1000) // 4 digits
 {
  cfc.arg_count = cue / 1000;
  cue %= 1000;
  cfc.convention = cue / 100;
  cue %= 100;
  cfc.return_code = cue / 10;
  cue %= 10; // 1 digits left
  return 1;
 }
 else if(cue >= 100) // 3 digits
 {
  cfc.arg_count = cue / 100;
  cue %= 100;
  cfc.convention = cue / 10;
  cue %= 10;
  cfc.return_code = cue;  // 0 digits left
  return 0;
 }
 else if(cue >= 10) // 2 digits
 {
  cfc.arg_count = 0;
  cfc.convention = cue / 10;
  cfc.return_code = cue % 10;
  return 0;
 }
 else // 1 digit
 {
  cfc.arg_count = 0;
  cfc.convention = 0;
  cfc.return_code = cue;
  return 0;
 }

}

u1 _do_binary(u1 arg_count, u4 type_pattern)
{
 u1 result = 0;
 u1 mask = ~((1 << arg_count) - 1);
 bool last_true = false;
 for(u1 i = 0, b = 1; i < arg_count; ++i, b <<= 1)
 {
  u1 d = type_pattern % 10;
  last_true = (d == 2);
  if(last_true)
    result |= b;
  type_pattern /= 10;
 }
 if(!last_true)
 {
  result |= mask;
 }
 return result;
}

Chasm_Function_Code _parse_cfc(n8 cue, bool udn_literal = true)
{
 Chasm_Function_Code result;

 //result.type_pattern_binary = udn_literal? 100:200;

 result.type_pattern_binary = 0;

 u1 distinct_type_pattern_len, arg_count;
 u4 distinct_type_pattern_len_exp = 1;
 u4 arg_count_exp = 1;

 auto do_exp = [&distinct_type_pattern_len, &arg_count,
   &distinct_type_pattern_len_exp, &arg_count_exp]()
 {
  for(int i = 0; i < distinct_type_pattern_len; ++i)
    distinct_type_pattern_len_exp *= 10;
  distinct_type_pattern_len_exp *= arg_count;
  for(int i = 0; i < arg_count; ++i)
    arg_count_exp *= 10;
 };



 u1 len = _early_parse(result, cue);
 arg_count = result.arg_count;

 if(len == 1)
 {
  result.type_pattern = cue % 10;
  return result;
 }

 if(len > result.arg_count)
 {
  // type pattern already encoded
  distinct_type_pattern_len = len - result.arg_count;
    // result.type_pattern_binary += (distinct_type_pattern_len * 10) + result.arg_count;
  do_exp();

  if(distinct_type_pattern_len > 2)
  {
   result.type_pattern = cue % arg_count_exp;
   cue /= arg_count_exp;
   result.distinct_type_pattern = distinct_type_pattern_len_exp + cue;
   return result;
  }
  else if(distinct_type_pattern_len == 2)
  {
   u4 type_pattern = cue % arg_count_exp;
   cue /= arg_count_exp;
   result.distinct_type_pattern = distinct_type_pattern_len_exp + cue;
   if(arg_count < 6)
     result.type_pattern = type_pattern;
   else
     result.type_pattern = -1;

   result.type_pattern_binary = _do_binary(arg_count, type_pattern);
   return result;
  }
  else if(distinct_type_pattern_len == 1)
  {

  }
 }

 result.type_pattern = result.distinct_type_pattern = 0;

 // // need to encode the type pattern
 u1 type_counts[arg_count];
 u1 distinct_type_numbers[arg_count];// {255,255,255};
 u1 type_numbers[arg_count];// {255,255,255};
// for(int i = 0; i < arg_count; ++i)
// {
//  type_counts[i] = 0;
//  type_numbers[i] = 255;
// }

 u1 seen_type_count = 0;
 u1 digit_exp = 1;

 u4 types = cue; // % arg_count_exp;


 for(int i = 0; i < arg_count; ++i) //, digit_exp *= 10)
 {
  u1 d = types % 10;
  type_numbers[arg_count - i - 1] = d;

  u1 j = 0;

  if(seen_type_count == 0)
  {
   seen_type_count = 1;
   distinct_type_numbers[0] = d;
   type_counts[0] = 1;
//   types /= 10;
//   continue;
   goto outer_continue;
  }

  for(; j < seen_type_count; ++j)
  {
   if(distinct_type_numbers[j] == d)
   {
    ++type_counts[j];
    goto outer_continue;
   }
  }

  ++seen_type_count;
  distinct_type_numbers[j] = d;
  type_counts[j] = 1;

 outer_continue:
  types /= 10;
 }

 // problem if any type counts are > 3 ...


 std::sort(distinct_type_numbers, distinct_type_numbers + seen_type_count);

 u4 e = 1;
 for(s1 i = seen_type_count - 1; i >= 0; --i, e *= 10) //, digit_exp *= 10)
 {
  u1 d = distinct_type_numbers[i];
  result.distinct_type_pattern += d * e;
 }
 result.distinct_type_pattern += arg_count * e;

 u4 type_pattern = 0;
 e = 1;
 for(s1 i = arg_count - 1; i >= 0; --i, e *= 10) //, digit_exp *= 10)
 {
  u1 d = type_numbers[i];
  for(u1 j = 0; j < seen_type_count; ++j)
  {
   if(d == distinct_type_numbers[j])
   {
    type_pattern += ((j + 1) * e);
    break;
   }
  }
 }

 if(arg_count < 6)
   result.type_pattern = type_pattern;

 if(seen_type_count == 2)
   result.type_pattern_binary = _do_binary(arg_count, type_pattern);

 return result;
}



Chasm_Function_Code operator""_cfc(n8 cue)
{
 return _parse_cfc(cue);
}

#define INCLUDE_MAP_CODE
 QMap<u2, u2> type_patterns_4of3_map {
  #include "./dev/consoles/fns/type-patterns-4of3.cpp"
 };
#undef INCLUDE_MAP_CODE// def INCLUDE_MAP_CODE


void Chasm_Runtime::evaluate_4_re9(Chasm_Call_Package* ccp, Chasm_Function_Code fncode,
  minimal_fn_s0_re9_type fn, minimal_fn_s1_re9_type sfn, Chasm_Carrier* rcar)
{
 // #include "./dev/consoles/fns/s01/a3/ch-eval-s01_3_re0.cpp"


 Chasm_Channel* lambda = ccp->channel("lambda");
 if(!lambda)
   return;

 Chasm_Channel* retvalue = ccp->channel("retvalue");
 if(!retvalue)
   return;

 Chasm_Carrier cc = retvalue->first_carrier();

 void* rr = cc.value<void*>();

 Chasm_Channel* sigma = ccp->channel("sigma");
 void* _this;
 if(sigma)
   _this = sigma->first_carrier().value<void*>();
 else
   _this = nullptr;

 u2 index = type_patterns_4of3_map.value(fncode.distinct_type_pattern);

 run_s01_4of3_re9(fncode.type_pattern, index, (minimal_fn_s0_re9_type) fn,
   (minimal_fn_s1_re9_type) sfn, lambda->pasn8(1), lambda->pasn8(2),
   lambda->pasn8(3), lambda->pasn8(4), rr, _this);

 if(rcar)
   rcar->set_value(rr);

// run_s01_4of3_re9(u4 pattern, u4 index, minimal_fn_s0_re9_type fn,
//   minimal_fn_s1_re9_type sfn, n8 arg1, n8 arg2, n8 arg3, n8 arg4, void*& retv,  void* _this)
//
}



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
