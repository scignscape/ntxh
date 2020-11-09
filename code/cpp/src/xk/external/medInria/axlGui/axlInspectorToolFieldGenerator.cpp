/* axlInspectorToolFieldGenerator.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Wed Mar 16 17:19:51 2011 (+0100)
 * Version: $Id$
 * Last-Updated: mar. mars 29 12:41:17 2011 (+0200)
 *           By: Meriadeg Perrinel
 *     Update #: 33
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorToolFieldGenerator.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlAbstractData.h>
#include <axlCore/axlAbstractFieldGenerator.h>
#include <axlCore/axlPoint.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>

#include <QtGui>

class axlInspectorToolFieldGeneratorPrivate
{
public:
    axlAbstractFieldGenerator *process;
    axlInspectorObjectController *controller;
};

axlInspectorToolFieldGenerator::axlInspectorToolFieldGenerator(QWidget *parent) : QFrame(parent), d(new axlInspectorToolFieldGeneratorPrivate)
{
    d->process = NULL;

    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *button = new QPushButton("Run", this);
    connect(button, SIGNAL(clicked()), this, SLOT(run()));

    layout->addWidget(new QLabel("axlInspectorToolFieldGenerator", this));
    layout->addWidget(button);

}

axlInspectorToolFieldGenerator::~axlInspectorToolFieldGenerator(void)
{
    //delete d->process;
    delete d;

    d = NULL;
}

void axlInspectorToolFieldGenerator::setController(axlInspectorObjectController *controller)
{
    d->controller = controller;
}

void axlInspectorToolFieldGenerator::setImplementation(const QString& implementation)
{
    if(!(d->process = dynamic_cast<axlAbstractFieldGenerator *> (dtkAbstractProcessFactory::instance()->create(implementation))))
        qDebug() << "Unable to create FieldGenerator" << implementation << "concrete implementation";

    connect(d->process, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData *>, QString)), this, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData *>, QString)));

}

void axlInspectorToolFieldGenerator::run(void)
{
    int numberOfDataSelected =0;

    // Field can be constructed for a lot of axlAbstractData in the same time
    foreach(axlInspectorObjectManagerTreeItem *item, d->controller->items()) {

        if(item->text(2) == "Selected" )
        {
            if(axlAbstractData *axlData = dynamic_cast<axlAbstractData *> (d->controller->data(item)))
            {
                d->process->setInput(axlData, numberOfDataSelected);


                numberOfDataSelected++;
            }
        }
    }

    if(numberOfDataSelected > 0)
        d->process->run();

}
