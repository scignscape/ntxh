
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef QH_NODE_DATA__H
#define QH_NODE_DATA__H

#include <QByteArray>

#include <QVariant>

#include <functional>

#include "global-types.h"


//class Qh_Bundle_Code;


#include "qh-bundle-code.h"

class Qh_Node_Data
{
 QVector<u1> data_;

 QVector<QPair<u4, u4>> offsets_;

public:

 Qh_Node_Data();

 QPair<u4, u4> add_str(const QString& str);

 QString read_str(u4 start, u4 end);

 QPair<u4, u4> add_pointer(void* ptr);

 void* read_pointer(u4 start, u4 end);

 u4 check_resize(u4 start, u4 amount);

};


#endif // QH_NODE_DATA__H


