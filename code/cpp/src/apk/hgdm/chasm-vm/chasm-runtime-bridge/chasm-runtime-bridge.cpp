
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "chasm-runtime-bridge.h"

#include "chasm/chasm-runtime.h"
#include "chasm/chasm-call-package.h"

#include <QString>
#include <QVariant>
#include <QByteArray>

#include <QUrl>

#include <QPoint>


Chasm_Runtime_Bridge::Chasm_Runtime_Bridge(Chasm_Runtime* csr)
  :  csr_(csr), current_call_package_(nullptr),
     current_type_object_(nullptr), current_carrienr_queue_(nullptr)
{
 const QVector<Chasm_Type_Object*>& pto = *csr_->pretype_type_objects();

 type_object_ref_ = pto[0];
 type_object_u1_ = pto[1];
 type_object_u2_ = pto[2];
 type_object_QString_ = pto[3];
 type_object_u4_ = pto[4];
 type_object_QByteArray_ = pto[5];
 type_object_r8_ = pto[6];
 type_object_QVariant_ = pto[7];
 type_object_n8_ = pto[8];
 type_object_ptr_ = pto[9];
}

void Chasm_Runtime_Bridge::push_carrier_queue()
{
 current_carrienr_queue_ = new QQueue<Chasm_Carrier>;
 carrier_stacks_.push(current_carrienr_queue_);
}

void Chasm_Runtime_Bridge::gen_carrier()
{
 current_carrienr_queue_->enqueue( csr_->gen_carrier_by_type_object(current_type_object_) );
}

void Chasm_Runtime_Bridge::gen_carrier(void* pv)
{
 current_carrienr_queue_->enqueue( csr_->gen_carrier_by_type_object(current_type_object_, pv) );
}


void Chasm_Runtime_Bridge::load_type_ref()
{
 current_type_object_ = type_object_ref_;
}

void Chasm_Runtime_Bridge::load_type_u1()
{
 current_type_object_ = type_object_u1_;
}

void Chasm_Runtime_Bridge::load_type_u2()
{
 current_type_object_ = type_object_u2_;
}

void Chasm_Runtime_Bridge::load_type_QString()
{
 current_type_object_ = type_object_QString_;
}

void Chasm_Runtime_Bridge::load_type_u4()
{
 current_type_object_ = type_object_u4_;
}

void Chasm_Runtime_Bridge::load_type_QByteArray()
{
 current_type_object_ = type_object_QByteArray_;
}

void Chasm_Runtime_Bridge::load_type_r8()
{
 current_type_object_ = type_object_r8_;
}

void Chasm_Runtime_Bridge::load_type_QVariant()
{
 current_type_object_ = type_object_QVariant_;
}

void Chasm_Runtime_Bridge::load_type_n8()
{
 current_type_object_ = type_object_n8_;
}

void Chasm_Runtime_Bridge::load_type_ptr()
{
 current_type_object_ = type_object_ptr_;
}


void Chasm_Runtime_Bridge::new_call_package() //Chasm_Call_Package*
{
 current_call_package_ = csr_->new_call_package();
}

void Chasm_Runtime_Bridge::add_new_channel(QString name)
{
 current_call_package_->add_new_channel(name);
}

