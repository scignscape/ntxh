
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
  :  csr_(csr), current_call_package_(nullptr), current_loaded_raw_value_(0),
     current_type_object_(nullptr), current_carrier_deque_(nullptr)
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


void Chasm_Runtime_Bridge::run_eval(QString proc_name)
{
 {
  auto it = procedure_name_resolutions_.find(proc_name);
  if(it != procedure_name_resolutions_.end())
    proc_name = *it;
 }
 auto it = registered_procedures_.find(proc_name);
 if(it == registered_procedures_.end())
   return;
 const QPair<Chasm_Function_Code, _minimal_fn_type>& pr = *it;
 if(pr.first.convention == 0)
 {
  csr_->evaluate(current_call_package_, pr.first, pr.second.s0);
 }
 else if(pr.first.convention == 1)
 {
  csr_->evaluate(current_call_package_, pr.first, pr.second.s1);
 }
}


void Chasm_Runtime_Bridge::register_procedure_s0(QString name,
  _minimal_fn_s0_type fn, QString proc)
{
 n8 nn = proc.mid(1).toULongLong();
 Chasm_Function_Code fncode = _cfc(nn);
 procedure_name_resolutions_[name] = name + proc;
 registered_procedures_[name + proc] = {fncode, {.s0 = fn}};
}


void Chasm_Runtime_Bridge::reset_carrier_deque()
{
 current_carrier_deque_->clear();
}

void Chasm_Runtime_Bridge::add_carriers()
{
 current_call_package_->add_carriers(*current_carrier_deque_);
}

void Chasm_Runtime_Bridge::push_carrier_deque()
{
 if(current_carrier_deque_)
   carrier_stacks_.push(current_carrier_deque_);
 current_carrier_deque_ = new std::deque<Chasm_Carrier>;
}

void Chasm_Runtime_Bridge::gen_carrier_tvr(QString rep)
{
 Chasm_Typed_Value_Representation tvr({current_type_object_, current_loaded_raw_value_, rep});
 current_carrier_deque_->push_back( csr_->gen_carrier(tvr) );
}

void Chasm_Runtime_Bridge::reset_loaded_raw_value()
{
 current_loaded_raw_value_ = 0;
}

void Chasm_Runtime_Bridge::reset_type_object()
{
 current_type_object_ = nullptr;
}


void Chasm_Runtime_Bridge::gen_carrier()
{
 current_carrier_deque_->push_back( csr_->gen_carrier_by_type_object(current_type_object_) );
}

void Chasm_Runtime_Bridge::gen_carrier(void* pv)
{
 current_carrier_deque_->push_back( csr_->gen_carrier_by_type_object(current_type_object_, pv) );
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

