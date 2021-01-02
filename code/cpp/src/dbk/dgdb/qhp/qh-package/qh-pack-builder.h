
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

class Qh_Node_Data;
class Qh_Hypernode;

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

 Qh_Node_Data* node_data_;
 u4 current_node_data_byte_index_;
 u4 current_node_data_field_index_;

public:

 Qh_Pack_Builder(Qh_Bundle_Code& bundle_code);

 ACCESSORS__CONST_RGET(QVector<u1> ,data)
 ACCESSORS(Qh_Node_Data* ,node_data)

 Qh_Hypernode* as_hypernode();

 u2 add_structure_value(QVariant qvar);
 u2 add_array_value(QVariant qvar);

 void add_structure_or_array_value(QVariant qvar,
   QPair<u1, Qh_Bundle_Code::Type_Hints> pr);


 void add_structure_or_array_value(QVariant qvar, u1 bytes_req, Qh_Bundle_Code::Type_Hints th);
 void add_structure_or_array_value_str(QString str, u1 bytes_req);

 void init_node_data();

 void check_resize(u2 bytes_req);

};


#endif // QH_PACK_BUILDER__H


