
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "qh-pack-builder.h"

#include "qh-bundle-code.h"

#include "qh-node-data.h"

#include "qh-hypernode.h"


Qh_Pack_Builder::Qh_Pack_Builder(Qh_Bundle_Code& bundle_code)
  :  bundle_code_(bundle_code), current_bit_index_(0),
     current_byte_index_(0), current_array_value_index_(0),
     current_structure_value_index_(0),
     declared_structure_value_boundary_(0),
     current_structure_value_boundary_(0),
     node_data_(nullptr),
     current_node_data_byte_index_(0),
     current_node_data_field_index_(0)
{

}


Qh_Hypernode* Qh_Pack_Builder::as_hypernode()
{
 Qh_Hypernode* result = new Qh_Hypernode(data_, node_data_);
 return result;
}


void Qh_Pack_Builder::check_resize(u2 bytes_req)
{
 u4 end = current_byte_index_ + bytes_req;
 if(data_.size() < (s4) end)
   data_.resize(end);
}


void Qh_Pack_Builder::add_structure_or_array_value(QVariant qvar, u1 bytes_req, Qh_Bundle_Code::Type_Hints th)
{
 check_resize(bytes_req);

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
  data_[current_byte_index_] = (u1) (nn >> 8);
  data_[current_byte_index_ + 1] = (u1) (nn & 255);
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

void Qh_Pack_Builder::init_node_data()
{
 node_data_ = new Qh_Node_Data;
}


void Qh_Pack_Builder::add_structure_or_array_value_str(QString str, u1 bytes_req)
{
 if(bytes_req == 0)
 {
  check_resize(8);

  QPair<u4, u4> pr = node_data_->add_str(str);
  data_[current_byte_index_] = (u1) (pr.first >> 24);
  data_[current_byte_index_ + 1] = (u1) ((pr.first >> 16) & 255);
  data_[current_byte_index_ + 2] = (u1) ((pr.first >> 8) & 255);
  data_[current_byte_index_ + 3] = (u1) (pr.first & 255);

  data_[current_byte_index_ + 4] = (u1) (pr.second >> 24);
  data_[current_byte_index_ + 5] = (u1) ((pr.second >> 16) & 255);
  data_[current_byte_index_ + 6] = (u1) ((pr.second >> 8) & 255);
  data_[current_byte_index_ + 7] = (u1) (pr.second & 255);
 }
}

void Qh_Pack_Builder::add_structure_or_array_value(QVariant qvar,
  QPair<u1, Qh_Bundle_Code::Type_Hints> pr)
{
 switch (pr.second)
 {
 case Qh_Bundle_Code::Type_Hints::Chars_QString:
  add_structure_or_array_value_str(qvar.toString(), pr.first);
  break;
 case Qh_Bundle_Code::Type_Hints::Signed:
 case Qh_Bundle_Code::Type_Hints::Unsigned:
  add_structure_or_array_value(qvar, pr.first, pr.second);
  break;
 }
}


u2 Qh_Pack_Builder::add_structure_value(QVariant qvar)
{
 ++current_structure_value_index_;
 QPair<u1, Qh_Bundle_Code::Type_Hints> pr = bundle_code_.get_requirements(current_structure_value_index_);
 add_structure_or_array_value(qvar, pr);
 return current_structure_value_index_;
}


u2 Qh_Pack_Builder::add_array_value(QVariant qvar)
{
 if(current_array_value_index_ == 0)
   current_structure_value_boundary_ = current_byte_index_;
 ++current_array_value_index_;
 QPair<u1, Qh_Bundle_Code::Type_Hints> pr = bundle_code_.get_requirements(0);
 add_structure_or_array_value(qvar, pr);
 return current_array_value_index_;
}

