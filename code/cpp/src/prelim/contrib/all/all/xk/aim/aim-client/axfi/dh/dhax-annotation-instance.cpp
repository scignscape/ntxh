
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
  :  shape_lengths_({.int4=nullptr})
{

}

void DHAX_Annotation_Instance::check_init_shape_lengths()
{
 if(!shape_lengths_.int4)
   init_shape_lengths();
}

void DHAX_Annotation_Instance::init_shape_lengths()
{
 if(single_shape_length())
   return; // nothing to do ...

 if(get_shape_lengths_dimension_scale() == Dimension_Scale::Float)
 {
  if(get_shape_lengths_byte_lengths() == Byte_Lengths::Eight)
    shape_lengths_.dbl8 = new QVector<double>;
  else
    shape_lengths_.fl4 = new QVector<float>;
 }
 else
 {
  if(get_shape_lengths_byte_lengths() == Byte_Lengths::Eight)
    shape_lengths_.int8 = new QVector<n8>;
  else
    shape_lengths_.int4 = new QVector<u4>;
 }
}

void DHAX_Annotation_Instance::set_shape_length(double len)
{
 check_init_shape_lengths();
 if(get_shape_lengths_dimension_scale() == Dimension_Scale::Float)
 {
  if(get_shape_lengths_byte_lengths() == Byte_Lengths::Eight)
    *shape_lengths_.dbl8 = {len};
  else
    *shape_lengths_.fl4 = {(float)len};
 }
 else
 {
  qDebug() << "Warning: converting double to integer for shape length";
  if(get_shape_lengths_byte_lengths() == Byte_Lengths::Eight)
    *shape_lengths_.int8 = {(n8)len};
  else
    *shape_lengths_.int4 = {(u4)len};
 }
}

void DHAX_Annotation_Instance::set_shape_length(float len)
{
 // //  just reuse the double implementation; probably OK
 set_shape_length((double) len);
}


void DHAX_Annotation_Instance::set_shape_length(n8 len)
{
 if(!single_shape_length())
   qDebug() << "Warning: setting a single length for an annotation expecting a length vector";

 if(get_shape_lengths_byte_lengths() == Byte_Lengths::Eight)
   shape_lengths_.single = len;

 else
 {
  u4 len4 = len;
  if(len4 != len)
    qDebug() << "Warning: length truncated to fit 4 byte integer";
  shape_lengths_.single = len4;
 }
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
 static u2 code = 0;
 if(code)
   composite_dimension_code_ = code;
 else
 {
  // //  init for this object and keep the result for others
  set_dimension_units(Dimension_Units::Px);
  set_dimension_scale(Dimension_Scale::Integer);
  set_byte_lengths(Byte_Lengths::Four);
  reuse_dimensions_for_shape_lengths();
  code = composite_dimension_code_;
 }
}

void DHAX_Annotation_Instance::reuse_dimensions_for_shape_lengths()
{
 u2 composite = composite_dimension_code_ & 127; // ignore signed flag
 composite_dimension_code_ &= 0b1000'0000'1111'1111;
 composite_dimension_code_ |= (composite << 9);
}

bool DHAX_Annotation_Instance::single_shape_length()
{
 return composite_dimension_code_ & 0x8000; // high bit of second byte ...
}

void DHAX_Annotation_Instance::note_single_shape_length()
{
 composite_dimension_code_ |= 0x8000; // high bit of second byte ...
}


bool DHAX_Annotation_Instance::is_signed()
{
 return composite_dimension_code_ & 128; // high bit of first byte...
}

void DHAX_Annotation_Instance::note_signed()
{
 composite_dimension_code_ |= 128;
}

void DHAX_Annotation_Instance::set_byte_lengths
  (Byte_Lengths byte_lengths)
{
 composite_dimension_code_ &= 0b1111'1111'1111'0011;
 composite_dimension_code_ |= ((u1) byte_lengths << 3);
}

DHAX_Annotation_Instance::Byte_Lengths
  DHAX_Annotation_Instance::get_byte_lengths() const
{
 return (Byte_Lengths) ((composite_dimension_code_ >> 3) & 3);
}

void DHAX_Annotation_Instance::set_shape_lengths_byte_lengths
  (Byte_Lengths byte_lengths)
{
 composite_dimension_code_ &= 0b1111'0011'1111'1111;
 composite_dimension_code_ |= ((u2) byte_lengths << 11);
}

DHAX_Annotation_Instance::Byte_Lengths
  DHAX_Annotation_Instance::get_shape_lengths_byte_lengths() const
{
 return (Byte_Lengths) ((composite_dimension_code_ >> 11) & 3);
}


void DHAX_Annotation_Instance::set_dimension_units
  (Dimension_Units dimension_units)
{
 composite_dimension_code_ &= 0b1111'1111'1000'1111;
 composite_dimension_code_ |= ((u1) dimension_units << 5);
}

DHAX_Annotation_Instance::Dimension_Units
  DHAX_Annotation_Instance::get_dimension_units()  const
{
 return (Dimension_Units) ((composite_dimension_code_ >> 5) & 7);
}

void DHAX_Annotation_Instance::set_shape_lengths_dimension_units
  (Dimension_Units dimension_units)
{
 composite_dimension_code_ &= 0b1000'1111'1111'1111;
 composite_dimension_code_ |= ((u2) dimension_units << 13);
}

DHAX_Annotation_Instance::Dimension_Units
  DHAX_Annotation_Instance::get_shape_lengths_dimension_units()  const
{
 return (Dimension_Units) ((composite_dimension_code_ >> 13) & 7);
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


void DHAX_Annotation_Instance::set_shape_lengths_dimension_scale
  (Dimension_Scale dimension_scale)
{
 composite_dimension_code_ &= 0b1111'1100'1111'1111;
 composite_dimension_code_ |= ((u2) dimension_scale << 9);
}

DHAX_Annotation_Instance::Dimension_Scale
  DHAX_Annotation_Instance::get_shape_lengths_dimension_scale()  const
{
 return (Dimension_Scale) ((composite_dimension_code_ >> 9) & 3);
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


void DHAX_Annotation_Instance::add_shape_length(n8 len)
{
 if(single_shape_length())
 {
  qDebug() << "Warning: adding shape length to single length may overwrite old value";
  set_shape_length(len);
  return;
 }

 if(get_shape_lengths_dimension_scale() == Dimension_Scale::Float)
 {
  if(get_byte_lengths() == Byte_Lengths::Eight)
    shape_lengths_.dbl8->push_back(len);
  else
    shape_lengths_.fl4->push_back(len);
 }
 else if(get_shape_lengths_byte_lengths() == Byte_Lengths::Eight)
   shape_lengths_.int8->push_back(len);
 else
 {
  u4 len4 = len;
  if(len4 != len)
    qDebug() << "Warning: length truncated to fit 4 byte integer";
  shape_lengths_.int4->push_back(len4);
 }
}

void DHAX_Annotation_Instance::add_shape_length(double len)
{
 if(single_shape_length())
 {
  qDebug() << "Warning: adding shape length to single length may overwrite old value";
  set_shape_length(len);
  return;
 }

 if(get_shape_lengths_dimension_scale() == Dimension_Scale::Float)
 {
  if(get_byte_lengths() == Byte_Lengths::Eight)
    shape_lengths_.dbl8->push_back(len);
  else
    shape_lengths_.fl4->push_back(len);
 }
 else
 {
  qDebug() << "Warning: converting double to integer for shape length";
  if(get_shape_lengths_byte_lengths() == Byte_Lengths::Eight)
    shape_lengths_.int8->push_back(len);
  else
    shape_lengths_.int4->push_back(len);
 }
}

void DHAX_Annotation_Instance::add_shape_length(float len)
{
 if(single_shape_length())
 {
  qDebug() << "Warning: adding shape length to single length may overwrite old value";
  set_shape_length(len);
  return;
 }

 if(get_shape_lengths_dimension_scale() == Dimension_Scale::Float)
 {
  if(get_shape_lengths_byte_lengths() == Byte_Lengths::Eight)
    shape_lengths_.dbl8->push_back(len);
  else
    shape_lengths_.fl4->push_back(len);
 }
 else
 {
  qDebug() << "Warning: converting float to integer for shape length";
  if(get_shape_lengths_byte_lengths() == Byte_Lengths::Eight)
    shape_lengths_.int8->push_back(len);
  else
    shape_lengths_.int4->push_back(len);
 }
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

