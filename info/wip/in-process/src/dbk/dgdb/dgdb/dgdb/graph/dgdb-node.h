
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef DGDB_NODE__H
#define DGDB_NODE__H

#include "accessors.h"

#include "kans.h"

KANS_(DGDB)

class DgDb_Type;
class WG_Stage_Value;

class DgDb_Node
{
 void* vertex_;
 void* xnode_;
 WG_Stage_Value* stage_value_;
 void* wg_record_;

 DgDb_Type* dgdb_type_;

public:

 ACCESSORS(void* ,vertex)
 ACCESSORS(void* ,xnode)
 ACCESSORS(WG_Stage_Value* ,stage_value)
 ACCESSORS(void* ,wg_record)
 ACCESSORS(DgDb_Type* ,dgdb_type)

 DgDb_Node(void* vertex);

};


_KANS(DGDB)

#endif // DGDB_NODE__H


