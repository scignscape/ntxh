
#include "simple-ellipse-annotation.h"

#include <QPainter>

#include <QDebug>

#include <QWheelEvent>

#include "global-types.h"


Simple_Ellipse_Annotation::Simple_Ellipse_Annotation(const QPointF& sc, QWidget* p)
 : Simple_Annotation_Base(sc, p)
{
 scaffold_.setTopLeft(sc);
 scaffold_.setBottomRight(sc);
}

void Simple_Ellipse_Annotation::process_paint_event(QPaintEvent* event, QPainter& painter)
{
 QRect _scaffold; map_from_parent(scaffold_, _scaffold);
 painter.drawEllipse(_scaffold);
}

