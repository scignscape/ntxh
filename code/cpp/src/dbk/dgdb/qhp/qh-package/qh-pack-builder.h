
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef QH_PACK_BUILDER__H
#define QH_PACK_BUILDER__H

#include <QByteArray>

#include <QVariant>

#include <functional>

#include "global-types.h"

#include "accessors.h"

//class Qh_Bundle_Code;


#include "qh-bundle-code.h"

class Qh_Pack_Builder
{
 Qh_Bundle_Code& bundle_code_;

 u1 current_bit_index_;
 u4 current_byte_index_;
 u4 current_array_value_index_;
 u2 current_structure_value_index_;
 u2 declared_structure_value_boundary_;
 u2 current_structure_value_boundary_;

 QVector<u1> data_;

public:

 Qh_Pack_Builder(Qh_Bundle_Code& bundle_code);

 ACCESSORS__CONST_RGET(QVector<u1> ,data)

 u2 add_structure_value(QVariant qvar);

 void add_structure_value(QVariant qvar, u1 bytes_req, Qh_Bundle_Code::Type_Hints th);


};


#endif // QH_PACK_BUILDER__H


