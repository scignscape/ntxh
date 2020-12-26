
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "qh-pack-builder.h"

#include "qh-bundle-code.h"


Qh_Pack_Builder::Qh_Pack_Builder(Qh_Bundle_Code& bundle_code)
  :  bundle_code_(bundle_code), current_bit_index_(0),
     current_byte_index_(0), current_array_value_index_(0),
     current_structure_value_index_(0),
     declared_structure_value_boundary_(0),
     current_structure_value_boundary_(0)
{

}


void Qh_Pack_Builder::add_structure_value(QVariant qvar, u1 bytes_req, Qh_Bundle_Code::Type_Hints th)
{
 u4 end = current_byte_index_ + bytes_req;
 if(data_.size() < (s4) end)
   data_.resize(end);

 n8 nn = 0;


 if(th == Qh_Bundle_Code::Type_Hints::Unsigned)
 {
  if(bytes_req == 8)
    nn = qvar.toULongLong();
  else
    nn = qvar.toUInt();
 }
 else if(th == Qh_Bundle_Code::Type_Hints::Unsigned)
 {
  if(bytes_req == 8)
    nn = qvar.toLongLong();
  else
    nn = qvar.toInt();
 }
 else if(th == Qh_Bundle_Code::Type_Hints::Real)
 {
  if(bytes_req == 8)
    nn = qvar.toDouble();
  else
    // // this version of the method should not be called
     //   with 1-2 byte reals ...
    nn = qvar.toFloat();
 }

 switch (bytes_req)
 {
 case 1: data_[current_byte_index_] = (u1) nn; break;
 case 2:
  data_[current_byte_index_] = (u1) (nn & 255);
  data_[current_byte_index_ + 1] = (u1) (nn >> 8);
  break;
 case 4:
  data_[current_byte_index_] = (u1) (nn >> 24);
  data_[current_byte_index_ + 1] = (u1) ((nn >> 16) & 255);
  data_[current_byte_index_ + 2] = (u1) ((nn >> 8) & 255);
  data_[current_byte_index_ + 3] = (u1) (nn & 255);
  break;
 case 8:
  data_[current_byte_index_] = (u1) (nn >> 56);
  data_[current_byte_index_ + 1] = (u1) ((nn >> 48) & 255);
  data_[current_byte_index_ + 2] = (u1) ((nn >> 40) & 255);
  data_[current_byte_index_ + 3] = (u1) ((nn >> 32) & 255);
  data_[current_byte_index_ + 4] = (u1) ((nn >> 24) & 255);
  data_[current_byte_index_ + 5] = (u1) ((nn >> 16) & 255);
  data_[current_byte_index_ + 6] = (u1) ((nn >> 8) & 255);
  data_[current_byte_index_ + 7] = (u1) (nn & 255);
  break;
 default: break;
 }

 current_byte_index_ += bytes_req;
}


u2 Qh_Pack_Builder::add_structure_value(QVariant qvar)
{
 ++current_structure_value_index_;
 QPair<u1, Qh_Bundle_Code::Type_Hints> pr = bundle_code_.get_requirements(current_structure_value_index_);

 switch (pr.second)
 {
// case Qh_Bundle_Code::

 case Qh_Bundle_Code::Type_Hints::Signed:
 case Qh_Bundle_Code::Type_Hints::Unsigned:
  add_structure_value(qvar, pr.first, pr.second);
  break;
 }

 return current_structure_value_index_;
}
