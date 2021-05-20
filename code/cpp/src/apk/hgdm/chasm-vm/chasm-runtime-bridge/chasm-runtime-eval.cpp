
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "chasm-runtime-eval.h"

#include "chasm/chasm-runtime.h"
#include "chasm/chasm-call-package.h"

#include "chasm-procedure-table/chasm-procedure-table.h"

#include "csm-ghost-scope.h"

#include <QString>
#include <QVariant>
#include <QByteArray>

#include <QUrl>

#include <QPoint>

#include <QRegularExpression>


Chasm_Runtime_Eval::Chasm_Runtime_Eval(Chasm_Runtime* csr)
  :  csr_(csr), proctable_(nullptr)
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


Chasm_Carrier Chasm_Runtime_Eval::call_s0(QString name, QString args_rep)
{
 return call_s0(name, args_rep, "retvalue");
}


Chasm_Carrier Chasm_Runtime_Eval::call_s0(QString name, QString args_rep, QString ret_channel_name)
{
 _minimal_fn_s0_type fn = nullptr;
 _minimal_fn_s1_type sfn = nullptr;

 Chasm_Function_Code cfc = proctable_->find_procedure(name, fn, sfn);

 if(cfc.invalid())
   return {};

 Chasm_Call_Package* ccp = csr_->new_call_package();

 if(cfc.arg_count > 0)
 {
  ccp->add_new_channel("lambda");
  QStringList qsl = args_rep.split(';');
  u1 current_pretype = 0;
  for(u1 u = 0; u < cfc.arg_count; ++u)
  {
   QString rep = qsl.value(u);
   QRegularExpression rx("^(\\d+)/");
   QRegularExpressionMatch rxm = rx.match(rep);
   if(rxm.hasMatch())
   {
    current_pretype = rxm.captured(1).toInt();
    rep = rep.mid(rxm.capturedEnd());
   }
   Chasm_Carrier cc = csr_->gen_carrier(current_pretype, rep);
   ccp->add_carrier(cc);
  }
 }


 ccp->add_new_channel(ret_channel_name);
 Chasm_Carrier rcc = csr_->gen_carrier(cfc.return_code);
 ccp->add_carrier(rcc);

 if(fn)
 {
  csr_->evaluate(ccp, cfc, fn, &rcc);
 }

 return rcc;
}


Chasm_Carrier Chasm_Runtime_Eval::call_s1(void* obj, QString name)
{
 _minimal_fn_s0_type fn = nullptr;
 _minimal_fn_s1_type sfn = nullptr;

 Chasm_Function_Code cfc = proctable_->find_procedure(name, fn, sfn);

 if(cfc.invalid())
   return {};
 //csr

 Chasm_Call_Package* ccp = csr_->new_call_package();
 ccp->add_new_channel("sigma");
 Chasm_Carrier scc = csr_->gen_carrier(9).take_value(&obj);
 ccp->add_carrier(scc);

 ccp->add_new_channel("retvalue");
 Chasm_Carrier rcc = csr_->gen_carrier(cfc.return_code);
 ccp->add_carrier(rcc);

 if(sfn)
 {
  csr_->evaluate(ccp, cfc, sfn, &rcc);
 }

 return rcc;
}
