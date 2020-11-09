/* axlFieldParametricNormalVectorCreator.cpp---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlFieldParametricNormalVectorCreator.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldParametricNormalVector.h>
#include <axlCore/axlAbstractData.h>
#include <axlCore/axlAbstractSurfaceParametric.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkGlobal.h>
#include <QtGui>

class axlFieldParametricNormalVectorCreatorPrivate
{
public:
    axlAbstractSurfaceParametric *input;
};

axlFieldParametricNormalVectorCreator::axlFieldParametricNormalVectorCreator(void) : axlAbstractFieldGenerator(),  d(new axlFieldParametricNormalVectorCreatorPrivate)
{
    d->input = NULL;

}

axlFieldParametricNormalVectorCreator::~axlFieldParametricNormalVectorCreator(void)
{
    delete d;

    d = NULL;
}


void axlFieldParametricNormalVectorCreator::setInput(dtkAbstractData *data, int channel)
{
    if(axlAbstractSurfaceParametric *surface = dynamic_cast<axlAbstractSurfaceParametric *>(data))
        d->input = surface;

}


int axlFieldParametricNormalVectorCreator::update(void)
{

    if(!d->input)
        return 0;

    axlFieldParametricNormalVector *field = new axlFieldParametricNormalVector();

    QString newName = d->input->changeFieldName(field->objectName());
    field->setObjectName(newName);
    d->input->addField(field);
    field->setSurface(d->input);


    QList<axlAbstractData *>list;
    list << d->input;
    emit dataSetFieldsChanged(list, field->objectName());

    return 1;

}


int axlFieldParametricNormalVectorCreator::channelCount(void)
{
    return 0;
}


QString axlFieldParametricNormalVectorCreator::description(void) const
{
    return "axlFieldParametricNormalVectorCreator created fields for input tha compute the normal vector in each parameter coordinates of the input support.";
}

QString axlFieldParametricNormalVectorCreator::identifier(void) const
{
    return "axlFieldParametricNormalVectorCreator";
}

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractProcess *createaxlFieldParametricNormalVectorCreator(void)
{
    return new axlFieldParametricNormalVectorCreator;
}

