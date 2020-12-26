
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "qh-package/qh-bundle-code.h"

#include "qh-package/qh-pack-builder.h"
#include "qh-package/qh-pack-reader.h"


#include <QDebug>

int main(int argc, char* argv[])
{
 Qh_Bundle_Code qbc;

 qbc.add_u2();
 qbc.add_u1();

 Qh_Pack_Builder qpb(qbc);

 qpb.add_structure_value(QVariant::fromValue(77));
 qpb.add_structure_value(QVariant::fromValue(78));

 Qh_Pack_Reader qpr(qbc, qpb.data());

 QVariant qvar1 = qpr.read_value();
 QVariant qvar2 = qpr.read_value();

 u1 uu1 = qvar1.toUInt();
 u2 uu2 = qvar2.toUInt();


 qDebug() << "uu1 = " << uu1;
 qDebug() << "uu2 = " << uu2;


// qbc.each([](u1 code, Qh_Bundle_Code::Type_Hints th, u2 c)
// {
//  qDebug() << "code = " << '(' << Qh_Bundle_Code::get_type_hint_string(th) << ") " << code;
//  return c;
// });

 return 0;
}

