
#include "simple-rectangle-annotation.h"

#include <QPainter>

#include <QDebug>

#include <QWheelEvent>

#include "global-types.h"


Simple_Rectangle_Annotation::Simple_Rectangle_Annotation(const QPointF& sc, QWidget* p)
 : Simple_Annotation_Base(sc, p)
{
 scaffold_.setTopLeft(sc);
 scaffold_.setBottomRight(sc);
}

