
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-annotation-instance.h"



DHAX_Annotation_Instance::DHAX_Annotation_Instance()
{

}

void DHAX_Annotation_Instance::locations_to_qpoints(QVector<QPoint>& result)
{
 for(n8 nn : locations_)
 {
  DHAX_Location_2d* loc = (DHAX_Location_2d*) nn;
  QPoint qp = loc->to_qpoint();
  result.push_back(qp);
 }
}

void DHAX_Annotation_Instance::set_byte_lengths
  (Byte_Lengths byte_lengths)
{

}

DHAX_Annotation_Instance::Byte_Lengths
  DHAX_Annotation_Instance::get_byte_lengths() const
{

}


void DHAX_Annotation_Instance::set_dimension_units
  (Dimension_Units dimension_units)
{

}

DHAX_Annotation_Instance::Dimension_Units
  DHAX_Annotation_Instance::get_dimension_units()  const
{

}

void DHAX_Annotation_Instance::set_dimension_scale
  (Dimension_Scale dimension_scale)
{

}

DHAX_Annotation_Instance::Dimension_Scale
  DHAX_Annotation_Instance::get_dimension_scale()  const
{

}

//ACCESSORS__DECLARE(Byte_Lengths ,byte_lengths)
//ACCESSORS__DECLARE(Dimension_Units ,dimension_units)
//ACCESSORS__DECLARE(Dimension_Scale ,dimension_scale)


void DHAX_Annotation_Instance::absorb_shape_point(const QPoint& qp)
{
 DHAX_Location_2d* loc = new DHAX_Location_2d(qp.x(), qp.y());
 locations_.push_back( (n8) loc );
}

