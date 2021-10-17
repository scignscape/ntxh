
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

#include "location/dhax-location-2d.h"

#include <functional>

#include "kans.h"


//KANS_(GTagML)

class DHAX_Annotation_Group;

class DHAX_Annotation_Instance
{
 QVector<n8> locations_;

 DHAX_Annotation_Group* group_;
 QString comment_;

 u2 composite_dimension_code_;

 u1 composite_shape_code_;

 union {
  QVector<u4>* int4;
  QVector<n8>* int8;
  QVector<float>* fl4;
  QVector<double>* dbl8;
  n8 single;
 } shape_lengths_;

public:

 DHAX_Annotation_Instance();

 ACCESSORS(QVector<n8> ,locations)

// ACCESSORS__RGET(QStringList ,scoped_identifiers)
// ACCESSORS(n8 ,opaque_shape_kind_code)
// ACCESSORS(QString ,comment)

 ACCESSORS(DHAX_Annotation_Group* ,group)
 ACCESSORS(QString ,comment)


 enum class Dimension_Scale {
   Integer, Float, Ratio, Proper_Fraction
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

 ACCESSORS__GSDECLARE(Byte_Lengths ,shape_lengths_byte_lengths)
 ACCESSORS__GSDECLARE(Dimension_Units ,shape_lengths_dimension_units)
 ACCESSORS__GSDECLARE(Dimension_Scale ,shape_lengths_dimension_scale)

 bool is_signed();
 void note_signed();

 void default_dimensions();
 void reuse_dimensions_for_shape_lengths();

 bool single_shape_length();
 void note_single_shape_length();

 void init_shape_lengths();
 void check_init_shape_lengths();
 void set_shape_length(n8 len);
 void set_shape_length(double len);
 void set_shape_length(float len);

 void add_shape_point(s4 c1, s4 c2);
 void add_shape_point(u4 c1, u4 c2);
 void add_shape_point(double c1, double c2);
 void add_shape_point(float c1, float c2);

 void add_shape_length(n8 len);
 void add_shape_length(double len);
 void add_shape_length(float len);


 void add_signed_shape_point(s4 c1, s4 c2);

// void absorb_shape_point(const QPoint& qp);
 QString to_compact_string();
 void locations_to_qpoints(QVector<QPoint>& result);

};

// _KANS(GTagML)


#endif  //  DHAX_ANNOTATION_INSTANCE__H
