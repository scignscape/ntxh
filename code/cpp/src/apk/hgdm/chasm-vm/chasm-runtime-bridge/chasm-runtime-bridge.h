
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

#include <QDebug>

#include "chasm/chasm-carrier.h"

#include "accessors.h"
#include "flags.h"

#include "global-types.h"
#include "kans.h"


class Chasm_Runtime;
class Chasm_Call_Package;
class Chasm_Type_Object;

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

 QStack<QQueue<Chasm_Carrier>*> carrier_stacks_;

 QQueue<Chasm_Carrier>* current_carrienr_queue_;

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

 void push_carrier_queue();
 void gen_carrier();
 void gen_carrier(void* pv);


};

// _KANS(GTagML)

#endif // CHASM_RUNTIME_BRIDGE__H