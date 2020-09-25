
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef DGDB_FRAME__H
#define DGDB_FRAME__H

#include <QVector>

#include "accessors.h"

#include "kans.h"

KANS_(DGDB)

class DgDb_Node;

class DgDb_Frame : public QVector<DgDb_Node*> 
{
 DgDb_Frame* parent_frame_;

public:

 DgDb_Frame(DgDb_Frame* parent_frame = nullptr);

 ACCESSORS(DgDb_Frame* ,parent_frame)

 virtual void add(DgDb_Node* node)
 {
  push_back(node);
 }

};


_KANS(DGDB)

#endif // DGDB_FRAME__H


