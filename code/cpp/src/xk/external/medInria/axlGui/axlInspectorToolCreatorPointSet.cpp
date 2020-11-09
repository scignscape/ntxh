/* axlInspectorToolCreatorPointSet.cpp ---
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

#include "axlInspectorToolCreatorPointSet.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlPointSet.h>
#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkGuiSupport/dtkColorButton.h>

#include <QtGui>

class axlInspectorToolCreatorPointSetPrivate
{
public:
    QSlider *sliderOpacity;
    dtkColorButton *colorButton;
    axlInspectorObjectController *controller;

    QSpinBox *spinBoxNumPoints;
};

axlInspectorToolCreatorPointSet::axlInspectorToolCreatorPointSet(QWidget *parent) : QFrame(parent), d(new axlInspectorToolCreatorPointSetPrivate)
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


    QHBoxLayout *layoutNumPoints = new QHBoxLayout;
    QLabel *labelNumPoints = new QLabel("NumPoints",this);
    d->spinBoxNumPoints = new QSpinBox(this);
    d->spinBoxNumPoints->setMaximum(10000);
    d->spinBoxNumPoints->setMinimum(1);
    d->spinBoxNumPoints->setValue(1);
    layoutNumPoints->addWidget(labelNumPoints);
    layoutNumPoints->addWidget(d->spinBoxNumPoints);

    QPushButton *button = new QPushButton("Create", this);
    connect(button, SIGNAL(clicked()), this, SLOT(run()));

    layout->addWidget(new QLabel("axlInspectorToolCreatorPointSet", this));
    layout->addLayout(layoutNumPoints);
    layout->addLayout(layoutOpacity);
    layout->addLayout(layoutColorButton);
    layout->addWidget(button);
}

axlInspectorToolCreatorPointSet::~axlInspectorToolCreatorPointSet(void)
{
    delete d;

    d = NULL;
}

void axlInspectorToolCreatorPointSet::setController(axlInspectorObjectController *controller)
{
    d->controller = controller;
}

void axlInspectorToolCreatorPointSet::run(void)
{
    axlPointSet *newPointSet = new axlPointSet();

    for(int i = 0; i < d->spinBoxNumPoints->value(); i++)
    {
        newPointSet->push_back(new axlPoint(i, i, i));
    }

    newPointSet->setSize(10.0);
    newPointSet->setColor(d->colorButton->color());
    double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
    newPointSet->setOpacity(opacity);

    emit dataInserted(newPointSet);
}
