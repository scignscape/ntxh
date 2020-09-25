
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef AXFD_ZNODE__H
#define AXFD_ZNODE__H

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

class AXFD_RNode;

class AXFD_ZNode  
{ 
 union {
   QPair<u4, u4> index_;
   AXFD_RNode* rnode_;
 };


};


_KANS(AXFD)

#endif // AXFD_ZNODE__H


