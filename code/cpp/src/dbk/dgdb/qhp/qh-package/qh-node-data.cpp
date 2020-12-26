
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "qh-node-data.h"


Qh_Node_Data::Qh_Node_Data()
{

}

QPair<u4, u4> Qh_Node_Data::add_str(const QString& str)
{
 u4 start = (u4) data_.size();
 u4 end = start + str.size() * 2;
 if(data_.size() < (s4) end)
   data_.resize(end);

 for(u4 uu = start, i = 0; uu < end; uu += 2, ++i)
 {
  QChar qc = str.at(i);
  u2 uni = qc.unicode();
  data_[uu] = uni >> 8;
  data_[uu + 1] = uni & 255;
 }

 return {start, end};
}

QString Qh_Node_Data::read_str(u4 start, u4 end)
{
 QString result((end - start) / 2, QChar{});

 for(u4 uu = start, i = 0; uu < end; uu += 2, ++i)
 {
  u2 uni = (((u2) data_[uu]) << 8) | data_[uu + 1];  // qc.unicode();
  result[(s4)i] = QChar(uni);
 }
 return result;
}
