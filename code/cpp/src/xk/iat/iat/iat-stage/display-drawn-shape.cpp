

#include "display-drawn-shape.h"

#include "iat-model/iat-axfi/axfi-annotation.h"


Display_Drawn_Shape::Display_Drawn_Shape(Shape_Kinds Shape_Kinds)
  :  shape_kind_(Shape_Kinds)
{

}

void Display_Drawn_Shape::reset()
{
 points_.clear();
}

void Display_Drawn_Shape::reset_all()
{
 points_.clear();
 shape_kind_ = Shape_Kinds::N_A;
}

QString Display_Drawn_Shape::shape_kind_to_string()
{
 switch (shape_kind_)
 {
 case Shape_Kinds::Rectangle: return "Rectangle";
 case Shape_Kinds::Ellipse: return "Ellipse";
 case Shape_Kinds::Polygon: return "Polygon";
 case Shape_Kinds::Polyline: return "Polyline";

 default: return {};

 }
}

QPoint _coordinate_scaling(const QPoint& init_point, r8 resize_factor)
{
 QPoint new_point;
 if(resize_factor == 25)
 {
  new_point = init_point;
 }
 else
 {
  new_point = init_point;

//  new_point.rx() = init_point.x()*(100.0/(190 - resize_factor * 18));
//  new_point.ry() = init_point.y()*(100.0/(190 - resize_factor * 18));
 }
 return new_point;
}

void Display_Drawn_Shape::init_from_axfi_annotation(AXFI_Annotation& axa, r8 resize_factor)
{
 shape_kind_ = (Shape_Kinds) axa.opaque_shape_kind_code();
 QVector<QPoint> points;
 axa.locations_to_qpoints(points);

 //points_.resize(points.size());
 std::copy(points.begin(), points.end(), std::back_inserter(points_));

}

AXFI_Annotation* Display_Drawn_Shape::to_axfi_annotation(r8 resize_factor)
{
 AXFI_Annotation* result = new AXFI_Annotation;

 result->set_shape_designation(shape_kind_to_string());

 result->set_opaque_shape_kind_code((n8) shape_kind_);

 for(const QPoint& point : points_)
 {
  QPoint sp = _coordinate_scaling(point, resize_factor);
  result->absorb_shape_point(sp);
 }

// QPoint scaled_point = coordinate_scaling() ;//edits.at(i).shapePoints.at(j));

// another.shapePoints << scaled_point;
// axa->absorb_shape_point(scaled_point);

 return result;
}

