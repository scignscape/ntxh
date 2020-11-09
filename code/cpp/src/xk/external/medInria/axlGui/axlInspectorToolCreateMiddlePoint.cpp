
#include "axlInspectorToolCreateMiddlePoint.h"

axlInspectorToolCreateMiddlePoint::axlInspectorToolCreateMiddlePoint(QWidget *parent)
 :  QFrame(parent)
{

}

#ifdef HIDE
 // //  why is this here?

// //? what is this?
/* axlInspectorToolCreatorLine.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Wed Mar 16 17:19:51 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Mar 16 17:38:31 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 31
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorToolCreatorLine.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlLine.h>
#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkGuiSupport/dtkColorButton.h>

#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlLineCreator.h>

#include <QtGui>

class axlInspectorToolCreatorLinePrivate
{
public:
    QSlider *sliderOpacity;
    dtkColorButton *colorButton;
    axlInspectorObjectController *controller;

    QDoubleSpinBox *spinBoxCoordinateFirst_x;
    QDoubleSpinBox *spinBoxCoordinateFirst_y;
    QDoubleSpinBox *spinBoxCoordinateFirst_z;

    QDoubleSpinBox *spinBoxCoordinateSecond_x;
    QDoubleSpinBox *spinBoxCoordinateSecond_y;
    QDoubleSpinBox *spinBoxCoordinateSecond_z;
};


axlInspectorToolCreatorLine::axlInspectorToolCreatorLine(QWidget *parent) :
  //? QFrame(parent), d(new axlInspectorToolCreatorLinePrivate)
  axlInspectorToolCreator(parent), d(new axlInspectorToolCreatorLinePrivate)
{
    QVBoxLayout *layout = new QVBoxLayout(this);


    QPushButton *button = new QPushButton("Create", this);
    connect(button, SIGNAL(clicked()), this, SLOT(run()));

    layout->addWidget(new QLabel("axlInspectorToolCreatorLine", this));
    layout->addWidget(button);
}


axlInspectorToolCreatorLine::~axlInspectorToolCreatorLine(void)
{
    delete d;

    d = NULL;
}

void axlInspectorToolCreatorLine::setController(axlInspectorObjectController *controller)
{
    d->controller = controller;
}

void axlInspectorToolCreatorLine::run(void)
{
    // WARNING THESE POINT IS ONLY REFERENCED BY THE LINE : risk of memory leek when the line will be deleted
    axlPoint *firstPoint = new axlPoint(d->spinBoxCoordinateFirst_x->value(), d->spinBoxCoordinateFirst_y->value(), d->spinBoxCoordinateFirst_z->value());
    axlPoint *secondPoint = new axlPoint(d->spinBoxCoordinateSecond_x->value(), d->spinBoxCoordinateSecond_y->value(), d->spinBoxCoordinateSecond_z->value());
    axlDataDynamic *dynamicLine = new axlDataDynamic();
    axlLineCreator *lineCreator = new axlLineCreator();
    dynamicLine->setProcess(lineCreator);
    dynamicLine->setInput(firstPoint);
    dynamicLine->setInput(secondPoint);
    dynamicLine->update();


//?    axlLine* line = dynamic_cast<axlLine *>(dynamicLine->output());
    axlLine* line = (axlLine*) dynamicLine->output();

    line->setParent(dynamicLine);
//    axlLine* line = new axlLine(firstPoint, secondPoint);
    line->setColor(d->colorButton->color());
    double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
    line->setOpacity(opacity);
    emit dataInserted(line);

}

#endif // HIDE 



