
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef ROTATEABLE_ARROW_ANNOTATION__H
#define ROTATEABLE_ARROW_ANNOTATION__H


#include <QRubberBand>

#include "global-types.h"

#include "accessors.h"

#include "multistep-annotation-base.h"


class Rotateable_Arrow_Annotation //
  : public MultiStep_Annotation_Base
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

 r8 shaft_offset_;
 r8 shaft_offset_delta_;

 QPolygonF rendered_polygon_;


protected:

 void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;


public:

 Rotateable_Arrow_Annotation(DHAX_Mouse_Interaction_Data& mouse_interaction_data, const QPointF& sc, QWidget* p = nullptr);

 Rotateable_Arrow_Annotation(const QByteArray& data);

 void as_polygon(QPolygonF& result);


 ACCESSORS__RGET(QRectF ,shaft)
 ACCESSORS__RGET(QRectF ,tip)
 //ACCESSORS__RGET(QRectF ,tip_point_width)
 ACCESSORS(r8 ,rotation)

 ACCESSORS__CONST_RGET(QPolygonF ,rendered_polygon)


 void adjust_geometry(const QPointF& pos) Q_DECL_OVERRIDE;

 void reset_geometry(const QPointF& sc = {}) Q_DECL_OVERRIDE;

 QString kind_name() Q_DECL_OVERRIDE {return "Arrow"; }
 void generate_ntxh(QString& result) Q_DECL_OVERRIDE;

 void init_tip_phase(const QPointF& pos);
 void finish_tip_phase(const QPointF& pos);
 void finish_rotation_phase(const QPointF& pos);

 virtual void init_second_phase(const QPointF &pos) Q_DECL_OVERRIDE
 {
  init_tip_phase(pos);
 }

 virtual void finish_second_phase(const QPointF &pos) Q_DECL_OVERRIDE
 {
  finish_tip_phase(pos);
 }

 virtual void finish_third_phase(const QPointF &pos) Q_DECL_OVERRIDE
 {
  finish_rotation_phase(pos);
 }

protected:

 void process_paint_event(QPaintEvent* event, QPainter& painter) Q_DECL_OVERRIDE;
 void set_gradient_center(QConicalGradient& gradient) Q_DECL_OVERRIDE;


Q_SIGNALS:

protected:

// void paintEvent(QPaintEvent *event) ;


public Q_SLOTS:

};

#endif // ROTATEABLE_ARROW_ANNOTATION__H
