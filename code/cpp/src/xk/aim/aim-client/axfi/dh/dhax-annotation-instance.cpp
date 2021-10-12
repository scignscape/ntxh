
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-annotation-instance.h"

#include "location/dhax-location-2d.h"
#include "location/dhax-signed-location-2d.h"
#include "location/dhax-float-location-2d.h"
#include "location/dhax-double-location-2d.h"

#include <QDebug>

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

void DHAX_Annotation_Instance::default_dimensions()
{
 static u1 code = 0;
 if(code)
   composite_dimension_code_ = code;
 else
 {
  // //  init for this object and keep the result for others
  set_dimension_units(Dimension_Units::Px);
  set_dimension_scale(Dimension_Scale::Integer);
  set_byte_lengths(Byte_Lengths::Four);
  code = composite_dimension_code_;
 }
}


bool DHAX_Annotation_Instance::is_signed()
{
 return composite_dimension_code_ & 128; // high bit ...
}

void DHAX_Annotation_Instance::note_signed()
{
 composite_dimension_code_ |= 128;
}

void DHAX_Annotation_Instance::set_byte_lengths
  (Byte_Lengths byte_lengths)
{
 composite_dimension_code_ &= 0b1111'0011;
 composite_dimension_code_ |= ((u1) byte_lengths << 3);
}

DHAX_Annotation_Instance::Byte_Lengths
  DHAX_Annotation_Instance::get_byte_lengths() const
{
 return (Byte_Lengths) ((composite_dimension_code_ >> 3) & 3);
}


void DHAX_Annotation_Instance::set_dimension_units
  (Dimension_Units dimension_units)
{
 composite_dimension_code_ &= 0b1000'1111;
 composite_dimension_code_ |= ((u1) dimension_units << 5);
}

DHAX_Annotation_Instance::Dimension_Units
  DHAX_Annotation_Instance::get_dimension_units()  const
{
 return (Dimension_Units) ((composite_dimension_code_ >> 5) & 7);
}

void DHAX_Annotation_Instance::set_dimension_scale
  (Dimension_Scale dimension_scale)
{
 composite_dimension_code_ &= 0b1111'1100;
 composite_dimension_code_ |= (u1) dimension_scale;
}

DHAX_Annotation_Instance::Dimension_Scale
  DHAX_Annotation_Instance::get_dimension_scale()  const
{
 return (Dimension_Scale) (composite_dimension_code_ & 3);
}

//ACCESSORS__DECLARE(Byte_Lengths ,byte_lengths)
//ACCESSORS__DECLARE(Dimension_Units ,dimension_units)
//ACCESSORS__DECLARE(Dimension_Scale ,dimension_scale)


//void DHAX_Annotation_Instance::absorb_shape_point(const QPoint& qp)
//{
// DHAX_Location_2d* loc = new DHAX_Location_2d(qp.x(), qp.y());
// locations_.push_back( (n8) loc );
//}

void DHAX_Annotation_Instance::add_shape_point(u4 c1, u4 c2)
{
 DHAX_Location_2d* loc = new DHAX_Location_2d(c1, c2);
 locations_.push_back( (n8) loc );
}

void DHAX_Annotation_Instance::add_shape_point(s4 c1, s4 c2)
{
 // // note: this is not intended for signed arguments
  //   (unlike "add_signed_shape_point")
  //   but rather for unsigned literals that are
  //   interpreted as signed integers.
  //   In this scenario we know they are within proper bounds ...
 add_shape_point((u4) c1, (u4) c2);
}


void DHAX_Annotation_Instance::add_signed_shape_point(s4 c1, s4 c2)
{
 n8 location;
 if(is_signed())
 {
  DHAX_Signed_Location_2d* loc = new DHAX_Signed_Location_2d(c1, c2);
  location = (n8) loc;
 }
 else if(get_dimension_scale() == Dimension_Scale::Float)
 {
  if(get_byte_lengths() == Byte_Lengths::Four)
  {
   DHAX_Float_Location_2d* loc = new DHAX_Float_Location_2d(c1, c2);
   location = (n8) loc;
  }
  else
  {
   DHAX_Double_Location_2d* loc = new DHAX_Double_Location_2d(c1, c2);
   location = (n8) loc;
  }
 }
 else // //  todo: currently ignoring ratios ...
 {
  if( (c1 < 0) || (c2 < 0) )
    qDebug() << "Warning: signed integers passed to anntoation expecting unsigned ...";
  DHAX_Location_2d* loc = new DHAX_Location_2d((u4)c1, (u4)c2);
  location = (n8) loc;
 }
 locations_.push_back(location);
}

void DHAX_Annotation_Instance::add_shape_point(double c1, double c2)
{
 n8 location;
 if(get_byte_lengths() == Byte_Lengths::Four)
 {
  if(get_dimension_scale() == Dimension_Scale::Float)
  {
   qDebug() << "Warning: double-precision values passed to anntoation expecting single-precision floats ...";
   DHAX_Float_Location_2d* loc = new DHAX_Float_Location_2d( (float) c1, (float) c2);
   location = (n8) loc;
  }
  else if(is_signed())
  {
   qDebug() << "Warning: double-precision values truncated to 4-byte signed integer for anntoation ...";
   DHAX_Signed_Location_2d* loc = new DHAX_Signed_Location_2d( (s4) c1, (s4) c2);
   location = (n8) loc;
  }
  else
  {
   qDebug() << "Warning: double-precision values truncated to 4-byte unsigned integer for anntoation ...";
   DHAX_Location_2d* loc = new DHAX_Location_2d( (u4) c1, (u4) c2);
   location = (n8) loc;
  }
 }
 else // //  todo: ignoring shorts and ratios for now ...
 {
  if(get_dimension_scale() == Dimension_Scale::Float)
  {
   DHAX_Double_Location_2d* loc = new DHAX_Double_Location_2d(c1, c2);
   location = (n8) loc;
  }
  else
  {
   qDebug() << "Use of double incompatible with annotation format.";
  }
 }
}


void DHAX_Annotation_Instance::add_shape_point(float c1, float c2)
{
 n8 location;

 if(get_dimension_scale() == Dimension_Scale::Float)
 {
  if(get_byte_lengths() == Byte_Lengths::Four)
  {
   DHAX_Float_Location_2d* loc = new DHAX_Float_Location_2d(c1, c2);
   location = (n8) loc;
  }
  else if(get_byte_lengths() == Byte_Lengths::Eight)
  {
   DHAX_Double_Location_2d* loc = new DHAX_Double_Location_2d(c1, c2);
   location = (n8) loc;
  }
  else // //  todo maybe convert for a ratio or half-precision?
  {
   qDebug() << "Use of double incompatible with annotation format.";
  }
 }
 else if(get_byte_lengths() == Byte_Lengths::Four)
 {
  if(is_signed())
  {
   qDebug() << "Warning: floating-point values converted to 4-byte signed integer for anntoation ...";
   DHAX_Signed_Location_2d* loc = new DHAX_Signed_Location_2d( (s4) c1, (s4) c2);
   location = (n8) loc;
  }
  else
  {
   qDebug() << "Warning: floating-point values converted to 4-byte unsigned integer for anntoation ...";
   DHAX_Location_2d* loc = new DHAX_Location_2d( (u4) c1, (u4) c2);
   location = (n8) loc;
  }
 }
 else // //  todo: ignoring shorts and ratios for now ...
 {
  qDebug() << "Use of float incompatible with annotation format.";
 }
}

