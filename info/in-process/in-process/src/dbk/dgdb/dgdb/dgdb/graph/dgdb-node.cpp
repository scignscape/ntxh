
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgdb-node.h"

USING_KANS(DGDB)

DgDb_Node::DgDb_Node(void* vertex)
  :  vertex_(vertex), xnode_(nullptr),
     stage_value_(nullptr), wg_record_(nullptr),
     dgdb_type_(nullptr)
{

}


