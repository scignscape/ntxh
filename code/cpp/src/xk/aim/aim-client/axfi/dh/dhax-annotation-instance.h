
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_ANNOTATION_INSTANCE__H
#define DHAX_ANNOTATION_INSTANCE__H

#include <QString>
#include <QPoint>
#include <QVector>


#include "accessors.h"
#include "flags.h"

#include "global-types.h"

#include "dhax-location-2d.h"

#include <functional>

#include "kans.h"


//KANS_(GTagML)

class DHAX_Annotation_Group;

class DHAX_Annotation_Instance
{
 QVector<n8> locations_;

 DHAX_Annotation_Group* group_;
 QString comment_;

 u1 composite_dimension_code_;

public:

 DHAX_Annotation_Instance();

// ACCESSORS(QString ,shape_designation)
// ACCESSORS__RGET(QStringList ,scoped_identifiers)
// ACCESSORS(n8 ,opaque_shape_kind_code)
// ACCESSORS(QString ,comment)

 ACCESSORS(DHAX_Annotation_Group* ,group)
 ACCESSORS(QString ,comment)


 enum class Dimension_Scale {
   N_A, Integer, Float, Ratio
 };

 enum class Dimension_Units {
   N_A, Px, Pc, In, Pt, Cm, Mm
 };

 enum class Byte_Lengths {
   Other, Two, Four, Eight
 };

 ACCESSORS__GSDECLARE(Byte_Lengths ,byte_lengths)
 ACCESSORS__GSDECLARE(Dimension_Units ,dimension_units)
 ACCESSORS__GSDECLARE(Dimension_Scale ,dimension_scale)


 void absorb_shape_point(const QPoint& qp);
 QString to_compact_string();
 void locations_to_qpoints(QVector<QPoint>& result);

};

// _KANS(GTagML)


#endif  //  DHAX_ANNOTATION_INSTANCE__H
