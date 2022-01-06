
#ifndef ARROW_ANNOTATION__H
#define ARROW_ANNOTATION__H


#include <QRubberBand>

#include "global-types.h"

#include "accessors.h"


class Arrow_Annotation //
  : public QWidget
{
 Q_OBJECT


 QRectF shaft_;
 QRectF tip_;

 r8 tip_point_width_;
 r8 tip_point_width_delta_;

 r8 tip_corner_bend_;
 r8 tip_corner_bend_delta_;

 r8 rotation_;

 QLineF rotation_landmark_;
 QPointF rotation_center_;
 QPoint mapped_rotation_center_;

 //?QWidget* parent_;

 enum class Corner_Pair_Directions {
  N_A, Up = 1, Up_Right_Up = 2, Up_Right = 3,
  Right = 5,
  Down_Right_Down = 6, Down_Right = 7,
  Down = 9,
  Down_Left_Down = 10, Down_Left = 11,
  Left = 13,
  Up_Left_Up = 14, Up_Left = 15,
  Direction_Only = 15,
  First_Phase = 16, Second_Phase = 32, Third_Phase = 64,
  Second_or_Third_Phase = Second_Phase | Third_Phase,
  Fourth_Phase = 128, Third_or_Fourth_Phase = Third_Phase | Fourth_Phase,
  Phase_234 = Second_or_Third_Phase | Fourth_Phase,
 };

 ENUM_FLAGS_OP_MACROS(Corner_Pair_Directions)


 Corner_Pair_Directions current_corner_pair_direction_;


protected:

 void map_from_parent(const QRectF& source, QRect& result);
// void map_from_parent_plus_x(const QRectF& source, r8 x_delta, QRect& result);
// void map_from_parent_plus_y(const QRectF& source, r8 y_delta, QRect& result);

 static s1 _spaceship(r8 lhs, r8 rhs = 0)
 {
  if(lhs < rhs)
    return 1;
  if(rhs < lhs)
    return -1;
  return 0;
 }

 static Corner_Pair_Directions get_corner_pair_direction(const QPointF& landmark,
   const QPointF& trajector);

 static Corner_Pair_Directions get_corner_pair_direction(const QRectF& rect)
 {
  // //  assumes rect has been normalized ...
  return get_corner_pair_direction(rect.topLeft(), rect.bottomRight());
 }

 void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;


public:

 Arrow_Annotation(const QPointF& sc, QWidget* p = nullptr);

 ACCESSORS__RGET(QRectF ,shaft)
 ACCESSORS__RGET(QRectF ,tip)
 //ACCESSORS__RGET(QRectF ,tip_point_width)
 ACCESSORS(r8 ,rotation)


 void adjust_geometry(const QPointF& pos);

 void reset_geometry(const QPointF& sc = {});


 void init_tip_phase(const QPointF& pos);
 void finish_tip_phase(const QPointF& pos);
 void finish_rotation_phase(const QPointF& pos);

Q_SIGNALS:

protected:

 void paintEvent(QPaintEvent *event);


public Q_SLOTS:

};

#endif // ARROW_ANNOTATION__H