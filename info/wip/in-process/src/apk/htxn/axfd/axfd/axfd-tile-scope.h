
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef AXFD_TILE_SCOPE__H
#define AXFD_TILE_SCOPE__H

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

class AXFD_Document;

struct AXFD_Tile_Code
{
 u4 enter;
 u4 leave;
}; 


class AXFD_Tile_Scope : public QVector<AXFD_Tile_Code>
{ 
public:

 AXFD_Tile_Scope();

 QString to_sieved_string(AXFD_Document& doc, 
   void* layer = nullptr);
};

_KANS(HTXN)

#endif // AXFD_TILE_SCOPE__H


