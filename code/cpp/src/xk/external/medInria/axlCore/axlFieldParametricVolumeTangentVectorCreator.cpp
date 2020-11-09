/* axlFieldParametricVolumeTangentVectorCreator.cpp---
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

#include "axlFieldParametricVolumeTangentVectorCreator.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldParametricVolumeTangentVector.h>
#include <axlCore/axlAbstractData.h>
#include <axlCore/axlAbstractVolumeParametric.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkGlobal.h>
#include <QtGui>

class axlFieldParametricVolumeTangentVectorCreatorPrivate
{
public:
    axlAbstractVolumeParametric *input;
    double a;
    double b;
    double c;
};

axlFieldParametricVolumeTangentVectorCreator::axlFieldParametricVolumeTangentVectorCreator(void) : axlAbstractFieldGenerator(),  d(new axlFieldParametricVolumeTangentVectorCreatorPrivate)
{
    d->input = NULL;
    d->a = 0;
    d->b = 0;
    d->c = 0;

}

axlFieldParametricVolumeTangentVectorCreator::~axlFieldParametricVolumeTangentVectorCreator(void)
{
    delete d;

    d = NULL;
}


void axlFieldParametricVolumeTangentVectorCreator::setInput(dtkAbstractData *data, int channel)
{
    if(axlAbstractVolumeParametric *surface = dynamic_cast<axlAbstractVolumeParametric *>(data))
        d->input = surface;

}


void axlFieldParametricVolumeTangentVectorCreator::setParameter(double data, int channel){
    if(channel == 0)
        d->a = data;
    else if(channel == 1)
        d->b = data;
    else if(channel == 2)
        d->c = data;
    else
        qDebug()<< "only three values are possible : 0 to 2";

}


int axlFieldParametricVolumeTangentVectorCreator::update(void)
{

    if(!d->input)
        return 0;

    axlFieldParametricVolumeTangentVector *field = new axlFieldParametricVolumeTangentVector();

    QString newName = d->input->changeFieldName(field->objectName());
    field->setObjectName(newName);
    d->input->addField(field);
    field->setVolume(d->input);
    field->setParameter(d->a, 0);
    field->setParameter(d->b, 1);
    field->setParameter(d->c, 2);


    QList<axlAbstractData *>list;
    list << d->input;
    emit dataSetFieldsChanged(list, field->objectName());

    return 1;

}


int axlFieldParametricVolumeTangentVectorCreator::channelCount(void)
{
    return 0;
}


QString axlFieldParametricVolumeTangentVectorCreator::description(void) const
{
    return "axlFieldParametricVolumeTangentVectorCreator created fields for input tha compute the normal vector in each parameter coordinates of the input support.";
}

QString axlFieldParametricVolumeTangentVectorCreator::identifier(void) const
{
    return "axlFieldParametricVolumeTangentVectorCreator";
}

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractProcess *createaxlFieldParametricVolumeTangentVectorCreator(void)
{
    return new axlFieldParametricVolumeTangentVectorCreator;
}


