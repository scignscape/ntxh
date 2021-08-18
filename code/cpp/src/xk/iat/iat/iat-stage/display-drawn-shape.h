
#ifndef DISPLAY_DRAWN_SHAPE__H
#define DISPLAY_DRAWN_SHAPE__H

#include <QPoint>
#include <QVector>
//#include <QtGui>

#include "accessors.h"


class Display_Drawn_Shape
{
 QVector<QPoint> points_;

public:

 enum class Shape_Kind
 {
  N_A, Rectangle, Ellipse, Polygon
 };

private:

 Shape_Kind shape_kind_;

public:

 Display_Drawn_Shape(Shape_Kind shape_kind);

 void reset();
 void reset_all();

 ACCESSORS__RGET(QVector<QPoint> ,points)
 ACCESSORS(Shape_Kind ,shape_kind)
};


#endif // DISPLAY_DRAWN_SHAPE__H
