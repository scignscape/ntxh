
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-annotation.h"



DHAX_Annotation::DHAX_Annotation()
{

}

void DHAX_Annotation::locations_to_qpoints(QVector<QPoint>& result)
{
 for(n8 nn : locations_)
 {
  DHAX_Location_2d* loc = (DHAX_Location_2d*) nn;
  QPoint qp = loc->to_qpoint();
  result.push_back(qp);
 }
}


void DHAX_Annotation::absorb_shape_point(const QPoint& qp)
{
 DHAX_Location_2d* loc = new DHAX_Location_2d(qp.x(), qp.y());
 locations_.push_back( (n8) loc );
}

