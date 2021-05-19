
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

void Chasm_Procedure_Table::register_procedure_s0(QString name,
  _minimal_fn_s0_type fn, QString proc)
{
 n8 nn = proc.mid(1).toULongLong();
 Chasm_Function_Code fncode = _cfc(nn);
 procedure_name_resolutions_[name] = name + proc;
 registered_procedures_[name + proc] = {fncode, {.s0 = fn}};

}
