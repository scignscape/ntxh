
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef AXFD_RNODE__H
#define AXFD_RNODE__H

#include "accessors.h"

#include "global-types.h"

#include "flags.h"

#include "kans.h"

#include <QString>
#include <QVector>
#include <QPair>

#include <functional>

#include "global-types.h"
#include "accessors.h"


#include "axfd-string-node.h"


class QTextStream;

KANS_(AXFD)

class AXFD_Tile_Scope;

class AXFD_RNode : public QVector<QPair<QString, AXFD_Tile_Scope*>>
{ 
 AXFD_String_Node tag_command_name_;
  
 AXFD_RNode(QString tag_command_name);
 //AXFD_RNode();

 ACCESSORS__RGET(AXFD_String_Node ,tag_command_name)

};


_KANS(AXFD)

#endif // AXFD_RNODE__H


