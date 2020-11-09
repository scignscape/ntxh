/* axlFieldParametricCurveTangentVectorCreator.cpp---
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

#include "axlFieldParametricCurveTangentVectorCreator.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlFieldParametricCurveTangentVector.h>
#include <axlCore/axlAbstractData.h>
#include <axlCore/axlAbstractCurveParametric.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkGlobal.h>
#include <QtGui>

class axlFieldParametricCurveTangentVectorCreatorPrivate
{
public:
    axlAbstractCurveParametric *input;
};

axlFieldParametricCurveTangentVectorCreator::axlFieldParametricCurveTangentVectorCreator(void) : axlAbstractFieldGenerator(),  d(new axlFieldParametricCurveTangentVectorCreatorPrivate)
{
    d->input = NULL;

}

axlFieldParametricCurveTangentVectorCreator::~axlFieldParametricCurveTangentVectorCreator(void)
{
    delete d;

    d = NULL;
}


void axlFieldParametricCurveTangentVectorCreator::setInput(dtkAbstractData *data, int channel)
{
    if(axlAbstractCurveParametric *surface = dynamic_cast<axlAbstractCurveParametric *>(data))
        d->input = surface;

}


int axlFieldParametricCurveTangentVectorCreator::update(void)
{

    if(!d->input)
        return 0;

    axlFieldParametricCurveTangentVector *field = new axlFieldParametricCurveTangentVector();

    QString newName = d->input->changeFieldName(field->objectName());
    field->setObjectName(newName);
    d->input->addField(field);
    field->setCurve(d->input);


    QList<axlAbstractData *>list;
    list << d->input;
    emit dataSetFieldsChanged(list, field->objectName());

    return 1;

}


int axlFieldParametricCurveTangentVectorCreator::channelCount(void)
{
    return 0;
}


QString axlFieldParametricCurveTangentVectorCreator::description(void) const
{
    return "axlFieldParametricCurveTangentVectorCreator created fields for input tha compute the normal vector in each parameter coordinates of the input support.";
}

QString axlFieldParametricCurveTangentVectorCreator::identifier(void) const
{
    return "axlFieldParametricCurveTangentVectorCreator";
}

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractProcess *createaxlFieldParametricCurveTangentVectorCreator(void)
{
    return new axlFieldParametricCurveTangentVectorCreator;
}


