
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-location-2d.h"


DHAX_Location_2d::DHAX_Location_2d(n8 c1, n8 c2)
 :  c1_(c1), c2_(c2)
{

}

QString DHAX_Location_2d::to_string()
{
 return QString("%1;%2").arg(c1_).arg(c2_);
}

QPoint DHAX_Location_2d::to_qpoint()
{
 return { (int) c1_, (int) c2_ };
}

//void DHAX_Location_2d::read_string(QString str, QVector<n8>& locations)
//{
// QStringList parts = str.split(":");
// for(QString part : parts)
// {
//  QStringList subparts = part.split(";");
//  if(subparts.size() < 2)
//    continue; // malformed ...

//  DHAX_Location_2d* loc = new DHAX_Location_2d(subparts[0].toInt(), subparts[1].toInt());

//  locations.push_back((n8) loc);
// }
//}

