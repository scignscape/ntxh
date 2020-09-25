
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef AXFD_STRING_NODE__H
#define AXFD_STRING_NODE__H

#include "accessors.h"

#include "global-types.h"

#include "flags.h"

#include "kans.h"

#include <QString>
#include <QList>
#include <QDate>

#include <functional>

#include "global-types.h"


class QTextStream;

KANS_(AXFD)

class AXFD_Tile_Scope;

class AXFD_String_Node 
{
 void* string_or_layer_;
 u4 enter_;
 u4 leave_;

 AXFD_String_Node(QString str);
 AXFD_String_Node(void* pv = nullptr);

 static AXFD_String_Node _from_range(void* pv, u4 enter, u4 leave);

public:

 ACCESSORS(u4 ,enter)
 ACCESSORS(u4 ,leave)

 QString* get_qstring();

 static AXFD_String_Node from_string(QString str);

 static AXFD_String_Node from_range(u4 enter, u4 leave);

 template<typename T>
 static AXFD_String_Node from_range(T* layer, u4 enter, u4 leave)
 {
  return _from_range(layer, enter, leave);
 }
 
 template<typename T>
 T* get_layer()
 {
  if(enter_ == 0)
    return nullptr;
  return (T*) string_or_layer_;
 }

};


_KANS(HTXN)

#endif // AXFD_STRING_NODE__H


