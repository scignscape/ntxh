
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DW_DOMINION__H
#define DW_DOMINION__H

#include <QString>

#include <QMap>

#include "accessors.h"

#include "global-types.h"

#include "kans.h"

#include "flags.h"


KANS_(DGDB)

class DW_Instance;


class DW_Dominion
{
 QStringList connectors_;

public:


 ACCESSORS__RGET(QStringList ,connectors)

 DW_Dominion();


};

_KANS(DGDB)


#endif // DW_DOMINION__H


