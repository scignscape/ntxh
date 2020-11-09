/* axlInspectorToolCreatorPoint.cpp ---
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

#include "axlInspectorToolCreatorPoint.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkGuiSupport/dtkColorButton.h>

#include <QtGui>

class axlInspectorToolCreatorPointPrivate
{
public:
    QSlider *sliderOpacity;
    dtkColorButton *colorButton;
    axlInspectorObjectController *controller;

    QDoubleSpinBox *spinBoxCoordonate_x;
    QDoubleSpinBox *spinBoxCoordonate_y;
    QDoubleSpinBox *spinBoxCoordonate_z;
};

axlInspectorToolCreatorPoint::axlInspectorToolCreatorPoint(QWidget *parent) : axlInspectorToolCreator(parent), d(new axlInspectorToolCreatorPointPrivate)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    //OPACITY//
    d->sliderOpacity = new QSlider(Qt::Horizontal, this);

    QHBoxLayout *layoutOpacity = new QHBoxLayout;
    layoutOpacity->addWidget(new QLabel("Opacity",this));
    layoutOpacity->addWidget(d->sliderOpacity);
    d->sliderOpacity->setMaximum(100);

    //COLOR//
    d->colorButton = new dtkColorButton(this);

    QHBoxLayout *layoutColorButton = new QHBoxLayout;
    layoutColorButton->addWidget(new QLabel("Color",this));
    layoutColorButton->addWidget(d->colorButton);
    d->colorButton->setColor(QColor("#a0a0a4"));


    QVBoxLayout *layoutCoordonate = new QVBoxLayout();
    QHBoxLayout *layoutCoordonate_x = new QHBoxLayout();
    QHBoxLayout *layoutCoordonate_y = new QHBoxLayout();
    QHBoxLayout *layoutCoordonate_z = new QHBoxLayout();
    QLabel *labelCoordonate_x = new QLabel("x",this);
    QLabel *labelCoordonate_y = new QLabel("y",this);
    QLabel *labelCoordonate_z = new QLabel("z",this);
    d->spinBoxCoordonate_x = new QDoubleSpinBox(this);
    d->spinBoxCoordonate_y = new QDoubleSpinBox(this);
    d->spinBoxCoordonate_z = new QDoubleSpinBox(this);

    d->spinBoxCoordonate_x->setRange(-1000, 1000);
    d->spinBoxCoordonate_y->setRange(-1000, 1000);
    d->spinBoxCoordonate_z->setRange(-1000, 1000);

    d->spinBoxCoordonate_x->setValue(0.0);
    d->spinBoxCoordonate_y->setValue(0.0);
    d->spinBoxCoordonate_z->setValue(0.0);
    d->spinBoxCoordonate_x->setSingleStep(0.1);
    d->spinBoxCoordonate_y->setSingleStep(0.1);
    d->spinBoxCoordonate_z->setSingleStep(0.1);

    layoutCoordonate_x->addWidget(labelCoordonate_x);
    layoutCoordonate_x->addWidget(d->spinBoxCoordonate_x);
    layoutCoordonate_y->addWidget(labelCoordonate_y);
    layoutCoordonate_y->addWidget(d->spinBoxCoordonate_y);
    layoutCoordonate_z->addWidget(labelCoordonate_z);
    layoutCoordonate_z->addWidget(d->spinBoxCoordonate_z);
    layoutCoordonate->addLayout(layoutCoordonate_x);
    layoutCoordonate->addLayout(layoutCoordonate_y);
    layoutCoordonate->addLayout(layoutCoordonate_z);

    QPushButton *button = new QPushButton("Create", this);
    connect(button, SIGNAL(clicked()), this, SLOT(run()));

    layout->addWidget(new QLabel("axlInspectorToolCreatorPoint", this));
    layout->addLayout(layoutCoordonate);
    layout->addLayout(layoutOpacity);
    layout->addLayout(layoutColorButton);
    layout->addWidget(button);
}

axlInspectorToolCreatorPoint::~axlInspectorToolCreatorPoint(void)
{
    delete d;

    d = NULL;
}

void axlInspectorToolCreatorPoint::setController(axlInspectorObjectController *controller)
{
    d->controller = controller;
}

void axlInspectorToolCreatorPoint::run(void)
{
    axlPoint *newPoint = new axlPoint(d->spinBoxCoordonate_x->value(), d->spinBoxCoordonate_y->value(), d->spinBoxCoordonate_z->value());
    newPoint->setColor(d->colorButton->color());
    double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
    newPoint->setOpacity(opacity);
    emit dataInserted(newPoint);
}
