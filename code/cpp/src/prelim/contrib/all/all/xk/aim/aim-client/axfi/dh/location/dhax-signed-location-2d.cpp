
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-signed-location-2d.h"

#include <QDebug>


DHAX_Signed_Location_2d::DHAX_Signed_Location_2d(s4 c1, s4 c2)
 :  c1_(c1), c2_(c2)
{

}


n8 DHAX_Signed_Location_2d::encode8()
{
 return ( (n8) c1_ << 32) | c2_;
}


void DHAX_Signed_Location_2d::decode8(n8 compressed)
{
 c2_ = (s4) (compressed & 0x0000'0000'FFFF'FFFF);
 c1_ = (s4) (compressed >> 32);
}

void DHAX_Signed_Location_2d::check_decode8(n8 compressed)
{
 DHAX_Signed_Location_2d temp(0,0);
 temp.decode8(compressed);
 if(c1_ == temp.c1_ && c2_ == temp.c2_)
   qDebug() << "Decoded: OK";
 else
   qDebug() << "Decoded: Error";
}

QString DHAX_Signed_Location_2d::to_string()
{
 return QString("%1;%2").arg(c1_).arg(c2_);
}

QPoint DHAX_Signed_Location_2d::to_qpoint()
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
