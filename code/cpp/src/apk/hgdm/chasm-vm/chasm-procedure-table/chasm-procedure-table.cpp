
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "chasm-procedure-table.h"

#include "chasm/chasm-runtime.h"
#include "chasm/chasm-call-package.h"


#include <QString>
#include <QVariant>
#include <QByteArray>

#include <QUrl>

#include <QPoint>

#include <QRegularExpression>


Chasm_Procedure_Table::Chasm_Procedure_Table(Chasm_Runtime* csr)
{
 const QVector<Chasm_Type_Object*>& pto = *csr->pretype_type_objects();

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


QString read_fncode(QString& code, QString& lead)
{
 QString result = code;

 QRegularExpression rx("^(\\D+)(0*)");

 QRegularExpressionMatch rxm = rx.match(result);
 if(rxm.hasMatch())
 {
  lead = rxm.captured(1);
  result = code.mid(rxm.capturedEnd());
  if(!rxm.captured(2).isEmpty())
  {
   code = lead + result;
  }
 }
 return result;
}

void Chasm_Procedure_Table::register_procedure_s1(QString name,
  _minimal_fn_s1_type sfn, QString code)
{
 QString lead;
 QString fc = read_fncode(code, lead);
 n8 nn = fc.toULongLong();
 Chasm_Function_Code fncode = _cfc(nn);
 procedure_name_resolutions_[name] = name + code;
 registered_procedures_[name + code] = {fncode, _minimal_fn_type {.s1 = sfn}};
}


void Chasm_Procedure_Table::register_procedure_s0(QString name,
  _minimal_fn_s0_type fn, QString code)
{
 QString lead;
 QString fc = read_fncode(code, lead);
 n8 nn = fc.toULongLong();
 Chasm_Function_Code fncode = _cfc(nn);
 procedure_name_resolutions_[name] = name + code;
 registered_procedures_[name + code] = {fncode, {.s0 = fn}};
}

Chasm_Function_Code Chasm_Procedure_Table::find_procedure(QString name,
  _minimal_fn_s0_type& s0, _minimal_fn_s1_type& s1)
{
 {
  auto it = procedure_name_resolutions_.find(name);
  if(it != procedure_name_resolutions_.end())
    name = *it;
 }
 auto it = registered_procedures_.find(name);
 if(it == registered_procedures_.end())
   return Chasm_Function_Code::_invalid();
 const QPair<Chasm_Function_Code, _minimal_fn_type>& pr = *it;
 if(pr.first.convention == 0)
   s0 = pr.second.s0;
 else
   s1 = pr.second.s1;
 return pr.first;
}

