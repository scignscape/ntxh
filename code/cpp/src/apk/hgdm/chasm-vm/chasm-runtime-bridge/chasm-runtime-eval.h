
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef CHASM_RUNTIME_EVAL__H
#define CHASM_RUNTIME_EVAL__H

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

//#define register_s0(proc ,code) register_procedure_s0(#proc, (void(*)()) &proc, #code)
//#define register_s1(proc ,code) register_procedure_s1(#proc, (void(_min_::*)()) &proc, #code)

#include "chasm-procedure-table/chasm-procedure-table.h"

class Chasm_Call_Package;
class Chasm_Type_Object;
class CSM_Ghost_Scope;


//typedef void(*_minimal_fn_s0_type)();
//typedef void(_min_::*_minimal_fn_s1_type)();
//union _minimal_fn_type { _minimal_fn_s0_type s0; _minimal_fn_s1_type s1; };

class Chasm_Runtime_Eval
{
 Chasm_Runtime* csr_;

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

 Chasm_Procedure_Table* proctable_;


public:

 ACCESSORS(Chasm_Procedure_Table* ,proctable)

 Chasm_Runtime_Eval(Chasm_Runtime* csr);

 Chasm_Carrier call_s1(void* obj, QString name);

 Chasm_Carrier call_s0(QString name, QString args_rep);


};

// _KANS(GTagML)

#endif // CHASM_RUNTIME_EVAL__H
