
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


struct _min_{};

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

#endif // def HIDE

//#include "./dev/consoles/fns/run-a4of3/run-s01-4of3-re0.cpp"
//#include "./dev/consoles/fns/run-a4of3/run-s01-4of3-re1.cpp"
//#include "./dev/consoles/fns/run-a4of3/run-s01-4of3-re2.cpp"
//#include "./dev/consoles/fns/run-a4of3/run-s01-4of3-re3.cpp"
//#include "./dev/consoles/fns/run-a4of3/run-s01-4of3-re4.cpp"
//#include "./dev/consoles/fns/run-a4of3/run-s01-4of3-re5.cpp"
//#include "./dev/consoles/fns/run-a4of3/run-s01-4of3-re6.cpp"
//#include "./dev/consoles/fns/run-a4of3/run-s01-4of3-re7.cpp"
//#include "./dev/consoles/fns/run-a4of3/run-s01-4of3-re8.cpp"
//#include "./dev/consoles/fns/run-a4of3/run-s01-4of3-re9.cpp"



//struct _min_{};

class Chasm_Call_Package;
class Chasm_Type_Object;

struct Chasm_Typed_Value_Representation
{
 Chasm_Type_Object* type_object;
 n8 raw_value;
 QString rep;
};

struct Chasm_Function_Code
{
 u1 arg_count;
 u1 convention;
 u1 return_code;
 u2 distinct_type_pattern;
 s2 type_pattern;
 u1 type_pattern_binary;
};

Chasm_Function_Code operator""_cfc(n8 cue);

//KANS_(GTagML)


//template<typename FN_Type>
extern void _evaluate_s01_3of3(Chasm_Call_Package* ccp, Chasm_Function_Code fncode,
  void(*fn)(), void(_min_::*sfn)(), Chasm_Carrier* rcar);

//FN_Type fn, Chasm_Carrier* rcar);

//template<typename FN_Type>
extern void _evaluate_s01_4of3(Chasm_Call_Package* ccp, Chasm_Function_Code fncode,
  void(*fn)(), void(_min_::*sfn)(), Chasm_Carrier* rcar);

                              //FN_Type fn, Chasm_Carrier* rcar);

//template<typename FN_Type>
//extern void _evaluate_s0_Xof1(Chasm_Call_Package* ccp, Chasm_Function_Code fncode,
//  FN_Type fn, Chasm_Carrier* rcar);

extern void _evaluate_s01_Xof1(Chasm_Call_Package* ccp, Chasm_Function_Code fncode,
  void(*fn)(), void(_min_::*sfn)(), Chasm_Carrier* rcar);


//template<typename FN_Type>
extern void _evaluate_s01_Xof2(Chasm_Call_Package* ccp, Chasm_Function_Code fncode,
  void(*fn)(), void(_min_::*sfn)(), Chasm_Carrier* rcar);

                               //FN_Type fn, Chasm_Carrier* rcar);

void _evaluate_s01_0_rX(Chasm_Call_Package* ccp, Chasm_Function_Code fncode,
  void(*fn)(), void(_min_::*sfn)(), Chasm_Carrier* rcar);

//void _evaluate_s1_0_rX(Chasm_Call_Package* ccp, Chasm_Function_Code fncode,
//  void(*fn)(), Chasm_Carrier* rcar);


class Chasm_Runtime
{
 //QString text_;

 struct _Retvalue
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

  _Retvalue() : _ref(new n8(0)), _u1(new u1(0)), _u2(new u2(0)),
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

 QMap<QString, Chasm_Type_Object*> type_objects_;

public:

 Chasm_Runtime();

 _Retvalue Retvalue;

 Chasm_Type_Object* register_type_object(QString name, u2 pos1code, u2 pos2code,
   u2 pos3code, u2 pos4code);

 Chasm_Type_Object* get_type_object_by_name(QString name);

 Chasm_Call_Package* new_call_package();

 Chasm_Carrier gen_carrier(Chasm_Typed_Value_Representation& tvr);
 Chasm_Carrier gen_carrier(QString type_name = {});
 Chasm_Carrier gen_carrier(u1 type_flag);

 Chasm_Carrier gen_shared_ref_carrier(std::shared_ptr<n8>* ss);
 //Chasm_Carrier gen_shared_ref_carrier(n8 val);

 template<typename CARRIER_Type>
 inline Chasm_Carrier gen_carrier();

 template<typename CARRIER_Type>
 inline Chasm_Carrier gen_carrier(void* value);

 void init_no_file_session();

 void release(Chasm_Call_Package* ccp);


 template<typename RETURN_Type, typename CLASS_Type>
 void evaluate(Chasm_Call_Package* ccp, Chasm_Function_Code fncode, RETURN_Type (CLASS_Type::*sfn), Chasm_Carrier* rcar = nullptr)
 {
  if(fncode.distinct_type_pattern < 10)
  {
   if(fncode.distinct_type_pattern == 0)
   {
    if(fncode.convention == 0)
      ; //_evaluate_s01_0_rX(ccp, fncode, (void(*)()) fn, nullptr, rcar);
    else if(fncode.convention == 1)
      _evaluate_s01_0_rX(ccp, fncode, nullptr, (void(_min_::*)()) sfn, rcar);
   }

   else if(fncode.convention == 0)
     ;// _evaluate_s0_Xof1(ccp, fncode, fn, rcar);
   //     else if(fncode.convention == 1)
   //       evaluate_s1_Xof1(ccp, fncode, fn, rcar);
  }
  else if(fncode.distinct_type_pattern < 100)
  {
//   if(fncode.convention == 0)
//     evaluate_s0_Xof2(ccp, fncode, fn, rcar);
  }
  else if(fncode.distinct_type_pattern < 1000)
  {
   if(fncode.convention == 0)
     ;//_evaluate_s0_Xof2(ccp, fncode, fn, rcar);
  }
  else if(fncode.arg_count == 3)
   // // 3 args ...
    ;//_evaluate_s0_3of3(ccp, fncode, fn, rcar);
  else if(fncode.arg_count == 4)
   // // 4 args ...
    ;//_evaluate_s0_4of3(ccp, fncode, fn, rcar);
 }


 template<typename FN_Type>
 void evaluate(Chasm_Call_Package* ccp, Chasm_Function_Code fncode, FN_Type fn, Chasm_Carrier* rcar = nullptr)
 {
  if(fncode.distinct_type_pattern < 10)
  {
   if(fncode.distinct_type_pattern == 0)
   {
    if(fncode.convention == 0)
      _evaluate_s01_0_rX(ccp, fncode, (void(*)()) fn, nullptr, rcar);
    else if(fncode.convention == 1)
      ;//_evaluate_s01_0_rX(ccp, fncode, nullptr, (void(_min_::*)()) fn, rcar);
   }

   else if(fncode.convention == 0)
     _evaluate_s01_Xof1(ccp, fncode, (void(*)()) fn, nullptr, rcar);
   //     else if(fncode.convention == 1)
   //       evaluate_s1_Xof1(ccp, fncode, fn, rcar);
  }
  else if(fncode.distinct_type_pattern < 100)
  {
//   if(fncode.convention == 0)
//     evaluate_s0_Xof2(ccp, fncode, fn, rcar);
  }
  else if(fncode.distinct_type_pattern < 1000)
  {
   if(fncode.convention == 0)
     _evaluate_s01_Xof2(ccp, fncode, (void(*)()) fn, nullptr, rcar);
  }
  else if(fncode.arg_count == 3)
   // // 3 args ...
    _evaluate_s01_3of3(ccp, fncode, (void(*)()) fn, nullptr, rcar);
  else if(fncode.arg_count == 4)
   // // 4 args ...
    _evaluate_s01_4of3(ccp, fncode, (void(*)()) fn, nullptr, rcar);
 }
};

// _KANS(GTagML)

#endif // CHASM_RUNTIME__H
