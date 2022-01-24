
#ifndef SIMPLE_RECTANGLE_ANNOTATION__H
#define SIMPLE_RECTANGLE_ANNOTATION__H


#include <QRubberBand>

#include "global-types.h"

#include "accessors.h"

#include "../simple-annotation-base.h"


class Simple_Rectangle_Annotation : public Simple_Annotation_Base
{
 Q_OBJECT


public:

 Simple_Rectangle_Annotation(DHAX_Mouse_Interaction_Data& mouse_interaction_data, const QPointF& sc, QWidget* p = nullptr);


protected:


Q_SIGNALS:

protected:

// void paintEvent(QPaintEvent *event) ;


public Q_SLOTS:

};

#endif // SIMPLE_RECTANGLE_ANNOTATION__H
