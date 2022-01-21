
#ifndef SIMPLE_ANNOTATION_BASE__H
#define SIMPLE_ANNOTATION_BASE__H


#include <QRubberBand>

#include "global-types.h"

#include "accessors.h"

#include "multistep-annotation-base.h"


class Simple_Annotation_Base : public MultiStep_Annotation_Base
{
 Q_OBJECT

protected:
 QRectF scaffold_;


public:

 Simple_Annotation_Base(const QPointF& sc, QWidget* p = nullptr);

 virtual void adjust_geometry(const QPointF& pos) Q_DECL_OVERRIDE;

 virtual void reset_geometry(const QPointF& sc = {}) Q_DECL_OVERRIDE;

 virtual void draw_vertex_handles(QPainter& painter, u1 radius) Q_DECL_OVERRIDE;

 virtual void init_shape_pen(QConicalGradient& gradient, QPen& pen) Q_DECL_OVERRIDE
 {
  init_dotted_shape_pen(gradient, pen);
 }

 virtual void init_shape_brush(QBrush& brush, Qt::BrushStyle& style, u1 density_level = 0) Q_DECL_OVERRIDE
 {
  if(density_level == 0)
    init_dotted_shape_brush(brush, style);
  else
    init_dotted_shape_brush(brush, style, density_level);
 }

 virtual void init_second_phase(const QPointF &pos) Q_DECL_OVERRIDE
 {
 }

 virtual void finish_second_phase(const QPointF &pos) Q_DECL_OVERRIDE
 {
 }

 virtual void finish_third_phase(const QPointF &pos) Q_DECL_OVERRIDE
 {
 }


protected:

 void process_paint_event(QPaintEvent* event, QPainter& painter) Q_DECL_OVERRIDE;
 void set_gradient_center(QConicalGradient& gradient) Q_DECL_OVERRIDE;

Q_SIGNALS:

protected:

// void paintEvent(QPaintEvent *event) ;


public Q_SLOTS:

};

#endif // SIMPLE_ANNOTATION_BASE__H
