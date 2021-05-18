
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef CHASM_RUNTIME_BRIDGE__H
#define CHASM_RUNTIME_BRIDGE__H

#include <QString>

#include <QStack>
#include <QVariant>
#include <QQueue>
#include <deque>

#include <QDebug>

#include "chasm/chasm-carrier.h"

#include "accessors.h"
#include "flags.h"

#include "global-types.h"
#include "kans.h"

#include "chasm/chasm-runtime.h"


class Chasm_Call_Package;
class Chasm_Type_Object;

typedef void(*_minimal_fn_s0_type)();
typedef void(_min_::*_minimal_fn_s1_type)();

union _minimal_fn_type { _minimal_fn_s0_type s0; _minimal_fn_s1_type s1; };

class Chasm_Runtime_Bridge
{
 Chasm_Runtime* csr_;
 Chasm_Call_Package* current_call_package_;
 Chasm_Type_Object* current_type_object_;

 Chasm_Type_Object* type_object_ref_;
 Chasm_Type_Object* type_object_u1_;
 Chasm_Type_Object* type_object_u2_;
 Chasm_Type_Object* type_object_QString_;
 Chasm_Type_Object* type_object_u4_;
 Chasm_Type_Object* type_object_QByteArray_;
 Chasm_Type_Object* type_object_r8_;
 Chasm_Type_Object* type_object_QVariant_;
 Chasm_Type_Object* type_object_n8_;
 Chasm_Type_Object* type_object_ptr_;

 QStack<std::deque<Chasm_Carrier>*> carrier_stacks_;

 std::deque<Chasm_Carrier>* current_carrier_deque_;

 QMap<QString, QString> procedure_name_resolutions_;
 QMap<QString, QPair<Chasm_Function_Code, _minimal_fn_type>> registered_procedures_;

 n8 current_loaded_raw_value_;

public:

 Chasm_Runtime_Bridge(Chasm_Runtime* csr);

 void new_call_package(); //Chasm_Call_Package*

 void add_new_channel(QString name);

 void load_type_ref();
 void load_type_u1();
 void load_type_u2();
 void load_type_QString();
 void load_type_u4();
 void load_type_QByteArray();
 void load_type_r8();
 void load_type_QVariant();
 void load_type_n8();
 void load_type_ptr();

 void push_carrier_deque();
 void gen_carrier();
 void gen_carrier(void* pv);
 void gen_carrier_tvr(QString rep);

 void reset_loaded_raw_value();
 void reset_type_object();

 void add_carriers();
 void reset_carrier_deque();

// void register_procedure_s0(QString name,
//   _minimal_fn_s0_type fn, u4 proc);

 void register_procedure_s0(QString name,
   _minimal_fn_s0_type fn, QString code);

 void run_eval(QString proc_name);

};

// _KANS(GTagML)

#endif // CHASM_RUNTIME_BRIDGE__H
