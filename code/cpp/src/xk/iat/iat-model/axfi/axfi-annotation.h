
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef AXFI_ANNOTATION__H
#define AXFI_ANNOTATION__H

#include <QString>
#include <QPoint>
#include <QVector>


#include "accessors.h"
#include "flags.h"

#include "global-types.h"

#include "axfi-location-2d.h"

#include <functional>

#include "kans.h"


//KANS_(GTagML)


class AXFI_Annotation
{
 QStringList scoped_identifiers_;

 QString shape_designation_;

 QVector<n8> locations_;


public:

 AXFI_Annotation();

 ACCESSORS(QString ,shape_designation)
 ACCESSORS__RGET(QStringList ,scoped_identifiers)


 void read_iat_string(QString line);

 void from_compact_string(QString cs);

 void add_scoped_identifier(QString si);

 void absorb_shape_point(const QPoint& qp);

 QString to_compact_string();

 void locations_to_qpoints(QVector<QPoint>& result);

};

// _KANS(GTagML)


#endif  //  AXFI_ANNOTATION__H
