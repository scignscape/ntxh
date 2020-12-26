
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "qh-pack-reader.h"


Qh_Pack_Reader::Qh_Pack_Reader(Qh_Bundle_Code& bundle_code, const QVector<u1>& data)
  :  bundle_code_(bundle_code), data_(data),
     current_index_(0), current_byte_index_(0)
{

}

QVariant Qh_Pack_Reader::read_value()
{
 QPair<u1, Qh_Bundle_Code::Type_Hints> pr = bundle_code_.get_requirements(current_index_);

 ++current_index_;
 u4 cbi = current_byte_index_;
 current_byte_index_ += pr.first;

 switch (pr.second)
 {
 case Qh_Bundle_Code::Type_Hints::Unsigned:
  {
   switch(pr.first)
   {
   case 1: return QVariant::fromValue( (u1) data_[cbi] );
   case 2: return QVariant::fromValue( (u2) (
     (data_[cbi] << 8) |
     (data_[cbi + 1])
     ));
   }
  }
 }


}


