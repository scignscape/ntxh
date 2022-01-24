
#include "simple-rectangle-annotation.h"

#include <QPainter>

#include <QDebug>

#include <QWheelEvent>

#include "global-types.h"


Simple_Rectangle_Annotation::Simple_Rectangle_Annotation(DHAX_Mouse_Interaction_Data& mouse_interaction_data,
   const QPointF& sc, QWidget* p)
 : Simple_Annotation_Base(mouse_interaction_data, sc, p)
{
 scaffold_.setTopLeft(sc);
 scaffold_.setBottomRight(sc);
}

