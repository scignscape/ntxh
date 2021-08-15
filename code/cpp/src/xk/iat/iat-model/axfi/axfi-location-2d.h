
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef AXFI_LOCATION_2D__H
#define AXFI_LOCATION_2D__H

#include <QString>
#include <QPoint>


#include "accessors.h"
#include "flags.h"

#include "global-types.h"

#include <functional>

#include "kans.h"


//KANS_(GTagML)


class AXFI_Location_2d
{
 n8 c1_;
 n8 c2_;

public:

 AXFI_Location_2d(n8 c1, n8 c2);

 ACCESSORS(n8 ,c1)
 ACCESSORS(n8 ,c2)

 QString to_string();

 QPoint to_qpoint();

 static void read_string(QString str, QVector<n8>& locations);

};

// _KANS(GTagML)


#endif  //  AXFI_LOCATION_2D__H
