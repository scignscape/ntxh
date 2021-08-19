
#ifndef DISPLAY_DRAWN_SHAPE__H
#define DISPLAY_DRAWN_SHAPE__H

#include <QPoint>
#include <QVector>
//#include <QtGui>

#include "accessors.h"

#include "global-types.h"

class AXFI_Annotation;

class Display_Drawn_Shape
{
 QVector<QPoint> points_;

public:

 enum class Shape_Kinds
 {
  N_A, Rectangle, Ellipse, Polygon, Polyline
 };

private:

 Shape_Kinds shape_kind_;

public:

 Display_Drawn_Shape(Shape_Kinds Shape_Kinds = Shape_Kinds::N_A);

 void init_from_axfi_annotation(AXFI_Annotation& axa, r8 resize_factor);

 void reset();
 void reset_all();

 AXFI_Annotation* to_axfi_annotation(r8 resize_factor);

 QString shape_kind_to_string();

 ACCESSORS__RGET(QVector<QPoint> ,points)
 ACCESSORS(Shape_Kinds ,shape_kind)
};


#endif // DISPLAY_DRAWN_SHAPE__H
