/* axlFieldParametricSurfaceTangentVectorCreator.cpp---
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

#include "axlFieldParametricSurfaceTangentVectorCreator.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldParametricSurfaceTangentVector.h>
#include <axlCore/axlAbstractData.h>
#include <axlCore/axlAbstractSurfaceParametric.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkGlobal.h>
#include <QtGui>

class axlFieldParametricSurfaceTangentVectorCreatorPrivate
{
public:
    axlAbstractSurfaceParametric *input;
    double a;
    double b;
};

axlFieldParametricSurfaceTangentVectorCreator::axlFieldParametricSurfaceTangentVectorCreator(void) : axlAbstractFieldGenerator(),  d(new axlFieldParametricSurfaceTangentVectorCreatorPrivate)
{
    d->input = NULL;
    d->a = 0;
    d->b = 0;

}

axlFieldParametricSurfaceTangentVectorCreator::~axlFieldParametricSurfaceTangentVectorCreator(void)
{
    delete d;

    d = NULL;
}


void axlFieldParametricSurfaceTangentVectorCreator::setInput(dtkAbstractData *data, int channel)
{
    if(axlAbstractSurfaceParametric *surface = dynamic_cast<axlAbstractSurfaceParametric *>(data))
        d->input = surface;

}


void axlFieldParametricSurfaceTangentVectorCreator::setParameter(double data, int channel){
    if(channel == 0)
        d->a = data;
    else if(channel == 1)
        d->b = data;
    else
        qDebug()<< "only two values are possible ; 0 to 1";

}


int axlFieldParametricSurfaceTangentVectorCreator::update(void)
{

    if(!d->input)
        return 0;

    axlFieldParametricSurfaceTangentVector *field = new axlFieldParametricSurfaceTangentVector();

    QString newName = d->input->changeFieldName(field->objectName());
    field->setObjectName(newName);
    d->input->addField(field);
    field->setSurface(d->input);
    field->setParameter(d->a, 0);
    field->setParameter(d->b, 1);


    QList<axlAbstractData *>list;
    list << d->input;
    emit dataSetFieldsChanged(list, field->objectName());

    return 1;

}


int axlFieldParametricSurfaceTangentVectorCreator::channelCount(void)
{
    return 0;
}


QString axlFieldParametricSurfaceTangentVectorCreator::description(void) const
{
    return "axlFieldParametricSurfaceTangentVectorCreator created fields for input tha compute the normal vector in each parameter coordinates of the input support.";
}

QString axlFieldParametricSurfaceTangentVectorCreator::identifier(void) const
{
    return "axlFieldParametricSurfaceTangentVectorCreator";
}

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractProcess *createaxlFieldParametricSurfaceTangentVectorCreator(void)
{
    return new axlFieldParametricSurfaceTangentVectorCreator;
}


